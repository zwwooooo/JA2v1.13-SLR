#ifndef __LOCAL_DEFINES_
#define __LOCAL_DEFINES_

#include "Screens.h"





//
// Make sure the application has a name
//

#define APPLICATION_NAME		"Jagged Alliance 2 v1.13"
#define APPLICATION_NAMEW		L"Jagged Alliance 2 v1.13"

//
// Basic defines for the video manager. These represent the starting values
//

#ifdef BOUNDS_CHECKER
	#define		WINDOWED_MODE
#endif

#ifdef _DEBUG
 #define WINDOWED_MODE
#endif

extern UINT16	SCREEN_WIDTH;
extern UINT16	SCREEN_HEIGHT;

//zwwooooo: Big resolution: 声明全局变量 - 变量定义在 SCRENS.cpp -->
/* 固定战略地图界面屏幕大小为1024*768 - 定义2个新参数来限制
Game Clock.h - 控制时间显示和点击位置
mapscreen.cpp - 战略界面地图相关数据显示、操作位置
Map Screen Interface Border.cpp - 战略界面界面显示位置等
Map Screen Interface Bottom.cpp - 战略界面界面显示位置等
里面的 SCREEN_WIDTH，SCREEN_HEIGHT */
extern int	SCREEN_WIDTH_1024;
extern int	SCREEN_HEIGHT_768;
//定义个变量来判断需要修改的界面文件名
extern int	iResolution_BIG;
/*声明全局变量: 目前分辨率的宽、高参数
- 调整战略地图界面左下角信息显示高度 Strategic\message.cpp
- 调整战术界面图片渲染大小 Strategic\Render Dirty.cpp */
extern int	SCREEN_WIDTH_BIG;
extern int	SCREEN_HEIGHT_BIG;
//zwwooooo: Big resolution <--

extern int iResolution;			// Resolution id from the ini file
extern int iPlayIntro;
extern INT16 iScreenWidthOffset;
extern INT16 iScreenHeightOffset;

extern BOOLEAN fDisplayOverheadMap;

#define PIXEL_DEPTH			16

//
// These defines are used as MUTEX handles.
//

#define MAX_MUTEX_HANDLES	 32

#define REFRESH_THREAD_MUTEX	0
#define FRAME_BUFFER_MUTEX	1
#define MOUSE_BUFFER_MUTEX	2
#define DIRTY_BUFFER_MUTEX	3
#define SCROLL_MESSAGE_MUTEX	4


#endif