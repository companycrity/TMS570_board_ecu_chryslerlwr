/*****************************************************************************
* Copyright 2010 Nexteer Automotive, All Rights Reserved.
* Nexteer Confidential
*
* Module File Name  : EPS_DiagSrvcs_ISO.Interface.h file
* Module Description: Common Manufacturing Program Interface for XCP and ISO services
* Product           : Gen II Plus - EA3.0
* Author            : Kevin Smith
*
* Notes:
* This file contains the configurations for the ISO services. It should be
* modified for each program as needed.
*
*****************************************************************************/
/* Version Control:
 * Date Created:      Mon Apr 12 10:20:00 2012
 * %version:          7 %
 * %derived_by:       jzh87w %
 * %date_modified:    Mon Mar  3 16:02:20 2014 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 07/31/12 	1		KS		Initial Component Release
 * 08/31/12 	2		SAH		Updates for anomaly 3655, reading NTcs
 * 09/18/12		3		SAH		Enabled service FD0D which is now in AstLmt component.
 * 09/18/12		4		SAH		Enabled service FD0D which is now in AstLmt component.
 * 10/10/12		5		SAH		Updated service FD01 to report out Bootloader rel number.
 * 10/10/12		6		SAH		Added lnk_symbols header
 * 12/06/12		7		SAH		Updates for new diagmgr
 * 12/17/12 	9		SAH		Variable update for new MtrVel component
 * 12/20/12 	10		SAH		Variable update for SignCondn(vehspd) component
 * 01/25/13 	11		SAH		Variable update for MtrTqCmdCRF name change
 * 05/13/13 	12		SAH		Variable name update for MtrlCtrl version 8 integration
 * 05/20/13 	13		SAH		Added CM_EnableTestMode
 * 06/18/13 	14		SAH		Updates for new CMS version 2.0 generation
 * 07/09/13 	15		JJW		F0FF service support changes for integration of ApXcp component
 * 07/12/13		16		Jared	Disabled PID 0000 for anomaly 5221												9035
 * 07/12513		17		SAH		Added trusted function calls
 * 07/23/13		19		JJW		Changed to NtWrapC_AstLmt_Scom_ManualTrqCmd
 * 08/08/13		20		SAH		Added AvgFricLrn Scomm functions
 * 10/15/13		22		SAH		Updates for XCP PID variable names
 * 11/12/13		23		SAH		Updates for XCP PID variable names
 * 01/18/14		2		SAH		Updated to CMS version 06B.3
 * 03/03/14		7		SAH		Updated to CMS version 07A.3
 */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include area >>		                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "EPS_DiagSrvcs_CommonData.h"
#include "EPS_DiagSrvcs_SrvcLUTbl.h"

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include area >>   		      		    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#ifndef EPS_DIAGSRVCS_ISO_INTERFACE_H
#define EPS_DIAGSRVCS_ISO_INTERFACE_H

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of custom include area >>	                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "CalConstants.h"
#include "desc.h"					/* Required for interfacing with the CAN transport layer */
#include "trustfct.h" /* Os Trusted Function call definitions */
#include "Lnk_Symbols.h"
#include "Frfm.h"
#include "Ap_DiagMgr.h"
#include "NtWrap.h"
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of custom include area >>	                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of custom define area >>   		  	    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/* --- Common Defines --- */
#define CM_DIAGBUFFLEN_CNT_U16                      kDescPrimBufferLen
#define NEXTEER_SESSION								kDescStateSessionNexteer_Mode
#define CM_NumLIDHeaderBytes_Cnt_u16				CDD_DiagSrvcsUnusedVar_Cnt_M_u16
#define CM_MsgBufferType							DescMsg
#define CM_MsgLenType								DescMsgLen
#define CM_Std_ReturnType							Std_ReturnType
#define CM_RESP_OK									RTE_E_OK

/* No Error Response (Positive Codes) */
#define D_EPSNRCNOERROR_CNT_U8					kDescNrcNone

/* offsets for the data buffers for diag request/responses */
#define CM_NULL								0x00
#define D_ALLDTC_MASK_CNT_U32 				0xFFFFFFU
#define CM_RTE_MODE_StaMd_Mode_OPERATE		RTE_MODE_StaMd_Mode_OPERATE
#define D_REQMSG_IOC_OFFSET_CNT_U16			0U
#define D_REQMSG_RESET_OFFSET_CNT_U16		0U
#define D_RESPMSG_OFFSET_CNT_U16			0U

#define D_PIDREAD_OFFSET_CNT_U16			0U
#define D_RETURNDATA_OFFSET_CNT_U16			0U
#define D_REQUESTDATA_OFFSET_CNT_U16		0U

/* Negative Response Codes */
#define D_EPSNRCNOTNEXTEERPROD_CNT_U08    D_EPSNRCREQOUTOFRANGE_CNT_U08
#define D_EPSNRCSERVICEMISSING_CNT_U08    D_EPSNRCREQOUTOFRANGE_CNT_U08

#define CM_GetCurrentDiagnosticMode(mode) (*mode = DescGetStateSession())

/**********************************************************************************************************************
 * --- RTE GLOBAL DATA START ---
 *
 * This section is for variables that are external references to RTE variables. (Formally found in the RTE_GlobalData.h)
 *
 *********************************************************************************************************************/
/* System State*/
extern VAR(Rte_ModeType_StaMd_Mode, RTE_VAR_NOINIT) Rte_ModeMachine_StaMd_SystemState_Mode;
/* Battery Voltage */
extern VAR(Float, RTE_VAR_NOINIT) Rte_BatteryVoltage_Vecu_Volt_f32;
/* T1 Voltage */
extern VAR(Float, RTE_VAR_NOINIT) Rte_IoHwAbstractionUsr_T1ADC_Volt_f32;
/* T2 Voltage */
extern VAR(Float, RTE_VAR_NOINIT) Rte_IoHwAbstractionUsr_T2ADC_Volt_f32;
/* Hw Trq */
extern VAR(Float, RTE_VAR_NOINIT) Rte_HwTrq_AnaHwTorque_HwNm_f32;
/* Final Handwheel Position */
extern VAR(Float, RTE_VAR_INIT) Rte_Ap_AbsHwPosScom_HwPos_HwDeg_f32;
/* Motor Trq Limit */
extern VAR(Float, RTE_VAR_NOINIT) Rte_CtrldDisShtdn_CntDisMtrTrqCmdMRF_MtrNm_f32;
/* Cumulative Motor Position */
extern VAR(Float, RTE_VAR_NOINIT) Rte_MtrPos_CumMtrPosMRF_Deg_f32;
/* Motor Velocity MRF Cord */
extern VAR(Float, RTE_VAR_NOINIT) Rte_MtrVel_MRFMotorVel_MtrRadpS_f32;
/* Vehicle Speed */
extern VAR(Float, RTE_VAR_NOINIT) Rte_Ap_SignlCondn_VehicleSpeed_Kph_f32;
/* Vehicle Speed Override */
extern VAR(uint16, EPSDIAGSRVCS_VAR) EpsDiagSrvc_VehSpdOverride_Kph_M_u16p0;
/* Default Vehicle Speed */
extern VAR(Boolean, RTE_VAR_INIT) Rte_DiagMgr_DiagStsDefVehSpd_Cnt_lgc;
/* Digital (PWM) T1 Duty Cycle */
extern VAR(Float, RTE_VAR_INIT) Rte_IoHwAbstractionUsr_T1Duty_Uls_f32;
/* Digital (PWM) T1 Volt */
extern VAR(Float, RTE_VAR_INIT) Rte_IoHwAbstractionUsr_T1ADC_Volt_f32;
/* Digital (PWM) T2 Duty Cycle */
extern VAR(Float, RTE_VAR_INIT) Rte_IoHwAbstractionUsr_T2Duty_Uls_f32;
/* Digital (PWM) T2 Volt */
extern VAR(Float, RTE_VAR_INIT) Rte_IoHwAbstractionUsr_T2ADC_Volt_f32;
/* digital Hw Trq */
extern VAR(Float, RTE_VAR_INIT) Rte_DigHwTrq_DigHwTrq_HwNm_f32;
/* Tbar Stiffness */
extern CONST(float32, CAL_CONST) k_TbarStiff_NmpDeg_f32;
/* Hw Trq Scale Analog */
extern CONST(float32, CAL_CONST) k_HwTrqSclNom_VoltspDeg_f32;
/* Hw Trq Scale Digital */
extern CONST(float32, CAL_CONST) k_DigHwTrqSensScaleNom_VoltspDeg_f32;
/* T1 Trim Volts Analog, T2 Trim Volts Analog, HwTrqTrim Volts Analog*/
extern VAR(HwTrqTrim_Datatype, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_HwTrq_HwTrqTrimData;
/* T1 Trim Volts Digital, T2 Trim Volts Digital, HwTrqTrim Volts Digital*/
extern VAR(HwTrqTrim_Datatype, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_DigHwTrq_DigTrqTrim;
/* ECU Controller Temp */
extern VAR(Float, RTE_VAR_INIT) Rte_CtrlTemp_FiltMeasTemp_DegC_f32;
/* Sin1 Amp */
extern VAR(Float, RTE_VAR_INIT) Rte_Sa_MtrPos2_SinTheta1_Volt_f32;
/* Cos 1 Amp */
extern VAR(Float, RTE_VAR_INIT) Rte_Sa_MtrPos2_CosTheta1_Volt_f32;
/* Est QAX Current */
extern VAR(Float, RTE_VAR_INIT) Rte_ParamComp_ExpIq_Amp_f32;
/* Modulation Index */
extern VAR(Float, RTE_VAR_INIT) Rte_CDDInterface_ModIdxFinal_Uls_f32;
/* Controller Temp (ADC Volts) */
extern VAR(Float, RTE_VAR_INIT) Rte_IoHwAbstractionUsr_TemperatureADC_Volt_f32;
/* Mag Temp Estimation */
extern VAR(Float, RTE_VAR_INIT) Rte_Ap_MtrTempEst_MagTempEst_DegC_f32;

/* Used in other services, such as appdesc */
extern VAR(Boolean, RTE_VAR_NOINIT) Rte_SrlComInput_SrlComEngOn_Cnt_lgc;
/* Constant to allow use of F0FF */
extern volatile CONST(boolean, AUTOMATIC) EnableTestMode_Cnt_lgc;

/* NvM RAM locations for customer specific services */
extern VAR(uint8, NVM_APPL_DATA) Nvm_DataUnivNumSysID_Cnt_u8[9];

/* Defines for global RTE data */
#define CM_HwTrq_HwNm_f32							Rte_HwTrq_AnaHwTorque_HwNm_f32
#define CM_DiagStsDefVehSpd_Cnt_lgc					Rte_DiagMgr_DiagStsDefVehSpd_Cnt_lgc
#define CM_VehicleSpeed_Kph_f32						Rte_Ap_SignlCondn_VehicleSpeed_Kph_f32

/* Defines for calibrations */
#define CM_k_TrimHwTrqLimit_HwNm_f32	k_SrvcHwTrqLimit_HwNm_f32
#define CM_k_TrimVehSpdLimit_Kph_f32	k_SrvcVehSpdLimit_Kph_f32

/**********************************************************************************************************************
 * --- RTE GLOBAL DATA END ---
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * --- SERIAL COMM FUNCTION START ---
 *
 * This section is for functions that are external references to system functions. (Formally found in the SComm_Func.h)
 *
 *********************************************************************************************************************/

/* 0x22 and 0x2E Services */
extern FUNC(void, RTE_AP_RETURN_APPL_CODE) Return_SCom_GetEOLRtnRange(P2VAR(Float, AUTOMATIC, RTE_AP_RETURN_APPL_VAR) Par_f32);
extern FUNC(void, RTE_AP_RETURN_APPL_CODE) Return_SCom_SetEOLRtnRange(Float Par_f32);
extern FUNC(void, RTE_AP_PARAMCOMP_APPL_CODE) SCom_KeIntgSVParam_Get(P2VAR(Float, AUTOMATIC, RTE_AP_PARAMCOMP_APPL_VAR) KeIntgSV_Amp_f32);
extern FUNC(void, RTE_AP_PARAMCOMP_APPL_CODE) SCom_KeIntgSVParam_Set(Float KeIntgSV_Amp_f32);
extern FUNC(void, RTE_AP_PARAMCOMP_APPL_CODE) SCom_RIntgSVParam_Get(P2VAR(Float, AUTOMATIC, RTE_AP_PARAMCOMP_APPL_VAR) RIntgSV_Amp_f32);
extern FUNC(void, RTE_AP_PARAMCOMP_APPL_CODE) SCom_RIntgSVParam_Set(Float RIntgSV_Amp_f32);
extern FUNC(Std_ReturnType, RTE_IOHWABSTRACTIONUSR_APPL_CODE) IoHwAb_InputT1_V_f32(P2VAR(Float, AUTOMATIC, RTE_IOHWABSTRACTIONUSR_APPL_VAR) signal);
extern FUNC(Std_ReturnType, RTE_IOHWABSTRACTIONUSR_APPL_CODE) IoHwAb_InputT2_V_f32(P2VAR(Float, AUTOMATIC, RTE_IOHWABSTRACTIONUSR_APPL_VAR) signal);
extern FUNC(void, RTE_AP_ABSHWPOSSCOM_APPL_CODE) AbsHwPosScom_Scom_HwPosSrvRead(P2VAR(Boolean, AUTOMATIC, RTE_AP_ABSHWPOSSCOM_APPL_VAR) Par);
extern FUNC(void, INTERRUPT_CODE) EnableSysTickInterrupt(void);
extern FUNC(void, INTERRUPT_CODE) DisableSysTickInterrupt(void);

/* 0x31 Services */
extern t_FrfmReturnCode FrfmClearDTC(t_FrfmDtcNumType reqDtcCode, t_FrfmDTCOrigin dtcOrigin);

/* Defines for global services */
#define CM_DiagMgr_SCom_ClearBlackBox	DiagMgr_SCom_ClearBlackBox

/* 1160 */
extern FUNC(void, RTE_AP_STAMD_APPL_CODE) StaMd_SCom_EcuReset(void);

/* F000, F007 */
extern FUNC(void, RTE_AP_LRNEOT_APPL_CODE) LrnEOT_Scom_ResetEOT(void);

/* F000, F001 */
extern FUNC(void, RTE_AP_DIAGMGR_APPL_CODE) DiagMgr_SCom_ResetNTCStatus(void);

/* F000, FDB6 */
extern FUNC(void, RTE_AP_ACTIVEPULL_APPL_CODE) ActivePull_SCom_SetLTComp(Float LTComp_HwNm_f32);

/* F000 */
extern FUNC(void, RTE_AP_AVGFRICLRN_APPL_CODE) AvgFricLrn_SCom_ResetToZero(void);
extern FUNC(void, RTE_AP_AVGFRICLRN_APPL_CODE) AvgFricLrn_SCom_InitLearnedTables(void);
extern FUNC(void, RTE_AP_BATTERYVOLTAGE_APPL_CODE) BatteryVoltage_SCom_ClearTransOvData(void);

/* F002 */
extern FUNC(Std_ReturnType, RTE_SA_HWTRQ_APPL_CODE) HwTrq_SCom_SetHwTrqTrim(void);
extern FUNC(Std_ReturnType, RTE_SA_HWTRQ_APPL_CODE) HwTrq_SCom_ClrHwTrqTrim(void);
extern FUNC(Std_ReturnType, RTE_SA_HWTRQ_APPL_CODE) HwTrq_SCom_ClrHwTrqScale(void);

/* F005 */
extern FUNC(void, RTE_AP_DIAGMGR_APPL_CODE) DiagMgr_SCom_GetNTCInfo(VAR(NTCNumber, AUTOMATIC) NTC_Cnt_T_enum, P2VAR(uint8, AUTOMATIC, AUTOMATIC) Param_Ptr_T_u08, P2VAR(uint8, AUTOMATIC, AUTOMATIC) Status_Ptr_T_u08, P2VAR(uint8, AUTOMATIC, AUTOMATIC) AgingCounter_Ptr_T_u08);

/* F008 */
extern FUNC(Std_ReturnType, RTE_SA_HWTRQ_APPL_CODE) CmMtrCurr_SCom_CalGain(void);

/* F009 */
extern FUNC(void, RTE_SA_CMMTRCURR_APPL_CODE) CmMtrCurr_SCom_MtrCurrOffReadStatus(P2VAR(MtrCurrOffProcessFlag, AUTOMATIC, RTE_SA_CMMTRCURR_APPL_VAR) CurrOffStatus);
extern FUNC(Std_ReturnType, RTE_SA_CMMTRCURR_APPL_CODE) CmMtrCurr_SCom_CalOffset(void);

/* FD01 */
extern CONST(uint8, AUTOMATIC) Lnk_BootRelNum_Addr;

/* FD02 */
extern VAR(uint32,  CDD_VAR_NOINIT) CDD_EOLSrlComSvcDft_Cnt_G_b32;

/* FD04 */
extern FUNC(void, RTE_SA_MTRPOS_APPL_CODE) MtrPos_SCom_ReadEOLMtrCals(P2VAR(MtrPosCal_DataType, AUTOMATIC, RTE_SA_MTRPOS_APPL_VAR) MtrCalDataPtr);
extern FUNC(void, RTE_SA_MTRPOS_APPL_CODE) MtrPos_SCom_SetEOLMtrCals(P2CONST(MtrPosCal_DataType, AUTOMATIC, RTE_SA_MTRPOS_APPL_DATA) MtrCalDataPtr);

/* FD05 */
extern FUNC(Std_ReturnType, RTE_SA_HWTRQ_APPL_CODE) HwTrq_SCom_ManualSetHwTrqTrim(P2CONST(HwTrqTrim_Datatype, AUTOMATIC, RTE_SA_HWTRQ_APPL_DATA) HwTrqTrimDataPtr);
extern FUNC(void, RTE_SA_HWTRQ_APPL_CODE) HwTrq_SCom_ReadHwTrqTrim(P2VAR(HwTrqTrim_Datatype, AUTOMATIC, RTE_SA_HWTRQ_APPL_VAR) HwTrqTrimDatPtr);

/* FD07 */
extern FUNC(void, RTE_AP_POLARITY_APPL_CODE) Polarity_SCom_ReadPolarity(P2VAR(UInt8, AUTOMATIC, RTE_AP_POLARITY_APPL_VAR) Polarity_Ptr_T_b08);
extern FUNC(void, RTE_AP_POLARITY_APPL_CODE) Polarity_SCom_SetPolarity(UInt8 Polarity_Cnt_T_b08);

/* FD08 */
extern FUNC(void, RTE_SA_HWTRQ_APPL_CODE) HwTrq_SCom_ReadHwTrqScale(P2VAR(HwTrqScale_Datatype, AUTOMATIC, RTE_SA_HWTRQ_APPL_VAR) HwTrqScaleDataPtr);
extern FUNC(Std_ReturnType, RTE_SA_HWTRQ_APPL_CODE) HwTrq_SCom_SetHwTrqScale(Float ScaleValue);

/* FD0D */
extern FUNC(Std_ReturnType, RTE_AP_ASTLMT_APPL_CODE) AstLmt_Scom_ManualTrqCmd(Boolean EnableManualCtrl, Float MtrTrqCmd_MtrNm_f32);

/* FD11 */
extern VAR(boolean, CDD_VAR_NOINIT) CDD_DftAsstTbl_Cnt_G_lgc;
extern VAR(float32, CDD_VAR_NOINIT) CDD_DwnldAsstGain_Uls_G_f32;

/* FD12 */
extern FUNC(void, RTE_SA_CMMTRCURR_APPL_CODE) CmMtrCurr_SCom_ReadMtrCurrCals(P2VAR(PhaseCurrCal_DataType, AUTOMATIC, RTE_SA_CMMTRCURR_APPL_VAR) ShCurrCalPtr);
extern FUNC(void, RTE_SA_CMMTRCURR_APPL_CODE) CmMtrCurr_SCom_SetMtrCurrCals(P2CONST(PhaseCurrCal_DataType, AUTOMATIC, RTE_SA_CMMTRCURR_APPL_DATA) ShCurrCalPtr);

/* FD13 */
extern FUNC(void, RTE_AP_DIAGMGR_APPL_CODE) DiagMgr_SCom_ReadStrgArray(void);
extern FUNC(void, RTE_AP_DIAGMGR_APPL_CODE) DiagMgr_SCom_GetNTCParamByte(NTCNumber NTC, P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGMGR_APPL_VAR) NTCParamByte);
extern VAR(NTCStrgArray, NVM_APPL_DATA) NTCStrgArray_Cnt_str;

/* FD1B */
extern FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_SCom_ManualVehSpd(Float VehSpd_Kph_f32);

/* FD20 */
extern FUNC(void, RTE_AP_BATTERYVOLTAGE_APPL_CODE) BatteryVoltage_SCom_ReadTransOvData(P2VAR(UInt16, AUTOMATIC, RTE_AP_BATTERYVOLTAGE_APPL_VAR) OvervoltageCounter_Cnt_u16, P2VAR(Float, AUTOMATIC, RTE_AP_BATTERYVOLTAGE_APPL_VAR) MaxBattVoltage_Volts_f32);

/* FD23 */
/* See CDD_Data.h for extern:  extern VAR(EnergyModeStateType, RTE_VAR_INIT) CDD_EnergyModeState_Cnt_G_enum; */
#define CMS_SetOperatingMode(arg)	(CDD_EnergyModeState_Cnt_G_enum = (arg))

/* FD25 */
extern FUNC(void, RTE_AP_TRQCMDSCL_APPL_CODE) TrqCmdScl_SCom_Get(P2VAR(Float, AUTOMATIC, RTE_AP_TRQCMDSCL_APPL_VAR) Par_f32);
extern FUNC(void, RTE_AP_TRQCMDSCL_APPL_CODE) TrqCmdScl_SCom_Set(Float Par_f32);

/* FD26 */
extern FUNC(void, RTE_AP_AVGFRICLRN_APPL_CODE) AvgFricLrn_SCom_SetSelect(Boolean EnableFricLearning_Cnt_lgc, Boolean EnableOffsetOutput_Cnt_lgc, UInt8 OpMode_Uls_u08);
extern FUNC(void, RTE_AP_AVGFRICLRN_APPL_CODE) AvgFricLrn_SCom_GetSelect(P2VAR(Boolean, AUTOMATIC, RTE_AP_AVGFRICLRN_APPL_VAR) EnableFricLearning_Cnt_lgc, P2VAR(Boolean, AUTOMATIC, RTE_AP_AVGFRICLRN_APPL_VAR) EnableOffsetOutput_Cnt_lgc, P2VAR(UInt8, AUTOMATIC, RTE_AP_AVGFRICLRN_APPL_VAR) OpMode_Uls_u08);

/* FD27 */
extern FUNC(void, RTE_AP_AVGFRICLRN_APPL_CODE) AvgFricLrn_SCom_SetOffsetOutputDefeat(Boolean DefeatOffsetOutput_Cnt_lgc);
extern FUNC(void, RTE_AP_AVGFRICLRN_APPL_CODE) AvgFricLrn_SCom_GetOffsetOutputDefeat(P2VAR(Boolean, AUTOMATIC, RTE_AP_AVGFRICLRN_APPL_VAR) DefeatOffsetOutput_Cnt_lgc);

/* FD29 */
extern FUNC(void, RTE_AP_AVGFRICLRN_APPL_CODE) AvgFricLrn_SCom_SetEOLFric(Float EOLFric_HwNm_f32);
extern FUNC(void, RTE_AP_AVGFRICLRN_APPL_CODE) AvgFricLrn_SCom_GetEOLFric(P2VAR(Float, AUTOMATIC, RTE_AP_AVGFRICLRN_APPL_VAR) EOLFric_HwNm_f32);

/* FDAD */
extern FUNC(void, RTE_AP_ACTIVEPULL_APPL_CODE) ActivePull_SCom_ReadParam(P2VAR(Float, AUTOMATIC, RTE_AP_ACTIVEPULL_APPL_VAR) PullCompCmd_HwNm_f32, P2VAR(Float, AUTOMATIC, RTE_AP_ACTIVEPULL_APPL_VAR) STComp_HwNm_f32, P2VAR(Float, AUTOMATIC, RTE_AP_ACTIVEPULL_APPL_VAR) LTComp_HwNm_f32, P2VAR(Boolean, AUTOMATIC, RTE_AP_ACTIVEPULL_APPL_VAR) EnableLearn_Cnt_lgc);

/* FDAF */
extern VAR(NTCBlkBoxData, NVM_APPL_DATA) NTCBlackBoxData_Cnt_str;

/* FDB0 */
extern FUNC(void, RTE_AP_TRQCANC_APPL_CODE) TrqCanc_Scom_SetCogTrqCal(P2CONST(IPMCoggingCancTrq, AUTOMATIC, RTE_AP_TRQCANC_APPL_DATA) CogTrqCalPtr, UInt16 ID);
extern FUNC(void, RTE_AP_TRQCANC_APPL_CODE) TrqCanc_Scom_ReadCogTrqCal(P2VAR(IPMCoggingCancTrq, AUTOMATIC, RTE_AP_TRQCANC_APPL_VAR) CogTrqCalPtr, UInt16 ID);

/* FDB4 */
extern FUNC(void, RTE_AP_CURRPARAMCOMP_APPL_CODE) SCom_EOLNomMtrParam_Get(P2VAR(Float, AUTOMATIC, RTE_AP_CURRPARAMCOMP_APPL_VAR) NomKe_VpRadpS_f32, P2VAR(Float, AUTOMATIC, RTE_AP_CURRPARAMCOMP_APPL_VAR) NomRmtr_Ohm_f32);
extern FUNC(void, RTE_AP_CURRPARAMCOMP_APPL_CODE) SCom_EOLNomMtrParam_Set(Float NomKe_VpRadpS_f32, Float NomRmtr_Ohm_f32);

/* FDB5 */
extern FUNC(void, RTE_AP_ACTIVEPULL_APPL_CODE) ActivePull_SCom_SetSTComp(Float STComp_HwNm_f32);

/**********************************************************************************************************************
 * --- SERIAL COMM FUNCTION END ---
 *********************************************************************************************************************/

/* --- Common Manufacturing Services Selection ---
 * This block of defines control which services are to be included for the program at the time of build.
 * Unused or not defined services should be set to D_DIAGSRVC_DISABLED.
 */
/****************************** BEGIN CMS GENERATION - DO NOT CHANGE/REMOVE THIS COMMENT ******************************/
#define D_EPSDIAGSRVPID0000_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVXCP0001_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP0002_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP0003_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP0004_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP0005_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP0006_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP0007_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP0008_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP0009_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP000A_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP000B_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP000C_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP000D_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP000E_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP000F_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP0010_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP0011_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP0012_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP0013_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP0014_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVXCP0015_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVXCP0016_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVXCP0017_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVXCP0018_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVXCP0019_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP001A_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP001B_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVXCP001C_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP001D_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP001E_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP001F_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVXCP0020_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVXCP0021_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVXCP0022_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP0023_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP0024_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP0025_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP0026_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVXCP0027_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP0028_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP0029_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP002A_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVXCP002B_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVXCP002C_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVXCP002D_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVXCP002E_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVXCP002F_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVXCP0030_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVXCP0031_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVXCP0032_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVXCP0033_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVXCP0034_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVXCP0035_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVXCP0036_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVXCP0037_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVXCP0038_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVXCP0039_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP003A_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVXCP003B_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVXCP003C_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVXCP003D_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVXCP003E_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVXCP003F_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVXCP0040_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVXCP0100_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVXCP0101_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP0102_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP0103_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVXCP0104_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVXCP0105_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP0106_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP0107_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVXCP0108_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVXCP0109_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVXCP010A_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP010B_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVRESET1160_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVRIDF000_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVRIDF001_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVRIDF002_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVRIDF003_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVRIDF004_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVRIDF005_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVRIDF006_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVRIDF007_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVRIDF008_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVRIDF009_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVRIDF00A_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVRIDF00B_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVRIDF00C_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVRIDF00D_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVRIDF00E_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVRIDF00F_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVRIDF0FF_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFD01_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFD02_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFD03_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVPIDFD04_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFD05_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFD06_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVPIDFD07_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFD08_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFD09_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVPIDFD0A_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVPIDFD0B_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFD0C_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVIOCFD0D_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFD0E_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFD0F_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVPIDFD10_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVIOCFD11_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFD12_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFD13_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFD14_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVPIDFD15_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVPIDFD16_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVPIDFD17_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFD18_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVPIDFD19_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFD1A_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFD1B_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFD1C_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFD1D_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVPIDFD1E_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFD1F_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVPIDFD20_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFD21_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVPIDFD22_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVPIDFD23_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVPIDFD24_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVPIDFD25_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFD26_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFD27_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFD28_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVPIDFD29_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFD30_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVPIDFD31_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVPIDFD41_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFDA0_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVPIDFDA1_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFDA2_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFDA3_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFDA4_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVPIDFDA5_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVPIDFDA7_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVPIDFDA8_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVPIDFDA9_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVPIDFDAC_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFDAD_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFDAE_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFDAF_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFDB0_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFDB1_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFDB2_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFDB3_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFDB4_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFDB5_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFDB6_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFDB7_CNT_ENUM	D_DIAGSRVC_DISABLED

/* -----[ Begin XCP Variables ]----- */
#define CM_ModeMachine_StaMd_SystemState_Mode &Rte_ModeMachine_StaMd_SystemState_Mode
#define CM_BatteryVoltage_Vecu_Volts_f32      &Rte_BatteryVoltage_Vecu_Volt_f32
#define CM_Adc_T1                             NULL_PTR
#define CM_Analog_T1_Volts                    &Rte_IoHwAbstractionUsr_T1ADC_Volt_f32
#define CM_Adc_T2                             NULL_PTR
#define CM_Analog_T2_Volts                    &Rte_IoHwAbstractionUsr_T2ADC_Volt_f32
#define CM_HwTrqArb_HwTrq_HwNm_f32            &Rte_HwTrq_AnaHwTorque_HwNm_f32
#define CM_FinalHwPos_FinHwPos_HwDeg_f32      &Rte_Ap_AbsHwPosScom_HwPos_HwDeg_f32
#define CM_ScaledMtrPos_HwDeg_M_f32           NULL_PTR
#define CM_KeFBckTyH_VpRadpS_f32              NULL_PTR
#define CM_RFBckTyH_Ohm_f32                   NULL_PTR
#define CM_Sin1MaxTyH_Volts_f32               NULL_PTR
#define CM_Sin1MinTyH_Volts_f32               NULL_PTR
#define CM_Cos1MaxTyH_Volts_f32               NULL_PTR
#define CM_Cos1MinTyH_Volts_f32               NULL_PTR
#define CM_MtrTrqLmt_MRFMtrTrqCmd_MtrNm_f32   &Rte_CtrldDisShtdn_CntDisMtrTrqCmdMRF_MtrNm_f32
#define CM_MtrPos_MRFCumMtrPos_Deg_f32        &Rte_MtrPos_CumMtrPosMRF_Deg_f32
#define CM_MtrVel_MRFMtrVel_MtrRadpS_f32      &Rte_MtrVel_MRFMotorVel_MtrRadpS_f32
#define CM_VehicleSpeed_VehSpd_Kph_f32        &Rte_Ap_SignlCondn_VehicleSpeed_Kph_f32
#define CM_k_TbarStiff_NmpDeg_F32             &k_TbarStiff_NmpDeg_f32
#define CM_k_HwTrqSclNom_VoltspDeg_f32        &k_HwTrqSclNom_VoltspDeg_f32
#define CM_T1_Trim_Volts_Analog               &Rte_HwTrq_HwTrqTrimData.T1Trim_Volts_f32
#define CM_T2_Trim_Volts_Analog               &Rte_HwTrq_HwTrqTrimData.T2Trim_Volts_f32
#define CM_HwTrq_Trim_Volts_Analog            &Rte_HwTrq_HwTrqTrimData.HwTrqTrim_Volts_f32
#define CM_CtrlTemp_FiltMeasTemp_DegC_f32     &Rte_CtrlTemp_FiltMeasTemp_DegC_f32
#define CM_QaxCurrFiltSV_Amp_M_s11p20         NULL_PTR
#define CM_CDDInterface_Sin1Theta_Volts_f32   &Rte_Sa_MtrPos2_SinTheta1_Volt_f32
#define CM_CDDInterface_Cos1Theta_Volts_f32   &Rte_Sa_MtrPos2_CosTheta1_Volt_f32
#define CM_MtrTempEst_MagTempEst_DegC_f32     &Rte_Ap_MtrTempEst_MagTempEst_DegC_f32
#define CM_VltgCtrl_ModIdx_Uls_f32            &Rte_CDDInterface_ModIdxFinal_Uls_f32
#define CM_TemperatureADC_Volt_f32            &Rte_IoHwAbstractionUsr_TemperatureADC_Volt_f32
#define CM_MtrCurrQax_Amp_f32                 &CDD_MtrCurrQax_Amp_G_f32
/* -----[ End XCP Variables ]----- */

#if (D_EPSDIAGSRVRESET1160_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_StaMd_SCom_EcuReset                  NtWrapC_StaMd_SCom_EcuReset
#endif

#if (D_EPSDIAGSRVRIDF000_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define D_F000NMEC_CNT_LGC                      TRUE
	#define D_F000IGNCNTR_CNT_LGC                   TRUE
	#define D_F000LEARNEDEOT_CNT_LGC                TRUE
	#define D_F000ACTIVEPULLCOMP_CNT_LGC            TRUE
	#define D_F000NXTRDTCTBL_CNT_LGC                TRUE
	#define D_F000NXTRDTCBLACKBOX_CNT_LGC           TRUE
	#define D_F000CUSTDTCTBL_CNT_LGC                TRUE
	#define D_F000FRICTIONDETECTPARAM_CNT_LGC       TRUE
	#define D_F000WIRPARAM_CNT_LGC                  TRUE
	#define D_F000INITLRNDTBLS_CNT_LGC              TRUE
	#define D_F000TRANSOVDATA_CNT_LGC               TRUE
	#define CM_Reset_LrnEOT_Scom_ResetEOT           LrnEOT_Scom_ResetEOT
	#define CM_Reset_ActivePull_SCom_SetLTComp      ActivePull_SCom_SetLTComp
	#define CM_Reset_ClearNTCs_SComm                DiagMgr_SCom_ResetNTCStatus
//	#define CM_Reset_ClearCustDTCs_SComm            FrfmClearDTC(a,b)
	#define CM_AvgFricLrn_SCom_ResetToZero          AvgFricLrn_SCom_ResetToZero
	#define CM_AvgFricLrn_SCom_InitLearnedTables    AvgFricLrn_SCom_InitLearnedTables
	#define CM_BatteryVoltage_SCom_ClearTransOvData BatteryVoltage_SCom_ClearTransOvData
	/* --- The following are custom definitions not defined in configuration. ---
	 * They may be deprecated data or something that should be configured in the tool.
	 * Please revise and REMOVE any UNNEEDED definitions. */
	#define CM_Reset_ClearCustDTCs_SComm(a,b,c)                  FrfmClearDTC(a,b)
#endif

#if (D_EPSDIAGSRVRIDF001_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_ClearNTCs_SComm                      DiagMgr_SCom_ResetNTCStatus
//	#define CM_ClearCustDTCs_SComm                  FrfmClearDTC(a,b)
	/* --- The following are custom definitions not defined in configuration. ---
	 * They may be deprecated data or something that should be configured in the tool.
	 * Please revise and REMOVE any UNNEEDED definitions. */
	#define CM_ClearCustDTCs_SComm(a,b,c)                  FrfmClearDTC(a,b)
	#define DEM_DTC_ORIGIN_PRIMARY_MEMORY				   0u
#endif

#if (D_EPSDIAGSRVRIDF002_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_HwTrq_SCom_ClrHwTrqTrim              NtWrapC_HwTrq_SCom_ClrHwTrqTrim
	#define CM_HwTrq_SCom_ClrHwTrqScale             NtWrapC_HwTrq_SCom_ClrHwTrqScale
	#define CM_HwTrq_SCom_SetHwTrqTrim              NtWrapC_HwTrq_SCom_SetHwTrqTrim
#endif

#if (D_EPSDIAGSRVRIDF003_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define D_F003CLRTRIMNORET_CNT_LGC              TRUE
	#define D_F003DISABLELRNTRIM_CNT_LGC            TRUE
#endif

#if (D_EPSDIAGSRVRIDF004_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define D_SENTBASEDSENSOR_CNT_LGC               TRUE
#endif

#if (D_EPSDIAGSRVRIDF005_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_DiagMgr_SCom_GetNTCInfo              DiagMgr_SCom_GetNTCInfo
#endif

#if (D_EPSDIAGSRVRIDF006_CNT_ENUM == D_DIAGSRVC_ENABLED)
	/* Defines specific to RID: F006 */
#endif

#if (D_EPSDIAGSRVRIDF007_CNT_ENUM == D_DIAGSRVC_ENABLED)
	/* Defines specific to RID: F007 */
#endif

#if (D_EPSDIAGSRVRIDF008_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_CmMtrCurr_SCom_CalGain               NtWrapC_CmMtrCurr_SCom_CalGain
#endif

#if (D_EPSDIAGSRVRIDF009_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_CmMtrCurr_SCom_MtrCurrOffReadStatus  CmMtrCurr_SCom_MtrCurrOffReadStatus
	#define CM_CmMtrCurr_SCom_CalOffset             NtWrapC_CmMtrCurr_SCom_CalOffset
	#define MtrCurrOffProcessFlag                   boolean
	#define D_RIDF009SVCDFTBITSSET_CNT_U16          0x301
	#define D_RIDF009SVCDFTBITSCLR_CNT_U16          (~D_RIDF009SVCDFTBITSSET_CNT_U16)
#endif

#if (D_EPSDIAGSRVRIDF00A_CNT_ENUM == D_DIAGSRVC_ENABLED)
	/* Defines specific to RID: F00A */
#endif

#if (D_EPSDIAGSRVRIDF00B_CNT_ENUM == D_DIAGSRVC_ENABLED)
	/* Defines specific to RID: F00B */
#endif

#if (D_EPSDIAGSRVRIDF00C_CNT_ENUM == D_DIAGSRVC_ENABLED)
	/* Defines specific to RID: F00C */
#endif

#if (D_EPSDIAGSRVRIDF00D_CNT_ENUM == D_DIAGSRVC_ENABLED)
	/* Defines specific to RID: F00D */
#endif

#if (D_EPSDIAGSRVRIDF00E_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define D_RIDF00ESVCDFTBITSSET_CNT_U16          0x301
#endif

#if (D_EPSDIAGSRVRIDF00F_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_k_SComTrqPosPol_Cnt_s08              k_SComTrqPosPol_Cnt_s08
#endif

#if (D_EPSDIAGSRVRIDF0FF_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_EnableTestMode_Cnt_lgc               EnableTestMode_Cnt_lgc
	#define CM_ProcessF0FF                          Call_ProcessF0FF
	#define CM_WdgM_CheckpointReached               WdgM_CheckpointReached
	#define CM_DisableSysTickInterrupt              DisableSysTickInterrupt
	#define CM_EnableSysTickInterrupt               EnableSysTickInterrupt
	#define CM_GetAlarm                             GetAlarm
	#define CM_CancelAlarm                          CancelAlarm
	#define CM_SetRelAlarm                          SetRelAlarm
#endif

#if (D_EPSDIAGSRVPIDFD01_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_SwRelNum_Cnt_u08                     k_SWRelNum_Cnt_u8
	#define CM_CalRelNum_Cnt_u08                    k_CalRelNum_Cnt_u8
	#define CM_BootRelNum_Cnt_u08                   Lnk_BootRelNum_Addr
#endif

#if (D_EPSDIAGSRVPIDFD02_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_SrlComSvcDft_Cnt_b32                 CDD_EOLSrlComSvcDft_Cnt_G_b32
	/* --- The following are custom definitions not defined in configuration. ---
	 * They may be deprecated data or something that should be configured in the tool.
	 * Please revise and REMOVE any UNNEEDED definitions. */
	#define D_SVCDFTRXMSGS_CNT_B32				0x08000000u //134217728u
	#define D_SVCDFTMULTIGNMASK_CNT_B32			0x50000000u //1342177280u
#endif

#if (D_EPSDIAGSRVPIDFD03_CNT_ENUM == D_DIAGSRVC_ENABLED)
	/* Defines specific to PID: FD03 */
#endif

#if (D_EPSDIAGSRVPIDFD04_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_MtrPosCal_DataType                   MtrPosCal_DataType
	#define CM_MtrPos_SCom_SetEOLMtrCals            NtWrapC_MtrPos_SCom_SetEOLMtrCals
	#define CM_MtrPos_SCom_ReadEOLMtrCals           MtrPos_SCom_ReadEOLMtrCals
	#define D_HARTBLSIZE_CNT_U16                    144
#endif

#if (D_EPSDIAGSRVPIDFD05_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_HwTrq_SCom_ManualSetHwTrqTrim        NtWrapC_HwTrq_SCom_ManualSetHwTrqTrim
	#define CM_HwTrq_SCom_ReadHwTrqTrim             HwTrq_SCom_ReadHwTrqTrim
	/* --- The following are custom definitions not defined in configuration. ---
	 * They may be deprecated data or something that should be configured in the tool.
	 * Please revise and REMOVE any UNNEEDED definitions. */
	#define CM_HwTrqTrim_Datatype 					HwTrqTrim_Datatype
#endif

#if (D_EPSDIAGSRVPIDFD06_CNT_ENUM == D_DIAGSRVC_ENABLED)
	/* Defines specific to PID: FD06 */
#endif

#if (D_EPSDIAGSRVPIDFD07_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define D_FD07_USE8BITPOLARITY_CNT_LGC          TRUE
	#define CM_Polarity_SCom_SetPolarity            NtWrapC_Polarity_SCom_SetPolarity
	#define CM_Polarity_SCom_ReadPolarity           Polarity_SCom_ReadPolarity
#endif

#if (D_EPSDIAGSRVPIDFD08_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_HwTrq_SCom_SetHwTrqScale             NtWrapC_HwTrq_SCom_SetHwTrqScale
	#define CM_HwTrq_SCom_ReadHwTrqScale            HwTrq_SCom_ReadHwTrqScale
	/* --- The following are custom definitions not defined in configuration. ---
	 * They may be deprecated data or something that should be configured in the tool.
	 * Please revise and REMOVE any UNNEEDED definitions. */
	#define CM_HwTrqScale_Datatype			HwTrqScale_Datatype
#endif

#if (D_EPSDIAGSRVPIDFD09_CNT_ENUM == D_DIAGSRVC_ENABLED)
	/* Defines specific to PID: FD09 */
#endif

#if (D_EPSDIAGSRVPIDFD0A_CNT_ENUM == D_DIAGSRVC_ENABLED)
	/* Defines specific to PID: FD0A */
#endif

#if (D_EPSDIAGSRVPIDFD0B_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_WIRSel_Cnt_u16                       CDD_EOLNxtrWIRSelect_Cnt_G_u16
#endif

#if (D_EPSDIAGSRVPIDFD0C_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define D_PIDFD0CIGNORELPARAM_CNT_LGC           TRUE
#endif

#if (D_EPSDIAGSRVIOCFD0D_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_MtrTrqLmt_SCom_ManualTrqCmd          NtWrapC_AstLmt_Scom_ManualTrqCmd
#endif

#if (D_EPSDIAGSRVPIDFD0E_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_MtrTrqCmd_MtrNm_f32                  Rte_CtrldDisShtdn_CntDisMtrTrqCmdMRF_MtrNm_f32
	#define CM_CumMtrPos_Deg_f32                    Rte_MtrPos_CumMtrPosMRF_Deg_f32
#endif

#if (D_EPSDIAGSRVPIDFD0F_CNT_ENUM == D_DIAGSRVC_ENABLED)
	/* Defines specific to PID: FD0F */
#endif

#if (D_EPSDIAGSRVPIDFD10_CNT_ENUM == D_DIAGSRVC_ENABLED)
	/* Defines specific to PID: FD10 */
#endif

#if (D_EPSDIAGSRVIOCFD11_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_DFTASSTTBL_CNT_LGC                   CDD_DftAsstTbl_Cnt_G_lgc
	#define CM_DWNLDASSTGAIN_ULS_F32                CDD_DwnldAsstGain_Uls_G_f32
#endif

#if (D_EPSDIAGSRVPIDFD12_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_PhaseCurrCal_DataType                PhaseCurrCal_DataType
	#define CM_CmMtrCurr_SCom_SetMtrCurrCals        NtWrapC_CmMtrCurr_SCom_SetMtrCurrCals
	#define CM_CmMtrCurr_SCom_ReadMtrCurrCals       CmMtrCurr_SCom_ReadMtrCurrCals
#endif

#if (D_EPSDIAGSRVPIDFD13_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_DiagMgr_SCom_ReadStrgArray           DiagMgr_SCom_ReadStrgArray
	#define CM_DTCMaxStorage_Cnt_u16                D_MAXDTCSTORAGE_CNT_U16
	#define CM_NTCStrgArray_Type                    NTCStrgArray
	#define CM_DiagMgr_SCom_GetNTCInfo              DiagMgr_SCom_GetNTCInfo
#endif

#if (D_EPSDIAGSRVPIDFD14_CNT_ENUM == D_DIAGSRVC_ENABLED)
	/* Defines specific to PID: FD14 */
#endif

#if (D_EPSDIAGSRVPIDFD15_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_HwTrqTrim_Datatype                   CM_HwTrqTrim_Datatype
#endif

#if (D_EPSDIAGSRVPIDFD16_CNT_ENUM == D_DIAGSRVC_ENABLED)
	/* Defines specific to PID: FD16 */
#endif

#if (D_EPSDIAGSRVPIDFD17_CNT_ENUM == D_DIAGSRVC_ENABLED)
	/* Defines specific to PID: FD17 */
#endif

#if (D_EPSDIAGSRVPIDFD18_CNT_ENUM == D_DIAGSRVC_ENABLED)
	/* Defines specific to PID: FD18 */
#endif

#if (D_EPSDIAGSRVPIDFD19_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_NxtrMEC_Cnt_G_u8                     Nvm_NMEC_Cnt_u8
#endif

#if (D_EPSDIAGSRVPIDFD1A_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_Rte_ModeType_StaMd_Mode              Rte_ModeType_StaMd_Mode
	#define CM_SystemState_Cnt_enum                 Rte_ModeMachine_StaMd_SystemState_Mode
#endif

#if (D_EPSDIAGSRVPIDFD1B_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_ManualVehSpd_SCom                    SrlComInput_SCom_ManualVehSpd
#endif

#if (D_EPSDIAGSRVPIDFD1C_CNT_ENUM == D_DIAGSRVC_ENABLED)
	/* Defines specific to PID: FD1C */
#endif

#if (D_EPSDIAGSRVPIDFD1D_CNT_ENUM == D_DIAGSRVC_ENABLED)
	/* Defines specific to PID: FD1D */
#endif

#if (D_EPSDIAGSRVPIDFD1E_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_MfgDiagInhibit_Cnt_lgc               MfgDiagInhibit_Uls_G_lgc
#endif

#if (D_EPSDIAGSRVPIDFD1F_CNT_ENUM == D_DIAGSRVC_ENABLED)
	/* Defines specific to PID: FD1F */
#endif

#if (D_EPSDIAGSRVPIDFD20_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_BatteryVoltage_SCom_ReadTransOvData  BatteryVoltage_SCom_ReadTransOvData
#endif

#if (D_EPSDIAGSRVPIDFD21_CNT_ENUM == D_DIAGSRVC_ENABLED)
	/* Defines specific to PID: FD21 */
#endif

#if (D_EPSDIAGSRVPIDFD22_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_TcPartNumType                        TcPartNumType
	#define D_PIDFD22STRLEN_CNT_U08                 D_TcPNArraySize_Cnt_U16
#endif

#if (D_EPSDIAGSRVPIDFD23_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_Vsm_OperatingModeType                Vsm_OperatingModeType
#endif

#if (D_EPSDIAGSRVPIDFD24_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_EOLTurnsCntrCals_Datatype            EOLTurnsCntrCals_Datatype
#endif

#if (D_EPSDIAGSRVPIDFD25_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_TrqCmdScl_SCom_Set                   NtWrapC_TrqCmdScl_SCom_Set
	#define CM_TrqCmdScl_SCom_Get                   TrqCmdScl_SCom_Get
#endif

#if (D_EPSDIAGSRVPIDFD26_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_AvgFricLrn_SCom_SetSelect            AvgFricLrn_SCom_SetSelect
	#define CM_AvgFricLrn_SCom_GetSelect            AvgFricLrn_SCom_GetSelect
#endif

#if (D_EPSDIAGSRVPIDFD27_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_AvgFricLrn_SCom_SetOffsetOutputDefeat AvgFricLrn_SCom_SetOffsetOutputDefeat
	#define CM_AvgFricLrn_SCom_GetOffsetOutputDefeat AvgFricLrn_SCom_GetOffsetOutputDefeat
#endif

#if (D_EPSDIAGSRVPIDFD28_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_TurnsCounter_Scom_GetFlashTraceabilityID None
	#define CM_TcFlashIDType                        None
#endif

#if (D_EPSDIAGSRVPIDFD29_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_AvgFricLrn_SCom_SetEOLFric           AvgFricLrn_SCom_SetEOLFric
	#define CM_AvgFricLrn_SCom_GetEOLFric           AvgFricLrn_SCom_GetEOLFric
#endif

#if (D_EPSDIAGSRVPIDFD30_CNT_ENUM == D_DIAGSRVC_ENABLED)
	/* Defines specific to PID: FD30 */
#endif

#if (D_EPSDIAGSRVPIDFD31_CNT_ENUM == D_DIAGSRVC_ENABLED)
	/* Defines specific to PID: FD31 */
#endif

#if (D_EPSDIAGSRVPIDFD41_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_Rte_IoHwAbstractionUsr_T1ADC_Volt_f32 Rte_IoHwAbstractionUsr_T1ADC_Volt_f32
	#define CM_Rte_IoHwAbstractionUsr_T2ADC_Volt_f32 Rte_IoHwAbstractionUsr_T2ADC_Volt_f32
#endif

#if (D_EPSDIAGSRVPIDFDA0_CNT_ENUM == D_DIAGSRVC_ENABLED)
	/* --- The following are custom definitions not defined in configuration. ---
	 * They may be deprecated data or something that should be configured in the tool.
	 * Please revise and REMOVE any UNNEEDED definitions. */
//	#define CM_ManufModeType	ManufModeType
#endif

#if (D_EPSDIAGSRVPIDFDA1_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_ECUSerialNumber                      Nvm_EcuSrlNum_Cnt_u8
#endif

#if (D_EPSDIAGSRVPIDFDA2_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_EPSSerialNumber                      Nvm_EpsSrlNum_Cnt_u8
#endif

#if (D_EPSDIAGSRVPIDFDA3_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_ECUHardwarePN                        Nvm_EcuHwPn_Cnt_u8
#endif

#if (D_EPSDIAGSRVPIDFDA4_CNT_ENUM == D_DIAGSRVC_ENABLED)
	/* Defines specific to PID: FDA4 */
#endif

#if (D_EPSDIAGSRVPIDFDA5_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_ShCurrCal_DataType                   ShCurrCal_DataType
#endif

#if (D_EPSDIAGSRVPIDFDA7_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_HwPosRelCal_DataType                 HwPosRelCal_DataType
#endif

#if (D_EPSDIAGSRVPIDFDA8_CNT_ENUM == D_DIAGSRVC_ENABLED)
	/* Defines specific to PID: FDA8 */
#endif

#if (D_EPSDIAGSRVPIDFDA9_CNT_ENUM == D_DIAGSRVC_ENABLED)
	/* Defines specific to PID: FDA9 */
#endif

#if (D_EPSDIAGSRVPIDFDAC_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_MfgScratchPad_Cnt_G_u8               Nvm_NxtrManfScrpd_Cnt_u8
#endif

#if (D_EPSDIAGSRVPIDFDAD_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_ActivePull_SCom_ReadParam            ActivePull_SCom_ReadParam
#endif

#if (D_EPSDIAGSRVPIDFDAE_CNT_ENUM == D_DIAGSRVC_ENABLED)
	/* Defines specific to PID: FDAE */
#endif

#if (D_EPSDIAGSRVPIDFDAF_CNT_ENUM == D_DIAGSRVC_ENABLED)

#endif

#if (D_EPSDIAGSRVPIDFDB0_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_IPMCoggingCancTrq                    CoggingCancTrq
	#define CM_IPMTrqCanc_Scom_SetCogTrqCal         NtWrapC_TrqCanc_Scom_SetCogTrqCal
	#define CM_IPMTrqCanc_Scom_ReadCogTrqCal        TrqCanc_Scom_ReadCogTrqCal
#endif

#if (D_EPSDIAGSRVPIDFDB1_CNT_ENUM == D_DIAGSRVC_ENABLED)
	/* Defines specific to PID: FDB1 */
#endif

#if (D_EPSDIAGSRVPIDFDB2_CNT_ENUM == D_DIAGSRVC_ENABLED)
	/* Defines specific to PID: FDB2 */
#endif

#if (D_EPSDIAGSRVPIDFDB3_CNT_ENUM == D_DIAGSRVC_ENABLED)
	/* Defines specific to PID: FDB3 */
#endif

#if (D_EPSDIAGSRVPIDFDB4_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define D_RANDKESUPPORTONLY_CNT_LGC             TRUE
	#define CM_SCom_EOLNomMtrParam_Set_FDB4         NtWrapC_SCom_EOLNomMtrParam_Set
	#define CM_SCom_EOLNomMtrParam_Get_FDB4         SCom_EOLNomMtrParam_Get
#endif

#if (D_EPSDIAGSRVPIDFDB5_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_ActivePull_SCom_SetSTComp            ActivePull_SCom_SetSTComp
#endif

#if (D_EPSDIAGSRVPIDFDB6_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_ActivePull_SCom_SetLTComp            ActivePull_SCom_SetLTComp
#endif

#if (D_EPSDIAGSRVPIDFDB7_CNT_ENUM == D_DIAGSRVC_ENABLED)
	/* Defines specific to PID: FDB7 */
#endif

/******************************* END CMS GENERATION - DO NOT CHANGE/REMOVE THIS COMMENT *******************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of custom define area >>	                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#endif /* EPS_DIAGSRVCS_ISO_INTERFACE_H */
