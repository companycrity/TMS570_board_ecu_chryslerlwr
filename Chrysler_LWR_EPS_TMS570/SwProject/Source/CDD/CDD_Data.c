/*****************************************************************************
* Copyright 2010 Nexteer Automotive, All Rights Reserved.
* Nexteer Confidential
*
* Module File Name  : CDD_Data.c
* Module Description: Definition file for data communicated between Nexteer
*                      Complex Device Drivers (CDD)
* Product           : Gen II Plus - EA3.0
* Author            : Jeremy Warmbier
*****************************************************************************/
/* Version Control:
 * Date Created:      Wed Apr 13 12:17:00 2011
 * %version:          17 %
 * %derived_by:       jzh87w %
 * %date_modified:    Fri Feb 14 10:52:30 2014 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 04/13/11  1        LWW       Initial K2xx Synergy Version
 * 07/05/11  2        LWW       Added WIR data required for services
 * 08/03/11  3		  SAH		Added Structure for EOL part numbers
 * 11/03/11  4		  LWW		Added CDD_Adc_ConvFlag_Uls_u08
 * 01/06/12  5		  LWW		Added updates for new services
 * 04/17/12  9		  LWW		Removed partnumber structure
 * 04/18/12  10		  LWW		Added IPM CDD variables
 * 12/10/12  2		  SAH		Added CDD_MtrCurrQaxFinalRef_Amp_G_f32
 * 12/17/12  3		  SAH		Added signals for new MtrVel component
 * 12/20/12  4		  SAH		Added CDD_MtrVoltDax_Volt_G_f32 and CDD_MtrVoltQax_Volt_G_f32
 * 02/21/13  6		  SAH		Added ePWM global variables
 * 05/13/13  7		  Story		No comment
 * 05/24/13  8		  SAH		Updates for Mtrpos component integration
 * 07/26/13  10		  SAH		Moved CDD_Odometer_Cnt_u32 from Ap_10 to Ap_9
 * 07/31/13  11		  SAH		Moved CDD_DftAsstTbl_Cnt_G_lgc and CDD_DwnldAsstGain_Uls_G_f32 from Ap_10 to Ap_9
 * 08/01/13  12		  SAH		Moved some scomm variables from Ap_10 to Ap_9
 * 09/27/13  13		  SAH		Removed access buffer from commoffset
 * 10/11/13  14		  SAH		Added CorrMtrCurrposition
 * 02/14/14  15		  SAH       Add EcuHardResetSrvcActive_Cnt_G_lgc flag used in SchM and appdesc
 * 05/12/14  16		  SAH       Added ChryEngDft_Cnt_G_lgc flag used in cddinterface and appdesc
 * 07/22/14  17		  SAH       Added PullCompDis flag used in cddinterface and appdesc
 */

#include "Std_Types.h"
#include "CDD_Const.h"
#include "CDD_Data.h"

/**********************************************************************************************************************
 *  Ap_9
 *********************************************************************************************************************/
#define CDDDATA9_START_SEC_VAR_NOINIT_32
#include "MemMap.h" /* PRQA S 5087 */
/* EOL Global Data */
VAR(uint16, CDD_VAR_NOINIT) CDD_EOLCustWIRSelect_Cnt_G_u16;
VAR(uint16, CDD_VAR_NOINIT) CDD_EOLNxtrWIRSelect_Cnt_G_u16;
VAR(uint32, CDD_VAR_NOINIT) CDD_EOLSrlComSvcDft_Cnt_G_b32;
VAR(uint32,  AP_SRLCOMINPUT_VAR_INIT) CDD_Odometer_Cnt_u32;
VAR(boolean, CDD_VAR_NOINIT) CDD_DftAsstTbl_Cnt_G_lgc;
VAR(float, CDD_VAR_NOINIT) CDD_DwnldAsstGain_Uls_G_f32;
VAR(boolean, CDD_VAR_NOINIT) CDD_WIRDisableSvc_Cnt_G_lgc;
VAR(boolean, CDD_VAR_NOINIT) CDD_DctvFailSafeRctnsCnt_G_lgc;
VAR(boolean, CDD_VAR_NOINIT) CDD_CntrlDTCReset_G_lgc;

#define CDDDATA9_STOP_SEC_VAR_NOINIT_32
#include "MemMap.h" /* PRQA S 5087 */

#define CDDDATA9_START_SEC_VAR_NOINIT_BOOLEAN
#include "MemMap.h" /* PRQA S 5087 */

VAR(boolean, CDD_VAR_NOINIT) EcuHardResetSrvcActive_Cnt_G_lgc;
VAR(boolean, CDD_VAR_NOINIT) ChryEngDft_Cnt_G_lgc;
VAR(boolean, CDD_VAR_NOINIT) Appdesc_PullCompDis_Cnt_G_lgc;

#define CDDDATA9_STOP_SEC_VAR_NOINIT_BOOLEAN
#include "MemMap.h" /* PRQA S 5087 */

/**********************************************************************************************************************
 *  Ap_10
 *********************************************************************************************************************/
#define CDDDATA10_START_SEC_VAR_NOINIT_16
#include "MemMap.h" /* PRQA S 5087 */

/* Data Native to MtrCtrl Loop */
VAR(uint16, CDD_VAR_NOINIT) CDD_DutyCycleSmall_Cnt_G_u16[D_APPCDDBFRSIZE_CNT_U16];

#define CDDDATA10_STOP_SEC_VAR_NOINIT_16
#include "MemMap.h" /* PRQA S 5087 */

#define CDDDATA10_START_SEC_VAR_NOINIT_32
#include "MemMap.h" /* PRQA S 5087 */
VAR(float32, CDD_VAR_NOINIT) CDD_MtrCurrQax_Amp_G_f32[D_APPCDDBFRSIZE_CNT_U16];
VAR(float32, CDD_VAR_NOINIT) CDD_MtrCurrDax_Amp_G_f32[D_APPCDDBFRSIZE_CNT_U16];
VAR(float32, CDD_VAR_NOINIT) CDD_MRFMtrVel_MtrRadpS_G_f32[D_APPCDDBFRSIZE_CNT_U16];
VAR(float32, CDD_VAR_NOINIT) CDD_MtrCurr1Offset_Volt_G_f32[D_APPCDDBFRSIZE_CNT_U16];
VAR(float32, CDD_VAR_NOINIT) CDD_MtrCurr2Offset_Volt_G_f32[D_APPCDDBFRSIZE_CNT_U16];
VAR(float32, CDD_VAR_NOINIT) CDD_CorrMtrPosElec_Rev_G_f32[D_APPCDDBFRSIZE_CNT_U16];
VAR(float32, CDD_VAR_NOINIT) CDD_CorrMtrCurrPosition_Rev_G_f32[D_APPCDDBFRSIZE_CNT_U16];
VAR(float32, CDD_VAR_NOINIT) CDD_MtrCurrK1_Amps_G_f32[D_APPCDDBFRSIZE_CNT_U16];
VAR(float32, CDD_VAR_NOINIT) CDD_MtrCurrK2_Amps_G_f32[D_APPCDDBFRSIZE_CNT_U16];
VAR(float32, CDD_VAR_NOINIT) CDD_MtrCurr1_Volts_G_f32[D_APPCDDBFRSIZE_CNT_U16];
VAR(float32, CDD_VAR_NOINIT) CDD_MtrCurr2_Volts_G_f32[D_APPCDDBFRSIZE_CNT_U16];
VAR(float32, CDD_VAR_NOINIT) CDD_DaxPropotionalGain_Uls_G_f32[D_APPCDDBFRSIZE_CNT_U16];
VAR(float32, CDD_VAR_NOINIT) CDD_DaxIntegralGain_Uls_G_f32[D_APPCDDBFRSIZE_CNT_U16];
VAR(float32, CDD_VAR_NOINIT) CDD_QaxIntegralGain_Uls_G_f32[D_APPCDDBFRSIZE_CNT_U16];
VAR(float32, CDD_VAR_NOINIT) CDD_QaxPropotionalGain_Uls_G_f32[D_APPCDDBFRSIZE_CNT_U16];
VAR(float32, CDD_VAR_NOINIT) CDD_Vecu_Volt_G_f32[D_APPCDDBFRSIZE_CNT_U16];
VAR(float32, CDD_VAR_NOINIT) CDD_MtrCurrDaxRef_Amp_G_f32[D_APPCDDBFRSIZE_CNT_U16];
VAR(float32, CDD_VAR_NOINIT) CDD_MtrCurrQaxRef_Amp_G_f32[D_APPCDDBFRSIZE_CNT_U16];
VAR(float32, CDD_VAR_NOINIT) CDD_MtrVoltDaxFF_Volt_G_f32[D_APPCDDBFRSIZE_CNT_U16];
VAR(float32, CDD_VAR_NOINIT) CDD_MtrVoltQaxFF_Volt_G_f32[D_APPCDDBFRSIZE_CNT_U16];
VAR(float32, CDD_VAR_NOINIT) CDD_MtrCurr1TempOffset_Volt_G_f32[D_APPCDDBFRSIZE_CNT_U16];
VAR(float32, CDD_VAR_NOINIT) CDD_MtrCurr2TempOffset_Volt_G_f32[D_APPCDDBFRSIZE_CNT_U16];
VAR(uint16,CDD_VAR_NOINIT)   CDD_ModIdxSrlComSvcDft_Cnt_G_u16;
VAR(uint16,CDD_VAR_NOINIT)  PhaseAdvanceFinal_Rev_G_u0p16;
VAR(float32, CDD_VAR_NOINIT)  CDD_ElecPosDelayComp_Rad_G_f32;
VAR(sint8,CDD_VAR_NOINIT)	CDD_MtrElecPol_Cnt_G_s8;
VAR(Rte_ModeType_StaMd_Mode, CDD_VAR_NOINIT) CDD_SysState_Cnt_G_Enum;
VAR(uint16,CDD_VAR_NOINIT) CDD_DCPhsBComp_Cnt_G_u16p0;
VAR(uint16,CDD_VAR_NOINIT) CDD_DCPhsCComp_Cnt_G_u16p0;
VAR(uint16,CDD_VAR_NOINIT) CDD_MtrCurrOffComOffset_Cnt_G_u16[D_APPCDDBFRSIZE_CNT_U16];
VAR(float32,CDD_VAR_NOINIT) CDD_MtrPosComputationDelay_Deg_G_f32[D_APPCDDBFRSIZE_CNT_U16];
VAR(float32,CDD_VAR_NOINIT) CDD_MtrCurrQax12Mag_Amp_G_f32[D_APPCDDBFRSIZE_CNT_U16];
VAR(float32,CDD_VAR_NOINIT) CDD_MtrCurrQax6Mag_Amp_G_f32[D_APPCDDBFRSIZE_CNT_U16];
VAR(float32,CDD_VAR_NOINIT) CDD_MtrCurrQax12Ph_Rev_G_f32[D_APPCDDBFRSIZE_CNT_U16];
VAR(float32,CDD_VAR_NOINIT) CDD_MtrCurrQax6Ph_Rev_G_f32[D_APPCDDBFRSIZE_CNT_U16];
VAR(float32,CDD_VAR_NOINIT) CDD_EstKe_VpRadpS_G_f32[D_APPCDDBFRSIZE_CNT_U16];

VAR(float32, CDD_VAR_NOINIT) CDD_MtrCurrQaxCog_Amp_G_f32;
VAR(float32, CDD_VAR_NOINIT) CDD_MtrCurrQaxRpl_Amp_G_f32;
VAR(uint32, CDD_VAR_NOINIT) CDD_PWMDutyCycleASum_Cnt_G_u32[D_APPCDDBFRSIZE_CNT_U16];
VAR(uint32, CDD_VAR_NOINIT) CDD_PWMDutyCycleBSum_Cnt_G_u32[D_APPCDDBFRSIZE_CNT_U16];
VAR(uint32, CDD_VAR_NOINIT) CDD_PWMDutyCycleCSum_Cnt_G_u32[D_APPCDDBFRSIZE_CNT_U16];
VAR(uint32, CDD_VAR_NOINIT) CDD_PWMPeriodSum_Cnt_G_u32[D_APPCDDBFRSIZE_CNT_U16];
	
VAR(uint16, CDD_VAR_NOINIT) CDD_PhsReasA_Cnt_G_u16[D_APPCDDBFRSIZE_CNT_U16];
VAR(uint16, CDD_VAR_NOINIT) CDD_PhsReasB_Cnt_G_u16[D_APPCDDBFRSIZE_CNT_U16];
VAR(uint16, CDD_VAR_NOINIT) CDD_PhsReasC_Cnt_G_u16[D_APPCDDBFRSIZE_CNT_U16];


/* Data Native to Application Loop */
VAR(uint16, CDD_VAR_NOINIT) CDD_CommOffset_Cnt_G_u16;
VAR(uint16, CDD_VAR_NOINIT) CDD_DeadTimeComp_Uls_G_u8p8[D_APPCDDBFRSIZE_CNT_U16];
VAR(uint32, CDD_VAR_NOINIT) CDD_ModIdxFinal_Uls_G_u16p16[D_APPCDDBFRSIZE_CNT_U16];
VAR(sint16, CDD_VAR_NOINIT) CDD_MtrTrqCmdSign_Cnt_G_s16[D_APPCDDBFRSIZE_CNT_U16];
VAR(uint16, CDD_VAR_NOINIT) CDD_PhaseAdvFinal_Cnt_G_u16[D_APPCDDBFRSIZE_CNT_U16];
VAR(boolean, CDD_VAR_NOINIT) CDD_PwmDisable_Cnt_G_lgc[D_APPCDDBFRSIZE_CNT_U16];
VAR(FETFAULTTYPE_ENUM, CDD_VAR_NOINIT) CDD_FETFaultType_Cnt_G_enum[D_APPCDDBFRSIZE_CNT_U16];
VAR(FETPHASETYPE_ENUM, CDD_VAR_NOINIT) CDD_FETFaultPhase_Cnt_G_enum[D_APPCDDBFRSIZE_CNT_U16];
VAR(float32, CDD_VAR_NOINIT) CDD_MtrCurrQaxFinalRef_Amp_G_f32[D_APPCDDBFRSIZE_CNT_U16];
VAR(float32, CDD_VAR_NOINIT) CDD_MtrVoltDax_Volt_G_f32[D_APPCDDBFRSIZE_CNT_U16];
VAR(float32, CDD_VAR_NOINIT) CDD_MtrVoltQax_Volt_G_f32[D_APPCDDBFRSIZE_CNT_U16];


/* Data Consistancy Buffer Access Variables */
VAR(uint16, CDD_VAR_NOINIT) CDD_AppDataFwdPthAccessBfr_Cnt_G_u16;
VAR(uint16, CDD_VAR_NOINIT) CDD_AppDataFbkPthAccessBfr_Cnt_G_u16;
VAR(uint16, CDD_VAR_NOINIT) CDD_CDDDataAccessBfr_Cnt_G_u16;


/* ePWM Globals SAH*/
VAR(uint16, CDD_VAR_NOINT) CDD_DCPhsComp_Cnt_G_u16[3];
VAR(uint16, CDD_VAR_NOINT) CDD_PWMPeriod_Cnt_G_u16;


volatile VAR(uint8, IOHWAB_NOINIT_8BIT) CDD_Adc_ConvFlag_Uls_u08;

#define CDDDATA10_STOP_SEC_VAR_NOINIT_32
#include "MemMap.h" /* PRQA S 5087 */
