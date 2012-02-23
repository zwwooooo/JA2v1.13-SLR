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

//zwwooooo: Big resolution: ����ȫ�ֱ��� - ���������� SCRENS.cpp -->
/* �̶�ս�Ե�ͼ������Ļ��СΪ1024*768 - ����2���²���������
Game Clock.h - ����ʱ����ʾ�͵��λ��
mapscreen.cpp - ս�Խ����ͼ���������ʾ������λ��
Map Screen Interface Border.cpp - ս�Խ��������ʾλ�õ�
Map Screen Interface Bottom.cpp - ս�Խ��������ʾλ�õ�
����� SCREEN_WIDTH��SCREEN_HEIGHT */
extern int	SCREEN_WIDTH_1024;
extern int	SCREEN_HEIGHT_768;
//������������ж���Ҫ�޸ĵĽ����ļ���
extern int	iResolution_BIG;
/*����ȫ�ֱ���: Ŀǰ�ֱ��ʵĿ��߲���
- ����ս�Ե�ͼ�������½���Ϣ��ʾ�߶� Strategic\message.cpp
- ����ս������ͼƬ��Ⱦ��С Strategic\Render Dirty.cpp */
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