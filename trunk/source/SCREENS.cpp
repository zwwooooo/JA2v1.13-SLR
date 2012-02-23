#ifdef PRECOMPILEDHEADERS
	#include "JA2 All.h"
#else
	#include "Screens.h"
#endif

int iResolution;		// INI file
int iPlayIntro;
/* WANNE, Sgt.Kolja
 * INI file (Windowed or Fullscreen) 
 * REPLACE all defines WINDOWED_MODE with this variable
 * this is the LAST occurence of WINDOWED_MODE !
 * If (and only if) optionally set, we got a preset of
 * Windowed Screen. But this can be overloaded by INI or CmdLine
 */
#ifdef WINDOWED_MODE 
int iScreenMode = 1;	/* 1 for Windowed, 0 for Fullscreen */
#else
int iScreenMode = 0;	/* 0 for Fullscreen */
#endif
BOOL bScreenModeCmdLine = FALSE;

UINT16 SCREEN_WIDTH;
UINT16 SCREEN_HEIGHT;

//zwwooooo: Big resolution: 定义变量 - 全局声明在 local.h -->
/* 固定战略地图界面屏幕大小为1024*768 - 定义2个新参数来限制
Game Clock.h - 控制时间显示和点击位置
mapscreen.cpp - 战略界面地图相关数据显示、操作位置
Map Screen Interface Border.cpp - 战略界面界面显示位置等
Map Screen Interface Bottom.cpp - 战略界面界面显示位置等
里面的 SCREEN_WIDTH，SCREEN_HEIGHT */
int	SCREEN_WIDTH_1024;
int	SCREEN_HEIGHT_768;
//变量定义: 定义个变量来判断需要修改的界面文件名
int	iResolution_BIG;
/*声明全局变量: 目前分辨率的宽、高参数
- 调整战略地图界面左下角信息显示高度 Strategic\message.cpp
- 调整战术界面图片渲染大小 Strategic\Render Dirty.cpp */
int SCREEN_WIDTH_BIG;
int SCREEN_HEIGHT_BIG;
//zwwooooo: Big resolution <--

INT16 iScreenWidthOffset;
INT16 iScreenHeightOffset;

BOOLEAN fDisplayOverheadMap;

Screens GameScreens[MAX_SCREENS] =
{
	{ EditScreenInit,							EditScreenHandle,							EditScreenShutdown					}, 
	{ SavingScreenInitialize,	 SavingScreenHandle,						SavingScreenShutdown				}, // Title Screen
	{ LoadingScreenInitialize,	LoadingScreenHandle,					LoadingScreenShutdown				}, // Title Screen
	{ ErrorScreenInitialize,		ErrorScreenHandle,						ErrorScreenShutdown					}, // Title Screen
	{ InitScreenInitialize,		InitScreenHandle,							InitScreenShutdown					}, // Title Screen
	{ MainGameScreenInit,					MainGameScreenHandle,					MainGameScreenShutdown			},
	{ AniEditScreenInit,					AniEditScreenHandle,					AniEditScreenShutdown				},
	{ PalEditScreenInit,					PalEditScreenHandle,					PalEditScreenShutdown				},
	{ DebugScreenInit,						DebugScreenHandle,						DebugScreenShutdown					},
	{ MapScreenInit,							MapScreenHandle,							MapScreenShutdown						},
	{ LaptopScreenInit,						LaptopScreenHandle,						LaptopScreenShutdown				},
	{ LoadSaveScreenInit,					LoadSaveScreenHandle,					LoadSaveScreenShutdown			},
	{ MapUtilScreenInit,					MapUtilScreenHandle,					MapUtilScreenShutdown				},
	{ FadeScreenInit,							FadeScreenHandle,							FadeScreenShutdown					},
	{ MessageBoxScreenInit,				MessageBoxScreenHandle,				MessageBoxScreenShutdown		},
	{ MainMenuScreenInit,					MainMenuScreenHandle,					MainMenuScreenShutdown			},
	{ AutoResolveScreenInit,			AutoResolveScreenHandle,			AutoResolveScreenShutdown		},
	{ SaveLoadScreenInit,					SaveLoadScreenHandle,					SaveLoadScreenShutdown			},
	{ OptionsScreenInit,					OptionsScreenHandle,					OptionsScreenShutdown				},
	{ ShopKeeperScreenInit,				ShopKeeperScreenHandle,				ShopKeeperScreenShutdown		},
	{ SexScreenInit,							SexScreenHandle,							SexScreenShutdown						},
	{ GameInitOptionsScreenInit,	GameInitOptionsScreenHandle,	GameInitOptionsScreenShutdown		},
	{ DemoExitScreenInit,					DemoExitScreenHandle,					DemoExitScreenShutdown			},
	{ IntroScreenInit,						IntroScreenHandle,						IntroScreenShutdown					},
	{ CreditScreenInit,						CreditScreenHandle,						CreditScreenShutdown				},
	{ MPJoinScreenInit,						MPJoinScreenHandle,						MPJoinScreenShutdown				}, // OJW - 20081129
	{ MPHostScreenInit,						MPHostScreenHandle,						MPHostScreenShutdown				},
	{ MPScoreScreenInit,					MPScoreScreenHandle,					MPScoreScreenShutdown				}, // OJW - 20081222
	{ MPChatScreenInit,					MPChatScreenHandle,					MPChatScreenShutdown				}, // OJW - 20090314
	{ MPConnectScreenInit,					MPConnectScreenHandle,					MPConnectScreenShutdown				}, // OJW - 20090422

#ifdef JA2BETAVERSION
	{ AIViewerScreenInit,					AIViewerScreenHandle,			AIViewerScreenShutdown			},
#endif

	{ QuestDebugScreenInit,				QuestDebugScreenHandle,		QuestDebugScreenShutdown		}
};