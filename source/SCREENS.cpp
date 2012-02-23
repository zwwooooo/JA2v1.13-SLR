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

//zwwooooo: Big resolution: ������� - ȫ�������� local.h -->
/* �̶�ս�Ե�ͼ������Ļ��СΪ1024*768 - ����2���²���������
Game Clock.h - ����ʱ����ʾ�͵��λ��
mapscreen.cpp - ս�Խ����ͼ���������ʾ������λ��
Map Screen Interface Border.cpp - ս�Խ��������ʾλ�õ�
Map Screen Interface Bottom.cpp - ս�Խ��������ʾλ�õ�
����� SCREEN_WIDTH��SCREEN_HEIGHT */
int	SCREEN_WIDTH_1024;
int	SCREEN_HEIGHT_768;
//��������: ������������ж���Ҫ�޸ĵĽ����ļ���
int	iResolution_BIG;
/*����ȫ�ֱ���: Ŀǰ�ֱ��ʵĿ����߲���
- ����ս�Ե�ͼ�������½���Ϣ��ʾ�߶� Strategic\message.cpp
- ����ս������ͼƬ��Ⱦ��С Strategic\Render Dirty.cpp */
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