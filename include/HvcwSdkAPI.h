/*-------------------------------------------------------------------*/
/*  Copyright(C) 2015-2016 by OMRON Corporation                      */
/*  All Rights Reserved.                                             */
/*                                                                   */
/*   This source code is the Confidential and Proprietary Property   */
/*   of OMRON Corporation.  Any unauthorized use, reproduction or    */
/*   transfer of this software is strictly prohibited.               */
/*                                                                   */
/*-------------------------------------------------------------------*/

#ifndef __HVCWSDKAPI_H
#define __HVCWSDKAPI_H

#define HVC_API

#ifdef __cplusplus
extern "C" {
#endif

#include "HvcwTypedef.h"

/*-----------------------------------------------------------------------------*/
/*                                                                             */
/*                                 DEFINES                                     */
/*                                                                             */
/*-----------------------------------------------------------------------------*/

/* HVC Handle */
#ifndef SDK_DEF_HHVC
#define SDK_DEF_HHVC
    typedef HVCW_VOID*   HHVC;
#endif /* SDK_DEF_HHVC */

/* Roll Angle Definitions. */
#define HVCW_ROLL_ANGLE_0             (0x00001001)     /* Up            0 degree */
#define HVCW_ROLL_ANGLE_1             (0x00002002)     /* Upper Right  30 degree */
#define HVCW_ROLL_ANGLE_2             (0x00004004)     /* Upper Right  60 degree */
#define HVCW_ROLL_ANGLE_3             (0x00008008)     /* Right        90 degree */
#define HVCW_ROLL_ANGLE_4             (0x00010010)     /* Lower Right 120 degree */
#define HVCW_ROLL_ANGLE_5             (0x00020020)     /* Lower Right 150 degree */
#define HVCW_ROLL_ANGLE_6             (0x00040040)     /* Down        180 degree */
#define HVCW_ROLL_ANGLE_7             (0x00080080)     /* Lower Left  210 degree */
#define HVCW_ROLL_ANGLE_8             (0x00100100)     /* Lower Left  240 degree */
#define HVCW_ROLL_ANGLE_9             (0x00200200)     /* Left        270 degree */
#define HVCW_ROLL_ANGLE_10            (0x00400400)     /* Upper Left  300 degree */
#define HVCW_ROLL_ANGLE_11            (0x00800800)     /* Upper Left  330 degree */

#define HVCW_ROLL_ANGLE_UP            (HVCW_ROLL_ANGLE_0)   /* Up    +/- 15 degree only will be detected */
#define HVCW_ROLL_ANGLE_RIGHT         (HVCW_ROLL_ANGLE_3)   /* Right +/- 15 degree only will be detected */
#define HVCW_ROLL_ANGLE_DOWN          (HVCW_ROLL_ANGLE_6)   /* Down  +/- 15 degree only will be detected */
#define HVCW_ROLL_ANGLE_LEFT          (HVCW_ROLL_ANGLE_9)   /* Left  +/- 15 degree only will be detected */

/* Pose Angle Definitions. */
#define HVCW_POSE_ANGLE_FRONT         (0)              /* Front        */
#define HVCW_POSE_ANGLE_HALF_PROFILE  (1)              /* Half Profile */
#define HVCW_POSE_ANGLE_PROFILE       (2)              /* Profile      */

#define HVCW_PET_TYPE_DOG             (0)              /* Detected pet type: dog    */
#define HVCW_PET_TYPE_CAT             (1)              /* Detected pet type: cat    */

#define HVCW_GENDER_FEMALE            (0)              /* Estimated gender: female  */
#define HVCW_GENDER_MALE              (1)              /* Estimated gender: male    */

/*-----------------------------------------------------------------------------*/
/*                                                                             */
/*                                 ENUM DEFINES                                */
/*                                                                             */
/*-----------------------------------------------------------------------------*/
/**
 * @enum HVCW_VideoResolution
 * Live streaming video resolution
 */
typedef enum HVCW_VideoResolution {
    HVCW_VideoResolution_High = 0,        /* 0=1280x720 */
    HVCW_VideoResolution_Middle,          /* 1= 640x360 */
    HVCW_VideoResolution_Low              /* 2= 320x180 */
} HVCW_VIDEO_RESOLUTION;

/**
 * @enum HVCW_NightVisionMode
 * Night vision mode
 */
typedef enum HVCW_NightVisionMode {
    HVCW_NightVisionMode_Auto = 0,        /* 0=Auto control mode for night vision based on surrounding lighting */
    HVCW_NightVisionMode_Manual           /* 1=Manual control mode for night vision                             */
} HVCW_NIGHT_VISION_MODE;

/**
 * @enum HVCW_NightVisionStatus
 * Night vision status
 */
typedef enum HVCW_NightVisionStatus {
    HVCW_NightVisionStatus_Off = 0,       /* 0=Night vision OFF */
    HVCW_NightVisionStatus_On             /* 1=Night vision ON */
} HVCW_NIGHT_VISION_STATUS;

/**
 * @enum HVCW_Event
 * Event
 */
typedef enum HVCW_Event{
    HVCW_Event_ConnectionNum   = 0,       /*  0=Send notification when camera connection number changed.        */
    HVCW_Event_StreamingNum,              /*  1=Send notification when camera live streaming number changed.    */
    HVCW_Event_NightVisionMode = 6,       /*  6=Send notification when night vision mode changed.               */
    HVCW_Event_NightVisionStatus,         /*  7=Send notification when night vision status changed.             */
    HVCW_Event_SpeakerVolume   = 9,       /*  9=Send notification when camera speaker volume changed.           */
    HVCW_Event_Disconnected    = 13,      /* 13=Send notification when camera disconnected.                     */
    HVCW_Event_Reconnected,               /* 14=Send notification when camera reconnected after disconnection.  */
    HVCW_Event_StorageStatus   = 18       /* 18=Send notification when camera storage status changed.           */
}HVCW_EVENT;

/**
 * @enum HVCW_StorageStatus
 * Storage status
 */
typedef enum HVCW_StorageStatus{
    HVCW_StorageStatus_NotInsert = 0,     /* 0=Storage not detected             */
    HVCW_StorageStatus_NotReady,          /* 1=Storage detected but not useable */
    HVCW_StorageStatus_NeedFormat,        /* 2=Storage requires formatting      */
    HVCW_StorageStatus_Normal,            /* 3=Storage useable                  */
    HVCW_StorageStatus_Error,             /* 4=Storage error makes is unusable  */
    HVCW_StorageStatus_Formatting = 6,    /* 6=Storage formatting               */
    HVCW_StorageStatus_NotSupport         /* 7=Storage not supported            */
} HVCW_STORAGE_STATUS;

/**
 * @enum HVCW_StorageFormatResultCode
 * Storage formatting result
 */
typedef enum HVCW_StorageFormatResultCode {
    HVCW_StorageFormatResultCode_Success = 0,        /* 0=Formatting success                */
    HVCW_StorageFormatResultCode_RemovedStorage,     /* 1=Storage removed during formatting */
    HVCW_StorageFormatResultCode_NotSupportStorage,  /* 2=Storage not supported             */
    HVCW_StorageFormatResultCode_Timeout,            /* 3=Timeout during formatting         */
    HVCW_StorageFormatResultCode_AlreadyRunning,     /* 4=Formatting already under way      */
    HVCW_StorageFormatResultCode_CheckDisk,          /* 5=Check disk under way              */
    HVCW_StorageFormatResultCode_FatalError          /* 6=Other error                       */
} HVCW_STORAGE_FORMAT_RESULT_CODE;

/**
 * @enum HVCW_ConnectionType
 * Connection type
 */
typedef enum HVCW_ConnectionType {
    HVCW_ConnectionType_Disconnect = 0,   /* 0=Not connected    */
    HVCW_ConnectionType_P2P,              /* 1=P2P connection   */
    HVCW_ConnectionType_Relay,            /* 2=Relay connection */
    HVCW_ConnectionType_Local             /* 3=Local connection */
} HVCW_CONNECTION_TYPE;

/**
 * @enum HVCW_LiveEvent
 * Live event
 */
typedef enum HVCW_LiveEvent{
    HVCW_LiveEvent_Started = 0,           /* 0=Send notification on video decoding start after live streaming start.                                                    */
    HVCW_LiveEvent_Stopped,               /* 1=Send notification when live streaming stopped.                                                                           */
    HVCW_LiveEvent_Disconnected,          /* 2=Send notification if camera disconnected. Live streaming must be stopped with HVCW_StopLive().                           */
    HVCW_LiveEvent_Error,                 /* 3=Send notification if live streaming discontinuation error occurs. Live streaming must be stopped with HVCW_StopLive().   */
    HVCW_LiveEvent_FPS,                   /* 4=Send notification of FPS info                                                                                            */
    HVCW_LiveEvent_ChangeResolution       /* 5=Send notification when live streaming resolution changed.                                                                */
}HVCW_LIVE_EVENT;

/* Scheduler type */
typedef enum HVCW_ScheduleType{
    HVCW_ScheduleType_OneTime = 0,        /* 0=One time schedule    */
    HVCW_ScheduleType_Repeat,             /* 1=Repeat schedule      */
    HVCW_ScheduleType_Max
} HVCW_SCHEDULER_TYPE;

/* Event type */
typedef enum HVCW_EventProgramType{
    HVCW_EventProgramType_Sound = 0,      /* 0=Sound detection event    */
    HVCW_EventProgramType_Motion,         /* 1=Motion detection event   */
    HVCW_EventProgramType_Timer,          /* 2=Timer event              */
    HVCW_EventProgramType_Max
} HVCW_EVENT_PROGRAM_TYPE;

typedef enum HVCW_ScheduleFrequency{
    HVCW_ScheduleFrequency_Once = 0,      /* 0=Run once     */
    HVCW_ScheduleFrequency_Daily,         /* 1=Run daily    */
    HVCW_ScheduleFrequency_Weekday,       /* 2=Run weekly   */
    HVCW_ScheduleFrequency_Max
} HVCW_SCHEDULE_FREQUENCY;

typedef enum HVCW_SaveResult{
   HVCW_SaveResult_None = 0,              /* 0=Save none                    */
   HVCW_SaveResult_All,                   /* 1=Save all                     */
   HVCW_SaveResult_Detection,             /* 2=Save if OKAO conditions met  */
   HVCW_SaveResult_Max
} HVCW_SAVE_RESULT;

typedef enum HVCW_FRSaveResult{
    HVCW_FRSaveResult_None = 0,           /* 0=Save none            */
    HVCW_FRSaveResult_All,                /* 1=Save all             */
    HVCW_FRSaveResult_Known,              /* 2=Save if known user   */
    HVCW_FRSaveResult_Unknown,            /* 3=Save if unknown user */
    HVCW_FRSaveResult_Max
} HVCW_FR_SAVE_RESULT;

typedef enum HVCW_FileExt {
    HVCW_FileExt_Log = 2,                 /* 2=Log file             */
    HVCW_FileExt_MessageText,             /* 3=Message text file    */
    HVCW_FileExt_Sound,                   /* 4=Sound file           */
    HVCW_FileExt_JpgImage = 6,            /* 6=JPEG image file      */
    HVCW_FileExt_ThumbnailJpgImage = 8    /* 8=Thumbnail image file */
} HVCW_FILE_EXT;

typedef enum HVCW_OkaoFunction{
    HVCW_OkaoFunction_Body = 0,           /*  0=Human Body Detection        */
    HVCW_OkaoFunction_Hand,               /*  1=Hand Detection              */
    HVCW_OkaoFunction_Pet,                /*  2=Pet Detection               */
    HVCW_OkaoFunction_Face,               /*  3=Face Detection              */
    HVCW_OkaoFunction_Direction,          /*  4=Face Direction Estimation   */
    HVCW_OkaoFunction_Age,                /*  5=Age Estimation              */
    HVCW_OkaoFunction_Gender,             /*  6=Gender Estimation           */
    HVCW_OkaoFunction_Gaze,               /*  7=Gaze Estimation             */
    HVCW_OkaoFunction_Blink,              /*  8=Blink Estimation            */
    HVCW_OkaoFunction_Expression,         /*  9=Expression Estimation       */
    HVCW_OkaoFunction_Recognition,        /* 10=Face Recognition            */
    HVCW_OkaoFunction_Max
} HVCW_OKAO_FUNCTION;

/* Expression */
typedef enum HVCW_Expression {
    HVCW_Expression_Ignore = -1,          /* -1=Ignore                  */
    HVCW_Expression_Neutral = 0,          /*  0=Expression: neutral     */
    HVCW_Expression_Happiness,            /*  1=Expression: happiness   */
    HVCW_Expression_Surprise,             /*  2=Expression: surprise    */
    HVCW_Expression_Anger,                /*  3=Expression: anger       */
    HVCW_Expression_Sadness,              /*  4=Expression: sadness     */
    HVCW_Expression_Max
} HVCW_EXPRESSION;


/*-----------------------------------------------------------------------------*/
/*                                                                             */
/*                              STRUCTURE DEFINES                              */
/*                                                                             */
/*-----------------------------------------------------------------------------*/

/**
 * HVCW handle
 */
#ifndef HVCW_HANDLE
#define HVCW_HANDLE
    typedef HVCW_VOID* HHVC;
#endif /* HVCW_HANDLE */

#ifndef HVCW_C2W_HANDLE
#define HVCW_C2W_HANDLE
    typedef HVCW_VOID* C2W_HANDLE;
#endif /* HVCW_C2W_HANDLE */

/**
 * @struct HVCW_VideoFrame
 * YUV420P video frame storing struct
 */
typedef struct{
    HVCW_BYTE         *buffer[3];              /* Store luminance and color-difference info */
    HVCW_UINT32        stride[3];              /* Storage stride info of each buffer        */
    HVCW_UINT32        width;                  /* Width                                     */
    HVCW_UINT32        height;                 /* Height                                    */
} HVCW_VIDEOFRAME;

/**
 * @struct HVCW_Point
 * Coordinate struct
 */
typedef struct {
    HVCW_INT32 nX;                             /* X coordinates     */
    HVCW_INT32 nY;                             /* Y coordinates     */
} HVCW_POINT;

/**
 * @struct HVCW_Rect
 * Rectangle struct
 */
typedef struct {
    HVCW_INT32  nX;                            /* Start point x coordinates */
    HVCW_INT32  nY;                            /* Start point y coordinates */
    HVCW_INT32  nWidth;                        /* Width                     */
    HVCW_INT32  nHeight;                       /* Height                    */
} HVCW_RECT;

/**
 * @struct HVCW_DetectionParam
 * Motion detection parameter struct
 */
typedef struct {
    HVCW_RECT   rect;                          /* Rectangle     */
    HVCW_UINT8  sensitivity;                   /* Sensitivity   */
} HVCW_DETECTIONPARAM;

typedef struct {
    HVCW_INT32 nYear;                          /* Year (YYYY)   */
    HVCW_INT32 nMonth;                         /* Month         */
    HVCW_INT32 nDay;                           /* Day           */
    HVCW_INT32 nHour;                          /* Hour          */
    HVCW_INT32 nMinute;                        /* Minutes       */
} HVCW_SCHEDULE_TIME;

typedef struct {
    HVCW_INT32 nIndex;                           /* One time scheduler index (only for Onetime) */
    HVCW_SCHEDULE_FREQUENCY frequency;           /* Schedule cycle                              */
    HVCW_BOOL bWeekday[7];                       /* Day setting (only if frequency is Weekday)  */
    HVCW_SCHEDULE_TIME startTime;                /* Start time                                  */
    HVCW_SCHEDULE_TIME endTime;                  /* End time (only for Repeat)                  */
    HVCW_INT32 nInterval;                        /* Process interval                            */
    HVCW_BOOL abFunction[HVCW_OkaoFunction_Max]; /* OKAO function flag                          */
    HVCW_SAVE_RESULT saveLog;                    /* Log save method                             */
    HVCW_SAVE_RESULT saveImage;                  /* Image save method                           */
} HVCW_SCHEDULE_INFO;

typedef struct {
    HVCW_INT32  nBody;                         /* Threshold value (body detection)  */
    HVCW_INT32  nHand;                         /* Threshold value (hand detection)  */
    HVCW_INT32  nPet;                          /* Threshold value (pet detection)   */
    HVCW_INT32  nFace;                         /* Threshold value (face detection)  */
    HVCW_INT32  nRecognition;                  /* Threshold value (recognition)     */
} HVCW_OKAO_THRESHOLD;

typedef struct {
    HVCW_INT32  nMin;                          /* Min. value    */
    HVCW_INT32  nMax;                          /* Max. value    */
} HVCW_RANGE;

typedef struct {
    HVCW_RANGE  body;                          /* Detection size (body detection)   */
    HVCW_RANGE  hand;                          /* Detection size (hand detection)   */
    HVCW_RANGE  pet;                           /* Detection size (pet detection)    */
    HVCW_RANGE  face;                          /* Detection size (face detection)   */
} HVCW_OKAO_SIZE_RANGE;

typedef struct {
    HVCW_UINT32  nPose;                        /* Face direction    */
    HVCW_UINT32  nAngle;                       /* Face angle        */
} HVCW_OKAO_DETECTION_ANGLE_FACE;

typedef struct {
    HVCW_UINT32  nBody;                        /* Detection angle (body detection)  */
    HVCW_UINT32  nHand;                        /* Detection angle (hand detection)  */
    HVCW_UINT32  nPet;                         /* Detection angle (pet detection)   */
    HVCW_OKAO_DETECTION_ANGLE_FACE face;       /* Detection angle (face detection)  */
} HVCW_OKAO_DETECTION_ANGLE;

typedef struct {
    HVCW_INT32  nLR;                           /* Yaw angle             */
    HVCW_INT32  nUD;                           /* Pitch angle           */
    HVCW_INT32  nRoll;                         /* Roll angle            */
    HVCW_INT32  nConfidence;                   /* Degree of confidence  */
} HVCW_OKAO_RESULT_DIRECTION;

typedef struct {
    HVCW_INT32  nAge;                          /* Age                   */
    HVCW_INT32  nConfidence;                   /* Degree of confidence  */
} HVCW_OKAO_RESULT_AGE;

typedef struct {
    HVCW_INT32  nGender;                       /* Gender                */
    HVCW_INT32  nConfidence;                   /* Degree of confidence  */
} HVCW_OKAO_RESULT_GENDER;

typedef struct {
    HVCW_INT32  nLR;                           /* Yaw angle (left-right)    */
    HVCW_INT32  nUD;                           /* Pitch angle (up-down)     */
} HVCW_OKAO_RESULT_GAZE;

typedef struct {
    HVCW_INT32  nLeftEye;                      /* Left eye blink degree     */
    HVCW_INT32  nRightEye;                     /* Right eye blink degree    */
} HVCW_OKAO_RESULT_BLINK;

typedef struct {
    HVCW_INT32  anScore[HVCW_Expression_Max];  /* Score for each expression     */
    HVCW_INT32  nDegree;                       /* Expression degree (neg./pos.) */
} HVCW_OKAO_RESULT_EXPRESSION;

typedef struct {
    HVCW_INT32  nUID;                          /* User ID   */
    HVCW_INT32  nScore;                        /* Score     */
} HVCW_OKAO_RESULT_RECOGNITION;

typedef struct {
    HVCW_POINT  ptCenter;                      /* Center point          */
    HVCW_INT32  nSize;                         /* Size                  */
    HVCW_INT32  nConfidence;                   /* Degree of confidence  */
    HVCW_INT32  nPetType;                      /* Pet type              */
} HVCW_OKAO_RESULT_PET;

typedef struct {
    HVCW_POINT                   center;       /* Center point                          */
    HVCW_INT32                   nSize;        /* Size                                  */
    HVCW_INT32                   nConfidence;  /* Degree of confidence                  */
    HVCW_OKAO_RESULT_DIRECTION   direction;    /* Result (face direction estimation)    */
    HVCW_OKAO_RESULT_AGE         age;          /* Result (age estimation)               */
    HVCW_OKAO_RESULT_GENDER      gender;       /* Result (gender estimation)            */
    HVCW_OKAO_RESULT_GAZE        gaze;         /* Result (gaze estimation)              */
    HVCW_OKAO_RESULT_BLINK       blink;        /* Result (blink estimation)             */
    HVCW_OKAO_RESULT_EXPRESSION  expression;   /* Result (expression estimation)        */
    HVCW_OKAO_RESULT_RECOGNITION recognition;  /* Result (face detection)               */
} HVCW_OKAO_RESULT_FACE;

typedef struct {
    HVCW_POINT  center;                        /* Center point          */
    HVCW_INT32  nSize;                         /* Size                  */
    HVCW_INT32  nConfidence;                   /* Degree of confidence  */
} HVCW_OKAO_RESULT_DETECTION;

typedef struct {
    HVCW_INT32    nCount;                      /* Result count (body detection) */
    HVCW_OKAO_RESULT_DETECTION  body[35];      /* Result (body)                 */
} HVCW_OKAO_RESULT_BODIES;

typedef struct {
    HVCW_INT32    nCount;                      /* Result count (hand detection) */
    HVCW_OKAO_RESULT_DETECTION  hand[35];      /* Result (hand)                 */
} HVCW_OKAO_RESULT_HANDS;

typedef struct {
    HVCW_INT32    nCount;                      /* Result count (pet detection)  */
    HVCW_OKAO_RESULT_PET    pet[10];           /* Result (pet)                  */
} HVCW_OKAO_RESULT_PETS;

typedef struct {
    HVCW_INT32    nCount;                      /* Result count (face detection) */
    HVCW_OKAO_RESULT_FACE   face[35];          /* Result (face)                 */
} HVCW_OKAO_RESULT_FACES;

typedef struct {
    HVCW_OKAO_RESULT_BODIES bodies;            /* Result (body)     */
    HVCW_OKAO_RESULT_HANDS  hands;             /* Result (hand)     */
    HVCW_OKAO_RESULT_PETS   pets;              /* Result (pet)      */
    HVCW_OKAO_RESULT_FACES  faces;             /* Result (face)     */
} HVCW_OKAO_RESULT;

typedef struct {
    HVCW_CHAR   acName[40];                    /* File name */
    HVCW_INT32  nSize;                         /* File size */
    HVCW_UINT32 Reserved;                      /* Reserved  */
} HVCW_FILEINFO;

typedef struct {
    HVCW_RECT area;             /* Motion detection area        */
    HVCW_INT32 nSensitivity;    /* Motion detection sensitivity */
    HVCW_UINT32 unDuration;     /* Motion detection duration    */
    HVCW_UINT32 unRatio;        /* Motion detection ratio       */
    HVCW_UINT32 unOffPeriod;    /* Event interval               */
} HVCW_EP_MOTION_EVENT;

typedef struct {
    HVCW_INT32  nSensitivity;   /* Sound detection sensitivity  */
    HVCW_UINT32 unDuration;     /* Sound detection duration     */
    HVCW_UINT32 unRatio;        /* Sound detection ratio        */
    HVCW_UINT32 unOffPeriod;    /* Event interval               */
} HVCW_EP_SOUND_EVENT;

typedef struct {
    HVCW_UINT32 unInterval;     /* Event interval */
} HVCW_EP_TIMER_EVENT;

typedef struct {
    HVCW_BOOL bEnable;          /* Body detection function flag     */
    HVCW_INT32 nCount;          /* Decision value (detection count) */
} HVCW_EP_BODY;

typedef struct {
    HVCW_BOOL bEnable;          /* Function flag (pet detection)    */
    HVCW_INT32 nCount;          /* Decision value (detection count) */
} HVCW_EP_PET;

typedef struct {
    HVCW_BOOL bEnable;          /* Function flag (face detection)   */
    HVCW_INT32 nCount;          /* Decision value (detection count) */
} HVCW_EP_FACE;

typedef struct {
    HVCW_BOOL bEnable;          /* Function flag (age estimation)           */
    HVCW_RANGE stAgeRange;      /* Decision value (age)                     */
    HVCW_INT32 nConfidence;     /* Threshold value (degree of confidence)   */
} HVCW_EP_AGE;

typedef struct {
    HVCW_BOOL bEnable;          /* Function flag (gender estimation)        */
    HVCW_INT32 nGender;         /* Decision value (gender)                  */
    HVCW_INT32 nConfidence;     /* Threshold value (degree of confidence)   */
} HVCW_EP_GENDER;

typedef struct {
    HVCW_BOOL bEnable;          /* Function flag (expression estimation)    */
    HVCW_EXPRESSION expression; /* Decision value (expression)              */
    HVCW_INT32 nScore;          /* Threshold value (score decision)         */
    HVCW_RANGE degreeRange;     /* Decision value (expression degree)       */
} HVCW_EP_EXPRESSION;

typedef struct {
    HVCW_BOOL bEnable;          /* Function flag (face recognition)  */
} HVCW_EP_RECOGNITION;

typedef struct {
    HVCW_BOOL bEnable;          /* Push notification flag           */
    HVCW_FILEINFO fileInfo;     /* Push notification message file   */
} HVCW_EP_PUSH_ALERT;

typedef struct {
    HVCW_BOOL bEnable;          /* Sound output flag        */
    HVCW_FILEINFO fileInfo;     /* Sound output sound file  */
} HVCW_EP_SOUND;

typedef struct {
    HVCW_EP_PUSH_ALERT pushAlert; /* Push notification settings */
    HVCW_EP_SOUND sound;          /* Sound output settings      */
} HVCW_EP_NOTIFICATION;

typedef struct {
    HVCW_EP_BODY        body;           /* Decision value (body)        */
    HVCW_EP_PET         pet;            /* Decision value (pet)         */
    HVCW_EP_FACE        face;           /* Decision value (face)        */
    HVCW_EP_AGE         age;            /* Decision value (age)         */
    HVCW_EP_GENDER      gender;         /* Decision value (gender)      */
    HVCW_EP_EXPRESSION  expression;     /* Decision value (expression)  */
    HVCW_EP_RECOGNITION recognition;    /* Decision value (recognition) */
} HVCW_EP_OKAO_PROCESS;

typedef struct {
    HVCW_SAVE_RESULT     saveLog;       /* Log save                 */
    HVCW_SAVE_RESULT     saveImage;     /* Image save               */
    HVCW_EP_NOTIFICATION notification;  /* Notification settings    */
} HVCW_EP_POST_PROCESS;

typedef struct {
    HVCW_INT32 nUserID;                     /* User ID */
    HVCW_FILEINFO fileInfo;                 /* Target file */
} HVCW_EP_KNOWNUSER;

typedef struct {
    HVCW_EP_KNOWNUSER knownUser[20];        /* Process if registered user       */
    HVCW_EP_PUSH_ALERT unknownUser;         /* Process if non-registered user   */
} HVCW_EP_FR_PUSH_ALERT;

typedef struct {
    HVCW_EP_KNOWNUSER knownUser[20];        /* Registered user      */
    HVCW_EP_SOUND unknownUser;              /* Non-registered user  */
} HVCW_EP_FR_SOUND;

typedef struct {
    HVCW_EP_FR_PUSH_ALERT pushAlert;        /* Push notification settings   */
    HVCW_EP_FR_SOUND      sound;            /* Sound output settings        */
} HVCW_EP_FR_NOTIFICATION;

typedef struct {
    HVCW_FR_SAVE_RESULT     saveImage;      /* Image save                               */
    HVCW_EP_FR_NOTIFICATION notification;   /* Face recognition notification settings   */
} HVCW_EP_FR_POST_PROCESS;

typedef struct {
    HVCW_INT32 nIndex;                      /* Motion detection event index (for motion detection only) */
    HVCW_VOID* eventProgram;                /* Event settings                                           */
} HVCW_EVENT_PROGRAM;

typedef struct {
    HVCW_EP_MOTION_EVENT motionEvent;       /* Motion detection event settings                  */
    HVCW_EP_OKAO_PROCESS okaoProcess;       /* OKAO process settings                            */
    HVCW_EP_POST_PROCESS postProcess;       /* Notification process settings                    */
    HVCW_EP_FR_POST_PROCESS frPostProcess;  /* Notification process settings for recognition    */
} HVCW_EVENT_PROGRAM_MOTION;

typedef struct {
    HVCW_EP_SOUND_EVENT soundEvent;         /* Sound detection event settings                   */
    HVCW_EP_OKAO_PROCESS okaoProcess;       /* OKAO process settings                            */
    HVCW_EP_POST_PROCESS postProcess;       /* Notification process settings                    */
    HVCW_EP_FR_POST_PROCESS frPostProcess;  /* Notification process settings for recognition    */
} HVCW_EVENT_PROGRAM_SOUND;

typedef struct {
    HVCW_EP_TIMER_EVENT timerEvent;         /* Timer event settings                             */
    HVCW_EP_OKAO_PROCESS okaoProcess;       /* OKAO process settings                            */
    HVCW_EP_POST_PROCESS postProcess;       /* Notification process settings                    */
    HVCW_EP_FR_POST_PROCESS frPostProcess;  /* Notification process settings for recognition    */
} HVCW_EVENT_PROGRAM_TIMER;

typedef struct {
    HVCW_UINT32          ucTotalSize;       /* Total storage size (KB)  */
    HVCW_UINT32          ucUsedSize;        /* Used storage size (KB)   */
    HVCW_UINT32          ucFreeSize;        /* Free storage size (KB)   */
    HVCW_STORAGE_STATUS  storageStatus;     /* Storage status           */
} HVCW_STORAGEINFO;

/**********************************************************/
/* Callback API                                           */
/**********************************************************/
/* Rendering request callback function */
typedef HVCW_INT32 (*HVCW_RequestRenderingCallback)(HVCW_BOOL bVideo, HVCW_VOID *pUserParam, 
                                                    HVCW_VOID *pRenderInfo, HVCW_UINT32 unInfoLen, HVCW_UINT32 unTimeStamp);

/* Live event notification callback function */
typedef HVCW_INT32 (*HVCW_LiveEventCallback)(HVCW_INT32 nEventId, HVCW_VOID *pUserParam, HVCW_VOID *pEventInfo);

/* Event notification callback function */
typedef HVCW_INT32 (*HVCW_EventCallback)(HVCW_INT32 nEventId, HVCW_VOID *pUserParam, HVCW_VOID *pEventInfo);


/**********************************************************/
/* HVCW SDK API                                           */
/**********************************************************/
/* Get SDK version function */
HVC_API HVCW_INT32 HVCW_GetVersion(HVCW_UINT8 *pucMajor, HVCW_UINT8 *pucMinor, HVCW_UINT8 *pucRelease);

/* Connect camera function */
HVC_API HVCW_INT32 HVCW_Connect(HHVC hHVC, HVCW_UINT8 *pucCameraId, HVCW_UINT8 *pucAccessToken);
/* Disconnect camera function */
HVC_API HVCW_INT32 HVCW_Disconnect(HHVC hHVC);

/* Get camera firmware version function */
HVC_API HVCW_INT32 HVCW_GetCameraVersion(HHVC hHVC, HVCW_UINT8 aucVersion[128]);

/* Update camera firmware function */
HVC_API HVCW_INT32 HVCW_UpdateFirmware(HHVC hHVC);

/* Set camera night vision mode function */
HVC_API HVCW_INT32 HVCW_SetNightVisionMode(HHVC hHVC, HVCW_NIGHT_VISION_MODE mode);
/* Get camera night vision mode function */
HVC_API HVCW_INT32 HVCW_GetNightVisionMode(HHVC hHVC, HVCW_NIGHT_VISION_MODE *pMode);

/* Set camera night vision status function */
HVC_API HVCW_INT32 HVCW_SetNightVisionStatus(HHVC hHVC, HVCW_NIGHT_VISION_STATUS status);
/* Get camera night vision status function */
HVC_API HVCW_INT32 HVCW_GetNightVisionStatus(HHVC hHVC, HVCW_NIGHT_VISION_STATUS *pStatus);

/* Enable event monitor function */
HVC_API HVCW_INT32 HVCW_EnableEventMonitor(HHVC hHVC, HVCW_VOID *pUserParam, HVCW_EventCallback callbackFunc);
/* Disable event monitor function */
HVC_API HVCW_INT32 HVCW_DisableEventMonitor(HHVC hHVC);

/* Set camera speaker volume function */
HVC_API HVCW_INT32 HVCW_SetSpeakerVolume(HHVC hHVC, HVCW_UINT32 unVolume);
/* Get camera speaker volume function */
HVC_API HVCW_INT32 HVCW_GetSpeakerVolume(HHVC hHVC, HVCW_UINT32 *punVolume);

/* Set mic sensitivity function */
HVC_API HVCW_INT32 HVCW_SetMicSensitivity(HHVC hHVC, HVCW_UINT32 unSensitivity);
/* Get mic sensitivity function */
HVC_API HVCW_INT32 HVCW_GetMicSensitivity(HHVC hHVC, HVCW_UINT32 *punSensitivity);

/* Get camera WiFi RSSI value function */
HVC_API HVCW_INT32 HVCW_GetWiFiRSSI(HHVC hHVC, HVCW_INT32 *pnWifiRssi);

/* Generate network setting sound file function  */
HVC_API HVCW_INT32 HVCW_GenerateDataSoundFile(HVCW_UINT8 *pucTargetFile, HVCW_UINT8 *pucSSID, HVCW_UINT8 *pucPassword, HVCW_UINT8 *pusAccessToken);

/* Format storage function */
HVC_API HVCW_INT32 HVCW_RequestStorageFormat(HHVC hHVC, HVCW_STORAGE_FORMAT_RESULT_CODE *pResultCode);

/* Get camera connection type function */
HVC_API HVCW_INT32 HVCW_GetConnectionType(HHVC hHVC, HVCW_CONNECTION_TYPE *pConnType);

/* Start live streaming function */
HVC_API HVCW_INT32 HVCW_StartLive(HHVC hHVC,
                                  HVCW_VOID *pUserParam, 
                                  HVCW_VIDEO_RESOLUTION videoResolution, 
                                  HVCW_RequestRenderingCallback renderingCallback, 
                                  HVCW_LiveEventCallback eventCallback);
/* Stop live streaming function */
HVC_API HVCW_INT32 HVCW_StopLive(HHVC hHVC);

/* Free video frame buffer function */
HVC_API HVCW_INT32 HVCW_FreeDecodedVideoBuffer(HHVC hHVC, const HVCW_VOID *pBuffer);

/* Free sound data buffer function */
HVC_API HVCW_INT32 HVCW_FreeDecodedAudioBuffer(HHVC hHVC, const HVCW_VOID *pBuffer);

/* Enter talk mode function */
HVC_API HVCW_INT32 HVCW_EnterTalkMode(HHVC hHVC);
/* Exit talk mode function */
HVC_API HVCW_INT32 HVCW_ExitTalkMode(HHVC hHVC);

/* Transfer sound data function */
HVC_API HVCW_INT32 HVCW_TransferSoundData(HHVC hHVC, HVCW_BYTE *pucSoundData, HVCW_UINT32 unSoundLen);

/* Set live streaming resolution function */
HVC_API HVCW_INT32 HVCW_SetVideoResolution(HHVC hHVC, HVCW_VIDEO_RESOLUTION videoResolution);
/* Get live streaming resolution function */
HVC_API HVCW_INT32 HVCW_GetVideoResolution(HHVC hHVC, HVCW_VIDEO_RESOLUTION *pVideoResolution);

/* Enable sound detection function */
HVC_API HVCW_INT32 HVCW_EnableSoundDetection(HHVC hHVC, HVCW_UINT32 unSensitivity);
/* Disable sound detection function */
HVC_API HVCW_INT32 HVCW_DisableSoundDetection(HHVC hHVC);

/* Get sound detection status function */
HVC_API HVCW_INT32 HVCW_GetSoundDetection(HHVC hHVC, HVCW_BOOL *pbOn, HVCW_UINT32 *punSensitivity);

/* Enable motion detection function */
HVC_API HVCW_INT32 HVCW_EnableMotionDetection(HHVC hHVC, HVCW_UINT32 unDetectionParamsCount, const HVCW_DETECTIONPARAM aDetectionParams[10]);
/* Disable motion detection function */
HVC_API HVCW_INT32 HVCW_DisableMotionDetection(HHVC hHVC);

/* Get motion detection status function */
HVC_API HVCW_INT32 HVCW_GetMotionDetection(HHVC hHVC,
                                           HVCW_BOOL *pbOn,
                                           HVCW_UINT32 *punDetectionParamCount,
                                           HVCW_DETECTIONPARAM aDetectionParams[10]);

/* Get camera MAC address function */
HVC_API HVCW_INT32 HVCW_GetCameraMacAddress(HHVC hHVC, HVCW_UINT8 aucMACAddress[32]);

/* Check for new camera firmware function */
HVC_API HVCW_INT32 HVCW_CheckNewFirmware(HHVC hHVC, HVCW_UINT8 aucVersion[128]);

/* Get storage info function */
HVC_API HVCW_INT32 HVCW_GetStorageInfo(HHVC hHVC, HVCW_STORAGEINFO *pStorageInfo);

/* Check for fast download support function */
HVC_API HVCW_INT32 HVCW_IsSupportDownloadFileFast(HHVC hHVC, HVCW_BOOL *pbDownloadFileFast);

/* Download file (fast) function */
HVC_API HVCW_INT32 HVCW_DownloadFile_Fast(HHVC hHVC,
                                          HVCW_FILE_EXT fileExt, 
                                          const HVCW_CHAR *pcFileName,
                                          HVCW_UINT32 unFileNameLength,
                                          HVCW_INT32 *pnSize,
                                          HVCW_UINT8 **pucBuffer);

/* Free file data buffer function */
HVC_API HVCW_INT32 HVCW_FreeFileBuffer(HHVC hHVC, const HVCW_UINT8 *pucBuffer);

/*--------------------------------------------------------*/
/* HVCW SDK OKAO API                                      */
/*--------------------------------------------------------*/
/* Create HVCW handle */
HVC_API HHVC HVCW_CreateHandle(void);
/* Delete HVCW handle */
HVC_API HVCW_INT32 HVCW_DeleteHandle(HHVC hHVC);

/* Set app ID */
HVC_API HVCW_INT32 HVCW_SetAppID(HHVC hHVC, HVCW_INT32 nAppID, HVCW_UINT8 *pucReturnStatus);
/* Get app ID */
HVC_API HVCW_INT32 HVCW_GetAppID(HHVC hHVC, HVCW_INT32 *pnAppID, HVCW_UINT8 *pucReturnStatus);

/* Set OKAO mode */
HVC_API HVCW_INT32 HVCW_SetOkaoMode(HHVC hHVC, HVCW_BOOL bOkaoMode, HVCW_UINT8 *pucReturnStatus);
/* Get OKAO mode */
HVC_API HVCW_INT32 HVCW_GetOkaoMode(HHVC hHVC, HVCW_BOOL *pbOkaoMode, HVCW_UINT8 *pucReturnStatus);

/* Get number of files */
HVC_API HVCW_INT32 HVCW_GetFileCount(HHVC hHVC, HVCW_FILE_EXT fileExt, HVCW_UINT32 *punFileCount, HVCW_UINT8 *pucReturnStatus);

/* Get file info */
HVC_API HVCW_INT32 HVCW_GetFileInfo(HHVC hHVC, HVCW_FILE_EXT fileExt, HVCW_UINT32 unFileIndex, HVCW_FILEINFO *pFileInfo, HVCW_UINT8 *pucReturnStatus);

/* File download */
HVC_API HVCW_INT32 HVCW_DownloadFile(HHVC hHVC, const HVCW_FILEINFO *pFileInfo, HVCW_UINT8 *pucBuffer, HVCW_UINT8 *pucReturnStatus);
/* File upload */
HVC_API HVCW_INT32 HVCW_UploadFile(HHVC hHVC, HVCW_CHAR acFileName[40], HVCW_INT32 nBufferSize, const HVCW_UINT8 *pucBuffer, HVCW_UINT8 *pucReturnStatus);

/* Delete file */
HVC_API HVCW_INT32 HVCW_DeleteFile(HHVC hHVC, const HVCW_FILEINFO *pFileInfo, HVCW_UINT8 *pucReturnStatus);

/* Get OKAO process image size */
HVC_API HVCW_INT32 HVCW_GetLastOkaoImageSize(HHVC hHVC, HVCW_INT32 *pnImgBufSize, HVCW_UINT8 *pucReturnStatus);

/* Get OKAO process image */
HVC_API HVCW_INT32 HVCW_GetLastOkaoImage(HHVC hHVC, HVCW_INT32 nImgBufSize, HVCW_UINT8 *pucImage, HVCW_UINT8 *pucReturnStatus);

/* Take picture */
HVC_API HVCW_INT32 HVCW_TakePicture(HHVC hHVC, HVCW_FILEINFO *pFileInfo, HVCW_UINT8 *pucReturnStatus);

/* Set threshold value */
HVC_API HVCW_INT32 HVCW_OKAO_SetThreshold(HHVC hHVC, const HVCW_OKAO_THRESHOLD *pThreshold, HVCW_UINT8 *pucReturnStatus);
/* Get threshold value */
HVC_API HVCW_INT32 HVCW_OKAO_GetThreshold(HHVC hHVC, HVCW_OKAO_THRESHOLD *pThreshold, HVCW_UINT8 *pucReturnStatus);

/* Set detection size */
HVC_API HVCW_INT32 HVCW_OKAO_SetSizeRange(HHVC hHVC, const HVCW_OKAO_SIZE_RANGE *pSizeRange, HVCW_UINT8 *pucReturnStatus);
/* Get detection size */
HVC_API HVCW_INT32 HVCW_OKAO_GetSizeRange(HHVC hHVC, HVCW_OKAO_SIZE_RANGE *pSizeRange, HVCW_UINT8 *pucReturnStatus);

/* Set detection angle */
HVC_API HVCW_INT32 HVCW_OKAO_SetDetectionAngle(HHVC hHVC, const HVCW_OKAO_DETECTION_ANGLE *pDetectionAngle, HVCW_UINT8 *pucReturnStatus);
/* Get detection angle */
HVC_API HVCW_INT32 HVCW_OKAO_GetDetectionAngle(HHVC hHVC, HVCW_OKAO_DETECTION_ANGLE *pDetectionAngle, HVCW_UINT8 *pucReturnStatus);

/* Run OKAO */
HVC_API HVCW_INT32 HVCW_OKAO_Execute(HHVC hHVC, HVCW_BOOL abUseFunction[HVCW_OkaoFunction_Max], HVCW_OKAO_RESULT *pResult, HVCW_UINT8 *pucReturnStatus);

/* Register Album */
HVC_API HVCW_INT32 HVCW_ALBUM_Register(HHVC hHVC, HVCW_INT32 nUserID, HVCW_INT32 nDataID, HVCW_OKAO_RESULT_DETECTION *pFaceResult, HVCW_FILEINFO *pFileInfo, HVCW_UINT8 *pucReturnStatus);

/* Change user name */
HVC_API HVCW_INT32 HVCW_ALBUM_SetUserName(HHVC hHVC, HVCW_INT32 nUserID, const HVCW_CHAR acName[44], HVCW_UINT8 *pucReturnStatus);

/* Get user name */
HVC_API HVCW_INT32 HVCW_ALBUM_GetUserName(HHVC hHVC, HVCW_INT32 nUserID, HVCW_CHAR acName[44], HVCW_UINT8 *pucReturnStatus);

/* Delete registration data */
HVC_API HVCW_INT32 HVCW_ALBUM_DeleteData(HHVC hHVC, HVCW_INT32 nUserID, HVCW_INT32 nDataID, HVCW_UINT8 *pucReturnStatus);

/* Delete all registration data */
HVC_API HVCW_INT32 HVCW_ALBUM_DeleteAllData(HHVC hHVC, HVCW_UINT8 *pucReturnStatus);

/* Get registration status */
HVC_API HVCW_INT32 HVCW_ALBUM_GetRegistrationStatus (HHVC hHVC, HVCW_INT32 nUserID, HVCW_BOOL abExist[10], HVCW_UINT8 *pucReturnStatus);

/* Get Album size */
HVC_API HVCW_INT32 HVCW_ALBUM_GetSize(HHVC hHVC, HVCW_INT32 *pnAlbumSize, HVCW_UINT8 *pucReturnStatus);

/* Download Album */
HVC_API HVCW_INT32 HVCW_ALBUM_Download(HHVC hHVC, HVCW_UINT8 *pucAlbum, HVCW_UINT8 *pucReturnStatus);
/* Upload Album */
HVC_API HVCW_INT32 HVCW_ALBUM_Upload(HHVC hHVC, HVCW_INT32 nAlbumSize, const HVCW_UINT8 *pucAlbum, HVCW_UINT8 *pucReturnStatus);

/* Write Album data on flash */
HVC_API HVCW_INT32 HVCW_ALBUM_Save(HHVC hHVC, HVCW_UINT8 *pucReturnStatus);

/* Set schedule */
HVC_API HVCW_INT32 HVCW_SetScheduler(HHVC hHVC, HVCW_SCHEDULER_TYPE schedulerType, HVCW_BOOL bEnable, const HVCW_SCHEDULE_INFO *pSchedule, HVCW_UINT8 *pucReturnStatus);
/* Get schedule */
HVC_API HVCW_INT32 HVCW_GetScheduler(HHVC hHVC, HVCW_SCHEDULER_TYPE schedulerType, HVCW_BOOL *pbEnable, HVCW_SCHEDULE_INFO *pSchedule, HVCW_UINT8 *pucReturnStatus);

/* Set event program */
HVC_API HVCW_INT32 HVCW_SetEventProgram(HHVC hHVC, HVCW_EVENT_PROGRAM_TYPE eventProgramType, HVCW_BOOL bEnable, const HVCW_EVENT_PROGRAM *pEventProgram, HVCW_UINT8 *pucReturnStatus);
/* Get event program */
HVC_API HVCW_INT32 HVCW_GetEventProgram(HHVC hHVC, HVCW_EVENT_PROGRAM_TYPE eventProgramType, HVCW_BOOL *pbEnable, HVCW_EVENT_PROGRAM *pEventProgram, HVCW_UINT8 *pucReturnStatus);


#ifdef __cplusplus
} /* closing brace for extern "C" */
#endif

#endif /* __HVCWSDKAPI_H */
