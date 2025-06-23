/*******************************************************************************
Copyright (c)  Tech. Co., Ltd. All rights reserved.
--------------------------------------------------------------------------------
Description: 解码库SDK头文件

--------------------------------------------------------------------------------
Modification History
DATE          AUTHOR          DESCRIPTION
2012-09-13                    增加解码回调接口
--------------------------------------------------------------------------------

*******************************************************************************/

#ifndef _HDV_SDK_PLAY_12781258KJFKALJFI_H_
#define _HDV_SDK_PLAY_12781258KJFKALJFI_H_

/******************************************************************************
SDKPLAY编译参数定义
*******************************************************************************/
#ifdef WIN32 //windows平台

#if defined(HDVSDK_PLAY_DLL)
    #define HDVSDK_API  __declspec(dllexport)
#else
    #define HDVSDK_API  __declspec(dllimport)
#endif
#define STDCALL  __stdcall
#define CALLBACK __stdcall

#else //其他平台

#define HDVSDK_API extern "C"
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

#endif

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
SDKPLAY宏定义
*******************************************************************************/

/************************************************************************************
SDKPLAY错误码定义，对应HDVPLAY_GetLastError接口的返回值，PLAY库错误码的范围：500-999
*************************************************************************************/
#define ERR_PLAY_SUCCEED        500  /**< 执行成功 */
#define ERR_PLAY_FAIL           501  /**< 执行失败 */
#define ERR_PLAY_INVALIDPARAM   502  /**< 输入参数非法 */
#define ERR_PLAY_NOMEMORY       503  /**< 系统内存不足 */
#define ERR_PLAY_NOINIT         504  /**< 没有初始化 */
#define ERR_PLAY_OPENFILE       505  /**< 文件打开失败 */
#define ERR_PLAY_OPENSTREAM     506  /**< 流打开失败 */
#define ERR_PLAY_ORDER          507  /**< SDK接口的调用次序错误 */
/******************************************************************************
SDKPLAY数据结构定义
*******************************************************************************/
/**
* @enum tagRecordtype
* @brief 录像的类型
* @attention 无
*/
typedef enum tagRecordtype
{
    RECORD_AVI, /**< 使用AVI录像格式，不提供解码接口 */
    RECORD_IFV, /**< 使用自定义的IFV格式，提供完整解码接口 */
} E_RECORD_TYPE;

/**
* @enum tagPictype
* @brief 截图的图像类型
* @attention 无
*/
typedef enum tagPictype
{
    PIC_JPEG,
    PIC_BMP,
} E_PIC_TYPE;

/**
* @struct tagFrameInfo
* @brief 媒体流信息
* @attention 无
*/
typedef struct tagMediaInfo
{
    unsigned short  wWidth;         /**< 图像宽度，如果媒体流不含有视频，则为0 */
    unsigned short  wHeight;        /**< 图像高度，如果媒体流不含有视频，则为0 */
    unsigned char   byFrameRate;    /**< 图像帧率，如果媒体流不含有视频，则为0 */
    unsigned char   byChannels;     /**< 音频通道，如果媒体流不含有音频，则为0 */
    unsigned short  wSamplesPerSec; /**< 音频采样率，如果媒体流不含有音频，则为0 */
	unsigned char 	cVideoCodec;	/**< 视频流编码类型，0代表H264，1代表H265，-1代表未知编码 */
} S_MEDIAINFO;

/**
* @enum tagFrametype
* @brief 回调解码后的数据帧类型
* @attention
*/
typedef enum tagFrametype
{
    FT_YUV,
} E_FRAME_TYPE;

/**
* @struct tagFrameInfo
* @brief 回调解码后的数据帧信息
* @attention 无
*/
typedef struct tagFrameInfo
{ 
    unsigned long nWidth;     /**< 画面宽，单位像素 */
    unsigned long nHeight;    /**< 画面高，单位像素 */
    unsigned long nStamp;     /**< 时标信息，单位毫秒 */
    E_FRAME_TYPE  eFrameType; /**< 数据类型，详见E_FRAME_TYPE定义说明 */
    unsigned long nFrameRate; /**< 视频帧率 */
} S_FRAMEINFO; 
/******************************************************************************
SDKPLAY初始化接口
*******************************************************************************/
/**
* 初始化解码库SDK，调用其他SDK函数的前提
* @return 返回如下结果：
* - 成功：true
* - 失败：false
* - 获取错误码调用HDVPLAY_GetLastError
* @note 初始化解码库只需调用一次，与HDVPLAY_Cleanup配对
*/
HDVSDK_API bool STDCALL HDVPLAY_Init();
/**
* 释放解码库SDK资源，在结束之前最后调用
* @return 返回如下结果：
* - 成功：true
* - 失败：false
* - 获取错误码调用HDVPLAY_GetLastError
* @note 释放解码库，与HDVPLAY_Init配对
*/
HDVSDK_API bool STDCALL HDVPLAY_Cleanup();

/******************************************************************************
SDKPLAY获取错误码接口
*******************************************************************************/
/**
* 获取错误码
* @return 返回值为错误码
* @note 无
*/
HDVSDK_API long STDCALL HDVPLAY_GetLastError();

/******************************************************************************
SDKPLAY文件解码接口
*******************************************************************************/
/**
* 打开文件
* @param [IN]   sFileName 要解码的文件名
* @return 返回如下结果：
* - 失败：-1
* - 其他值：表示返回的解码句柄值。该解码句柄具有唯一性，后续的操作都需要通过此句柄实现
* - 获取错误码调用HDVPLAY_GetLastError
* @note 无
*/
HDVSDK_API long STDCALL HDVPLAY_OpenFile(const char *sFileName);
/**
* 关闭文件
* @param [IN]   lPlayHandle 解码句柄，HDVPLAY_OpenFile的返回值
* @return 返回如下结果：
* - 成功：true
* - 失败：false
* - 获取错误码调用HDVPLAY_GetLastError
* @note 无
*/
HDVSDK_API bool STDCALL HDVPLAY_CloseFile(long lPlayHandle);

/******************************************************************************
SDKPLAY流解码接口
*******************************************************************************/
/**
* 打开流
* @param [IN]   pStreamHead     媒体流头数据
* @param [IN]   lStreamHeadSize 媒体流头数据的大小，单位为字节
* @return 返回如下结果：
* - 失败：-1
* - 其他值：表示返回的解码句柄值。该解码句柄具有唯一性，后续的操作都需要通过此句柄实现
* - 获取错误码调用HDVPLAY_GetLastError
* @note 无
*/
HDVSDK_API long STDCALL HDVPLAY_OpenStream(const unsigned char *pStreamHead,
                                           unsigned long       lStreamHeadSize);
/**
* 输入媒体流数据，打开流之后才能输入数据
* @param [IN]   lPlayHandle     解码句柄，HDVPLAY_OpenStream的返回值
* @param [IN]   pStreamBuf      媒体流数据
* @param [IN]   lStreamBufSize  媒体流数据的大小，单位为字节
* @return 返回如下结果：
* - 成功：true
* - 失败：false
* - 获取错误码调用HDVPLAY_GetLastError
* @note 无
*/
HDVSDK_API bool STDCALL HDVPLAY_InputData(long                lPlayHandle,
                                          const unsigned char *pStreamBuf,
                                          unsigned long       lStreamBufSize);
/**
* 关闭流
* @param [IN]   lPlayHandle 解码句柄，HDVPLAY_OpenStream的返回值
* @return 返回如下结果：
* - 成功：true
* - 失败：false
* - 获取错误码调用HDVPLAY_GetLastError
* @note 无
*/
HDVSDK_API bool STDCALL HDVPLAY_CloseStream(long lPlayHandle);

/******************************************************************************
SDKPLAY解码控制接口
*******************************************************************************/
/**
* 播放开始
* @param [IN]   lPlayHandle 解码句柄
* @param [IN]   hPlayWnd    播放窗口句柄，为空(NULL)表示只解码不显示
* @param [IN]   bCloseSound 仅实时播放时有效,该参数控制实时播放的同时是否关闭声音，默认是开启声音的
* @return 返回如下结果：
* - 成功：true
* - 失败：false
* - 获取错误码调用HDVPLAY_GetLastError
* @note 播放视频画面大小将根据 hWnd 窗口调整。
* 如果已经播放，只是改变当前播放速度为正常速度
*/
HDVSDK_API bool STDCALL HDVPLAY_Play(long lPlayHandle,
                                     HWND hPlayWnd,
                                     bool bCloseSound = false);
/**
* 播放停止
* @param [IN]   lPlayHandle 解码句柄
* @return 返回如下结果：
* - 成功：true
* - 失败：false
* - 获取错误码调用HDVPLAY_GetLastError
* @note 无
*/
HDVSDK_API bool STDCALL HDVPLAY_Stop(long lPlayHandle);
/**
* 播放暂停
* @param [IN]   lPlayHandle 解码句柄
* @return 返回如下结果：
* - 成功：true
* - 失败：false
* - 获取错误码调用HDVPLAY_GetLastError
* @note 无
*/
HDVSDK_API bool STDCALL HDVPLAY_Pause(long lPlayHandle);
/**
* 播放恢复
* @param [IN]   lPlayHandle 解码句柄
* @return 返回如下结果：
* - 成功：true
* - 失败：false
* - 获取错误码调用HDVPLAY_GetLastError
* @note 无
*/
HDVSDK_API bool STDCALL HDVPLAY_Resume(long lPlayHandle);
/**
* 快放
* @param [IN]   lPlayHandle 解码句柄
* @return 返回如下结果：
* - 成功：true
* - 失败：false
* - 获取错误码调用HDVPLAY_GetLastError
* @note 快速播放，每次调用将使当前播放速度加快一倍，最多调用 4 次；
要恢复正常播放调用HDVPLAY_Play()，从当前位置开始正常播放。
*/
HDVSDK_API bool STDCALL HDVPLAY_Fast(long lPlayHandle);
/**
* 慢放
* @param [IN]   lPlayHandle 解码句柄
* @return 返回如下结果：
* - 成功：true
* - 失败：false
* - 获取错误码调用HDVPLAY_GetLastError
* @note 慢速播放，每次调用将使当前播放速度减慢一倍，最多调用 4 次；
要恢复正常播放调用HDVPLAY_Play()，从当前位置开始正常播放。
*/
HDVSDK_API bool STDCALL HDVPLAY_Slow(long lPlayHandle);
/**
* 单帧前进
* @param [IN]   lPlayHandle 解码句柄
* @return 返回如下结果：
* - 成功：true
* - 失败：false
* - 获取错误码调用HDVPLAY_GetLastError
* @note 无
*/
HDVSDK_API bool STDCALL HDVPLAY_Forward(long lPlayHandle);
/**
* 单帧后退
* @param [IN]   lPlayHandle 解码句柄
* @return 返回如下结果：
* - 成功：true
* - 失败：false
* - 获取错误码调用HDVPLAY_GetLastError
* @note 无
*/
HDVSDK_API bool STDCALL HDVPLAY_Backward(long lPlayHandle);

/******************************************************************************
SDKPLAY解码状态接口
*******************************************************************************/
/**
* 获得媒体流信息
* @param [IN]   lPlayHandle 解码句柄
* @param [IN]   pMediaInfo  媒体流信息，详见S_MEDIAINFO的定义
* @return 返回如下结果：
* - 成功：true
* - 失败：false
* - 获取错误码调用HDVPLAY_GetLastError
* @note 无
*/
HDVSDK_API bool STDCALL HDVPLAY_GetMediaInfo(long        lPlayHandle,
                                             S_MEDIAINFO *pMediaInfo);

/**
* 获取文件的总时间，单位秒
* @param [IN]   lPlayHandle 解码句柄
* @return 返回如下结果：
* - 失败：-1
* - 其他值：表示媒体文件播放的总时间，单位秒。
* - 获取错误码调用HDVPLAY_GetLastError
* @note 无
*/
HDVSDK_API long STDCALL HDVPLAY_GetFileTime(long lPlayHandle);

/**
* 获取播放时间
* @param [IN]   lPlayHandle 解码句柄
* @return 返回如下结果：
* - 失败：-1
* - 其他值：表示当前播放的时间，单位秒。
* - 获取错误码调用HDVPLAY_GetLastError
* @note 无
*/
HDVSDK_API long STDCALL HDVPLAY_GetPlayTime(long lPlayHandle);

/**
* 设置播放时间
* @param [IN]   lPlayHandle 解码句柄
* @param [IN]   lSecond     播放时间，单位秒
* @return 返回如下结果：
* - 成功：true
* - 失败：false
* - 获取错误码调用HDVPLAY_GetLastError
* @note 无
*/
HDVSDK_API bool STDCALL HDVPLAY_SetPlayTime(long lPlayHandle,
                                              long lSecond);

/******************************************************************************
SDKPLAY声音接口
*******************************************************************************/
/**
* 获得当前的音量值
* @param [IN]   lPlayHandle 解码句柄
* @return 返回当前设置的音量值，范围 0-0xFFFF
* - 获取错误码调用HDVPLAY_GetLastError
* @note 无
*/
HDVSDK_API unsigned short STDCALL HDVPLAY_GetVolume(long lPlayHandle);
/**
* 设置音量大小
* @param [IN]   lPlayHandle 解码句柄
* @param [IN]   nVolume     音量的值，范围 0-0xFFFF
* @return 返回如下结果：
* - 成功：true
* - 失败：false
* - 获取错误码调用HDVPLAY_GetLastError
* @note 可以在播放之前设置，返回值是false，但设置的值被保存，
并作为启动声音时的初始音量
*/
HDVSDK_API bool STDCALL HDVPLAY_SetVolume(long           lPlayHandle,
                                          unsigned short nVolume);

/**
* 播放声音，在独占模式下播放
* @param [IN]   lPlayHandle 解码句柄
* @return 返回如下结果：
* - 成功：true
* - 失败：false
* - 获取错误码调用HDVPLAY_GetLastError
* @note 以独占模式播放声音，同一时刻只能打开一路通道播放
*/
HDVSDK_API bool STDCALL HDVPLAY_PlaySound(long lPlayHandle);
/**
* 关闭声音，在独占模式下关闭
* @param 无
* @return 返回如下结果：
* - 成功：true
* - 失败：false
* - 获取错误码调用HDVPLAY_GetLastError
* @note 以独占模式关闭声音，会使所有通道的声音都关闭
*/
HDVSDK_API bool STDCALL HDVPLAY_StopSound();

/**
* 播放声音，在共享模式下播放
* @param [IN]   lPlayHandle 解码句柄
* @return 返回如下结果：
* - 成功：true
* - 失败：false
* - 获取错误码调用HDVPLAY_GetLastError
* @note 以共享模式播放声音，只管播放本路声音而不去关闭其他路的声音
*/
HDVSDK_API bool STDCALL HDVPLAY_PlaySoundShare(long lPlayHandle);
/**
* 关闭声音，在共享模式下关闭
* @param [IN]   lPlayHandle 解码句柄
* @return 返回如下结果：
* - 成功：true
* - 失败：false
* - 获取错误码调用HDVPLAY_GetLastError
* @note 以共享模式关闭声音，只关闭本路声音而不去关闭其他路的声音
*/
HDVSDK_API bool STDCALL HDVPLAY_StopSoundShare(long lPlayHandle);

/******************************************************************************
SDKPLAY录像接口
*******************************************************************************/
/**
* 录像开始
* @param [IN]   lPlayHandle 解码句柄
* @param [IN]   sFileName   录像的文件名
* @param [IN]   eRecordType 保存的录像格式
* @return 返回如下结果：
* - 成功：true
* - 失败：false
* - 获取错误码调用HDVPLAY_GetLastError
* @note 无
*/
HDVSDK_API bool STDCALL HDVPLAY_StartRecord(long          lPlayHandle,
                                            const char    *sFileName,
                                            E_RECORD_TYPE eRecordType);
/**
* 录像停止
* @param [IN]   lPlayHandle 解码句柄
* @return 返回如下结果：
* - 成功：true
* - 失败：false
* - 获取错误码调用HDVPLAY_GetLastError
* @note 无
*/
HDVSDK_API bool STDCALL HDVPLAY_StopRecord(long lPlayHandle);

/******************************************************************************
SDKPLAY回调解码后的数据
*******************************************************************************/
/**
* 解码回调函数指针类型
* @param [IN] lPlayHandle 当前的解码句柄
* @param [IN] pBuf        解码后的媒体数据
* @param [IN] nBufSize    解码后的媒体数据pBuf的长度
* @param [IN] pFrameInfo  解码后的媒体信息，详见S_FRAMEINFO定义
* @param [IN] pUserData   用户数据，调用HDVPLAY_SetDecodeCallBack时用户输入的值
* @return 无
* @note 无
*/
typedef void (CALLBACK *CBDecodeFun)(long               lPlayHandle,
	const unsigned char *pBuf,
	unsigned long       nBufSize,
	S_FRAMEINFO         *pFrameInfo,
	void                *pUserData);
/**
* 设置解码回调函数
* @param [IN] lPlayHandle 当前的解码句柄
* @param [IN] fDecodeFun  解码回调函数，可以为空(NULL)，NULL表示不再解码回调
* @param [IN] pUserData   用户自定义的数据，回调函数原值返回
* @return 返回如下结果：
* - 成功：true
* - 失败：false
* - 获取错误码调用HDVPLAY_GetLastError
* @note 该接口设置解码回调函数，用户可以自己处理解码后的媒体数据。注意解码部分不控制速度，
只要用户从回调函数中返回，解码器就会解码下一部分数据。
*/
HDVSDK_API bool STDCALL HDVPLAY_SetDecodeCallBack(long        lPlayHandle,
	CBDecodeFun fDecodeFun,
	void        *pUserData = NULL);

/******************************************************************************
SDKPLAY图像接口
*******************************************************************************/
/**
* 叠加字符和图像回调函数的指针类型
* @param [OUT] lPlayHandle 当前的解码句柄
* @param [OUT] hDc         画图DC
* @param [OUT] nWidth      视频图像的宽度
* @param [OUT] nHeight     视频图像的高度
* @param [OUT] pUserData   用户数据，调用HDVPLAY_SetDrawFunCallBack时用户输入的值
* @return 无
* @note 无
*/
typedef void (CALLBACK *CBDrawFun)(long         lPlayHandle,
                                   HDC          hDc,
                                   unsigned int nWidth,
                                   unsigned int nHeight,
                                   void         *pUserData);
/**
* 叠加字符和图像，只在实时流上叠加
* @param [IN] lPlayHandle 当前的解码句柄
* @param [IN] fDrawFun    叠加字符和图像回调函数
* @param [IN] pUserData   用户自定义的数据，回调函数原值返回
* @return 返回如下结果：
* - 成功：true
* - 失败：false
* - 获取错误码调用HDVPLAY_GetLastError
* @note 该接口主要完成注册回调函数，获得当前表面的DC，用户可以在这个DC上画图或写字。
*       注：由于视频是缩放显示在窗口里的，所以视频坐标与窗口坐标有种缩放比例如下：显示窗口坐标/视频坐标=显示窗口大小/视频实际大小，
*       计算窗口或视频坐标时要按照该公式计算。
*/
HDVSDK_API bool STDCALL HDVPLAY_SetDrawFunCallBack(long      lPlayHandle,
                                                   CBDrawFun fDrawFun,
                                                   void      *pUserData = NULL);

/**
* 截图
* @param [IN]   lPlayHandle  当前的解码句柄
* @param [IN]   sPicFileName 图像文件名
* @param [IN]   ePicType     保存的图像格式
* @return 返回如下结果：
* - 成功：true
* - 失败：false
*/
HDVSDK_API bool STDCALL HDVPLAY_CapturePicture(long       lPlayHandle,
                                               const char *sPicFileName,
                                               E_PIC_TYPE ePicType);

/**
* 电子放大接口
* @param [IN]   lPlayHandle	当前的解码句柄
* @param [IN]   rcZoomArea	需放大的区域的矩形坐标
* @param [IN]   bZoomOut	-TRUE:放大;-FALSE:恢复
* @return 返回如下结果：
* - 成功：true
* - 失败：false
*/
HDVSDK_API bool STDCALL HDVPLAY_SetZoomAreaRect(long lPlayHandle, 
												RECT rcZoomArea, 
												BOOL bZoomOut = TRUE);

/**
* YUV转RGB24接口
* @param [IN]   yuv	yuv数据块,CBDecodeFun的buf参数
* @param [IN]   rgb24	输出内存块,大小必须大于或等于width*height*3
* @param [IN]   width	图像宽
* @param [IN]   height	图像高
* @return 返回如下结果：
* - 成功：true
* - 失败：false
*/
HDVSDK_API bool STDCALL HDVPLAY_YUVToRGB24(unsigned char* yuv, unsigned char* rgb24, int width, int height);

#ifdef __cplusplus
}
#endif //#ifdef __cplusplus

#endif //#ifndef _HDV_SDK_PLAY_12781258KJFKALJFI_H_
