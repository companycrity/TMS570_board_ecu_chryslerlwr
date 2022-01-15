
/*****************************************************************************
* Copyright 2010 Nexteer Automotive, All Rights Reserved.
* Nexteer Confidential
*
* Module File Name  : Cd_NvMProxy_PBcfg.h
* Module Description: Configuration of the Cd_NvMProxy BSW
* Product           : Gen II Plus - EA3.0
* Author            : Jeremy Warmbier
*****************************************************************************/
/*---------------------------------------------------------------------------
 * Version Control:
 * Date Created:      Tue Feb  7 11:23:49 2012
 * %version:          EA3#4.1.6 %
 * %derived_by:       gz324f %
 * %date_modified:    Wed Feb  5 13:43:54 2014 % 
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 02/07/12   1        JJW       Initial creation
 * 10/17/12   2        JJW       Generated output file
 * 11/20/12   3        JJW       Removed generation of Block status mirror array.  It is defined in the static SWC
 * 05/30/13   4        JJW       Removed unsuported config feature, added multi-block support
 * 11/21/13   5        LWW       Added Redundant and CRC block checking
 */

#include "Std_Types.h"
#define NVMPROXY_C
#include "Cd_NvMProxy_Cfg.h"
#undef NVMPROXY_C


/* Global data buffers to be used in NvM cfg for Read All destinations */
#define NVMPROXY_START_SEC_VAR_NOINIT_8
#include "MemMap.h"


	
#pragma DATA_ALIGN (NvMP_Rte_MtrPos_MtrPosSnsr_EOLData, 4U);
VAR(uint8, AUTOMATIC) NvMP_Rte_MtrPos_MtrPosSnsr_EOLData[sizeof(Rte_MtrPos_MtrPosSnsr_EOLData)];	
	
#pragma DATA_ALIGN (NvMP_Rte_CmMtrCurr_ShCurrCal, 4U);
VAR(uint8, AUTOMATIC) NvMP_Rte_CmMtrCurr_ShCurrCal[sizeof(Rte_CmMtrCurr_ShCurrCal)];	
	
#pragma DATA_ALIGN (NvMP_Rte_HwTrq_HwTrqScaleData, 4U);
VAR(uint8, AUTOMATIC) NvMP_Rte_HwTrq_HwTrqScaleData[sizeof(Rte_HwTrq_HwTrqScaleData)];	
	
#pragma DATA_ALIGN (NvMP_Rte_HwTrq_HwTrqTrimData, 4U); 
VAR(uint8, AUTOMATIC) NvMP_Rte_HwTrq_HwTrqTrimData[sizeof(Rte_HwTrq_HwTrqTrimData)+D_CRC16SIZE_CNT_U16];	
	
#pragma DATA_ALIGN (NvMP_Rte_HwTrq_EOLTrqStepData, 4U);
VAR(uint8, AUTOMATIC) NvMP_Rte_HwTrq_EOLTrqStepData[sizeof(Rte_HwTrq_EOLTrqStepData)];	
	
#pragma DATA_ALIGN (NvMP_Rte_CurrParamComp_EOLNomMtrParam, 4U);
VAR(uint8, AUTOMATIC) NvMP_Rte_CurrParamComp_EOLNomMtrParam[sizeof(Rte_CurrParamComp_EOLNomMtrParam)];	
	
#pragma DATA_ALIGN (NvMP_Rte_TrqCmdScl_TorqueCmdSF_Uls_f32, 4U);
VAR(uint8, AUTOMATIC) NvMP_Rte_TrqCmdScl_TorqueCmdSF_Uls_f32[sizeof(Rte_TrqCmdScl_TorqueCmdSF_Uls_f32)];	
	
#pragma DATA_ALIGN (NvMP_Rte_Polarity_Polarity_Cnt_Str, 4U);
VAR(uint8, AUTOMATIC) NvMP_Rte_Polarity_Polarity_Cnt_Str[sizeof(Rte_Polarity_Polarity_Cnt_Str)];	
	
	
	
	
	
#pragma DATA_ALIGN (NvMP_Rte_Ap_TrqCanc_CogTrqCal, 4U);
VAR(uint8, AUTOMATIC) NvMP_Rte_Ap_TrqCanc_CogTrqCal[sizeof(Rte_Ap_TrqCanc_CogTrqCal)];	
	
#pragma DATA_ALIGN (NvMP_Rte_BatteryVoltage_OvervoltageData, 4U);
VAR(uint8, AUTOMATIC) NvMP_Rte_BatteryVoltage_OvervoltageData[sizeof(Rte_BatteryVoltage_OvervoltageData)];	
	
#pragma DATA_ALIGN (NvMP_Rte_Ap_TrqCanc_CogTrqRplComp, 4U);
VAR(uint8, AUTOMATIC) NvMP_Rte_Ap_TrqCanc_CogTrqRplComp[sizeof(Rte_Ap_TrqCanc_CogTrqRplComp)];	
	
#pragma DATA_ALIGN (NvMP_Rte_Ap_AstLmt_SteerAsstDefeat, 4U);
VAR(uint8, AUTOMATIC) NvMP_Rte_Ap_AstLmt_SteerAsstDefeat[sizeof(Rte_Ap_AstLmt_SteerAsstDefeat)];	

#define NVMPROXY_STOP_SEC_VAR_NOINIT_8
#include "MemMap.h"

/* Block Test and Copy Configuration */
#define NVMPROXY_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
CONST(NvMProxyCfg_Type, AUTOMATIC) NvMProxyCfg[ D_NUMPRXYBLOCKS_CNT_U16 ] = {
	{0, NULL_PTR,  NULL_PTR, 0, NVMPROXY_NONE, NVMPROXY_NOTAPPLICABLE, NULL_PTR, NULL_PTR}, /* Multi-block fixed config */
	{Rte_NvmBlock_MtrPos_MtrPosSnsr_EOLData, (uint8*)&NvMP_Rte_MtrPos_MtrPosSnsr_EOLData,  (uint8*)&Rte_MtrPos_MtrPosSnsr_EOLData, sizeof(Rte_MtrPos_MtrPosSnsr_EOLData), NVMPROXY_NONE, NVMPROXY_NOTAPPLICABLE, NULL_PTR, NULL_PTR},
	{Rte_NvmBlock_CmMtrCurr_ShCurrCal, (uint8*)&NvMP_Rte_CmMtrCurr_ShCurrCal,  (uint8*)&Rte_CmMtrCurr_ShCurrCal, sizeof(Rte_CmMtrCurr_ShCurrCal), NVMPROXY_NONE, NVMPROXY_NOTAPPLICABLE, NULL_PTR, NULL_PTR},
	{Rte_NvmBlock_HwTrq_HwTrqScaleData, (uint8*)&NvMP_Rte_HwTrq_HwTrqScaleData,  (uint8*)&Rte_HwTrq_HwTrqScaleData, sizeof(Rte_HwTrq_HwTrqScaleData), NVMPROXY_NONE, NVMPROXY_NOTAPPLICABLE, NULL_PTR, NULL_PTR},
	{Rte_NvmBlock_HwTrq_HwTrqTrimData, (uint8*)&NvMP_Rte_HwTrq_HwTrqTrimData,  (uint8*)&Rte_HwTrq_HwTrqTrimData, sizeof(Rte_HwTrq_HwTrqTrimData), NVMPROXY_CRC16, NVMPROXY_NTC_0A, NULL_PTR, NULL_PTR},
	{Rte_NvmBlock_HwTrq_EOLTrqStepData, (uint8*)&NvMP_Rte_HwTrq_EOLTrqStepData,  (uint8*)&Rte_HwTrq_EOLTrqStepData, sizeof(Rte_HwTrq_EOLTrqStepData), NVMPROXY_ZERODATA, NVMPROXY_NOTAPPLICABLE, NULL_PTR, NULL_PTR},
	{Rte_NvmBlock_CurrParamComp_EOLNomMtrParam, (uint8*)&NvMP_Rte_CurrParamComp_EOLNomMtrParam,  (uint8*)&Rte_CurrParamComp_EOLNomMtrParam, sizeof(Rte_CurrParamComp_EOLNomMtrParam), NVMPROXY_NONE, NVMPROXY_NOTAPPLICABLE, NULL_PTR, NULL_PTR},
	{Rte_NvmBlock_TrqCmdScl_TorqueCmdSF_Uls_f32, (uint8*)&NvMP_Rte_TrqCmdScl_TorqueCmdSF_Uls_f32,  (uint8*)&Rte_TrqCmdScl_TorqueCmdSF_Uls_f32, sizeof(Rte_TrqCmdScl_TorqueCmdSF_Uls_f32), NVMPROXY_NONE, NVMPROXY_NOTAPPLICABLE, NULL_PTR, NULL_PTR},
	{Rte_NvmBlock_Polarity_EOLCtrlPolarity, (uint8*)&NvMP_Rte_Polarity_Polarity_Cnt_Str,  (uint8*)&Rte_Polarity_Polarity_Cnt_Str, sizeof(Rte_Polarity_Polarity_Cnt_Str), NVMPROXY_NONE, NVMPROXY_NOTAPPLICABLE, NULL_PTR, NULL_PTR},
	{Rte_NvmBlock_StaMd_CloseCheckData, (uint8*)&CloseCheck_Cnt_u32,  (uint8*)&CloseCheck_Cnt_u32, sizeof(CloseCheck_Cnt_u32), NVMPROXY_NONE, NVMPROXY_NOTAPPLICABLE, NULL_PTR, NULL_PTR},
	{Rte_NvmBlock_StaMd_TypeHRamBuffer, (uint8*)&TypeHData_Cnt_u08,  (uint8*)&TypeHData_Cnt_u08, sizeof(TypeHData_Cnt_u08), NVMPROXY_NONE, NVMPROXY_NOTAPPLICABLE, NULL_PTR, NULL_PTR},
	{Rte_NvmBlock_IPMTrqCanc_CogTrqCal, (uint8*)&NvMP_Rte_Ap_TrqCanc_CogTrqCal,  (uint8*)&Rte_Ap_TrqCanc_CogTrqCal, sizeof(Rte_Ap_TrqCanc_CogTrqCal), NVMPROXY_NONE, NVMPROXY_NOTAPPLICABLE, NULL_PTR, NULL_PTR},
	{Rte_NvmBlock_BatteryVoltage_OvervoltageData, (uint8*)&NvMP_Rte_BatteryVoltage_OvervoltageData,  (uint8*)&Rte_BatteryVoltage_OvervoltageData, sizeof(Rte_BatteryVoltage_OvervoltageData), NVMPROXY_NONE, NVMPROXY_NOTAPPLICABLE, NULL_PTR, NULL_PTR},
	{Rte_NvmBlock_Ap_TrqCanc_CogTrqRplComp, (uint8*)&NvMP_Rte_Ap_TrqCanc_CogTrqRplComp,  (uint8*)&Rte_Ap_TrqCanc_CogTrqRplComp, sizeof(Rte_Ap_TrqCanc_CogTrqRplComp), NVMPROXY_NONE, NVMPROXY_NOTAPPLICABLE, NULL_PTR, NULL_PTR},
	{Rte_NvmBlock_Ap_AstLmt_SteerAsstDefeat, (uint8*)&NvMP_Rte_Ap_AstLmt_SteerAsstDefeat,  (uint8*)&Rte_Ap_AstLmt_SteerAsstDefeat, sizeof(Rte_Ap_AstLmt_SteerAsstDefeat), NVMPROXY_NONE, NVMPROXY_NOTAPPLICABLE, NULL_PTR, NULL_PTR},
};
#define NVMPROXY_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"


