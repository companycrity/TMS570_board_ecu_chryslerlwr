


/*
   !! B E T A   V E R S I O N !!

  These programs are fully operative programs.
  However, they are not thoroughly tested yet (beta-version).
  With regard to the fact that the programs are a beta-version only,
  Vector Informatik's liability shall be expressly excluded in cases of ordinary negligence,
  to the extent admissible by law or statute.
*/



/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Ap_DemIf.c
 *     Workspace:  E:/__SandBox__/MyCustomerProjects/Nexteer/Chrysler_LWR_EPS_TMS570-tzj9qy_synergy/Chrysler_LWR_EPS_TMS570/Tools/AsrProject/Config/DCF/EPS.dcf
 *     SW-C Type:  Ap_DemIf
 *  Generated at:  Wed Jul 25 12:02:53 2012
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1 (Beta)
 *       License:  License CBD1010124 valid for CBD1010124 Nexteer  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  C-Code implementation template for SW-C <Ap_DemIf>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/* Version Control:
 * Date Created:      Tue Jul 19 10:51:26 2011
 * %version:          10 %
 * %derived_by:       sz1dx6 %
 * %date_modified:    Thu Jan 16 11:24:06 2014 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 07/19/11  1        LWW       Initial stub (no DEM currently)
 * 09/24/11  3        LWW       FWK updates for DEM integration
 * 09/26/11  4        SAH       DTC calls for DEM integration
 * 09/28/11  5        LWW       DEM integration fixes
 * 12/15/11  6        LWW       Changes for standard port usage
 * 01/25/12	 7		  LWW		FWK Updates
 * 08/12/13  '5		  SAH		Input updates for EC6 enable
 * 09/11/13  '6       NRAR      Changes made as per Anom 5453. CTC's for NTC's 14E, 14F are set based on         9685
                                 "Power Distribution Faults" filter conditions 
 * 10/12/13  '7		  SAH		Added Dem_Init1 on quick ign cycle
 * 11/20/13  8        M. Story  Anomaly 6023
 * 11/21/13  9        M. Story  Anomaly 6052
 * 01/15/14  10       M. Story  Anomaly 6191
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "Rte_Ap_DemIf.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "Dem.h"
#include "fixmath.h"

#define 	D_NTCFAILED_CNT_U8							0x01
#define 	D_NET_CFG_STAT_PT_PROGRAMMED_CNT_U8			0x01 /* Programmed, Configuration is valid*/
#define     D_Voltage_Resolution						10

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
 * Double: Real in interval [-DBL_MAX...DBL_MAX] with double precision including NaN (standard type)
 * Float: Real in interval [-FLT_MAX...FLT_MAX] with single precision (standard type)
 * SInt16: Integer in interval [-32768...32767] (standard type)
 * SInt32: Integer in interval [-2147483648...2147483647] (standard type)
 * SInt8: Integer in interval [-128...127] (standard type)
 * UInt16: Integer in interval [0...65535] (standard type)
 * UInt32: Integer in interval [0...4294967295] (standard type)
 * UInt8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
 * Dem_OperationCycleStateType: Enumeration of integer in interval [1...2] with enumerators
 *   DEM_CYCLE_STATE_START (1U)
 *   DEM_CYCLE_STATE_END (2U)
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
 *   NTC_Num_RAMDiag_ADCRamFlt (26U)
 *   NTC_Num_DCANRAMFault (27U)
 *   NTC_Num_CPU_RegVer (32U)
 *   NTC_Num_CPU_CoreInitFlt (33U)
 *   NTC_Num_CPU_CoreRunTimeFlt (34U)
 *   NTC_Num_CPU_ClockMon (35U)
 *   NTC_Num_PropExeDiag_InitDiag (41U)
 *   NTC_Num_PrgFlwDeadlnFlt (42U)
 *   NTC_Num_PropExeDiag_RunTimeDiag (43U)
 *   NTC_Num_PropExeDiag_COPTimeout (44U)
 *   NTC_Num_PerDiag_ADC1Flt (50U)
 *   NTC_Num_PerDiag_ADC2Flt (51U)
 *   NTC_Num_PerDiag_ADCCrossChkFlt (52U)
 *   NTC_Num_PerDiag_IllegalAccess (53U)
 *   NTC_Num_TmpMonFunc (64U)
 *   NTC_Num_TmpMonRunTimeFlt (65U)
 *   NTC_Num_PowerRelayInitFlt (66U)
 *   NTC_Num_PrechargeFailure (67U)
 *   NTC_Num_PowerRelayRunFlt (68U)
 *   NTC_Num_Thermistor (69U)
 *   NTC_Num_RefSupplyVltg (70U)
 *   NTC_Num_TrcvrInterfaceFlt (71U)
 *   NTC_Num_GateDrvFlt (77U)
 *   NTC_Num_OnStateSingleFET (78U)
 *   NTC_Num_OnStateMultiFET (79U)
 *   NTC_Num_PhaseVoltageVerf (80U)
 *   NTC_Num_PhaseDscnt (81U)
 *   NTC_Num_DigPhaseVoltageVerf (82U)
 *   NTC_Num_CurrentMeas1 (84U)
 *   NTC_Num_CurrentMeas2 (85U)
 *   NTC_Num_CurrentMeasCrossChk (86U)
 *   NTC_Num_HwTrqSensor (96U)
 *   NTC_Num_AnaVsDigHwTrq (97U)
 *   NTC_Num_TrqSensorRecoveryFlt (98U)
 *   NTC_Num_T1vsT2 (101U)
 *   NTC_Num_T1OutofRange (102U)
 *   NTC_Num_T2OutofRange (103U)
 *   NTC_Num_DigT1vsT2 (104U)
 *   NTC_Num_DigT1OutofRange (105U)
 *   NTC_Num_DigT2OutofRange (106U)
 *   NTC_Num_HWASensorRel (110U)
 *   NTC_Num_HWASensorAbs (111U)
 *   NTC_Num_PriMSB_SinCosCorr (112U)
 *   NTC_Num_SecMSB_SinCosCorr (113U)
 *   NTC_Num_PriVsSec_SinCosCorr (114U)
 *   NTC_Num_DigMSBFlt (115U)
 *   NTC_Num_MtrVelFlt (116U)
 *   NTC_Num_HWAtoMtrAngleCorr (117U)
 *   NTC_Num_TurnCntr_PosLoss (128U)
 *   NTC_Num_TurnCntr_NonPosLoss (129U)
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
 *   NTC_Num_IgnConfDiag (184U)
 *   NTC_Num_TurnsCntrLowBattFault (185U)
 *   NTC_Num_EEPROMCloseFailed (191U)
 *   NTC_Num_SigPath1CrossChk (192U)
 *   NTC_Num_SigPath2CrossChk (193U)
 *   NTC_Num_SigPath3CrossChk (194U)
 *   NTC_Num_SigPath4CrossChk (195U)
 *   NTC_Num_SigPath5CrossChk (196U)
 *   NTC_Num_WhlImbAlgFlt (224U)
 *   NTC_Num_PAHwVelFlt (225U)
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
 *   NTC_Num_InvalidMsg_N (296U)
 *   NTC_Num_MissingMsg_N (297U)
 *   NTC_Num_CRCFltMsg_N (298U)
 *   NTC_Num_PgrsCntFltMsg_N (299U)
 *   NTC_Num_DataRngFltMsg_N (300U)
 *   NTC_Num_DataRateFltMsg_N (301U)
 *   NTC_Num_DataOtherFltMsg_N (302U)
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
 *   NTC_Num_SysConsistencyVerf (496U)
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
 * NxtrOpCycle: Enumeration of integer in interval [0...0] with enumerators
 *   NxtrDefaultOpCycle (0U)
 * NxtrOpCycleState: Enumeration of integer in interval [1...2] with enumerators
 *   NXTR_CYCLE_STATE_START (1U)
 *   NXTR_CYCLE_STATE_END (2U)
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
 * Boolean: D_TRUE_CNT_LGC = TRUE
 * Double: D_SFINVMILLI_ULS_F32 = 1000
 * Float: D_100MS_SEC_F32 = 0.1F
 * Float: D_180OVRPI_ULS_F32 = 57.295779513082F
 * Float: D_2MS_MS_F32 = 0.002F
 * Float: D_2MS_SEC_F32 = 0.002F
 * Float: D_2PI_ULS_F32 = 6.2831853071796F
 * Float: D_MTRCTRLHIGHLMT_VOLTS_F32 = 18.0F
 * Float: D_MTRCTRLLOWLMT_VOLTS_F32 = 9.0F
 * Float: D_MTRTRQCMDHILMT_MTRNM_F32 = 8.8F
 * Float: D_MTRTRQCMDLOLMT_MTRNM_F32 = -8.8F
 * Float: D_MTRTRQCMLOLMT_MTRNM_F32 = -8.8F
 * Float: D_ONE_ULS_F32 = 1.0F
 * Float: D_PIOVR180_ULS_F32 = 0.0174532925199F
 * Float: D_PI_ULS_F32 = 3.1415926535898F
 * Float: D_VECUMIN_VOLTS_F32 = 5.0F
 * Float: D_ZERO_ULS_F32 = 0.0F
 * SInt16: D_NEGONE_CNT_S16 = -1
 * SInt16: D_ONE_CNT_S16 = 1
 * SInt16: D_ZERO_CNT_S16 = 0
 * SInt32: D_NEGONE_CNT_S32 = -1
 * SInt32: D_ONE_CNT_S32 = 1
 * SInt32: D_ZERO_CNT_S32 = 0
 * SInt8: D_NEGONE_CNT_S8 = -1
 * SInt8: D_ONE_CNT_S8 = 1
 * SInt8: D_ZERO_CNT_S8 = 0
 * UInt16: D_DELTAROLLASST_MTRNM_U5P11 = 512U
 * UInt16: D_MAXCONF_ULS_U8P8 = 256U
 * UInt16: D_MTRPOLESDIV2_CNT_U16 = 3U
 * UInt16: D_ONE_CNT_U16 = 1U
 * UInt16: D_QUADRANT1_CNT_U16 = 1U
 * UInt16: D_QUADRANT2_CNT_U16 = 2U
 * UInt16: D_QUADRANT3_CNT_U16 = 3U
 * UInt16: D_QUADRANT4_CNT_U16 = 4U
 * UInt16: D_RACKCNTRUNLEARNED_CNT_U16 = 65535U
 * UInt16: D_RACKTOVEHCNTRINVALID_CNT_U16 = 4095U
 * UInt16: D_RACKTOVEHCNTRUNLEARNED_CNT_U16 = 4094U
 * UInt16: D_ZERO_CNT_U16 = 0U
 * UInt32: D_ONE_CNT_U32 = 1U
 * UInt32: D_SVCDFTKININTDIAG_CNT_B32 = 4U
 * UInt32: D_ZERO_CNT_U32 = 0U
 * UInt8: D_MTRPOLESDIV2_CNT_U8 = 3U
 * UInt8: D_ONE_CNT_U8 = 1U
 * UInt8: D_QUADRANT1_CNT_U8 = 1U
 * UInt8: D_QUADRANT2_CNT_U8 = 2U
 * UInt8: D_QUADRANT3_CNT_U8 = 3U
 * UInt8: D_QUADRANT4_CNT_U8 = 4U
 * UInt8: D_TURNSCNTRPARTNUMINIT_CNT_U08 = 255U
 * UInt8: D_ZERO_CNT_U8 = 0U
 *
 *********************************************************************************************************************/


#define RTE_START_SEC_AP_DEMIF_APPL_CODE
#include "MemMap.h"

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DemIf_Init
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_DEMIF_APPL_CODE) DemIf_Init(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DemIf_Init
 *********************************************************************************************************************/

	 (void)Dem_SetEnableCondition (DEM_ID_EC5_IOD_FUSE_STATUS,TRUE); //For now, Assuming EC5 is always fulfilled
	 (void)Dem_SetEnableCondition (DEM_ID_EC8_IODEVICE_CONFIG,TRUE); //For now, Assuming EC8 is always fulfilled

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DemIf_RestartDem
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <RestartDem> of PortPrototype <DemIf>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void DemIf_RestartDem(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_DEMIF_APPL_CODE) DemIf_RestartDem(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DemIf_RestartDem
 *********************************************************************************************************************/

	Dem_Init1();
	Dem_Init();

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DemIf_SetEventStatus
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <SetEventStatus> of PortPrototype <DemIf>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DemIf_SetEventStatus(UInt8 EventId, NxtrDiagMgrStatus EventStatus)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DemIf_E_NOT_OK
 *
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_AP_DEMIF_APPL_CODE) DemIf_SetEventStatus(UInt8 EventId, NxtrDiagMgrStatus EventStatus)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DemIf_SetEventStatus (returns application error)
 *********************************************************************************************************************/
	Std_ReturnType result;
	VAR(boolean, AUTOMATIC) EventHandled_Cnt_T_lgc = FALSE;
	VAR(boolean,  AUTOMATIC) BusOffPresent_Cnt_T_lgc;
	VAR(boolean,  AUTOMATIC) DataOtherFltMsgPresent_Cnt_T_lgc;
	VAR(boolean,  AUTOMATIC) DataOtherFlt2MsgPresent_Cnt_T_lgc;
	VAR(uint8,  AUTOMATIC) CMDIgnStat_Cnt_u08;
	VAR(uint16,  AUTOMATIC) NET_CFG_STAT_PT_Cnt_T_u16;
	VAR(uint8,  AUTOMATIC) CMDLclIgnStat_Cnt_u08;

	Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_BusOffCh1, &BusOffPresent_Cnt_T_lgc);
	Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_DataOtherFltMsg_R, &DataOtherFltMsgPresent_Cnt_T_lgc);
	Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_DataOtherFlt2Msg_R, &DataOtherFlt2MsgPresent_Cnt_T_lgc);
	Rte_Read_Ap_DemIf_CMDIgnStat_Cnt_u08(&CMDIgnStat_Cnt_u08);
	Rte_Read_Ap_DemIf_NET_CFG_STAT_PT_Cnt_u16(&NET_CFG_STAT_PT_Cnt_T_u16);

	switch(CMDIgnStat_Cnt_u08)
	{
	case 0:
		CMDLclIgnStat_Cnt_u08 = 2;
		break;
	case 1:
		CMDLclIgnStat_Cnt_u08 = 2;
		break;
	case 2:
		CMDLclIgnStat_Cnt_u08 = 1;
		break;
	case 3:
		CMDLclIgnStat_Cnt_u08 = 1;
		break;
	case 4:
		CMDLclIgnStat_Cnt_u08 = 0;
		break;
	case 5:
		CMDLclIgnStat_Cnt_u08 = 3;
		break;
	default:
		CMDLclIgnStat_Cnt_u08 = 4;
		break;
	}

	FrfmSetLocalIgnitionStatus(CMDLclIgnStat_Cnt_u08);

	if((TRUE == DataOtherFltMsgPresent_Cnt_T_lgc) ||
			(TRUE == DataOtherFlt2MsgPresent_Cnt_T_lgc))
	{
		switch(EventId)/* Suppress ECU Faults*/
		{
			case 0x00U:
			case 0x09U:
			case 0x08U:
			case 0x03U:
			case 0x19U:
			case 0x1BU:
			{
				EventHandled_Cnt_T_lgc = TRUE;
			}
			break;
			default:
			break;
		}
	}

	if(0x04 != CMDIgnStat_Cnt_u08)
	{
		switch(EventId)/* Suppress Power Distribution Faults*/
		{
			case 0x04U:
			case 0x05U:
			case 0x06U: 
			case 0x07U:
			{
				EventHandled_Cnt_T_lgc = TRUE;
			}
			break;
			default:
			break;
		}
	}

	/* Suppress Nw Communication Faults*/
	if(((TRUE == DataOtherFltMsgPresent_Cnt_T_lgc) ||
			(TRUE == DataOtherFlt2MsgPresent_Cnt_T_lgc) ||
			(TRUE == BusOffPresent_Cnt_T_lgc) ||
			(0x01 != NET_CFG_STAT_PT_Cnt_T_u16)) &&
			(0x0EU == EventId))
	{
			EventHandled_Cnt_T_lgc = TRUE;
	}

	/* Suppress Nw Communication Faults*/
	if((0x04 != CMDIgnStat_Cnt_u08) ||
		(TRUE == DataOtherFltMsgPresent_Cnt_T_lgc) ||
		(TRUE == DataOtherFlt2MsgPresent_Cnt_T_lgc) ||
		(TRUE == BusOffPresent_Cnt_T_lgc)||
		(0x01 != NET_CFG_STAT_PT_Cnt_T_u16))
	{
		switch(EventId)
		{
			case 0x11U:
			case 0x12U:
			case 0x13U:
			case 0x14U:
			case 0x16U:
			case 0x17U:
			case 0x0DU:
			case 0x0FU:
			case 0x10U:
			case 0x1AU:
			{
				EventHandled_Cnt_T_lgc = TRUE;
			}
			break;
			default:
			break;
		}
	}

	if(FALSE == EventHandled_Cnt_T_lgc)
	{
		result = Dem_SetEventStatus(EventId, EventStatus);
	}

	return result;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DemIf_SetInputsConditions
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
 *   Float Rte_IRead_DemIf_SetInputsConditions_DemLocalVoltage_Volt_f32(void)
 *   Float Rte_IRead_DemIf_SetInputsConditions_DemSystemVoltage_Volt_f32(void)
 *   UInt8 Rte_IRead_DemIf_SetInputsConditions_NWCONFIG_STATUS_EC6_DE_NET_CFG_STAT_PT(void)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_GetNTCStatus(NTCNumber NTC, UInt8 *Status)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_DEMIF_APPL_CODE) DemIf_SetInputsConditions(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DemIf_SetInputsConditions
 *********************************************************************************************************************/
	VAR(uint8, AUTOMATIC) BusoffStatus_Cnt_T_u8;
	VAR(uint8, AUTOMATIC) NWConfigStatus_Cnt_T_u8;
	VAR(float32, AUTOMATIC) LocalVoltage_Cnt_T_f32;
	VAR(uint16, AUTOMATIC)  LocalVoltage_Cnt_T_u16;
	VAR(float32, AUTOMATIC) SystemVoltage_Cnt_T_f32;
	VAR(uint16, AUTOMATIC)  SystemVoltage_Cnt_T_u16;

	/* Handling of EC7: Bus Physical Status*/
	Rte_Call_NxtrDiagMgr_GetNTCStatus(NTC_Num_BusOffCh1, &BusoffStatus_Cnt_T_u8); //NTC NTC_Num_BusOffCh1???
	if ((BusoffStatus_Cnt_T_u8 & D_NTCFAILED_CNT_U8) == D_NTCFAILED_CNT_U8)
	{
		(void)Dem_SetEnableCondition (DEM_ID_EC7_BUS_PHYSICAL_STATUS,FALSE); //Assuming EC7 depends only on Bus Off DTC TestFailed
	}
	else
	{
		(void)Dem_SetEnableCondition (DEM_ID_EC7_BUS_PHYSICAL_STATUS,TRUE);
	}

	/* NWCONFIG_STATUS_EC6 */
	NWConfigStatus_Cnt_T_u8 = Rte_IRead_DemIf_SetInputsConditions_NET_CFG_STAT_PT_Cnt_u16();
	if (NWConfigStatus_Cnt_T_u8 == D_NET_CFG_STAT_PT_PROGRAMMED_CNT_U8)
	{
		(void)Dem_SetEnableCondition (DEM_ID_EC6_NWCONFIG_STATUS,TRUE);
	}
	else
	{
		(void)Dem_SetEnableCondition (DEM_ID_EC6_NWCONFIG_STATUS,FALSE);
	}

	/* Local voltage */
	LocalVoltage_Cnt_T_f32 = Rte_IRead_DemIf_SetInputsConditions_DemLocalVoltage_Volt_f32();
	//-- need scaling and conversion
	LocalVoltage_Cnt_T_f32 = (float32)(LocalVoltage_Cnt_T_f32 * D_Voltage_Resolution);
	LocalVoltage_Cnt_T_u16 = FPM_FloatToFixed_m(LocalVoltage_Cnt_T_f32, u16p0_T);
	(void)Dem_SetVoltageValue(DEM_LOCALVOLTAGE,LocalVoltage_Cnt_T_u16 );


	/* System voltage */
	SystemVoltage_Cnt_T_f32 = Rte_IRead_DemIf_SetInputsConditions_DemSystemVoltage_Volt_f32();
	//-- need scaling and conversion
	SystemVoltage_Cnt_T_f32 = (float32)(SystemVoltage_Cnt_T_f32 * D_Voltage_Resolution);
	SystemVoltage_Cnt_T_u16 = FPM_FloatToFixed_m(LocalVoltage_Cnt_T_f32, u16p0_T);
	(void)Dem_SetVoltageValue(DEM_SYSTEMVOLTAGE,SystemVoltage_Cnt_T_u16 );


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DemIf_SetOperationCycleState
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <SetOperationCycleState> of PortPrototype <DemIf>
 *
 **********************************************************************************************************************
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_OperationCycle_SetOperationCycleState(Dem_OperationCycleStateType CycleState)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_OperationCycle_DEM_E_QUEUE_OVERFLOW, RTE_E_OperationCycle_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void DemIf_SetOperationCycleState(NxtrOpCycle NxtrOperationCycleId, NxtrOpCycleState NxtrCycleState)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_DEMIF_APPL_CODE) DemIf_SetOperationCycleState(NxtrOpCycle NxtrOperationCycleId, NxtrOpCycleState NxtrCycleState)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DemIf_SetOperationCycleState
 *********************************************************************************************************************/
	
	(void)Dem_SetOperationCycleState(NxtrOperationCycleId, NxtrCycleState);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define RTE_STOP_SEC_AP_DEMIF_APPL_CODE
#include "MemMap.h"


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
