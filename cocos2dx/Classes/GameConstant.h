
#ifndef __GAMECONSTANT_H__
#define	__GAMECONSTANT_H__

#include "Tool.h"

#define CH_STRING(str)  stringToCH((std::string)str)


#define FONT_SIZE_SMALL				16
#define FONT_SIZE_MIDDLE			18
#define FONT_SIZE_BIG				20
#define FONT_SIZE_BIGER             22


#define FONT_NAME_NORMAL                     "arial.ttf"

typedef enum{
	G_Z_NULL = -1,
	G_Z_BACKGROUND,
	G_Z_BUILD,
	G_Z_UI,
	G_Z_FIGHT,
	G_Z_ACTOR,
	G_Z_CARTOON,
	G_Z_INTERFACE,
	G_Z_COLOR,
	G_Z_MENU,
// 	G_NULL = -1,
// 	G_Z_MAP,
// 	G_Z_PLAYER,
// 	G_Z_ARROW,
// 	G_Z_UI,
// 	G_Z_COLOR,
// 	G_Z_CHILDMENU,//¶þ¼¶²Ëµ¥
// 	G_Z_MENU,
// 	G_Z_STORYNPC,
// 	G_Z_FIGHT,
// 	G_Z_TSK,
// 	G_Z_DIALOG,
// 	G_Z_BLACKSCREEN,
}GAMESCENE_Z;


#endif