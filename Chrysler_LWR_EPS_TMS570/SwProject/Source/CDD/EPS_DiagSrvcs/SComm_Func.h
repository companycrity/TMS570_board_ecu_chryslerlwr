/*****************************************************************************
* Copyright 2003 Delphi Technologies, Inc., All Rights Reserved.
* Delphi Confidential
*
* Module File Name  : SComm_Func.h
* Module Description: Prototypes for functions used by Serial Communication
*                     Driver
* Product           : Gen II Plus - EA3.0
* Author            : Bobby OSteen
*****************************************************************************/
/* Version Control:
 * Date Created:      Wed Apr 13 12:17:00 2011
 * %version:          2 %
 * %derived_by:       jzh87w %
 * %date_modified:    Tue Dec  4 16:09:21 2012 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 04/13/11  1        LWW       Initial K2xx Synergy Version
 * 07/08/11  2		  SAH		Added WIR functions
 * 08/03/11  3		  SAH		Added Active Pull functions
 * 08/04/11  4		  SAH		Added EOT scom reset function
 * 09/27/11	 5		  SAH		Added NTC parameter read function 
 * 01/25/12	 6		  LWW		Updated datatypes 
 * 02/01/12	 7		  LWW		Added prototypes of new SCom functions
 * 04/18/12	 12		  LWW		Updates for ActivePull Scom Functions
 * 04/19/12	 13		  LWW		Updates for IPM services
 */

#ifndef SCOMM_FUNC_H
#define SCOMM_FUNC_H


#include "fpmtype.h"
#include <Std_Types.h>              /* include AUTOSAR standard types         */
#include "Rte_type.h"
#include "desc.h"



/***** Diagnostic Application ****
extern FUNC(void, EPSDIAGSRVCS_CODE) EPSDiagSrvcs_Init(void); 
extern FUNC(void, EPSDIAGSRVCS_CODE) EPSDiagSrvcs_Task(void); 

extern FUNC(void, EPSDIAGSRVCS_CODE) EPS_DiagSessionChangeIndicator(	CONST(uint8,AUTOMATIC) SesCtrlTypeOld,
   																		CONST(uint8,AUTOMATIC) SesCtrlTypeNew);
extern DescMsg EPSInternalPIDRead(DescMsg pbDiagData, uint16 PID, uint16 diagReqDataLen);
extern void EPSInternalPIDWrite(DescMsg pbDiagData, uint16 PID, uint16 diagReqDataLen);
extern void EPSInternalIOControl(DescMsg pbDiagData, uint16 CPID, uint16 diagReqDataLen);
extern void EPSInternalRoutineControl(DescMsg pbDiagData, uint16 RID, uint16 diagReqDataLen);
extern void EPSInternalRoutineControlType2(DescMsg pbDiagData, uint16 RID, uint16 diagReqDataLen);
extern void EPSInternalRoutineControlType3(DescMsg pbDiagData, uint16 RID, uint16 diagReqDataLen);


/* Diagnostic services to application Scomm functions *
/* MtrTrqLmt *
extern FUNC(Std_ReturnType, RTE_AP_MTRTRQLMT_APPL_CODE) MtrTrqLmt_SCom_ManualTrqCmd(Boolean EnableManualCtrl, Float MtrTrqCmd_MtrNm_f32);
extern FUNC(void, RTE_AP_TRQCMDSCL_APPL_CODE) TrqCmdScl_SCom_Get(P2VAR(Float, AUTOMATIC, RTE_AP_TRQCMDSCL_APPL_VAR) Par_f32);
extern FUNC(void, RTE_AP_TRQCMDSCL_APPL_CODE) TrqCmdScl_SCom_Set(Float Par_f32);
/* HwTrq *
extern FUNC(Std_ReturnType, RTE_SA_HWTRQ_APPL_CODE) HwTrq_SCom_ClrHwTrqScale(void);
extern FUNC(Std_ReturnType, RTE_SA_HWTRQ_APPL_CODE) HwTrq_SCom_ClrHwTrqTrim(void);
extern FUNC(void, RTE_SA_HWTRQ_APPL_CODE) HwTrq_SCom_ReadHwTrqScale(P2VAR(HwTrqScale_Datatype, AUTOMATIC, RTE_SA_HWTRQ_APPL_VAR) HwTrqScaleDataPtr);
extern FUNC(void, RTE_SA_HWTRQ_APPL_CODE) HwTrq_SCom_ReadHwTrqTrim(P2VAR(HwTrqTrim_Datatype, AUTOMATIC, RTE_SA_HWTRQ_APPL_VAR) HwTrqTrimDatPtr);
extern FUNC(Std_ReturnType, RTE_SA_HWTRQ_APPL_CODE) HwTrq_SCom_SetHwTrqScale(Float arg);
extern FUNC(Std_ReturnType, RTE_SA_HWTRQ_APPL_CODE) HwTrq_SCom_SetHwTrqTrim(void);
/* ParameterEst *
//extern FUNC(void, RTE_AP_PARAMCOMP_APPL_CODE) SCom_EOLNomMtrParam_Get(P2VAR(Float, AUTOMATIC, RTE_AP_PARAMCOMP_APPL_VAR) NomKe_VpRadpS_f32, P2VAR(Float, AUTOMATIC, RTE_AP_PARAMCOMP_APPL_VAR) NomL_Henry_f32, P2VAR(Float, AUTOMATIC, RTE_AP_PARAMCOMP_APPL_VAR) NomRmtr_Ohm_f32);
//extern FUNC(void, RTE_AP_PARAMCOMP_APPL_CODE) SCom_EOLNomMtrParam_Set(Float NomKe_VpRadpS_f32, Float NomL_Henry_f32, Float NomRmtr_Ohm_f32);
/* MtrPos *
extern FUNC(void, RTE_SA_MTRPOS_APPL_CODE) MtrPos_SCom_ReadEOLMtrCals(P2VAR(MtrPosCal_DataType, AUTOMATIC, RTE_SA_MTRPOS_APPL_VAR) MtrCalDataPtr);
extern FUNC(void, RTE_SA_MTRPOS_APPL_CODE) MtrPos_SCom_SetEOLMtrCals(P2CONST(MtrPosCal_DataType, AUTOMATIC, RTE_SA_MTRPOS_APPL_DATA) MtrCalDataPtr);
/* Polarity *
extern FUNC(void, RTE_AP_POLARITY_APPL_CODE) Polarity_SCom_ReadPolarity(P2VAR(UInt16, AUTOMATIC, RTE_AP_POLARITY_APPL_VAR) Polarity_Cnt_b16);
extern FUNC(Std_ReturnType, RTE_AP_POLARITY_APPL_CODE) Polarity_SCom_SetPolarity(UInt16 Polarity_Cnt_b16);
/* MtrCurr *
extern FUNC(Std_ReturnType, RTE_SA_MTRCURR_APPL_CODE) MtrCurr_SCom_CalGain(void);
extern FUNC(void, RTE_SA_MTRCURR_APPL_CODE) MtrCurr_SCom_CalOffset(void);
extern FUNC(void, RTE_SA_MTRCURR_APPL_CODE) MtrCurr_SCom_ReadMtrCurrCals(P2VAR(ShCurrCal_DataType, AUTOMATIC, RTE_SA_MTRCURR_APPL_VAR) ShCurrCalPtr);
extern FUNC(void, RTE_SA_MTRCURR_APPL_CODE) MtrCurr_SCom_SetMtrCurrCals(P2CONST(ShCurrCal_DataType, AUTOMATIC, RTE_SA_MTRCURR_APPL_DATA) ShCurrCalPtr);
/* Diagnostic Manager *
extern FUNC(void, RTE_AP_DIAGMGR_APPL_CODE) DiagMgr_SCom_ReadStrgArray(P2VAR(NTCStrgArray, AUTOMATIC, RTE_AP_DIAGMGR_APPL_VAR) NTCStrgArray);
extern FUNC(void, RTE_AP_DIAGMGR_APPL_CODE) DiagMgr_SCom_GetNTCParamByte(NTCNumber NTC, P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGMGR_APPL_VAR) NTCParamByte);
/* WIR *
extern FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_SCom_GetSrlComWIRFltStatus(P2VAR(UInt16, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) SrlComWIRFltStatus);
extern FUNC(void, RTE_AP_WHLIMBREJ_APPL_CODE) WhlImbRej_SCom_GetWIRInfo(P2VAR(WhlImbComp_DataType, AUTOMATIC, RTE_AP_WHLIMBREJ_APPL_VAR) CompData, P2VAR(UInt16, AUTOMATIC, RTE_AP_WHLIMBREJ_APPL_VAR) AlgFltStatus);
/* Active Pull *
extern FUNC(Std_ReturnType, RTE_AP_ACTIVEPULL_APPL_CODE) ActivePull_SCom_Reset(void);
extern FUNC(void, RTE_AP_ACTIVEPULL_APPL_CODE) ActivePull_SCom_SetLTComp(Float LTComp_HwNm_f32);
extern FUNC(void, RTE_AP_ACTIVEPULL_APPL_CODE) ActivePull_SCom_SetSTComp(Float STComp_HwNm_f32);
/* EOT Reset *
extern FUNC(void, RTE_AP_FINALHWPOS_APPL_CODE) FinalHwPos_Scom_ResetEOT(void);
/* Vehicle Speed Manual Override *
extern FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_SCom_ManualVehSpd(Float VehSpd_Kph_f32);
extern FUNC(void, RTE_AP_RETURN_APPL_CODE) Return_SCom_SetEOLRtnRange(Float Par_f32);
extern FUNC(void, RTE_AP_RETURN_APPL_CODE) Return_SCom_GetEOLRtnRange(P2VAR(Float, AUTOMATIC, RTE_AP_RETURN_APPL_VAR) Par_f32);

/* Turns Counter Services *
extern FUNC(void, RTE_AP_ABSHWPOS_APPL_CODE) AbsHwPos_SCom_VehicleSystemStatus(P2VAR(SInt16, AUTOMATIC, RTE_AP_ABSHWPOS_APPL_VAR) NCMAbsHwPos_HwDeg_s11p4);
extern FUNC(void, RTE_AP_LRNEOT_APPL_CODE) LrnEOT_Scom_ResetEOT(void);
extern FUNC(void, RTE_AP_LRNEOT_APPL_CODE) LrnEOT_Scom_ResetRckCntrPrf(void);
extern FUNC(void, RTE_AP_ABSHWPOS_APPL_CODE) AbsHwPos_Scom_ClearCenterPosition(void);
extern FUNC(void, RTE_AP_ABSHWPOS_APPL_CODE) AbsHwPos_Scom_ClearRacktoVehCntrOffset(void);
extern FUNC(void, RTE_AP_ABSHWPOS_APPL_CODE) AbsHwPos_Scom_SetCenterPosition(Float Offset_HwDeg_P_f32);
extern FUNC(void, RTE_CD_TURNSCOUNTER_APPL_CODE) TurnsCntrReset_SCom_SetInputParam(void);

/* Current Mode *
extern FUNC(Std_ReturnType, RTE_SA_CMMTRCURR_APPL_CODE) CmMtrCurr_SCom_CalGain(void);
extern FUNC(Std_ReturnType, RTE_SA_CMMTRCURR_APPL_CODE) CmMtrCurr_SCom_CalOffset(void);
extern FUNC(void, RTE_SA_CMMTRCURR_APPL_CODE) CmMtrCurr_SCom_ReadMtrCurrCals(P2VAR(PhaseCurrCal_DataType, AUTOMATIC, RTE_SA_CMMTRCURR_APPL_VAR) ShCurrCalPtr);
extern FUNC(void, RTE_SA_CMMTRCURR_APPL_CODE) CmMtrCurr_SCom_SetMtrCurrCals(P2CONST(PhaseCurrCal_DataType, AUTOMATIC, RTE_SA_CMMTRCURR_APPL_DATA) ShCurrCalPtr);
extern FUNC(void,AUTOMATIC) CmMtrCurr_SCom_MtrCurrOffReadStatus(P2VAR(MtrCurrOffProcessFlag, AUTOMATIC, AUTOMATIC) TestPtr);

#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
extern FUNC(void, RTE_AP_IPMTRQCANC_APPL_CODE) IPMTrqCanc_Scom_ReadCogTrqCal(P2VAR(UInt16, AUTOMATIC, RTE_AP_IPMTRQCANC_APPL_VAR) CogTrqCalPtr, UInt16 ID);
#else
extern FUNC(void, RTE_AP_IPMTRQCANC_APPL_CODE) IPMTrqCanc_Scom_ReadCogTrqCal(P2VAR(IPMCoggingCancTrq, AUTOMATIC, RTE_AP_IPMTRQCANC_APPL_VAR) CogTrqCalPtr, UInt16 ID);
#endif

#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
extern FUNC(void, RTE_AP_IPMTRQCANC_APPL_CODE) IPMTrqCanc_Scom_SetCogTrqCal(P2CONST(UInt16, AUTOMATIC, RTE_AP_IPMTRQCANC_APPL_DATA) CogTrqCalPtr, UInt16 ID)
#else
extern FUNC(void, RTE_AP_IPMTRQCANC_APPL_CODE) IPMTrqCanc_Scom_SetCogTrqCal(P2CONST(IPMCoggingCancTrq, AUTOMATIC, RTE_AP_IPMTRQCANC_APPL_DATA) CogTrqCalPtr, UInt16 ID);
#endif

#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
extern FUNC(void, RTE_AP_IPMTRQCANC_APPL_CODE) IPMTrqCanc_Scom_SetCogTrqCal(P2CONST(UInt16, AUTOMATIC, RTE_AP_IPMTRQCANC_APPL_DATA) CogTrqCalPtr, UInt16 ID);
#else
extern FUNC(void, RTE_AP_IPMTRQCANC_APPL_CODE) IPMTrqCanc_Scom_SetCogTrqCal(P2CONST(IPMCoggingCancTrq, AUTOMATIC, RTE_AP_IPMTRQCANC_APPL_DATA) CogTrqCalPtr, UInt16 ID);
#endif

extern FUNC(void, RTE_AP_CURRPARAMCOMP_APPL_CODE) SCom_EOLNomMtrParam_Get(P2VAR(Float, AUTOMATIC, RTE_AP_CURRPARAMCOMP_APPL_VAR) NomKe_VpRadpS_f32, P2VAR(Float, AUTOMATIC, RTE_AP_CURRPARAMCOMP_APPL_VAR) NomLq_Henry_f32, P2VAR(Float, AUTOMATIC, RTE_AP_CURRPARAMCOMP_APPL_VAR) NomRmtr_Ohm_f32, P2VAR(Float, AUTOMATIC, RTE_AP_CURRPARAMCOMP_APPL_VAR) NomLd_Henry_f32);
extern FUNC(void, RTE_AP_CURRPARAMCOMP_APPL_CODE) SCom_EOLNomMtrParam_Set(Float NomKe_VpRadpS_f32, Float NomLq_Henry_f32, Float NomRmtr_Ohm_f32, Float NomLd_Henry_f32);

*/
#endif


