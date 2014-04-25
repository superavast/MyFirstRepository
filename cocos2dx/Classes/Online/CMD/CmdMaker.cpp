#include "CmdMaker.h" 
 
CCObject**	  CmdMaker::listenerList	= NULL; 
SEL_CallFuncO* CmdMaker::selectorList   = NULL; 
 
void CmdMaker::setNetCallback(INT_TYPE cmdid , CCObject* listen, SEL_CallFuncO callfun) 
{ 
	if (listenerList == NULL) 
	{ 
		INIT_ARRAY( CCObject* , listenerList	, CONST_CMD_MAX ); 
		INIT_ARRAY( SEL_CallFuncO , selectorList , CONST_CMD_MAX ); 
		for (int i = 0;i < CONST_CMD_MAX;i ++) 
		{ 
			listenerList[i] = NULL; 
			selectorList[i] = NULL; 
		} 
	} 
	 
	CCAssert( cmdid >=0 && cmdid < CONST_CMD_MAX, "setNetCallback cmd id error!" ) ; 
	 
	listenerList[cmdid] = listen; 
	selectorList[cmdid] = callfun; 
} 
 
void CmdMaker::clearNetworkCallBack() 
{ 
	if (listenerList == NULL) return; 
	for (int i = 0;i < CONST_CMD_MAX;i++) 
	{ 
		listenerList[i] = NULL; 
		selectorList[i] = NULL; 
	} 
} 
 
void CmdMaker::removeNetworkCallBack(INT_TYPE cmdids) 
{ 
	if (listenerList == NULL) return; 
	listenerList[cmdids] = NULL; 
	selectorList[cmdids] = NULL; 
} 
 
void CmdMaker::NetworkCallBack (BaseDownCMD* downCMD) 
{ 
	if (listenerList == NULL) return; 
	if (listenerList[downCMD->CMDID] && selectorList[downCMD->CMDID]) 
	{ 
		(listenerList[downCMD->CMDID]->*selectorList[downCMD->CMDID])(downCMD); 
	} 
} 
 
BaseUpCMD* CmdMaker::CmdFactory (INT_TYPE cmdid) 
{ 
	BaseUpCMD* ret = NULL; 
	 
	switch (cmdid) 
 	{ 
	case CMD_LOGIN:
			ret = CMD_User_LoginGame_up::create();
			break;
// 		case CMD_User_GetOneServerState: 
// 			ret = CMD_User_GetOneServerState_up::create(); 
// 			break; 
// 		case CMD_User_Register: 
// 			ret = CMD_User_Register_up::create(); 
// 			break; 
// 		case CMD_User_LoginGame: 
// 			ret = CMD_User_LoginGame_up::create(); 
// 			break; 
// 		case CMD_User_SelectServer: 
// 			ret = CMD_User_SelectServer_up::create(); 
// 			break; 
// 		case CMD_User_IsRole: 
// 			ret = CMD_User_IsRole_up::create(); 
// 			break; 
// 		case CMD_User_CreateRole: 
// 			ret = CMD_User_CreateRole_up::create(); 
// 			break; 
// 		case CMD_User_IsOnePartner: 
// 			ret = CMD_User_IsOnePartner_up::create(); 
// 			break; 
// 		case CMD_User_GetOnePartner: 
// 			ret = CMD_User_GetOnePartner_up::create(); 
// 			break; 
// 		case CMD_User_SelectOnePartner: 
// 			ret = CMD_User_SelectOnePartner_up::create(); 
// 			break; 
// 		case CMD_User_GetPlayerBasic: 
// 			ret = CMD_User_GetPlayerBasic_up::create(); 
// 			break; 
// 		case CMD_User_GetPlayerItem: 
// 			ret = CMD_User_GetPlayerItem_up::create(); 
// 			break; 
// 		case CMD_User_GetPlayerMission: 
// 			ret = CMD_User_GetPlayerMission_up::create(); 
// 			break; 
// 		case CMD_User_GetPlayerCity: 
// 			ret = CMD_User_GetPlayerCity_up::create(); 
// 			break; 
// 		case CMD_Perfect_GetPerfect: 
// 			ret = CMD_Perfect_GetPerfect_up::create(); 
// 			break; 
// 		case CMD_Partner_GetHouseInfo: 
// 			ret = CMD_Partner_GetHouseInfo_up::create(); 
// 			break; 
// 		case CMD_Partner_RecruitPartner: 
// 			ret = CMD_Partner_RecruitPartner_up::create(); 
// 			break; 
// 		case CMD_Partner_RecruitOK: 
// 			ret = CMD_Partner_RecruitOK_up::create(); 
// 			break; 
// 		case CMD_Partner_DelPartner: 
// 			ret = CMD_Partner_DelPartner_up::create(); 
// 			break; 
// 		case CMD_Partner_GetDelSoul: 
// 			ret = CMD_Partner_GetDelSoul_up::create(); 
// 			break; 
// 		case CMD_Partner_SNYCTime: 
// 			ret = CMD_Partner_SNYCTime_up::create(); 
// 			break; 
// 		case CMD_Rep_GetMap: 
// 			ret = CMD_Rep_GetMap_up::create(); 
// 			break; 
// 		case CMD_Rep_GetRepetition: 
// 			ret = CMD_Rep_GetRepetition_up::create(); 
// 			break; 
// 		case CMD_Rep_BuyCount: 
// 			ret = CMD_Rep_BuyCount_up::create(); 
// 			break; 
// 		case CMD_Rep_IntoRepetition: 
// 			ret = CMD_Rep_IntoRepetition_up::create(); 
// 			break; 
// 		case CMD_Battle_LayoutBattle: 
// 			ret = CMD_Battle_LayoutBattle_up::create(); 
// 			break; 
// 		case CMD_Rep_GetFightResult: 
// 			ret = CMD_Rep_GetFightResult_up::create(); 
// 			break; 
// 		case CMD_Star_GetLookStar: 
// 			ret = CMD_Star_GetLookStar_up::create(); 
// 			break; 
// 		case CMD_Star_Look: 
// 			ret = CMD_Star_Look_up::create(); 
// 			break; 
// 		case CMD_Star_LookRmb: 
// 			ret = CMD_Star_LookRmb_up::create(); 
// 			break; 
// 		case CMD_Star_LookPick: 
// 			ret = CMD_Star_LookPick_up::create(); 
// 			break; 
// 		case CMD_Star_LookOnePick: 
// 			ret = CMD_Star_LookOnePick_up::create(); 
// 			break; 
// 		case CMD_Star_LookFuse: 
// 			ret = CMD_Star_LookFuse_up::create(); 
// 			break; 
// 		case CMD_Star_OneFuse: 
// 			ret = CMD_Star_OneFuse_up::create(); 
// 			break; 
// 		case CMD_Star_GetSoldierStar: 
// 			ret = CMD_Star_GetSoldierStar_up::create(); 
// 			break; 
// 		case CMD_Star_Lock: 
// 			ret = CMD_Star_Lock_up::create(); 
// 			break; 
// 		case CMD_Star_Fuse: 
// 			ret = CMD_Star_Fuse_up::create(); 
// 			break; 
// 		case CMD_Star_StarWear: 
// 			ret = CMD_Star_StarWear_up::create(); 
// 			break; 
// 		case CMD_Star_StarOff: 
// 			ret = CMD_Star_StarOff_up::create(); 
// 			break; 
// 		case CMD_Star_StarMove: 
// 			ret = CMD_Star_StarMove_up::create(); 
// 			break; 
// 		case CMD_Star_GetExchangeList: 
// 			ret = CMD_Star_GetExchangeList_up::create(); 
// 			break; 
// 		case CMD_Star_Exchange: 
// 			ret = CMD_Star_Exchange_up::create(); 
// 			break; 
// 		case CMD_Role_GetRole: 
// 			ret = CMD_Role_GetRole_up::create(); 
// 			break; 
// 		case CMD_Role_FitSkill: 
// 			ret = CMD_Role_FitSkill_up::create(); 
// 			break; 
// 		case CMD_Role_GetSkillList: 
// 			ret = CMD_Role_GetSkillList_up::create(); 
// 			break; 
// 		case CMD_Role_SelectSkill: 
// 			ret = CMD_Role_SelectSkill_up::create(); 
// 			break; 
// 		case CMD_Role_GetRepairCost: 
// 			ret = CMD_Role_GetRepairCost_up::create(); 
// 			break; 
// 		case CMD_Equip_GetEquip: 
// 			ret = CMD_Equip_GetEquip_up::create(); 
// 			break; 
// 		case CMD_Equip_Up: 
// 			ret = CMD_Equip_Up_up::create(); 
// 			break; 
// 		case CMD_Equip_RmbUp: 
// 			ret = CMD_Equip_RmbUp_up::create(); 
// 			break; 
// 		case CMD_Mission_Accept: 
// 			ret = CMD_Mission_Accept_up::create(); 
// 			break; 
// 		case CMD_Mission_Finish: 
// 			ret = CMD_Mission_Finish_up::create(); 
// 			break; 
// 		case CMD_UpRank_GetUpRank: 
// 			ret = CMD_UpRank_GetUpRank_up::create(); 
// 			break; 
// 		case CMD_UpRank_UpRank: 
// 			ret = CMD_UpRank_UpRank_up::create(); 
// 			break; 
// 		case CMD_Barrack_GetBarrack: 
// 			ret = CMD_Barrack_GetBarrack_up::create(); 
// 			break; 
// 		case CMD_Barrack_Refurbish: 
// 			ret = CMD_Barrack_Refurbish_up::create(); 
// 			break; 
// 		case CMD_Barrack_GetAdd: 
// 			ret = CMD_Barrack_GetAdd_up::create(); 
// 			break; 
// 		case CMD_Barrack_Drill: 
// 			ret = CMD_Barrack_Drill_up::create(); 
// 			break; 
// 		case CMD_Barrack_SYNCTime: 
// 			ret = CMD_Barrack_SYNCTime_up::create(); 
// 			break; 
// 		case CMD_User_OpenFunction: 
// 			ret = CMD_User_OpenFunction_up::create(); 
// 			break; 
// 		case CMD_SEquip_GetSEquip: 
// 			ret = CMD_SEquip_GetSEquip_up::create(); 
// 			break; 
// 		case CMD_SEquip_SEquipUp: 
// 			ret = CMD_SEquip_SEquipUp_up::create(); 
// 			break; 
// 		case CMD_HideEquip_GetLayer: 
// 			ret = CMD_HideEquip_GetLayer_up::create(); 
// 			break; 
// 		case CMD_HideEquip_IntoFight: 
// 			ret = CMD_HideEquip_IntoFight_up::create(); 
// 			break; 
// 		case CMD_HideEquip_FightResult: 
// 			ret = CMD_HideEquip_FightResult_up::create(); 
// 			break; 
// 		case CMD_HideEquip_Sweep: 
// 			ret = CMD_HideEquip_Sweep_up::create(); 
// 			break; 
// 		case CMD_ShootArrow_GetShootArrow: 
// 			ret = CMD_ShootArrow_GetShootArrow_up::create(); 
// 			break; 
// 		case CMD_ShootArrow_Arrow: 
// 			ret = CMD_ShootArrow_Arrow_up::create(); 
// 			break; 
// 		case CMD_ShootArrow_GodArrow: 
// 			ret = CMD_ShootArrow_GodArrow_up::create(); 
// 			break; 
// 		case CMD_Script_ScriptOver: 
// 			ret = CMD_Script_ScriptOver_up::create(); 
// 			break; 
// 		case CMD_Arena_GetArena: 
// 			ret = CMD_Arena_GetArena_up::create(); 
// 			break; 
// 		case CMD_Arena_IntoArenaLei: 
// 			ret = CMD_Arena_IntoArenaLei_up::create(); 
// 			break; 
// 		case CMD_Arena_IntoArena: 
// 			ret = CMD_Arena_IntoArena_up::create(); 
// 			break; 
// 		case CMD_Arena_FightResultLei: 
// 			ret = CMD_Arena_FightResultLei_up::create(); 
// 			break; 
// 		case CMD_Arena_FightResult: 
// 			ret = CMD_Arena_FightResult_up::create(); 
// 			break; 
// 		case CMD_Pack_Arrange: 
// 			ret = CMD_Pack_Arrange_up::create(); 
// 			break; 
// 		case CMD_SEquip_GetSeize: 
// 			ret = CMD_SEquip_GetSeize_up::create(); 
// 			break; 
// 		case CMD_SEquip_IntoSeize: 
// 			ret = CMD_SEquip_IntoSeize_up::create(); 
// 			break; 
// 		case CMD_SEquip_FightResult: 
// 			ret = CMD_SEquip_FightResult_up::create(); 
// 			break; 
// 		case CMD_Arena_RefArena: 
// 			ret = CMD_Arena_RefArena_up::create(); 
// 			break; 
// 		case CMD_Arena_SNYCTime: 
// 			ret = CMD_Arena_SNYCTime_up::create(); 
// 			break; 
// 		case CMD_Arena_BuyFightNum: 
// 			ret = CMD_Arena_BuyFightNum_up::create(); 
// 			break; 
// 		case CMD_Arena_BuyRefNum: 
// 			ret = CMD_Arena_BuyRefNum_up::create(); 
// 			break; 
// 		case CMD_SkyBook_GetSkyBook: 
// 			ret = CMD_SkyBook_GetSkyBook_up::create(); 
// 			break; 
// 		case CMD_SkyBook_RefSkyBook: 
// 			ret = CMD_SkyBook_RefSkyBook_up::create(); 
// 			break; 
// 		case CMD_SkyBook_RmbRefSkyBook: 
// 			ret = CMD_SkyBook_RmbRefSkyBook_up::create(); 
// 			break; 
// 		case CMD_SkyBook_IntiFight: 
// 			ret = CMD_SkyBook_IntiFight_up::create(); 
// 			break; 
// 		case CMD_SkyBook_FightResult: 
// 			ret = CMD_SkyBook_FightResult_up::create(); 
// 			break; 
// 		case CMD_Active_GetActive: 
// 			ret = CMD_Active_GetActive_up::create(); 
// 			break; 
// 		case CMD_Active_GetGift: 
// 			ret = CMD_Active_GetGift_up::create(); 
// 			break; 
// 		case CMD_Pack_GetMoney: 
// 			ret = CMD_Pack_GetMoney_up::create(); 
// 			break; 
// 		case CMD_Pack_SellItem: 
// 			ret = CMD_Pack_SellItem_up::create(); 
// 			break; 
// 		case CMD_Role_SkillUp: 
// 			ret = CMD_Role_SkillUp_up::create(); 
// 			break; 
// 		case CMD_Pack_GetOpenMoney: 
// 			ret = CMD_Pack_GetOpenMoney_up::create(); 
// 			break; 
// 		case CMD_Pack_OpenPack: 
// 			ret = CMD_Pack_OpenPack_up::create(); 
// 			break; 
// 		case CMD_Pack_UseGift: 
// 			ret = CMD_Pack_UseGift_up::create(); 
// 			break; 
// 		case CMD_Mission_UpData: 
// 			ret = CMD_Mission_UpData_up::create(); 
// 			break; 
// 		case CMD_User_Site: 
// 			ret = CMD_User_Site_up::create(); 
// 			break; 
// 		case CMD_User_AddExp: 
// 			ret = CMD_User_AddExp_up::create(); 
// 			break; 
// 		case CMD_Vip_GetVip: 
// 			ret = CMD_Vip_GetVip_up::create(); 
// 			break; 
// 		case CMD_Vip_VipLevel: 
// 			ret = CMD_Vip_VipLevel_up::create(); 
// 			break; 
// 		case CMD_User_AddEnergy: 
// 			ret = CMD_User_AddEnergy_up::create(); 
// 			break; 
// 		case CMD_User_GetEnergyRmb: 
// 			ret = CMD_User_GetEnergyRmb_up::create(); 
// 			break; 
// 		case CMD_User_BuyEnergy: 
// 			ret = CMD_User_BuyEnergy_up::create(); 
// 			break; 
// 		case CMD_Temp_AddMoney: 
// 			ret = CMD_Temp_AddMoney_up::create(); 
// 			break; 
// 		case CMD_Temp_AddRmb: 
// 			ret = CMD_Temp_AddRmb_up::create(); 
// 			break; 
// 		case CMD_OnLine_GetAward: 
// 			ret = CMD_OnLine_GetAward_up::create(); 
// 			break; 
// 		case CMD_OnLine_SYNC: 
// 			ret = CMD_OnLine_SYNC_up::create(); 
// 			break; 
// 		case CMD_User_GetFunction: 
// 			ret = CMD_User_GetFunction_up::create(); 
// 			break; 
// 		case CMD_User_GetNoGetItem: 
// 			ret = CMD_User_GetNoGetItem_up::create(); 
// 			break; 
// 		case CMD_User_GetRmb: 
// 			ret = CMD_User_GetRmb_up::create(); 
// 			break; 
// 		case CMD_Equip_GetItemLayer: 
// 			ret = CMD_Equip_GetItemLayer_up::create(); 
// 			break; 
// 		case CMD_Top_GetTop: 
// 			ret = CMD_Top_GetTop_up::create(); 
// 			break; 
// 		case CMD_Chat_GetChat: 
// 			ret = CMD_Chat_GetChat_up::create(); 
// 			break; 
// 		case CMD_Chat_SendSay: 
// 			ret = CMD_Chat_SendSay_up::create(); 
// 			break; 
// 		case CMD_Friend_GetFriend: 
// 			ret = CMD_Friend_GetFriend_up::create(); 
// 			break; 
// 		case CMD_Friend_GetBlack: 
// 			ret = CMD_Friend_GetBlack_up::create(); 
// 			break; 
// 		case CMD_Friend_AddFriend: 
// 			ret = CMD_Friend_AddFriend_up::create(); 
// 			break; 
// 		case CMD_Friend_AddBlack: 
// 			ret = CMD_Friend_AddBlack_up::create(); 
// 			break; 
// 		case CMD_Friend_Del: 
// 			ret = CMD_Friend_Del_up::create(); 
// 			break; 
// 		case CMD_Friend_AddFriendName: 
// 			ret = CMD_Friend_AddFriendName_up::create(); 
// 			break; 
// 		case CMD_BattleOne_Save: 
// 			ret = CMD_BattleOne_Save_up::create(); 
// 			break; 
// 		case CMD_BattleOne_Get: 
// 			ret = CMD_BattleOne_Get_up::create(); 
// 			break; 
// 		case CMD_BattleOne_Load: 
// 			ret = CMD_BattleOne_Load_up::create(); 
// 			break; 
// 		case CMD_Title_GetList: 
// 			ret = CMD_Title_GetList_up::create(); 
// 			break; 
// 		case CMD_Title_Show: 
// 			ret = CMD_Title_Show_up::create(); 
// 			break; 
// 		case CMD_Title_GetReward: 
// 			ret = CMD_Title_GetReward_up::create(); 
// 			break; 
// 		case CMD_Sweep_GetRepetition: 
// 			ret = CMD_Sweep_GetRepetition_up::create(); 
// 			break; 
// 		case CMD_Sweep_Start: 
// 			ret = CMD_Sweep_Start_up::create(); 
// 			break; 
// 		case CMD_Sweep_GetStart: 
// 			ret = CMD_Sweep_GetStart_up::create(); 
// 			break; 
// 		case CMD_Sweep_SNYCTime: 
// 			ret = CMD_Sweep_SNYCTime_up::create(); 
// 			break; 
// 		case CMD_Sweep_GetAward: 
// 			ret = CMD_Sweep_GetAward_up::create(); 
// 			break; 
// 		case CMD_Sweep_GetCostRmb: 
// 			ret = CMD_Sweep_GetCostRmb_up::create(); 
// 			break; 
// 		case CMD_Sweep_RmbOver: 
// 			ret = CMD_Sweep_RmbOver_up::create(); 
// 			break; 
// 		case CMD_User_Exit: 
// 			ret = CMD_User_Exit_up::create(); 
// 			break; 
	} 
	 
	CCAssert(ret, "CmdFactory is error!"); 
	return ret; 
} 
 
BaseDownCMD* CmdMaker::getCallbackCMD (INT_TYPE cmdid) 
{ 
	BaseDownCMD* ret = NULL; 
	 
	switch (cmdid) 
	{ 
// 		case CMD_User_GetOneServerState: 
// 			ret = CMD_User_GetOneServerState_down::create(); 
// 			break; 
// 		case CMD_User_Register: 
// 			ret = CMD_User_Register_down::create(); 
// 			break; 
// 		case CMD_User_LoginGame: 
// 			ret = CMD_User_LoginGame_down::create(); 
// 			break; 
// 		case CMD_User_SelectServer: 
// 			ret = CMD_User_SelectServer_down::create(); 
// 			break; 
// 		case CMD_User_IsRole: 
// 			ret = CMD_User_IsRole_down::create(); 
// 			break; 
// 		case CMD_User_CreateRole: 
// 			ret = CMD_User_CreateRole_down::create(); 
// 			break; 
// 		case CMD_User_IsOnePartner: 
// 			ret = CMD_User_IsOnePartner_down::create(); 
// 			break; 
// 		case CMD_User_GetOnePartner: 
// 			ret = CMD_User_GetOnePartner_down::create(); 
// 			break; 
// 		case CMD_User_SelectOnePartner: 
// 			ret = CMD_User_SelectOnePartner_down::create(); 
// 			break; 
// 		case CMD_User_GetPlayerBasic: 
// 			ret = CMD_User_GetPlayerBasic_down::create(); 
// 			break; 
// 		case CMD_User_GetPlayerItem: 
// 			ret = CMD_User_GetPlayerItem_down::create(); 
// 			break; 
// 		case CMD_User_GetPlayerMission: 
// 			ret = CMD_User_GetPlayerMission_down::create(); 
// 			break; 
// 		case CMD_User_GetPlayerCity: 
// 			ret = CMD_User_GetPlayerCity_down::create(); 
// 			break; 
// 		case CMD_Perfect_GetPerfect: 
// 			ret = CMD_Perfect_GetPerfect_down::create(); 
// 			break; 
// 		case CMD_Partner_GetHouseInfo: 
// 			ret = CMD_Partner_GetHouseInfo_down::create(); 
// 			break; 
// 		case CMD_Partner_RecruitPartner: 
// 			ret = CMD_Partner_RecruitPartner_down::create(); 
// 			break; 
// 		case CMD_Partner_RecruitOK: 
// 			ret = CMD_Partner_RecruitOK_down::create(); 
// 			break; 
// 		case CMD_Partner_DelPartner: 
// 			ret = CMD_Partner_DelPartner_down::create(); 
// 			break; 
// 		case CMD_Partner_GetDelSoul: 
// 			ret = CMD_Partner_GetDelSoul_down::create(); 
// 			break; 
// 		case CMD_Partner_SNYCTime: 
// 			ret = CMD_Partner_SNYCTime_down::create(); 
// 			break; 
// 		case CMD_Rep_GetMap: 
// 			ret = CMD_Rep_GetMap_down::create(); 
// 			break; 
// 		case CMD_Rep_GetRepetition: 
// 			ret = CMD_Rep_GetRepetition_down::create(); 
// 			break; 
// 		case CMD_Rep_BuyCount: 
// 			ret = CMD_Rep_BuyCount_down::create(); 
// 			break; 
// 		case CMD_Rep_IntoRepetition: 
// 			ret = CMD_Rep_IntoRepetition_down::create(); 
// 			break; 
// 		case CMD_Battle_LayoutBattle: 
// 			ret = CMD_Battle_LayoutBattle_down::create(); 
// 			break; 
// 		case CMD_Rep_GetFightResult: 
// 			ret = CMD_Rep_GetFightResult_down::create(); 
// 			break; 
// 		case CMD_Star_GetLookStar: 
// 			ret = CMD_Star_GetLookStar_down::create(); 
// 			break; 
// 		case CMD_Star_Look: 
// 			ret = CMD_Star_Look_down::create(); 
// 			break; 
// 		case CMD_Star_LookRmb: 
// 			ret = CMD_Star_LookRmb_down::create(); 
// 			break; 
// 		case CMD_Star_LookPick: 
// 			ret = CMD_Star_LookPick_down::create(); 
// 			break; 
// 		case CMD_Star_LookOnePick: 
// 			ret = CMD_Star_LookOnePick_down::create(); 
// 			break; 
// 		case CMD_Star_LookFuse: 
// 			ret = CMD_Star_LookFuse_down::create(); 
// 			break; 
// 		case CMD_Star_OneFuse: 
// 			ret = CMD_Star_OneFuse_down::create(); 
// 			break; 
// 		case CMD_Star_GetSoldierStar: 
// 			ret = CMD_Star_GetSoldierStar_down::create(); 
// 			break; 
// 		case CMD_Star_Lock: 
// 			ret = CMD_Star_Lock_down::create(); 
// 			break; 
// 		case CMD_Star_Fuse: 
// 			ret = CMD_Star_Fuse_down::create(); 
// 			break; 
// 		case CMD_Star_StarWear: 
// 			ret = CMD_Star_StarWear_down::create(); 
// 			break; 
// 		case CMD_Star_StarOff: 
// 			ret = CMD_Star_StarOff_down::create(); 
// 			break; 
// 		case CMD_Star_StarMove: 
// 			ret = CMD_Star_StarMove_down::create(); 
// 			break; 
// 		case CMD_Star_GetExchangeList: 
// 			ret = CMD_Star_GetExchangeList_down::create(); 
// 			break; 
// 		case CMD_Star_Exchange: 
// 			ret = CMD_Star_Exchange_down::create(); 
// 			break; 
// 		case CMD_Role_GetRole: 
// 			ret = CMD_Role_GetRole_down::create(); 
// 			break; 
// 		case CMD_Role_FitSkill: 
// 			ret = CMD_Role_FitSkill_down::create(); 
// 			break; 
// 		case CMD_Role_GetSkillList: 
// 			ret = CMD_Role_GetSkillList_down::create(); 
// 			break; 
// 		case CMD_Role_SelectSkill: 
// 			ret = CMD_Role_SelectSkill_down::create(); 
// 			break; 
// 		case CMD_Role_GetRepairCost: 
// 			ret = CMD_Role_GetRepairCost_down::create(); 
// 			break; 
// 		case CMD_Equip_GetEquip: 
// 			ret = CMD_Equip_GetEquip_down::create(); 
// 			break; 
// 		case CMD_Equip_Up: 
// 			ret = CMD_Equip_Up_down::create(); 
// 			break; 
// 		case CMD_Equip_RmbUp: 
// 			ret = CMD_Equip_RmbUp_down::create(); 
// 			break; 
// 		case CMD_Mission_Accept: 
// 			ret = CMD_Mission_Accept_down::create(); 
// 			break; 
// 		case CMD_Mission_Finish: 
// 			ret = CMD_Mission_Finish_down::create(); 
// 			break; 
// 		case CMD_UpRank_GetUpRank: 
// 			ret = CMD_UpRank_GetUpRank_down::create(); 
// 			break; 
// 		case CMD_UpRank_UpRank: 
// 			ret = CMD_UpRank_UpRank_down::create(); 
// 			break; 
// 		case CMD_Barrack_GetBarrack: 
// 			ret = CMD_Barrack_GetBarrack_down::create(); 
// 			break; 
// 		case CMD_Barrack_Refurbish: 
// 			ret = CMD_Barrack_Refurbish_down::create(); 
// 			break; 
// 		case CMD_Barrack_GetAdd: 
// 			ret = CMD_Barrack_GetAdd_down::create(); 
// 			break; 
// 		case CMD_Barrack_Drill: 
// 			ret = CMD_Barrack_Drill_down::create(); 
// 			break; 
// 		case CMD_Barrack_SYNCTime: 
// 			ret = CMD_Barrack_SYNCTime_down::create(); 
// 			break; 
// 		case CMD_User_OpenFunction: 
// 			ret = CMD_User_OpenFunction_down::create(); 
// 			break; 
// 		case CMD_SEquip_GetSEquip: 
// 			ret = CMD_SEquip_GetSEquip_down::create(); 
// 			break; 
// 		case CMD_SEquip_SEquipUp: 
// 			ret = CMD_SEquip_SEquipUp_down::create(); 
// 			break; 
// 		case CMD_HideEquip_GetLayer: 
// 			ret = CMD_HideEquip_GetLayer_down::create(); 
// 			break; 
// 		case CMD_HideEquip_IntoFight: 
// 			ret = CMD_HideEquip_IntoFight_down::create(); 
// 			break; 
// 		case CMD_HideEquip_FightResult: 
// 			ret = CMD_HideEquip_FightResult_down::create(); 
// 			break; 
// 		case CMD_HideEquip_Sweep: 
// 			ret = CMD_HideEquip_Sweep_down::create(); 
// 			break; 
// 		case CMD_ShootArrow_GetShootArrow: 
// 			ret = CMD_ShootArrow_GetShootArrow_down::create(); 
// 			break; 
// 		case CMD_ShootArrow_Arrow: 
// 			ret = CMD_ShootArrow_Arrow_down::create(); 
// 			break; 
// 		case CMD_ShootArrow_GodArrow: 
// 			ret = CMD_ShootArrow_GodArrow_down::create(); 
// 			break; 
// 		case CMD_Script_ScriptOver: 
// 			ret = CMD_Script_ScriptOver_down::create(); 
// 			break; 
// 		case CMD_Arena_GetArena: 
// 			ret = CMD_Arena_GetArena_down::create(); 
// 			break; 
// 		case CMD_Arena_IntoArenaLei: 
// 			ret = CMD_Arena_IntoArenaLei_down::create(); 
// 			break; 
// 		case CMD_Arena_IntoArena: 
// 			ret = CMD_Arena_IntoArena_down::create(); 
// 			break; 
// 		case CMD_Arena_FightResultLei: 
// 			ret = CMD_Arena_FightResultLei_down::create(); 
// 			break; 
// 		case CMD_Arena_FightResult: 
// 			ret = CMD_Arena_FightResult_down::create(); 
// 			break; 
// 		case CMD_Pack_Arrange: 
// 			ret = CMD_Pack_Arrange_down::create(); 
// 			break; 
// 		case CMD_SEquip_GetSeize: 
// 			ret = CMD_SEquip_GetSeize_down::create(); 
// 			break; 
// 		case CMD_SEquip_IntoSeize: 
// 			ret = CMD_SEquip_IntoSeize_down::create(); 
// 			break; 
// 		case CMD_SEquip_FightResult: 
// 			ret = CMD_SEquip_FightResult_down::create(); 
// 			break; 
// 		case CMD_Arena_RefArena: 
// 			ret = CMD_Arena_RefArena_down::create(); 
// 			break; 
// 		case CMD_Arena_SNYCTime: 
// 			ret = CMD_Arena_SNYCTime_down::create(); 
// 			break; 
// 		case CMD_Arena_BuyFightNum: 
// 			ret = CMD_Arena_BuyFightNum_down::create(); 
// 			break; 
// 		case CMD_Arena_BuyRefNum: 
// 			ret = CMD_Arena_BuyRefNum_down::create(); 
// 			break; 
// 		case CMD_SkyBook_GetSkyBook: 
// 			ret = CMD_SkyBook_GetSkyBook_down::create(); 
// 			break; 
// 		case CMD_SkyBook_RefSkyBook: 
// 			ret = CMD_SkyBook_RefSkyBook_down::create(); 
// 			break; 
// 		case CMD_SkyBook_RmbRefSkyBook: 
// 			ret = CMD_SkyBook_RmbRefSkyBook_down::create(); 
// 			break; 
// 		case CMD_SkyBook_IntiFight: 
// 			ret = CMD_SkyBook_IntiFight_down::create(); 
// 			break; 
// 		case CMD_SkyBook_FightResult: 
// 			ret = CMD_SkyBook_FightResult_down::create(); 
// 			break; 
// 		case CMD_Active_GetActive: 
// 			ret = CMD_Active_GetActive_down::create(); 
// 			break; 
// 		case CMD_Active_GetGift: 
// 			ret = CMD_Active_GetGift_down::create(); 
// 			break; 
// 		case CMD_Pack_GetMoney: 
// 			ret = CMD_Pack_GetMoney_down::create(); 
// 			break; 
// 		case CMD_Pack_SellItem: 
// 			ret = CMD_Pack_SellItem_down::create(); 
// 			break; 
// 		case CMD_Role_SkillUp: 
// 			ret = CMD_Role_SkillUp_down::create(); 
// 			break; 
// 		case CMD_Pack_GetOpenMoney: 
// 			ret = CMD_Pack_GetOpenMoney_down::create(); 
// 			break; 
// 		case CMD_Pack_OpenPack: 
// 			ret = CMD_Pack_OpenPack_down::create(); 
// 			break; 
// 		case CMD_Pack_UseGift: 
// 			ret = CMD_Pack_UseGift_down::create(); 
// 			break; 
// 		case CMD_Mission_UpData: 
// 			ret = CMD_Mission_UpData_down::create(); 
// 			break; 
// 		case CMD_User_Site: 
// 			ret = CMD_User_Site_down::create(); 
// 			break; 
// 		case CMD_User_AddExp: 
// 			ret = CMD_User_AddExp_down::create(); 
// 			break; 
// 		case CMD_Vip_GetVip: 
// 			ret = CMD_Vip_GetVip_down::create(); 
// 			break; 
// 		case CMD_Vip_VipLevel: 
// 			ret = CMD_Vip_VipLevel_down::create(); 
// 			break; 
// 		case CMD_User_AddEnergy: 
// 			ret = CMD_User_AddEnergy_down::create(); 
// 			break; 
// 		case CMD_User_GetEnergyRmb: 
// 			ret = CMD_User_GetEnergyRmb_down::create(); 
// 			break; 
// 		case CMD_User_BuyEnergy: 
// 			ret = CMD_User_BuyEnergy_down::create(); 
// 			break; 
// 		case CMD_Temp_AddMoney: 
// 			ret = CMD_Temp_AddMoney_down::create(); 
// 			break; 
// 		case CMD_Temp_AddRmb: 
// 			ret = CMD_Temp_AddRmb_down::create(); 
// 			break; 
// 		case CMD_OnLine_GetAward: 
// 			ret = CMD_OnLine_GetAward_down::create(); 
// 			break; 
// 		case CMD_OnLine_SYNC: 
// 			ret = CMD_OnLine_SYNC_down::create(); 
// 			break; 
// 		case CMD_User_GetFunction: 
// 			ret = CMD_User_GetFunction_down::create(); 
// 			break; 
// 		case CMD_User_GetNoGetItem: 
// 			ret = CMD_User_GetNoGetItem_down::create(); 
// 			break; 
// 		case CMD_User_GetRmb: 
// 			ret = CMD_User_GetRmb_down::create(); 
// 			break; 
// 		case CMD_Equip_GetItemLayer: 
// 			ret = CMD_Equip_GetItemLayer_down::create(); 
// 			break; 
// 		case CMD_Top_GetTop: 
// 			ret = CMD_Top_GetTop_down::create(); 
// 			break; 
// 		case CMD_Chat_GetChat: 
// 			ret = CMD_Chat_GetChat_down::create(); 
// 			break; 
// 		case CMD_Chat_SendSay: 
// 			ret = CMD_Chat_SendSay_down::create(); 
// 			break; 
// 		case CMD_Friend_GetFriend: 
// 			ret = CMD_Friend_GetFriend_down::create(); 
// 			break; 
// 		case CMD_Friend_GetBlack: 
// 			ret = CMD_Friend_GetBlack_down::create(); 
// 			break; 
// 		case CMD_Friend_AddFriend: 
// 			ret = CMD_Friend_AddFriend_down::create(); 
// 			break; 
// 		case CMD_Friend_AddBlack: 
// 			ret = CMD_Friend_AddBlack_down::create(); 
// 			break; 
// 		case CMD_Friend_Del: 
// 			ret = CMD_Friend_Del_down::create(); 
// 			break; 
// 		case CMD_Friend_AddFriendName: 
// 			ret = CMD_Friend_AddFriendName_down::create(); 
// 			break; 
// 		case CMD_BattleOne_Save: 
// 			ret = CMD_BattleOne_Save_down::create(); 
// 			break; 
// 		case CMD_BattleOne_Get: 
// 			ret = CMD_BattleOne_Get_down::create(); 
// 			break; 
// 		case CMD_BattleOne_Load: 
// 			ret = CMD_BattleOne_Load_down::create(); 
// 			break; 
// 		case CMD_Title_GetList: 
// 			ret = CMD_Title_GetList_down::create(); 
// 			break; 
// 		case CMD_Title_Show: 
// 			ret = CMD_Title_Show_down::create(); 
// 			break; 
// 		case CMD_Title_GetReward: 
// 			ret = CMD_Title_GetReward_down::create(); 
// 			break; 
// 		case CMD_Sweep_GetRepetition: 
// 			ret = CMD_Sweep_GetRepetition_down::create(); 
// 			break; 
// 		case CMD_Sweep_Start: 
// 			ret = CMD_Sweep_Start_down::create(); 
// 			break; 
// 		case CMD_Sweep_GetStart: 
// 			ret = CMD_Sweep_GetStart_down::create(); 
// 			break; 
// 		case CMD_Sweep_SNYCTime: 
// 			ret = CMD_Sweep_SNYCTime_down::create(); 
// 			break; 
// 		case CMD_Sweep_GetAward: 
// 			ret = CMD_Sweep_GetAward_down::create(); 
// 			break; 
// 		case CMD_Sweep_GetCostRmb: 
// 			ret = CMD_Sweep_GetCostRmb_down::create(); 
// 			break; 
// 		case CMD_Sweep_RmbOver: 
// 			ret = CMD_Sweep_RmbOver_down::create(); 
// 			break; 
// 		case CMD_User_Exit: 
// 			ret = CMD_User_Exit_down::create(); 
// 			break; 
	} 
	 
	CCAssert(ret, "getCallbackCMD is error!"); 
	return ret; 
} 
