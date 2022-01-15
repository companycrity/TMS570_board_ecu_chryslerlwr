/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Sa_BkCpPc.c
 *     Workspace:  C:/cmsynergy/CBD_BkCpPc_FDD11B/BkCpPc-wz7x3j/BkCpPc/autosar/Sa_BkCpPc.dcf
 *     SW-C Type:  Sa_BkCpPc
 *  Generated at:  Tue Jun  4 16:28:43 2013
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1 (Beta)
 *       License:  License CBD1010124 valid for CBD1010124 Nexteer  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  C-Code implementation template for SW-C <Sa_BkCpPc>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/* Version Control:
 * Date Created:      Wed Sep 12 10:31:35 2012
 * %version:          8 %
 * %derived_by:       wz7x3j %
 * %date_modified:    Wed Jun  5 11:34:00 2013 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author    Change Description                                                           SCR #
 * --------  -------  --------  ---------------------------------------------------------------------------  ----------
 * 09/12/12  1        OT        Initial Version (FDD 11B v001)                                               6165
 * 09/27/12  2        OT        Added Trns2 (Warm Init state reset)                                          6365
 * 10/24/12  3        OT        Anomaly 3912 - write outputs in all branches                                 6632
 * 27/02/13	 4       Selva      Updated to version 3 FDD 11B                                                      
 * 03/01/13	 5	     Selva      Set RunTimeFaultAcc_Cnt_M_u16 to zero  in tans 2
 * 05/29/13	 6	      BDO       Anomaly 5092 - add power disconnect configurable parameter                   8486
 * 06/04/13  7        BDO       Anomaly 5122 - updates to support Configuration A integration                8543
 * 06/05/13  8        BDO       Set PwrDiscATestComplete in BULKCAP_PRECHARGE state for Configuration A      8543
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *
 * AUTOSAR Modelling Object Descriptions
 *
 **********************************************************************************************************************

 Data Element Prototypes:
 ========================
  Volt_f32 of Port Interface Voltage_Volt_f32
    This signal is intended to communicate any type voltage signal measured by the ecu.  This signal has a lower limit of 0 which reequires users of the signal to provide divide by 0 protection if it is used as a denominator in a calculation.  See Vecu port prototype if a port with a lower limit is desired.


 Operation Prototypes:
 =====================
  DtrmnElapsedTime_mS_u16 of Port Interface SystemTime
    Nexteer SystemTime Service


 Mode Declaration Groups:
 ========================
  StaMd_Mode
    EPS System State mode declaration

 *********************************************************************************************************************/

#include "Rte_Sa_BkCpPc.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


#include "Sa_BkCpPc_Cfg.h"
#include "GlobalMacro.h"
#include "CalConstants.h"


#define D_VDISCHMAXFACTOR_ULS_F32	1.05f
#define D_VDISCHMINFACTOR_ULS_F32	0.95f
#define D_PWRDISCCONFIGB_CNT_U08    2U    /* Power Disconnect configuration A = 1, B = 2 */

typedef enum {
	BULKCAP_WAITFORSTARTA = 0u,
	BULKCAP_VERIFYDISCOPEN,
	BULKCAP_WAITFORSQRWAVE,
	BULKCAP_PRECHARGE,
	BULKCAP_WAITFORSTARTB,
	BULKCAP_POSTCLOSE,
	BULKCAP_VERIFYCLOSE,
	BULKCAP_RUNTIMEDIAG
} BulkCapPrechargeSequenceType;


#define BKCPPC_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(boolean, SA_BKCPPC_VAR) FirstRunComplete_Cnt_M_lgc;
STATIC VAR(boolean, SA_BKCPPC_VAR) PowerRelayInitFltFailed_Cnt_M_lgc;
STATIC VAR(boolean, SA_BKCPPC_VAR) PwrDiscATestComplete_Cnt_M_lgc;
STATIC VAR(boolean, SA_BKCPPC_VAR) PwrDiscBTestComplete_Cnt_M_lgc;
STATIC VAR(boolean, SA_BKCPPC_VAR) PwrDiscClosed_Cnt_M_lgc;
STATIC VAR(BulkCapPrechargeSequenceType, SA_BKCPPC_VAR) BulkCapPrechargeState_Cnt_M_enum;
STATIC volatile VAR(boolean, SA_BKCPPC_VAR) MotionDetected_Cnt_D_lgc;
#define BKCPPC_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */


#define BKCPPC_START_SEC_VAR_CLEARED_16
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(uint16, SA_BKCPPC_VAR) RunTimeFaultAcc_Cnt_M_u16;
#define BKCPPC_STOP_SEC_VAR_CLEARED_16
#include "MemMap.h" /* PRQA S 5087 */


#define BKCPPC_START_SEC_VAR_CLEARED_32
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(uint32,  SA_BKCPPC_VAR) VerifyDiscOpenDiagTimer_mS_M_u32;
STATIC VAR(uint32,  SA_BKCPPC_VAR) WaitForSqrWaveDiagTimer_mS_M_u32;
STATIC VAR(uint32,  SA_BKCPPC_VAR) PrechargeDiagTimer_mS_M_u32;
STATIC VAR(uint32,  SA_BKCPPC_VAR) PostCloseDiagTimer_mS_M_u32;
STATIC VAR(uint32,  SA_BKCPPC_VAR) VerifyCloseDiagTimer_mS_M_u32;
STATIC VAR(float32, SA_BKCPPC_VAR) VdischMax_Volts_M_f32;
STATIC VAR(float32, SA_BKCPPC_VAR) VdischMin_Volts_M_f32;
STATIC VAR(float32, SA_BKCPPC_VAR) VbattStart_Volts_M_f32;
STATIC VAR(float32, SA_BKCPPC_VAR) VswitchStart_Volts_M_f32;
STATIC volatile VAR(float32, SA_BKCPPC_VAR) DeltaV_Volts_D_f32;
STATIC volatile VAR(float32, SA_BKCPPC_VAR) VswitchCorrected_Volts_D_f32;
#define BKCPPC_STOP_SEC_VAR_CLEARED_32
#include "MemMap.h" /* PRQA S 5087 */


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
 * Float: Real in interval [-FLT_MAX...FLT_MAX] with single precision (standard type)
 * IoHwAb_BoolType: Integer in interval [0...1]
 * UInt16: Integer in interval [0...65535] (standard type)
 * UInt32: Integer in interval [0...4294967295] (standard type)
 * UInt8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
 * NTCNumber: Enumeration of integer in interval [0...511] with enumerators
 *   NTC_Num_FlashWrapperLgcFlt (1U)
 *   NTC_Num_FlashECCCorr (2U)
 *   NTC_Num_FlashECCMemFlt (3U)
 *   NTC_Num_FlashCRCMemFault (4U)
 *   NTC_Num_EEPROMDiag (10U)
 *   NTC_Num_EEPROMDiagMtrStr (11U)
 *   NTC_Num_PriSnsrTrqStorFlt (12U)
 *   NTC_Num_EEPROMDiagPosTrimStr (13U)
 *   NTC_Num_SecSnsrTrqStorFlt (14U)
 *   NTC_Num_EEPROMDiagPolarityStr (15U)
 *   NTC_Num_RAMDiag_GeneralFlt (16U)
 *   NTC_Num_RAMDiag_WrprLgcFlt (17U)
 *   NTC_Num_RAMDiag_ECCCorrIndFlt (18U)
 *   NTC_Num_RAMDiag_ECCMemFlt (19U)
 *   NTC_Num_RAMDiag_CRCMemFlt (20U)
 *   NTC_Num_RAMDiag_VIMRamFlt (23U)
 *   NTC_Num_RAMDiag_NHET1RamFlt (24U)
 *   NTC_Num_RAMDiag_NHET2RamFlt (25U)
 *   NTC_Num_RAMDiag_ADC1RamFlt (26U)
 *   NTC_Num_RAMDiag_DCANRamFault (27U)
 *   NTC_Num_RAMDiag_ADC2RamFlt (28U)
 *   NTC_Num_RAMDiag_HETTU1RamFlt (29U)
 *   NTC_Num_RAMDiag_HETTU2RamFlt (30U)
 *   NTC_Num_CPU_RegVer (32U)
 *   NTC_Num_CPU_CoreInitFlt (33U)
 *   NTC_Num_CPU_CoreRunTimeFlt (34U)
 *   NTC_Num_CPU_ClockMon (35U)
 *   NTC_Num_CPU_eFuseFlt (36U)
 *   NTC_Num_CPU_MPUViolation (37U)
 *   NTC_Num_CPU_FactPrcsErr (40U)
 *   NTC_Num_PropExeDiag_InitDiag (41U)
 *   NTC_Num_PrgFlwDeadlnFlt (42U)
 *   NTC_Num_PropExeDiag_RunTimeDiag (43U)
 *   NTC_Num_PropExeDiag_COPTimeout (44U)
 *   NTC_Num_PropExeDiag_PrefetchAbort (48U)
 *   NTC_Num_PropExeDiag_DataAbort (49U)
 *   NTC_Num_PerDiag_ADC1Flt (50U)
 *   NTC_Num_PerDiag_ADC2Flt (51U)
 *   NTC_Num_PerDiag_ADCCrossChkFlt (52U)
 *   NTC_Num_PerDiag_IllegalAccess (53U)
 *   NTC_Num_PerDiag_DMAFlt (54U)
 *   NTC_Num_PerDiag_CPUWarning (63U)
 *   NTC_Num_TmpMonFunc (64U)
 *   NTC_Num_TmpMonRunTimeFlt (65U)
 *   NTC_Num_PowerRelayInitFlt (66U)
 *   NTC_Num_PrechargeFailure (67U)
 *   NTC_Num_PowerRelayRunFlt (68U)
 *   NTC_Num_Thermistor (69U)
 *   NTC_Num_RefSupplyVltg (70U)
 *   NTC_Num_TrcvrInterfaceFlt (71U)
 *   NTC_Num_CPUSupplyOvervoltage (72U)
 *   NTC_Num_GateDrvFlt (77U)
 *   NTC_Num_OnStateSingleFET (78U)
 *   NTC_Num_OnStateMultiFET (79U)
 *   NTC_Num_PhaseVoltageVerf (80U)
 *   NTC_Num_PhaseDscnt (81U)
 *   NTC_Num_DigPhaseVoltageVerf (82U)
 *   NTC_Num_PhaseDscntFailedDisable (83U)
 *   NTC_Num_CurrentMeas1 (84U)
 *   NTC_Num_CurrentMeas2 (85U)
 *   NTC_Num_CurrentMeasCrossChk (86U)
 *   NTC_Num_PDSupplyOverVoltage (87U)
 *   NTC_Num_ChargePumpUnderVoltage (88U)
 *   NTC_Num_HwTrqSensor (96U)
 *   NTC_Num_AnaVsDigHwTrq (97U)
 *   NTC_Num_TrqSensorRecoveryFlt (98U)
 *   NTC_Num_TrqSensorScaleInvalid (100U)
 *   NTC_Num_T1vsT2 (101U)
 *   NTC_Num_T1OutofRange (102U)
 *   NTC_Num_T2OutofRange (103U)
 *   NTC_Num_DigT1vsT2 (104U)
 *   NTC_Num_DigT1OutofRange (105U)
 *   NTC_Num_DigT2OutofRange (106U)
 *   NTC_Num_RedT1vsT2 (107U)
 *   NTC_Num_HWASensorRel (110U)
 *   NTC_Num_HWASensorAbs (111U)
 *   NTC_Num_PriMSB_SinCosCorr (112U)
 *   NTC_Num_SecMSB_SinCosCorr (113U)
 *   NTC_Num_PriVsSec_SinCosCorr (114U)
 *   NTC_Num_DigMSBFlt (115U)
 *   NTC_Num_MtrVelFlt (116U)
 *   NTC_Num_HWAtoMtrAngleCorr (117U)
 *   NTC_Num_RedPriVsSec_SinCosCorr (118U)
 *   NTC_Num_TurnCntr_PosLoss (128U)
 *   NTC_Num_TurnCntr_MicroProcFlt (129U)
 *   NTC_Num_TurnCntr_SensorPosFlt (130U)
 *   NTC_Num_TurnCntr_SpiComFlt (131U)
 *   NTC_Num_TurnCntr_HighQuiescCur (132U)
 *   NTC_Num_TurnCntr_MainResets (133U)
 *   NTC_Num_TurnCntr_PosLossNotSpdDep (134U)
 *   NTC_Num_KinematicIntDiag (144U)
 *   NTC_Num_HighFriction (145U)
 *   NTC_Num_DutyCycleExceeded (148U)
 *   NTC_Num_AbsTempThermLimit (149U)
 *   NTC_Num_LatchActive (160U)
 *   NTC_Num_OpTrqVsHwTrq (168U)
 *   NTC_Num_CurrentReas (169U)
 *   NTC_Num_OpVoltage (176U)
 *   NTC_Num_ExVoltageLow (177U)
 *   NTC_Num_ReducedAsstLowVoltage (178U)
 *   NTC_Num_ExVoltageHigh (180U)
 *   NTC_Num_OpVoltageOvrMax (181U)
 *   NTC_Num_BattTransOverVolt (182U)
 *   NTC_Num_IgnConfDiag (184U)
 *   NTC_Num_TurnCntr_LowBattery (185U)
 *   NTC_Num_EEPROMCloseFailed (191U)
 *   NTC_Num_SigPath1CrossChk (192U)
 *   NTC_Num_SigPath2CrossChk (193U)
 *   NTC_Num_SigPath3CrossChk (194U)
 *   NTC_Num_SigPath4CrossChk (195U)
 *   NTC_Num_SigPath5CrossChk (196U)
 *   NTC_Num_DampingFWReached (197U)
 *   NTC_Num_AssistFWReached (198U)
 *   NTC_Num_ReturnFWReached (199U)
 *   NTC_Num_DampingFWFltMode (200U)
 *   NTC_Num_AssistFWFltMode (201U)
 *   NTC_Num_VBICFltMode (202U)
 *   NTC_Num_StaMdsSysC (203U)
 *   NTC_NUM_SysFailureForRotVel (204U)
 *   NTC_NUM_SysFailForRedntRotVel (205U)
 *   NTC_Num_SysFailureForTrqSnsr (206U)
 *   NTC_Num_SysFailureForRedTrqSnsr (207U)
 *   NTC_NUM_SysFailureForCtrlVolt (209U)
 *   NTC_Num_GlblSgnlOvrwrtDet (223U)
 *   NTC_Num_VLF_00 (224U)
 *   NTC_Num_VLF_01 (225U)
 *   NTC_Num_VLF_02 (226U)
 *   NTC_Num_VLF_03 (227U)
 *   NTC_Num_VLF_04 (228U)
 *   NTC_Num_VLF_05 (229U)
 *   NTC_Num_VLF_06 (230U)
 *   NTC_Num_VLF_07 (231U)
 *   NTC_Num_VLF_08 (232U)
 *   NTC_Num_VLF_09 (233U)
 *   NTC_Num_VLF_10 (234U)
 *   NTC_Num_VLF_11 (235U)
 *   NTC_Num_VLF_12 (236U)
 *   NTC_Num_VLF_13 (237U)
 *   NTC_Num_VLF_14 (238U)
 *   NTC_Num_VLF_15 (239U)
 *   NTC_Num_VLF_16 (240U)
 *   NTC_Num_VLF_17 (241U)
 *   NTC_Num_VLF_18 (242U)
 *   NTC_Num_VLF_19 (243U)
 *   NTC_Num_VLF_20 (244U)
 *   NTC_Num_VLF_21 (245U)
 *   NTC_Num_VLF_22 (246U)
 *   NTC_Num_VLF_23 (247U)
 *   NTC_Num_VLF_24 (248U)
 *   NTC_Num_VLF_25 (249U)
 *   NTC_Num_VLF_26 (250U)
 *   NTC_Num_VLF_27 (251U)
 *   NTC_Num_VLF_28 (252U)
 *   NTC_Num_VLF_29 (253U)
 *   NTC_Num_VLF_30 (254U)
 *   NTC_Num_VLF_31 (255U)
 *   NTC_Num_BusOffCh1 (256U)
 *   NTC_Num_BusOffCh1NodeMute (257U)
 *   NTC_Num_Node1AAbsent (258U)
 *   NTC_Num_Node1AFaulty (259U)
 *   NTC_Num_Node1BAbsent (260U)
 *   NTC_Num_Node1BFaulty (261U)
 *   NTC_Num_Node1CAbsent (262U)
 *   NTC_Num_Node1CFaulty (263U)
 *   NTC_Num_Node1DAbsent (264U)
 *   NTC_Num_Node1DFaulty (265U)
 *   NTC_Num_Node1EAbsent (266U)
 *   NTC_Num_Node1EFaulty (267U)
 *   NTC_Num_Node1FAbsent (268U)
 *   NTC_Num_Node1FFaulty (269U)
 *   NTC_Num_Node1GAbsent (270U)
 *   NTC_Num_Node1GFaulty (271U)
 *   NTC_Num_BusOffCh2 (272U)
 *   NTC_Num_Node2AAbsent (273U)
 *   NTC_Num_Node2AFaulty (274U)
 *   NTC_Num_Node2BAbsent (275U)
 *   NTC_Num_Node2BFaulty (276U)
 *   NTC_Num_Node2CAbsent (277U)
 *   NTC_Num_Node2CFaulty (278U)
 *   NTC_Num_Node2DAbsent (279U)
 *   NTC_Num_Node2DFaulty (280U)
 *   NTC_Num_Node2EAbsent (281U)
 *   NTC_Num_Node2EFaulty (282U)
 *   NTC_Num_Node2FAbsent (283U)
 *   NTC_Num_Node2FFaulty (284U)
 *   NTC_Num_Node2GAbsent (285U)
 *   NTC_Num_Node2GFaulty (286U)
 *   NTC_Num_InvalidMsg_M (288U)
 *   NTC_Num_MissingMsg_M (289U)
 *   NTC_Num_CRCFltMsg_M (290U)
 *   NTC_Num_PgrsCntFltMsg_M (291U)
 *   NTC_Num_DataRngFltMsg_M (292U)
 *   NTC_Num_DataRateFltMsg_M (293U)
 *   NTC_Num_DataOtherFltMsg_M (294U)
 *   NTC_Num_DataOther2FltMsg_M (295U)
 *   NTC_Num_InvalidMsg_N (296U)
 *   NTC_Num_MissingMsg_N (297U)
 *   NTC_Num_CRCFltMsg_N (298U)
 *   NTC_Num_PgrsCntFltMsg_N (299U)
 *   NTC_Num_DataRngFltMsg_N (300U)
 *   NTC_Num_DataRateFltMsg_N (301U)
 *   NTC_Num_DataOtherFltMsg_N (302U)
 *   NTC_Num_DataOtherFlt2Msg_N (303U)
 *   NTC_Num_InvalidMsg_O (304U)
 *   NTC_Num_MissingMsg_O (305U)
 *   NTC_Num_CRCFltMsg_O (306U)
 *   NTC_Num_PgrsCntFltMsg_O (307U)
 *   NTC_Num_DataRngFltMsg_O (308U)
 *   NTC_Num_DataRateFltMsg_O (309U)
 *   NTC_Num_DataOtherFltMsg_O (310U)
 *   NTC_Num_InvalidMsg_P (312U)
 *   NTC_Num_MissingMsg_P (313U)
 *   NTC_Num_CRCFltMsg_P (314U)
 *   NTC_Num_PgrsCntFltMsg_P (315U)
 *   NTC_Num_DataRngFltMsg_P (316U)
 *   NTC_Num_DataRateFltMsg_P (317U)
 *   NTC_Num_DataOtherFltMsg_P (318U)
 *   NTC_Num_InvalidMsg_Q (320U)
 *   NTC_Num_MissingMsg_Q (321U)
 *   NTC_Num_CRCFltMsg_Q (322U)
 *   NTC_Num_PgrsCntFltMsg_Q (323U)
 *   NTC_Num_DataRngFltMsg_Q (324U)
 *   NTC_Num_DataRateFltMsg_Q (325U)
 *   NTC_Num_DataOtherFltMsg_Q (326U)
 *   NTC_Num_InvalidMsg_R (328U)
 *   NTC_Num_MissingMsg_R (329U)
 *   NTC_Num_CRCFltMsg_R (330U)
 *   NTC_Num_PgrsCntFltMsg_R (331U)
 *   NTC_Num_DataRngFltMsg_R (332U)
 *   NTC_Num_DataRateFltMsg_R (333U)
 *   NTC_Num_DataOtherFltMsg_R (334U)
 *   NTC_Num_DataOtherFlt2Msg_R (335U)
 *   NTC_Num_InvalidMsg_S (336U)
 *   NTC_Num_MissingMsg_S (337U)
 *   NTC_Num_CRCFltMsg_S (338U)
 *   NTC_Num_PgrsCntFltMsg_S (339U)
 *   NTC_Num_DataRngFltMsg_S (340U)
 *   NTC_Num_DataRateFltMsg_S (341U)
 *   NTC_Num_DataOtherFltMsg_S (342U)
 *   NTC_Num_InvalidMsg_T (344U)
 *   NTC_Num_MissingMsg_T (345U)
 *   NTC_Num_CRCFltMsg_T (346U)
 *   NTC_Num_PgrsCntFltMsg_T (347U)
 *   NTC_Num_DataRngFltMsg_T (348U)
 *   NTC_Num_DataRateFltMsg_T (349U)
 *   NTC_Num_DataOtherFltMsg_T (350U)
 *   NTC_Num_InvalidMsg_U (352U)
 *   NTC_Num_MissingMsg_U (353U)
 *   NTC_Num_CRCFltMsg_U (354U)
 *   NTC_Num_PgrsCntFltMsg_U (355U)
 *   NTC_Num_DataRngFltMsg_U (356U)
 *   NTC_Num_DataRateFltMsg_U (357U)
 *   NTC_Num_DataOtherFltMsg_U (358U)
 *   NTC_Num_InvalidMsg_V (360U)
 *   NTC_Num_MissingMsg_V (361U)
 *   NTC_Num_CRCFltMsg_V (362U)
 *   NTC_Num_PgrsCntFltMsg_V (363U)
 *   NTC_Num_DataRngFltMsg_V (364U)
 *   NTC_Num_DataRateFltMsg_V (365U)
 *   NTC_Num_DataOtherFltMsg_V (366U)
 *   NTC_Num_InvalidMsg_W (368U)
 *   NTC_Num_MissingMsg_W (369U)
 *   NTC_Num_CRCFltMsg_W (370U)
 *   NTC_Num_PgrsCntFltMsg_W (371U)
 *   NTC_Num_DataRngFltMsg_W (372U)
 *   NTC_Num_DataRateFltMsg_W (373U)
 *   NTC_Num_DataOtherFltMsg_W (374U)
 *   NTC_Num_InvalidMsg_X (376U)
 *   NTC_Num_MissingMsg_X (377U)
 *   NTC_Num_CRCFltMsg_X (378U)
 *   NTC_Num_PgrsCntFltMsg_X (379U)
 *   NTC_Num_DataRngFltMsg_X (380U)
 *   NTC_Num_DataRateFltMsg_X (381U)
 *   NTC_Num_DataOtherFltMsg_X (382U)
 *   NTC_Num_InvalidMsg_Y (384U)
 *   NTC_Num_MissingMsg_Y (385U)
 *   NTC_Num_CRCFltMsg_Y (386U)
 *   NTC_Num_PgrsCntFltMsg_Y (387U)
 *   NTC_Num_DataRngFltMsg_Y (388U)
 *   NTC_Num_DataRateFltMsg_Y (389U)
 *   NTC_Num_DataOtherFltMsg_Y (390U)
 *   NTC_Num_InvalidMsg_Z (392U)
 *   NTC_Num_MissingMsg_Z (393U)
 *   NTC_Num_CRCFltMsg_Z (394U)
 *   NTC_Num_PgrsCntFltMsg_Z (395U)
 *   NTC_Num_DataRngFltMsg_Z (396U)
 *   NTC_Num_DataRateFltMsg_Z (397U)
 *   NTC_Num_DataOtherFltMsg_Z (398U)
 *   NTC_Num_DSTXORActive (399U)
 *   NTC_Num_InvalidMsg_AA (400U)
 *   NTC_Num_MissingMsg_AA (401U)
 *   NTC_Num_CRCFltMsg_AA (402U)
 *   NTC_Num_PgrsCntFltMsg_AA (403U)
 *   NTC_Num_DataRngFltMsg_AA (404U)
 *   NTC_Num_DataRateFltMsg_AA (405U)
 *   NTC_Num_DataOtherFltMsg_AA (406U)
 *   NTC_Num_InvalidMsg_AB (408U)
 *   NTC_Num_MissingMsg_AB (409U)
 *   NTC_Num_CRCFltMsg_AB (410U)
 *   NTC_Num_PgrsCntFltMsg_AB (411U)
 *   NTC_Num_DataRngFltMsg_AB (412U)
 *   NTC_Num_DataRateFltMsg_AB (413U)
 *   NTC_Num_DataOtherFltMsg_AB (414U)
 *   NTC_Num_InvalidMsg_AC (416U)
 *   NTC_Num_MissingMsg_AC (417U)
 *   NTC_Num_CRCFltMsg_AC (418U)
 *   NTC_Num_PgrsCntFltMsg_AC (419U)
 *   NTC_Num_DataRngFltMsg_AC (420U)
 *   NTC_Num_DataRateFltMsg_AC (421U)
 *   NTC_Num_DataOtherFltMsg_AC (422U)
 *   NTC_Num_InvalidMsg_AD (424U)
 *   NTC_Num_MissingMsg_AD (425U)
 *   NTC_Num_CRCFltMsg_AD (426U)
 *   NTC_Num_PgrsCntFltMsg_AD (427U)
 *   NTC_Num_DataRngFltMsg_AD (428U)
 *   NTC_Num_DataRateFltMsg_AD (429U)
 *   NTC_Num_DataOtherFltMsg_AD (430U)
 *   NTC_Num_InvalidMsg_AE (432U)
 *   NTC_Num_MissingMsg_AE (433U)
 *   NTC_Num_CRCFltMsg_AE (434U)
 *   NTC_Num_PgrsCntFltMsg_AE (435U)
 *   NTC_Num_DataRngFltMsg_AE (436U)
 *   NTC_Num_DataRateFltMsg_AE (437U)
 *   NTC_Num_DataOtherFltMsg_AE (438U)
 *   NTC_Num_InvalidMsg_AF (440U)
 *   NTC_Num_MissingMsg_AF (441U)
 *   NTC_Num_CRCFltMsg_AF (442U)
 *   NTC_Num_PgrsCntFltMsg_AF (443U)
 *   NTC_Num_DataRngFltMsg_AF (444U)
 *   NTC_Num_DataRateFltMsg_AF (445U)
 *   NTC_Num_DataOtherFltMsg_AF (446U)
 *   NTC_Num_InvalidMsg_AG (448U)
 *   NTC_Num_MissingMsg_AG (449U)
 *   NTC_Num_CRCFltMsg_AG (450U)
 *   NTC_Num_PgrsCntFltMsg_AG (451U)
 *   NTC_Num_DataRngFltMsg_AG (452U)
 *   NTC_Num_DataRateFltMsg_AG (453U)
 *   NTC_Num_DataOtherFltMsg_AG (454U)
 *   NTC_Num_InvalidMsg_AH (456U)
 *   NTC_Num_MissingMsg_AH (457U)
 *   NTC_Num_CRCFltMsg_AH (458U)
 *   NTC_Num_PgrsCntFltMsg_AH (459U)
 *   NTC_Num_DataRngFltMsg_AH (460U)
 *   NTC_Num_DataRateFltMsg_AH (461U)
 *   NTC_Num_DataOtherFltMsg_AH (462U)
 *   NTC_Num_FlexrayCommunicationError (465U)
 *   NTC_Num_InvalidMsg_AI (466U)
 *   NTC_Num_MissingMsg_AI (467U)
 *   NTC_Num_SysConsistencyVerf (496U)
 *   NTC_Num_ConfigMisMatch (497U)
 *   NTC_Num_CalNotPrgmd (498U)
 *   NTC_Num_EOLVehTunNtPerf (501U)
 *   NTC_Num_MtrSensorNotTrimmed (502U)
 *   NTC_Num_HWASensorNotTrimmed (504U)
 *   NTC_Num_HWASensorTrimNoAttempt (505U)
 *   NTC_Num_TrqSensorScaleNotSet (506U)
 *   NTC_Num_TrqSensorNotTrimmed (507U)
 *   NTC_Num_DigTrqSensorScaleNotSet (509U)
 *   NTC_Num_DigTrqSensorNotTrimmed (510U)
 * NxtrDiagMgrStatus: Enumeration of integer in interval [0...255] with enumerators
 *   NTC_STATUS_PASSED (0U)
 *   NTC_STATUS_FAILED (1U)
 *   NTC_STATUS_PREPASSED (2U)
 *   NTC_STATUS_PREFAILED (3U)
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
 * Float: D_ZERO_ULS_F32 = 0.0F
 * UInt16: D_ZERO_CNT_U16 = 0U
 *
 *********************************************************************************************************************/


#define RTE_START_SEC_SA_BKCPPC_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BkCpPc_Per1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 2ms
 *     and not in Mode(s) <OFF, DISABLE>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Implicit S/R API:
 *   -----------------
 *   Float Rte_IRead_BkCpPc_Per1_BattSwitched_Volt_f32(void)
 *   Float Rte_IRead_BkCpPc_Per1_Batt_Volt_f32(void)
 *   Float Rte_IRead_BkCpPc_Per1_MotorVelocityMRFUnfiltered_MtrRadpS_f32(void)
 *   Float Rte_IRead_BkCpPc_Per1_OVERRIDESIGDIAGADC_Volt_f32(void)
 *   Float Rte_IRead_BkCpPc_Per1_PMOSDIAGADC_Volt_f32(void)
 *   Boolean Rte_IRead_BkCpPc_Per1_PwrDiscATestStart_Cnt_lgc(void)
 *   Boolean Rte_IRead_BkCpPc_Per1_PwrDiscBTestStart_Cnt_lgc(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_BkCpPc_Per1_PwrDiscATestComplete_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_BkCpPc_Per1_PwrDiscATestComplete_Cnt_lgc(void)
 *   void Rte_IWrite_BkCpPc_Per1_PwrDiscBTestComplete_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_BkCpPc_Per1_PwrDiscBTestComplete_Cnt_lgc(void)
 *   void Rte_IWrite_BkCpPc_Per1_PwrDiscClosed_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_BkCpPc_Per1_PwrDiscClosed_Cnt_lgc(void)
 *
 * Mode Interfaces:
 * ================
 *   Rte_ModeType_StaMd_Mode Rte_Mode_SystemState_Mode(void)
 *   Modes of Rte_ModeType_StaMd_Mode:
 *   - RTE_MODE_StaMd_Mode_DISABLE
 *   - RTE_MODE_StaMd_Mode_OFF
 *   - RTE_MODE_StaMd_Mode_OPERATE
 *   - RTE_MODE_StaMd_Mode_WARMINIT
 *   - RTE_TRANSITION_StaMd_Mode
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *   Std_ReturnType Rte_Call_PhyCapDischarge_OP_SET(IoHwAb_BoolType signal)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DigitalOut_E_NOT_OK
 *   Std_ReturnType Rte_Call_PhyCapPrecharge_OP_SET(IoHwAb_BoolType signal)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DigitalOut_E_NOT_OK
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

FUNC(void, RTE_SA_BKCPPC_APPL_CODE) BkCpPc_Per1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: BkCpPc_Per1
 *********************************************************************************************************************/
	
	
	VAR(float32, AUTOMATIC) MotorVelocityMRFUnfiltered_MtrRadpS_T_f32;
	VAR(float32, AUTOMATIC) OVERRIDESIGDIAGADC_Volt_T_f32;
	VAR(float32, AUTOMATIC) PMOSDIAGADC_Volt_T_f32;
	VAR(boolean, AUTOMATIC) PwrDiscATestStart_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) PwrDiscBTestStart_Cnt_T_lgc;
	VAR(float32, AUTOMATIC) Vbatt_Volts_T_f32;
	VAR(float32, AUTOMATIC) Vswitch_Volts_T_f32;
	
	VAR(boolean, AUTOMATIC) MotionDetected_Cnt_T_lgc;
	
	VAR(float32, AUTOMATIC) DeltaV_Volts_T_f32;
	
	VAR(uint16,  AUTOMATIC) ElapsedTime_mS_T_u16;
	
	VAR(float32, AUTOMATIC) VswitchCorrected_Volts_T_f32;
	VAR(float32, AUTOMATIC) AbsDeltaVswitch_Volts_T_f32;
	VAR(float32, AUTOMATIC) ChargeMinDelta_Volts_T_f32;
	
	
	/* Configurable Start of Runnable Checkpoint */
	Rte_Call_BkCpPc_Per1_CP0_CheckpointReached();
	
	
	MotorVelocityMRFUnfiltered_MtrRadpS_T_f32 = Rte_IRead_BkCpPc_Per1_MotorVelocityMRFUnfiltered_MtrRadpS_f32();
	OVERRIDESIGDIAGADC_Volt_T_f32 = Rte_IRead_BkCpPc_Per1_OVERRIDESIGDIAGADC_Volt_f32();
	PMOSDIAGADC_Volt_T_f32 = Rte_IRead_BkCpPc_Per1_PMOSDIAGADC_Volt_f32();
	PwrDiscATestStart_Cnt_T_lgc = Rte_IRead_BkCpPc_Per1_PwrDiscATestStart_Cnt_lgc();
	PwrDiscBTestStart_Cnt_T_lgc = Rte_IRead_BkCpPc_Per1_PwrDiscBTestStart_Cnt_lgc();
	Vbatt_Volts_T_f32 = Rte_IRead_BkCpPc_Per1_Batt_Volt_f32();
	Vswitch_Volts_T_f32 = Rte_IRead_BkCpPc_Per1_BattSwitched_Volt_f32();
	
	
	/*** Motor Motion Check ***/
	if (D_PWRDISCCONFIGURATION_CNT_U08 == D_PWRDISCCONFIGB_CNT_U08)
	{
		if( Abs_f32_m(MotorVelocityMRFUnfiltered_MtrRadpS_T_f32) > k_MtrMotionThresh_MtrRadpS_f32 )
		{
			MotionDetected_Cnt_T_lgc = TRUE;
		}
		else
		{
			MotionDetected_Cnt_T_lgc = FALSE;
		}
	}
	else
	{   /* Default to PWRDISCCONFIGA */
		MotionDetected_Cnt_T_lgc = FALSE;
	}
	
	MotionDetected_Cnt_D_lgc = MotionDetected_Cnt_T_lgc;
	
	
	
	/*** Calculate Delta Voltage ***/
	
	DeltaV_Volts_T_f32 = Min_m(k_MaxSwitchedVolt_Volts_f32, Vbatt_Volts_T_f32) - Vswitch_Volts_T_f32;
	
	DeltaV_Volts_D_f32 = DeltaV_Volts_T_f32;
	
	
	
	/*** State Determination and Power Disconnect Sequence A Control ***/
	
	switch( BulkCapPrechargeState_Cnt_M_enum )
	{
		case BULKCAP_WAITFORSTARTA:
			if( PwrDiscATestStart_Cnt_T_lgc == TRUE )
			{
				PowerRelayInitFltFailed_Cnt_M_lgc = FALSE;
				if( FirstRunComplete_Cnt_M_lgc == FALSE )
				{
					BulkCapPrechargeState_Cnt_M_enum = BULKCAP_VERIFYDISCOPEN;
					(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&VerifyDiscOpenDiagTimer_mS_M_u32);
					FirstRunComplete_Cnt_M_lgc = TRUE;

					if (D_PWRDISCCONFIGURATION_CNT_U08 == D_PWRDISCCONFIGB_CNT_U08)
					{
						(void)Rte_Call_PhyCapPrecharge_OP_SET(STD_LOW);
						(void)Rte_Call_PhyCapDischarge_OP_SET(STD_HIGH);
					}
				}
				else
				{
					BulkCapPrechargeState_Cnt_M_enum = BULKCAP_WAITFORSQRWAVE;
					(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&WaitForSqrWaveDiagTimer_mS_M_u32);

					if (D_PWRDISCCONFIGURATION_CNT_U08 == D_PWRDISCCONFIGB_CNT_U08)
					{
						(void)Rte_Call_PhyCapPrecharge_OP_SET(STD_LOW);
						(void)Rte_Call_PhyCapDischarge_OP_SET(STD_LOW);
					}
				}
			}
			break;
		
		case BULKCAP_VERIFYDISCOPEN:
			if (D_PWRDISCCONFIGURATION_CNT_U08 == D_PWRDISCCONFIGB_CNT_U08)
			{
				if( (DeltaV_Volts_T_f32 >= k_PwrDiscOpenThresh_Volts_f32) &&
					(PMOSDIAGADC_Volt_T_f32 <= k_PMOSDIAGOpenThresh_Volts_f32) &&
					(OVERRIDESIGDIAGADC_Volt_T_f32 <= k_OVERRIDESIGDIAGOpenThresh_Volts_f32) )
				{
					BulkCapPrechargeState_Cnt_M_enum = BULKCAP_WAITFORSQRWAVE;
					(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&WaitForSqrWaveDiagTimer_mS_M_u32);
					(void)Rte_Call_PhyCapPrecharge_OP_SET(STD_LOW);
					(void)Rte_Call_PhyCapDischarge_OP_SET(STD_LOW);
				}
				else if( MotionDetected_Cnt_T_lgc == TRUE )
				{
					(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&VerifyDiscOpenDiagTimer_mS_M_u32);
				}
				else
				{
					(void)Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(VerifyDiscOpenDiagTimer_mS_M_u32, &ElapsedTime_mS_T_u16);
					if( ElapsedTime_mS_T_u16 > k_VerifyPwrDiscOpenThresh_mS_u16 )
					{
						if( DeltaV_Volts_T_f32 < k_PwrDiscOpenThresh_Volts_f32 )
						{
							(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_PowerRelayInitFlt, 0x01u, NTC_STATUS_FAILED);
							PowerRelayInitFltFailed_Cnt_M_lgc = TRUE;
						}
						else if( PMOSDIAGADC_Volt_T_f32 > k_PMOSDIAGOpenThresh_Volts_f32 )
						{
							(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_PowerRelayInitFlt, 0x04u, NTC_STATUS_FAILED);
							PowerRelayInitFltFailed_Cnt_M_lgc = TRUE;
						}
						else if( OVERRIDESIGDIAGADC_Volt_T_f32 > k_OVERRIDESIGDIAGOpenThresh_Volts_f32 )
						{
							(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_PowerRelayInitFlt, 0x08u, NTC_STATUS_FAILED);
							PowerRelayInitFltFailed_Cnt_M_lgc = TRUE;
						}
						else
						{
							/* do nothing */
						}
					}
				}
			}
			else
			{ /* Default to PWRDISCCONFIGA */
				if(DeltaV_Volts_T_f32 >= k_PwrDiscOpenThresh_Volts_f32)
				{
					BulkCapPrechargeState_Cnt_M_enum = BULKCAP_WAITFORSQRWAVE;
				}
				else
				{
					(void)Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(VerifyDiscOpenDiagTimer_mS_M_u32, &ElapsedTime_mS_T_u16);
					if( ElapsedTime_mS_T_u16 > k_VerifyPwrDiscOpenThresh_mS_u16 )
					{
						(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_PowerRelayInitFlt, 0x01u, NTC_STATUS_FAILED);
						PowerRelayInitFltFailed_Cnt_M_lgc = TRUE;
					}
				}
			}
			break;
		
		case BULKCAP_WAITFORSQRWAVE:
			if (D_PWRDISCCONFIGURATION_CNT_U08 == D_PWRDISCCONFIGB_CNT_U08)
			{
				(void)Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(WaitForSqrWaveDiagTimer_mS_M_u32, &ElapsedTime_mS_T_u16);
				if( ElapsedTime_mS_T_u16 >= k_WaitForSqrWaveThresh_mS_u16 )
				{
					BulkCapPrechargeState_Cnt_M_enum = BULKCAP_PRECHARGE;
					(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&PrechargeDiagTimer_mS_M_u32);
					(void)Rte_Call_PhyCapPrecharge_OP_SET(STD_HIGH);
					(void)Rte_Call_PhyCapDischarge_OP_SET(STD_LOW);
				}
			}
			else
			{ /* Default to PWRDISCCONFIGA */
				BulkCapPrechargeState_Cnt_M_enum = BULKCAP_PRECHARGE;
			}
			break;
		
		case BULKCAP_PRECHARGE:
			if (D_PWRDISCCONFIGURATION_CNT_U08 == D_PWRDISCCONFIGB_CNT_U08)
			{
				if( (DeltaV_Volts_T_f32 <= k_PwrDiscCloseThresh_Volts_f32) &&
					(PMOSDIAGADC_Volt_T_f32 <= k_PMOSDIAGOpenThresh_Volts_f32) &&
					(OVERRIDESIGDIAGADC_Volt_T_f32 <= k_OVERRIDESIGDIAGOpenThresh_Volts_f32) &&
					(Vbatt_Volts_T_f32 < k_MaxSwitchedVolt_Volts_f32) )
				{
					BulkCapPrechargeState_Cnt_M_enum = BULKCAP_WAITFORSTARTB;
					PwrDiscATestComplete_Cnt_M_lgc = TRUE;
					(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_PrechargeFailure, 0u, NTC_STATUS_PASSED);
				}
				else
				{
					(void)Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(PrechargeDiagTimer_mS_M_u32, &ElapsedTime_mS_T_u16);
					if( ElapsedTime_mS_T_u16 > k_PrechargeThresh_mS_u16 )
					{
						if( DeltaV_Volts_T_f32 > k_PwrDiscCloseThresh_Volts_f32 )
						{
							(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_PrechargeFailure, 0x01u, NTC_STATUS_FAILED);
						}
						else if( PMOSDIAGADC_Volt_T_f32 > k_PMOSDIAGOpenThresh_Volts_f32 )
						{
							(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_PrechargeFailure, 0x04u, NTC_STATUS_FAILED);
						}
						else if( OVERRIDESIGDIAGADC_Volt_T_f32 > k_OVERRIDESIGDIAGOpenThresh_Volts_f32 )
						{
							(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_PrechargeFailure, 0x08u, NTC_STATUS_FAILED);
						}
						else if( Vbatt_Volts_T_f32 >= k_MaxSwitchedVolt_Volts_f32 )
						{
							(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_PrechargeFailure, 0x10u, NTC_STATUS_FAILED);
						}
						else
						{
							/* do nothing */
						}
					}
				}
			}
			else
			{ /* Default to PWRDISCCONFIGA */
				BulkCapPrechargeState_Cnt_M_enum = BULKCAP_WAITFORSTARTB;
				PwrDiscATestComplete_Cnt_M_lgc = TRUE;
			}
			break;
		
		case BULKCAP_WAITFORSTARTB:
			if( PwrDiscBTestStart_Cnt_T_lgc == TRUE )
			{
				BulkCapPrechargeState_Cnt_M_enum = BULKCAP_POSTCLOSE;
				(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&PostCloseDiagTimer_mS_M_u32);
			}
			break;
		
		case BULKCAP_POSTCLOSE:
			if (D_PWRDISCCONFIGURATION_CNT_U08 == D_PWRDISCCONFIGB_CNT_U08)
			{
				if( Abs_f32_m(Vbatt_Volts_T_f32 - PMOSDIAGADC_Volt_T_f32) < k_PMOSVError_Volts_f32 )
				{
					BulkCapPrechargeState_Cnt_M_enum = BULKCAP_VERIFYCLOSE;
					(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&VerifyCloseDiagTimer_mS_M_u32);
					VdischMax_Volts_M_f32 = Vswitch_Volts_T_f32 * D_VDISCHMAXFACTOR_ULS_F32;
					VdischMin_Volts_M_f32 = Vswitch_Volts_T_f32 * D_VDISCHMINFACTOR_ULS_F32;
					VbattStart_Volts_M_f32 = Vbatt_Volts_T_f32;
					VswitchStart_Volts_M_f32 = Vswitch_Volts_T_f32;
					(void)Rte_Call_PhyCapPrecharge_OP_SET(STD_LOW);
					(void)Rte_Call_PhyCapDischarge_OP_SET(STD_HIGH);
				}
				else
				{
					(void)Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(PostCloseDiagTimer_mS_M_u32, &ElapsedTime_mS_T_u16);
					if( ElapsedTime_mS_T_u16 > k_PMOSTError_mS_u16 )
					{
						(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_PowerRelayInitFlt, 0x10u, NTC_STATUS_FAILED);
						PowerRelayInitFltFailed_Cnt_M_lgc = TRUE;
					}
				}
			}
			else
			{ /* Default to PWRDISCCONFIGA */
				BulkCapPrechargeState_Cnt_M_enum = BULKCAP_VERIFYCLOSE;
			}
			break;
		
		case BULKCAP_VERIFYCLOSE:
			if (D_PWRDISCCONFIGURATION_CNT_U08 == D_PWRDISCCONFIGB_CNT_U08)
			{
				VdischMax_Volts_M_f32 *= k_MaxDischEst_Uls_f32;
				VdischMin_Volts_M_f32 *= k_MinDischEst_Uls_f32;
				VswitchCorrected_Volts_T_f32 = (Vswitch_Volts_T_f32 * VbattStart_Volts_M_f32) / Vbatt_Volts_T_f32;
				VswitchCorrected_Volts_D_f32 = VswitchCorrected_Volts_T_f32;
				AbsDeltaVswitch_Volts_T_f32 = Abs_f32_m(VswitchStart_Volts_M_f32 - VswitchCorrected_Volts_T_f32);

				if( ( (Vswitch_Volts_T_f32 > VdischMax_Volts_M_f32) ||
					  (Vswitch_Volts_T_f32 < VdischMin_Volts_M_f32) ) &&
					(AbsDeltaVswitch_Volts_T_f32 <= k_VswitchDeltaThresh_Volts_f32) )
				{
					BulkCapPrechargeState_Cnt_M_enum = BULKCAP_RUNTIMEDIAG;
					PwrDiscBTestComplete_Cnt_M_lgc = TRUE;
					PwrDiscClosed_Cnt_M_lgc = TRUE;
					if( PowerRelayInitFltFailed_Cnt_M_lgc == FALSE )
					{
						(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_PowerRelayInitFlt, 0u, NTC_STATUS_PASSED);
					}
					(void)Rte_Call_PhyCapPrecharge_OP_SET(STD_LOW);
					(void)Rte_Call_PhyCapDischarge_OP_SET(STD_LOW);
				}
				else
				{
					(void)Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(VerifyCloseDiagTimer_mS_M_u32, &ElapsedTime_mS_T_u16);
					if( (AbsDeltaVswitch_Volts_T_f32 > k_VswitchDeltaThresh_Volts_f32) ||
						(ElapsedTime_mS_T_u16 >= k_VerifyPwrDiscCloseThresh_mS_u16) )
					{
						(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_PowerRelayInitFlt, 0x02u, NTC_STATUS_FAILED);
						PowerRelayInitFltFailed_Cnt_M_lgc = TRUE;
					}
				}
			}
			else
			{ /* Default to PWRDISCCONFIGA */
				BulkCapPrechargeState_Cnt_M_enum = BULKCAP_RUNTIMEDIAG;
				PwrDiscBTestComplete_Cnt_M_lgc = TRUE;
				PwrDiscClosed_Cnt_M_lgc = TRUE;

				if( PowerRelayInitFltFailed_Cnt_M_lgc == FALSE )
				{
					(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_PowerRelayInitFlt, 0u, NTC_STATUS_PASSED);
				}
			}
			break;
		
		case BULKCAP_RUNTIMEDIAG:
			if (D_PWRDISCCONFIGURATION_CNT_U08 == D_PWRDISCCONFIGB_CNT_U08)
			{
				if (Vbatt_Volts_T_f32 < k_VbattSwitchThreshNonExt_Volt_f32)
				{
					ChargeMinDelta_Volts_T_f32 = k_ChargeMinDeltaNonOp_Volt_f32;
				}
				else if (Vbatt_Volts_T_f32 <  k_VbattSwitchThreshExNorm_Volt_f32 )
				{
					ChargeMinDelta_Volts_T_f32 = k_ChargeMinDeltaExtOp_Volt_f32 ;
				}
				else
				{
					ChargeMinDelta_Volts_T_f32 = k_ChargeMinDeltaNormlOp_Volt_f32 ;
				}
				if( (OVERRIDESIGDIAGADC_Volt_T_f32 - Vbatt_Volts_T_f32) <= ChargeMinDelta_Volts_T_f32 )
				{
					RunTimeFaultAcc_Cnt_M_u16 = DiagPStep_m(RunTimeFaultAcc_Cnt_M_u16, k_ChargePumpDiag_Cnt_str);
					if( DiagFailed_m(RunTimeFaultAcc_Cnt_M_u16, k_ChargePumpDiag_Cnt_str) == TRUE )
					{
						(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_PowerRelayRunFlt, 0x01u, NTC_STATUS_FAILED);
					}
				}
				else
				{
					RunTimeFaultAcc_Cnt_M_u16 = DiagNStep_m(RunTimeFaultAcc_Cnt_M_u16, k_ChargePumpDiag_Cnt_str);
					if( RunTimeFaultAcc_Cnt_M_u16 == D_ZERO_CNT_U16 )
					{
						(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_PowerRelayRunFlt, 0u, NTC_STATUS_PASSED);
					}
				}
			}
			break;
		
		default:
			break;
	}
	
	
	
	Rte_IWrite_BkCpPc_Per1_PwrDiscATestComplete_Cnt_lgc(PwrDiscATestComplete_Cnt_M_lgc);
	Rte_IWrite_BkCpPc_Per1_PwrDiscBTestComplete_Cnt_lgc(PwrDiscBTestComplete_Cnt_M_lgc);
	Rte_IWrite_BkCpPc_Per1_PwrDiscClosed_Cnt_lgc(PwrDiscClosed_Cnt_M_lgc);
	
	
	/* Configurable Start of Runnable Checkpoint */
	Rte_Call_BkCpPc_Per1_CP1_CheckpointReached();
	
	
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BkCpPc_Trns1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on entering of Mode <DISABLE> of ModeDeclarationGroupPrototype <Mode> of PortPrototype <SystemState>
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_BkCpPc_Trns1_PwrDiscATestComplete_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_BkCpPc_Trns1_PwrDiscATestComplete_Cnt_lgc(void)
 *   void Rte_IWrite_BkCpPc_Trns1_PwrDiscBTestComplete_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_BkCpPc_Trns1_PwrDiscBTestComplete_Cnt_lgc(void)
 *
 * Mode Interfaces:
 * ================
 *   Rte_ModeType_StaMd_Mode Rte_Mode_SystemState_Mode(void)
 *   Modes of Rte_ModeType_StaMd_Mode:
 *   - RTE_MODE_StaMd_Mode_DISABLE
 *   - RTE_MODE_StaMd_Mode_OFF
 *   - RTE_MODE_StaMd_Mode_OPERATE
 *   - RTE_MODE_StaMd_Mode_WARMINIT
 *   - RTE_TRANSITION_StaMd_Mode
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_PhyCapDischarge_OP_SET(IoHwAb_BoolType signal)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DigitalOut_E_NOT_OK
 *   Std_ReturnType Rte_Call_PhyCapPrecharge_OP_SET(IoHwAb_BoolType signal)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DigitalOut_E_NOT_OK
 *
 *********************************************************************************************************************/

FUNC(void, RTE_SA_BKCPPC_APPL_CODE) BkCpPc_Trns1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: BkCpPc_Trns1
 *********************************************************************************************************************/
	
	if (D_PWRDISCCONFIGURATION_CNT_U08 == D_PWRDISCCONFIGB_CNT_U08)
	{
		(void)Rte_Call_PhyCapPrecharge_OP_SET(STD_LOW);
		(void)Rte_Call_PhyCapDischarge_OP_SET(STD_LOW);
	}
	
	PwrDiscATestComplete_Cnt_M_lgc = FALSE;
	Rte_IWrite_BkCpPc_Trns1_PwrDiscATestComplete_Cnt_lgc(FALSE);
	PwrDiscBTestComplete_Cnt_M_lgc = FALSE;
	Rte_IWrite_BkCpPc_Trns1_PwrDiscBTestComplete_Cnt_lgc(FALSE);
	
	
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BkCpPc_Trns2
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on entering of Mode <WARMINIT> of ModeDeclarationGroupPrototype <Mode> of PortPrototype <SystemState>
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_BkCpPc_Trns2_PwrDiscATestComplete_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_BkCpPc_Trns2_PwrDiscATestComplete_Cnt_lgc(void)
 *   void Rte_IWrite_BkCpPc_Trns2_PwrDiscBTestComplete_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_BkCpPc_Trns2_PwrDiscBTestComplete_Cnt_lgc(void)
 *   void Rte_IWrite_BkCpPc_Trns2_PwrDiscClosed_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_BkCpPc_Trns2_PwrDiscClosed_Cnt_lgc(void)
 *
 * Mode Interfaces:
 * ================
 *   Rte_ModeType_StaMd_Mode Rte_Mode_SystemState_Mode(void)
 *   Modes of Rte_ModeType_StaMd_Mode:
 *   - RTE_MODE_StaMd_Mode_DISABLE
 *   - RTE_MODE_StaMd_Mode_OFF
 *   - RTE_MODE_StaMd_Mode_OPERATE
 *   - RTE_MODE_StaMd_Mode_WARMINIT
 *   - RTE_TRANSITION_StaMd_Mode
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *   Std_ReturnType Rte_Call_PhyCapDischarge_OP_SET(IoHwAb_BoolType signal)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DigitalOut_E_NOT_OK
 *   Std_ReturnType Rte_Call_PhyCapPrecharge_OP_SET(IoHwAb_BoolType signal)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DigitalOut_E_NOT_OK
 *
 *********************************************************************************************************************/

FUNC(void, RTE_SA_BKCPPC_APPL_CODE) BkCpPc_Trns2(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: BkCpPc_Trns2
 *********************************************************************************************************************/
	
	if (D_PWRDISCCONFIGURATION_CNT_U08 == D_PWRDISCCONFIGB_CNT_U08)
	{
		(void)Rte_Call_PhyCapDischarge_OP_SET(STD_LOW);
		(void)Rte_Call_PhyCapPrecharge_OP_SET(STD_LOW);
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_PowerRelayRunFlt, 0u, NTC_STATUS_PASSED);
	}
	
	PwrDiscATestComplete_Cnt_M_lgc = FALSE;
	Rte_IWrite_BkCpPc_Trns2_PwrDiscATestComplete_Cnt_lgc(FALSE);
	PwrDiscBTestComplete_Cnt_M_lgc = FALSE;
	Rte_IWrite_BkCpPc_Trns2_PwrDiscBTestComplete_Cnt_lgc(FALSE);
	PwrDiscClosed_Cnt_M_lgc = FALSE;
	Rte_IWrite_BkCpPc_Trns2_PwrDiscClosed_Cnt_lgc(FALSE);
	BulkCapPrechargeState_Cnt_M_enum = BULKCAP_WAITFORSTARTA;
	RunTimeFaultAcc_Cnt_M_u16 = D_ZERO_CNT_U16;
	
	
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CapPcDcStub_OP_SET
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <OP_SET> of PortPrototype <CapPcDcStub>
 *
 **********************************************************************************************************************
 *
 * Mode Interfaces:
 * ================
 *   Rte_ModeType_StaMd_Mode Rte_Mode_SystemState_Mode(void)
 *   Modes of Rte_ModeType_StaMd_Mode:
 *   - RTE_MODE_StaMd_Mode_DISABLE
 *   - RTE_MODE_StaMd_Mode_OFF
 *   - RTE_MODE_StaMd_Mode_OPERATE
 *   - RTE_MODE_StaMd_Mode_WARMINIT
 *   - RTE_TRANSITION_StaMd_Mode
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType CapPcDcStub_OP_SET(IoHwAb_BoolType signal)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DigitalOut_E_NOT_OK
 *
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_SA_BKCPPC_APPL_CODE) CapPcDcStub_OP_SET(IoHwAb_BoolType signal)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CapPcDcStub_OP_SET (returns application error)
 *********************************************************************************************************************/

  /* Capacitor Discharge/Precharge server stub for Configuration A - See '6.8.1.1 Design Rationale' in MDD for details */
  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define RTE_STOP_SEC_SA_BKCPPC_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
