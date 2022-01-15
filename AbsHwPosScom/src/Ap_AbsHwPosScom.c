/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Ap_AbsHwPosScom.c
 *     Workspace:  C:/Synergy/AbsHwPosScom-zz4r1x/AbsHwPosScom/autosar
 *     SW-C Type:  Ap_AbsHwPosScom
 *  Generated at:  Wed Oct 24 15:44:47 2012
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nexteer  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  C-Code implementation template for SW-C <Ap_AbsHwPosScom>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/* Version Control:
 * Date Created:      Sat Apr 21 12:06:33 2012
 * %version:          12 %
 * %derived_by:       zz4r1x %
 * %date_modified:    Fri Oct 26 11:06:03 2012 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 04/21/12  1        LWW       Initial template for implmentation
 * 04/25/12  2        NRAR      FDD 05D implementation and text formatting
 * 04/26/12  3        NRAR      Updated HandWheelPosition range from +/-1440.11 to +/-1620 
 * 04/26/12  4        NRAR      Building warning fixes
 * 05/03/12  5        LWW       Anomaly 3257 correction and QAC fixes
 * 07/05/12  6        NRAR      Changes as per FDD Ver003, Ver 002 and Anomaly 3382 is ignored as now no limit is required as s/w
 *							is implemented in floating type.
 * 07/18/12  7        NRAR      UTP Fix
 * 07/18/12  8        LWW       Framework updates						
 * 08/11/12  9        BWL       Update per FDD v006
 * 09/26/12  10        Selva      Checkpoints added and mempmap macros corrected		                          6354
 * 10/24/12  11       BWL       Update execution rate for Per2 and Per3                                           6624
 * 10/24/12  12       BWL       Fix filter rate constants                                                         6624
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *
 * AUTOSAR Modelling Object Descriptions
 *
 **********************************************************************************************************************

 Operation Prototypes:
 =====================
  DtrmnElapsedTime_mS_u16 of Port Interface SystemTime
    Nexteer SystemTime Service

 *********************************************************************************************************************/

#include "Rte_Ap_AbsHwPosScom.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "CalConstants.h"
#include "GlobalMacro.h"
#include "filters.h"
#include "Interpolation.h"
#include "GlobalMacro.h"
#include "fixmath.h"
#include <float.h>
#include "Ap_AbsHwPosScom_Cfg.h"

#define D_ABSPOSLOLMT_HWDEG_F32     -1620.0F
#define D_ABSPOSHILMT_HWDEG_F32     1620.0F
#define D_10MS_SEC_F32 0.010F

#define ABSHWPOSSCOM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"
STATIC VAR(LPF32KSV_Str, AP_ABSHWPOSSCOM_VAR_NOINIT) PinTrqFiltSV_HwNm_M_str;
STATIC VAR(LPF32KSV_Str, AP_ABSHWPOSSCOM_VAR_NOINIT) HwPFilter1SV_HwDeg_M_Str;
STATIC VAR(LPF32KSV_Str, AP_ABSHWPOSSCOM_VAR_NOINIT) HwPFilter2SV_HwDeg_M_Str;
STATIC VAR(LPF32KSV_Str, AP_ABSHWPOSSCOM_VAR_NOINIT) FinHwPosFiltSV_HwDeg_M_Str;
#define ABSHWPOSSCOM_STOP_SEC_VAR_CLEARED__UNSPECIFIED
#include "MemMap.h"

#define ABSHWPOSSCOM_START_SEC_VAR_CLEARED_32
#include "MemMap.h"
STATIC VAR(float32, AP_ABSHWPOSSCOM_VAR_NOINIT) ScaledMtrPos_HwDeg_M_f32;
STATIC VAR(float32, AP_ABSHWPOSSCOM_VAR_NOINIT) MtrComplErr_HwDeg_M_f32;
STATIC VAR(float32, AP_ABSHWPOSSCOM_VAR_NOINIT) RelHwPos_HwDeg_M_f32;
STATIC VAR(float32, AP_ABSHWPOSSCOM_VAR_NOINIT) RelToSComOffset_HwDeg_M_f32;
STATIC VAR(float32, AP_ABSHWPOSSCOM_VAR_NOINIT) HwPMtrVelT1Cal_MtrRadpS_M_f32;
STATIC VAR(float32, AP_ABSHWPOSSCOM_VAR_NOINIT) HwPVSpdT1Cal_Kph_M_f32 ;
STATIC VAR(float32, AP_ABSHWPOSSCOM_VAR_NOINIT) HwPPinTrqT1Cal_HwNm_M_f32 ;
STATIC VAR(uint32, AP_ABSHWPOSSCOM_VAR_NOINIT) StabilitySyncTimer_mS_M_u32;
STATIC VAR(float32, AP_ABSHWPOSSCOM_VAR_NOINIT) HwPWindowCal_HwDeg_M_f32;
STATIC VAR(float32, AP_ABSHWPOSSCOM_VAR_NOINIT) HwPFilter1Kn_Hz_M_f32 ;
STATIC VAR(float32, AP_ABSHWPOSSCOM_VAR_NOINIT) HwPFilter2Kn_Hz_M_f32;
STATIC VAR(float32, AP_ABSHWPOSSCOM_VAR_NOINIT) AutoCntrTrgtAuth_Uls_M_f32;
STATIC VAR(float32, AP_ABSHWPOSSCOM_VAR_NOINIT) FinHwAuth_Uls_M_f32;
STATIC VAR(uint32, AP_ABSHWPOSSCOM_VAR_NOINIT) HwPTimer1_ms_M_u32;
STATIC VAR(uint32, AP_ABSHWPOSSCOM_VAR_NOINIT) HwPTimer2_ms_M_u32;
STATIC VAR(uint32, AP_ABSHWPOSSCOM_VAR_NOINIT) HwPTimer4_ms_M_u32;
STATIC VAR(float32, AP_ABSHWPOSSCOM_VAR_NOINIT) VehDynTrgtAuth_Uls_M_f32;
STATIC VAR(float32, AP_ABSHWPOSSCOM_VAR_NOINIT) ScomHwPosAuth_Uls_M_f32;
STATIC VAR(float32, AP_ABSHWPOSSCOM_VAR_NOINIT) HwPFilter1Prev_HwDeg_M_f32;
STATIC VAR(float32, AP_ABSHWPOSSCOM_VAR_NOINIT) HwPFilter1Out_HwDeg_M_f32;
STATIC VAR(float32, AP_ABSHWPOSSCOM_VAR_NOINIT) HwPFilter2Out_HwDeg_M_f32;
STATIC VAR(float32, AP_ABSHWPOSSCOM_VAR_NOINIT) FinHwPosLPFOp_HwDeg_M_f32;
STATIC volatile VAR(float32, AP_ABSHWPOSSCOM_VAR_NOINIT) TempHwPos_HwDeg_M_f32;
STATIC VAR(float32, AP_ABSHWPOSSCOM_VAR_NOINIT) VehDynTrgtAngle_HwDeg_M_f32;
STATIC VAR(float32, AP_ABSHWPOSSCOM_VAR_NOINIT) FiltPinionTrq_HwNm_M_f32;
STATIC VAR(float32, AP_ABSHWPOSSCOM_VAR_NOINIT) NewScomInpHwA_HwDeg_M_f32;

#define ABSHWPOSSCOM_STOP_SEC_VAR_CLEARED_32
#include "MemMap.h"

#define ABSHWPOSSCOM_START_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h"
STATIC VAR(boolean, AP_ABSHWPOSSCOM_VAR_NOINIT) HwPFilter1En_Cnt_M_lgc;
STATIC VAR(boolean, AP_ABSHWPOSSCOM_VAR_NOINIT) HwPFilter2En_Cnt_M_lgc;
STATIC VAR(boolean, AP_ABSHWPOSSCOM_VAR_NOINIT) HwPFilter1Init_Cnt_M_lgc;
STATIC VAR(boolean, AP_ABSHWPOSSCOM_VAR_NOINIT) HwPFilter2Init_Cnt_M_lgc;
STATIC VAR(boolean, AP_ABSHWPOSSCOM_VAR_NOINIT) HwPAutoCenter_Cnt_M_lgc;
STATIC VAR(boolean, AP_ABSHWPOSSCOM_VAR_NOINIT) HwPHighSpdAC_Cnt_M_lgc;
STATIC VAR(boolean, AP_ABSHWPOSSCOM_VAR_NOINIT) HwPosSrvSetToZero_Cnt_M_lgc;
STATIC VAR(boolean, AP_ABSHWPOSSCOM_VAR_NOINIT) RelToScomOfstFound_Cnt_M_lgc;
#define ABSHWPOSSCOM_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h"


#define ABSHWPOSSCOM_START_SEC_VAR_CLEARED_16
#include "MemMap.h"
STATIC VAR(uint16, AP_ABSHWPOSSCOM_VAR_NOINIT) HwPTimer1Max_ms_M_u16;
STATIC VAR(uint16, AP_ABSHWPOSSCOM_VAR_NOINIT) HwPTimer2Max_ms_M_u16;

#define ABSHWPOSSCOM_STOP_SEC_VAR_CLEARED_16
#include "MemMap.h"

#define ABSHWPOSSCOM_START_SEC_VAR_SAVED_ZONEH_32
#include "MemMap.h"
STATIC VAR(float32, AP_ABSHWPOSSCOM_VAR_NOINIT) VdynToScomErrorThy_HwDeg_M_f32;
#define ABSHWPOSSCOM_STOP_SEC_VAR_SAVED_ZONEH_32
#include "MemMap.h"

STATIC FUNC(void, AP_ABSHWPOSSCOM_CODE) HwPosSLFilter1(	VAR(float32, AUTOMATIC) MtrPos_HwDeg_T_f32,
															VAR(boolean, AUTOMATIC) FilterEn);	
															
STATIC FUNC(void, AP_ABSHWPOSSCOM_CODE) HwPosSLFilter2(	VAR(float32, AUTOMATIC) MtrPos_HwDeg_T_f32,
															VAR(boolean, AUTOMATIC) FilterEn);

STATIC FUNC(boolean, AP_ABSHWPOSSCOM_CODE) Filter1Enable(	VAR(float32, AUTOMATIC) CRFMtrVel_MtrRadpS_T_f32,
															VAR(float32, AUTOMATIC) VehSpd_Kph_T_f32,
															VAR(boolean, AUTOMATIC) VSpdValid_Cnt_T_lgc,
															VAR(float32, AUTOMATIC) PinionTrq_HwNm_T_f32);		
															
STATIC FUNC(boolean, AP_ABSHWPOSSCOM_CODE) Filter2Enable(	VAR(float32, AUTOMATIC) MtrPos_HwDeg_T_f32,
															VAR(boolean, AUTOMATIC) HwPFilter1En_Cnt_T_lgc);

STATIC FUNC(void, AP_ABSHWPOSSCOM_CODE) CalSwitchTimer(	VAR(float32, AUTOMATIC) CRFMtrVel_MtrRadpS_T_f32,
															VAR(float32, AUTOMATIC) VehSpd_Kph_T_f32,
															VAR(boolean, AUTOMATIC) VSpdValid_Cnt_T_lgc,
															VAR(float32, AUTOMATIC) PinionTrq_HwNm_T_f32,
															CONSTP2VAR(boolean, AUTOMATIC, AP_ABSHWPOSSCOM_CONST) HwPFilter1En_Cnt_T_lgc,
															CONSTP2VAR(boolean, AUTOMATIC, AP_ABSHWPOSSCOM_CONST) HwPFilter2En_Cnt_T_lgc);

STATIC FUNC(void, AP_ABSHWPOSSCOM_CODE) ScomHwPosAuth(void);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include and declaration area >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * Used AUTOSAR Data Types
 *
 **********************************************************************************************************************
 *
 * Primitive Types:
 * ================
 * Boolean: Boolean (standard type)
 * Float: Real in interval ]-FLT_MAX...FLT_MAX[ with single precision (standard type)
 * UInt16: Integer in interval [0...65535] (standard type)
 * UInt32: Integer in interval [0...4294967295] (standard type)
 * UInt8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
 * NTCNumber: Enumeration of integer in interval [0...511] with enumerators
 *   NTC_Num_FlashWrapperLgcFlt (1u)
 *   NTC_Num_FlashECCCorr (2u)
 *   NTC_Num_FlashECCMemFlt (3u)
 *   NTC_Num_FlashCRCMemFault (4u)
 *   NTC_Num_EEPROMDiag (10u)
 *   NTC_Num_EEPROMDiagMtrStr (11u)
 *   NTC_Num_PriSnsrTrqStorFlt (12u)
 *   NTC_Num_EEPROMDiagPosTrimStr (13u)
 *   NTC_Num_SecSnsrTrqStorFlt (14u)
 *   NTC_Num_EEPROMDiagPolarityStr (15u)
 *   NTC_Num_RAMDiag_GeneralFlt (16u)
 *   NTC_Num_RAMDiag_WrprLgcFlt (17u)
 *   NTC_Num_RAMDiag_ECCCorrIndFlt (18u)
 *   NTC_Num_RAMDiag_ECCMemFlt (19u)
 *   NTC_Num_RAMDiag_CRCMemFlt (20u)
 *   NTC_Num_RAMDiag_VIMRamFlt (23u)
 *   NTC_Num_RAMDiag_NHET1RamFlt (24u)
 *   NTC_Num_RAMDiag_NHET2RamFlt (25u)
 *   NTC_Num_RAMDiag_ADC1RamFlt (26u)
 *   NTC_Num_RAMDiag_DCANRamFault (27u)
 *   NTC_Num_RAMDiag_ADC2RamFlt (28u)
 *   NTC_Num_RAMDiag_HETTU1RamFlt (29u)
 *   NTC_Num_RAMDiag_HETTU2RamFlt (30u)
 *   NTC_Num_CPU_RegVer (32u)
 *   NTC_Num_CPU_CoreInitFlt (33u)
 *   NTC_Num_CPU_CoreRunTimeFlt (34u)
 *   NTC_Num_CPU_ClockMon (35u)
 *   NTC_Num_CPU_eFuseFlt (36u)
 *   NTC_Num_CPU_MPUViolation (37u)
 *   NTC_Num_CPU_FactPrcsErr (40u)
 *   NTC_Num_PropExeDiag_InitDiag (41u)
 *   NTC_Num_PrgFlwDeadlnFlt (42u)
 *   NTC_Num_PropExeDiag_RunTimeDiag (43u)
 *   NTC_Num_PropExeDiag_COPTimeout (44u)
 *   NTC_Num_PropExeDiag_PrefetchAbort (48u)
 *   NTC_Num_PropExeDiag_DataAbort (49u)
 *   NTC_Num_PerDiag_ADC1Flt (50u)
 *   NTC_Num_PerDiag_ADC2Flt (51u)
 *   NTC_Num_PerDiag_ADCCrossChkFlt (52u)
 *   NTC_Num_PerDiag_IllegalAccess (53u)
 *   NTC_Num_PerDiag_DMAFlt (54u)
 *   NTC_Num_PerDiag_CPUWarning (63u)
 *   NTC_Num_TmpMonFunc (64u)
 *   NTC_Num_TmpMonRunTimeFlt (65u)
 *   NTC_Num_PowerRelayInitFlt (66u)
 *   NTC_Num_PrechargeFailure (67u)
 *   NTC_Num_PowerRelayRunFlt (68u)
 *   NTC_Num_Thermistor (69u)
 *   NTC_Num_RefSupplyVltg (70u)
 *   NTC_Num_TrcvrInterfaceFlt (71u)
 *   NTC_Num_CPUSupplyOvervoltage (72u)
 *   NTC_Num_GateDrvFlt (77u)
 *   NTC_Num_OnStateSingleFET (78u)
 *   NTC_Num_OnStateMultiFET (79u)
 *   NTC_Num_PhaseVoltageVerf (80u)
 *   NTC_Num_PhaseDscnt (81u)
 *   NTC_Num_DigPhaseVoltageVerf (82u)
 *   NTC_Num_CurrentMeas1 (84u)
 *   NTC_Num_CurrentMeas2 (85u)
 *   NTC_Num_CurrentMeasCrossChk (86u)
 *   NTC_Num_HwTrqSensor (96u)
 *   NTC_Num_AnaVsDigHwTrq (97u)
 *   NTC_Num_TrqSensorRecoveryFlt (98u)
 *   NTC_Num_TrqSensorScaleInvalid (100u)
 *   NTC_Num_T1vsT2 (101u)
 *   NTC_Num_T1OutofRange (102u)
 *   NTC_Num_T2OutofRange (103u)
 *   NTC_Num_DigT1vsT2 (104u)
 *   NTC_Num_DigT1OutofRange (105u)
 *   NTC_Num_DigT2OutofRange (106u)
 *   NTC_Num_HWASensorRel (110u)
 *   NTC_Num_HWASensorAbs (111u)
 *   NTC_Num_PriMSB_SinCosCorr (112u)
 *   NTC_Num_SecMSB_SinCosCorr (113u)
 *   NTC_Num_PriVsSec_SinCosCorr (114u)
 *   NTC_Num_DigMSBFlt (115u)
 *   NTC_Num_MtrVelFlt (116u)
 *   NTC_Num_HWAtoMtrAngleCorr (117u)
 *   NTC_Num_TurnCntr_PosLoss (128u)
 *   NTC_Num_TurnCntr_MicroProcFlt (129u)
 *   NTC_Num_TurnCntr_SensorPosFlt (130u)
 *   NTC_Num_TurnCntr_SpiComFlt (131u)
 *   NTC_Num_TurnCntr_HighQuiescCur (132u)
 *   NTC_Num_TurnCntr_MainResets (133u)
 *   NTC_Num_KinematicIntDiag (144u)
 *   NTC_Num_HighFriction (145u)
 *   NTC_Num_DutyCycleExceeded (148u)
 *   NTC_Num_AbsTempThermLimit (149u)
 *   NTC_Num_LatchActive (160u)
 *   NTC_Num_OpTrqVsHwTrq (168u)
 *   NTC_Num_CurrentReas (169u)
 *   NTC_Num_OpVoltage (176u)
 *   NTC_Num_ExVoltageLow (177u)
 *   NTC_Num_ReducedAsstLowVoltage (178u)
 *   NTC_Num_ExVoltageHigh (180u)
 *   NTC_Num_OpVoltageOvrMax (181u)
 *   NTC_Num_IgnConfDiag (184u)
 *   NTC_Num_TurnCntr_LowBattery (185u)
 *   NTC_Num_EEPROMCloseFailed (191u)
 *   NTC_Num_SigPath1CrossChk (192u)
 *   NTC_Num_SigPath2CrossChk (193u)
 *   NTC_Num_SigPath3CrossChk (194u)
 *   NTC_Num_SigPath4CrossChk (195u)
 *   NTC_Num_SigPath5CrossChk (196u)
 *   NTC_Num_DampingFWReached (197u)
 *   NTC_Num_AssistFWReached (198u)
 *   NTC_Num_ReturnFWReached (199u)
 *   NTC_Num_DampingFWFltMode (200u)
 *   NTC_Num_AssistFWFltMode (201u)
 *   NTC_Num_VBICFltMode (202u)
 *   NTC_Num_WhlImbAlgFlt (224u)
 *   NTC_Num_PAHwVelFlt (225u)
 *   NTC_Num_AngleCntrlFltC (226u)
 *   NTC_Num_AngleCntrlFltD (227u)
 *   NTC_Num_AngleCntrlFltFG (228u)
 *   NTC_Num_BusOffCh1 (256u)
 *   NTC_Num_BusOffCh1NodeMute (257u)
 *   NTC_Num_Node1AAbsent (258u)
 *   NTC_Num_Node1AFaulty (259u)
 *   NTC_Num_Node1BAbsent (260u)
 *   NTC_Num_Node1BFaulty (261u)
 *   NTC_Num_Node1CAbsent (262u)
 *   NTC_Num_Node1CFaulty (263u)
 *   NTC_Num_Node1DAbsent (264u)
 *   NTC_Num_Node1DFaulty (265u)
 *   NTC_Num_Node1EAbsent (266u)
 *   NTC_Num_Node1EFaulty (267u)
 *   NTC_Num_Node1FAbsent (268u)
 *   NTC_Num_Node1FFaulty (269u)
 *   NTC_Num_Node1GAbsent (270u)
 *   NTC_Num_Node1GFaulty (271u)
 *   NTC_Num_BusOffCh2 (272u)
 *   NTC_Num_Node2AAbsent (273u)
 *   NTC_Num_Node2AFaulty (274u)
 *   NTC_Num_Node2BAbsent (275u)
 *   NTC_Num_Node2BFaulty (276u)
 *   NTC_Num_Node2CAbsent (277u)
 *   NTC_Num_Node2CFaulty (278u)
 *   NTC_Num_Node2DAbsent (279u)
 *   NTC_Num_Node2DFaulty (280u)
 *   NTC_Num_Node2EAbsent (281u)
 *   NTC_Num_Node2EFaulty (282u)
 *   NTC_Num_Node2FAbsent (283u)
 *   NTC_Num_Node2FFaulty (284u)
 *   NTC_Num_Node2GAbsent (285u)
 *   NTC_Num_Node2GFaulty (286u)
 *   NTC_Num_InvalidMsg_M (288u)
 *   NTC_Num_MissingMsg_M (289u)
 *   NTC_Num_CRCFltMsg_M (290u)
 *   NTC_Num_PgrsCntFltMsg_M (291u)
 *   NTC_Num_DataRngFltMsg_M (292u)
 *   NTC_Num_DataRateFltMsg_M (293u)
 *   NTC_Num_DataOtherFltMsg_M (294u)
 *   NTC_Num_InvalidMsg_N (296u)
 *   NTC_Num_MissingMsg_N (297u)
 *   NTC_Num_CRCFltMsg_N (298u)
 *   NTC_Num_PgrsCntFltMsg_N (299u)
 *   NTC_Num_DataRngFltMsg_N (300u)
 *   NTC_Num_DataRateFltMsg_N (301u)
 *   NTC_Num_DataOtherFltMsg_N (302u)
 *   NTC_Num_InvalidMsg_O (304u)
 *   NTC_Num_MissingMsg_O (305u)
 *   NTC_Num_CRCFltMsg_O (306u)
 *   NTC_Num_PgrsCntFltMsg_O (307u)
 *   NTC_Num_DataRngFltMsg_O (308u)
 *   NTC_Num_DataRateFltMsg_O (309u)
 *   NTC_Num_DataOtherFltMsg_O (310u)
 *   NTC_Num_InvalidMsg_P (312u)
 *   NTC_Num_MissingMsg_P (313u)
 *   NTC_Num_CRCFltMsg_P (314u)
 *   NTC_Num_PgrsCntFltMsg_P (315u)
 *   NTC_Num_DataRngFltMsg_P (316u)
 *   NTC_Num_DataRateFltMsg_P (317u)
 *   NTC_Num_DataOtherFltMsg_P (318u)
 *   NTC_Num_InvalidMsg_Q (320u)
 *   NTC_Num_MissingMsg_Q (321u)
 *   NTC_Num_CRCFltMsg_Q (322u)
 *   NTC_Num_PgrsCntFltMsg_Q (323u)
 *   NTC_Num_DataRngFltMsg_Q (324u)
 *   NTC_Num_DataRateFltMsg_Q (325u)
 *   NTC_Num_DataOtherFltMsg_Q (326u)
 *   NTC_Num_InvalidMsg_R (328u)
 *   NTC_Num_MissingMsg_R (329u)
 *   NTC_Num_CRCFltMsg_R (330u)
 *   NTC_Num_PgrsCntFltMsg_R (331u)
 *   NTC_Num_DataRngFltMsg_R (332u)
 *   NTC_Num_DataRateFltMsg_R (333u)
 *   NTC_Num_DataOtherFltMsg_R (334u)
 *   NTC_Num_InvalidMsg_S (336u)
 *   NTC_Num_MissingMsg_S (337u)
 *   NTC_Num_CRCFltMsg_S (338u)
 *   NTC_Num_PgrsCntFltMsg_S (339u)
 *   NTC_Num_DataRngFltMsg_S (340u)
 *   NTC_Num_DataRateFltMsg_S (341u)
 *   NTC_Num_DataOtherFltMsg_S (342u)
 *   NTC_Num_InvalidMsg_T (344u)
 *   NTC_Num_MissingMsg_T (345u)
 *   NTC_Num_CRCFltMsg_T (346u)
 *   NTC_Num_PgrsCntFltMsg_T (347u)
 *   NTC_Num_DataRngFltMsg_T (348u)
 *   NTC_Num_DataRateFltMsg_T (349u)
 *   NTC_Num_DataOtherFltMsg_T (350u)
 *   NTC_Num_InvalidMsg_U (352u)
 *   NTC_Num_MissingMsg_U (353u)
 *   NTC_Num_CRCFltMsg_U (354u)
 *   NTC_Num_PgrsCntFltMsg_U (355u)
 *   NTC_Num_DataRngFltMsg_U (356u)
 *   NTC_Num_DataRateFltMsg_U (357u)
 *   NTC_Num_DataOtherFltMsg_U (358u)
 *   NTC_Num_InvalidMsg_V (360u)
 *   NTC_Num_MissingMsg_V (361u)
 *   NTC_Num_CRCFltMsg_V (362u)
 *   NTC_Num_PgrsCntFltMsg_V (363u)
 *   NTC_Num_DataRngFltMsg_V (364u)
 *   NTC_Num_DataRateFltMsg_V (365u)
 *   NTC_Num_DataOtherFltMsg_V (366u)
 *   NTC_Num_InvalidMsg_W (368u)
 *   NTC_Num_MissingMsg_W (369u)
 *   NTC_Num_CRCFltMsg_W (370u)
 *   NTC_Num_PgrsCntFltMsg_W (371u)
 *   NTC_Num_DataRngFltMsg_W (372u)
 *   NTC_Num_DataRateFltMsg_W (373u)
 *   NTC_Num_DataOtherFltMsg_W (374u)
 *   NTC_Num_InvalidMsg_X (376u)
 *   NTC_Num_MissingMsg_X (377u)
 *   NTC_Num_CRCFltMsg_X (378u)
 *   NTC_Num_PgrsCntFltMsg_X (379u)
 *   NTC_Num_DataRngFltMsg_X (380u)
 *   NTC_Num_DataRateFltMsg_X (381u)
 *   NTC_Num_DataOtherFltMsg_X (382u)
 *   NTC_Num_InvalidMsg_Y (384u)
 *   NTC_Num_MissingMsg_Y (385u)
 *   NTC_Num_CRCFltMsg_Y (386u)
 *   NTC_Num_PgrsCntFltMsg_Y (387u)
 *   NTC_Num_DataRngFltMsg_Y (388u)
 *   NTC_Num_DataRateFltMsg_Y (389u)
 *   NTC_Num_DataOtherFltMsg_Y (390u)
 *   NTC_Num_InvalidMsg_Z (392u)
 *   NTC_Num_MissingMsg_Z (393u)
 *   NTC_Num_CRCFltMsg_Z (394u)
 *   NTC_Num_PgrsCntFltMsg_Z (395u)
 *   NTC_Num_DataRngFltMsg_Z (396u)
 *   NTC_Num_DataRateFltMsg_Z (397u)
 *   NTC_Num_DataOtherFltMsg_Z (398u)
 *   NTC_Num_InvalidMsg_AA (400u)
 *   NTC_Num_MissingMsg_AA (401u)
 *   NTC_Num_CRCFltMsg_AA (402u)
 *   NTC_Num_PgrsCntFltMsg_AA (403u)
 *   NTC_Num_DataRngFltMsg_AA (404u)
 *   NTC_Num_DataRateFltMsg_AA (405u)
 *   NTC_Num_DataOtherFltMsg_AA (406u)
 *   NTC_Num_InvalidMsg_AB (408u)
 *   NTC_Num_MissingMsg_AB (409u)
 *   NTC_Num_CRCFltMsg_AB (410u)
 *   NTC_Num_PgrsCntFltMsg_AB (411u)
 *   NTC_Num_DataRngFltMsg_AB (412u)
 *   NTC_Num_DataRateFltMsg_AB (413u)
 *   NTC_Num_DataOtherFltMsg_AB (414u)
 *   NTC_Num_InvalidMsg_AC (416u)
 *   NTC_Num_MissingMsg_AC (417u)
 *   NTC_Num_CRCFltMsg_AC (418u)
 *   NTC_Num_PgrsCntFltMsg_AC (419u)
 *   NTC_Num_DataRngFltMsg_AC (420u)
 *   NTC_Num_DataRateFltMsg_AC (421u)
 *   NTC_Num_DataOtherFltMsg_AC (422u)
 *   NTC_Num_InvalidMsg_AD (424u)
 *   NTC_Num_MissingMsg_AD (425u)
 *   NTC_Num_CRCFltMsg_AD (426u)
 *   NTC_Num_PgrsCntFltMsg_AD (427u)
 *   NTC_Num_DataRngFltMsg_AD (428u)
 *   NTC_Num_DataRateFltMsg_AD (429u)
 *   NTC_Num_DataOtherFltMsg_AD (430u)
 *   NTC_Num_InvalidMsg_AE (432u)
 *   NTC_Num_MissingMsg_AE (433u)
 *   NTC_Num_CRCFltMsg_AE (434u)
 *   NTC_Num_PgrsCntFltMsg_AE (435u)
 *   NTC_Num_DataRngFltMsg_AE (436u)
 *   NTC_Num_DataRateFltMsg_AE (437u)
 *   NTC_Num_DataOtherFltMsg_AE (438u)
 *   NTC_Num_InvalidMsg_AF (440u)
 *   NTC_Num_MissingMsg_AF (441u)
 *   NTC_Num_CRCFltMsg_AF (442u)
 *   NTC_Num_PgrsCntFltMsg_AF (443u)
 *   NTC_Num_DataRngFltMsg_AF (444u)
 *   NTC_Num_DataRateFltMsg_AF (445u)
 *   NTC_Num_DataOtherFltMsg_AF (446u)
 *   NTC_Num_InvalidMsg_AG (448u)
 *   NTC_Num_MissingMsg_AG (449u)
 *   NTC_Num_CRCFltMsg_AG (450u)
 *   NTC_Num_PgrsCntFltMsg_AG (451u)
 *   NTC_Num_DataRngFltMsg_AG (452u)
 *   NTC_Num_DataRateFltMsg_AG (453u)
 *   NTC_Num_DataOtherFltMsg_AG (454u)
 *   NTC_Num_InvalidMsg_AH (456u)
 *   NTC_Num_MissingMsg_AH (457u)
 *   NTC_Num_CRCFltMsg_AH (458u)
 *   NTC_Num_PgrsCntFltMsg_AH (459u)
 *   NTC_Num_DataRngFltMsg_AH (460u)
 *   NTC_Num_DataRateFltMsg_AH (461u)
 *   NTC_Num_DataOtherFltMsg_AH (462u)
 *   NTC_Num_FlexrayCommunicationError (465u)
 *   NTC_Num_SysConsistencyVerf (496u)
 *   NTC_Num_ConfigMisMatch (497u)
 *   NTC_Num_CalNotPrgmd (498u)
 *   NTC_Num_EOLVehTunNtPerf (501u)
 *   NTC_Num_MtrSensorNotTrimmed (502u)
 *   NTC_Num_HWASensorNotTrimmed (504u)
 *   NTC_Num_HWASensorTrimNoAttempt (505u)
 *   NTC_Num_TrqSensorScaleNotSet (506u)
 *   NTC_Num_TrqSensorNotTrimmed (507u)
 *   NTC_Num_DigTrqSensorScaleNotSet (509u)
 *   NTC_Num_DigTrqSensorNotTrimmed (510u)
 * NxtrDiagMgrStatus: Enumeration of integer in interval [0...255] with enumerators
 *   NTC_STATUS_PASSED (0u)
 *   NTC_STATUS_FAILED (1u)
 *   NTC_STATUS_PREPASSED (2u)
 *   NTC_STATUS_PREFAILED (3u)
 *
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * Defined Constants
 *
 **********************************************************************************************************************
 *
 * Primitive Type Constants:
 * =========================
 * Boolean: D_FALSE_CNT_LGC = FALSE
 * Float: D_2MS_SEC_F32 = 0.002
 * Float: D_ONE_ULS_F32 = 1
 * Float: D_ZERO_ULS_F32 = 0
 *
 *********************************************************************************************************************/


#define RTE_START_SEC_AP_ABSHWPOSSCOM_APPL_CODE
#include "MemMap.h"

/**********************************************************************************************************************
 *
 * Runnable Entity Name: AbsHwPosScom_Init1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_SystemTime_GetSystemTime_mS_u32(UInt32 *CurrentTime)
 *     Synchronous Service Invocation. Timeout: None
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_ABSHWPOSSCOM_APPL_CODE) AbsHwPosScom_Init1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: AbsHwPosScom_Init1
 *********************************************************************************************************************/


	Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_KinematicIntDiag, 0x01, NTC_STATUS_PASSED);

	HwPMtrVelT1Cal_MtrRadpS_M_f32 = k_AutoCtrMtrVelT1L_MtrRadpS_f32;
	HwPVSpdT1Cal_Kph_M_f32 = k_AutoCtrVehSpdT1L_Kph_f32;
	HwPPinTrqT1Cal_HwNm_M_f32 = k_AutoCtrPinTrqT1L_HwNm_f32;
	HwPTimer1Max_ms_M_u16 = k_HwPTimer1MaxL_ms_u16; 
	HwPWindowCal_HwDeg_M_f32 = k_AutoCtrWindowL_HwDeg_f32;
	HwPFilter1Kn_Hz_M_f32 = k_AutoCtrFiltOneCoeffkL_Hz_f32;
	HwPFilter2Kn_Hz_M_f32 = k_AutoCtrFiltTwoCoeffkL_Hz_f32;
	AutoCntrTrgtAuth_Uls_M_f32 = k_VDAuthL_Uls_f32;
	HwPTimer2Max_ms_M_u16 = k_AutoCtrTimer2LSpd_ms_u16; 

	HwPAutoCenter_Cnt_M_lgc = FALSE;
	HwPFilter1Init_Cnt_M_lgc = FALSE;
	HwPFilter2Init_Cnt_M_lgc = FALSE;

	RelToSComOffset_HwDeg_M_f32=0.0f;
	RelToScomOfstFound_Cnt_M_lgc = FALSE;

	VdynToScomErrorThy_HwDeg_M_f32 =Limit_m(VdynToScomErrorThy_HwDeg_M_f32, (-1.0F)*k_VdynToSComCorrLmt_HwDeg_f32, k_VdynToSComCorrLmt_HwDeg_f32);
	

	LPF_KUpdate_f32_m(k_AutoCtrPinTrqLPFCoeffK_Hz_f32, D_10MS_SEC_F32, &PinTrqFiltSV_HwNm_M_str);
	LPF_KUpdate_f32_m(HwPFilter1Kn_Hz_M_f32, D_10MS_SEC_F32, &HwPFilter1SV_HwDeg_M_Str); 
	LPF_KUpdate_f32_m(HwPFilter2Kn_Hz_M_f32, D_10MS_SEC_F32, &HwPFilter2SV_HwDeg_M_Str);
	LPF_KUpdate_f32_m(k_RbstPosLPFKn_Hz_f32, D_2MS_SEC_F32, &FinHwPosFiltSV_HwDeg_M_Str);



	Rte_Call_SystemTime_GetSystemTime_mS_u32(&StabilitySyncTimer_mS_M_u32);

	Rte_Call_SystemTime_GetSystemTime_mS_u32(&HwPTimer1_ms_M_u32);
	Rte_Call_SystemTime_GetSystemTime_mS_u32(&HwPTimer2_ms_M_u32);
	Rte_Call_SystemTime_GetSystemTime_mS_u32(&HwPTimer4_ms_M_u32);
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: AbsHwPosScom_Per1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 2ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Implicit S/R API:
 *   -----------------
 *   Float Rte_IRead_AbsHwPosScom_Per1_CRFCumMtrPos_Deg_f32(void)
 *   Float Rte_IRead_AbsHwPosScom_Per1_CRFMtrTrqCmd_MtrNm_f32(void)
 *   Float Rte_IRead_AbsHwPosScom_Per1_CRFMtrVel_MtrRadpS_f32(void)
 *   Boolean Rte_IRead_AbsHwPosScom_Per1_DiagStsHwPosDis_Cnt_lgc(void)
 *   Float Rte_IRead_AbsHwPosScom_Per1_HwTrq_HwNm_f32(void)
 *   Boolean Rte_IRead_AbsHwPosScom_Per1_SComInpHwAValid_Cnt_lgc(void)
 *   Float Rte_IRead_AbsHwPosScom_Per1_SComInpHwA_HwDeg_f32(void)
 *   Boolean Rte_IRead_AbsHwPosScom_Per1_VehicleSpeedValid_Cnt_lgc(void)
 *   Float Rte_IRead_AbsHwPosScom_Per1_VehicleSpeed_Kph_f32(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_AbsHwPosScom_Per1_HwPosAuthority_Uls_f32(Float data)
 *   Float *Rte_IWriteRef_AbsHwPosScom_Per1_HwPosAuthority_Uls_f32(void)
 *   void Rte_IWrite_AbsHwPosScom_Per1_HwPos_HwDeg_f32(Float data)
 *   Float *Rte_IWriteRef_AbsHwPosScom_Per1_HwPos_HwDeg_f32(void)
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(UInt32 InitialTime, UInt16 *ElapsedTime)
 *     Synchronous Service Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_SystemTime_GetSystemTime_mS_u32(UInt32 *CurrentTime)
 *     Synchronous Service Invocation. Timeout: None
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_ABSHWPOSSCOM_APPL_CODE) AbsHwPosScom_Per1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: AbsHwPosScom_Per1
 *********************************************************************************************************************/
	VAR(float32, AUTOMATIC) CRFCumMtrPos_Deg_T_f32;
	VAR(float32, AUTOMATIC) CRFMtrTrqCmd_MtrNm_T_f32;
	VAR(float32, AUTOMATIC) MtrPos_HwDeg_T_f32;
	VAR(uint16, AUTOMATIC) CRFMtrTrqCmd_MtrNm_T_u8p8;
	VAR(uint16, AUTOMATIC) MtrCompl_HwDegpMtrNm_T_u6p10;
	VAR(float32, AUTOMATIC) MtrCompl_HwDegpMtrNm_T_f32;
	VAR(float32, AUTOMATIC) CRFMtrTrqCmdAbs_MtrNm_T_f32;

	
	/* From old ScombasedHwPos  */

	
	VAR(float32, AUTOMATIC) CRFMtrVel_MtrRadpS_T_f32;
	VAR(float32, AUTOMATIC) MtrBasedPos_HwDeg_T_f32;
	VAR(boolean, AUTOMATIC) VehSpdValid_Cnt_T_lgc;
	VAR(float32, AUTOMATIC) VehSpd_Kph_T_f32;
	VAR(float32, AUTOMATIC) PinionTrq_HwNm_T_f32;
	VAR(float32, AUTOMATIC) SnsrlessHwPos_HwDeg_T_f32;
	VAR(float32, AUTOMATIC) SrlComRxHwPos_HwDeg_T_f32;
	VAR(boolean, AUTOMATIC) SrlComHwPosVld_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) DiagStsHwPosDis_Cnt_T_lgc;
	VAR(float32, AUTOMATIC)	DeltaHwPos_HwDeg_T_f32;
	VAR(float32, AUTOMATIC)	TempHwPos_HwDeg_T_f32;
	VAR(uint16, AUTOMATIC) ElapsedTime_mS_T_u16;
	VAR(float32, AUTOMATIC) HwTrq_HwNm_T_f32;
	VAR(float32, AUTOMATIC) HwTrqAbs_HwNm_T_f32;
	VAR(float32, AUTOMATIC)	CRFMtrVelAbs_MtrRadpS_T_f32;
	VAR(float32, AUTOMATIC)	HwPosTrgtAuth_Uls_T_f32;
	
	/* Configurable Start of Runnable Checkpoint */
	Rte_Call_AbsHwPosScom_Per1_CP0_CheckpointReached();
	
	HwPosTrgtAuth_Uls_T_f32 = 0.0F;
	TempHwPos_HwDeg_T_f32 = 0.0F;

	
 
	/* Acess Rte */
	CRFMtrVel_MtrRadpS_T_f32 = Rte_IRead_AbsHwPosScom_Per1_CRFMtrVel_MtrRadpS_f32();
	VehSpdValid_Cnt_T_lgc = Rte_IRead_AbsHwPosScom_Per1_VehicleSpeedValid_Cnt_lgc();
	VehSpd_Kph_T_f32 = Rte_IRead_AbsHwPosScom_Per1_VehicleSpeed_Kph_f32();
	SrlComRxHwPos_HwDeg_T_f32 = Rte_IRead_AbsHwPosScom_Per1_SComInpHwA_HwDeg_f32();
	SrlComHwPosVld_Cnt_T_lgc = Rte_IRead_AbsHwPosScom_Per1_SComInpHwAValid_Cnt_lgc();
	DiagStsHwPosDis_Cnt_T_lgc = Rte_IRead_AbsHwPosScom_Per1_DiagStsHwPosDis_Cnt_lgc();
	HwTrq_HwNm_T_f32 = Rte_IRead_AbsHwPosScom_Per1_HwTrq_HwNm_f32();
	
	PinionTrq_HwNm_T_f32 = FiltPinionTrq_HwNm_M_f32;
	

	/* scale and compliance error calculation */
	CRFCumMtrPos_Deg_T_f32 = Rte_IRead_AbsHwPosScom_Per1_CRFCumMtrPos_Deg_f32();
	CRFMtrTrqCmd_MtrNm_T_f32 = Rte_IRead_AbsHwPosScom_Per1_CRFMtrTrqCmd_MtrNm_f32();
	CRFMtrTrqCmdAbs_MtrNm_T_f32 = Abs_f32_m(CRFMtrTrqCmd_MtrNm_T_f32);
	HwTrqAbs_HwNm_T_f32 = Abs_f32_m(HwTrq_HwNm_T_f32);
	CRFMtrVelAbs_MtrRadpS_T_f32 = Abs_f32_m(CRFMtrVel_MtrRadpS_T_f32);

	CRFMtrTrqCmd_MtrNm_T_u8p8 = FPM_FloatToFixed_m(CRFMtrTrqCmdAbs_MtrNm_T_f32, u8p8_T);

	MtrCompl_HwDegpMtrNm_T_u6p10 = IntplVarXY_u16_u16Xu16Y_Cnt( 
                                           t_MtrPosComplTblX_MtrNm_u8p8,
                                           t_MtrPosComplTblY_HwDegpMtrNm_u6p10,
                                           TableSize_m(t_MtrPosComplTblX_MtrNm_u8p8),
                                           CRFMtrTrqCmd_MtrNm_T_u8p8);

	MtrCompl_HwDegpMtrNm_T_f32 = FPM_FixedToFloat_m(MtrCompl_HwDegpMtrNm_T_u6p10, u6p10_T);

	/*Compliance Error calculated */
	MtrComplErr_HwDeg_M_f32 = MtrCompl_HwDegpMtrNm_T_f32 * CRFMtrTrqCmd_MtrNm_T_f32;
	MtrPos_HwDeg_T_f32 = CRFCumMtrPos_Deg_T_f32 / k_InvGearRatio_Uls_f32;


  	ScaledMtrPos_HwDeg_M_f32 = MtrPos_HwDeg_T_f32 - MtrComplErr_HwDeg_M_f32;

	MtrBasedPos_HwDeg_T_f32 = ScaledMtrPos_HwDeg_M_f32;

	/*MtrBasedPos_HwDeg_T_f32 = Limit_m(MtrBasedPos_HwDeg_T_f32,D_ABSPOSLOLMT_HWDEG_F32,D_ABSPOSHILMT_HWDEG_F32);
	MtrBasedPos_HwDeg_T_s11p4 = FPM_FloatToFixed_m(MtrBasedPos_HwDeg_T_f32, s11p4_T);*/


	HwPFilter1En_Cnt_M_lgc = Filter1Enable(CRFMtrVel_MtrRadpS_T_f32, VehSpd_Kph_T_f32, VehSpdValid_Cnt_T_lgc, PinionTrq_HwNm_T_f32);
	HwPFilter2En_Cnt_M_lgc = Filter2Enable(MtrBasedPos_HwDeg_T_f32, HwPFilter1En_Cnt_M_lgc);


	/*Generate ScomHwPos */
	if(TRUE == HwPosSrvSetToZero_Cnt_M_lgc)
	{
		if(FALSE == RelToScomOfstFound_Cnt_M_lgc)
		{
			RelToScomOfstFound_Cnt_M_lgc = TRUE;
			RelToSComOffset_HwDeg_M_f32 = 0.0f - ScaledMtrPos_HwDeg_M_f32;
		}
		ScomHwPosAuth();
	}
	else 
	{
		if(TRUE == SrlComHwPosVld_Cnt_T_lgc)
		{
			Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(StabilitySyncTimer_mS_M_u32,&ElapsedTime_mS_T_u16);


			if(ElapsedTime_mS_T_u16 >= k_HwPosVehStabilityTime_mS_u16)
			{
				Rte_Call_SystemTime_GetSystemTime_mS_u32(&StabilitySyncTimer_mS_M_u32);
				RelToSComOffset_HwDeg_M_f32 = SrlComRxHwPos_HwDeg_T_f32 - ScaledMtrPos_HwDeg_M_f32;
				RelToScomOfstFound_Cnt_M_lgc = TRUE;
				ScomHwPosAuth();

			}
			else
			{
				if( (CRFMtrTrqCmdAbs_MtrNm_T_f32 <= k_HwPosVehStabilityTrqCmd_MtrNm_f32) && (HwTrqAbs_HwNm_T_f32 <= k_HwPosVehStabilityHwTrq_HwNm_f32)  &&  (CRFMtrVelAbs_MtrRadpS_T_f32 <= k_HwPosVehStabilityMtrVel_MtrRadpS_f32))
				{
					ScomHwPosAuth();

				}
				else 
				{
					Rte_Call_SystemTime_GetSystemTime_mS_u32(&StabilitySyncTimer_mS_M_u32);	
					ScomHwPosAuth();

				}
		   }
		}
		else
		{
			Rte_Call_SystemTime_GetSystemTime_mS_u32(&StabilitySyncTimer_mS_M_u32);	
			NewScomInpHwA_HwDeg_M_f32 = 0.0f;
			ScomHwPosAuth_Uls_M_f32 = 0.0f;
		}
	}


	/*Select HwPos */

	if (FALSE == HwPHighSpdAC_Cnt_M_lgc)
	{
		CalSwitchTimer(CRFMtrVel_MtrRadpS_T_f32, VehSpd_Kph_T_f32, VehSpdValid_Cnt_T_lgc, PinionTrq_HwNm_T_f32, &HwPFilter1En_Cnt_M_lgc, &HwPFilter2En_Cnt_M_lgc);
	}

	if (FALSE == DiagStsHwPosDis_Cnt_T_lgc)
    {
       if(Abs_f32_m(ScomHwPosAuth_Uls_M_f32 - k_ScomHwPosAuth_Uls_f32) <= FLT_EPSILON)
        {
           
			TempHwPos_HwDeg_T_f32 = NewScomInpHwA_HwDeg_M_f32;
			HwPosTrgtAuth_Uls_T_f32 = k_ScomHwPosAuth_Uls_f32;
        }

		else if (Abs_f32_m(VehDynTrgtAuth_Uls_M_f32 - k_HiSpdAcAuth_Uls_f32) <= FLT_EPSILON)
		{
			TempHwPos_HwDeg_T_f32 = VehDynTrgtAngle_HwDeg_M_f32;
			HwPosTrgtAuth_Uls_T_f32 = VehDynTrgtAuth_Uls_M_f32;

		}

		else if(Abs_f32_m(VehDynTrgtAuth_Uls_M_f32 - k_VDAuthL_Uls_f32) <= FLT_EPSILON )
		{
			TempHwPos_HwDeg_T_f32 = VehDynTrgtAngle_HwDeg_M_f32;
			HwPosTrgtAuth_Uls_T_f32 = VehDynTrgtAuth_Uls_M_f32;
		}
        else
        {
        	/* Default is 0 HwDeg, No Conf, Learn EOT = False.  Per temp var init*/
        }
	}

	TempHwPos_HwDeg_M_f32 = TempHwPos_HwDeg_T_f32;


  /*Output Soothing LowPassFilter - Below correct LPF*/
	DeltaHwPos_HwDeg_T_f32 = FinHwPosLPFOp_HwDeg_M_f32 - TempHwPos_HwDeg_T_f32;
	
	if (Abs_f32_m(DeltaHwPos_HwDeg_T_f32) < k_HwPosOpLPFError_HwDeg_f32)
	{
		

		LPF_Init_f32_m(TempHwPos_HwDeg_T_f32, k_RbstPosLPFKn_Hz_f32, D_2MS_SEC_F32, &FinHwPosFiltSV_HwDeg_M_Str);
	}
														
		FinHwPosLPFOp_HwDeg_M_f32 = LPF_OpUpdate_f32_m(TempHwPos_HwDeg_T_f32, &FinHwPosFiltSV_HwDeg_M_Str);

	
	FinHwAuth_Uls_M_f32 = Limit_m(HwPosTrgtAuth_Uls_T_f32,(FinHwAuth_Uls_M_f32-k_HwPosAuthorityStep_Uls_f32), (FinHwAuth_Uls_M_f32+k_HwPosAuthorityStep_Uls_f32));


/*OUTPUTS*/

	HwPosTrgtAuth_Uls_T_f32 = Min_m(FinHwAuth_Uls_M_f32,  D_ONE_ULS_F32);


	FinHwPosLPFOp_HwDeg_M_f32 = Limit_m(FinHwPosLPFOp_HwDeg_M_f32, D_ABSPOSLOLMT_HWDEG_F32, D_ABSPOSHILMT_HWDEG_F32);
	Rte_IWrite_AbsHwPosScom_Per1_HwPos_HwDeg_f32(FinHwPosLPFOp_HwDeg_M_f32);  
	            

	Rte_IWrite_AbsHwPosScom_Per1_HwPosAuthority_Uls_f32(HwPosTrgtAuth_Uls_T_f32);
    /* Configurable End of Runnable Checkpoint */
    Rte_Call_AbsHwPosScom_Per1_CP1_CheckpointReached();

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: AbsHwPosScom_Per2
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 10ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Implicit S/R API:
 *   -----------------
 *   Boolean Rte_IRead_AbsHwPosScom_Per2_KinIntDiagSrlComSvcDft_Cnt_lgc(void)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_ABSHWPOSSCOM_APPL_CODE) AbsHwPosScom_Per2(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: AbsHwPosScom_Per2
 *********************************************************************************************************************/
	VAR(uint32, AUTOMATIC) KinIntDiagSComSvcDft_Cnt_T_lgc;
	/* Configurable Start of Runnable Checkpoint */
	Rte_Call_AbsHwPosScom_Per2_CP0_CheckpointReached();

	
	KinIntDiagSComSvcDft_Cnt_T_lgc =Rte_IRead_AbsHwPosScom_Per2_KinIntDiagSrlComSvcDft_Cnt_lgc();
 
	if((Abs_f32_m(ScaledMtrPos_HwDeg_M_f32)) > k_KinmIntDiagMaxRackLmt_HwDeg_f32)
	{
	   if(FALSE == KinIntDiagSComSvcDft_Cnt_T_lgc)
	   {
	      
		   Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_KinematicIntDiag, 0x01, NTC_STATUS_FAILED);
	   }
	   else
	   {
	     /* Do Nothing */
	   }
	}
	else
	{
	   /* Do Nothing */ 
	}
    /* Configurable End of Runnable Checkpoint */
    Rte_Call_AbsHwPosScom_Per2_CP1_CheckpointReached();

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: AbsHwPosScom_Per3
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 10ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Implicit S/R API:
 *   -----------------
 *   Float Rte_IRead_AbsHwPosScom_Per3_CRFMtrTrqCmd_MtrNm_f32(void)
 *   Float Rte_IRead_AbsHwPosScom_Per3_HwTrq_HwNm_f32(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_ABSHWPOSSCOM_APPL_CODE) AbsHwPosScom_Per3(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: AbsHwPosScom_Per3
 *********************************************************************************************************************/
	VAR(boolean, AUTOMATIC) HwPFilter1En_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) HwPFilter2En_Cnt_T_lgc;
	VAR(float32, AUTOMATIC) MtrBasedPos_HwDeg_T_f32;
	VAR(float32, AUTOMATIC) CRFMtrTrqCmd_MtrNm_T_f32;
	VAR(float32, AUTOMATIC) HwTrq_HwNm_T_f32;
	VAR(float32, AUTOMATIC) PinionTrq_HwNm_T_f32;
	VAR(float32, AUTOMATIC) FiltPinionTrq_HwNm_T_f32;
   
    /* Configurable Start of Runnable Checkpoint */
	Rte_Call_AbsHwPosScom_Per3_CP0_CheckpointReached();

	CRFMtrTrqCmd_MtrNm_T_f32 = Rte_IRead_AbsHwPosScom_Per3_CRFMtrTrqCmd_MtrNm_f32();
	HwTrq_HwNm_T_f32 = Rte_IRead_AbsHwPosScom_Per3_HwTrq_HwNm_f32();

	HwPFilter1En_Cnt_T_lgc = HwPFilter1En_Cnt_M_lgc;
	HwPFilter2En_Cnt_T_lgc = HwPFilter2En_Cnt_M_lgc;
	
	/*Initialize RelHwPos with ScaledMtrPos */
	RelHwPos_HwDeg_M_f32 = ScaledMtrPos_HwDeg_M_f32;

	MtrBasedPos_HwDeg_T_f32 = RelHwPos_HwDeg_M_f32;
	
   
	PinionTrq_HwNm_T_f32 = HwTrq_HwNm_T_f32 + (CRFMtrTrqCmd_MtrNm_T_f32 * k_InvGearRatio_Uls_f32);
   

	FiltPinionTrq_HwNm_T_f32 = LPF_OpUpdate_f32_m(PinionTrq_HwNm_T_f32, &PinTrqFiltSV_HwNm_M_str);


	/*Filtered PinionTrq */
	FiltPinionTrq_HwNm_M_f32 = FiltPinionTrq_HwNm_T_f32;

	HwPosSLFilter1(MtrBasedPos_HwDeg_T_f32, HwPFilter1En_Cnt_T_lgc);
	HwPosSLFilter2(MtrBasedPos_HwDeg_T_f32, HwPFilter2En_Cnt_T_lgc);

    /* Configurable End of Runnable Checkpoint */
    Rte_Call_AbsHwPosScom_Per3_CP1_CheckpointReached();





/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: AbsHwPosScom_Scom_HwPosSrvRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <HwPosSrvRead> of PortPrototype <AbsHwPosScom_Scom>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void AbsHwPosScom_Scom_HwPosSrvRead(Boolean *Par)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_ABSHWPOSSCOM_APPL_CODE) AbsHwPosScom_Scom_HwPosSrvRead(P2VAR(Boolean, AUTOMATIC, RTE_AP_ABSHWPOSSCOM_APPL_VAR) Par)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: AbsHwPosScom_Scom_HwPosSrvRead
 *********************************************************************************************************************/
	*Par = HwPosSrvSetToZero_Cnt_M_lgc;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: AbsHwPosScom_Scom_HwPosSrvSetToZero
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <HwPosSrvSetToZero> of PortPrototype <AbsHwPosScom_Scom>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void AbsHwPosScom_Scom_HwPosSrvSetToZero(Boolean Par)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_ABSHWPOSSCOM_APPL_CODE) AbsHwPosScom_Scom_HwPosSrvSetToZero(Boolean Par)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: AbsHwPosScom_Scom_HwPosSrvSetToZero
 *********************************************************************************************************************/
HwPosSrvSetToZero_Cnt_M_lgc = Par;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define RTE_STOP_SEC_AP_ABSHWPOSSCOM_APPL_CODE
#include "MemMap.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

 #define RTE_START_SEC_AP_ABSHWPOSSCOM_APPL_CODE
#include "MemMap.h"
STATIC FUNC(void, AP_ABSHWPOSSCOM_CODE) HwPosSLFilter1(	VAR(float32, AUTOMATIC) MtrPos_HwDeg_T_f32,
															VAR(boolean, AUTOMATIC) FilterEn)
{
	VAR(float32, AUTOMATIC) Temp_HwPFilter1Out;
   
	if (TRUE == FilterEn)
	{
		if (FALSE == HwPFilter1Init_Cnt_M_lgc)
		{
			
			LPF_Init_f32_m(MtrPos_HwDeg_T_f32, HwPFilter1Kn_Hz_M_f32, D_10MS_SEC_F32, &HwPFilter1SV_HwDeg_M_Str);
         	HwPFilter1Init_Cnt_M_lgc = TRUE;
		}
      
		Temp_HwPFilter1Out = LPF_OpUpdate_f32_m(MtrPos_HwDeg_T_f32, &HwPFilter1SV_HwDeg_M_Str);

		HwPFilter1Prev_HwDeg_M_f32 = HwPFilter1Out_HwDeg_M_f32;
      	HwPFilter1Out_HwDeg_M_f32 = Temp_HwPFilter1Out;
	}
}


STATIC FUNC(void, AP_ABSHWPOSSCOM_CODE) HwPosSLFilter2(	VAR(float32, AUTOMATIC) MtrPos_HwDeg_T_f32,
															VAR(boolean, AUTOMATIC) FilterEn)
{
	if (TRUE == FilterEn)
	{
		if (FALSE == HwPFilter2Init_Cnt_M_lgc)
		{
			
			LPF_Init_f32_m(HwPFilter1Out_HwDeg_M_f32, HwPFilter2Kn_Hz_M_f32, D_10MS_SEC_F32, &HwPFilter2SV_HwDeg_M_Str);
         	HwPFilter2Init_Cnt_M_lgc = TRUE;
         	HwPAutoCenter_Cnt_M_lgc = TRUE;
		}
      
		HwPFilter2Out_HwDeg_M_f32 = LPF_OpUpdate_f32_m(MtrPos_HwDeg_T_f32, &HwPFilter2SV_HwDeg_M_Str);
	}
}


STATIC FUNC(boolean, AP_ABSHWPOSSCOM_CODE) Filter1Enable(	VAR(float32, AUTOMATIC) CRFMtrVel_MtrRadpS_T_f32,
															VAR(float32, AUTOMATIC) VehSpd_Kph_T_f32,
															VAR(boolean, AUTOMATIC) VSpdValid_Cnt_T_lgc,
															VAR(float32, AUTOMATIC) PinionTrq_HwNm_T_f32)
{
	VAR(boolean, AUTOMATIC) HwPFilter1En_Cnt_T_lgc;
	VAR(uint16, AUTOMATIC) ElapsedTime_mS_T_u16;
	VAR(float32, AUTOMATIC) AbsCRFMtrVel_MtrRadpS_T_f32;
	VAR(float32, AUTOMATIC) AbsPinionTrq_HwNm_T_f32;


	AbsCRFMtrVel_MtrRadpS_T_f32 = Abs_f32_m(CRFMtrVel_MtrRadpS_T_f32);
	AbsPinionTrq_HwNm_T_f32 = Abs_f32_m(PinionTrq_HwNm_T_f32);

	if ((AbsCRFMtrVel_MtrRadpS_T_f32 <= HwPMtrVelT1Cal_MtrRadpS_M_f32) &&
       (VehSpd_Kph_T_f32 >= HwPVSpdT1Cal_Kph_M_f32) && 
       (TRUE == VSpdValid_Cnt_T_lgc) && 
       (AbsPinionTrq_HwNm_T_f32 <= HwPPinTrqT1Cal_HwNm_M_f32))
	{
		/* Enable conditions satisfied */
		Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(HwPTimer1_ms_M_u32,&ElapsedTime_mS_T_u16);
     	if (ElapsedTime_mS_T_u16 >= HwPTimer1Max_ms_M_u16)
		{
        	HwPFilter1En_Cnt_T_lgc = TRUE;
        }
      	else
		{
			HwPFilter1En_Cnt_T_lgc = FALSE;
		
		}
	}
   	else
	{
		Rte_Call_SystemTime_GetSystemTime_mS_u32(&HwPTimer1_ms_M_u32);
		HwPFilter1En_Cnt_T_lgc = FALSE;
	}
	
	return (HwPFilter1En_Cnt_T_lgc);
}


STATIC FUNC(boolean, AP_ABSHWPOSSCOM_CODE) Filter2Enable(	VAR(float32, AUTOMATIC) MtrPos_HwDeg_T_f32,
															VAR(boolean, AUTOMATIC) HwPFilter1En_Cnt_T_lgc)
{
	VAR(boolean, AUTOMATIC) HwPFilter2En_Cnt_T_lgc;
	VAR(uint16, AUTOMATIC) ElapsedTime_mS_T_u16;
	VAR(float32, AUTOMATIC) AbsMtrPosFilt_HwDeg_T_f32;
	
	AbsMtrPosFilt_HwDeg_T_f32 = Abs_f32_m(MtrPos_HwDeg_T_f32 - HwPFilter1Out_HwDeg_M_f32);

	if ((AbsMtrPosFilt_HwDeg_T_f32 <= HwPWindowCal_HwDeg_M_f32) &&
        (TRUE == HwPFilter1En_Cnt_T_lgc))
	{
		Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(HwPTimer2_ms_M_u32,&ElapsedTime_mS_T_u16);
		if (ElapsedTime_mS_T_u16 >= HwPTimer2Max_ms_M_u16)
		{
			HwPFilter2En_Cnt_T_lgc = TRUE;
			VehDynTrgtAuth_Uls_M_f32 = AutoCntrTrgtAuth_Uls_M_f32;
		}
      	else
		{
			HwPFilter2En_Cnt_T_lgc = FALSE;
		}
	}
	else
	{
		Rte_Call_SystemTime_GetSystemTime_mS_u32(&HwPTimer2_ms_M_u32);
		HwPFilter2En_Cnt_T_lgc = FALSE;
	}
      
	if(HwPAutoCenter_Cnt_M_lgc == TRUE)
	{
		VehDynTrgtAngle_HwDeg_M_f32 =  MtrPos_HwDeg_T_f32 -HwPFilter2Out_HwDeg_M_f32;
	}
	
	return (HwPFilter2En_Cnt_T_lgc);
}



STATIC FUNC(void, AP_ABSHWPOSSCOM_CODE) CalSwitchTimer(	VAR(float32, AUTOMATIC) CRFMtrVel_MtrRadpS_T_f32,
															VAR(float32, AUTOMATIC) VehSpd_Kph_T_f32,
															VAR(boolean, AUTOMATIC) VSpdValid_Cnt_T_lgc,
															VAR(float32, AUTOMATIC) PinionTrq_HwNm_T_f32,
															CONSTP2VAR(boolean, AUTOMATIC, AP_SCOMBASEDHWPOS_CONST) HwPFilter1En_Cnt_T_lgc,
															CONSTP2VAR(boolean, AUTOMATIC, AP_SCOMBASEDHWPOS_CONST) HwPFilter2En_Cnt_T_lgc)
{
	VAR(uint16, AUTOMATIC) ElapsedTime_mS_T_u16;
		VAR(float32, AUTOMATIC) AbsCRFMtrVel_MtrRadpS_T_f32;
	VAR(float32, AUTOMATIC) AbsPinionTrq_HwNm_T_f32;
	VAR(float32, AUTOMATIC) AbsHwFilter_HwDeg_T_f32;

	AbsCRFMtrVel_MtrRadpS_T_f32 = Abs_f32_m(CRFMtrVel_MtrRadpS_T_f32);
	AbsPinionTrq_HwNm_T_f32 = Abs_f32_m(PinionTrq_HwNm_T_f32);
	AbsHwFilter_HwDeg_T_f32 = Abs_f32_m(HwPFilter1Out_HwDeg_M_f32 - HwPFilter1Prev_HwDeg_M_f32);

	if ((AbsCRFMtrVel_MtrRadpS_T_f32 <= k_MtrVelTmr4H_MtrRadpS_f32) && 
        (VehSpd_Kph_T_f32 >= k_VehSpdTmr4H_kph_f32) &&
        (VSpdValid_Cnt_T_lgc == TRUE) &&
        (AbsPinionTrq_HwNm_T_f32 <= k_PinTrqTmr4H_HwNm_f32))

	{
		if ((TRUE == *HwPFilter1En_Cnt_T_lgc) &&
            (AbsHwFilter_HwDeg_T_f32 <= k_Tmr4CntrWindowH_HwDeg_f32))
		{
			/* Enable conditions satisfied */
			Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(HwPTimer4_ms_M_u32,&ElapsedTime_mS_T_u16);
			if (ElapsedTime_mS_T_u16 >=  k_AutoCtrTimer4H_ms_u16 )

			{
				/* AutoCenter Output */
            	HwPHighSpdAC_Cnt_M_lgc = TRUE;
                       
            	/* Reset Timer1 and clear flags so that the computation could be done with High speed cals*/
            	Rte_Call_SystemTime_GetSystemTime_mS_u32(&HwPTimer1_ms_M_u32);
			   	*HwPFilter1En_Cnt_T_lgc = FALSE;
            	*HwPFilter2En_Cnt_T_lgc = FALSE;

				/*Switch to High Speed Calibration Values*/
			 	HwPMtrVelT1Cal_MtrRadpS_M_f32 = k_HwPMtrVelT1H_MtrRadpS_f32;
			 	HwPVSpdT1Cal_Kph_M_f32 = k_HwPVehSpdT1H_Kph_f32;
			 	HwPPinTrqT1Cal_HwNm_M_f32 = k_HwPPinionTrqT1H_HwNm_f32;
		 	 	HwPTimer1Max_ms_M_u16 = k_HwPTimer1MaxH_ms_u16;
		     	HwPWindowCal_HwDeg_M_f32 = k_HwPWindowCalH_HwDeg_f32;
			 	HwPFilter1Kn_Hz_M_f32 = k_HwPFilter1KnH_Hz_f32;
			 	HwPFilter2Kn_Hz_M_f32 = k_HwPFilter2KnH_Hz_f32;
			 	AutoCntrTrgtAuth_Uls_M_f32 = k_HiSpdAcAuth_Uls_f32;
				HwPTimer2Max_ms_M_u16 = k_HwPTmr2MaxHiSpd_ms_u16;
			}
		 	
		}
      	else
		{
			Rte_Call_SystemTime_GetSystemTime_mS_u32(&HwPTimer4_ms_M_u32);
		}
	}
	else
	{
		Rte_Call_SystemTime_GetSystemTime_mS_u32(&HwPTimer4_ms_M_u32);
	}
}




STATIC FUNC(void, AP_ABSHWPOSSCOM_CODE) ScomHwPosAuth(void)
{
	VAR(float32, AUTOMATIC) ScomInpHwATemp_HwDeg_T_f32;
	VAR(float32, AUTOMATIC) VdynToScomError_HwDeg_T_f32;

ScomInpHwATemp_HwDeg_T_f32 = RelToSComOffset_HwDeg_M_f32 + ScaledMtrPos_HwDeg_M_f32;

	if(VehDynTrgtAuth_Uls_M_f32 >= k_HiSpdAcAuth_Uls_f32)
	{
		
		VdynToScomError_HwDeg_T_f32 = VehDynTrgtAngle_HwDeg_M_f32 - ScomInpHwATemp_HwDeg_T_f32;

		if( Abs_f32_m(VdynToScomError_HwDeg_T_f32) <= k_VdynToScomMaxErr_HwDeg_f32 )
		{
			VdynToScomErrorThy_HwDeg_M_f32 = Limit_m(VdynToScomError_HwDeg_T_f32, (-1.0f)*k_VdynToSComCorrLmt_HwDeg_f32, k_VdynToSComCorrLmt_HwDeg_f32);
			NewScomInpHwA_HwDeg_M_f32 = ScomInpHwATemp_HwDeg_T_f32 + VdynToScomErrorThy_HwDeg_M_f32;
			if(TRUE == RelToScomOfstFound_Cnt_M_lgc )
			{
			ScomHwPosAuth_Uls_M_f32 = k_ScomHwPosAuth_Uls_f32;
			}
			else
			{
			ScomHwPosAuth_Uls_M_f32 = 0.0F;
			}
		}
		else
		{
			ScomHwPosAuth_Uls_M_f32 = 0.0F;
		}

	}
	else 
	{
			NewScomInpHwA_HwDeg_M_f32 = ScomInpHwATemp_HwDeg_T_f32 + VdynToScomErrorThy_HwDeg_M_f32;
			if(TRUE == RelToScomOfstFound_Cnt_M_lgc )
			{
			ScomHwPosAuth_Uls_M_f32 = k_ScomHwPosAuth_Uls_f32;
			}
			else
			{
			ScomHwPosAuth_Uls_M_f32 = 0.0F;
			}
			
	}

}






#define RTE_STOP_SEC_AP_ABSHWPOSSCOM_APPL_CODE
#include "MemMap.h"
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
