/*****************************************************************************
* Copyright 2010 Nexteer Automotive, All Rights Reserved.
* Nexteer Confidential
*
* Module File Name  : CalConstants.h
* Module Description: This file contains the declarations of calibration 
*                     constants used in the EPS Software.
* Product           : Gen II Plus EA3.0
* Author            : Lucas Wendling
*****************************************************************************/
/* Version Control:
 * Date Created:      Wed Apr 13 12:17:00 2011
 * %version:          6 %
 * %derived_by:       xz0btk %
 * %date_modified:    Thu Aug  1 11:30:06 2013 %
 *---------------------------------------------------------------------------------------------------------------------
 */

#ifndef CALCONSTANTS_H
#define CALCONSTANTS_H

#include "Rte_Type.h"
#include "fixmath.h"
#include "filters.h"
#include "Ap_DiagMgr_Types.h"


/*********************** Start of Auto Generated Code ************************/

/****************** File Generated on 8/1/2013 11:24:28 AM *******************/
/************************** SrlComInput - Rev 13.0 ***************************/



extern CONST(uint16, CAL_CONST) k_VehSpdMisMsgTimeOut_mS_u16p0;
extern CONST(uint16, CAL_CONST) k_VehSpdValTimeOut_mS_u16p0;
extern CONST(uint16, CAL_CONST) k_IgnStatMisMsgTimeOut_mS_u16p0;
extern CONST(uint16, CAL_CONST) k_IgnStatValTimeOut_mS_u16p0;
extern CONST(uint16, CAL_CONST) k_EngRPMMisMsgTimeOut_mS_u16p0;
extern CONST(uint16, CAL_CONST) k_EngRPMValTimeOut_mS_u16p0;
extern CONST(uint16, CAL_CONST) k_SWAValTimeOut_mS_u16p0;
extern CONST(sint8, CAL_CONST) k_StrgWhlAnglPol_s08;
extern CONST(uint16, CAL_CONST) k_SWAMisMsgTimeOut_mS_u16p0;
extern CONST(uint16, CAL_CONST) k_PSTMisMsgTimeOut_mS_u16p0;
extern CONST(uint16, CAL_CONST) k_VehCfg5MisMsgTimeOut_mS_u16p0;
extern CONST(uint16, CAL_CONST) k_HalfMsgTimeOut_mS_u16p0;
extern CONST(uint16, CAL_CONST) k_NETCFGMsgTimeOut_mS_u16p0;
extern CONST(uint16, CAL_CONST) k_EcuCfg6MsgTimeOut_mS_u16p0;
extern CONST(DiagSettings_Str, CAL_CONST) k_PSTTrqOverlayDiag_Cnt_str;
extern CONST(float32, CAL_CONST) k_PSTTrqOverlayLmt_Cnt_f32;
extern CONST(uint16, CAL_CONST) k_MC292hMsg_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_MC11ChMsg_Cnt_u16;
extern CONST(DiagSettings_Str, CAL_CONST) k_DSTTOCProgCnt1Diag_Cnt_str;
extern CONST(DiagSettings_Str, CAL_CONST) k_DSTTOCProgCnt2Diag_Cnt_str;
extern CONST(uint16, CAL_CONST) k_MC29FhMsg_Cnt_u16;
extern CONST(float32, CAL_CONST) k_HalfTrqMax_Nm_f32;
extern CONST(uint32, CAL_CONST) k_MsgMaxHalfTorqTO_mS_u32p0;
extern CONST(float32, CAL_CONST) k_PASlewRate_NmpS_f32;
extern CONST(float32, CAL_CONST) k_PSTTrqOvrlChngeLmt_NmpS_f32;
extern CONST(DiagSettings_Str, CAL_CONST) k_PSTTrqOvrlChngeLmtDiag_Cnt_str;
extern CONST(float32, CAL_CONST) k_HaLFSlewRate_NmpS_f32;
extern CONST(float32, CAL_CONST) k_HaLFTrqOvrlChngeLmt_NmpS_f32;
extern CONST(DiagSettings_Str, CAL_CONST) k_HaLFTrqOverlayDiag_Cnt_str;
extern CONST(uint16, CAL_CONST) k_CRC292DiagMsg_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_CRC29FDiagMsg_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_CRC11CDiagMsg_Cnt_u16;
extern CONST(float32, CAL_CONST) k_IWSSVSpdConst_Cnt_f32;
extern CONST(uint16, CAL_CONST) k_BattVoltInvTimeOut_mS_u16p0;
extern CONST(uint16, CAL_CONST) k_BattVoltMsgTimeOut_mS_u16p0;
extern CONST(uint16, CAL_CONST) k_ECMA3MsgTimeOut_mS_u16p0;
extern CONST(uint16, CAL_CONST) k_ESP4AInvTimeOut_mS_u16p0;
extern CONST(uint16, CAL_CONST) k_ESP4AMsgTimeOut_mS_u16p0;
extern CONST(uint16, CAL_CONST) k_IC1AAInvTimeOut_mS_u16p0;
extern CONST(uint16, CAL_CONST) k_IC1AMsgTimeOut_mS_u16p0;
extern CONST(uint16, CAL_CONST) k_VehCfg1AInvTimeOut_mS_u16p0;
extern CONST(uint16, CAL_CONST) k_VehCfg1MsgTimeOut_mS_u16p0;
extern CONST(uint16, CAL_CONST) k_VINInvTimeOut_mS_u16p0;
extern CONST(uint16, CAL_CONST) k_VINMsgTimeOut_mS_u16p0;
extern CONST(uint16, CAL_CONST) k_BattMsgVoltHighTimeOut_mS_u16p0;
extern CONST(uint16, CAL_CONST) k_BattMsgVoltLowTimeOut_mS_u16p0;
extern CONST(uint16, CAL_CONST) k_CBCNodeAbsTime_mS_u16p0;
extern CONST(uint16, CAL_CONST) k_DSLNodeAbsTime_mS_u16p0;
extern CONST(uint16, CAL_CONST) k_StrWhlAnglRatTime_mS_u16p0;
extern CONST(uint16, CAL_CONST) k_VehCfg3InvMsgTimeOut_mS_u16p0;

/********************************** Unknown **********************************/
extern CONST(uint16, CAL_CONST) k_CRC294DiagThr1_Cnt_u16;
extern CONST(DiagSettings_Str, CAL_CONST) k_CRC294DiagThr2_Cnt_str;
extern CONST(uint16, CAL_CONST) k_DSTMisMsgThr0_ms_u16;
extern CONST(uint16, CAL_CONST) k_DSTTOCActMisMsgThr1_Cnt_u16p0;
extern CONST(DiagSettings_Str, CAL_CONST) k_DSTTOCActMisMsgThr2_Cnt_str;
extern CONST(uint16, CAL_CONST) k_DSTTOCNotActMisMsgThr1_Cnt_u16p0;
extern CONST(DiagSettings_Str, CAL_CONST) k_DSTTOCNotActMisMsgThr2_Cnt_str;
extern CONST(DiagSettings_Str, CAL_CONST) k_DSTTOCProgCntDiagThr2_Cnt_str;
extern CONST(uint16, CAL_CONST) k_DSTTOCProgCntThr1_Cnt_u16;
extern CONST(float32, CAL_CONST) k_MsgMaxHalfTorqTO_Nm_f32;
extern CONST(float32, CAL_CONST) k_DSTTrqMax_HwNm_f32;
extern CONST(float32, CAL_CONST) k_DSTTrqOvrlSlewLmt_NmpS_f32;
extern CONST(uint32, CAL_CONST) k_MaxDSTActiveTime_mS_u32p0;
extern CONST(uint16, CAL_CONST) k_MaxDSTXorCptNTC18F_Cnt_u16;
extern CONST(float32, CAL_CONST) k_maxFreqChg_RevpSec_f32;
extern CONST(uint16, CAL_CONST) k_WSP2AInvTimeOut_mS_u16p0;
extern CONST(uint16, CAL_CONST) k_WSP2TimeOut_mS_u16p0;
extern CONST(uint16, CAL_CONST) k_EngCfgMisMsgTimeOut_mS_u16p0;
extern CONST(uint16, CAL_CONST) k_EngOilTempMsgTimeOut_mS_u16p0;
extern CONST(uint16, CAL_CONST) k_ECMA3InvTimeOut_mS_u16p0;
extern CONST(uint16, CAL_CONST) k_RevGearMsgTimeOut_mS_u16p0;
extern CONST(uint16, CAL_CONST) k_TrnsStatInvTimeOut_mS_u16p0;
extern CONST(uint16, CAL_CONST) k_TrnsStatTimeOut_mS_u16p0;
extern CONST(uint16, CAL_CONST) k_VehCfg5MsgTimeOut_mS_u16p0;
extern CONST(uint16, CAL_CONST) k_ESPA5MsgTimeOut_mS_u16p0;
extern CONST(uint16, CAL_CONST) k_ESPA5ValTimeOut_mS_u16p0;
extern CONST(uint16, CAL_CONST) k_ESPA6MsgTimeOut_mS_u16p0;
extern CONST(uint16, CAL_CONST) k_ESPA6ValTimeOut_mS_u16p0;
extern CONST(uint16, CAL_CONST) k_TireCircRcvdTimeOut_mS_u16p0;
extern CONST(DiagSettings_Str, CAL_CONST) k_TrqOvrlMaxSlewDiag_Cnt_str;
extern CONST(uint16, CAL_CONST) k_CfgRQCMisMsgTimeOut_mS_u16p0;
extern CONST(uint16, CAL_CONST) k_CfgRQMisMsgTimeOut_mS_u16p0;
extern CONST(uint16, CAL_CONST) k_EcuCfg6InvMsgTimeOut_mS_u16p0;
extern CONST(uint16, CAL_CONST) k_ESPA5MsgTimeOut_mS_u16p0;
extern CONST(uint16, CAL_CONST) k_ESPA5ValTimeOut_mS_u16p0;
extern CONST(uint16, CAL_CONST) k_ESPA6MsgTimeOut_mS_u16p0;
extern CONST(uint16, CAL_CONST) k_ESPA6ValTimeOut_mS_u16p0;
extern CONST(uint16, CAL_CONST) k_GWLINIC2InvMsgTimeOut_mS_u16p0;
extern CONST(uint16, CAL_CONST) k_GWLINIC2MsgTimeOut_mS_u16p0;
extern CONST(uint16, CAL_CONST) k_VehCfg7InvMsgTimeOut_mS_u16p0;
extern CONST(uint16, CAL_CONST) k_VehCfg7MsgTimeOut_mS_u16p0;
extern CONST(float32, CAL_CONST) k_StuckTrqBnd_Nm_f32;
extern CONST(float32, CAL_CONST) k_TrqStckActv_HwNm_M_f32;
extern CONST(uint16, CAL_CONST) k_TrqStckHiSWATime_mS_u16p0;
extern CONST(uint16, CAL_CONST) k_TrqStckLowSWATime_mS_u16p0;
extern CONST(float32, CAL_CONST) k_TrqStckSWA_HwDeg_f32;
extern CONST(uint32, CAL_CONST) k_DSTTOCInvMsgTimeOut_mS_u16p0;
extern CONST(uint16, CAL_CONST) k_MaxHlfRmpOutRt_Nm_F32;
extern CONST(float32, CAL_CONST) k_MtrTrqOvrlyStrRqMax_Nm_f32;
extern CONST(uint16, CAL_CONST) k_PerMisMchCntLmt_Cnt_u16;
extern CONST(uint8, CAL_CONST) k_PerMisMchFltThr_Cnt_u08;
#endif

/*********************** Start of Code Footer ************************/





















