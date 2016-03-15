package jp.co.omron.plus_sensing.hvc_c2w_sample;

/**
 * Camera info
 */
public final class CameraInfo {
    /** Camera ID */
    private String id;
    /** Camera name */
    private String name;
    /** MAC address */
    private String macAddress;
    /** Related app ID */
    private String appID;
    /** Owner type */
    private int ownerType;
    /** Owner email address */
    private String ownerEmail;

    /**
     * Constructor
     */
    public CameraInfo() {
    }

    /**
     * Constructor
     */
    public CameraInfo(String id, String name, String macAddress, String appID, int ownerType, String ownerEmail) {
        this.id = id;
        this.name = name;
        this.macAddress = macAddress;
        this.appID = appID;
        this.ownerType = ownerType;
        this.ownerEmail = ownerEmail;
    }

    /**
     * Set camera ID
     * @param id camera ID
     */
    public void setID(String id) {
        this.id = id;
    }

    /**
     * Get camera ID
     * @return Camera ID
     */
    public String getID() {
        return id;
    }

    /**
     * Set camera name
     * @param name Camera name
     */
    public void setName(String name) {
        this.name = name;
    }

    /**
     * Get camera name
     * @return Camera name
     */
    public String getName() {
        return name;
    }

    /**
     * Set MAC address
     * @param macAddress MAC address
     */
    public void setMacAddress(String macAddress) {
        this.macAddress = macAddress;
    }

    /**
     * Get MAC address
     * @return MAC address
     */
    public String getMacAddress() {
        return macAddress;
    }

    /**
     * Set related app ID
     * @param appID Related app ID
     */
    public void setAppID(String appID) {
        this.appID = appID;
    }

    /**
     * Get related app ID
     * @return Related app ID
     */
    public String getAppID() {
        return appID;
    }

    /**
     * Set owner type
     * @param ownerType Owner type
     */
    public void setOwnerType(int ownerType) {
        this.ownerType = ownerType;
    }

    /**
     * Get owner type
     * @return Owner type
     */
    public int getOwnerType() {
        return ownerType;
    }

    /**
     * Set owner email address
     * @param ownerEmail Owner email address
     */
    public void setOwnerEmail(String ownerEmail) {
        this.ownerEmail = ownerEmail;
    }

    /**
     * Get owner email address
     * @return Owner email address
     */
    public String getOwnerEmail() {
        return ownerEmail;
    }
}
