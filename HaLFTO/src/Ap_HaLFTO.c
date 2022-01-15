/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Ap_HaLFTO.c
 *     Workspace:  C:/SynergyWorkspace/WorkingProjects/HaLFTO-008.0_NoUTP/HaLFTO/autosar
 *     SW-C Type:  Ap_HaLFTO
 *  Generated at:  Tue May 20 13:31:06 2014
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nexteer  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  C-Code implementation template for SW-C <Ap_HaLFTO>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/* Version Control:
 * Date Created:      Fri Nov  2 09:03:23 2012
 * %version:          12 %
 * %derived_by:       gzkys7 %
 * %date_modified:    Thu Mar  6 10:48:47 2014 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author    Change Description                                                           SCR #
 * --------  -------  --------  ---------------------------------------------------------------------------  ----------
 * 10/31/12  1        BWL       Initial Version (FDD 40D v001)                                               6604
 * 02/20/13  2        SR        Corrected vehicle speed check Incorrect HaLF activation                      7414
 * 02/26/13  3        SR        Corrected Transition T5 from Recoverable to Inactive as per anomaly 4527     7496
 * 05/08/13  4        BDO       Update to FDD 40D v004														 8232
 * 07/09/13  5		  SP		Update to CF 08C v001														 8739
 * 10/07/13  6        MR        Added logic to pass the NTCs if the enable criteria is FALSE.                9801
 * 01/23/14  7        VT		Updated to FDD CF-08C v004													11194
 * 02/06/14  8        VT		Updated to FDD CF-08C v005													11365
 * 02/24/14  9        VT		Updated to FDD CF-08C v006													11467
 * 03/06/14  10       VT		Updated to FDD CF-08C v007													11566
 * 03/06/14  11       M. Story	Updated to FDD CF-08C v008													11817
 * 05/20/14	 12       SB		A6806 anomaly fix															11959
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


 Mode Declaration Groups:
 ========================
  StaMd_Mode
    EPS System State mode declaration

 *********************************************************************************************************************/

#include "Rte_Ap_HaLFTO.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "Ap_HaLFTO_Cfg.h"
#include "GlobalMacro.h"
#include "CalConstants.h"
#include "float.h"


#define D_HALFSTATEINACTIVE_CNT_U08		((uint8)0U)
#define D_HALFSTATEACTIVE_CNT_U08		((uint8)1U)
#define D_HALFSTATEIHIBITED_CNT_U08		((uint8)2U)
#define D_HALFSTATERECOVERABLE_CNT_U08	((uint8)3U)

#define D_DSTACTIVE1_CNT_U08			((uint8)5U)
#define D_DSTACTIVE2_CNT_U08			((uint8)6U)
#define D_DSTACTIVE3_CNT_U08			((uint8)7U)

#define D_INCORHALFACTVNMASK_CNT_U08	((uint8)0x01U)
#define D_HALFDEACTLONGMASK_CNT_U08		((uint8)0x02U)

#define HALFTO_START_SEC_VAR_CLEARED_8
#include "MemMap.h" /* PRQA S 5087 *//* PRQA S 3218 1 */
STATIC VAR(uint8, AP_HALFTO_VAR) HaLFTO_State_Cnt_M_u08;
#define HALFTO_STOP_SEC_VAR_CLEARED_8
#include "MemMap.h" /* PRQA S 5087 */

#define HALFTO_START_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h" /* PRQA S 5087 *//* PRQA S 3218 4*/
STATIC VAR(boolean, AP_HALFTO_VAR) HaLFTO_IncorHaLFActvnFailed_Cnt_M_lgc;
STATIC VAR(boolean, AP_HALFTO_VAR) HaLFTO_HaLFDeactLongFailed_Cnt_M_lgc;
STATIC VAR(boolean, AP_HALFTO_VAR) HaLFTO_DeactDSTStateChkFail_Cnt_D_lgc;
#define HALFTO_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h" /* PRQA S 5087 */

#define HALFTO_START_SEC_VAR_NOINIT_32
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(uint32, AP_HALFTO_VAR) HaLFTO_IncorHaLFActvnHwTrqTimer_mS_M_u32;
STATIC VAR(uint32, AP_HALFTO_VAR) HaLFTO_IncorHaLFActvnVehSpdTimer_mS_M_u32;
STATIC VAR(uint32, AP_HALFTO_VAR) HaLFTO_IncorHaLFActvnRevGearTimer_mS_M_u32;
STATIC VAR(uint32, AP_HALFTO_VAR) HaLFTO_HaLFDeactHwTrqTimer_mS_M_u32mS_M_u32;
STATIC VAR(uint32, AP_HALFTO_VAR) HaLFTO_HaLFDeactVehSpdTimer_mS_M_u32;
STATIC VAR(uint32, AP_HALFTO_VAR) HaLFTO_HaLFDeactRevGearTimer_mS_M_u32;
STATIC VAR(uint32, AP_HALFTO_VAR) HaLFTO_DSTSyncTimer_mS_M_u32;
STATIC VAR(uint32, AP_HALFTO_VAR) HaLFTO_LimitPercentFilteredTimer_mS_M_u32;
#define HALFTO_STOP_SEC_VAR_NOINIT_32
#include "MemMap.h" /* PRQA S 5087 */


STATIC INLINE FUNC(NxtrDiagMgrStatus, RTE_AP_HALFTO_APPL_CODE) HwTrqVehSpdRevGearCheck( VAR(uint16,  AUTOMATIC) HwTrqTime_mS_T_u16,
																	    CONSTP2VAR(uint32,  AUTOMATIC, AP_HALFTO_CONST) HwTrqTimerPtr_mS_T_u32,
														   	   	   	   	   	   VAR(float32, AUTOMATIC) MaxHwTrq_HwNm_T_f32,
														   	   	   	   	   	   VAR(uint16,  AUTOMATIC) VehSpdTime_mS_T_u16,
														   	   	   	   	CONSTP2VAR(uint32,  AUTOMATIC, AP_HALFTO_CONST) VehSpdTimerPtr_mS_T_u32,
														   	   	   	   	   	   VAR(float32, AUTOMATIC) MinVehSpd_Kph_T_f32,
														   	   	   	   	   	   VAR(float32, AUTOMATIC) MaxVehSpd_Kph_T_f32,
														   	   	   	   	   	   VAR(uint16,  AUTOMATIC) RevGearChkTime_mS_T_u16,
														   	   	   	   	CONSTP2VAR(uint32,  AUTOMATIC, AP_HALFTO_CONST) RevGearTimerPtr_mS_T_u32);
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
 *   NTC_Num_PhaseDscntFailedDisable (83u)
 *   NTC_Num_CurrentMeas1 (84u)
 *   NTC_Num_CurrentMeas2 (85u)
 *   NTC_Num_CurrentMeasCrossChk (86u)
 *   NTC_Num_PDSupplyOverVoltage (87u)
 *   NTC_Num_ChargePumpUnderVoltage (88u)
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
 *   NTC_Num_RedT1vsT2 (107u)
 *   NTC_Num_HWASensorRel (110u)
 *   NTC_Num_HWASensorAbs (111u)
 *   NTC_Num_PriMSB_SinCosCorr (112u)
 *   NTC_Num_SecMSB_SinCosCorr (113u)
 *   NTC_Num_PriVsSec_SinCosCorr (114u)
 *   NTC_Num_DigMSBFlt (115u)
 *   NTC_Num_MtrVelFlt (116u)
 *   NTC_Num_HWAtoMtrAngleCorr (117u)
 *   NTC_Num_RedPriVsSec_SinCosCorr (118u)
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
 *   NTC_Num_StaMdsSysC (203u)
 *   NTC_NUM_SysFailureForRotVel (204u)
 *   NTC_NUM_SysFailForRedntRotVel (205u)
 *   NTC_Num_SysFailureForTrqSnsr (206u)
 *   NTC_Num_SysFailureForRedTrqSnsr (207u)
 *   NTC_NUM_SysFailureForCtrlVolt (209u)
 *   NTC_Num_GlblSgnlOvrwrtDet (223u)
 *   NTC_Num_VLF_00 (224u)
 *   NTC_Num_VLF_01 (225u)
 *   NTC_Num_VLF_02 (226u)
 *   NTC_Num_VLF_03 (227u)
 *   NTC_Num_VLF_04 (228u)
 *   NTC_Num_VLF_05 (229u)
 *   NTC_Num_VLF_06 (230u)
 *   NTC_Num_VLF_07 (231u)
 *   NTC_Num_VLF_08 (232u)
 *   NTC_Num_VLF_09 (233u)
 *   NTC_Num_VLF_10 (234u)
 *   NTC_Num_VLF_11 (235u)
 *   NTC_Num_VLF_12 (236u)
 *   NTC_Num_VLF_13 (237u)
 *   NTC_Num_VLF_14 (238u)
 *   NTC_Num_VLF_15 (239u)
 *   NTC_Num_VLF_16 (240u)
 *   NTC_Num_VLF_17 (241u)
 *   NTC_Num_VLF_18 (242u)
 *   NTC_Num_VLF_19 (243u)
 *   NTC_Num_VLF_20 (244u)
 *   NTC_Num_VLF_21 (245u)
 *   NTC_Num_VLF_22 (246u)
 *   NTC_Num_VLF_23 (247u)
 *   NTC_Num_VLF_24 (248u)
 *   NTC_Num_VLF_25 (249u)
 *   NTC_Num_VLF_26 (250u)
 *   NTC_Num_VLF_27 (251u)
 *   NTC_Num_VLF_28 (252u)
 *   NTC_Num_VLF_29 (253u)
 *   NTC_Num_VLF_30 (254u)
 *   NTC_Num_VLF_31 (255u)
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
 * Float: D_ZERO_ULS_F32 = 0
 * UInt8: D_ZERO_CNT_U8 = 0u
 *
 *********************************************************************************************************************/


#define RTE_START_SEC_AP_HALFTO_APPL_CODE
#include "MemMap.h"/* PRQA S 5087 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: HaLFTO_Init1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
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
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_HaLFState_SCom_Transition(UInt8 State_Cnt_T_u08)
 *     Synchronous Server Invocation. Timeout: None
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_SystemTime_GetSystemTime_mS_u32(UInt32 *CurrentTime)
 *     Synchronous Service Invocation. Timeout: None
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_HALFTO_APPL_CODE) HaLFTO_Init1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: HaLFTO_Init1
 *********************************************************************************************************************/
	
	
	VAR(uint32, AUTOMATIC) Time_mS_u32;
	
	(void)Rte_Call_HaLFState_SCom_Transition(D_HALFSTATEINACTIVE_CNT_U08);
	
	(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&Time_mS_u32);
	HaLFTO_IncorHaLFActvnHwTrqTimer_mS_M_u32 = Time_mS_u32;
	HaLFTO_IncorHaLFActvnVehSpdTimer_mS_M_u32 = Time_mS_u32;
	HaLFTO_IncorHaLFActvnRevGearTimer_mS_M_u32 = Time_mS_u32;

	HaLFTO_HaLFDeactHwTrqTimer_mS_M_u32mS_M_u32 = Time_mS_u32;
	HaLFTO_HaLFDeactVehSpdTimer_mS_M_u32 = Time_mS_u32;
	HaLFTO_HaLFDeactRevGearTimer_mS_M_u32 = Time_mS_u32;

	HaLFTO_DSTSyncTimer_mS_M_u32 = Time_mS_u32;
	HaLFTO_LimitPercentFilteredTimer_mS_M_u32 = Time_mS_u32;
	
	(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_VLF_04, 0x0U, NTC_STATUS_PASSED);
	
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: HaLFTO_Per1
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
 *   UInt8 Rte_IRead_HaLFTO_Per1_DSTState_Cnt_u08(void)
 *   Boolean Rte_IRead_HaLFTO_Per1_DiagStsNonRecRmpToZeroFltPres_Cnt_lgc(void)
 *   Boolean Rte_IRead_HaLFTO_Per1_DiagStsRecRmpToZeroFltPres_Cnt_lgc(void)
 *   Boolean Rte_IRead_HaLFTO_Per1_HaLFEnableRqst_Cnt_lgc(void)
 *   Boolean Rte_IRead_HaLFTO_Per1_HaLFErrInterfaceActive_Cnt_lgc(void)
 *   Boolean Rte_IRead_HaLFTO_Per1_HaLFExtSystemFltActive_Cnt_lgc(void)
 *   Boolean Rte_IRead_HaLFTO_Per1_HaLFFuncPresent_Cnt_lgc(void)
 *   Boolean Rte_IRead_HaLFTO_Per1_HaLFIntSystemFltActive_Cnt_lgc(void)
 *   Boolean Rte_IRead_HaLFTO_Per1_HaLFSWATrqFail_Cnt_lgc(void)
 *   Boolean Rte_IRead_HaLFTO_Per1_HaLFSlewComplete_Cnt_lgc(void)
 *   Boolean Rte_IRead_HaLFTO_Per1_HaLFTrqOvReverseGearEngage_Cnt_lgc(void)
 *   Float Rte_IRead_HaLFTO_Per1_HwTorque_HwNm_f32(void)
 *   Float Rte_IRead_HaLFTO_Per1_LimitPercentFiltered_Uls_f32(void)
 *   Boolean Rte_IRead_HaLFTO_Per1_PrevHaLFEnableRqst_Cnt_lgc(void)
 *   Float Rte_IRead_HaLFTO_Per1_PrevHaLFTrqOvCmdRqst_MtrNm_f32(void)
 *   Boolean Rte_IRead_HaLFTO_Per1_TOEOLDisable_Cnt_lgc(void)
 *   Float Rte_IRead_HaLFTO_Per1_VehicleSpeed_Kph_f32(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_HaLFTO_Per1_HaLFActive_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_HaLFTO_Per1_HaLFActive_Cnt_lgc(void)
 *   void Rte_IWrite_HaLFTO_Per1_HaLFState_Cnt_u08(UInt8 data)
 *   UInt8 *Rte_IWriteRef_HaLFTO_Per1_HaLFState_Cnt_u08(void)
 *   void Rte_IWrite_HaLFTO_Per1_HaLFSuspend_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_HaLFTO_Per1_HaLFSuspend_Cnt_lgc(void)
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
 *   Std_ReturnType Rte_Call_HaLFState_SCom_Transition(UInt8 State_Cnt_T_u08)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_GetNTCFailed(NTCNumber NTC_Cnt_T_enum, Boolean *NTCFailed_Ptr_T_lgc)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
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

FUNC(void, RTE_AP_HALFTO_APPL_CODE) HaLFTO_Per1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: HaLFTO_Per1
 *********************************************************************************************************************/
	
	
	VAR(uint8,   AUTOMATIC) DSTState_Cnt_T_u08;
	VAR(boolean, AUTOMATIC) DiagStsNonRecRmpToZeroFltPres_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) DiagStsRecRmpToZeroFltPres_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) HaLFEnableRqst_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) HaLFErrInterfaceActive_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) HaLFExtSystemFltActive_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) HaLFFuncPresent_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) HaLFIntSystemFltActive_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) HaLFSWATrqFail_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) HaLFSlewComplete_Cnt_T_lgc;
	VAR(float32, AUTOMATIC) LimitPercentFiltered_Uls_T_f32;
	VAR(boolean, AUTOMATIC) PrevHaLFEnableRqst_Cnt_T_lgc;
	VAR(float32, AUTOMATIC) PrevTrqOvCmdRqst_MtrNm_T_f32;
	
	
	VAR(NxtrDiagMgrStatus,  AUTOMATIC) IncorHaLFActvnStatus_Cnt_T_enum;
	VAR(NxtrDiagMgrStatus,  AUTOMATIC) HaLFDeactLongStatus_Cnt_T_enum;

	VAR(uint16,  AUTOMATIC) ElapsedTime_mS_T_u16;
	VAR(boolean, AUTOMATIC) NTCLowBattVtg_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) HaLFSuspend_T_lgc;
	VAR(uint8,   AUTOMATIC) HaLFTO_State_Cnt_T_u08;
	VAR(boolean, AUTOMATIC) TOEOLDisable_Cnt_T_lgc;
	
	/* Configurable Start of Runnable Checkpoint */
	Rte_Call_HaLFTO_Per1_CP0_CheckpointReached();
	
	DSTState_Cnt_T_u08 = Rte_IRead_HaLFTO_Per1_DSTState_Cnt_u08();
	DiagStsNonRecRmpToZeroFltPres_Cnt_T_lgc = Rte_IRead_HaLFTO_Per1_DiagStsNonRecRmpToZeroFltPres_Cnt_lgc();
	DiagStsRecRmpToZeroFltPres_Cnt_T_lgc = Rte_IRead_HaLFTO_Per1_DiagStsRecRmpToZeroFltPres_Cnt_lgc();
	HaLFEnableRqst_Cnt_T_lgc = Rte_IRead_HaLFTO_Per1_HaLFEnableRqst_Cnt_lgc();
	HaLFErrInterfaceActive_Cnt_T_lgc = Rte_IRead_HaLFTO_Per1_HaLFErrInterfaceActive_Cnt_lgc();
	HaLFExtSystemFltActive_Cnt_T_lgc = Rte_IRead_HaLFTO_Per1_HaLFExtSystemFltActive_Cnt_lgc();
	HaLFFuncPresent_Cnt_T_lgc = Rte_IRead_HaLFTO_Per1_HaLFFuncPresent_Cnt_lgc();
	HaLFIntSystemFltActive_Cnt_T_lgc = Rte_IRead_HaLFTO_Per1_HaLFIntSystemFltActive_Cnt_lgc();
	HaLFSWATrqFail_Cnt_T_lgc = Rte_IRead_HaLFTO_Per1_HaLFSWATrqFail_Cnt_lgc();
	HaLFSlewComplete_Cnt_T_lgc = Rte_IRead_HaLFTO_Per1_HaLFSlewComplete_Cnt_lgc();
	LimitPercentFiltered_Uls_T_f32 = Rte_IRead_HaLFTO_Per1_LimitPercentFiltered_Uls_f32();
	TOEOLDisable_Cnt_T_lgc = Rte_IRead_HaLFTO_Per1_TOEOLDisable_Cnt_lgc();
	PrevHaLFEnableRqst_Cnt_T_lgc = Rte_IRead_HaLFTO_Per1_PrevHaLFEnableRqst_Cnt_lgc();
	PrevTrqOvCmdRqst_MtrNm_T_f32 = Rte_IRead_HaLFTO_Per1_PrevHaLFTrqOvCmdRqst_MtrNm_f32();
	IncorHaLFActvnStatus_Cnt_T_enum = NTC_STATUS_PASSED;
	HaLFDeactLongStatus_Cnt_T_enum = NTC_STATUS_PASSED;

	/* Incorrect HaLF Activation Diagnostic */
	
	if (TRUE == HaLFFuncPresent_Cnt_T_lgc)
	{
		if ((FALSE == PrevHaLFEnableRqst_Cnt_T_lgc) && (TRUE == HaLFEnableRqst_Cnt_T_lgc))
		{
			IncorHaLFActvnStatus_Cnt_T_enum = HwTrqVehSpdRevGearCheck( k_HaLFActvHwTrqTime_mS_u16,
																	   &HaLFTO_IncorHaLFActvnHwTrqTimer_mS_M_u32,
																	   k_HaLFActvMaxHwTrq_HwNm_f32,
																	   k_HaLFActvVehSpdTime_mS_u16,
																	   &HaLFTO_IncorHaLFActvnVehSpdTimer_mS_M_u32,
																	   k_HaLFActvMinVehSpd_Kph_f32,
																	   k_HaLFActvMaxVehSpd_Kph_f32,
																	   k_HaLFActvRevGearTime_mS_u16,
																	   &HaLFTO_IncorHaLFActvnRevGearTimer_mS_M_u32);

			if (Abs_f32_m(PrevTrqOvCmdRqst_MtrNm_T_f32) > FLT_EPSILON)
			{
				IncorHaLFActvnStatus_Cnt_T_enum = NTC_STATUS_FAILED;
			}
			
			if((TRUE == HaLFEnableRqst_Cnt_T_lgc) && (TRUE == HaLFSWATrqFail_Cnt_T_lgc))
			{
				IncorHaLFActvnStatus_Cnt_T_enum = NTC_STATUS_FAILED;
			}
			
			/* This call is mutually exclusive with the call for HaLF Deactivation Diagnostic.*/
			/*NTC_Num_VLF_04 is HalF function Fault*/
			(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_VLF_04, D_INCORHALFACTVNMASK_CNT_U08, IncorHaLFActvnStatus_Cnt_T_enum);
			
			if(NTC_STATUS_FAILED == IncorHaLFActvnStatus_Cnt_T_enum)
			{
				HaLFTO_IncorHaLFActvnFailed_Cnt_M_lgc = TRUE;
			}
			else
			{
				HaLFTO_IncorHaLFActvnFailed_Cnt_M_lgc = FALSE;
			}
		}
		else
		{
			/* HaLF Deactivation Diagnostic */
			if (TRUE == HaLFEnableRqst_Cnt_T_lgc)
			{
				HaLFDeactLongStatus_Cnt_T_enum = HwTrqVehSpdRevGearCheck(  k_HaLFDeactHwTrqTime_mS_u16,
																		   &HaLFTO_HaLFDeactHwTrqTimer_mS_M_u32mS_M_u32,
																		   k_HaLFDeactMaxHwTrq_HwNm_f32,
																		   k_HaLFDeactVehSpdTime_mS_u16,
																		   &HaLFTO_HaLFDeactVehSpdTimer_mS_M_u32,
																		   k_HaLFDeactMinVehSpd_Kph_f32,
																		   k_HaLFDeactMaxVehSpd_Kph_f32,
																		   k_HaLFDeactRevGearTime_mS_u16,
																		   &HaLFTO_HaLFDeactRevGearTimer_mS_M_u32);

				/* DST Active State Deactivation */
				if( (D_DSTACTIVE1_CNT_U08 == DSTState_Cnt_T_u08) || (D_DSTACTIVE2_CNT_U08 == DSTState_Cnt_T_u08) || (D_DSTACTIVE3_CNT_U08 == DSTState_Cnt_T_u08) )
				{
					(void)Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(HaLFTO_DSTSyncTimer_mS_M_u32, &ElapsedTime_mS_T_u16);

					if((ElapsedTime_mS_T_u16 >= k_HaLFDSTSyncTime_mS_u16) && (TRUE == HaLFEnableRqst_Cnt_T_lgc))
					{
						HaLFDeactLongStatus_Cnt_T_enum = NTC_STATUS_FAILED;
					}
				}
				else
				{
					(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&HaLFTO_DSTSyncTimer_mS_M_u32);
				}

				HaLFTO_DeactDSTStateChkFail_Cnt_D_lgc = DSTState_Cnt_T_u08;

				if(FALSE == HaLFEnableRqst_Cnt_T_lgc)
				{
					HaLFDeactLongStatus_Cnt_T_enum = NTC_STATUS_PASSED;
				}

				/*NTC_Num_VLF_04 is HalF function Fault*/
				(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_VLF_04, D_HALFDEACTLONGMASK_CNT_U08, HaLFDeactLongStatus_Cnt_T_enum);

				if(NTC_STATUS_FAILED == HaLFDeactLongStatus_Cnt_T_enum)
				{
					HaLFTO_HaLFDeactLongFailed_Cnt_M_lgc = TRUE;
				}
				else
				{
					HaLFTO_HaLFDeactLongFailed_Cnt_M_lgc = FALSE;
				}
			}
			
		}
	}
	else
	{
		(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&HaLFTO_IncorHaLFActvnHwTrqTimer_mS_M_u32);
		(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&HaLFTO_IncorHaLFActvnVehSpdTimer_mS_M_u32);
		(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&HaLFTO_IncorHaLFActvnRevGearTimer_mS_M_u32);
		(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&HaLFTO_HaLFDeactHwTrqTimer_mS_M_u32mS_M_u32);
		(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&HaLFTO_HaLFDeactVehSpdTimer_mS_M_u32);
		(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&HaLFTO_HaLFDeactRevGearTimer_mS_M_u32);
		(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&HaLFTO_DSTSyncTimer_mS_M_u32);
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_VLF_04, 0x0U, NTC_STATUS_PASSED);		
	}

	/* HalF Torque Overlay Enable */
	
	(void)Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_ExVoltageLow, &NTCLowBattVtg_Cnt_T_lgc);
	
	if(LimitPercentFiltered_Uls_T_f32 <= k_TrqOverlayLimitPerc_Uls_f32)
	{
		(void)Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(HaLFTO_LimitPercentFilteredTimer_mS_M_u32, &ElapsedTime_mS_T_u16);
		
		if((TRUE == HaLFErrInterfaceActive_Cnt_T_lgc) ||
			(ElapsedTime_mS_T_u16 < k_TrqOverlaySuspendTime_mS_u16) ||
			(TRUE == NTCLowBattVtg_Cnt_T_lgc) ||
			(TRUE == DiagStsNonRecRmpToZeroFltPres_Cnt_T_lgc) ||
			(TRUE == DiagStsRecRmpToZeroFltPres_Cnt_T_lgc))
		{
			HaLFSuspend_T_lgc = TRUE;
		}
		else
		{
			HaLFSuspend_T_lgc = FALSE;
		}
	}
	else
	{
		(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&HaLFTO_LimitPercentFilteredTimer_mS_M_u32);
		HaLFSuspend_T_lgc = TRUE;
	}
	
	/* Transition Vector Logic for HalF_State output */
	switch(HaLFTO_State_Cnt_M_u08)
	{
		case D_HALFSTATEINACTIVE_CNT_U08:
			/* T7 */
			if( (TRUE == DiagStsNonRecRmpToZeroFltPres_Cnt_T_lgc) ||
				(TRUE == HaLFIntSystemFltActive_Cnt_T_lgc) ||
				(TRUE == HaLFTO_IncorHaLFActvnFailed_Cnt_M_lgc))
			{
				HaLFTO_State_Cnt_T_u08 = D_HALFSTATEIHIBITED_CNT_U08;
			}
			/* T6 */
			else if((TRUE == HaLFSuspend_T_lgc) ||
				(TRUE == HaLFExtSystemFltActive_Cnt_T_lgc) ||
				(TRUE == TOEOLDisable_Cnt_T_lgc) )
			{
				HaLFTO_State_Cnt_T_u08 = D_HALFSTATERECOVERABLE_CNT_U08;
			}
			/* T1 */
			else if((Rte_Mode_SystemState_Mode() == RTE_MODE_StaMd_Mode_OPERATE) &&
				(TRUE == HaLFEnableRqst_Cnt_T_lgc) &&
				(FALSE == HaLFTO_IncorHaLFActvnFailed_Cnt_M_lgc) &&
				(TRUE == HaLFFuncPresent_Cnt_T_lgc) &&
				(TRUE == HaLFSlewComplete_Cnt_T_lgc))
			{
				HaLFTO_State_Cnt_T_u08 = D_HALFSTATEACTIVE_CNT_U08;
			}
			else
			{
				HaLFTO_State_Cnt_T_u08 = D_HALFSTATEINACTIVE_CNT_U08;
			}
			break;
		case D_HALFSTATEACTIVE_CNT_U08:
			/* T2 */
			if((TRUE == DiagStsNonRecRmpToZeroFltPres_Cnt_T_lgc) ||
				(TRUE == HaLFIntSystemFltActive_Cnt_T_lgc) ||
				(TRUE == HaLFTO_HaLFDeactLongFailed_Cnt_M_lgc))
			{
				HaLFTO_State_Cnt_T_u08 = D_HALFSTATEIHIBITED_CNT_U08;
			}
			/* T4 */
			else if((TRUE == HaLFSuspend_T_lgc) ||
				(TRUE == HaLFExtSystemFltActive_Cnt_T_lgc))
			{
				HaLFTO_State_Cnt_T_u08 = D_HALFSTATERECOVERABLE_CNT_U08;
			}
			/* T3 */
			else if(FALSE == HaLFEnableRqst_Cnt_T_lgc)
			{
				HaLFTO_State_Cnt_T_u08 = D_HALFSTATEINACTIVE_CNT_U08;
			}
			else
			{
				HaLFTO_State_Cnt_T_u08 = D_HALFSTATEACTIVE_CNT_U08;
			}
			break;
		case D_HALFSTATERECOVERABLE_CNT_U08:
			/* T8 */
			if((TRUE == DiagStsNonRecRmpToZeroFltPres_Cnt_T_lgc) ||
				(TRUE == HaLFIntSystemFltActive_Cnt_T_lgc))
			{
				HaLFTO_State_Cnt_T_u08 = D_HALFSTATEIHIBITED_CNT_U08;
			}
			/* T5 */
			else if((FALSE == HaLFSuspend_T_lgc) &&
				(TRUE == HaLFSlewComplete_Cnt_T_lgc) &&
				(FALSE == HaLFExtSystemFltActive_Cnt_T_lgc) &&
				(FALSE == TOEOLDisable_Cnt_T_lgc) &&
				(FALSE == HaLFEnableRqst_Cnt_T_lgc) )
			{
				HaLFTO_State_Cnt_T_u08 = D_HALFSTATEINACTIVE_CNT_U08;
			}
			else
			{
				HaLFTO_State_Cnt_T_u08 = D_HALFSTATERECOVERABLE_CNT_U08;
			}
			break;
		case D_HALFSTATEIHIBITED_CNT_U08:
			HaLFTO_State_Cnt_T_u08 = D_HALFSTATEIHIBITED_CNT_U08;
			break;
		default:
			HaLFTO_State_Cnt_T_u08 = D_HALFSTATEIHIBITED_CNT_U08;
			break;
	}
	
	/* Transitions Complete */
	
		if(HaLFTO_State_Cnt_M_u08 != HaLFTO_State_Cnt_T_u08)
	{
		(void)Rte_Call_HaLFState_SCom_Transition(HaLFTO_State_Cnt_T_u08);
		HaLFTO_State_Cnt_M_u08 = HaLFTO_State_Cnt_T_u08;
	}
	
	if(D_HALFSTATEACTIVE_CNT_U08 == HaLFTO_State_Cnt_M_u08)
	{
		Rte_IWrite_HaLFTO_Per1_HaLFActive_Cnt_lgc(TRUE);
	}
	else
	{
		Rte_IWrite_HaLFTO_Per1_HaLFActive_Cnt_lgc(FALSE);
	}
	
	Rte_IWrite_HaLFTO_Per1_HaLFState_Cnt_u08(HaLFTO_State_Cnt_M_u08);
	Rte_IWrite_HaLFTO_Per1_HaLFSuspend_Cnt_lgc(HaLFSuspend_T_lgc);
	
	/* Configurable End of Runnable Checkpoint */
	Rte_Call_HaLFTO_Per1_CP1_CheckpointReached();
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define RTE_STOP_SEC_AP_HALFTO_APPL_CODE
#include "MemMap.h"/* PRQA S 5087 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/******************************************************************************
  * Name:        HwTrqVehSpdRevGearCheck
  * Description: Common Activate/Deactivate HwTrq, VehSpd and RevGear diagnostic. Threshold CALs are not common
  * Inputs:      HwTrqTime, HwTrqTimerPtr, MaxHwTrq, VehSpdTime, VehSpdTimerPtr, MinVehSpd, MaxVehSpd, RevGearChkTime, RevGearTimerPtr
  * Outputs:     HaLFDiagStatus_Cnt_T_enum (status of incorrect activation OR deactivation diagnostic)
  ****************************************************************************/
STATIC INLINE FUNC(NxtrDiagMgrStatus, RTE_AP_HALFTO_APPL_CODE) HwTrqVehSpdRevGearCheck( VAR(uint16,  AUTOMATIC) HwTrqTime_mS_T_u16,
																	    CONSTP2VAR(uint32,  AUTOMATIC, AP_HALFTO_CONST) HwTrqTimerPtr_mS_T_u32,
														   	   	   	   	   	   VAR(float32, AUTOMATIC) MaxHwTrq_HwNm_T_f32,
														   	   	   	   	   	   VAR(uint16,  AUTOMATIC) VehSpdTime_mS_T_u16,
														   	   	   	   	CONSTP2VAR(uint32,  AUTOMATIC, AP_HALFTO_CONST) VehSpdTimerPtr_mS_T_u32,
														   	   	   	   	   	   VAR(float32, AUTOMATIC) MinVehSpd_Kph_T_f32,
														   	   	   	   	   	   VAR(float32, AUTOMATIC) MaxVehSpd_Kph_T_f32,
														   	   	   	   	   	   VAR(uint16,  AUTOMATIC) RevGearChkTime_mS_T_u16,
														   	   	   	   	CONSTP2VAR(uint32,  AUTOMATIC, AP_HALFTO_CONST) RevGearTimerPtr_mS_T_u32)
{
	VAR(boolean, AUTOMATIC) HaLFEnableRqst_Cnt_T_lgc;
	VAR(float32, AUTOMATIC) HwTorque_HwNm_T_f32;
	VAR(boolean, AUTOMATIC) HaLFTrqOvReverseGearEngage_Cnt_T_lgc;
	VAR(float32, AUTOMATIC) VehicleSpeed_Kph_T_f32;
	VAR(uint16,  AUTOMATIC) ElapsedTime_mS_T_u16;
	VAR(NxtrDiagMgrStatus,  AUTOMATIC) HaLFDiagStatus_Cnt_T_enum;

	HaLFEnableRqst_Cnt_T_lgc = Rte_IRead_HaLFTO_Per1_HaLFEnableRqst_Cnt_lgc();
	HwTorque_HwNm_T_f32 = Rte_IRead_HaLFTO_Per1_HwTorque_HwNm_f32();
	HaLFTrqOvReverseGearEngage_Cnt_T_lgc = Rte_IRead_HaLFTO_Per1_HaLFTrqOvReverseGearEngage_Cnt_lgc();
	VehicleSpeed_Kph_T_f32 = Rte_IRead_HaLFTO_Per1_VehicleSpeed_Kph_f32();

	HaLFDiagStatus_Cnt_T_enum = NTC_STATUS_PASSED;

	/* Hw Trq Check */

	if((Abs_f32_m(HwTorque_HwNm_T_f32) > MaxHwTrq_HwNm_T_f32) && (TRUE == HaLFEnableRqst_Cnt_T_lgc))
	{
		(void)Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(*HwTrqTimerPtr_mS_T_u32, &ElapsedTime_mS_T_u16);

		if(ElapsedTime_mS_T_u16 >= HwTrqTime_mS_T_u16)
		{
			HaLFDiagStatus_Cnt_T_enum = NTC_STATUS_FAILED;
		}
	}
	else
	{
		(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(HwTrqTimerPtr_mS_T_u32);
	}

	/* Vehicle Speed Check */

	if((TRUE == HaLFEnableRqst_Cnt_T_lgc) &&
		((VehicleSpeed_Kph_T_f32 < MinVehSpd_Kph_T_f32) || (VehicleSpeed_Kph_T_f32 > MaxVehSpd_Kph_T_f32)))
	{
		(void)Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(*VehSpdTimerPtr_mS_T_u32, &ElapsedTime_mS_T_u16);

		if(ElapsedTime_mS_T_u16 >= VehSpdTime_mS_T_u16)
		{
			HaLFDiagStatus_Cnt_T_enum = NTC_STATUS_FAILED;
		}
	}
	else
	{
		(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(VehSpdTimerPtr_mS_T_u32);
	}

	/* Reverse Gear Check */

	if((TRUE == HaLFEnableRqst_Cnt_T_lgc) && (TRUE == HaLFTrqOvReverseGearEngage_Cnt_T_lgc))
	{
		(void)Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(*RevGearTimerPtr_mS_T_u32, &ElapsedTime_mS_T_u16);

		if(ElapsedTime_mS_T_u16 >= RevGearChkTime_mS_T_u16)
		{
			HaLFDiagStatus_Cnt_T_enum = NTC_STATUS_FAILED;
		}
	}
	else
	{
		(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(RevGearTimerPtr_mS_T_u32);
	}

	return (HaLFDiagStatus_Cnt_T_enum);

}
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
