/*******************************************************************************
Description: 网络通讯库和数据获取SDK头文件，包括PTZ和监听报警的封装
*******************************************************************************/

#ifndef _IPC_SDK_NET_JFIOAF419848KL_H_
#define _IPC_SDK_NET_JFIOAF419848KL_H_

/******************************************************************************
SDKNET编译参数定义
*******************************************************************************/
#ifdef WIN32 //windows平台

#if defined(IPCSDK_NET_DLL)
    #define IPCSDK_API  __declspec(dllexport)
#else
    #define IPCSDK_API  __declspec(dllimport)
	#include <windows.h>
#endif
#define STDCALL  __stdcall
#define CALLBACK __stdcall

#else //其他平台

#define IPCSDK_API extern "C"
#define STDCALL
#define CALLBACK
#define WORD	unsigned short
#define DWORD	unsigned long
#define LPDWORD	DWORD*
#define BOOL	int
#define TRUE	1
#define FALSE	0
#define BYTE	unsigned char
#define LONG	long
#define UINT	unsigned int
#define HDC		void*
#define HWND	void*
#define LPVOID	void*
#define NULL	0
typedef struct tagRECT
{
    long left;
    long top;
    long right;
    long bottom;
}RECT;
typedef struct tagPOINT
{
    long x;
    long y;
}POINT;

#endif

#ifdef __cplusplus
extern "C" {
#endif

#define SERIALNO_LEN       48    /**序列号长度*/
#define MAX_NAME_LEN_32    32    /**最大名称长度*/
#define MAX_VERSION_LEN    16    /**版本号长度*/
#define MAX_URL_LEN        128   /**最大URL字符串长度(用于解码器视频切换)*/
#define MAX_PARKING_PLACE_NUM 3	 /**最大车位数*/

#define DEVICE_TYPE_IPC 0
#define DEVICE_TYPE_NVR 1

/******************************************************************************
SDKNET通用错误码定义，对应IPCNET_GetLastError接口的返回值，NET库通用错误码的范围：0-499
*******************************************************************************/
//通用错误
#define ERR_NET_SUCCEED        0  /**< 执行成功 */
#define ERR_NET_FAIL           1  /**< 执行失败 */
#define ERR_NET_INVALIDPARAM   2  /**< 输入参数非法 */
#define ERR_NET_NOMEMORY       3  /**< 内存分配失败 */
#define ERR_NET_SYSFAIL        4  /**< 系统通用错误 */
#define ERR_NET_USERNAME       5  /**< 用户名错误 */
#define ERR_NET_PASSWORD       6  /**< 密码错误 */
#define ERR_NET_NOINIT         7  /**< 没有初始化 */
#define ERR_NET_INVALIDCHANNEL 8  /**< 通道号错误 */
#define ERR_NET_NOLOGIN        9  /**< 没有登录 */
//网络错误
#define ERR_NET_OPENSOCKET    10  /**< 创建SOCKET错误 */
#define ERR_NET_SEND          11  /**< 向设备发送网络数据失败 */
#define ERR_NET_RECV          12  /**< 从设备接收网络数据失败 */
#define ERR_NET_CONNNECT      13  /**< 连接设备失败，设备不在线、设备忙或网络原因引起的连接超时等 */
#define ERR_NET_AUDIOFULL     14  /**< 设备的音频连接已满 */

#define ERR_NET_DEVTYPE_PTZSURPPORT  15  /**< 不支持PTZ控制,设备类型错误 */
#define ERR_NET_NODEVTYPE            16  /**< 获取设备类型失败 */					 
#define ERR_NET_NODEVPARAMTYPE       17  /**< 不支持该设备类型,没有配置对象 */
#define ERR_NET_IPOFFLINE            18  /**< IP不在线 */
#define ERR_NET_RET_INVALIDPARAM     19  /**< 设备返回参数错误 */

#define ERR_NET_CONNNECT_NBIO        20  /**< 连接设备，设置非阻塞模式失败 */
#define ERR_NET_CONNNECT_SELECT      21  /**< 连接设备，设置select模式超时时间失败 */
#define ERR_NET_CONNNECT_ISSET       22  /**< 连接设备，设置select模式置位失败 */
#define ERR_NET_CONNNECT_BIO         23  /**< 连接设备，设置阻塞模式失败 */


/******************************************************************************
解码器错误码定义,范围1000-1499.
*******************************************************************************/
#define ERR_DEC_SUCCEED               1000  /**< 执行成功 */
#define ERR_DEC_SYSTEM                1003  /**< 系统内部错误 */
#define ERR_DEC_UNKNOWN               1004  /**< 未知错误 */
#define ERR_DEC_IPADDR_CONFLICT       1005  /**< IP地址冲突 */						 
#define ERR_DEC_DEVICE_NOTYPE         1008  /**< 不支持该设备类型，不是解码器 */
#define ERR_DEC_NETWORK_FAIL_CONNECT  1009  /**< 连接设备失败。设备不在线或网络原因引起的连接超时等 */
#define ERR_DEC_NETWORK_SEND		  1010  /**< 向设备发送失败 */
#define ERR_DEC_NETWORK_RECV          1011  /**< 从设备接收数据失败 */
#define ERR_DEC_NETWORK_RECV_TIMEOUT  1012  /**< 从设备接收数据超时 */
#define ERR_DEC_NETWORK_INVALIDATE    1013  /**< ip地址,子网掩码,网关不匹配 */
#define ERR_DEC_INVALIDATE_URL        1014  /**< 非法的URL */
#define ERR_DEC_NOMONITOR             1015  /**< 指定显示器不存在 */
#define ERR_DEC_NOWINDOW              1016  /**< 指定窗口不存在 */
#define ERR_DEC_PICTURE_NONUM         1017  /**< 不支持该画面数 */
#define ERR_DEC_PICTURE_SHIFT_FISRT   1018  /**< 画面数导航切换，已经达最早状态 */
#define ERR_DEC_PICTURE_SHIFT_LAST    1019  /**< 画面数导航切换，已经达最后状态 */			


/******************************************************************************
SDKNET通用数据结构定义
*******************************************************************************/
/**
* @struct tagNetExceptionType
* @brief 网络异常信息类型参数
* @attention
*/
typedef enum tagNetExceptionType
{
    NETEXCEPTION_RELEASE = 0, /**< 异常信息已解除，即恢复正常 */
    NETEXCEPTION_FULLCONNECT, /**< 设备端视频连接已超过最大值 */
    NETEXCEPTION_RECONNECT,   /**< 当前连接已经断开，将与设备进行重连 */
    NETEXCEPTION_STOPED,      /**< 与设备的连接完全断开，不再重连 */
    NETEXCEPTION_LOGINFAILED, /**< 用户名/密码错误导致的登录设备失败，将会自动进行重连 */
} E_NET_EXCEPTION_TYPE;
/**
* @struct tagPlayParam
* @brief 编码类型参数
* @attention
*/
typedef enum tagEncodeType
{
    ENCODE_MPEG4 = 1,   /**< MPEG4编码 */
    ENCODE_H264,        /**< H264编码 */
    ENCODE_H264_Hi3510, /**< H264 3510编码 */
    ENCODE_MJPEG,       /**< MJPEG编码，暂无用 */
	ENCODE_H265,        /**< H265编码 */
} E_ENCODE_TYPE;

/**
* @struct tagRealDataInfo
* @brief 实时数据流参数
* @attention
*/
typedef struct tagRealDataInfo
{
    unsigned long lChannel;    /**< 通道号，从0开始 */
    unsigned long lStreamMode; /**< 码流类型，0-主码流，1-子码流 */
    E_ENCODE_TYPE eEncodeType; /**< 编码类型*/
}S_REALDATA_INFO;

/**
* @enum tagRealDataType
* @brief 回调实时流的数据类型
* @attention 无
*/
typedef enum tagRealDataType
{
    REALDATA_HEAD,   /**< 实时流的头数据 */
    REALDATA_VIDEO,  /**< 实时视频流数据（包括复合流和音视频分开的视频流数据） */
    REALDATA_AUDIO,  /**< 实时音频流数据 */
} E_REALDATA_TYPE;

/**
* @struct tagTalkParam
* @brief 语音对讲的参数
* @attention
*/
typedef struct tagTalkParam
{
    unsigned int nAudioEncode;    /**< 预留，音频编码类型 */
    unsigned int nSamplesPerSec;  /**< 采样频率，取值为：8000，11025，22050，44100 */
    unsigned int nBitsPerSample;  /**< 预留，采样位数，如：8，16 */
	unsigned int nSampleFrmSize;  /**< 采样单位帧缓冲（发送）大小， 512或640（编码）*/
}S_TALK_PARAM;

/**
* @struct tagAlarmerInfo
* @brief 报警源设备信息
* @attention 无
*/
typedef struct tagAlarmerInfo
{   
    char sDeviceIP[128];      /**< 报警源设备的IP地址 */
    unsigned short wLinkPort; /**< 报警源设备的通讯端口 */
}S_ALARMER_INFO;

/**
* @enum tagRealDataType
* @brief 报警类型
* @attention 无
*/
typedef enum tagAlarmType
{
    ALARM_UNKNOWN = 0,/**< 未知类型报警 */
    ALARM_INPUT,      /**< 继电器输入报警 */
    ALARM_MOTION,     /**< 移动侦测报警 */
    ALARM_SHELTER,    /**< 视频遮挡报警 */
    ALARM_VIDEOLOST,  /**< 视频丢失报警 */
    ALARM_DEVICEERR,  /**< 预留，设备异常报警 */
}E_ALARM_TYPE;
/**
* @struct tagAlarmerDeviceInfo
* @brief 报警信息
* @attention 无
*/
typedef struct tagAlarmInfo
{
    E_ALARM_TYPE eAlarmType;    /**< 报警类型 */
    unsigned int nAlarmID;      /**< 报警通道号，从1开始，通常表示设备通道号，继电器输入报警时表示继电器输入号；设备异常类型时表示：1-硬盘满，2-硬盘出错，3-网络断开，4-非法访问，5-网络冲突 */ 
    unsigned char cAlarmStatus; /**< 报警状态，0-无报警，1-有报警。继电器输入报警时， 0-报警取消，1-报警触发，2-报警持续 */
    unsigned char cAlarmArea;   /**< 报警区域号，移动侦测和视频遮挡有效，区域号代表哪个区域发生报警 */
}S_ALARM_INFO;

/**
* @enum tagPtzCommand
* @brief 云台控制命令
* @attention 同时描述了IPCNET_PTZControl接口中2个参数对应的含义和设置，p1表示参数iParam1，p2表示参数iParam2
*/
typedef enum tagPtzCommand
{    
    //基本命令
    ZOOM_TELE,      /**< 焦距变大(倍率变大,视野缩小,目标放大),p1速度 */
    ZOOM_WIDE,      /**< 焦距变小(倍率变小,视野放大,目标缩小),p1速度 */
    FOCUS_NEAR,     /**< 焦点前调(目标靠近),p1速度 */
    FOCUS_FAR,      /**< 焦点后调(目标远离),p1速度 */
    IRIS_OPEN,      /**< 光圈扩大,p1速度 */
    IRIS_CLOSE,     /**< 光圈缩小,p1速度 */
    UP,             /**< 上转,p1水平速度,p2垂直速度 */
    DOWN,           /**< 下转,p1水平速度,p2垂直速度 */
    LEFT,           /**< 左转,p1水平速度,p2垂直速度 */
    RIGHT,          /**< 右转,p1水平速度,p2垂直速度 */
    UP_LEFT,      	/**< 左上,p1水平速度,p2垂直速度 */
    UP_RIGHT,    	/**< 右上,p1水平速度,p2垂直速度 */
    DOWN_LEFT,      /**< 左下,p1水平速度,p2垂直速度 */
    DOWN_RIGHT,     /**< 右下,p1水平速度,p2垂直速度 */

    //预置位操作
    SET_PRESET,     /**< 设置预置点,p1预置点的序号(1-255) */
    GOTO_PRESET,    /**< 转到预置点,p1预置点的序号  */

    //花样扫描
    START_CRUISE,   /**< 开始花样扫描,p1花样扫描的序号(1-4) */
    STOP_CRUISE,    /**< 停止花样扫描,p1花样扫描的序号 */
    RUN_CRUISE,     /**< 运行花样扫描,p1花样扫描的序号 */

    //自动水平运行
    START_AUTO_PAN, /**< 开始自动水平运行,p1自动水平运行的序号(1-4) */
    STOP_AUTO_PAN,  /**< 停止自动水平运行,p1自动水平运行的序号 */
    RUN_AUTO_PAN,   /**< 运行自动水平运行,p1自动水平运行的序号 */

    AUTO_SCAN,      /**< 自动扫描 */
    FLIP,           /**< 翻转 */
    STOP,           /**< 停止 */
    ENTER_MENU,     /**< 进入菜单 */        

    //辅助开关/继电器
    AUX_PWRON,      /**< 打开辅助设备开关,p1辅助开关号(1-雨刷,2-灯光,3-加热器) */
    AUX_PWROFF,     /**< 关闭辅助设备开关,p1辅助开关号(1-雨刷,2-灯光,3-加热器) */

	//自动老化模式命令Automatic aging model
	AUTO_AGING_PTZ_STOP,//停止命令，在停止缩放和聚焦时使用
	AUTO_AGING_FOCUS_NEAR,//放大命令
	AUTO_AGING_FOCUS_FAR,//缩小命令
	AUTO_AGING_ZOOM_TELE,//聚焦+ 命令
	AUTO_AGING_ZOOM_WIDE,//聚焦- 命令
	AUTO_AGING_LOCK_FOCAL1,//锁焦1命令
	AUTO_AGING_LOCK_FOCAL2,//锁焦2命令
	AUTO_AGING_MANUAL_CUTTING_COLOR,//手动切彩色模式命令
	AUTO_AGING_MANUAL_CUTTING_BLACK_WHITE,//手动切黑白模式命令
	AUTO_AGING_MANUAL_CUTTING_ICUT,//自动切换ICUT模式命令
	AUTO_AGING_OLD_MODE,//自动老化模式命令
	AUTO_AGING_NORMAL_MODE,//正常模式命令，在停止自动切换模式和自动老化模式时使用
	AUTO_AGING_SET_TIMES,//设置机芯倍数命令
	AUTO_AGING_SET_FOCUS_LEVEL,//设置机芯聚焦等级命令
	AUTO_AGING_RESET,//复位机芯命令
} E_PTZ_COMMAND;


/******************************************************************************
   解码器数据结构定义
*******************************************************************************/

/**
* @struct tagIPC_DEVICEINFO
* @brief 登录后返回的设备信息
* @attention 目前返回的只有lDevTypeNumber
*/
typedef  struct tagIPC_DEVICEINFO
{
	unsigned long  lDevTypeNumber;                 /**设备编号,主类型+次类型;如0x00010002为主类型1+次类型2 */
#if 0
	unsigned char  pszDevSerialNO[SERIALNO_LEN];   /**设备序列号 */	
	unsigned char  pszDevName[MAX_NAME_LEN_32];	   /**设备名称 */	
	unsigned char  pszDevSoftVer[MAX_VERSION_LEN]; /**设备版本号 */
	unsigned char  cAlarmInPortNum;                /**报警输入个数 */
	unsigned char  cAlarmOutPortNum;               /**报警输出个数 */
	unsigned char  cChanNum;                       /**通道个数,模拟的 */
	unsigned char  cIPChanNum;                     /**最大数字通道个数,保留 */
	unsigned char  cZeroChanNum;                   /**零通道编码个数,DVR需要 */
	unsigned char  cDiskNum;				       /**硬盘个数,DVR需要 */
	unsigned char  cAudioChanNum;				   /**语音通道个数,DVR需要 */
	unsigned char  cMainProto;					   /**主码流协议类型 */
	unsigned char  cSubProto;					   /**子码流协议类型 */
	unsigned char  cSupport;					   /**能力,位与结果为0表示不支持,1表示支持*/
									               /**cSupport & 0x1,表示是否支持搜索
													  cSupport & 0x2,表示是否支持回放
												      cSupport & 0x4,表示是否支持能力集获取 */
#endif
	unsigned char  cReserve[6];					   /**预留 */
}S_IPC_DEVICEINFO, *pS_IPC_DEVICEINFO;

/**
* @enum tagCamType
* @brief 前端设备(camera)类型
* @attention 0表示停止播放
*/
typedef enum tagCamType
{
	CAM_STOP = 0,      /**停止播放 */
	CAM_SERIAL_M,      /**M系列 */
	CAM_SERIAL_N,      /**N系列 */
	CAM_SERIAL_K,      /**K系列 */
	CAM_SERIAL_G,      /**G系列 */
	CAM_SERIAL_T,      /**T系列 */
	CAM_SERIAL_END     /*结束标记（无效） */
}E_CAM_TYPE;

/**
* @enum tagStreamType
* @brief 前端设备(camera)码流类型
* @attention 无
*/
typedef enum tagStreamType
{
	ENCODE_MPEG4_MAJOR = 1,   /**mpeg4主码流 */
	ENCODE_MPEG4_MINOR,       /**mpeg4副码流 */
	ENCODE_MOTION_JPEG,       /**MJPEG */		   
	ENCODE_H264_MAJOR,        /**h.264主码流 */	 
	ENCODE_H264_MINOR,        /**h.264副码流 */		   
	ENCODE_HI3510_H264_MAJOR ,/**Hi3510_h.264主码流 */ 
	ENCODE_HI3510_H264_MINOR, /**Hi3510_h.264副码流 */    
	ENCODE_END                /**结束标记 */  
}E_STREAM_TYPE;	

/**
* @enum tagPictureNumType
* @brief 画面数
* @attention 目前只支持4画面,以后可以扩充
*/
typedef enum tagPictureNumType
{
	PICTURE_NUM_ONE = 1,   /**1画面 */
	PICTURE_NUM_FORE = 4,  /**4画面 */
	PICTURE_NUM_NINE = 9,  /**9画面 */
	PICTURE_NUM_SIXTEEN = 16,/**16画面*/
	PICTURE_NUM_END        /**结束,扩展在此前添加 */
}E_PICNUM_TYPE;

/**
* @struct tagVIDEO_SHIFT_INFO
* @brief 视频切换信息
* @attention 无
*/
typedef  struct tagVIDEO_SHIFT_INFO
{
	E_CAM_TYPE     eDevType;			/**前端设备类型号,为0是表示停止解码 */
	char		   pszURL[MAX_URL_LEN];	/**视频源地址
										 IPC://<IP address>/Port/Channel/Codec/UserName/PassWord/
										 采用默认用户名密码时可以不填UserName和PassWord.
										 Port:采用TCP协议,90端口.
										 Channel:通道编号:以0为计数基点,取非负数.
										 Codec: 如上的E_STREAM_TYPE. 
										 例：IPC://192.168.1.100/90/0/1 */
	unsigned char  cMonitorID;		    /**显示器编号 */
	unsigned char  cWindowID;		    /**窗口编号 */
	unsigned short sExtLength;			/**扩展位 */
}S_VIDEO_SHIFT_INFO, *pS_VIDEO_SHIFT_INFO;

/**
* @struct tagPICTURE_SHIFT_INFO
* @brief 画面切换信息
* @attention 无
*/
typedef  struct tagPICTURE_SHIFT_INFO
{
	unsigned char cShiftDir;          /**切换方向,默认0正常切换,其他暂不支持 */         
	unsigned char cMonitorID;	      /**显示器编号 */
	unsigned char cPicNum;			  /**画面数量,目前支持1画面和4画面之间的切换 */
	unsigned char cFirstPic;		  /**首窗口显示画面编号,可指定对第几个画面进行单屏显示 */
}S_PICTURE_SHIFT_INFO, *pS_PICTURE_SHIFT_INFO;

/**
* @struct tagNET_INFO
* @brief 网络参数信息
* @attention 无
*/
typedef  struct tagNET_INFO
{
	unsigned char pszIPAddress[4];	/**IP地址 */		
	unsigned char pszNetMask[4];	/**子网掩码 */	
	unsigned char pszNetGate[4];	/**网关 */	
	unsigned char pszDNS[4];		/**DNS服务器 */		
	unsigned char cAutoGet;		    /**自动获取 */    
	unsigned char pszExtLength[3];	/**扩展位 */	
}S_NET_INFO, *pS_NET_INFO;

/**
* @struct tagDEV_PARAM_ALL
* @brief 设备参数信息
* @attention 无
*/
typedef  struct tagDEV_PARAM_ALL
{
	unsigned char          cNetNum;       /**psNetInfo结构体个数,固定为1 */
	unsigned char          cMonitorNum;   /**psPictureInfo结构体个数 */
	unsigned char          cVideoNum;	  /**psVideoInfo结构体个数 */
	unsigned char          cFill;		  /**填充字节 */
	S_NET_INFO             psNetInfo[1];  /**网络信息结构体 */
	S_PICTURE_SHIFT_INFO   *psPictureInfo;/**画面切换信息 */
	S_VIDEO_SHIFT_INFO     *psVideoInfo;  /**视频切换信息 */
	unsigned char          cPictureNum;   /**可支持的画面切换种类 */
	unsigned char          cPictureValue[31];/**可支持的画面切换个数 */
}S_DEV_PARAM_ALL, *pS_DEV_PARAM_ALL;

/**
* @enum tagGetParamCmd
* @brief 获取设备参数操作类型
* @attention 目前只支持解码器
*/
typedef enum tagGetParamCmd
{
	/***********解码器部分********/
	PARAM_GET_DECODER_V2524All = 0,      /**解码器V2524所有参数 */
	/***********结束**************/

	PARAM_GET_END 
}E_GETCMD_TYPE;

/**
* @enum tagSetParamCmd
* @brief 设置设备参数操作类型
* @attention 目前只支持解码器
*/
typedef enum tagSetParamCmd
{
	/*************解码器部分************/
	PARAM_SET_DECODER_VIDEOSHIFT = 0,      /**解码器视频切换 */
	PARAM_SET_DECODER_PICTURESHIFT,        /**画面切换 */
	PARAM_SET_DECODER_NETWORKSET,          /**网络设置 */
	PARAM_SET_DECODER_SETOPTION,           /**解码器启动选项设置 */
	/*************结束*****************/
	
	PARAM_SET_END 
}E_SETCMD_TYPE;

//停车场车位车牌识别
/**
* @struct tagIceDevInfo
* @brief 车位智能识别设备信息
* @attention 无
*/
typedef struct tagIceDevInfo
{   
	char sDeviceIP[128];      /**< 车位智能识别设备的IP地址 */
	unsigned short wLinkPort; /**< 车位智能识别设备的通讯端口 */
}S_ICEDEV_INFO;

/**
* @struct tagIpcIce_ParkingPlaceState
* @brief 当前车位状态
* @attention 无
*/
typedef struct tagIpcIce_ParkingPlaceState{
	int state;//0时不合法，1为当前车位上的车牌号，2时当前车位是空，
	char placeno[8];//车位编号
	char plate[16];//state1时有效
	int plate_color;//车牌颜色
	int plate_type;//车牌类型
	char reserved[64];
}S_IpcIce_ParkingPlaceState;

/**
* @struct tagIpcIce_Recognition_Result
* @brief 车位智能算法识别结果
* @attention 无
*/
typedef struct tagIpcIce_Recognition_Result{
	int changed;//代表当前状态有无变化，有变化1，无变化0，60秒未收到设备发来的包则说明设备断线
	int place_number;//车位数量，不能超过MAX_PARKING_PLACE_NUM
	int jpeg_length;//车牌照片长度
	S_IpcIce_ParkingPlaceState PlateResult[MAX_PARKING_PLACE_NUM];
}S_IpcIce_Recognition_Result;


//停车场卡口车牌识别
/**
* @struct tagIpcVLPR_Recognition_Result
* @brief 车牌智能算法识别结果
* @attention 无
*/
typedef struct tagHankIce_VPLR_Result{
	int alarm_type;				//代表当前报警类型VLPR_ALARM_T
	int alarm_ip;				//代表设备IP地址
	int cur_time;				//当前时间(从1970-1-1至今过去的秒数)
	int jpeg_length;			//图片长度,若为0则无图片
	int jpeg_width;				//图片分辨率的宽度
	int jpeg_height;			//图片分辨率的高度
	int has_plate;				//有无车牌,若为0则其后成员无效
	char plate_number[16];		//车牌号
	int plate_color;			//车牌颜色,ICE_PLATECOLOR_E
	int plate_top;				//车牌矩形上边缘坐标,0~100
	int plate_bottom;			//车牌矩形下边缘坐标,0~100
	int plate_left;				//车牌矩形左边缘坐标,0~100
	int plate_right;			//车牌矩形右边缘坐标,0~100
	int past_result_fromTFcard;	//标示当前结果是否是过去的TF卡中保存的结果
	char reserved[60];
}HankIce_VPLR_Result;

//3D指令
typedef struct tag3D_TMP_INFO
{
	long midx;////坐标中心的x值。
	long midy;//坐标中心的y值。
	char actionType;//1:不放大;2:放大4倍;3:放大;4:缩小
}Tmp_3D_Info;


/**
* @struct tagHeartbeatInfo
* @brief 心跳信息
* @attention
*/
typedef struct tagHeartbeatInfo
{
	char	cLive;			/**< 是否有心跳，0-有，1-无 */
	char	cReserved[19];	/**< 预留 */
}S_HEARTBEAT_INFO;


/**
* @struct tagLanSearchInfo
* @brief 局域网设备搜索反馈信息
* @attention 无
*/
typedef struct tagLanSearchInfo
{
	int nDevType;//设备类型 若该值为DEVICE_TYPE_IPC则为网络摄像机，若该值为DEVICE_TYPE_NVR则为网络硬盘录像机

	unsigned char ucSoftWareVersion[4];//设备的软件版本

	unsigned char ucDeviceIP[4];//设备IP地址

	unsigned char ucSubnetIP[4];//设备子网地址

	unsigned char ucGateway[4];//设备网关

	unsigned char ucDevMac[6];//设备MAC地址

	int nHttpPort;//HTTP端口号

	int nVideoPort;//视频端口号

	int nRtspPort;//RTSP端口号

	unsigned char ucReserved; // 保留字节，未使用

}S_LANSEARCH_INFO;


/**
* @enum tagSerialReqType
* @brief 透明通道命令类型
* @attention 无
*/
typedef enum tagSerialReqType
{
	SERIAL_SWITCH_TYPE = 0,	//0 透明通道开关切换
	SERIAL_CONNECT_TYPE,	//1 设置透明通道连接方式
	SERIAL_SET_TYPE,		//2 设置透明通道参数
	SERIAL_SEND_TYPE		//3 透明通道发送数据
}E_REQ_SERIAL_TYPE;

/******************************************************************************
SDKNET初始化接口
*******************************************************************************/
/**
* 初始化SDK，调用其他SDK函数的前提
* @return 返回如下结果：
* - 成功：true
* - 失败：false
* - 获取错误码调用IPCNET_GetLastError
* @note 无
*/
IPCSDK_API bool STDCALL IPCNET_Init();

/**
* 接收网络连接异常信息的回调函数
* @param [IN] lLoginID    登陆的ID，IPCNET_Login的返回值 
* @param [IN] lRealHandle 当前实时数据获取的句柄
* @param [IN] eNetMsgType 网络连接异常信息的类型
* @param [IN] pUserData   用户自定义的数据
* @return 无
* @note 无
*/
typedef void (CALLBACK *CBNetException)(long                 lLoginID,
                                        long                 lRealHandle, 
                                        E_NET_EXCEPTION_TYPE eNetMsgType,                                       
                                        void                 *pUserData);
/**
* 设置接收网络连接异常信息的回调函数
* @param [IN] fNetExceptionMsg 接收异常信息的回调函数，为NULL表示不接收异常信息
* @param [IN] pUserData        用户自定义的数据，回调函数原值返回
* @return 返回如下结果：
* - 成功：true
* - 失败：false
* - 获取错误码调用IPCNET_GetLastError
* @note 无
*/
IPCSDK_API bool STDCALL IPCNET_SetNetExceptionCallBack(CBNetException fNetExceptionMsg,
                                                       void           *pUserData = NULL);
/**
* 释放SDK资源，在结束之前最后调用
* @return 返回如下结果：
* - 成功：true
* - 失败：false
* - 获取错误码调用IPCNET_GetLastError
* @note 无
*/
IPCSDK_API bool STDCALL IPCNET_Cleanup();
/******************************************************************************
SDKNET获取错误码接口
*******************************************************************************/
/**
* 获取错误码
* @return 返回值为错误码
* @note 无
*/
IPCSDK_API long STDCALL IPCNET_GetLastError();

/******************************************************************************
普通摄像机用户登陆接口
*******************************************************************************/
/**
* 用户登陆
* @param [IN]   sDevIP    设备IP地址
* @param [IN]   nDevPort  设备端口号
* @param [IN]   sUserName 登录的用户名，最大长度为32字节
* @param [IN]   sPassword 用户密码，最大长度为32字节
* @param [IN]   bIsValidation 是否需要验证用户名和密码，默认不验证
* @return 返回如下结果：
* - 失败：-1
* - 其他值：表示返回的用户ID值。该用户ID具有唯一性，后续对设备的操作都需要通过此ID实现
* - 获取错误码调用IPCNET_GetLastError
* @note 无
*/
IPCSDK_API long STDCALL IPCNET_Login(const char         *sDevIP,
                                     const unsigned int nDevPort,
                                     const char         *sUserName,
                                     const char         *sPassword, 
									 bool				bIsValidation = false);

/******************************************************************************
解码器用户登陆接口
*******************************************************************************/
/**
* 用户登陆
* @param [IN]   sDevIP    设备IP地址
* @param [IN]   nDevPort  设备端口号
* @param [IN]   sUserName 登录的用户名,最大长度为32字节
* @param [IN]   sPassword 用户密码,最大长度为32字节
* @param [OUT]  psDeviceInfo 用户登录后设备返回的信息
* @return 返回如下结果:
* - 失败:-1
* - 其他值:表示返回的用户ID值.该用户ID具有唯一性,后续对设备的操作都需要通过此ID实现
* - 获取错误码调用IPCNET_GetLastError
* @note 无
*/
IPCSDK_API long STDCALL IPCNET_LoginDec(const char         *sDevIP,
									 const unsigned int nDevPort,
									 const char         *sUserName,
									 const char         *sPassword,
									 pS_IPC_DEVICEINFO psDeviceInfo = NULL);
/******************************************************************************
普通摄像机用户注销接口
*******************************************************************************/
/**
* 用户注销
* @param [IN]   lLoginID 用户ID号,IPCNET_Login的返回值
* @return 返回如下结果：
* - 成功:true
* - 失败:false
* - 获取错误码调用IPCNET_GetLastError
* @note 只用于普通摄像机(不包括解码器,抓拍机),与IPCNET_Login配合使用
*/
IPCSDK_API bool STDCALL IPCNET_Logout(long lLoginID);

/******************************************************************************
解码器用户注销接口
*******************************************************************************/
/**
* 用户注销
* @param [IN]   lLoginID 用户ID号,IPCNET_Login的返回值
* @return 返回如下结果:
* - 成功:true
* - 失败:false
* - 获取错误码调用IPCNET_GetLastError
* @note 只用于解码器,与IPCNET_LoginDec配合使用
*/
IPCSDK_API bool STDCALL IPCNET_LogoutDec(long lLoginID);

/******************************************************************************
SDKNET监听上传报警接口
*******************************************************************************/
/**
* 接收设备主动上传报警回调函数的指针类型
* @param [IN]   pAlarmer    报警源设备的信息
* @param [IN]   pAlarmInfo  报警信息 
* @param [IN]   pUserData   用户自定义的数据
* @return 无
* @note 无
*/
typedef void (CALLBACK *CBAlarmMsg)(S_ALARMER_INFO *pAlarmer,
                                    S_ALARM_INFO   *pAlarmInfo,
                                    void           *pUserData);
/**
* 启动报警监听，接收设备主动上传的报警信息
* @param [IN]   fDevUploadMsg 设备信息上传回调函数，不能为NULL
* @param [IN]   pUserData     用户自定义的数据，回调函数原值返回
* @return 返回如下结果：
* - 成功：true
* - 失败：false
* - 获取错误码调用IPCNET_GetLastError
* @note 无
*/
IPCSDK_API bool STDCALL IPCNET_StartAlarmListen(CBAlarmMsg fDevUploadMsg,
                                                void       *pUserData = NULL);
/**
* 停止报警监听
* @return 返回如下结果：
* - 成功：true
* - 失败：false
* - 获取错误码调用IPCNET_GetLastError
* @note 无
*/
IPCSDK_API bool STDCALL IPCNET_StopAlarmListen();

/**
* 报警输出控制发送接口
* @param [IN] sDevIP  设备的IP地址，如"192.168.112.234"
* @param [IN] nAuxNum 报警输出继电器的序号，从1开始
* @param [IN] bOpen   报警输出继电器开关，true-打开开关，false-关闭开关
* @return 返回如下结果：
* - 成功：true
* - 失败：false
* - 获取错误码调用IPCNET_GetLastError
* @note 该接口常用于报警联动，当用户需要触发设备的输出继电器作出响应时，可以使用该接口
*/
IPCSDK_API bool STDCALL IPCNET_AlarmOutputControl(const char   *sDevIP, 
                                                  unsigned int nAuxNum, 
                                                  bool         bOpen);

/******************************************************************************
SDKNET监听智能车位识别信息接口
*******************************************************************************/
/**
* 接收设备主动上传智能车位识别回调函数的指针类型
* @param [IN]   pIceDevInfo    智能车位识别设备的信息
* @param [IN]   pIceRecInfo  智能车位识别设备状态信息 
* @param [IN]	byJpegbuf	 图片缓冲
* @param [IN]	nJpegLenth	 图片大小
* @param [IN]   pUserData   用户自定义的数据
* @return 无
* @note 无
*/
typedef void (CALLBACK *CBIceRecMsg)(S_ICEDEV_INFO *pIceDevInfo, S_IpcIce_Recognition_Result *pIceRecInfo, unsigned char* byJpegbuf, int nJpegLenth, void *pUserData);

/**
* 启动智能车位识别监听，接收设备主动上传的智能车位识别信息
* @param [IN]   fDevIceRecUploadMsg 设备信息上传回调函数，不能为NULL
* @param [IN]   pUserData     用户自定义的数据，回调函数原值返回
* @return 返回如下结果：
* - 成功：true
* - 失败：false
* - 获取错误码调用IPCNET_GetLastError
* @note 无
*/
IPCSDK_API bool STDCALL IPCNET_StartIceRecListen(CBIceRecMsg fDevIceRecUploadMsg,
												void       *pUserData = NULL);

/**
* 停止智能车位识别监听
* @return 返回如下结果：
* - 成功：true
* - 失败：false
* - 获取错误码调用IPCNET_GetLastError
* @note 无
*/
IPCSDK_API bool STDCALL IPCNET_StopIceRecListen();

/**
* 接收设备主动上传智能车牌识别回调函数的指针类型
* @param [IN]   pVLPRDevInfo    智能车牌识别设备的信息
* @param [IN]   pVLPRInfo		智能车牌识别设备状态信息 
* @param [IN]	byJpegbuf	 图片缓冲
* @param [IN]	nJpegLenth	 图片大小
* @param [IN]   pUserData   用户自定义的数据
* @return 无
* @note 无
*/
typedef void (CALLBACK *CBVLPRMsg)(HankIce_VPLR_Result *pVLPRInfo, unsigned char* byJpegbuf, int nJpegLenth, void *pUserData);

/**
* 启动智能车牌识别监听，接收设备主动上传的智能车牌识别信息
* @param [IN]   fDevVLPRUploadMsg 设备信息上传回调函数，不能为NULL
* @param [IN]   pUserData     用户自定义的数据，回调函数原值返回
* @return 返回如下结果：
* - 成功：true
* - 失败：false
* - 获取错误码调用IPCNET_GetLastError
* @note 无
*/
IPCSDK_API bool STDCALL IPCNET_StartVLPRListen(CBVLPRMsg fDevVLPRUploadMsg,	void *pUserData = NULL);

/**
* 停止智能车牌识别监听
* @return 返回如下结果：
* - 成功：true
* - 失败：false
* - 获取错误码调用IPCNET_GetLastError
* @note 无
*/
IPCSDK_API bool STDCALL IPCNET_StopVLPRListen(void);

/******************************************************************************
SDKNET实时流获取接口
*******************************************************************************/
/**
* 实时码流数据回调函数的指针类型
* @param [IN]   lRealHandle 当前的实时数据的句柄
* @param [IN]   eDataType   回调的数据类型
* @param [IN]   pBuffer     存放数据的缓冲区指针
* @param [IN]   lBufSize    存放数据的缓冲区大小
* @param [IN]   pUserData   用户数据，调用IPCNET_StartRealData时用户输入的值
* @return 无
* @note 无
*/
typedef void (CALLBACK *CBRealData)(long           lRealHandle,
                                   E_REALDATA_TYPE eDataType,
                                   unsigned char   *pBuffer,
                                   unsigned long   lBufSize,
                                   void            *pUserData);
/**
* 开始实时数据获取
* @param [IN]   lLoginID      登陆的ID，IPCNET_Login的返回值
* @param [IN]   sRealDataInfo 实时数据流的参数结构体
* @param [IN]   fRealData     码流数据回调函数
* @param [IN]   pUserData     用户自定义的数据，回调函数原值返回
* @return 返回如下结果：
* - 失败：-1
* - 其他值：作为IPCNET_StopRealData等函数的句柄参数
* - 获取错误码调用IPCNET_GetLastError
* @note 无
*/
IPCSDK_API long STDCALL IPCNET_StartRealData(long            lLoginID,
                                             S_REALDATA_INFO *pRealDataInfo,
                                             CBRealData      fRealData,
                                             void            *pUserData = NULL);
/**
* 停止实时数据获取
* @param [IN]   lRealHandle 实时数据的句柄，IPCNET_StartRealData的返回值
* @return 返回如下结果：
* - 成功：true
* - 失败：false
* - 获取错误码调用IPCNET_GetLastError
* @note 无
*/
IPCSDK_API bool STDCALL IPCNET_StopRealData(long lRealHandle);

/******************************************************************************
SDKNET标准数据流获取接口
*******************************************************************************/
/**
* 标准数据的媒体信息，每次回调都会附带此信息。
**/
typedef struct tagAV_INFO
{
	unsigned char  m_AVType;		//音视频类型，1--视频，2--音频
	unsigned char  m_EncoderType;   //编码类型，  1--H264，2--MPEG4，3--G711_U（音频），4--H265
	unsigned char  m_FrameType;     //帧类型，    1--I帧， 2--P帧，		如果是音频帧，则为0
	unsigned char  m_FrameRate;		//帧率，	如果是音频帧，则为0
	unsigned short m_VideoWidth;    //视频宽度，如果是音频帧，则为0
	unsigned short m_VideoHeight;   //视频高度，如果是音频帧，则为0
	unsigned char  m_Reserved[3];	//保留
	unsigned char  m_Channels;		//通道类型，  1--单声道，2--双声道，如果是视频帧，则为0
	unsigned short m_Samples;       //采样率，  如果是视频帧，则为0
	unsigned short m_BitCount;      //采样位数，如果是视频帧，则为0
	unsigned int   m_TimeStamp;     //时间戳
}S_AV_INFO;
/**
* 标准码流数据回调函数的指针类型
* @param [IN]   lRawHandle     当前的原始数据的句柄
* @param [IN]   pAVInfo		   数据所对应的媒体信息，可针对此信息对音视频做不同处理
* @param [IN]   pRawBuffer     存放数据的缓冲区指针
* @param [IN]   lRawBufSize    存放数据的缓冲区大小
* @param [IN]   pUserData      用户数据，调用IPCNET_StartRawData时用户输入的值
* @return 无
* @note 
*/
typedef void (CALLBACK *CBRawData)(long            lRawHandle,
								   S_AV_INFO       *pAVInfo,
								   unsigned char   *pRawBuffer,
								   unsigned long   lRawBufSize,
								   void            *pUserData);
/**
* 开始获取标准数据
* @param [IN]   lLoginID      登陆的ID，IPCNET_Login的返回值
* @param [IN]   sRawDataInfo  实时数据流的参数结构体
* @param [IN]   fRawData      标准码流数据回调函数
* @param [IN]   pUserData     用户自定义的数据，回调函数原值返回
* @return 返回如下结果：
* - 失败：-1
* - 其他值：作为IPCNET_StopRawData等函数的句柄参数
* - 获取错误码调用IPCNET_GetLastError
* @note 与实时流获取是相互独立的，即可在不开启实时预览功能时直接获取标准数据
*/
IPCSDK_API long STDCALL IPCNET_StartRawData(long            lLoginID,
											S_REALDATA_INFO *pRawDataInfo,
											CBRawData       fRawData,
											void            *pUserData = NULL);
/**
* 停止获取标准数据
* @param [IN]   lRawHandle    IPCNET_StartRawData的返回值
* @return 返回如下结果：
* - 成功：true
* - 失败：false
* - 获取错误码调用IPCNET_GetLastError
* @note 无
*/
IPCSDK_API bool STDCALL IPCNET_StopRawData(long lRawHandle);

/******************************************************************************
SDKNET语音对讲接口
*******************************************************************************/

#define		AUDIO_ENCODE_G711_U					0x01
#define		AUDIO_ENCODE_G711_A					0x02
#define		AUDIO_ENCODE_ADPCM_A				0x03
#define		AUDIO_ENCODE_G726					0x04
#define		AUDIO_ENCODE_G711_A_HI				0x05	//HI H264
#define		AUDIO_ENCODE_G711_U_HI				0x06	//HI H264
#define		AUDIO_ENCODE_G726_HI				0x07	//HI H264
#define		AUDIO_ENCODE_PCM					0x08

/******************************************************************************
SDKNET云台控制接口
*******************************************************************************/
/**
* 云台控制接口，不用启动预览时也可以使用
* @param [IN]   lLoginID    登陆的ID，IPCNET_Login的返回值
* @param [IN]   nChannel    设备通道号， 从0开始
* @param [IN]   ePTZCommand 云台控制命令
* @param [IN]   iParam1     参数1，具体内容跟控制命令有关，详见E_PTZ_COMMAND
* @param [IN]   iParam2     参数2，同上
* @param [IN]   bStop       是否停止，对云台八方向操作及镜头操作命令有效，进行其他操作时，本参数应填充false
* @return 返回如下结果：
* - 成功：true
* - 失败：false
* - 获取错误码调用IPCNET_GetLastError
* @note 当iParam1表示速度时，范围是1~8
*/
IPCSDK_API bool STDCALL IPCNET_PTZControl(long          lLoginID,
                                          unsigned int  nChannel,
                                          E_PTZ_COMMAND ePTZCommand,
                                          int           iParam1 = 6,
                                          int           iParam2 = 6,
                                          bool          bStop = false);

/**
* PTZ区域选择放大接口
* @param [IN] lLoginID   登陆的ID，IPCNET_Login的返回值
* @param [IN] nChannel   设备通道号，从0开始
* @param [IN] rcSelWnd   选择要放大的客户区域坐标
* @param [IN] rcVideoWnd 视频显示框的客户区域坐标
* @return 返回如下结果：
* - 成功：true
* - 失败：false
* - 获取错误码调用IPCNET_GetLastError
*/
IPCSDK_API bool STDCALL IPCNET_PTZSelZoomIn(long        lLoginID,
                                           unsigned int nChannel,
                                           RECT         &rcSelWnd, 
                                           RECT         &rcVideoWnd,
                                           Tmp_3D_Info &tmp3DInfo);
/**
* PTZ矢量控制接口
* @param [IN] lLoginID   登陆的ID，IPCNET_Login的返回值
* @param [IN] nChannel   设备通道号，从0开始
* @param [IN] ptStart    矢量控制方向起始坐标
* @param [IN] ptEnd      矢量控制方向末尾坐标
* @param [IN] rcVideoWnd 视频显示框的客户区域坐标
* @return 返回如下结果：
* - 成功：true
* - 失败：false
* - 获取错误码调用IPCNET_GetLastError
* @note 要停止矢量控制，将ptStart和ptEnd坐标都设置为0。
*/
IPCSDK_API bool STDCALL IPCNET_PTZVectorControl(long         lLoginID,
                                                unsigned int nChannel,
                                                POINT        &ptStart,
                                                POINT        &ptEnd,
                                                RECT         &rcVideoWnd);


/**
* 获取设备参数
* @param [IN]   lLoginID         用户ID号,IPCDEC_Logon的返回值
* @param [IN]   iCommand	     命令号
* @param [IN]   iChannel         通道,无效为-1
* @param [IN]   pDataBuf	     数据     
* @param [IN]   iDataLen         数据长度（最大）
* @param [OUT]  iReturnedLen     数据实际长度
* @return 返回如下结果:
* - 成功:true
* - 失败:false
* - 获取错误码调用IPCNET_GetLastError
* @note 目前只支持解码器
*/
IPCSDK_API BOOL STDCALL IPCNET_GetDeviceConfig(long lLoginID, 
											   E_GETCMD_TYPE eCommand, 
											   int iChannel, 
											   void* pDataBuf, 
											   int iDataLen, 
											   int* iReturnedLen); 

/**
* 设置设备参数
* @param [IN]   lLoginID         用户ID号,IPCDEC_Logon的返回值
* @param [IN]   iCommand	     命令号
* @param [IN]   iChannel         通道,无效为-1
* @param [IN]   pDataBuf	     数据   
* @param [IN]   iDataLen         数据长度
* @return 返回如下结果:
* - 成功:true
* - 失败:false
* - 获取错误码调用IPCNET_GetLastError
* @note 目前只支持解码器
*/
IPCSDK_API BOOL STDCALL IPCNET_SetDeviceConfig(long lLoginID, 
											   E_SETCMD_TYPE eCommand, 
											   int iChannel, 
											   void* pDataBuf, 
											   int iDataLen); 

/******************************************************************************
SDKNET设备心跳接口
*******************************************************************************/
/**
* 心跳信息回调函数的指针类型
* @param [IN]   lHeartHandle		当前的心跳数据的句柄
* @param [IN]   S_HEARTBEAT_INFO	心跳信息结构体指针
* @param [IN]   pUserData			用户数据，调用IPCNET_StartHeartbeat时用户输入的值
* @return 无
* @note 功能未实现
*/
typedef void (CALLBACK *CBHeartbeat)(long				lHeartHandle,
									 S_HEARTBEAT_INFO	*pHeartbeat,
									  void*				pUserData );

/**
* 局域网设备搜索
* @param [IN]   psLanSearchInfo 存储搜索结果的tagLanSearchInfo结构体数组指针
* @param [IN]   nArrayLen psLanSearchInfo数组的大小
* @param [IN]   nWaitTimeMs 搜索等待时间,以毫秒为单位。
* @return 返回如下结果：
* - 成功：true
* - 失败：false
* - 获取错误码调用IPCNET_GetLastError
* @note   无
*/
IPCSDK_API bool STDCALL IPCNET_Lan_Search(struct tagLanSearchInfo *psLanSearchInfo, int nArrayLen, int nWaitTimeMs);


/**
* 用于获取透明通道的返回数据
* @param [OUT]	result		透明通道的返回结果
* @param [OUT]	pdata		指向串口返回数据的指针
* @param [OUT]	ndatalen	返回数据的长度
* @param [OUT]	pUserData	用户自定义的数据，回调函数原值返回
*/
typedef void (CALLBACK *CBTransparantSerial)(int result, unsigned char *pdata, int ndatalen, void *pUserData);

/**
* 开启透明通道控制
* @param [IN] lLoginID  			登陆的ID，IPCNET_Login的返回值
* @param [IN] nChannel				通道号，默认为1
* @param [IN] fTransparantSerial	透明通道数据回调函数
*/
IPCSDK_API bool STDCALL IPCNET_OpenTransparantSerialControl(long lLoginID,
															int nChannel, 
															CBTransparantSerial fTransparantSerial, 
															void *pUserData);

/**
* 发送透明通道控制命令
* @param [IN] lLoginID  		登陆的ID，IPCNET_Login的返回值
* @param [IN] eSerialReqType	透明通道控制命令
* @param [IN] iParam1 			具体内容跟控制命令有关，详见/Demo/TransparantSerialDemo目录下的参考
* @param [IN] iParam2 			同上
* @param [IN] iParam3 			同上
* @param [IN] iParam4 			同上
* @param [IN] data				通过串口发送的数据
* @param [IN] dataLen 			发送数据的长度
*/
IPCSDK_API bool STDCALL IPCNET_SendTransparantSerialControl(long lLoginID,
															E_REQ_SERIAL_TYPE eSerialReqType,
															int iParam1,
															int iParam2,
															int iParam3,
															int iParam4,
															unsigned char *pdata,
															int ndatalen);

/**
* 关闭透明通道控制
* @param [IN] lLoginID  		 登陆的ID，IPCNET_Login的返回值
*/
IPCSDK_API bool STDCALL IPCNET_CloseTransparantSerialControl(long lLoginID);

/**
* 服务器推送至客户端经过处理后的有效数据回调函数的指针类型
* @param [IN]   lPlayHandle		对应的句柄
* @param [IN]   bIceAlaSta		报警状态开启或关闭
* @param [IN]   pDataBuf		存放数据的缓冲区指针
* @param [IN]   lDataLength		存放数据的缓冲区大小
* @param [IN]   pUserData		用户数据，调用IPCNET_StartServerPush时用户输入的值
* @return long  目前返回-1为异常情况，非负数为正常
* @note   无
*/
typedef long (CALLBACK *CBIceAlarmPushData)(long lPlayHandle,
											bool				bIceAlaSta, 
											unsigned char*		pDataBuf,
											unsigned long		lDataLength,
											void*				pUserData );

typedef enum {
	ICE_TYPE_DTCA,//智能分析
	ICE_TYPE_HCNT,//人数统计
	ICE_TYPE_NONE
}EM_ICE_REQUEST;

/**
* 开始推送
* @param [IN] nIceType		报警类型 EM_ICE_REQUEST
* @param [IN] fCBSpushData	有效数据回调函数
* @param [IN] pUserData		用户数据
* @return 返回如下结果：
* - 失败：-1
* - 其他值：作为IPCNET_StopIceAlarmPush的句柄参数
* @note   无
*/
IPCSDK_API long STDCALL	IPCNET_StartIceAlarmPush(long lLoginID, EM_ICE_REQUEST emIceType, CBIceAlarmPushData fCBIceAlarmPushData, void* pUserData);

/**
* 停止推送
* @param [IN]	lLoginID   登陆的ID，INFNET_Login的返回值
* @param [IN]   lHandle Ice Alarm Push的句柄，IPCNET_StartIceAlarmPush的返回值
* @return 返回如下结果：
* - 成功：true
* - 失败：false
* @note   无
*/
IPCSDK_API bool STDCALL IPCNET_StopIceAlarmPush(long lHandle);

/************************************************************************/
/* TF卡录像回放流获取                                                   */
/************************************************************************/
/**
* TF卡录像流数据回调函数的指针类型(私有格式的数据)
* @param [IN]   lPlaybackHandle 当前的TF卡录像数据的句柄，IPCNET_StartPlaybackData的返回值
* @param [IN]   pPlaybackBuffer     存放数据的缓冲区指针
* @param [IN]   lPlaybackBufSize    存放数据的缓冲区大小
* @param [IN]   pUserData   用户数据，调用IPCNET_StartPlaybackData时用户输入的值
* @return 无
* @note 无
*/
typedef void (CALLBACK *CBPlaybackData)(long lPlaybackHandle, unsigned char *pPlaybackBuffer, unsigned long lPlaybackBufSize, void *pUserData);

/**
* TF卡录像流数据回调函数的指针类型(H264格式的裸数据帧)
* @param [IN]   lPlaybackRawHandle 当前的TF卡录像数据的句柄，IPCNET_StartPlaybackRawData的返回值
* @param [IN]   pPlaybackRawBuffer     存放数据的缓冲区指针
* @param [IN]   lPlaybackRawBufSize    存放数据的缓冲区大小
* @param [IN]   pUserData   用户数据，调用IPCNET_StartPlaybackRawData时用户输入的值
* @return 无
* @note 无
*/
typedef void (CALLBACK *CBPlaybackRawData)(long lPlaybackRawHandle, unsigned char *pPlaybackRawBuffer, unsigned long lPlaybackRawBufSize, void *pUserData);

/************************************************************************/
/* SD卡录像搜索                                                         */
/************************************************************************/
//录像搜索参数结构体
typedef struct{
	unsigned int m_nStartUTC;//搜索起始时间，UTC时间
	unsigned int m_nEndUTC;//搜索结束时间，UTC时间
	int m_nWaitTime;//搜索等待时间，为0的话默认为3000，单位ms。
	int m_nHttpPort;//Http时间，为0 的话默认为80。
	unsigned char uRet[16];//预留
}NET_FILECOND, *LPNET_FILECOND;

//录像搜索返回结果结构体
typedef struct{
	unsigned char m_ucSessionName[64];//文件名，作为播放接口或者下载接口的参数用。
	int m_nType;//录像文件类型：0x01：IO报警，0x02：移动侦测，0x04：手动录像，0x08：网络丢失
	int m_nStartTime;//录像文件起始时间，UTC时间
	int m_nEndTime;//录像文件结束时间，UTC时间
	unsigned char uRet[16];
}NET_FINDDATA, *LPNET_FINDDATA;

/**
* 根据时间查找设备TF卡录像文件。
* @param [IN]   lLoginID   登陆的ID，IPCNET_Login的返回值
* @param [IN]   pFindCond  欲查找的文件信息结构
* @return 返回如下结果：
* - 失败：-1
* - 其他值：作为IPCNET_FindNextFile、IPCNET_FindClose等函数的参数。
* @note 无
*/
IPCSDK_API long STDCALL IPCNET_FindFile(long lLoginID, LPNET_FILECOND pFindCond);

/**
* 逐个获取查找到的文件信息。
* @param [IN]   lFindHandle   文件查找句柄，IPCNET_FindFile的返回值。
* @param [IN]   lpFindData    保存文件信息的指针。
* @return 返回如下结果：
* - 失败：-1
* - 其他值：表示当前的获取状态等信息。
* @note 无
*/
IPCSDK_API long STDCALL IPCNET_FindNextFile(long lFindHandle, LPNET_FINDDATA lpFindData);

/**
* 关闭文件查找，释放资源。
* @param [IN]   lFindHandle 文件查找句柄，IPCNET_FindFile的返回值。
* @return 返回如下结果：
* - 成功：true
* - 失败：false
* @note 无
*/
IPCSDK_API bool STDCALL IPCNET_FindClose(long lFindHandle);

/************************************************************************/
/* SD卡录像下载                                                         */
/************************************************************************/
/**
* 按文件名下载录像文件。
* @param [IN]   lLoginID   登陆的ID，IPCNET_Login的返回值。
* @param [IN]   sFileName  要下载的录像文件名，录像搜索时，NET_FINDDATA结构体中的m_ucSessionName变量值。。
* @param [IN]   sSavedFileName   下载后保存到PC机的文件路径。
* @param [IN]   nDownloadPort    摄像机上的下载端口，默认为8088。
* @return 返回如下结果：
* - 失败：-1
* - 其他值：作为IPCNET_GetDownloadPos、IPCNET_StopGetFile等函数的参数。
* @note 无
*/
IPCSDK_API long STDCALL IPCNET_GetFileByName(long lLoginID, const char *sFileName, const char *sSavedFileName, int nDownloadPort = 8088);

/**
* 获取当前下载录像文件的进度。
* @param [IN]   lFileHandle   下载句柄，IPCNET_GetFileByName的返回值。
* @return 返回如下结果：
* - 失败：-1
* - 其他值：0～100表示下载的进度；100表示下载结束；正常范围0-100。
* @note 无
*/
IPCSDK_API int STDCALL IPCNET_GetDownloadPos(long lFileHandle);

/**
* 停止下载录像文件。
* @param [IN]   lFileHandle   下载句柄，IPCNET_GetFileByName的返回值。
* @return 返回如下结果：
* - 成功：true
* - 失败：false
* @note 无
*/
IPCSDK_API bool STDCALL IPCNET_StopGetFile(long lFileHandle);

/************************************************************************/
/* 抓图功能                                                             */
/************************************************************************/
/**
* 抓取摄像机图片。
* @param [IN]   lLoginID   登陆的ID，IPCNET_Login的返回值。
* @param [OUT]  sPicBuf    用于接收图片的缓冲区。
* @param [IN]   nPicBufSize图片的缓冲区大小。
* @param [IN]   nHttpPort  HTTP端口(默认80)。
* @param [IN]   iWaitTime  超时时间ms(默认3000ms)。
* @return 返回如下结果：
* - 成功：返回图片大小。
* - 失败：
-1001:打开端口失败
-1002:连接设备失败
-1003:发送请求失败
-1004:发送请求失败
-1005:图片大小异常
-1006:缓冲区太小
-1007:图片接收异常
-1008:设置超时失败
* @note 无
*/
IPCSDK_API long STDCALL IPCNET_CapturePicture(long lLoginID, char *sPicBuf, int nPicBufSize, int iWaitTime = 3000, int nHttpPort = 80);

/**
* 开始mjepg流的播放
* @param [IN]   lLoginID      登陆的ID，IPCNET_Login的返回值
* @param [IN]   nHttpPort     http端口
* @param [IN]   hWnd          窗口句柄
* @return 返回如下结果：
* - 失败：-1
* - 其他值：作为IPCNET_StopJpegData等函数的句柄参数
* @note 无
*/
IPCSDK_API long STDCALL IPCNET_StartJpegData(long lLoginID, int nHttpPort, HWND hWnd);

/**
* 停止mjepg流的播放
* @param [IN]   lJpegHandle 实时数据的句柄，IPCNET_StartJpegData的返回值
* @return 返回如下结果：
* - 成功：true
* - 失败：false
* @note 无
*/
IPCSDK_API bool STDCALL IPCNET_StopJpegData(long lJpegHandle);

#ifdef __cplusplus
}
#endif //#ifdef __cplusplus

#endif //#ifndef _IPC_SDK_NET_JFIOAF419848KL_H_
