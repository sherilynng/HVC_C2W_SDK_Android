package jp.co.omron.plus_sensing.hvc_c2w_live;

import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.content.IntentFilter;
import android.graphics.Bitmap;
import android.graphics.Canvas;
import android.media.AudioFormat;
import android.media.AudioManager;
import android.media.AudioTrack;
import android.net.wifi.ScanResult;
import android.net.wifi.WifiInfo;
import android.net.wifi.WifiManager;
import android.os.AsyncTask;
import android.os.Handler;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.text.InputType;
import android.text.SpannableStringBuilder;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.view.SurfaceHolder;
import android.view.SurfaceView;
import android.view.View;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.CheckBox;
import android.widget.EditText;
import android.widget.ScrollView;
import android.widget.Spinner;
import android.widget.TextView;

import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.MalformedURLException;
import java.net.URL;
import java.util.ArrayList;
import java.util.List;

import javax.net.ssl.HttpsURLConnection;

import jp.co.omron.hvcw.ErrorCodes;
import jp.co.omron.hvcw.HvcwApi;
import jp.co.omron.hvcw.Int;
import jp.co.omron.hvcw.LiveEventCallbackInterface;
import jp.co.omron.hvcw.RequestRenderingCallbackInterface;

public class MainActivity extends AppCompatActivity {

    private static final String TAG = MainActivity.class.getSimpleName();

    /** API key obtained from OMRON */
    private static final String API_KEY = "API_KEY"; // Replace by obtained key
    /** Application ID */
    private static final int APP_ID = 100; // 100 (fixed) for developers

    /** Web API request URL */
    private static final String SERVICE_URL = "https://developer.hvc.omron.com/c2w";
    /** Web API access token */
    private String accessToken = "";
    /** Web API access token valid period */
    private int expiresIn;
    /** Registered camera info list */
    private List<CameraInfo> cameraList = new ArrayList<CameraInfo>();
    /** Camera connection flag */
    private boolean isConnected = false;

    /** HVC SDK handle */
    private static HvcwApi api;

    // Password masking switch
    private EditText et1;
    private EditText et2;
    private CheckBox cb1;
    private CheckBox cb2;
    private int defaultInputType1;
    private int defaultInputType2;

    /** WiFi AP scan receiver */
    private BroadcastReceiver receiver;

    /** UI thread operation */
    private Handler handler = new Handler();

    /** Live image rendering */
    private SurfaceHolder surfaceHolder;

    /** For sound playback */
    private AudioTrack audioTrack = null;

    // Load library
    static {
        System.loadLibrary("openh264");
        System.loadLibrary("ffmpeg");
        System.loadLibrary("ldpc");
        System.loadLibrary("IOTCAPIs");
        System.loadLibrary("RDTAPIs");
        System.loadLibrary("c2w");
        System.loadLibrary("HvcOi");
        System.loadLibrary("HVCW");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // Check SDK version
        Int major = new Int();
        Int minor = new Int();
        Int release = new Int();
        HvcwApi.getVersion(major, minor, release);

        TextView tv = (TextView)findViewById(R.id.textView6);
        tv.setText("HVC SDK Ver." + major.getIntValue() + "." + minor.getIntValue() + "." + release.getIntValue());

        if (api != null) {
            api.deleteHandle();
        }

        // Create handle
        api = HvcwApi.createHandle();
        if (api == null) {
            Log.d(TAG, "createHandle() failed.");
            finish();
        }

        // Set UI
        initUIControl();

        // Preparation for playing sound
        // Signed 16 bit PCM, Sampling rate 8000, Channel 1
        int audioBuffSize = AudioTrack.getMinBufferSize(
                8000, AudioFormat.CHANNEL_OUT_MONO, AudioFormat.ENCODING_PCM_16BIT);

        audioTrack =  new AudioTrack(AudioManager.STREAM_MUSIC,
                8000,
                AudioFormat.CHANNEL_OUT_MONO,
                AudioFormat.ENCODING_PCM_16BIT,
                audioBuffSize,
                AudioTrack.MODE_STREAM);

        // Scan AP required for camera connection
        scanWifiAP();
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // Inflate the menu; this adds items to the action bar if it is present.
        getMenuInflater().inflate(R.menu.menu_main, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        // Handle action bar item clicks here. The action bar will
        // automatically handle clicks on the Home/Up button, so long
        // as you specify a parent activity in AndroidManifest.xml.
        int id = item.getItemId();

        //noinspection SimplifiableIfStatement
        if (id == R.id.action_settings) {
            return true;
        }

        return super.onOptionsItemSelected(item);
    }

    @Override
    protected void onDestroy() {
        // Release receiver
        unregisterReceiver(receiver);

        if (api != null) {
            // Disconnect if already connected to camera
            if (isConnected) {
                Log.d(TAG, "disconnect()");
                api.disconnect();
                isConnected = false;
            }

            // Delete handle
            Log.d(TAG, "deleteHandle()");
            api.deleteHandle();
            api = null;
        }
        super.onDestroy();
    }

    /**
     * UI initialization
     */
    private void initUIControl() {
        SurfaceView sv = (SurfaceView)findViewById(R.id.surfaceView);
        surfaceHolder = sv.getHolder();
        surfaceHolder.setFixedSize(320, 180);

        // Set EditText password masking switch

        // Login password
        et1 = (EditText)findViewById(R.id.editText2);
        defaultInputType1 = et1.getInputType();
        cb1 = (CheckBox)findViewById(R.id.checkBox);
        cb1.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if (cb1.isChecked()) {
                    et1.setInputType(InputType.TYPE_TEXT_VARIATION_VISIBLE_PASSWORD | defaultInputType1);
                } else {
                    et1.setInputType(InputType.TYPE_TEXT_VARIATION_PASSWORD | defaultInputType1);
                }
                et1.setSelection(et1.getText().length());
            }
        });

        // AP password
        et2 = (EditText)findViewById(R.id.editText3);
        defaultInputType2 = et2.getInputType();
        cb2 = (CheckBox)findViewById(R.id.checkBox2);
        cb2.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if (cb2.isChecked()) {
                    et2.setInputType(InputType.TYPE_TEXT_VARIATION_VISIBLE_PASSWORD | defaultInputType2);
                } else {
                    et2.setInputType(InputType.TYPE_TEXT_VARIATION_PASSWORD | defaultInputType2);
                }
                et2.setSelection(et2.getText().length());
            }
        });

        // Button click event

        // Signup
        Button btn = (Button)findViewById(R.id.button);
        btn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                EditText et = (EditText)findViewById(R.id.editText);
                SpannableStringBuilder sp = (SpannableStringBuilder)et.getText();
                String email = sp.toString();

                if (!email.isEmpty()) {
                    signup(email);
                }
            }
        });

        // Login
        btn = (Button)findViewById(R.id.button2);
        btn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                EditText et = (EditText)findViewById(R.id.editText);
                SpannableStringBuilder sp = (SpannableStringBuilder)et.getText();
                String email = sp.toString();

                et = (EditText)findViewById(R.id.editText2);
                sp = (SpannableStringBuilder)et.getText();
                String password = sp.toString();

                if (!email.isEmpty() && !password.isEmpty()) {
                    login(email, password);
                }
            }
        });

        // Logout
        btn = (Button)findViewById(R.id.button3);
        btn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                logout();
            }
        });

        // Connect
        btn = (Button)findViewById(R.id.button4);
        btn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Spinner spinner = (Spinner)findViewById(R.id.spinner);
                String ssid = (String)spinner.getSelectedItem();

                EditText et = (EditText)findViewById(R.id.editText3);
                SpannableStringBuilder sp = (SpannableStringBuilder)et.getText();
                String password = sp.toString();

                if (!ssid.isEmpty() && !password.isEmpty()) {
                    connect(ssid, password);
                }
            }
        });

        // Reload
        btn = (Button)findViewById(R.id.button5);
        btn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                getCameraList();
            }
        });

        // Set
        btn = (Button)findViewById(R.id.button6);
        btn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                setCamera();
            }
        });

        // Rename
        btn = (Button)findViewById(R.id.button7);
        btn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Spinner sp = (Spinner)findViewById(R.id.spinner2);
                int index = sp.getSelectedItemPosition();
                if (index >= cameraList.size()) {
                    addLog("error");
                    return;
                }
                final String cameraID = cameraList.get(index).getID();
                String cameraName = cameraList.get(index).getName();
                String macAddress = cameraList.get(index).getMacAddress();

                String newName;
                if (cameraName.equals("HVC-C2W")) {
                    newName = String.format("%s_%s", cameraName, macAddress.substring(8).toUpperCase());
                } else {
                    newName = "HVC-C2W";
                }
                rename(cameraID, newName);
            }
        });

        // Start
        btn = (Button)findViewById(R.id.button8);
        btn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                startLive();
            }
        });

        // Stop
        btn = (Button)findViewById(R.id.button9);
        btn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                stopLive();
            }
        });
    }

    /**
     * Add text at end of log in TextView
     * @param text Text to be added
     */
    private void addLog(String text) {
        // Add to end of log
        TextView tv = (TextView)findViewById(R.id.textView6);
        tv.append("\n" + text);

        // Scroll in order to see added part
        final ScrollView sv = (ScrollView) findViewById(R.id.scrollView);
        sv.post(new Runnable() {
            @Override
            public void run() {
                sv.fullScroll(ScrollView.FOCUS_DOWN);
            }
        });
    }

    /**
     * Scan AP
     */
    private void scanWifiAP() {
        final WifiManager wifiManager = (WifiManager)getSystemService(WIFI_SERVICE);
        if (wifiManager.getWifiState() == WifiManager.WIFI_STATE_ENABLED) {
            receiver = new BroadcastReceiver() {
                @Override
                public void onReceive(Context context, Intent intent) {
                    List<ScanResult> results = wifiManager.getScanResults();
                    ArrayAdapter adapter = new ArrayAdapter(MainActivity.this, android.R.layout.simple_spinner_item);
                    for (int i = 0; i < results.size(); ++i) {
                        String ssid = results.get(i).SSID;
                        // Do not register items with blank SSID
                        if (!ssid.isEmpty()) {
                            adapter.add(ssid);
                        }
                    }

                    // Set in spinner
                    adapter.setDropDownViewResource(android.R.layout.simple_spinner_dropdown_item);
                    Spinner sp = (Spinner)findViewById(R.id.spinner);
                    sp.setAdapter(adapter);
                }
            };
            registerReceiver(receiver, new IntentFilter(WifiManager.SCAN_RESULTS_AVAILABLE_ACTION));
        }
        wifiManager.startScan();
    }

    /**
     * User registration
     * @param mailAddress Mail address
     */
    private void signup(String mailAddress) {
        addLog("signup ->");

        String url = SERVICE_URL + "/api/v1/signup.php";
        String apiKey = "apiKey=" + API_KEY;
        String email = "email=" + mailAddress;
        String params = apiKey + "&" + email;
        Log.d(TAG, "url:" + url);
        Log.d(TAG, "params:" + params);

        PostMessageTask task = new PostMessageTask(new Listener() {
            public void onReceived(String json) {
                if (json != null) {
                    Log.d(TAG, "json:" + json);

                    try {
                        JSONObject jsonObject = new JSONObject(json);
                        JSONObject result = jsonObject.getJSONObject("result");
                        String code = result.getString("code");
                        String msg = result.getString("msg");
                        addLog(String.format("response=%s(%s)", code, msg));
                    } catch (JSONException e) {
                        e.printStackTrace();
                    }
                } else {
                    Log.d(TAG, "json:null");
                    addLog("error");
                }
            }
        });

        task.execute(url, params);
    }

    /**
     * Login
     * @param mailAddress Mail address
     * @param password Password
     */
    private void login(String mailAddress, String password) {
        addLog("login ->");

        String url = SERVICE_URL + "/api/v1/login.php";
        String apiKey = "apiKey=" + API_KEY;
        // Use device MAC address for deviceId
        WifiManager wifiManager = (WifiManager)getSystemService(Context.WIFI_SERVICE);
        WifiInfo wifiInfo = wifiManager.getConnectionInfo();
        String deviceId = "deviceId=" + wifiInfo.getMacAddress();
        String osType = "osType=" + "1";
        String email = "email=" + mailAddress;
        String pass = "password=" + password;
        String params = apiKey + "&" + deviceId + "&" + osType + "&" + "&" + email + "&" + pass;
        Log.d(TAG, "url:" + url);
        Log.d(TAG, "params:" + params);

        PostMessageTask task = new PostMessageTask(new Listener() {
            public void onReceived(String json) {
                if (json != null) {
                    Log.d(TAG, "json:" + json);

                    try {
                        JSONObject root = new JSONObject(json);
                        JSONObject result = root.getJSONObject("result");
                        String code = result.getString("code");
                        String msg = result.getString("msg");
                        if (msg.equals("success")) {
                            JSONObject access = root.getJSONObject("access");
                            accessToken = access.getString("token");
                            expiresIn = access.getInt("expiresIn");
                        }
                        addLog(String.format("response=%s(%s)", code, msg));
                        addLog(String.format("token=\"%s\"", accessToken));
                        addLog(String.format("expiresIn=%d", expiresIn));
                    } catch (JSONException e) {
                        e.printStackTrace();
                    }
                } else {
                    Log.d(TAG, "json:null");
                    addLog("error");
                }
            }
        });

        task.execute(url, params);
    }

    /**
     * Logout
     */
    private void logout() {
        addLog("logout ->");

        String url = SERVICE_URL + "/api/v1/logout.php";
        Log.d(TAG, "url:" + url);

        PostMessageTask task = new PostMessageTask(new Listener() {
            public void onReceived(String json) {
                if (json != null) {
                    Log.d(TAG, "json:" + json);

                    try {
                        JSONObject root = new JSONObject(json);
                        JSONObject result = root.getJSONObject("result");
                        String code = result.getString("code");
                        String msg = result.getString("msg");
                        if (msg.equals("success")) {
                            accessToken = "";
                            expiresIn = 0;
                        }
                        addLog(String.format("response=%s(%s)", code, msg));
                    } catch (JSONException e) {
                        e.printStackTrace();
                    }
                } else {
                    Log.d(TAG, "json:null");
                    addLog("error");
                }
                accessToken = null;
            }
        });

        task.execute(url, "", accessToken);
    }

    /**
     * Connect camera to network and register to service
     */
    private void connect(String ssid, String password) {
        addLog("connect ->");

        final String fileName = getApplicationContext().getFilesDir() + "/network_setting.pcm";

        // Generate network setting sound file for camera registration
        int ret = api.generateDataSoundFile(fileName, ssid, password, accessToken);
        if (ret == ErrorCodes.HVCW_SUCCESS) {
            // Play when generated
            new Thread(new Runnable() {
                @Override
                public void run() {
                    Log.d(TAG, "play:" + fileName);
                    File networkSettingFile = new File(fileName);
                    if (networkSettingFile == null) {
                        return;
                    }

                    byte[] byteData = new byte[(int) networkSettingFile.length()];
                    FileInputStream fis;
                    try {
                        fis = new FileInputStream(networkSettingFile);
                        fis.read(byteData);
                        fis.close();
                    } catch (FileNotFoundException e) {
                        e.printStackTrace();
                        return;
                    } catch (IOException e) {
                        e.printStackTrace();
                        return;
                    }

                    int audioBuffSize = AudioTrack.getMinBufferSize(
                            8000, AudioFormat.CHANNEL_OUT_MONO, AudioFormat.ENCODING_PCM_16BIT);

                    AudioTrack audio = new AudioTrack(AudioManager.STREAM_MUSIC,
                            8000,
                            AudioFormat.CHANNEL_OUT_MONO,
                            AudioFormat.ENCODING_PCM_16BIT,
                            audioBuffSize,
                            AudioTrack.MODE_STREAM);
                    audio.play();
                    audio.write(byteData, 0, byteData.length);
                }
            }).start();
        } else {
            Log.d(TAG, "generateDataSoundFile() failed.");
        }

        addLog(String.format("errorCode=%d", ret));
    }

    /**
     * Get registered camera list
     */
    private void getCameraList() {
        addLog("getCameraList ->");

        String url = SERVICE_URL + "/api/v1/getCameraList.php";
        Log.d(TAG, "url:" + url);

        PostMessageTask task = new PostMessageTask(new Listener() {
            public void onReceived(String json) {
                if (json != null) {
                    Log.d(TAG, "json:" + json);

                    try {
                        JSONObject root = new JSONObject(json);
                        JSONObject result = root.getJSONObject("result");
                        String code = result.getString("code");
                        String msg = result.getString("msg");
                        addLog(String.format("response=%s(%s)", code, msg));
                        if (msg.equals("success")) {
                            cameraList.clear();
                            ArrayAdapter adapter = new ArrayAdapter(MainActivity.this, android.R.layout.simple_spinner_item);
                            JSONArray array = root.getJSONArray("cameraList");
                            for (int i = 0; i < array.length(); ++i) {
                                JSONObject obj =array.getJSONObject(i);
                                CameraInfo ci = new CameraInfo();
                                String id = obj.getString("cameraId");
                                ci.setID(id);
                                String name = obj.getString("cameraName");
                                ci.setName(name);
                                ci.setMacAddress(obj.getString("cameraMacAddr"));
                                ci.setAppID(obj.getString("appId"));
                                ci.setOwnerType(obj.getInt("ownerType"));
                                ci.setOwnerEmail(obj.getString("ownerEmail"));
                                cameraList.add(ci);
                                adapter.add(name);
                                addLog(String.format("camera[%d] name=\"%s\",id=\"%s\"", i, name, id));
                            }

                            // Set in spinner
                            adapter.setDropDownViewResource(android.R.layout.simple_spinner_dropdown_item);
                            Spinner sp = (Spinner)findViewById(R.id.spinner2);
                            sp.setAdapter(adapter);
                        }
                    } catch (JSONException e) {
                        e.printStackTrace();
                    }
                } else {
                    Log.d(TAG, "json:null");
                    addLog("error");
                }
            }
        });

        task.execute(url, "", accessToken);
    }

    /**
     * Set camera to be used
     */
    private void setCamera() {
        addLog("setCamera ->");

        // Get selected camera ID
        Spinner sp = (Spinner)findViewById(R.id.spinner2);
        int index = sp.getSelectedItemPosition();
        if (index >= cameraList.size()) {
            addLog("error");
            return;
        }
        final String cameraID = cameraList.get(index).getID();

        // Async call as API transmits
        new Thread(new Runnable() {
            @Override
            public void run() {
                // Connect to camera
                Log.d(TAG, "connect:" + cameraID);
                int ret = api.connect(cameraID, accessToken);
                Int returnStatus = new Int();
                if (ret == ErrorCodes.HVCW_SUCCESS) {
                    isConnected = true;
                    // Set app ID
                    Log.d(TAG, "setAppID:" + APP_ID);
                    ret = api.setAppID(APP_ID, returnStatus);
                }

                final String msg = String.format("errorCode=%d,returnStatus=%#x", ret, returnStatus.getIntValue());
                handler.post(new Runnable() {
                    @Override
                    public void run() {
                        addLog(msg);
                    }
                });
            }
        }).start();
    }

    /**
     * Rename camera
     * @param id Camera ID
     * @param name New camera name
     */
    private void rename(String id, String name) {
        addLog("rename ->");

        String url = SERVICE_URL + "/api/v1/renameCamera.php";
        String cameraId = "cameraId=" + id;
        String newName = "newName=" + name;
        String params = cameraId + "&" + newName;
        Log.d(TAG, "url:" + url);
        Log.d(TAG, "params:" + params);

        PostMessageTask task = new PostMessageTask(new Listener() {
            public void onReceived(String json) {
                if (json != null) {
                    Log.d(TAG, "json:" + json);

                    try {
                        JSONObject root = new JSONObject(json);
                        JSONObject result = root.getJSONObject("result");
                        String code = result.getString("code");
                        String msg = result.getString("msg");
                        addLog(String.format("response=%s(%s)", code, msg));
                    } catch (JSONException e) {
                        e.printStackTrace();
                    }
                } else {
                    Log.d(TAG, "json:null");
                    addLog("error");
                }
            }
        });

        task.execute(url, params, accessToken);
    }

    /**
     * Start live streaming
     */
    private void startLive() {
        addLog("startLive ->");

        final RequestRenderingCallbackInterface requestRenderingCallback = new RequestRenderingCallbackInterface() {
            @Override
            public int soundDataCallback(long userParam, byte[] sound, long timeStamp) {
                String str;
                // Sound playing process
                if (sound != null) {
                    if (audioTrack.getState() == AudioTrack.STATE_INITIALIZED) {
                        audioTrack.play();
                        audioTrack.write(sound, 0, sound.length);
                        audioTrack.stop();
                    }

                    str = String.format("sound,size=%d", sound.length);
                } else {
                    str = "sound,error";
                }

                final String msg = str;
                handler.post(new Runnable() {
                    @Override
                    public void run() {
                        addLog(msg);
                    }
                });

                return 0;
            }

            @Override
            public int videoFrameCallback(long userParam, byte[] y, byte[] u, byte[] v, long width, long height, long timeStamp) {
                String str;
                // Display process
                if ((y != null) && (u != null) && (v != null)) {
                    // Display as bitmap since image is YUV420P
                    int[] rgb = decodeYUV420P(y, u, v, (int)width, (int)height);
                    Bitmap bmp = Bitmap.createBitmap(rgb, (int)width, (int)height, Bitmap.Config.ARGB_8888);
                    Canvas canvas = surfaceHolder.lockCanvas();
                    canvas.drawBitmap(bmp, 0, 0, null);
                    surfaceHolder.unlockCanvasAndPost(canvas);

                    str = String.format("video,width=%d,height=%d", width, height);
                } else {
                    str = "video,error";
                }

                final String msg = str;
                handler.post(new Runnable() {
                    @Override
                    public void run() {
                        addLog(msg);
                    }
                });

                return 0;
            }
        };

        final LiveEventCallbackInterface liveEventCallback = new LiveEventCallbackInterface() {
            @Override
            public int liveEventCallback(int eventID, long userParam, long eventInfo) {
                String str;
                switch(eventID){
                    case 0:
                        str = String.format("liveEvent,event=Started,info=%d", eventInfo);
                        break;
                    case 1:
                        str = String.format("liveEvent,event=Stopped,info=%d", eventInfo);
                        break;
                    case 2:
                        str = String.format("liveEvent,event=Disconnected,info=%d", eventInfo);
                        break;
                    case 3:
                        str = String.format("liveEvent,event=Error,info=%d", eventInfo);
                        break;
                    case 4:
                        str = String.format("liveEvent,event=FPS,info=%d", eventInfo);
                        break;
                    case 5:
                        str = String.format("liveEvent,event=ChangeResolution,info=%d", eventInfo);
                        break;
                    default:
                        str = String.format("liveEvent,event=Unknown,info=%d", eventInfo);
                        break;
                }

                final String msg = str;
                handler.post(new Runnable() {
                    @Override
                    public void run() {
                        addLog(msg);
                    }
                });

                return 0;
            }
        };

        // Async call as API transmits
        new Thread(new Runnable() {
            @Override
            public void run() {
                int ret = api.startLive(null, 2, requestRenderingCallback, liveEventCallback);

                final String msg = String.format("errorCode=%d", ret);
                handler.post(new Runnable() {
                    @Override
                    public void run() {
                        addLog(msg);
                    }
                });
            }
        }).start();
    }

    /**
     * End live streaming
     */
    private void stopLive() {
        addLog("stopLive ->");

        // Async call as API transmits
        new Thread(new Runnable() {
            @Override
            public void run() {
                int ret = api.stopLive();

                final String msg = String.format("errorCode=%d", ret);
                handler.post(new Runnable() {
                    @Override
                    public void run() {
                        addLog(msg);
                    }
                });
            }
        }).start();
    }

    /**
     * YUV420P to RGB
     * @param y Y
     * @param u (B-Y)
     * @param v (R-Y)
     * @param width Width
     * @param height Height
     * @return RBG(ARGB)
     */
    public static int[] decodeYUV420P(byte[] y, byte[] u, byte[] v, int width, int height) {
        int[] rgb = new int[width * height];
        for (int i = 0, yp = 0; i < height; i++) {
            int uvp = (i >> 1) * (width >> 1);
            int _u = 0;
            int _v = 0;
            for (int j = 0; j < width; j++, yp++) {
                int _y = (((int)y[yp]) & 0xff) - 16;
                if (_y < 0) _y = 0;
                if ((j & 1) == 0) {
                    _u = (u[uvp] & 0xff) - 128;
                    _v = (v[uvp] & 0xff) - 128;
                    ++uvp;
                }

                int y1192 = 1192 * _y;
                int r = (y1192 + 1634 * _v);
                int g = (y1192 - 833 * _v - 400 * _u);
                int b = (y1192 + 2066 * _u);

                if (r < 0) r = 0; else if (r > 262143) r = 262143;
                if (g < 0) g = 0; else if (g > 262143) g = 262143;
                if (b < 0) b = 0; else if (b > 262143) b = 262143;

                rgb[yp] = 0xff000000 | ((r << 6) & 0xff0000) | ((g >>2) & 0xff00) | ((b >> 10) & 0xff);
            }
        }
        return rgb;
    }

    /**
     * POST process listener
     */
    public interface Listener {
        void onReceived(String json);
    }

    /**
     * POST task for request URL
     */
    public class PostMessageTask extends AsyncTask<String, Void, String> {

        /** POST process listener */
        private Listener listener = null;

        /**
         * Constructor
         * @param listener POST process listener
         */
        public PostMessageTask(Listener listener) {
            this.listener = listener;
        }

        /**
         * Background process
         * Send result after POST
         * @param params [Request URL, access token (blank if not required), parameter]
         * @return POST result (null if HTTP error)
         */
        @Override
        protected String doInBackground(String... params) {
            HttpsURLConnection conn = null;
            String json = null;
            try {
                Log.d("PostSecureMessageTask", "connecting...");
                URL url;
                if (params[1].isEmpty()) {
                    // No parameter
                    url = new URL(params[0]);
                } else {
                    // Concatenate to URL if parameter present
                    url = new URL(params[0] + "?" + params[1]);
                }
                conn = (HttpsURLConnection)url.openConnection();
                conn.setRequestMethod("POST");
                conn.setRequestProperty("Content-Type", "application/x-www-form-urlencoded; charset=UTF-8");
                if (params.length == 3) {
                    // For request requiring an access token
                    conn.setRequestProperty("Authorization", "Bearer " + params[2]);
                }
                conn.setDoInput(true);
                conn.setDoOutput(true);

                // POST
                conn.connect();

                // Receive response
                if (conn.getResponseCode() == HttpsURLConnection.HTTP_OK) {
                    Log.d("PostMessageTask", "response 200");
                    StringBuilder sb = new StringBuilder();
                    BufferedReader reader = new BufferedReader(new InputStreamReader(conn.getInputStream()));
                    String line;
                    while ((line = reader.readLine()) != null) {
                        sb.append(line);
                    }
                    json = sb.toString();
                } else {
                    Log.d("PostMessageTask", "response " + conn.getResponseCode());
                }
            } catch(MalformedURLException e) {
                e.printStackTrace();
            } catch(IOException e) {
                e.printStackTrace();
            } finally {
                if(conn != null) {
                    Log.d("PostMessageTask", "disconnecting...");
                    conn.disconnect();
                }
            }

            return json;
        }

        @Override
        protected void onPostExecute(String param) {
            listener.onReceived(param);
        }
    }
}
