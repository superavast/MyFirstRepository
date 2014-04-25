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
 
// static const int CMD_User_GetOneServerState                        =              1; // 得到首服状态 
// static const int CMD_User_Register                                 =              2; // 注册 
// static const int CMD_User_LoginGame                                =              3; // 登陆 
// static const int CMD_User_SelectServer                             =              4; // 选择服务器 
// static const int CMD_User_IsRole                                   =              5; // 角色是否存在 
// static const int CMD_User_CreateRole                               =              6; // 创建主角 
// static const int CMD_User_IsOnePartner                             =              7; // 是否有一个伙伴 
// static const int CMD_User_GetOnePartner                            =              8; // 获得一个伙伴列表 
// static const int CMD_User_SelectOnePartner                         =              9; // 选择一个伙伴 
// static const int CMD_User_GetPlayerBasic                           =             10; // 获得玩家基本信息 
// static const int CMD_User_GetPlayerItem                            =             11; // 获得道具 
// static const int CMD_User_GetPlayerMission                         =             12; // 获得玩家任务 
// static const int CMD_User_GetPlayerCity                            =             13; // 获得主城信息 
// static const int CMD_Perfect_GetPerfect                            =             14; // 获得统御 
// static const int CMD_Partner_GetHouseInfo                          =             15; // 获得酒馆信息 
// static const int CMD_Partner_RecruitPartner                        =             16; // 招募伙伴 
// static const int CMD_Partner_RecruitOK                             =             17; // 招募确认 
// static const int CMD_Partner_DelPartner                            =             18; // 分解伙伴 
// static const int CMD_Partner_GetDelSoul                            =             19; // 获得分解魂数 
// static const int CMD_Partner_SNYCTime                              =             20; // 同步招募时间 
// static const int CMD_Rep_GetMap                                    =             21; // 获得大地图信息 
// static const int CMD_Rep_GetRepetition                             =             22; // 获得副本信息 
// static const int CMD_Rep_BuyCount                                  =             23; // 买副本层次数 
// static const int CMD_Rep_IntoRepetition                            =             24; // 进入副本层 
// static const int CMD_Battle_LayoutBattle                           =             25; // 布阵 
// static const int CMD_Rep_GetFightResult                            =             26; // 得到战斗结果 
// static const int CMD_Star_GetLookStar                              =             27; // 得到观星台 
// static const int CMD_Star_Look                                     =             28; // 观星 
// static const int CMD_Star_LookRmb                                  =             29; // 元宝观星 
// static const int CMD_Star_LookPick                                 =             30; // 拾取 
// static const int CMD_Star_LookOnePick                              =             31; // 一键拾取 
// static const int CMD_Star_LookFuse                                 =             32; // 观星融合 
// static const int CMD_Star_OneFuse                                  =             33; // 一键融合 
// static const int CMD_Star_GetSoldierStar                           =             34; // 获得兵种星魂 
// static const int CMD_Star_Lock                                     =             35; // 锁定解锁 
// static const int CMD_Star_Fuse                                     =             36; // 融合 
// static const int CMD_Star_StarWear                                 =             37; // 穿星魂 
// static const int CMD_Star_StarOff                                  =             38; // 脱星魂 
// static const int CMD_Star_StarMove                                 =             39; // 移动星魂 
// static const int CMD_Star_GetExchangeList                          =             40; // 得到兑换列表 
// static const int CMD_Star_Exchange                                 =             41; // 兑换星魂 
// static const int CMD_Role_GetRole                                  =             42; // 获得角色 
// static const int CMD_Role_FitSkill                                 =             43; // 角色装备技能 
// static const int CMD_Role_GetSkillList                             =             44; // 得到角色技能列表 
// static const int CMD_Role_SelectSkill                              =             45; // 选择角色技能 
// static const int CMD_Role_GetRepairCost                            =             46; // 获得修为消耗 
// static const int CMD_Equip_GetEquip                                =             47; // 获得装备 
// static const int CMD_Equip_Up                                      =             48; // 升级装备 
// static const int CMD_Equip_RmbUp                                   =             49; // 元宝升级装备 
// static const int CMD_Mission_Accept                                =             50; // 接任务 
// static const int CMD_Mission_Finish                                =             51; // 交任务 
// static const int CMD_UpRank_GetUpRank                              =             52; // 获得升星 
// static const int CMD_UpRank_UpRank                                 =             53; // 升星 
// static const int CMD_Barrack_GetBarrack                            =             54; // 获得兵营 
// static const int CMD_Barrack_Refurbish                             =             55; // 兵营刷新 
// static const int CMD_Barrack_GetAdd                                =             56; // 得到兵营属性加成 
// static const int CMD_Barrack_Drill                                 =             57; // 训练 
// static const int CMD_Barrack_SYNCTime                              =             58; // 同步兵营 
// static const int CMD_User_OpenFunction                             =             59; // 开启功能 
// static const int CMD_SEquip_GetSEquip                              =             60; // 获得神器 
// static const int CMD_SEquip_SEquipUp                               =             61; // 升级神器 
// static const int CMD_HideEquip_GetLayer                            =             62; // 得到藏兵阁的层 
// static const int CMD_HideEquip_IntoFight                           =             63; // 藏兵阁进入副本 
// static const int CMD_HideEquip_FightResult                         =             64; // 藏兵阁战斗结果 
// static const int CMD_HideEquip_Sweep                               =             65; // 藏兵阁扫荡 
// static const int CMD_ShootArrow_GetShootArrow                      =             66; // 得到射箭 
// static const int CMD_ShootArrow_Arrow                              =             67; // 射箭 
// static const int CMD_ShootArrow_GodArrow                           =             68; // 神射 
// static const int CMD_Script_ScriptOver                             =             69; // 脚本完成 
// static const int CMD_Arena_GetArena                                =             70; // 得到比武场 
// static const int CMD_Arena_IntoArenaLei                            =             71; // 进入擂台 
// static const int CMD_Arena_IntoArena                               =             72; // 进入比武 
// static const int CMD_Arena_FightResultLei                          =             73; // 得到擂台结果 
// static const int CMD_Arena_FightResult                             =             74; // 得到比武结果 
// static const int CMD_Pack_Arrange                                  =             75; // 背包整理 
// static const int CMD_SEquip_GetSeize                               =             76; // 获得神器抢夺 
// static const int CMD_SEquip_IntoSeize                              =             77; // 进入神器抢夺 
// static const int CMD_SEquip_FightResult                            =             78; // 神器抢夺结果 
// static const int CMD_Arena_RefArena                                =             79; // 刷新比武场 
// static const int CMD_Arena_SNYCTime                                =             80; // 比武场同步时间 
// static const int CMD_Arena_BuyFightNum                             =             81; // 买比武次数 
// static const int CMD_Arena_BuyRefNum                               =             82; // 买刷新次数 
// static const int CMD_SkyBook_GetSkyBook                            =             83; // 获得天书院 
// static const int CMD_SkyBook_RefSkyBook                            =             84; // 刷新天书院 
// static const int CMD_SkyBook_RmbRefSkyBook                         =             85; // 元宝刷新天书院 
// static const int CMD_SkyBook_IntiFight                             =             86; // 进入战斗 
// static const int CMD_SkyBook_FightResult                           =             87; // 战斗结果 
// static const int CMD_Active_GetActive                              =             88; // 获得活跃度 
// static const int CMD_Active_GetGift                                =             89; // 领奖 
// static const int CMD_Pack_GetMoney                                 =             90; // 取得道具价值 
// static const int CMD_Pack_SellItem                                 =             91; // 卖出道具 
// static const int CMD_Role_SkillUp                                  =             92; // 角色技能升级 
// static const int CMD_Pack_GetOpenMoney                             =             93; // 得到开格元宝 
// static const int CMD_Pack_OpenPack                                 =             94; // 开启格 
// static const int CMD_Pack_UseGift                                  =             95; // 使用礼包 
// static const int CMD_Mission_UpData                                =             96; // 任务更新 
// static const int CMD_User_Site                                     =             97; // 位置 
// static const int CMD_User_AddExp                                   =             98; // 当前状态 
// static const int CMD_Vip_GetVip                                    =             99; // 获得vip 
// static const int CMD_Vip_VipLevel                                  =            100; // vip等级 
// static const int CMD_User_AddEnergy                                =            101; // 体力 
// static const int CMD_User_GetEnergyRmb                             =            102; // 得到体力rmb 
// static const int CMD_User_BuyEnergy                                =            103; // 得到体力rmb 
// static const int CMD_Temp_AddMoney                                 =            104; // 加钱 
// static const int CMD_Temp_AddRmb                                   =            105; // 加rmb 
// static const int CMD_OnLine_GetAward                               =            106; // 在线领奖 
// static const int CMD_OnLine_SYNC                                   =            107; // 在线同步 
// static const int CMD_User_GetFunction                              =            108; // 得到功能 
// static const int CMD_User_GetNoGetItem                             =            109; // 领取未领道具 
// static const int CMD_User_GetRmb                                   =            110; // 领元宝 
// static const int CMD_Equip_GetItemLayer                            =            111; // 获得道具在层 
// static const int CMD_Top_GetTop                                    =            112; // 得到排行榜 
// static const int CMD_Chat_GetChat                                  =            113; // 得到聊天内容 
// static const int CMD_Chat_SendSay                                  =            114; // 发送聊天 
// static const int CMD_Friend_GetFriend                              =            115; // 得到好友列表 
// static const int CMD_Friend_GetBlack                               =            116; // 得到黑名单列表 
// static const int CMD_Friend_AddFriend                              =            117; // 加到好友 
// static const int CMD_Friend_AddBlack                               =            118; // 加到黑名单 
// static const int CMD_Friend_Del                                    =            119; // 删除 
// static const int CMD_Friend_AddFriendName                          =            120; // 加到好友名字 
// static const int CMD_BattleOne_Save                                =            121; // 保存阵型 
// static const int CMD_BattleOne_Get                                 =            122; // 得到阵型 
// static const int CMD_BattleOne_Load                                =            123; // 自动上阵 
// static const int CMD_Title_GetList                                 =            124; // 得到称号列表 
// static const int CMD_Title_Show                                    =            125; // 称号显示 
// static const int CMD_Title_GetReward                               =            126; // 称号领奖 
// static const int CMD_Sweep_GetRepetition                           =            127; // 获得扫荡副本 
// static const int CMD_Sweep_Start                                   =            128; // 开始扫荡 
// static const int CMD_Sweep_GetStart                                =            129; // 得到开始扫荡 
// static const int CMD_Sweep_SNYCTime                                =            130; // 同步扫荡时间 
// static const int CMD_Sweep_GetAward                                =            131; // 获得扫荡奖励消息 
// static const int CMD_Sweep_GetCostRmb                              =            132; // 得到rmb消耗 
// static const int CMD_Sweep_RmbOver                                 =            133; // 立即完成 
// static const int CMD_User_Exit                                     =            134; // 退出 
// static const int CONST_CMD_MAX                                     =            135; 
//  
enum COMMAND_TYPE
{
	GET_IMAGE = 1,				/*!< 得到单个PNG, 参数： png id */
	GET_ANIMATION = 2,		/*!< 得到单个动画， 参数：动画 id */
	GET_TERRAIN = 3,      /*!< 得到单个地图，参数:地图 id */

	CREATE_ROOT	= 16, /*!< 管理员 */
	ROOT_ENTER = 17, /*!< root 进入游戏 */

	NET_LEAVE = 129, /*!< 网络断开 */
	NET_ENTER = 130,	/*!< 网络连接 */	
	NET_HUNGUP = 131, /*!< 网络挂了*/
	NET_FLOODED = 132,/*!< 网络泛滥*/
	NET_FULL = 133,		/*!< 网络拥挤 */
	STOP_SERVER = 134, 	/*!< 停止服务 */

	CMD_LOGIN = 135,  	/*!< 登录 */

	CREATE_ROLE	= 136,   /*<! 新建角色 */
	BATTLE = 137,      		/*<! 战斗 */
	ENTER_WORLD =   138, /*<! 进入游戏  */
	ROLE_INFO = 139, /*!< 得到角色信息 */
	LOAD_OTHER = 140,/*<! 进入游戏后load其他属性  */
	GET_ROLES = 141, /*!< 得到角色列表 */
	NPC_ON_SCREEN = 142, /*!< npc 同屏 */
	PLAYER_ON_SCREEN = 143,/*!< 玩家同屏 */

	XCHANGE_SCENE = 144, /*!< 切换场景 */
	WALK = 145, 						/*!<行走 */
	MODIFY_POSITION = 146, /*!<修正位置*/
	QUIT_GAME = 147,  /*!<退出游戏 */
	LEARN_SKILL = 148,/*!<学习技能 */
	ADD_SKILL_PLACE = 149,/*!<增加心法技能位*/
	UNLEARN_SKILL = 150, /*!<遗忘技能 */
	LEARN_MERIDIAN = 151, /*!<学习经脉 */
	CLEAN_MERIDIAN = 152, /*!<洗点 */
	CMD_NPC = 153,/*!< npc 命令 */
	CMD_QUEST = 154, /*!< 任务命令*/	
	I_EXIT_GAME = 155, /*!< 告诉其他玩家，我离线了*/
	ADD_EXP= 156, /*!< 增加经验 */
	ADD_MONEY = 157, /*!< 增加钱 */
	OPEN_BAG = 158, /*!< 打开背包 */
	ADD_ITEM = 159, /*!< 拾取物品 */
	DELETE_ITEM = 160, /*!< 丢弃物品 */
	CHECK_ITEM = 161, /*!< 点击物品 */
	SORT_ITEM = 162, /*!< 排序物品 */
	USE_ITEM = 163, /*!< 使用物品 */

	OPEN_EQUIP = 164,/*!< 打开装备栏 */
	UNWEAR_EQUIP = 165,/*!< 卸下装备 */
	USE_EQUIP = 166,/*!< 使用装备 */
	ADD_MIT = 167,/*!< 增加修为值 */
	CHECK_EQUIP = 168,/*!< 查看装备 */
	CHECK_DESC = 169,/*!< 查看描述 */
	HEART_BEAT = 170,/*!< 心跳包 */
	DIFF_EQUIP = 171,/*!< 对比装备 */

	FIND_PATH = 172,/*!< 寻路 */
	CMD_TIPS = 173, /*!< 提示 */

	TEAM_JOIN = 174, /*!< 加入队伍 */
	TEAM_ANSWER = 175, /*!< 队伍回应 */
	TEAM_INFO = 176,	/*!< 同屏队伍信息 */

	OPEN_KUNGFU_UI = 177,/*!<  打开心法ui */
	CMD_SHOUT = 178, /*!< 聊天 */

	VIEW_PLAYER_INFO = 179, /*!< 观察玩家 */
	CREATE_TONG = 180, /*!< 新建团帮派 */	
	APPLICATION_TONG = 181, /*!< 申请加入帮派 */
	TONG_LIST		= 182, /*!< 帮派列表 */

	OPEN_PET  = 183,  /*!< 打开宠物装备 */
	INVITE_TONG = 185, /*!< 邀请加入队伍 */
	BUFF_OPT = 184,/*!< 锁定玩家发buff列表 */
	DELETE_PET = 186,/*!< 卸下宠物 */

	QUEST_LIST = 187, /*!< 玩家任务列表 */
	DELETE_BUFF = 188,/*!< 卸载BUFF */

	TEAM_LEAVE = 189,  /*!< 离开队伍 */
	TEAM_DISMISS = 190, /*!< 解散队伍 */
	TEAM_CHANGE_LEADER = 191, /*!< 改变队伍 */

	CMD_FUNC_COMPOSE = 192, /*!< 合成物品 */
	CMD_FUNC_DECOMPOSE = 193, /*!< 分解物品 */
	CMD_FUNC_STRENGTH = 194, /*!< 强化物品 */

	CMD_FUNC_PETCOMPOSE = 195,/*!< 宠物合成 */
	QUEST_INFO = 196, /*!< 任务详情 */
	TONG_DISMISS = 197, /*!< 解散帮派 */

	MAIL_HINT = 198,/*!< 邮件提示 */
	MAIL_CHECKUSER = 199, /*!< 判断玩家是否存在 */
	MAIL_POST = 200,  /*!< 发送邮件 */
	MAIL_OPEARTION = 201,/*!< 邮件操作 */

	TONG_CHANGE_POSITION = 202, /*!< 改变帮派职位 */

	TONG_LEAVE = 204, /*!< 离开帮派 */
	PET_FEED = 205,/*!< 宠物喂养 */

	CMD_FUNC_HOLE = 206, /*!< 物品打孔 */
	CMD_FUNC_INLAY = 207, /*!< 物品镶嵌 */

	SELECT_PETSTRENGTH_ITEM = 208, /*!< 选择宠物强化物品 */
	CHECK_PET = 209,/*!< 查看宠物 */

	USE_PET = 210,/*!< 装备宠物 */
	TONG_MEMBER_LIST = 211, /*!< 帮派成员列表 */

	NPC_INFO = 212, /*!< npc的详细信息 */
	OTHER_PLAYER_INFO = 213, /*!< 其他player的详细信息 */

	SELECT_PETCOMPOSE_ITEM = 214, /*!< 选择宠物合成物品*/
	SPLIT_ITEM = 215,/*!< 分解物品 */
	MOVE_ITEM = 216,/*!< 移动物品 */

	CMD_FUNC_STORE = 217, /*!< 买卖 */
	OPEN_NPC_STORE = 218,/*!< 打开NPC商店 */

	CMD_FUNC_COMPOSE_MONEY = 219,/*!< 查询合成物品金钱 */

	ADD_FRIEND = 220, /*!< 添加好友 */
	GET_FRIEND_LIST = 221,  /*!< 获得好友列表 */
	DEL_FRIEND = 222,  /*!< 删除好友 */

	CMD_FUNC_DECOMPOSE_MONEY = 223,	/*!< 查询分解物品金钱 */
	CMD_FUNC_HOLE_MONEY = 224,		/*!< 查询物品打孔金钱 */
	CMD_FUNC_INLAY_MONEY = 225,		/*!< 查询物品镶嵌金钱*/

	CMD_DISCOVERY_COUNTRY = 229, /*!< 发现新的区域 */

	CMD_FUNC_STRENGTH_MONEY = 230, /*!< 查询物品强化金钱 */
	CMD_FUNC_STRENGTH_RATE = 231, /*!< 查询物品强化几率 */

	CHECK_STORE_ITEM = 232,/*!< 查看NPC商店物品*/
	CHECK_STORE_DESC = 233,/*!< 查看NPC商店物品描述*/

	ENTER_SCENE = 234, /*!< 进入场景 */
	OPEN_DEPOT = 235,/*!< 打开仓库 */
	CMD_FUNC_DEPOT = 236,/*!< 仓库存储 */

	MAIL_MONEY = 237,/*!< 查询邮费 */
	CHECK_MONEY = 238,/*!<查询金钱 */

	TRADE_JOIN = 239,/*!<交易加入*/
	TRADE_ANSWER = 240,/*!<交易应答 */
	SYNC_TRADE_ITEM = 241,/*!<同步交易物品信息 */
	TRADE_CANCEL = 242,/*!<取消交易 */
	TRADE = 243,/*!<交易功能 */

	CMD_FUNC_TONG_TRANS = 244, /*!<帮派传送 */

	CMD_GET_ROLES = 245, /*!<得到角色信息 */
	LOCK_TRADE = 246,/*!<锁定交易 */

	TONG_DESCRIPT = 247, /*!<帮派描述 */
	TONG_FIRE_MEMBER = 248, /*!<开除帮派 */

	I_DEAD = 249,/*!<死亡 */
	OPEN_ATTR_POINT = 250,/*!<打开加点界面 */
	ADD_ATTR_POINT = 251,/*!<加点*/

	CMD_FUNC_REPAIR = 252,/*!<修理*/
	GET_REPAIR_FEE = 253,/*!<得到修理费*/

	PET_LOCK_SKILL = 254,/*!<锁定解锁宠物技能*/
	PET_BIND = 255,		/*!<绑定解绑宠物*/

	OPEN_MERIDIAN = 256,/*!<打开经脉界面*/
	GET_MERIDIAN_DESC = 257,/*!<得到经脉描述*/

	CLEAN_ATTR_POINT = 258,/*!<洗人身上点*/
	CHANGE_STATE = 259,/*!<玩家改变状态*/

	CMD_FUNC_HOLE_INFO = 260, /*!< 查询物品打孔信息 */

	CMD_FUNC_DISMANTLE = 261, /*!< 拆卸宝石 */
	GET_SERIES_INFO = 262, /*!< 得到冰火毒系列信息 */


	CMD_FUNC_PET_COMPOSE_MONEY = 263, /*!< 查询宠物合成所需金钱 */

	CMD_FUNC_TESTING = 600, /*!< 底层测试 */   // 这是什么指令???	
	CMD_PK = 264, /*!< 开启关闭pk状态 */
	CHECK_ATTRIBUTE = 265, /*!< 查看人物属性 */

	PET_DEFEND = 266,	/*!< 宠物守护 */
	CMD_SOCIAL = 267,/*!< 打开社交界面 */

	SYNC_HEALTH = 268,/*!< 同步气血 */
	SYNC_MANA = 269,/*!< 同步精气 */
	SYNC_PK = 270,/*!< 同步pk值 */

	CMD_BE_ADD_FRIEND = 271, /*!< 被别人添加好友 */
	OPT_ON_SCREEN = 272,/*!< 同屏操作(请求/取消)*/

	CMD_SET_QUICK = 273, /*!< 设置快捷栏 */

	TEAM_ITEM = 274, 	/*!< 等待队伍分配的物品 */
	TEAM_ROLL = 275, 	/*!< ROLL点 */

	APPLY_TONG_ARENA = 276, /*!< 申请加入帮派战场*/
	SEND_TONG_ARENA = 277, /*!< 传送到帮派战场*/
	CMD_FUNC_SEND = 278, /*!< 通用传送*/
	GET_APPLY_TONG_LIST = 279, /*!< 得到申请帮战列表*/
	GET_SEND_POINT = 280, /*!< 得到所有传送点*/

	TONG_CHANGE_DESCRIPT  = 281, /*!< 修改帮派公告*/
	TONG_NPC_UPGRADE = 282,		/*!< 修改建筑NPC升级*/	
	TONG_NPC_INFO = 283,		/*!< 帮派NPC建筑等级和升级金钱*/

	CHECK_SKILL = 284,  /*!< 查看技能*/
	DELETE_QUEST = 285, /*!< 放弃任务*/

	PET_CHANGE_ALIAS = 286, /*!< 宠物改名*/
	CHECK_NEAR_PLAYERS = 287,/*!< 查看附近玩家*/
	OTHER_PLAYER_DETAIL = 288,/*!< 查看其他玩家详细信息*/
	CMD_CHANGE_AVATAR = 289,/*!< 变身*/

	PET_SELECT_POTENTIAL_ITEM = 290, /*!< 选择激发宠物潜能的物品*/
	PET_POTENTIAL = 291,			/*!< 宠物激发潜能*/

	PET_EQUIP_USE = 292,			/*!< 宠物在装备栏中使用物品*/
	QUEST_FIND_PATH = 293,    /*!< 完成任务开始寻路*/
	QUIT_CONTEST = 294,       /*!< 退出切磋*/
	EQUIP_BIND = 295,					/*!< 绑定*/
	DELETE_NPC = 296,         /*!< 删除非同屏圈npc*/
	SEND_ARENA_INTEGRAL = 297,/*!< 发送战场积分*/
	INSTALL_BUFF = 298,       /*!< 安装buff*/
	PLAYER_ON_SCREEN_AVATAR = 299, /*!< 同屏玩家avatar*/
	PLAYER_ON_SCREEN_WALK = 300,   /*!< 同屏玩家走路*/
	PLAYER_ON_SCREEN_TONG = 301,   /*!< 同屏玩家帮派*/
	DELETE_PLAYER = 302,           /*!< 删除非同屏圈player*/ 
	QUEST_SIMPLE_INFO = 303,       /*!< 任务简单介绍*/
	PLAYER_ON_SCREEN_BATTLE = 304, /*!< 同屏玩家战斗*/

	CMD_TIPS_CODE = 305,       /*!< 提示状态码命令*/ 

	PUT_ITEM = 306,				 /*!< 添加物品*/ 

	CMD_QUESTION_INFO = 307,				/*!< 答题信息*/ 
	CMD_QUESTION_RUN = 308,				 	/*!< 进行答题*/ 
	CMD_QUESTION_END = 309,				 	/*!< 结束答题*/ 

	CMD_GAME_TIME = 310,				 	/*!< 游戏时间(打卡)*/

	CMD_CLIENT_READY = 313,				 	/*!< 客户端就绪*/
	CMD_OPEN_STORE = 311,				 	/*!< 打开商店*/
	CMD_BUY_GOODS = 312,	/*!< 购买元宝物品*/
	CMD_INGOT_RECORD = 314,/*!< 购买记录/收藏*/

	GM_SHUT_DOWN = 316,						/*!< GM踢人*/
	GM_SHUT_UP_LIST = 317,					/*!< GM禁言名单*/
	GM_SHUT_UP = 318,						/*!< GM禁言*/
	GM_QUIT = 319,							/*!< GM退出游戏*/
	GM_ENTER_WORLD = 320,					/*!< GM进入游戏*/
	GM_PLAYER_NUM = 321,					/*!< GM游戏人数*/
	GM_TALK = 322,							/*!< GM聊天*/ 

	CMD_VERIFICATION_CODE = 315, /*!< 认证验证码*/
	CMD_SET_FLOW = 323,         /*!< 流量设置*/
	CMD_GM_ROLE_FIND = 324, /*!< 角色查找*/
	CMD_GM_ROLE_MANAGEME = 325, /*!< 角色查询*/
	CMD_GM_ROLE_DETAILS = 326, /*!< 角色详细查询*/
	CMD_GM_PET_DETAILS = 327, /*!< 宠物详细查询*/
	CMD_GM_ROLE_ARTICLES = 328, /*!< 角色物品查询*/
	CMD_GM_ROLE_PETS = 329, /*!< 宠物查询*/

	CMD_CONTINUE_EFFECT = 330,  /*!< 持续效果*/
	CMD_CLEAN_EFFECT = 331,  /*!< 清除所有效果*/
	CMD_CHECK_EFFECT = 332,  /*!< 查看已有效果*/
	CMD_SET_VERSION = 333,   /*!< 设置版本号*/

	CMD_NOTICE = 334, 			/*!< GM打开公告*/
	CMD_NOTICE_LIST = 335, 		/*!< GM公告列表*/
	GM_NOTICE_OPT = 336, 		/*!< GM操作公告*/
	GM_NOTICE_ADD = 337, 		/*!< GM添加公告*/

	CMD_SET_PASS_WORD = 340,	/*!< 修改密码*/

	GM_SET_PLAYER_ATTR = 341, 			/*!< GM修改玩家属性*/
	GM_SET_PET_ATTR = 342, 				/*!< GM修改宠物属性*/
	GM_SET_PLAYER_ITEM = 343, 			/*!< GM增减物品*/
	GM_SET_PET_SKILL = 344, 			/*!< GM增减宠物技能*/
	GM_CHECK_PLAYER = 345, 			/*!< GM检查玩家属性*/
	GM_WATCH = 346, 				/*!< GM追踪*/
	GM_WATCH_LIST = 347, 			/*!< GM追踪列表*/
	GM_FREEZE = 348, 				/*!< GM封号*/

	CMD_BUSINESS_OPEN = 349, 		/*!< 打开摊位*/
	CMD_BUSINESS_OPT = 350,			/*!< 调整摊位里的物品*/
	CMD_BUSINESS_BUY = 351,			/*!< 摊位购买*/

	CMD_TITLE_TOP = 352,  		/*!< 称号列表*/
	CMD_SET_TITLE = 353,  		/*!< 设置称号*/
	CMD_NET_TOP = 354,  		/*!< 排名列表*/

	CMD_QUICK_GUIDE = 355,    /*!< 快捷引导*/
	CMD_COUNT_DOWN = 356,    /*!< 倒计时给奖励*/

	CMD_OFFLINEHANG = 357,  /*!< 离线挂机*/
	CMD_OFFLINEHANG_OPENNPC = 358 ,/*!< 离线挂机打开NPC*/
	CMD_OFFLINEHANG_EXTRACT = 359 ,/*!< 离线挂机提取经验*/

	CMD_ONLINEHANG_UI = 360,     /*!< 打开在线挂机UI*/
	CMD_ONLINEHANG = 361,        /*!< (开始\取消)在线挂机*/

	CMD_FUNC_CHANGE = 362,        /*!< Npc改变形象*/
	CMD_ACTIVATION = 363,				/*!< 激活码*/

	CMD_RECHARGE = 364,					/*!< 充值*/
	CMD_RECHARGE_LIST = 365,		/*!< 充值列表*/
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
