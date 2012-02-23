

::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
	SLR: Simple Large Resolution for JA2 1.13
::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

Source & sti files modify: zwwooooo



发布 http://zww.me/archives/25584
TBS  http://tbsgame.net/bbs/index.php?showtopic=65473
project http://code.google.com/p/ja2v113-slr-project/




::::::::: 设置中文版方法 :::::::::

1. 把 TBS 1.13 lang zh_CN（原名 TBS Chinese(GB) patch）补丁文件覆盖到游戏目录
svn地址 1 https://81.169.133.124/source/ja2/trunk/GameData/Chinese_Version
svn地址 2 https://tbs-chinese-gb-patch.googlecode.com/svn/trunk

2. 然后把打开 ja2.ini，在
VFS_CONFIG_INI = vfs_config.SLR.ini
前面加个英文分号 ;

3. 再把
; VFS_CONFIG_INI = vfs_config.SLR_CN.ini
前面的分号去掉，保存退出。

4. 运行 ja2_SLR_cn.exe 进行游戏。