#ifndef __CmdMaker_H__ 
#define __CmdMaker_H__ 
 
#include "cocos2d.h" 
//#include "cocos-ext.h" 
//#include "AppMacros.h" 
#include "stdafx.h" 
#include "../DataInput/CoutStream.h" 
#include "../BaseUpCMD.h" 
#include "../BaseDownCMD.h" 
 
#include "CMD_User_LoginGame_up.h" 

 
USING_NS_CC; 
//USING_NS_CC_EXT; 
 
// static const int CMD_User_GetOneServerState                        =              1; // �õ��׷�״̬ 
// static const int CMD_User_Register                                 =              2; // ע�� 
// static const int CMD_User_LoginGame                                =              3; // ��½ 
// static const int CMD_User_SelectServer                             =              4; // ѡ������� 
// static const int CMD_User_IsRole                                   =              5; // ��ɫ�Ƿ���� 
// static const int CMD_User_CreateRole                               =              6; // �������� 
// static const int CMD_User_IsOnePartner                             =              7; // �Ƿ���һ����� 
// static const int CMD_User_GetOnePartner                            =              8; // ���һ������б� 
// static const int CMD_User_SelectOnePartner                         =              9; // ѡ��һ����� 
// static const int CMD_User_GetPlayerBasic                           =             10; // �����һ�����Ϣ 
// static const int CMD_User_GetPlayerItem                            =             11; // ��õ��� 
// static const int CMD_User_GetPlayerMission                         =             12; // ���������� 
// static const int CMD_User_GetPlayerCity                            =             13; // ���������Ϣ 
// static const int CMD_Perfect_GetPerfect                            =             14; // ���ͳ�� 
// static const int CMD_Partner_GetHouseInfo                          =             15; // ��þƹ���Ϣ 
// static const int CMD_Partner_RecruitPartner                        =             16; // ��ļ��� 
// static const int CMD_Partner_RecruitOK                             =             17; // ��ļȷ�� 
// static const int CMD_Partner_DelPartner                            =             18; // �ֽ��� 
// static const int CMD_Partner_GetDelSoul                            =             19; // ��÷ֽ���� 
// static const int CMD_Partner_SNYCTime                              =             20; // ͬ����ļʱ�� 
// static const int CMD_Rep_GetMap                                    =             21; // ��ô��ͼ��Ϣ 
// static const int CMD_Rep_GetRepetition                             =             22; // ��ø�����Ϣ 
// static const int CMD_Rep_BuyCount                                  =             23; // �򸱱������ 
// static const int CMD_Rep_IntoRepetition                            =             24; // ���븱���� 
// static const int CMD_Battle_LayoutBattle                           =             25; // ���� 
// static const int CMD_Rep_GetFightResult                            =             26; // �õ�ս����� 
// static const int CMD_Star_GetLookStar                              =             27; // �õ�����̨ 
// static const int CMD_Star_Look                                     =             28; // ���� 
// static const int CMD_Star_LookRmb                                  =             29; // Ԫ������ 
// static const int CMD_Star_LookPick                                 =             30; // ʰȡ 
// static const int CMD_Star_LookOnePick                              =             31; // һ��ʰȡ 
// static const int CMD_Star_LookFuse                                 =             32; // �����ں� 
// static const int CMD_Star_OneFuse                                  =             33; // һ���ں� 
// static const int CMD_Star_GetSoldierStar                           =             34; // ��ñ����ǻ� 
// static const int CMD_Star_Lock                                     =             35; // �������� 
// static const int CMD_Star_Fuse                                     =             36; // �ں� 
// static const int CMD_Star_StarWear                                 =             37; // ���ǻ� 
// static const int CMD_Star_StarOff                                  =             38; // ���ǻ� 
// static const int CMD_Star_StarMove                                 =             39; // �ƶ��ǻ� 
// static const int CMD_Star_GetExchangeList                          =             40; // �õ��һ��б� 
// static const int CMD_Star_Exchange                                 =             41; // �һ��ǻ� 
// static const int CMD_Role_GetRole                                  =             42; // ��ý�ɫ 
// static const int CMD_Role_FitSkill                                 =             43; // ��ɫװ������ 
// static const int CMD_Role_GetSkillList                             =             44; // �õ���ɫ�����б� 
// static const int CMD_Role_SelectSkill                              =             45; // ѡ���ɫ���� 
// static const int CMD_Role_GetRepairCost                            =             46; // �����Ϊ���� 
// static const int CMD_Equip_GetEquip                                =             47; // ���װ�� 
// static const int CMD_Equip_Up                                      =             48; // ����װ�� 
// static const int CMD_Equip_RmbUp                                   =             49; // Ԫ������װ�� 
// static const int CMD_Mission_Accept                                =             50; // ������ 
// static const int CMD_Mission_Finish                                =             51; // ������ 
// static const int CMD_UpRank_GetUpRank                              =             52; // ������� 
// static const int CMD_UpRank_UpRank                                 =             53; // ���� 
// static const int CMD_Barrack_GetBarrack                            =             54; // ��ñ�Ӫ 
// static const int CMD_Barrack_Refurbish                             =             55; // ��Ӫˢ�� 
// static const int CMD_Barrack_GetAdd                                =             56; // �õ���Ӫ���Լӳ� 
// static const int CMD_Barrack_Drill                                 =             57; // ѵ�� 
// static const int CMD_Barrack_SYNCTime                              =             58; // ͬ����Ӫ 
// static const int CMD_User_OpenFunction                             =             59; // �������� 
// static const int CMD_SEquip_GetSEquip                              =             60; // ������� 
// static const int CMD_SEquip_SEquipUp                               =             61; // �������� 
// static const int CMD_HideEquip_GetLayer                            =             62; // �õ��ر���Ĳ� 
// static const int CMD_HideEquip_IntoFight                           =             63; // �ر�����븱�� 
// static const int CMD_HideEquip_FightResult                         =             64; // �ر���ս����� 
// static const int CMD_HideEquip_Sweep                               =             65; // �ر���ɨ�� 
// static const int CMD_ShootArrow_GetShootArrow                      =             66; // �õ���� 
// static const int CMD_ShootArrow_Arrow                              =             67; // ��� 
// static const int CMD_ShootArrow_GodArrow                           =             68; // ���� 
// static const int CMD_Script_ScriptOver                             =             69; // �ű���� 
// static const int CMD_Arena_GetArena                                =             70; // �õ����䳡 
// static const int CMD_Arena_IntoArenaLei                            =             71; // ������̨ 
// static const int CMD_Arena_IntoArena                               =             72; // ������� 
// static const int CMD_Arena_FightResultLei                          =             73; // �õ���̨��� 
// static const int CMD_Arena_FightResult                             =             74; // �õ������� 
// static const int CMD_Pack_Arrange                                  =             75; // �������� 
// static const int CMD_SEquip_GetSeize                               =             76; // ����������� 
// static const int CMD_SEquip_IntoSeize                              =             77; // ������������ 
// static const int CMD_SEquip_FightResult                            =             78; // ���������� 
// static const int CMD_Arena_RefArena                                =             79; // ˢ�±��䳡 
// static const int CMD_Arena_SNYCTime                                =             80; // ���䳡ͬ��ʱ�� 
// static const int CMD_Arena_BuyFightNum                             =             81; // �������� 
// static const int CMD_Arena_BuyRefNum                               =             82; // ��ˢ�´��� 
// static const int CMD_SkyBook_GetSkyBook                            =             83; // �������Ժ 
// static const int CMD_SkyBook_RefSkyBook                            =             84; // ˢ������Ժ 
// static const int CMD_SkyBook_RmbRefSkyBook                         =             85; // Ԫ��ˢ������Ժ 
// static const int CMD_SkyBook_IntiFight                             =             86; // ����ս�� 
// static const int CMD_SkyBook_FightResult                           =             87; // ս����� 
// static const int CMD_Active_GetActive                              =             88; // ��û�Ծ�� 
// static const int CMD_Active_GetGift                                =             89; // �콱 
// static const int CMD_Pack_GetMoney                                 =             90; // ȡ�õ��߼�ֵ 
// static const int CMD_Pack_SellItem                                 =             91; // �������� 
// static const int CMD_Role_SkillUp                                  =             92; // ��ɫ�������� 
// static const int CMD_Pack_GetOpenMoney                             =             93; // �õ�����Ԫ�� 
// static const int CMD_Pack_OpenPack                                 =             94; // ������ 
// static const int CMD_Pack_UseGift                                  =             95; // ʹ����� 
// static const int CMD_Mission_UpData                                =             96; // ������� 
// static const int CMD_User_Site                                     =             97; // λ�� 
// static const int CMD_User_AddExp                                   =             98; // ��ǰ״̬ 
// static const int CMD_Vip_GetVip                                    =             99; // ���vip 
// static const int CMD_Vip_VipLevel                                  =            100; // vip�ȼ� 
// static const int CMD_User_AddEnergy                                =            101; // ���� 
// static const int CMD_User_GetEnergyRmb                             =            102; // �õ�����rmb 
// static const int CMD_User_BuyEnergy                                =            103; // �õ�����rmb 
// static const int CMD_Temp_AddMoney                                 =            104; // ��Ǯ 
// static const int CMD_Temp_AddRmb                                   =            105; // ��rmb 
// static const int CMD_OnLine_GetAward                               =            106; // �����콱 
// static const int CMD_OnLine_SYNC                                   =            107; // ����ͬ�� 
// static const int CMD_User_GetFunction                              =            108; // �õ����� 
// static const int CMD_User_GetNoGetItem                             =            109; // ��ȡδ����� 
// static const int CMD_User_GetRmb                                   =            110; // ��Ԫ�� 
// static const int CMD_Equip_GetItemLayer                            =            111; // ��õ����ڲ� 
// static const int CMD_Top_GetTop                                    =            112; // �õ����а� 
// static const int CMD_Chat_GetChat                                  =            113; // �õ��������� 
// static const int CMD_Chat_SendSay                                  =            114; // �������� 
// static const int CMD_Friend_GetFriend                              =            115; // �õ������б� 
// static const int CMD_Friend_GetBlack                               =            116; // �õ��������б� 
// static const int CMD_Friend_AddFriend                              =            117; // �ӵ����� 
// static const int CMD_Friend_AddBlack                               =            118; // �ӵ������� 
// static const int CMD_Friend_Del                                    =            119; // ɾ�� 
// static const int CMD_Friend_AddFriendName                          =            120; // �ӵ��������� 
// static const int CMD_BattleOne_Save                                =            121; // �������� 
// static const int CMD_BattleOne_Get                                 =            122; // �õ����� 
// static const int CMD_BattleOne_Load                                =            123; // �Զ����� 
// static const int CMD_Title_GetList                                 =            124; // �õ��ƺ��б� 
// static const int CMD_Title_Show                                    =            125; // �ƺ���ʾ 
// static const int CMD_Title_GetReward                               =            126; // �ƺ��콱 
// static const int CMD_Sweep_GetRepetition                           =            127; // ���ɨ������ 
// static const int CMD_Sweep_Start                                   =            128; // ��ʼɨ�� 
// static const int CMD_Sweep_GetStart                                =            129; // �õ���ʼɨ�� 
// static const int CMD_Sweep_SNYCTime                                =            130; // ͬ��ɨ��ʱ�� 
// static const int CMD_Sweep_GetAward                                =            131; // ���ɨ��������Ϣ 
// static const int CMD_Sweep_GetCostRmb                              =            132; // �õ�rmb���� 
// static const int CMD_Sweep_RmbOver                                 =            133; // ������� 
// static const int CMD_User_Exit                                     =            134; // �˳� 
// static const int CONST_CMD_MAX                                     =            135; 
//  
enum COMMAND_TYPE
{
	GET_IMAGE = 1,				/*!< �õ�����PNG, ������ png id */
	GET_ANIMATION = 2,		/*!< �õ����������� ���������� id */
	GET_TERRAIN = 3,      /*!< �õ�������ͼ������:��ͼ id */

	CREATE_ROOT	= 16, /*!< ����Ա */
	ROOT_ENTER = 17, /*!< root ������Ϸ */

	NET_LEAVE = 129, /*!< ����Ͽ� */
	NET_ENTER = 130,	/*!< �������� */	
	NET_HUNGUP = 131, /*!< �������*/
	NET_FLOODED = 132,/*!< ���緺��*/
	NET_FULL = 133,		/*!< ����ӵ�� */
	STOP_SERVER = 134, 	/*!< ֹͣ���� */

	CMD_LOGIN = 135,  	/*!< ��¼ */

	CREATE_ROLE	= 136,   /*<! �½���ɫ */
	BATTLE = 137,      		/*<! ս�� */
	ENTER_WORLD =   138, /*<! ������Ϸ  */
	ROLE_INFO = 139, /*!< �õ���ɫ��Ϣ */
	LOAD_OTHER = 140,/*<! ������Ϸ��load��������  */
	GET_ROLES = 141, /*!< �õ���ɫ�б� */
	NPC_ON_SCREEN = 142, /*!< npc ͬ�� */
	PLAYER_ON_SCREEN = 143,/*!< ���ͬ�� */

	XCHANGE_SCENE = 144, /*!< �л����� */
	WALK = 145, 						/*!<���� */
	MODIFY_POSITION = 146, /*!<����λ��*/
	QUIT_GAME = 147,  /*!<�˳���Ϸ */
	LEARN_SKILL = 148,/*!<ѧϰ���� */
	ADD_SKILL_PLACE = 149,/*!<�����ķ�����λ*/
	UNLEARN_SKILL = 150, /*!<�������� */
	LEARN_MERIDIAN = 151, /*!<ѧϰ���� */
	CLEAN_MERIDIAN = 152, /*!<ϴ�� */
	CMD_NPC = 153,/*!< npc ���� */
	CMD_QUEST = 154, /*!< ��������*/	
	I_EXIT_GAME = 155, /*!< ����������ң���������*/
	ADD_EXP= 156, /*!< ���Ӿ��� */
	ADD_MONEY = 157, /*!< ����Ǯ */
	OPEN_BAG = 158, /*!< �򿪱��� */
	ADD_ITEM = 159, /*!< ʰȡ��Ʒ */
	DELETE_ITEM = 160, /*!< ������Ʒ */
	CHECK_ITEM = 161, /*!< �����Ʒ */
	SORT_ITEM = 162, /*!< ������Ʒ */
	USE_ITEM = 163, /*!< ʹ����Ʒ */

	OPEN_EQUIP = 164,/*!< ��װ���� */
	UNWEAR_EQUIP = 165,/*!< ж��װ�� */
	USE_EQUIP = 166,/*!< ʹ��װ�� */
	ADD_MIT = 167,/*!< ������Ϊֵ */
	CHECK_EQUIP = 168,/*!< �鿴װ�� */
	CHECK_DESC = 169,/*!< �鿴���� */
	HEART_BEAT = 170,/*!< ������ */
	DIFF_EQUIP = 171,/*!< �Ա�װ�� */

	FIND_PATH = 172,/*!< Ѱ· */
	CMD_TIPS = 173, /*!< ��ʾ */

	TEAM_JOIN = 174, /*!< ������� */
	TEAM_ANSWER = 175, /*!< �����Ӧ */
	TEAM_INFO = 176,	/*!< ͬ��������Ϣ */

	OPEN_KUNGFU_UI = 177,/*!<  ���ķ�ui */
	CMD_SHOUT = 178, /*!< ���� */

	VIEW_PLAYER_INFO = 179, /*!< �۲���� */
	CREATE_TONG = 180, /*!< �½��Ű��� */	
	APPLICATION_TONG = 181, /*!< ���������� */
	TONG_LIST		= 182, /*!< �����б� */

	OPEN_PET  = 183,  /*!< �򿪳���װ�� */
	INVITE_TONG = 185, /*!< ���������� */
	BUFF_OPT = 184,/*!< ������ҷ�buff�б� */
	DELETE_PET = 186,/*!< ж�³��� */

	QUEST_LIST = 187, /*!< ��������б� */
	DELETE_BUFF = 188,/*!< ж��BUFF */

	TEAM_LEAVE = 189,  /*!< �뿪���� */
	TEAM_DISMISS = 190, /*!< ��ɢ���� */
	TEAM_CHANGE_LEADER = 191, /*!< �ı���� */

	CMD_FUNC_COMPOSE = 192, /*!< �ϳ���Ʒ */
	CMD_FUNC_DECOMPOSE = 193, /*!< �ֽ���Ʒ */
	CMD_FUNC_STRENGTH = 194, /*!< ǿ����Ʒ */

	CMD_FUNC_PETCOMPOSE = 195,/*!< ����ϳ� */
	QUEST_INFO = 196, /*!< �������� */
	TONG_DISMISS = 197, /*!< ��ɢ���� */

	MAIL_HINT = 198,/*!< �ʼ���ʾ */
	MAIL_CHECKUSER = 199, /*!< �ж�����Ƿ���� */
	MAIL_POST = 200,  /*!< �����ʼ� */
	MAIL_OPEARTION = 201,/*!< �ʼ����� */

	TONG_CHANGE_POSITION = 202, /*!< �ı����ְλ */

	TONG_LEAVE = 204, /*!< �뿪���� */
	PET_FEED = 205,/*!< ����ι�� */

	CMD_FUNC_HOLE = 206, /*!< ��Ʒ��� */
	CMD_FUNC_INLAY = 207, /*!< ��Ʒ��Ƕ */

	SELECT_PETSTRENGTH_ITEM = 208, /*!< ѡ�����ǿ����Ʒ */
	CHECK_PET = 209,/*!< �鿴���� */

	USE_PET = 210,/*!< װ������ */
	TONG_MEMBER_LIST = 211, /*!< ���ɳ�Ա�б� */

	NPC_INFO = 212, /*!< npc����ϸ��Ϣ */
	OTHER_PLAYER_INFO = 213, /*!< ����player����ϸ��Ϣ */

	SELECT_PETCOMPOSE_ITEM = 214, /*!< ѡ�����ϳ���Ʒ*/
	SPLIT_ITEM = 215,/*!< �ֽ���Ʒ */
	MOVE_ITEM = 216,/*!< �ƶ���Ʒ */

	CMD_FUNC_STORE = 217, /*!< ���� */
	OPEN_NPC_STORE = 218,/*!< ��NPC�̵� */

	CMD_FUNC_COMPOSE_MONEY = 219,/*!< ��ѯ�ϳ���Ʒ��Ǯ */

	ADD_FRIEND = 220, /*!< ��Ӻ��� */
	GET_FRIEND_LIST = 221,  /*!< ��ú����б� */
	DEL_FRIEND = 222,  /*!< ɾ������ */

	CMD_FUNC_DECOMPOSE_MONEY = 223,	/*!< ��ѯ�ֽ���Ʒ��Ǯ */
	CMD_FUNC_HOLE_MONEY = 224,		/*!< ��ѯ��Ʒ��׽�Ǯ */
	CMD_FUNC_INLAY_MONEY = 225,		/*!< ��ѯ��Ʒ��Ƕ��Ǯ*/

	CMD_DISCOVERY_COUNTRY = 229, /*!< �����µ����� */

	CMD_FUNC_STRENGTH_MONEY = 230, /*!< ��ѯ��Ʒǿ����Ǯ */
	CMD_FUNC_STRENGTH_RATE = 231, /*!< ��ѯ��Ʒǿ������ */

	CHECK_STORE_ITEM = 232,/*!< �鿴NPC�̵���Ʒ*/
	CHECK_STORE_DESC = 233,/*!< �鿴NPC�̵���Ʒ����*/

	ENTER_SCENE = 234, /*!< ���볡�� */
	OPEN_DEPOT = 235,/*!< �򿪲ֿ� */
	CMD_FUNC_DEPOT = 236,/*!< �ֿ�洢 */

	MAIL_MONEY = 237,/*!< ��ѯ�ʷ� */
	CHECK_MONEY = 238,/*!<��ѯ��Ǯ */

	TRADE_JOIN = 239,/*!<���׼���*/
	TRADE_ANSWER = 240,/*!<����Ӧ�� */
	SYNC_TRADE_ITEM = 241,/*!<ͬ��������Ʒ��Ϣ */
	TRADE_CANCEL = 242,/*!<ȡ������ */
	TRADE = 243,/*!<���׹��� */

	CMD_FUNC_TONG_TRANS = 244, /*!<���ɴ��� */

	CMD_GET_ROLES = 245, /*!<�õ���ɫ��Ϣ */
	LOCK_TRADE = 246,/*!<�������� */

	TONG_DESCRIPT = 247, /*!<�������� */
	TONG_FIRE_MEMBER = 248, /*!<�������� */

	I_DEAD = 249,/*!<���� */
	OPEN_ATTR_POINT = 250,/*!<�򿪼ӵ���� */
	ADD_ATTR_POINT = 251,/*!<�ӵ�*/

	CMD_FUNC_REPAIR = 252,/*!<����*/
	GET_REPAIR_FEE = 253,/*!<�õ������*/

	PET_LOCK_SKILL = 254,/*!<�����������＼��*/
	PET_BIND = 255,		/*!<�󶨽�����*/

	OPEN_MERIDIAN = 256,/*!<�򿪾�������*/
	GET_MERIDIAN_DESC = 257,/*!<�õ���������*/

	CLEAN_ATTR_POINT = 258,/*!<ϴ�����ϵ�*/
	CHANGE_STATE = 259,/*!<��Ҹı�״̬*/

	CMD_FUNC_HOLE_INFO = 260, /*!< ��ѯ��Ʒ�����Ϣ */

	CMD_FUNC_DISMANTLE = 261, /*!< ��ж��ʯ */
	GET_SERIES_INFO = 262, /*!< �õ�����ϵ����Ϣ */


	CMD_FUNC_PET_COMPOSE_MONEY = 263, /*!< ��ѯ����ϳ������Ǯ */

	CMD_FUNC_TESTING = 600, /*!< �ײ���� */   // ����ʲôָ��???	
	CMD_PK = 264, /*!< �����ر�pk״̬ */
	CHECK_ATTRIBUTE = 265, /*!< �鿴�������� */

	PET_DEFEND = 266,	/*!< �����ػ� */
	CMD_SOCIAL = 267,/*!< ���罻���� */

	SYNC_HEALTH = 268,/*!< ͬ����Ѫ */
	SYNC_MANA = 269,/*!< ͬ������ */
	SYNC_PK = 270,/*!< ͬ��pkֵ */

	CMD_BE_ADD_FRIEND = 271, /*!< ��������Ӻ��� */
	OPT_ON_SCREEN = 272,/*!< ͬ������(����/ȡ��)*/

	CMD_SET_QUICK = 273, /*!< ���ÿ���� */

	TEAM_ITEM = 274, 	/*!< �ȴ�����������Ʒ */
	TEAM_ROLL = 275, 	/*!< ROLL�� */

	APPLY_TONG_ARENA = 276, /*!< ����������ս��*/
	SEND_TONG_ARENA = 277, /*!< ���͵�����ս��*/
	CMD_FUNC_SEND = 278, /*!< ͨ�ô���*/
	GET_APPLY_TONG_LIST = 279, /*!< �õ������ս�б�*/
	GET_SEND_POINT = 280, /*!< �õ����д��͵�*/

	TONG_CHANGE_DESCRIPT  = 281, /*!< �޸İ��ɹ���*/
	TONG_NPC_UPGRADE = 282,		/*!< �޸Ľ���NPC����*/	
	TONG_NPC_INFO = 283,		/*!< ����NPC�����ȼ���������Ǯ*/

	CHECK_SKILL = 284,  /*!< �鿴����*/
	DELETE_QUEST = 285, /*!< ��������*/

	PET_CHANGE_ALIAS = 286, /*!< �������*/
	CHECK_NEAR_PLAYERS = 287,/*!< �鿴�������*/
	OTHER_PLAYER_DETAIL = 288,/*!< �鿴���������ϸ��Ϣ*/
	CMD_CHANGE_AVATAR = 289,/*!< ����*/

	PET_SELECT_POTENTIAL_ITEM = 290, /*!< ѡ�񼤷�����Ǳ�ܵ���Ʒ*/
	PET_POTENTIAL = 291,			/*!< ���Ｄ��Ǳ��*/

	PET_EQUIP_USE = 292,			/*!< ������װ������ʹ����Ʒ*/
	QUEST_FIND_PATH = 293,    /*!< �������ʼѰ·*/
	QUIT_CONTEST = 294,       /*!< �˳��д�*/
	EQUIP_BIND = 295,					/*!< ��*/
	DELETE_NPC = 296,         /*!< ɾ����ͬ��Ȧnpc*/
	SEND_ARENA_INTEGRAL = 297,/*!< ����ս������*/
	INSTALL_BUFF = 298,       /*!< ��װbuff*/
	PLAYER_ON_SCREEN_AVATAR = 299, /*!< ͬ�����avatar*/
	PLAYER_ON_SCREEN_WALK = 300,   /*!< ͬ�������·*/
	PLAYER_ON_SCREEN_TONG = 301,   /*!< ͬ����Ұ���*/
	DELETE_PLAYER = 302,           /*!< ɾ����ͬ��Ȧplayer*/ 
	QUEST_SIMPLE_INFO = 303,       /*!< ����򵥽���*/
	PLAYER_ON_SCREEN_BATTLE = 304, /*!< ͬ�����ս��*/

	CMD_TIPS_CODE = 305,       /*!< ��ʾ״̬������*/ 

	PUT_ITEM = 306,				 /*!< �����Ʒ*/ 

	CMD_QUESTION_INFO = 307,				/*!< ������Ϣ*/ 
	CMD_QUESTION_RUN = 308,				 	/*!< ���д���*/ 
	CMD_QUESTION_END = 309,				 	/*!< ��������*/ 

	CMD_GAME_TIME = 310,				 	/*!< ��Ϸʱ��(��)*/

	CMD_CLIENT_READY = 313,				 	/*!< �ͻ��˾���*/
	CMD_OPEN_STORE = 311,				 	/*!< ���̵�*/
	CMD_BUY_GOODS = 312,	/*!< ����Ԫ����Ʒ*/
	CMD_INGOT_RECORD = 314,/*!< �����¼/�ղ�*/

	GM_SHUT_DOWN = 316,						/*!< GM����*/
	GM_SHUT_UP_LIST = 317,					/*!< GM��������*/
	GM_SHUT_UP = 318,						/*!< GM����*/
	GM_QUIT = 319,							/*!< GM�˳���Ϸ*/
	GM_ENTER_WORLD = 320,					/*!< GM������Ϸ*/
	GM_PLAYER_NUM = 321,					/*!< GM��Ϸ����*/
	GM_TALK = 322,							/*!< GM����*/ 

	CMD_VERIFICATION_CODE = 315, /*!< ��֤��֤��*/
	CMD_SET_FLOW = 323,         /*!< ��������*/
	CMD_GM_ROLE_FIND = 324, /*!< ��ɫ����*/
	CMD_GM_ROLE_MANAGEME = 325, /*!< ��ɫ��ѯ*/
	CMD_GM_ROLE_DETAILS = 326, /*!< ��ɫ��ϸ��ѯ*/
	CMD_GM_PET_DETAILS = 327, /*!< ������ϸ��ѯ*/
	CMD_GM_ROLE_ARTICLES = 328, /*!< ��ɫ��Ʒ��ѯ*/
	CMD_GM_ROLE_PETS = 329, /*!< �����ѯ*/

	CMD_CONTINUE_EFFECT = 330,  /*!< ����Ч��*/
	CMD_CLEAN_EFFECT = 331,  /*!< �������Ч��*/
	CMD_CHECK_EFFECT = 332,  /*!< �鿴����Ч��*/
	CMD_SET_VERSION = 333,   /*!< ���ð汾��*/

	CMD_NOTICE = 334, 			/*!< GM�򿪹���*/
	CMD_NOTICE_LIST = 335, 		/*!< GM�����б�*/
	GM_NOTICE_OPT = 336, 		/*!< GM��������*/
	GM_NOTICE_ADD = 337, 		/*!< GM��ӹ���*/

	CMD_SET_PASS_WORD = 340,	/*!< �޸�����*/

	GM_SET_PLAYER_ATTR = 341, 			/*!< GM�޸��������*/
	GM_SET_PET_ATTR = 342, 				/*!< GM�޸ĳ�������*/
	GM_SET_PLAYER_ITEM = 343, 			/*!< GM������Ʒ*/
	GM_SET_PET_SKILL = 344, 			/*!< GM�������＼��*/
	GM_CHECK_PLAYER = 345, 			/*!< GM����������*/
	GM_WATCH = 346, 				/*!< GM׷��*/
	GM_WATCH_LIST = 347, 			/*!< GM׷���б�*/
	GM_FREEZE = 348, 				/*!< GM���*/

	CMD_BUSINESS_OPEN = 349, 		/*!< ��̯λ*/
	CMD_BUSINESS_OPT = 350,			/*!< ����̯λ�����Ʒ*/
	CMD_BUSINESS_BUY = 351,			/*!< ̯λ����*/

	CMD_TITLE_TOP = 352,  		/*!< �ƺ��б�*/
	CMD_SET_TITLE = 353,  		/*!< ���óƺ�*/
	CMD_NET_TOP = 354,  		/*!< �����б�*/

	CMD_QUICK_GUIDE = 355,    /*!< �������*/
	CMD_COUNT_DOWN = 356,    /*!< ����ʱ������*/

	CMD_OFFLINEHANG = 357,  /*!< ���߹һ�*/
	CMD_OFFLINEHANG_OPENNPC = 358 ,/*!< ���߹һ���NPC*/
	CMD_OFFLINEHANG_EXTRACT = 359 ,/*!< ���߹һ���ȡ����*/

	CMD_ONLINEHANG_UI = 360,     /*!< �����߹һ�UI*/
	CMD_ONLINEHANG = 361,        /*!< (��ʼ\ȡ��)���߹һ�*/

	CMD_FUNC_CHANGE = 362,        /*!< Npc�ı�����*/
	CMD_ACTIVATION = 363,				/*!< ������*/

	CMD_RECHARGE = 364,					/*!< ��ֵ*/
	CMD_RECHARGE_LIST = 365,		/*!< ��ֵ�б�*/
	CONST_CMD_MAX = 366,
};

#define CMD_MAKER(a) CmdMaker::CmdFactory(a) 
#define CMD_CALLBACK(a, b, c) CmdMaker::setNetCallback(a, b, callfuncO_selector(c)); 
#define CMD_CLEAR_CALLBACK() CmdMaker::clearNetworkCallBack() 
#define CMD_REMOVE_CALLBACK(a) CmdMaker::removeNetworkCallBack(a) 
 
class CmdMaker 
{ 
	public: 
		static CCObject**	  listenerList   ; 
		static SEL_CallFuncO* selectorList   ; 
		static void			  setNetCallback(INT_TYPE cmdid , CCObject* listen, SEL_CallFuncO callfun) ; 
		static void			  clearNetworkCallBack(); 
		static void			  removeNetworkCallBack(INT_TYPE cmdid); 
		static BaseUpCMD*     CmdFactory (INT_TYPE cmdid); 
		static BaseDownCMD*   getCallbackCMD (INT_TYPE cmdid); 
		static void			  NetworkCallBack (BaseDownCMD* downCMD) ; 
		 
}; 
 
#endif // __CmdMaker_H__ 
