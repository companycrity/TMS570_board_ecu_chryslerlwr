/*****************************************************************************
* Copyright 2010 Nexteer Automotive, All Rights Reserved.
* Nexteer Confidential
*
* Module File Name  : NtWrap.h
* Module Description: Non-trusted function call wrapper definitions to allow
*						calling of SCom server functions not located in the
*						application with the Diag service handler.
* Product           : Gen II Plus - EA3.0
* Author            : Jeremy Warmbier
*****************************************************************************/
/* Version Control:
 * Date Created:      Fri Jul 13 18:34:17 2012
 * %version:          EA3#3.1.2 %
 * %date_modified:    Thu Jan 30 12:42:04 2014 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 07/08/13   1       JJW       Initial creation
 * 07/10/13   2       JJW       Added missing function definitions
 * 07/19/13   3       JJW       Anomaly corrections and updates per the SwArch design
 * 01/18/14   4       SAH       Changed polarity to 8 bit parameter
 */

#ifndef NTWRAP_H
#define NTWRAP_H

#include "Std_Types.h"
#include "Rte_Type.h"
#include "WdgM.h"
#include "Wdg_TMS570LS3x.h"

FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_Adc_Init();
FUNC(Std_ReturnType, RTE_NTWRAP_APPL_CODE) NtWrapC_AstLmt_Scom_ManualTrqCmd(Boolean EnableManualCtrl, Float MtrTrqCmd_MtrNm_f32);
FUNC(Std_ReturnType, NTWRAP_CODE) NtWrapC_HwTrq_SCom_ClrHwTrqScale(void);
FUNC(Std_ReturnType, NTWRAP_CODE) NtWrapC_HwTrq_SCom_ClrHwTrqTrim(void);
FUNC(Std_ReturnType, NTWRAP_CODE) NtWrapC_HwTrq_SCom_ManualSetHwTrqTrim(P2CONST(HwTrqTrim_Datatype, AUTOMATIC, RTE_SA_HWTRQ_APPL_DATA) HwTrqTrimDataPtr);
FUNC(void, NTWRAP_CODE) NtWrapC_HwTrq_SCom_SetEOLTrqStep(P2CONST(EOLTrqStepType, AUTOMATIC, RTE_SA_HWTRQ_APPL_DATA) TrqStep_HwNm_T_f32);
FUNC(Std_ReturnType, NTWRAP_CODE) NtWrapC_HwTrq_SCom_SetHwTrqScale(Float ScaleValue);
FUNC(Std_ReturnType, NTWRAP_CODE) NtWrapC_HwTrq_SCom_SetHwTrqTrim(void);
FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_MtrPos_SCom_SetEOLMtrCals(P2CONST(MtrPosCal_DataType, AUTOMATIC, RTE_NTWRAP_APPL_DATA) MtrCalDataPtr);
FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_Polarity_SCom_SetPolarity(UInt8 Polarity_Cnt_T_b08);
FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_SCom_EOLNomMtrParam_Set(Float NomKe_VpRadpS_f32, Float NomRmtr_Ohm_f32);
FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_StaMd_SCom_EcuReset(void);
FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_TrqCmdScl_SCom_Set(Float Par_f32);
FUNC(Std_ReturnType, NTWRAP_CODE) NtWrapC_CmMtrCurr_SCom_CalGain(void);
FUNC(Std_ReturnType, RTE_NTWRAP_APPL_CODE) NtWrapC_CmMtrCurr_SCom_CalOffset(void);
FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_CmMtrCurr_SCom_SetMtrCurrCals(P2CONST(PhaseCurrCal_DataType, AUTOMATIC, RTE_NTWRAP_APPL_DATA) ShCurrCalPtr);
FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_AbsHwPosScom_Scom_HwPosSrvSetToZero(Boolean Par);
FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_TrqCanc_Scom_SetCogTrqCal(P2CONST(CoggingCancTrq, AUTOMATIC, RTE_NTWRAP_APPL_DATA) CogTrqCalPtr, UInt16 ID);

FUNC(void, NTWRAP_CODE) NONTRUSTED_NtWrapS_XcpWriteAp8(NonTrustedFunctionIndexType index, NonTrustedFunctionParameterRefType par);
FUNC(void, NTWRAP_CODE) NONTRUSTED_NtWrapS_XcpWriteAp9(NonTrustedFunctionIndexType index, NonTrustedFunctionParameterRefType par);
FUNC(void, NTWRAP_CODE) NONTRUSTED_NtWrapS_XcpWriteAp10(NonTrustedFunctionIndexType index, NonTrustedFunctionParameterRefType par);

FUNC(void, NTWRAP_CODE) TRUSTED_TWrapS_XcpWriteAp0(TrustedFunctionIndexType index, TrustedFunctionParameterRefType FunctionParams);

/* Non-Rte external function Trusted function entry points */
void Call_Adc2_Init1(void);
void Call_NvMProxy_Init(void);
void Call_Rte_Start(void);
void Call_StaMd_Init1(void);
void Call_PwmCdd_Init(void);
Std_ReturnType NtWrapC_Wdg_TMS570LS3x_Init(P2CONST(Wdg_TMS570LS3x_ConfigType, AUTOMATIC, WDG_APPL_CONST) ConfigPtr);
void NtWrapC_WdgM_Init(P2CONST (WdgM_ConfigType, AUTOMATIC, WDGM_APPL_CONST) WdgMConfigPtr);
void Call_ProcessF0FF(P2VAR(uint8, AUTOMATIC, AUTOMATIC) t_SrvcData_Cnt_T_u08, VAR(uint16, AUTOMATIC) RequestDataIdx_Cnt_T_u16);


/*** Private Part (NtWrap Internal) *************************************/
#ifdef NTWRAP_C

#define		NTWRAP_DEV_ERROR_DETECT					STD_ON /* TODO: move NTWRAP_DEV_ERROR_DETECT to a cfg file */

#define 	NtWrap_ReportDet( errorId )				Det_ReportError( 0u /*ModuleId*/, 0u /*InstanceId*/, 0u /*ApiId*/, errorId )
#define		D_NTWRAPINVLDINDXDET_CNT_U08			0x00U

#endif


#endif
