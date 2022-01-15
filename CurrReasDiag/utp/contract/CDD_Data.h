/*****************************************************************************
* Copyright 2010 Nexteer Automotive, All Rights Reserved.
* Nexteer Confidential
*
* Module File Name  : CDD_Data.h
* Module Description: Header file for data communicated between Nexteer
*                      Complex Device Drivers (CDD)
* Product           : Gen II Plus - EA3.0
* Author            : Jeremy Warmbier
*****************************************************************************/
/* Version Control:
 * Date Created:      Wed Apr 13 12:17:00 2011
 * %version:          1 %
 * %derived_by:       kzc66z %
 * %date_modified:    Sat Feb 18 11:58:31 2012 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 04/13/11  1        LWW       Initial K2xx Synergy Version
 * 07/05/11  2        LWW       Added WIR data required for services
 * 08/03/11  3		  SAH		Added Structure for EOL part numbers
 * 11/03/11  4		  LWW		Added CDD_Adc_ConvFlag_Uls_u08
 * 01/06/12  5		  LWW		Added updates for new services
 */

#ifndef CDD_DATA_H
#define CDD_DATA_H

#include "Std_Types.h"
#include "CDD_Const.h"
#include "Rte_Type.h"

/*typedef struct {
	uint8	GMLANID_Cnt_u8[12];
	uint8   BaseModelPNAC_Cnt_u8[2];
	uint8	EndModelPNAC_Cnt_u8[2];
	uint8   BaseModelPN_Cnt_u8[4];
	uint8	EndModelPN_Cnt_u8[4];
	uint8   ManfTraceability_Cnt_u8[16];
	uint8   GMManfData_Cnt_u8[5];
	uint8   MEC_Cnt_u8;
	uint8   ProgDate_Cnt_u8[4];
	uint8	RepairShopCode_Cnt_u8[10];
	uint8   VIN_Cnt_u8[17];
	uint8   CalProgFlag_Cnt_u8;
}PRTNUMBERS_STR;
*/
/* Data Native to MtrCtrl Loop */
extern VAR(uint16, CDD_VAR_NOINIT) CDD_MtrPosMech_Rev_G_u0p16[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(uint16, CDD_VAR_NOINIT) CDD_MtrPosElec_Rev_G_u0p16[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(sint16, CDD_VAR_NOINIT) CDD_MtrRevCntr_Cnt_G_s16[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(uint16, CDD_VAR_NOINIT) CDD_SinTheta1_Volts_G_u3p13[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(uint16, CDD_VAR_NOINIT) CDD_CosTheta1_Volts_G_u3p13[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(uint16, CDD_VAR_NOINIT) CDD_DutyCycleSmall_Cnt_G_u16[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(uint16, CDD_VAR_NOINIT) CDD_Shcurr_Cnt_G_u16[D_APPCDDBFRSIZE_CNT_U16];

extern VAR(float32, CDD_VAR_NOINIT) CDD_MtrCurrQax_Amp_G_f32[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(float32, CDD_VAR_NOINIT) CDD_MtrCurrDax_Amp_G_f32[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(float32, CDD_VAR_NOINIT) CDD_MRFMtrVel_MtrRadpS_G_f32[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(float32, CDD_VAR_NOINIT) CDD_MtrCurr1Offset_Volt_G_f32[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(float32, CDD_VAR_NOINIT) CDD_MtrCurr2Offset_Volt_G_f32[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(float32, CDD_VAR_NOINIT) CDD_CorrMtrPosElec_Rev_G_f32[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(float32, CDD_VAR_NOINIT) CDD_MtrCurrK1_Amps_G_f32[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(float32, CDD_VAR_NOINIT) CDD_MtrCurrK2_Amps_G_f32[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(float32, CDD_VAR_NOINIT) CDD_MtrCurr1_Volts_G_f32[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(float32, CDD_VAR_NOINIT) CDD_MtrCurr2_Volts_G_f32[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(float32, CDD_VAR_NOINIT) CDD_DaxPropotionalGain_Uls_G_f32[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(float32, CDD_VAR_NOINIT) CDD_DaxIntegralGain_Uls_G_f32[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(float32, CDD_VAR_NOINIT) CDD_QaxIntegralGain_Uls_G_f32[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(float32, CDD_VAR_NOINIT) CDD_QaxPropotionalGain_Uls_G_f32[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(float32, CDD_VAR_NOINIT) CDD_Vecu_Volt_G_f32[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(float32, CDD_VAR_NOINIT) CDD_MtrCurrDaxRef_Amp_G_f32[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(float32, CDD_VAR_NOINIT) CDD_MtrCurrQaxRef_Amp_G_f32[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(float32, CDD_VAR_NOINIT) CDD_MtrVoltDaxFF_Volt_G_f32[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(float32, CDD_VAR_NOINIT) CDD_MtrVoltQaxFF_Volt_G_f32[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(uint16,CDD_VAR_NOINIT)	CDD_ModIdxSrlComSvcDft_Cnt_G_u16;
extern VAR(float32, CDD_VAR_NOINIT)  CDD_ElecPosDelayComp_Rad_G_f32;
extern VAR(sint8,CDD_VAR_NOINIT)	CDD_MtrElecPol_Cnt_G_s8;
extern VAR(Rte_ModeType_StaMd_Mode, CDD_VAR_NOINIT) CDD_SysState_Cnt_G_Enum;

/*extern VAR(uint32, CDD_VAR_NOINIT) CDD_PWMDutyCycleASum_Cnt_G_u32[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(uint32, CDD_VAR_NOINIT) CDD_PWMDutyCycleBSum_Cnt_G_u32[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(uint32, CDD_VAR_NOINIT) CDD_PWMDutyCycleCSum_Cnt_G_u32[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(uint32, CDD_VAR_NOINIT) CDD_PWMPeriodSum_Cnt_G_u32[D_APPCDDBFRSIZE_CNT_U16];
	
extern VAR(uint16, CDD_VAR_NOINIT) CDD_PhsReasA_Cnt_G_u16[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(uint16, CDD_VAR_NOINIT) CDD_PhsReasB_Cnt_G_u16[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(uint16, CDD_VAR_NOINIT) CDD_PhsReasC_Cnt_G_u16[D_APPCDDBFRSIZE_CNT_U16];
	
extern VAR(uint16, CDD_VAR_NOINIT) CDD_ADCSampleTime_uS_G_u16p0;

extern VAR(sint16, CDD_VAR_NOINIT) CDD_SinBuffer_Uls_G_s2p13[D_OVRSMPLBUFFSIZE_CNT_U16];
extern VAR(sint16, CDD_VAR_NOINIT) CDD_CosBuffer_Uls_G_s2p13[D_OVRSMPLBUFFSIZE_CNT_U16];
extern VAR(uint16, CDD_VAR_NOINIT) CDD_PosBuffer_Rev_G_u0p16[D_OVRSMPLBUFFSIZE_CNT_U16];
extern VAR(uint16, CDD_VAR_NOINIT) CDD_TimeBuffer_uS_G_u16p0[D_OVRSMPLBUFFSIZE_CNT_U16];*/

/* Data Native to Application Loop */
/*extern VAR(uint16, CDD_VAR_NOINIT) CDD_Sin1RTOffset_Volts_G_u3p13[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(uint16, CDD_VAR_NOINIT) CDD_Cos1RTOffset_Volts_G_u3p13[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(uint16, CDD_VAR_NOINIT) CDD_Sin1RTAmpRec_Uls_G_u3p13[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(uint16, CDD_VAR_NOINIT) CDD_Cos1RTAmpRec_Uls_G_u3p13[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(uint16, CDD_VAR_NOINIT) CDD_CommOffset_Cnt_G_u16[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(uint16, CDD_VAR_NOINIT) CDD_DeadTimeComp_Uls_G_u8p8[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(uint32, CDD_VAR_NOINIT) CDD_ModIdxFinal_Uls_G_u16p16[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(sint16, CDD_VAR_NOINIT) CDD_MtrTrqCmdSign_Cnt_G_s16[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(uint16, CDD_VAR_NOINIT) CDD_PhaseAdvFinal_Cnt_G_u16[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(boolean, CDD_VAR_NOINIT) CDD_PwmDisable_Cnt_G_lgc[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(FETFAULTTYPE_ENUM, CDD_VAR_NOINIT) CDD_FETFaultType_Cnt_G_enum[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(FETPHASETYPE_ENUM, CDD_VAR_NOINIT) CDD_FETFaultPhase_Cnt_G_enum[D_APPCDDBFRSIZE_CNT_U16];*/

/* Data Consistancy Buffer Access Variables */
/*extern VAR(uint16, CDD_VAR_NOINIT) CDD_AppDataFwdPthAccessBfr_Cnt_G_u16;
extern VAR(uint16, CDD_VAR_NOINIT) CDD_AppDataFbkPthAccessBfr_Cnt_G_u16;
extern VAR(uint16, CDD_VAR_NOINIT) CDD_CDDDataAccessBfr_Cnt_G_u16;
extern VAR(boolean, CDD_VAR_NOINIT) CDD_OvrSmplBfrWriteEn_Cnt_G_lgc;
*/
/* EOL Global Data */
/*extern VAR(uint16, CDD_VAR_NOINIT) CDD_EOLCustWIRSelect_Cnt_G_u16;
extern VAR(uint16, CDD_VAR_NOINIT) CDD_EOLNxtrWIRSelect_Cnt_G_u16;
extern VAR(uint32, CDD_VAR_NOINIT) CDD_EOLSrlComSvcDft_Cnt_G_b32;

extern VAR(uint16, CDD_VAR_NOINIT) CM_DiagNegRespCode_u16;
extern VAR(boolean, CDD_VAR_NOINIT) CDD_WIRDisableSvc_Cnt_G_lgc;
extern VAR(boolean, CDD_VAR_NOINIT) CDD_DftAsstTbl_Cnt_G_lgc;
extern VAR(float, CDD_VAR_NOINIT) CDD_DwnldAsstGain_Uls_G_f32;

extern VAR(PRTNUMBERS_STR, CDD_VAR_NOINIT) CDD_EOLPrtNumbers_Cnt_G_STR;


extern volatile VAR(uint8, CDD_VAR_NOINIT) CDD_Adc_ConvFlag_Uls_u08;*/
#endif
