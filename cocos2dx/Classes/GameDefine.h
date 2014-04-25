// #if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
// #include <winsock2.h>
// #endif

#ifndef __GAMEDEFINE_H__
#define	__GAMEDEFINE_H__
#include "Top.h"
#include "Tool.h"
#include "MobClickCpp.h"//
#include "UmengFunction.h"//

#define FONT_SIZE_SMALLERE          12
#define FONT_SIZE_SMALL				14
#define FONT_SIZE_MIDDLE			16
#define FONT_SIZE_BIG				18
#define FONT_SIZE_BIGER             20
typedef unsigned char byte;

#define SERVER_VER             10

#define FONT_NAME_NORMAL           "Arial"
#define FONT_NAME                  "Thonburi"

//
//#define WHITE                      255,255,255
//#define RED                        255,0,0
//#define GREYYELLOW                 225,170,88
//#define GREEN1                     4,251,48
//#define YELLOW1                    223,225,116
//#define YELLOW2                    251,250,2
//#define BLUE1                      3,43,138
//#define BLUE2                      0,30,255
//#define YELLOW3                    255,253,48
//#define PURPLE                     67,54,230
//#define PINK                       244,62,202


#define CH_STRING(str)  stringToCH(str).c_str()
#ifndef max
#define max(a,b)            (((a) > (b)) ? (a) : (b))
#endif

#ifndef min
#define min(a,b)            (((a) < (b)) ? (a) : (b))
#endif

#define SCRIPT_MAP_TAG   9900
enum
{
	TouchPriorityMAX = -1000,

	TouchPriorityMenuButtonZ = -200,
	TouchPriorityColorZ=-180,
	TouchPriorityMenuButton = -150,
    TouchPriorityMenuButtonS = -140,
	TouchPriorityColor=-128,
	TouchPriorityMenu=-100,

	TouchPriorityButton = -80,

	TouchPriorityMIN = 0,

};//��ť�˵������ȼ�

enum{
	SCENE_ID_NULL = -1,
	SCENE_ID_LOAD,
	SCENE_ID_LOGIN,
    SCENE_ID_CARTOON,
	SCENE_ID_GAME,
	SCENE_ID_SCENARIO,
};//SCENE_ID; 

enum{
	ZORDER_MIN = -1,
	G_Z_NULL = 0,//��
	G_Z_MAP,//��ͼ+����
	G_Z_EFFECT,//��Ч��
	G_Z_WEATHER,//������
	G_Z_UI,//������ui��
	G_Z_DIALOG,//�Ի���
	G_Z_COLOR,//��͸�������
	G_Z_MENU,
	G_Z_FIGHT,
	G_Z_FIGHTRESULT,
	G_Z_MENUZ,
	G_Z_ACTOR,
	G_Z_INTERFACE,
	G_Z_SLOT,
	G_Z_TSK,//������
	G_Z_MESSAGE,//��Ϣ��
	G_Z_SCRIPT,//�ű�
	G_Z_LIMIT=100,//����
	ZORDER_MAX=2000
};//GAMESCENE_Z;

enum
{
	G_ID_MAP=1,
	G_ID_WEATHER,
	G_ID_COLOR,
};//GAMESCENE_ID
enum
{
	ITEM_MATERIAL=0,//����
	ITEM_GIFT_PACK,//���
};
enum
{
	STAR_LOOK=0,//����
	STAR_EQUIP,//װ��
	STAR_PACK,//����
};
enum
{
	FIGHT_WIN=1,
	FIGHT_LOSE,	
};
enum
{
	GIFT_UNRECEIVE=0,//������ȡ
	GIFT_CAN_RECEIVE,//����ȡ
	GIFT_RECEIVEED,//����ȡ
};
enum
{
	W_TYPE_CLOUDY=0,//���� ��Ч��
	W_TYPE_FINE,//����
	W_TYPE_RAIN,//��
	W_TYPE_SNOW,//ѩ
	W_TYPE_BRUME,//��
};
enum
{
	G_ID_MOVEITEM,
};//

//enum
//{
//	ZORDER_MIN = -1,
//	//ZORDER_MAX = 2000,
//	ZORDER_MAX = 13,
//};//Z�Ἣֵ

enum{
	SCRIPT_ID_NULL = 0,
	SCRIPT_ID_SAY,
	SCRIPT_ID_SETSITE,
	SCRIPT_ID_ADDNPC,
	SCRIPT_ID_SETDIR,
	SCRIPT_ID_MOVETO,
	SCRIPT_ID_DELNPC,
	SCRIPT_ID_SETSCRIPT,
	SCRIPT_ID_STOPSAY,
	SCRIPT_ID_OPENFUNCTION,
	SCRIPT_ID_MISSION,
	SCRIPT_ID_OVER,
	SCRIPT_ID_GUIDE,
};//SCRIPT_ID;

enum{
	MAP_TYPE_SINGLE=0,//��ͼ
	MAP_TYPE_SINGLECYC,//��ͼѭ��
	MAP_TYPE_MULTI,//��ͼ
	MAP_TYPE_MULTICYC,//��ͼѭ��

	// 	MAP_TYPE_ATLAS,//������ͼ
// 	MAP_TYPE_WORLD,//�����ͼ
// 	MAP_TYPE_COMMONFIGHT,//��ͨս����ͼ
// 	MAP_TYPE_BOSSFIGHT,//bossս����ͼ
};//MAP_TYPE;


enum{
	ACTOR_TYPE_ROLE = 0,//����--���
	ACTOR_TYPE_PARTNER,//���
	ACTOR_TYPE_WARPET,//ս��
	ACTOR_TYPE_NPC,//npc
	ACTOR_TYPE_FIGHTNPC,//npc
	ACTOR_TYPE_OTHER,//�������
};//ACTOR_TYPE;


enum{
	WEAPON_TYPE_KNIFE = 0,//��
	WEAPON_TYPE_AXE,//��
	WEAPON_TYPE_GUN,//ǹ
	WEAPON_TYPE_CANNON,//��

};//WEAPON_TYPE;

enum{
	ACTOR_ACTION_STAND = 0,//վ�� 
	ACTOR_ACTION_MOVE,//�ƶ�
	ACTOR_ACTION_OTHER,//����
	ACTOR_ACTION_FIGHTSTAND,//վ��//
	ACTOR_ACTION_SPRINT,//���
	ACTOR_ACTION_ATTACK,//����
    ACTOR_ACTION_SKILL,//����
	ACTOR_ACTION_UNATTACK,//����
	ACTOR_ACTION_DIE,//����
	ACTOR_ACTION_STATE,//״̬
//	ACTOR_ACTION_VIC,//ʤ��//

};//ACTOR_ACTION;

enum{
//	FIGHT_STATE_DETACH=0,//ս��ǰ����
	FIGHT_STATE_ACTORINTO,//��ɫ����
	FIGHT_STATE_READY,//��ɫ׼��
	FIGHT_STATE_BUFSKILL,//��������
	FIGHT_STATE_MOVE,    //�ƶ�
	FIGHT_STATE_PAUSE,   //�ȴ��˶�����
	FIGHT_STATE_ATTACK,//��ɫ����
	FIGHT_STATE_SKILLPAUSE,//�ȴ����ܽ���
	FIGHT_STATE_SKILLEND,//�����ƶ�����
	FIGHT_STATE_UNATTACK,//�ܻ�
//	FIGHT_STATE_ATTACKSKILL,//���ܹ���
//	FIGHT_STATE_ATTACKED,//���������״̬
//	FIGHT_STATE_ATTACK;//�������״̬
	FIGHT_STATE_DIE,//����
	FIGHT_STATE_CURRENTSTATE,
	FIGHT_STATE_VIC,//ʤ��
	FIGHT_STATE_END,//����

};//FIGHT_STATE;

enum
{
	DIALOG_TYPE_SAY=0,
	DIALOG_TYPR_SELECT,
};//DialogType

enum
{
    /*public static final byte*/ MISSIONSTATE_NOREC0=0,//δ��
    /*public static final byte*/ MISSIONSTATE_YESREC1=1,//�ѽ�
    /*public static final byte*/ MISSIONSTATE_FINISH2=2,//�Ѵ��
    /*public static final byte*/ MISSIONSTATE_OVER3=3,//���
};
enum
{
    /*public static final byte*/ EQUIPSITE_HAND1=-1,//
	/*public static final byte*/ EQUIPSITE_HEAD2=-2,//
	/*public static final byte */EQUIPSITE_BODY3=-3,//
	/*public static final byte*/ EQUIPSITE_FOOT4=-4,//
	/*public static final byte*/ EQUIPSITE_PARTS5=-5,//
	/*public static final byte*/ EQUIPSITE_PARTS6=-6,//

};
enum
{
	 G_MENU_ROLE=0,//����
	 G_MENU_PACK,//����
	 G_MENU_RECRUIT,//��ļ����
     G_MENU_PERFECT,//ͳ��	
	 G_MENU_BATTLE,//����
	 G_MENU_EQUIP,//װ��
	 G_MENU_ACTIVE,//��Ծ�� 
	 G_MENU_STARLOOK,//����̨
	 G_MENU_SHOOTARROW,//�ٲ�����
	 G_MENU_SKYBOOK,//����Ժ
	 G_MENU_ARENA,//���䳡
	 G_MENU_BARRACKS,//��Ӫ	 
	 G_MENU_HIDEEQUIP,//�ر���
	 G_MENU_SEQUIP,//����	
	 G_MENU_CULTIVATE,//����
	 G_MENU_LOGIN,//��½
	 G_MENU_REPETITION,//����

	 G_MENU_FIGHT,//ս��

	 G_MENU_SYSTEMSET, //ϵͳ����
	 G_MENU_ONLINE,//���߽���
	 G_MENU_GETNOGETITEM,//����
	 G_MENU_GETRMB,//����

	 G_MENU_DRILL,//ѵ��	 
     G_MENU_STAR,//�ǳ��ػ� 
	 G_MENU_STAREXCHANGE,//�ǳ��һ�	 
	 G_MENU_STRENGTHEN,//ǿ��
     //G_MENU_REPETITION,//����
	 
	 
	 G_MENU_ADD,//���Լӳ�
	 
	 G_MENU_SKILL,//����
	 G_MENU_SEIZE,//����
		 
	 G_MENU_QUIT, //���ص�UI
	 G_MENU_CHAT,//����
	 G_MENU_FRIEND,//����
	 G_MENU_HEROES,//Ӣ����
	 G_MENU_RANKINGS,//���а�
	 G_MENU_DEMONSTATION,//ն��̨
	 G_MENU_MOUNT,//����ϵͳ
	 G_MENU_SWEEP,//ɨ��
	 
	 G_MENU_VIPRECHARGE, //VIP��ֵ

	 G_MENU_FIGHTRESULT, //ս�����
	 G_MENU_GUIDE,//ǿ�ƽ�ѧ
	 G_MENU_FEEDBACK,//����ҷ���
};
enum
{
    FUNCTION_ROLE=100,//��ɫ
	FUNCTION_PACK=101,//����
	FUNCTION_RECRUIT=102,//��ļ
	FUNCTION_PERFECT=103,//ͳ��
	FUNCTION_BATTLE=104,//����
	FUNCTION_EQUIP=105,//װ��  ұ��
	FUNCTION_EVERYDAY=106,//��Ծ
	FUNCTION_LOOKSTAR=107,//����
	FUNCTION_SHOOTARROW=108,//���
	FUNCTION_PAPERWAR=109,//ֽ��
	FUNCTION_ARENA=110,//����
	FUNCTION_BARRACK=111,//��Ӫ 
	FUNCTION_HIDEEQUIP=112,//�ر�
	FUNCTION_SEQUIP=113,//����
    FUNCTION_CULTIVATE=114,//����
    FUNCTION_LOGIN=115,//��½
	FUNCTION_REPETITION=116,//����ս��
    FUNCTION_ONLINE=119,//���߽���
	FUNCTION_GETNOGETITEM=120,//����
    FUNCTION_GETRMB=121,//��Ԫ��
	FUNCTION_TOP=122,//���а�
	FUNCTION_FRIEND=123,//����	
	FUNCTION_TITLE=124,//�ƺ�

};
enum{
    /*public static final byte*/ SOLDIERTYPE_INFANTRY0=0,//����
	/*public static final byte*/ SOLDIERTYPE_ARCHER1=1,//����
	/*public static final byte*/ SOLDIERTYPE_SOWAR2=2,//���
	/*public static final byte*/ SOLDIERTYPE_ADVISER3=3,//ıʿ
};
enum{
	/*public static final byte*/ L4_HP0=0,//����
	/*public static final byte*/ L4_ATTACK1=1,//����
	/*public static final byte*/ L4_DEFENCE2=2,//����
	/*public static final byte*/ L4_ATTACKSPEED3=3,//����
};
enum{
	/*public static final byte*/ EQUIP_ATT0=0,//����  ����
	/*public static final byte*/ EQUIP_DEF1=1,//����  ����
	/*public static final byte*/ EQUIP_SP2=2,//����   ����
	/*public static final byte*/ EQUIP_HP3=3,//����   ���� 
};
enum
{
    DEFINETYPE_NO0=0,
	DEFINETYPE_YES1=1,

};
enum
{
    PARTNERTYPE_ROLE0=0,//����
	PARTNERTYPE_GENERAL1=1,//��
	PARTNERTYPE_SOLDIER2=2,//��
	PARTNERTYPE_NPC3=3,//����

};
enum
{
    ROLETYPE_NORMAL0=0,//��ͨ
	ROLETYPE_BATTLE1=1,//��
	ROLETYPE_QUEER2=2,//����
	ROLETYPE_WARART3=3,//ı��

};
enum
{
    SEXTYPE_MAN0=0,
	EXTYPE_WOMAN1=1,
};
enum
{
    TYPE_MONEY1=1,//���
	TYPE_RMB2=2,//RMB
	TYPE_EXP3=3,//����
    TYPE_ITEM4=4,//����
    TYPE_REPAIR5=5,//��Ϊ
    TYPE_RENOWN6=6,//����
    TYPE_ENERGY7=7,//����
    TYPE_SEQUIPCHIP8=8,//��Ƭ
};
enum
{
    ISLAP_NO0=0,//������
    ISLAP_YES1=1,//����

};
enum
{
    RLAYERSTATE_NOOPEN0=0,//δ��
	RLAYERSTATE_YESOPEN1=1,//�ѿ�
	RLAYERSTATE_PASS2=2,//ͨ��

};
enum
{
	ERRORSTATE_ERROR0=0,//����
	ERRORSTATE_OK1=1,//�ɹ�
	ERRORSTATE_PASSWORDERROR2=2,//�������
	ERRORSTATE_USERNAMELONG3=3,//�û���̫��
	ERRORSTATE_USERNAMEERROR4=4,//�û������Ϸ�
	ERRORSTATE_USERBE5=5,//�û��Ѵ���
	ERRORSTATE_USERNOBE6=6,//�û�������
	ERRORSTATE_PARTNERNOBE7=7,//��鲻����
	ERRORSTATE_MONEYNO8=8,//��Ҳ���
	ERRORSTATE_RMBNO9=9,//����
	ERRORSTATE_ITEMNO10=10,//���ϲ���
	ERRORSTATE_ENERGYNO11=11,//��������
	ERRORSTATE_JADENUMNO12=12,//������������
	ERRORSTATE_NOPARTNER13=13,//û�п���ļ���
	ERRORSTATE_GETSOLDIERSOUL14=14,//�õ�����
	ERRORSTATE_GETGENERALSOUL15=15,//�õ�����
	ERRORSTATE_NOSOLDIERSOUL16=16,//���겻��
	ERRORSTATE_NOGENERALSOUL17=17,//���겻��
	ERRORSTATE_ROLENOBATTLE18=18,//���ǲ�������
	ERRORSTATE_ROLENODEL19=19,//���ǲ��ֽܷ�
	ERRORSTATE_ROLELEVELNO20=20,//���ǵȼ�����
	ERRORSTATE_PERFECTNO21=21,//ͳ������
	ERRORSTATE_NOMOVE22=22,//�����ƶ�
	ERRORSTATE_NAMENO23=23,//�����ظ�
	ERRORSTATE_NOMISSIONOVER24=24,//û����ɵ�����
	ERRORSTATE_NOONEP25=25,//û�е�һ�����
	ERRORSTATE_NORLC026=26,//�����������0
	ERRORSTATE_LOOKSTARMAX27=27,//����̨����
	ERRORSTATE_SOULPACKMAX28=28,//�ǻ������
	ERRORSTATE_SOULNOPICK29=29,//û�п�ʰȡ
	ERRORSTATE_SOULMAX30=30,//�ǻ�װ������
	ERRORSTATE_LEVELNO31=31,//�ȼ�����
	ERRORSTATE_ROLESKILLNO32=32,//���Ǽ���û��
	ERRORSTATE_REPAIRNO33=33,//��Ϊ����
	ERRORSTATE_ROLESKILLREP34=34,//�����ظ�
	ERRORSTATE_NOPARTNER35=35,//û�л��
	ERRORSTATE_BATTLENOPARTNER36=36,//����û�л��
	ERRORSTATE_NOMINTUTE37=37,//����2����
	ERRORSTATE_NORENOWN38=38,//��������
	ERRORSTATE_NODRILL39=39,//��ѵ����
	ERRORSTATE_NOCHIP40=40,//��Ƭ����
	ERRORSTATE_FUNCOPEN41=41,//�����ѿ���
	ERRORSTATE_FUNCNOOPEN42=42,//����δ����
	ERRORSTATE_SCRIPTBEOVER43=43,//�ű������
	ERRORSTATE_SHOOTARROWNUMMAX44=44,//����������
    ERRORSTATE_ARENALEIOK45=45,//��̨ռ��ɹ�
    ERRORSTATE_UPRANKMAX46=46,//�������
	ERRORSTATE_REFNO47=47,//ˢ������
	ERRORSTATE_GIFTNO48=48,//��Ծ���������
	ERRORSTATE_GIFTBE49=49,//��Ծ�������
	ERRORSTATE_RSKILLLEVELMAX50=50,//���Ǽ��ܵȼ����
	ERRORSTATE_SKILLBOOKNO51=51,//�����鲻��
	ERRORSTATE_PLAYERBEVIC52=52,//������ʤ��
	ERRORSTATE_LEVELNOROLELEVEL53=53,//���ܳ������ǵȼ�
	ERRORSTATE_HLAYERBEPASS54=54,//�ر��������ͨ��
	ERRORSTATE_SKYBOOKMAXFIGHTNUM=55,//����Ժ���ս������
	ERRORSTATE_SOULTYPEONE56=56,//�ǻ�������ͬ
	ERRORSTATE_ARENAFIGHTMAX57=57,//����������
	ERRORSTATE_NOME58=58,//�����Լ�
	ERRORSTATE_NOLEIDI59=59,//���ܱ��Լ���̨��
	ERRORSTATE_NOBUYENERGYNUM60=60,//��������������
	ERRORSTATE_NOTIME61=61,//û��
	ERRORSTATE_PACKNOPOS62=62,//������
	ERRORSTATE_SEQUIPLEVELMAX63=63,//�����ȼ����
	ERRORSTATE_EXPSOULNOWEAR64=64,//����������װ��
	ERRORSTATE_EXPSOULNOFUSE65=65,//�����������ں�
	ERRORSTATE_SOULNOFUSE66=66,//û�п��ں��ǻ�
	ERRORSTATE_NOGETITEM67=67,//û��δ�����
	ERRORSTATE_SOULLEVELMAX68=68,//�ǻ�ȼ����
	ERRORSTATE_NOVER69=69,		//�汾����
	ERRORSTATE_NOJOIN70=70,		//���ɽ���
    ERRORSTATE_NOOPENLAYER71=71,//����δ����
	ERRORSTATE_SOULNOFASE72=72,	//û�п��ں��ǻ�


};
enum
{
    SCRIPT_VIEW=50,
	G_UI_ROLE,
	G_UI_MENU,
	G_UI_BUTTON,
	G_UI_TSK,
	G_UI_MESSAGE,
	G_UI_LIMIT,
	CHARGE_TAG,
};
enum
{
    SM_OK=0,
	SM_NO,
	SM_OK_NO,
	SM_SAVE_NO,
	SM_FIGHT_END,
};
enum
{
    SOULTYPE_MAXHP0=0,//�������
    SOULTYPE_ATTACK1=1,//����
	SOULTYPE_DEFENCE2=2,//����
	SOULTYPE_ATTACKSPEED3=3,//����
	SOULTYPE_CRIT4=4,//����
	SOULTYPE_OCRIT5=5,//����
	SOULTYPE_ADDCRITPOWER6=6,//�ӱ���
	SOULTYPE_SPARECRITPOWER7=7,//������
	SOULTYPE_ADDHURT8=8,//����
	SOULTYPE_SPAREHURT9=9,//����	
	SOULTYPE_MONEY10=10,//ͭ��	
	SOULTYPE_EXP11=11,//����	

};

enum
{
	TYPE_NORMAL=0,//����
    TYPE_FIGHT,//ս��
	TYPE_ARENA,//����
	TYPE_ARENALEI,//��̨
	TYPE_SKYBOOK,//����Ժ
	TYPE_HIDEEQUIP,//�ر���
	TYPE_SEIZE,//����
	//TYPE_DEMONSTATION,//ն��̨
};
enum
{
    ROLE_BOY=5600,//������ ������ID
	ROLE_GIRL,//Ů���� ������ID
};
enum
{
    LEFT=0,//��ʾ������
	RIGHT=1,//��ʾ������
};
enum
{
    SERVER_STATE_NORMAL0=0,//������״̬  ��ͨ
	SERVER_STATE_NEW1=1,//������״̬  �·�
	SERVER_STATE_FIRE2=2,//������״̬  ��
	SERVER_STATE_REPAIR3=3,//������״̬  ά��
};
enum
{
    BARRACK_HP0=0,//����
	BARRACK_ATTACK1=1,//����
	BARRACK_DEFENCE2=2,//����
	BARRACK_SP3=3,//����
	BARRACK_CIRT4=4,//����
	BARRACK_OCIRT5=5,//����
	BARRACK_DODGE6=6,//����
	BARRACK_SHOTPRO7=7,//����
};
enum
{
    EFFECTSTATE_NORMAL0=0,//����
	EFFECTSTATE_ATTACK1=1,//����
	EFFECTSTATE_DEFENCE2=2,//����
	EFFECTSTATE_ATTACKSPEED3=3,//�ٶ�
	EFFECTSTATE_CRIT4=4,//����
	EFFECTSTATE_OCRIT5=5,//����
	EFFECTSTATE_REPLY6=6,//�ظ�
	EFFECTSTATE_NODIE7=7,//�޵�
	EFFECTSTATE_POISON8=8,//�ж�
	EFFECTSTATE_SWIM9=9,//ѣ��
	EFFECTSTATE_ADDHURT10=10,//����
	EFFECTSTATE_SPAREHURT11=11,//����	
	EFFECTSTATE_DODGE12=12,//����
	EFFECTSTATE_SHOTPRO13=13,//����
};
enum
{
    ARENA_BACK_ID=1703,//���䳡������ͼid
	HIDEEQUIP_BACK_ID=1704,//�ر��󱳾���ͼid
	SKYBOOK_BACK_ID=1705,//����Ժ������ͼid
	SEIZE_BACK_ID=1706,//���ᱳ����ͼid
};
enum
{   //����������
    UATTACKTYPE_NORMALO=0,//����
	UATTACKTYPE_CIRT1=1,//����
	UATTACKTYPE_DODGE2=2,//����

};
enum
{
    TEAMTYPE_ATTACK1=1,//��������
	TEAMTYPE_UATTACK2=2,//����������
};
enum
{
	CHANNEL_LOCAL_ID=0,
    
};
enum
{
    PEOPLE_NUM0=0,
    PEOPLE_NUM1=20,
    PEOPLE_NUM2=50,
};
enum
{
    CHAT_WORLD=1,
	CHAT_FRIENDS,
	CHAT_SYSTEM,
};
#endif
