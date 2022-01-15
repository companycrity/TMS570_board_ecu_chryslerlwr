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
 * %version:          14 %
 * %derived_by:       jzh87w %
 * %date_modified:    Fri Feb 14 10:52:31 2014 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 04/13/11  1        LWW       Initial K2xx Synergy Version
 * 07/05/11  2        LWW       Added WIR data required for services
 * 08/03/11  3		  SAH		Added Structure for EOL part numbers
 * 11/03/11  4		  LWW		Added CDD_Adc_ConvFlag_Uls_u08
 * 01/06/12  5		  LWW		Added updates for new services
 * 01/13/12  6		  SAH		Updated EOL Part number structure.
 * 04/17/12  10		  LWW		Removed partnumber structure
 * 04/18/12  11		  LWW		Added IPM CDD variables
 * 12/10/12  2		  SAH		Added CDD_MtrCurrQaxFinalRef_Amp_G_f32
 * 12/17/12  3		  SAH		Added signals for new MtrVel component
 * 12/20/12  4		  SAH		Added CDD_MtrVoltDax_Volt_G_f32 and CDD_MtrVoltQax_Volt_G_f32
 * 02/21/13  6		  SAH		Added ePWM global variables
 * 05/13/13  7		  Story		No comment
 * 05/24/13  8		  SAH		Updates for Mtrpos component integration
 * 08/01/13  9		  SAH		Removed unused variables
 * 09/27/13  10		  SAH		Removed access buffer from commoffset
 * 10/11/13  11		  SAH		Added CorrMtrCurrposition
 * 02/14/14  12		  SAH       Add EcuHardResetSrvcActive_Cnt_G_lgc flag used in SchM and appdesc
 * 05/12/14  13		  SAH       Added ChryEngDft_Cnt_G_lgc flag used in cddinterface and appdesc
 * 07/22/14  14		  SAH       Added PullCompDis flag used in cddinterface and appdesc
 */

#ifndef CDD_DATA_H
#define CDD_DATA_H

#include "Std_Types.h"
#include "CDD_Const.h"
#include "Rte_Type.h"

/* Turns Counter Flash Programming */
typedef enum {
	TcPrgInit	= 	0,
	TcPrgInPrcs =	1,
	TcPrgCmpl	=	2
} TcFlshPrgStatus_T;

/* Data Native to MtrCtrl Loop */
extern VAR(uint16, CDD_VAR_NOINIT) CDD_DutyCycleSmall_Cnt_G_u16[D_APPCDDBFRSIZE_CNT_U16];


extern VAR(float32, CDD_VAR_NOINIT) CDD_MtrCurrQax_Amp_G_f32[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(float32, CDD_VAR_NOINIT) CDD_MtrCurrDax_Amp_G_f32[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(float32, CDD_VAR_NOINIT) CDD_MRFMtrVel_MtrRadpS_G_f32[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(float32, CDD_VAR_NOINIT) CDD_MtrCurr1Offset_Volt_G_f32[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(float32, CDD_VAR_NOINIT) CDD_MtrCurr2Offset_Volt_G_f32[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(float32, CDD_VAR_NOINIT) CDD_CorrMtrPosElec_Rev_G_f32[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(float32, CDD_VAR_NOINIT) CDD_CorrMtrCurrPosition_Rev_G_f32[D_APPCDDBFRSIZE_CNT_U16];
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
extern VAR(uint16,CDD_VAR_NOINIT)  PhaseAdvanceFinal_Rev_G_u0p16;
extern VAR(float32, CDD_VAR_NOINIT)  CDD_ElecPosDelayComp_Rad_G_f32;
extern VAR(sint8,CDD_VAR_NOINIT)	CDD_MtrElecPol_Cnt_G_s8;
extern VAR(Rte_ModeType_StaMd_Mode, CDD_VAR_NOINIT) CDD_SysState_Cnt_G_Enum;
extern VAR(uint16,CDD_VAR_NOINIT) CDD_DCPhsBComp_Cnt_G_u16p0;
extern VAR(uint16,CDD_VAR_NOINIT) CDD_DCPhsCComp_Cnt_G_u16p0;
extern VAR(float32, CDD_VAR_NOINIT) CDD_MtrCurr1TempOffset_Volt_G_f32[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(float32, CDD_VAR_NOINIT) CDD_MtrCurr2TempOffset_Volt_G_f32[D_APPCDDBFRSIZE_CNT_U16];

extern VAR(uint16,CDD_VAR_NOINIT) CDD_MtrCurrOffComOffset_Cnt_G_u16[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(float32,CDD_VAR_NOINIT) CDD_MtrPosComputationDelay_Deg_G_f32[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(float32,CDD_VAR_NOINIT) CDD_MtrCurrQax12Mag_Amp_G_f32[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(float32,CDD_VAR_NOINIT) CDD_MtrCurrQax6Mag_Amp_G_f32[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(float32,CDD_VAR_NOINIT) CDD_MtrCurrQax12Ph_Rev_G_f32[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(float32,CDD_VAR_NOINIT) CDD_MtrCurrQax6Ph_Rev_G_f32[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(float32,CDD_VAR_NOINIT) CDD_EstKe_VpRadpS_G_f32[D_APPCDDBFRSIZE_CNT_U16];

extern VAR(float32, CDD_VAR_NOINIT) CDD_MtrCurrQaxCog_Amp_G_f32;
extern VAR(float32, CDD_VAR_NOINIT) CDD_MtrCurrQaxRpl_Amp_G_f32;
extern VAR(uint32, CDD_VAR_NOINIT) CDD_PWMDutyCycleASum_Cnt_G_u32[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(uint32, CDD_VAR_NOINIT) CDD_PWMDutyCycleBSum_Cnt_G_u32[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(uint32, CDD_VAR_NOINIT) CDD_PWMDutyCycleCSum_Cnt_G_u32[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(uint32, CDD_VAR_NOINIT) CDD_PWMPeriodSum_Cnt_G_u32[D_APPCDDBFRSIZE_CNT_U16];
	
extern VAR(uint16, CDD_VAR_NOINIT) CDD_PhsReasA_Cnt_G_u16[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(uint16, CDD_VAR_NOINIT) CDD_PhsReasB_Cnt_G_u16[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(uint16, CDD_VAR_NOINIT) CDD_PhsReasC_Cnt_G_u16[D_APPCDDBFRSIZE_CNT_U16];
	

/* Data Native to Application Loop */
extern VAR(uint16, CDD_VAR_NOINIT) CDD_CommOffset_Cnt_G_u16;
extern VAR(uint16, CDD_VAR_NOINIT) CDD_DeadTimeComp_Uls_G_u8p8[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(uint32, CDD_VAR_NOINIT) CDD_ModIdxFinal_Uls_G_u16p16[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(sint16, CDD_VAR_NOINIT) CDD_MtrTrqCmdSign_Cnt_G_s16[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(uint16, CDD_VAR_NOINIT) CDD_PhaseAdvFinal_Cnt_G_u16[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(boolean, CDD_VAR_NOINIT) CDD_PwmDisable_Cnt_G_lgc[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(float32, CDD_VAR_NOINIT) CDD_MtrCurrQaxFinalRef_Amp_G_f32[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(float32, CDD_VAR_NOINIT) CDD_MtrVoltDax_Volt_G_f32[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(float32, CDD_VAR_NOINIT) CDD_MtrVoltQax_Volt_G_f32[D_APPCDDBFRSIZE_CNT_U16];

/* Data Consistancy Buffer Access Variables */
extern VAR(uint16, CDD_VAR_NOINIT) CDD_AppDataFwdPthAccessBfr_Cnt_G_u16;
extern VAR(uint16, CDD_VAR_NOINIT) CDD_AppDataFbkPthAccessBfr_Cnt_G_u16;
extern VAR(uint16, CDD_VAR_NOINIT) CDD_CDDDataAccessBfr_Cnt_G_u16;
//extern VAR(boolean, CDD_VAR_NOINIT) CDD_OvrSmplBfrWriteEn_Cnt_G_lgc;

/* EOL Global Data */
extern VAR(uint16, CDD_VAR_NOINIT) CDD_EOLCustWIRSelect_Cnt_G_u16;
extern VAR(uint16, CDD_VAR_NOINIT) CDD_EOLNxtrWIRSelect_Cnt_G_u16;
extern VAR(uint32, CDD_VAR_NOINIT) CDD_EOLSrlComSvcDft_Cnt_G_b32;

extern VAR(boolean, CDD_VAR_NOINIT) CDD_WIRDisableSvc_Cnt_G_lgc;
extern VAR(boolean, CDD_VAR_NOINIT) CDD_DftAsstTbl_Cnt_G_lgc;
extern VAR(float, CDD_VAR_NOINIT) CDD_DwnldAsstGain_Uls_G_f32;
extern VAR(boolean, CDD_VAR_NOINIT) CDD_DctvFailSafeRctnsCnt_G_lgc;
extern VAR(boolean, CDD_VAR_NOINIT) CDD_CntrlDTCReset_G_lgc;
extern VAR(uint32,  AP_SRLCOMINPUT_VAR_INIT) CDD_Odometer_Cnt_u32;

extern volatile VAR(uint8, CDD_VAR_NOINIT) CDD_Adc_ConvFlag_Uls_u08;

/* ePWM Globals */
extern VAR(uint16, CDD_VAR_NOINT) CDD_DCPhsComp_Cnt_G_u16[3];
extern VAR(uint16, CDD_VAR_NOINT) CDD_PWMPeriod_Cnt_G_u16;

/* Flag used in SchM and appdesc to update NvM as fast as possible to help meet manufacturing shutdown ECU reset timing requirements */
extern VAR(boolean, CDD_VAR_NOINIT) EcuHardResetSrvcActive_Cnt_G_lgc;
extern VAR(boolean, CDD_VAR_NOINIT) ChryEngDft_Cnt_G_lgc;
extern VAR(boolean, CDD_VAR_NOINIT) Appdesc_PullCompDis_Cnt_G_lgc;



#endif
