/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Ap_PAwTO.c
 *     Workspace:  C:/CMSynergy/PAwTO/autosar
 *     SW-C Type:  Ap_PAwTO
 *  Generated at:  Tue Oct 22 12:51:49 2013
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nexteer  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  C-Code implementation template for SW-C <Ap_PAwTO>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/* Version Control:
 * Date Created:      Fri Nov  2 08:59:37 2012
 * %version:          10 %
 * %derived_by:       bz1q07 %
 * %date_modified:    Thu Feb  6 12:54:12 2014 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author    Change Description                                                           SCR #
 * --------  -------  --------  ---------------------------------------------------------------------------  ----------
 * 10/31/12  1        BWL       Initial Version (FDD 40B v002)                                               6602
 * 03/21/13  2        MRS       Anomaly 4434, 4534
 * 04/12/13  3        Srikanth  Anomaly fixes 4767,4768,4777												 7868
 * 04/18/13  4        MRS       Anomalies 4815, 4816                                                         7635,7636
 * 05/08/13  5        BDO       Update to FDD 40B v004														 8230
 * 06/20/13  6		  SP		Update to ES 40B v005														 8633
 * 07/03/13  7        SP		Update to SF 08A v001														 8737
 * 07/10/13  8        MR        Added logic to pass the NTCs if the enable criteria is FALSE.                9799
 * 10/22/13  9        MR        Changed GetNTCFailed to GetNTCActive macro.									 10567
 * 02/06/14  10       VT		Update to FDD SF-08A v004													 11366
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

#include "Rte_Ap_PAwTO.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "Ap_PAwTO_Cfg.h"

#include "GlobalMacro.h"
#include "fixmath.h"
#include "filters.h"
#include "CalConstants.h"
#include "float.h"


#define D_PASTATEINACTIVE_CNT_U08		((uint8)0U)
#define D_PASTATEACTIVE_CNT_U08			((uint8)1U)
#define D_PASTATEINHIBITED_CNT_U08		((uint8)2U)
#define D_PASTATERECOVERABLE_CNT_U08	((uint8)3U)

#define D_STDSTIL_CNT_U08				((uint8)0U)
#define D_FORWARD_CNT_U08				((uint8)1U)
#define D_BACKWRD_CNT_U08				((uint8)2U)
/* In FDD also known as SNA (Signal Not Availlable)*/
#define D_INVALID_CNT_U08				((uint8)3U)

#define D_MANOEUVREPAHSEBKWD_CNT_U08	((uint8)0U)
#define D_MANOEUVREPAHSEFWD_CNT_U08		((uint8)1U)


#define D_PARVSGEARMASK_CNT_U08			((uint8)0x01U)
#define D_PATRQOVNOTZEROMASK_CNT_U08	((uint8)0x02U)
#define D_PAVSPDNOTLOW_CNT_U08			((uint8)0x04U)

#define PAWTO_START_SEC_CONST_8
#include "MemMap.h" /* PRQA S 5087 */
STATIC CONST(uint8, AP_PAWTO_CONST) T2_IWSSCOMPSPIN_CNT_U08[D_INVALID_CNT_U08 + D_ONE_CNT_U8][D_INVALID_CNT_U08 + D_ONE_CNT_U8] =
{
	{D_STDSTIL_CNT_U08, D_FORWARD_CNT_U08, D_BACKWRD_CNT_U08, D_STDSTIL_CNT_U08},
	{D_FORWARD_CNT_U08, D_FORWARD_CNT_U08, D_FORWARD_CNT_U08, D_FORWARD_CNT_U08},
	{D_BACKWRD_CNT_U08, D_FORWARD_CNT_U08, D_BACKWRD_CNT_U08, D_BACKWRD_CNT_U08},
	{D_STDSTIL_CNT_U08, D_FORWARD_CNT_U08, D_BACKWRD_CNT_U08, D_INVALID_CNT_U08}
};
#define PAWTO_STOP_SEC_CONST_8
#include "MemMap.h" /* PRQA S 5087 */


#define PAWTO_START_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(boolean, AP_PAWTO_VAR) PAwTO_VSpdActvnMet_Cnt_M_lgc;
#define PAWTO_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h" /* PRQA S 5087 */


#define PAWTO_START_SEC_VAR_CLEARED_8
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(uint8,   AP_PAWTO_VAR) PAwTO_PrkAssistState_Cnt_M_u08;
STATIC VAR(uint8,   AP_PAWTO_VAR) PAwTO_IWSSComputedSpin_Cnt_M_u08;
#define PAWTO_STOP_SEC_VAR_CLEARED_8
#include "MemMap.h" /* PRQA S 5087 */


#define PAWTO_START_SEC_VAR_NOINIT_32
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(sint32,  AP_PAWTO_VAR) PAwTO_HandsOnHwTrqSV_HwNm_M_s4p27;
STATIC VAR(uint32,  AP_PAWTO_VAR) PAwTO_BoostCurveSwitchTimer_mS_M_u32;
STATIC VAR(uint32,  AP_PAWTO_VAR) PAwTO_LimitPercentFilteredTimer_mS_M_u32;
STATIC VAR(uint32,  AP_PAWTO_VAR) PAwTO_RvsGearTimer_mS_M_u32;
STATIC VAR(uint32,  AP_PAWTO_VAR) PAwTO_TrqOvRqNotZeroTimer_mS_M_u32;
STATIC VAR(uint32,  AP_PAWTO_VAR) PAwTO_VehSpdNotLowTimer_mS_M_u32;
STATIC VAR(uint32,  AP_PAWTO_VAR) PAwTO_IWSSWhlSpinTimer_mS_M_u32;
STATIC VAR(uint32,  AP_PAWTO_VAR) PAwTO_IWSSWhlSpinClrTimer_mS_M_u32;
STATIC VAR(uint32,  AP_PAWTO_VAR) PAwTO_ExcessVehSpdTimer_mS_M_u32;
STATIC VAR(uint32,  AP_PAWTO_VAR) PAwTO_ExcessVehSpdClrTimer_mS_M_u32;
STATIC VAR(uint32,  AP_PAWTO_VAR) PAwTO_MovMismatchTimer_mS_M_u32;
STATIC VAR(uint32,  AP_PAWTO_VAR) PAwTO_MovMismatchClrTimer_mS_M_u32;
STATIC VAR(uint32,  AP_PAWTO_VAR) PAwTO_VehicleSpeedMismatchTimer_mS_M_u32;
#define PAWTO_STOP_SEC_VAR_NOINIT_32
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
 *   NTC_Num_CurrentSensorCalOutOfRange (9u)
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
 *   NTC_Num_HWACrossChecks (108u)
 *   NTC_Num_HWASnsrCommFault (109u)
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
 *   NTC_Num_TurnCntr_PosLossNotSpdDep (134u)
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
 *   NTC_Num_BattTransOverVolt (182u)
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
 *   NTC_Num_DataOther2FltMsg_M (295u)
 *   NTC_Num_InvalidMsg_N (296u)
 *   NTC_Num_MissingMsg_N (297u)
 *   NTC_Num_CRCFltMsg_N (298u)
 *   NTC_Num_PgrsCntFltMsg_N (299u)
 *   NTC_Num_DataRngFltMsg_N (300u)
 *   NTC_Num_DataRateFltMsg_N (301u)
 *   NTC_Num_DataOtherFltMsg_N (302u)
 *   NTC_Num_DataOtherFlt2Msg_N (303u)
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
 *   NTC_Num_DataOtherFlt2Msg_R (335u)
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
 *   NTC_Num_DSTXORActive (399u)
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
 *   NTC_Num_InvalidMsg_AI (466u)
 *   NTC_Num_MissingMsg_AI (467u)
 *   NTC_Num_MissingMsg_AJ (473u)
 *   NTC_Num_MissingMsg_AK (481u)
 *   NTC_Num_MissingMsg_AL (489u)
 *   NTC_Num_SysConsistencyVerf (496u)
 *   NTC_Num_ConfigMisMatch (497u)
 *   NTC_Num_CalNotPrgmd (498u)
 *   NTC_Num_TunSetNotPrgmd (499u)
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
 * UInt8: D_ONE_CNT_U8 = 1u
 * UInt8: D_ZERO_CNT_U8 = 0u
 *
 *********************************************************************************************************************/


#define RTE_START_SEC_AP_PAWTO_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: PAwTO_Init1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Implicit S/R API:
 *   -----------------
 *   Float Rte_IRead_PAwTO_Init1_HwTorque_HwNm_f32(void)
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
 *   Std_ReturnType Rte_Call_PrkAssistState_SCom_Transition(UInt8 State_Cnt_T_u08)
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

FUNC(void, RTE_AP_PAWTO_APPL_CODE) PAwTO_Init1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: PAwTO_Init1
 *********************************************************************************************************************/
	
	
	VAR(float32, AUTOMATIC) HwTorque_HwNm_T_f32;
	VAR(uint32, AUTOMATIC) Time_mS_T_u32;
	
	
	HwTorque_HwNm_T_f32 = Rte_IRead_PAwTO_Init1_HwTorque_HwNm_f32();
	
	PAwTO_HandsOnHwTrqSV_HwNm_M_s4p27 = FPM_FloatToFixed_m(HwTorque_HwNm_T_f32, s4p27_T);
	
	
	(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&Time_mS_T_u32);
	PAwTO_BoostCurveSwitchTimer_mS_M_u32 = Time_mS_T_u32;
	PAwTO_LimitPercentFilteredTimer_mS_M_u32 = Time_mS_T_u32;
	PAwTO_RvsGearTimer_mS_M_u32 = Time_mS_T_u32;
	PAwTO_TrqOvRqNotZeroTimer_mS_M_u32 = Time_mS_T_u32;
	PAwTO_VehSpdNotLowTimer_mS_M_u32 = Time_mS_T_u32;
	PAwTO_IWSSWhlSpinTimer_mS_M_u32 = Time_mS_T_u32;
	PAwTO_IWSSWhlSpinClrTimer_mS_M_u32 = Time_mS_T_u32;
	PAwTO_ExcessVehSpdTimer_mS_M_u32 = Time_mS_T_u32;
	PAwTO_ExcessVehSpdClrTimer_mS_M_u32 = Time_mS_T_u32;
	PAwTO_MovMismatchTimer_mS_M_u32 = Time_mS_T_u32;
	PAwTO_MovMismatchClrTimer_mS_M_u32 = Time_mS_T_u32;
	PAwTO_VehicleSpeedMismatchTimer_mS_M_u32 = Time_mS_T_u32;
	
	
	(void)Rte_Call_PrkAssistState_SCom_Transition(D_PASTATEINACTIVE_CNT_U08);
	
	
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: PAwTO_Per1
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
 *   Boolean Rte_IRead_PAwTO_Per1_DiagStsNonRecRmpToZeroFltPres_Cnt_lgc(void)
 *   Boolean Rte_IRead_PAwTO_Per1_DiagStsRecRmpToZeroFltPres_Cnt_lgc(void)
 *   Float Rte_IRead_PAwTO_Per1_HwTorque_HwNm_f32(void)
 *   Float Rte_IRead_PAwTO_Per1_LimitPercentFiltered_Uls_f32(void)
 *   Boolean Rte_IRead_PAwTO_Per1_PAEnableRqst_Cnt_lgc(void)
 *   Boolean Rte_IRead_PAwTO_Per1_PAErrInterfaceActive_Cnt_lgc(void)
 *   Boolean Rte_IRead_PAwTO_Per1_PAExtSystemFltActive_Cnt_lgc(void)
 *   Boolean Rte_IRead_PAwTO_Per1_PAIntSystemFltActive_Cnt_lgc(void)
 *   Boolean Rte_IRead_PAwTO_Per1_PAWheelCriteriaMet_Cnt_lgc(void)
 *   Boolean Rte_IRead_PAwTO_Per1_PrkAsstFuncPresent_Cnt_lgc(void)
 *   Boolean Rte_IRead_PAwTO_Per1_PrkAsstSlewComplete_Cnt_lgc(void)
 *   Boolean Rte_IRead_PAwTO_Per1_TOEOLDisable_Cnt_lgc(void)
 *   Boolean Rte_IRead_PAwTO_Per1_TrqOvReverseGearEngage_Cnt_lgc(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_PAwTO_Per1_HandsOnDetect_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_PAwTO_Per1_HandsOnDetect_Cnt_lgc(void)
 *   void Rte_IWrite_PAwTO_Per1_PABoostCurveSwitch_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_PAwTO_Per1_PABoostCurveSwitch_Cnt_lgc(void)
 *   void Rte_IWrite_PAwTO_Per1_PrkAssistActive_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_PAwTO_Per1_PrkAssistActive_Cnt_lgc(void)
 *   void Rte_IWrite_PAwTO_Per1_PrkAssistState_Cnt_u08(UInt8 data)
 *   UInt8 *Rte_IWriteRef_PAwTO_Per1_PrkAssistState_Cnt_u08(void)
 *   void Rte_IWrite_PAwTO_Per1_PrkAssistSuspend_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_PAwTO_Per1_PrkAssistSuspend_Cnt_lgc(void)
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
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_GetNTCActive(NTCNumber NTC_Cnt_T_enum, Boolean *NTCActive_Ptr_T_lgc)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *   Std_ReturnType Rte_Call_PrkAssistState_SCom_Transition(UInt8 State_Cnt_T_u08)
 *     Synchronous Server Invocation. Timeout: None
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

FUNC(void, RTE_AP_PAWTO_APPL_CODE) PAwTO_Per1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: PAwTO_Per1
 *********************************************************************************************************************/
	
	
	VAR(boolean, AUTOMATIC) DiagStsNonRecRmpToZeroFltPres_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) DiagStsRecRmpToZeroFltPres_Cnt_T_lgc;
	VAR(float32, AUTOMATIC) HwTorque_HwNm_T_f32;
	VAR(float32, AUTOMATIC) LimitPercentFiltered_Uls_T_f32;
	VAR(boolean, AUTOMATIC) PAEnableRqst_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) PAErrInterfaceActive_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) PAExtSystemFltActive_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) PAIntSystemFltActive_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) PAWheelCriteriaMet_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) PrkAsstFuncPresent_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) PrkAsstSlewComplete_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) TrqOvReverseGearEngage_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) VSpdActvnMet_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) NTCLowBattVtg_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) NTCPAVspdMismatch_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) NTCPAIWSSVspdValidity_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) NTCPAExcessVspd_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) NTCPARationalityChk_Cnt_T_lgc;
	
	VAR(boolean, AUTOMATIC) ParkAsstActvnFailed_Cnt_T_lgc;
	
	VAR(sint16,  AUTOMATIC) HwTorque_HwNm_T_s4p11;
	VAR(uint16,  AUTOMATIC) ElapsedTime_mS_T_u16;
	VAR(uint8,   AUTOMATIC) PrkAssistState_Cnt_T_u08;
	
	VAR(boolean, AUTOMATIC) HandsOnDetect_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) PABoostCurveSwitch_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) PrkAssistActive_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) PrkAssistSuspend_Cnt_T_lgc;
	
	VAR(boolean, AUTOMATIC) TOEOLDisable_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) NTCTireCircmInvalid_Cnt_T_lgc;

	
	/* Configurable Start of Runnable Checkpoint */
	Rte_Call_PAwTO_Per1_CP0_CheckpointReached();
	
	DiagStsNonRecRmpToZeroFltPres_Cnt_T_lgc = Rte_IRead_PAwTO_Per1_DiagStsNonRecRmpToZeroFltPres_Cnt_lgc();
	DiagStsRecRmpToZeroFltPres_Cnt_T_lgc = Rte_IRead_PAwTO_Per1_DiagStsRecRmpToZeroFltPres_Cnt_lgc();
	HwTorque_HwNm_T_f32 = Rte_IRead_PAwTO_Per1_HwTorque_HwNm_f32();
	LimitPercentFiltered_Uls_T_f32 = Rte_IRead_PAwTO_Per1_LimitPercentFiltered_Uls_f32();
	PAEnableRqst_Cnt_T_lgc = Rte_IRead_PAwTO_Per1_PAEnableRqst_Cnt_lgc();
	PAErrInterfaceActive_Cnt_T_lgc = Rte_IRead_PAwTO_Per1_PAErrInterfaceActive_Cnt_lgc();
	PAExtSystemFltActive_Cnt_T_lgc = Rte_IRead_PAwTO_Per1_PAExtSystemFltActive_Cnt_lgc();
	PAIntSystemFltActive_Cnt_T_lgc = Rte_IRead_PAwTO_Per1_PAIntSystemFltActive_Cnt_lgc();
	PAWheelCriteriaMet_Cnt_T_lgc = Rte_IRead_PAwTO_Per1_PAWheelCriteriaMet_Cnt_lgc();
	PrkAsstFuncPresent_Cnt_T_lgc = Rte_IRead_PAwTO_Per1_PrkAsstFuncPresent_Cnt_lgc();
	PrkAsstSlewComplete_Cnt_T_lgc = Rte_IRead_PAwTO_Per1_PrkAsstSlewComplete_Cnt_lgc();
	TrqOvReverseGearEngage_Cnt_T_lgc = Rte_IRead_PAwTO_Per1_TrqOvReverseGearEngage_Cnt_lgc();
	TOEOLDisable_Cnt_T_lgc = Rte_IRead_PAwTO_Per1_TOEOLDisable_Cnt_lgc();
	VSpdActvnMet_Cnt_T_lgc = PAwTO_VSpdActvnMet_Cnt_M_lgc;
	
	(void)Rte_Call_NxtrDiagMgr_GetNTCActive(NTC_Num_ExVoltageLow, &NTCLowBattVtg_Cnt_T_lgc);
	(void)Rte_Call_NxtrDiagMgr_GetNTCActive(NTC_Num_VLF_02, &ParkAsstActvnFailed_Cnt_T_lgc);
	(void)Rte_Call_NxtrDiagMgr_GetNTCActive(NTC_Num_VLF_08, &NTCPAVspdMismatch_Cnt_T_lgc);
	(void)Rte_Call_NxtrDiagMgr_GetNTCActive(NTC_Num_VLF_05, &NTCPAIWSSVspdValidity_Cnt_T_lgc);
	(void)Rte_Call_NxtrDiagMgr_GetNTCActive(NTC_Num_VLF_06, &NTCPAExcessVspd_Cnt_T_lgc);
	(void)Rte_Call_NxtrDiagMgr_GetNTCActive(NTC_Num_VLF_07, &NTCPARationalityChk_Cnt_T_lgc);
	(void)Rte_Call_NxtrDiagMgr_GetNTCActive(NTC_Num_InvalidMsg_W, &NTCTireCircmInvalid_Cnt_T_lgc);
	
	
	/*** Hands On Detection ***/
	
	HwTorque_HwNm_T_s4p11 = FPM_FloatToFixed_m(HwTorque_HwNm_T_f32, s4p11_T);
	
	PAwTO_HandsOnHwTrqSV_HwNm_M_s4p27 = LPF_SvUpdate_s16InFixKTrunc_m(HwTorque_HwNm_T_s4p11,
																PAwTO_HandsOnHwTrqSV_HwNm_M_s4p27,
																k_HandsOnLPFKn_Cnt_u16);
	
	if( Abs_s32_m(PAwTO_HandsOnHwTrqSV_HwNm_M_s4p27) > k_TrqOverlayHandsOnTrq_HwNm_u5p27 )
	{
		HandsOnDetect_Cnt_T_lgc = TRUE;
	}
	else
	{
		HandsOnDetect_Cnt_T_lgc = FALSE;
	}
	
	
	
	/*** Park Assist Torque Overlay Enable ***/
	
	/** Process for PrkAssist_Activate Flag **/
	
	if( (Rte_Mode_SystemState_Mode() == RTE_MODE_StaMd_Mode_OPERATE) &&
		(VSpdActvnMet_Cnt_T_lgc == TRUE) &&
		(TrqOvReverseGearEngage_Cnt_T_lgc == TRUE) &&
		(PAWheelCriteriaMet_Cnt_T_lgc == TRUE) )
	{
		PrkAssistActive_Cnt_T_lgc = TRUE;
	}
	else
	{
		PrkAssistActive_Cnt_T_lgc = FALSE;
	}
	
	
	/** Process PA_BoostCurv_Switch Output **/
	
	if( (PAEnableRqst_Cnt_T_lgc == TRUE) &&
		(PrkAssistActive_Cnt_T_lgc == TRUE) )
	{
		(void)Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(PAwTO_BoostCurveSwitchTimer_mS_M_u32, &ElapsedTime_mS_T_u16);
		
		if( ElapsedTime_mS_T_u16 >= k_PABoostCurveTime_mS_u16 )
		{
			PABoostCurveSwitch_Cnt_T_lgc = TRUE;
		}
		else
		{
			PABoostCurveSwitch_Cnt_T_lgc = FALSE;
		}
	}
	else
	{
		(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&PAwTO_BoostCurveSwitchTimer_mS_M_u32);
		PABoostCurveSwitch_Cnt_T_lgc = FALSE;
	}
	
	
	/** Processing for PrkAssist_Suspend Flag **/
	
	if( LimitPercentFiltered_Uls_T_f32 <= k_TrqOverlayLimitPerc_Uls_f32 )
	{
		(void)Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(PAwTO_LimitPercentFilteredTimer_mS_M_u32, &ElapsedTime_mS_T_u16);

		if( (PAErrInterfaceActive_Cnt_T_lgc == TRUE) ||
			(ElapsedTime_mS_T_u16 < k_TrqOverlaySuspendTime_mS_u16) ||
			(NTCLowBattVtg_Cnt_T_lgc == TRUE) ||
			(DiagStsRecRmpToZeroFltPres_Cnt_T_lgc == TRUE) ||
			(DiagStsNonRecRmpToZeroFltPres_Cnt_T_lgc == TRUE) ||
			(NTCPAIWSSVspdValidity_Cnt_T_lgc == TRUE) ||
			(NTCPAExcessVspd_Cnt_T_lgc == TRUE) ||
			(NTCPARationalityChk_Cnt_T_lgc == TRUE) ||
			(NTCTireCircmInvalid_Cnt_T_lgc == TRUE) )
		{
			PrkAssistSuspend_Cnt_T_lgc = TRUE;
		}
		else
		{
			PrkAssistSuspend_Cnt_T_lgc = FALSE;
		}
	}
	else
	{
		(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&PAwTO_LimitPercentFilteredTimer_mS_M_u32);
		PrkAssistSuspend_Cnt_T_lgc = TRUE;
	}
	
	
	/** PrkAssist_State **/
	
	switch(PAwTO_PrkAssistState_Cnt_M_u08)
	{
		case D_PASTATEINACTIVE_CNT_U08:
			/* T7 */
			if( (DiagStsNonRecRmpToZeroFltPres_Cnt_T_lgc == TRUE) ||
				(PAIntSystemFltActive_Cnt_T_lgc == TRUE) ||
				(ParkAsstActvnFailed_Cnt_T_lgc == TRUE) )
			{
				PrkAssistState_Cnt_T_u08 = D_PASTATEINHIBITED_CNT_U08;
			}
			/* T6 */
			else if( (PrkAssistSuspend_Cnt_T_lgc == TRUE ) ||
					 (TOEOLDisable_Cnt_T_lgc == TRUE) ||
					 (PAExtSystemFltActive_Cnt_T_lgc == TRUE) )
			{
				PrkAssistState_Cnt_T_u08 = D_PASTATERECOVERABLE_CNT_U08;
			}
			/* T1 */
			else if( (PAEnableRqst_Cnt_T_lgc == TRUE) &&
					 (PrkAssistActive_Cnt_T_lgc == TRUE) &&
					 (PrkAsstFuncPresent_Cnt_T_lgc == TRUE) &&
					 (PrkAsstSlewComplete_Cnt_T_lgc == TRUE) )
			{
				PrkAssistState_Cnt_T_u08 = D_PASTATEACTIVE_CNT_U08;
			}
			else
			{
				PrkAssistState_Cnt_T_u08 = D_PASTATEINACTIVE_CNT_U08;
			}
			break;
		
		case D_PASTATEACTIVE_CNT_U08:
			/* T2 */
			if( (DiagStsNonRecRmpToZeroFltPres_Cnt_T_lgc == TRUE) ||
				(PAIntSystemFltActive_Cnt_T_lgc == TRUE) ||
				(NTCPAVspdMismatch_Cnt_T_lgc == TRUE) )
			{
				PrkAssistState_Cnt_T_u08 = D_PASTATEINHIBITED_CNT_U08;
			}
			/* T4 */
			else if( (PrkAssistSuspend_Cnt_T_lgc == TRUE) ||
					 (PAExtSystemFltActive_Cnt_T_lgc == TRUE) )
			{
				PrkAssistState_Cnt_T_u08 = D_PASTATERECOVERABLE_CNT_U08;
			}
			/* T3 */
			else if( PAEnableRqst_Cnt_T_lgc == FALSE )
			{
				PrkAssistState_Cnt_T_u08 = D_PASTATEINACTIVE_CNT_U08;
			}
			else
			{
				PrkAssistState_Cnt_T_u08 = D_PASTATEACTIVE_CNT_U08;
			}
			break;
		
		case D_PASTATERECOVERABLE_CNT_U08:
			/* T8 */
			if( (DiagStsNonRecRmpToZeroFltPres_Cnt_T_lgc == TRUE) ||
				(PAIntSystemFltActive_Cnt_T_lgc == TRUE) )
			{
				PrkAssistState_Cnt_T_u08 = D_PASTATEINHIBITED_CNT_U08;
			}
			/* T5 */
			else if( (PrkAssistSuspend_Cnt_T_lgc == FALSE) &&
					 (PrkAsstSlewComplete_Cnt_T_lgc == TRUE) &&
					 (TOEOLDisable_Cnt_T_lgc == FALSE) &&
					 (PAExtSystemFltActive_Cnt_T_lgc == FALSE) &&
					 (PAEnableRqst_Cnt_T_lgc == FALSE) )
			{
				PrkAssistState_Cnt_T_u08 = D_PASTATEINACTIVE_CNT_U08;
			}
			else
			{
				PrkAssistState_Cnt_T_u08 = D_PASTATERECOVERABLE_CNT_U08;
			}
			break;
		
		case D_PASTATEINHIBITED_CNT_U08:
		default:
			PrkAssistState_Cnt_T_u08 = D_PASTATEINHIBITED_CNT_U08;
			break;
	}
	
	/* Transition Complete */
	
	if( PrkAssistState_Cnt_T_u08 != PAwTO_PrkAssistState_Cnt_M_u08 )
	{
		(void)Rte_Call_PrkAssistState_SCom_Transition(PrkAssistState_Cnt_T_u08);
	}
	
	
	
	PAwTO_PrkAssistState_Cnt_M_u08 = PrkAssistState_Cnt_T_u08;
	
	Rte_IWrite_PAwTO_Per1_HandsOnDetect_Cnt_lgc(HandsOnDetect_Cnt_T_lgc);
	Rte_IWrite_PAwTO_Per1_PABoostCurveSwitch_Cnt_lgc(PABoostCurveSwitch_Cnt_T_lgc);
	Rte_IWrite_PAwTO_Per1_PrkAssistActive_Cnt_lgc(PrkAssistActive_Cnt_T_lgc);
	Rte_IWrite_PAwTO_Per1_PrkAssistState_Cnt_u08(PrkAssistState_Cnt_T_u08);
	Rte_IWrite_PAwTO_Per1_PrkAssistSuspend_Cnt_lgc(PrkAssistSuspend_Cnt_T_lgc);
	
	
	/* Configurable End of Runnable Checkpoint */
	Rte_Call_PAwTO_Per1_CP1_CheckpointReached();
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: PAwTO_Per2
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
 *   Float Rte_IRead_PAwTO_Per2_IWSSCalcVspd_Kph_f32(void)
 *   Boolean Rte_IRead_PAwTO_Per2_PAEnableRqst_Cnt_lgc(void)
 *   UInt8 Rte_IRead_PAwTO_Per2_PAManoeuvrePhase_Cnt_u08(void)
 *   Float Rte_IRead_PAwTO_Per2_PATrqOvCmdRqst_HwNm_f32(void)
 *   UInt8 Rte_IRead_PAwTO_Per2_PAWhlDirRLStat_Cnt_u08(void)
 *   UInt8 Rte_IRead_PAwTO_Per2_PAWhlDirRRStat_Cnt_u08(void)
 *   Boolean Rte_IRead_PAwTO_Per2_PAWhlPlsCntRLValid_Cnt_lgc(void)
 *   Boolean Rte_IRead_PAwTO_Per2_PAWhlPlsCntRRValid_Cnt_lgc(void)
 *   Boolean Rte_IRead_PAwTO_Per2_PrkAsstFuncPresent_Cnt_lgc(void)
 *   Boolean Rte_IRead_PAwTO_Per2_TrqOvReverseGearEngage_Cnt_lgc(void)
 *   Float Rte_IRead_PAwTO_Per2_VehicleSpeed_Kph_f32(void)
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
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_GetNTCActive(NTCNumber NTC_Cnt_T_enum, Boolean *NTCActive_Ptr_T_lgc)
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

FUNC(void, RTE_AP_PAWTO_APPL_CODE) PAwTO_Per2(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: PAwTO_Per2
 *********************************************************************************************************************/
	
	
	VAR(float32, AUTOMATIC) IWSSCalcVspd_Kph_T_f32;
	VAR(boolean, AUTOMATIC) PAEnableRqst_Cnt_T_lgc;
	VAR(uint8,   AUTOMATIC) PAManoeuvrePhase_Cnt_u08;
	VAR(float32, AUTOMATIC) PATrqOvCmdRqst_HwNm_T_f32;
	VAR(uint8,   AUTOMATIC) PAWhlDirRLStat_Cnt_T_u08;
	VAR(uint8,   AUTOMATIC) PAWhlDirRRStat_Cnt_T_u08;
	VAR(boolean, AUTOMATIC) PAWhlPlsCntRLValid_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) PAWhlPlsCntRRValid_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) TrqOvReverseGearEngage_Cnt_T_lgc;
	VAR(float32, AUTOMATIC) VehicleSpeed_Kph_T_f32;
	VAR(uint8,   AUTOMATIC) PrkAssistState_Cnt_T_u08;
	VAR(boolean, AUTOMATIC) NTCPAIWSSVspdValidity_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) NTCPAExcessVspd_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) NTCPARationalityChk_Cnt_T_lgc;
	VAR(NxtrDiagMgrStatus, AUTOMATIC) ParkAsstActvnStatus_Cnt_T_enum;
	VAR(uint8, AUTOMATIC) ParkAsstActvnParam_Cnt_T_u08;
	VAR(boolean, AUTOMATIC) PrkAsstFuncPresent_Cnt_T_lgc;
	
	VAR(uint16,  AUTOMATIC) ElapsedTime_mS_T_u16;
	
	
	/* Configurable Start of Runnable Checkpoint */
	Rte_Call_PAwTO_Per2_CP0_CheckpointReached();
	
	IWSSCalcVspd_Kph_T_f32 = Rte_IRead_PAwTO_Per2_IWSSCalcVspd_Kph_f32();
	PAEnableRqst_Cnt_T_lgc = Rte_IRead_PAwTO_Per2_PAEnableRqst_Cnt_lgc();
	PAManoeuvrePhase_Cnt_u08 = Rte_IRead_PAwTO_Per2_PAManoeuvrePhase_Cnt_u08();
	PATrqOvCmdRqst_HwNm_T_f32 = Rte_IRead_PAwTO_Per2_PATrqOvCmdRqst_HwNm_f32();
	PAWhlDirRLStat_Cnt_T_u08 = Rte_IRead_PAwTO_Per2_PAWhlDirRLStat_Cnt_u08();
	PAWhlDirRRStat_Cnt_T_u08 = Rte_IRead_PAwTO_Per2_PAWhlDirRRStat_Cnt_u08();
	PAWhlPlsCntRLValid_Cnt_T_lgc = Rte_IRead_PAwTO_Per2_PAWhlPlsCntRLValid_Cnt_lgc();
	PAWhlPlsCntRRValid_Cnt_T_lgc = Rte_IRead_PAwTO_Per2_PAWhlPlsCntRRValid_Cnt_lgc();
	TrqOvReverseGearEngage_Cnt_T_lgc = Rte_IRead_PAwTO_Per2_TrqOvReverseGearEngage_Cnt_lgc();
	VehicleSpeed_Kph_T_f32 = Rte_IRead_PAwTO_Per2_VehicleSpeed_Kph_f32();
	PrkAssistState_Cnt_T_u08 = PAwTO_PrkAssistState_Cnt_M_u08;
	(void)Rte_Call_NxtrDiagMgr_GetNTCActive(NTC_Num_VLF_05, &NTCPAIWSSVspdValidity_Cnt_T_lgc);
	(void)Rte_Call_NxtrDiagMgr_GetNTCActive(NTC_Num_VLF_06, &NTCPAExcessVspd_Cnt_T_lgc);
	(void)Rte_Call_NxtrDiagMgr_GetNTCActive(NTC_Num_VLF_07, &NTCPARationalityChk_Cnt_T_lgc);
	
	PAWhlDirRLStat_Cnt_T_u08 = Min_m(PAWhlDirRLStat_Cnt_T_u08, D_INVALID_CNT_U08);
	PAWhlDirRRStat_Cnt_T_u08 = Min_m(PAWhlDirRRStat_Cnt_T_u08, D_INVALID_CNT_U08);
	
	PrkAsstFuncPresent_Cnt_T_lgc = Rte_IRead_PAwTO_Per2_PrkAsstFuncPresent_Cnt_lgc();
	
	
	/*** Incorrect Park Assist Activation Diagnostic ***/
	if (PrkAsstFuncPresent_Cnt_T_lgc == TRUE)
	{
		if (PrkAssistState_Cnt_T_u08 == D_PASTATEINACTIVE_CNT_U08)
		{
			
			ParkAsstActvnStatus_Cnt_T_enum = NTC_STATUS_PASSED;
			ParkAsstActvnParam_Cnt_T_u08 = D_ZERO_CNT_U8;
			
			if( (PAEnableRqst_Cnt_T_lgc == TRUE) &&
				(TrqOvReverseGearEngage_Cnt_T_lgc == FALSE) )
			{
				(void)Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(PAwTO_RvsGearTimer_mS_M_u32, &ElapsedTime_mS_T_u16);
				
				if( ElapsedTime_mS_T_u16 >= k_PARvsGearChkTime_mS_u16 )
				{
					ParkAsstActvnStatus_Cnt_T_enum = NTC_STATUS_FAILED;
					ParkAsstActvnParam_Cnt_T_u08 |= D_PARVSGEARMASK_CNT_U08;
				}
			}
			else
			{
				(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&PAwTO_RvsGearTimer_mS_M_u32);
			}
			
			if( (Abs_f32_m(PATrqOvCmdRqst_HwNm_T_f32) > FLT_EPSILON) && 
				(PAEnableRqst_Cnt_T_lgc == FALSE) )
			{
				(void)Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(PAwTO_TrqOvRqNotZeroTimer_mS_M_u32, &ElapsedTime_mS_T_u16);
				
				if( ElapsedTime_mS_T_u16 >= k_PATrqOvNotZeroChkTime_mS_u16 )
				{
					ParkAsstActvnStatus_Cnt_T_enum = NTC_STATUS_FAILED;
					ParkAsstActvnParam_Cnt_T_u08 |= D_PATRQOVNOTZEROMASK_CNT_U08;
				}
			}
			else
			{
				(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&PAwTO_TrqOvRqNotZeroTimer_mS_M_u32);
			}
			
			if( (VehicleSpeed_Kph_T_f32 >= k_PAVSpdNotLowMin_Kph_f32) &&
				(VehicleSpeed_Kph_T_f32 <= k_PAVSpdNotLowMax_Kph_f32) )
			{
				PAwTO_VSpdActvnMet_Cnt_M_lgc = TRUE;
				
				(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&PAwTO_VehSpdNotLowTimer_mS_M_u32);
			}
			else
			{
				PAwTO_VSpdActvnMet_Cnt_M_lgc = FALSE;
				
				if( PAEnableRqst_Cnt_T_lgc == TRUE )
				{
					(void)Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(PAwTO_VehSpdNotLowTimer_mS_M_u32, &ElapsedTime_mS_T_u16);
					
					if( ElapsedTime_mS_T_u16 >= k_PAVehSpdNotLowTime_mS_u16 )
					{
						ParkAsstActvnStatus_Cnt_T_enum = NTC_STATUS_FAILED;
						ParkAsstActvnParam_Cnt_T_u08 |= D_PAVSPDNOTLOW_CNT_U08;
					}
				}
				else
				{
					(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&PAwTO_VehSpdNotLowTimer_mS_M_u32);
				}
			}
			
			/*NTC_Num_VLF_02 is Park Assist Fault */
			(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_VLF_02, ParkAsstActvnParam_Cnt_T_u08, ParkAsstActvnStatus_Cnt_T_enum);
		}
	}
	else
	{
		(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&PAwTO_RvsGearTimer_mS_M_u32);
		(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&PAwTO_TrqOvRqNotZeroTimer_mS_M_u32);
		(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&PAwTO_VehSpdNotLowTimer_mS_M_u32);
		
		/*If the Enable criteria is not met then pass the NTC  - NTC_Num_VLF_02 */		
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_VLF_02, 0x0U, NTC_STATUS_PASSED);
	
	}
	
	
	/*** Park Assist Deactivation Diagnostic ***/
	
	/** IWSS Signal Validity Check and Wheel Spin Signal Processing **/
	if(PrkAsstFuncPresent_Cnt_T_lgc == TRUE)
	{
		if( NTCPAIWSSVspdValidity_Cnt_T_lgc == TRUE )
		{
			(void)Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(PAwTO_IWSSWhlSpinClrTimer_mS_M_u32, &ElapsedTime_mS_T_u16);
			
			if( ElapsedTime_mS_T_u16 >= k_PAIWSSWhlSpinClrTime_mS_u16 )
			{
				/*NTC_Num_VLF_05 is Park Assist IWSS Speed Validity*/
				(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_VLF_05, 0x01U, NTC_STATUS_PASSED);
				(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&PAwTO_IWSSWhlSpinClrTimer_mS_M_u32);
			}
			else
			{
				if( (PAWhlDirRLStat_Cnt_T_u08 == D_INVALID_CNT_U08) ||
					(PAWhlDirRRStat_Cnt_T_u08 == D_INVALID_CNT_U08) ||
					(PAWhlPlsCntRLValid_Cnt_T_lgc == FALSE) ||
					(PAWhlPlsCntRRValid_Cnt_T_lgc == FALSE) )
				{
					/*NTC_Num_VLF_05 is Park Assist IWSS Speed Validity*/
					(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_VLF_05, 0x01U, NTC_STATUS_FAILED);
					(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&PAwTO_IWSSWhlSpinClrTimer_mS_M_u32);
				}
			}
			(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&PAwTO_IWSSWhlSpinTimer_mS_M_u32);
		}
		else
		{
			if( PAEnableRqst_Cnt_T_lgc == TRUE )
			{
				(void)Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(PAwTO_IWSSWhlSpinTimer_mS_M_u32, &ElapsedTime_mS_T_u16);
				
				if( ElapsedTime_mS_T_u16 >= k_PAIWSSWhlSpinSetTime_mS_u16 )
				{
					/*NTC_Num_VLF_05 is Park Assist IWSS Speed Validity*/
					(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_VLF_05, 0x01U, NTC_STATUS_FAILED);
					(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&PAwTO_IWSSWhlSpinTimer_mS_M_u32);
				}
				else
				{
					if( ( (PAWhlDirRLStat_Cnt_T_u08 != D_INVALID_CNT_U08) ||
						  (PAWhlDirRRStat_Cnt_T_u08 != D_INVALID_CNT_U08) ) &&
						( (PAWhlPlsCntRLValid_Cnt_T_lgc == TRUE) &&
						  (PAWhlPlsCntRRValid_Cnt_T_lgc == TRUE) ) )
					{
						/*NTC_Num_VLF_05 is Park Assist IWSS Speed Validity*/
						(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_VLF_05, 0x01U, NTC_STATUS_PASSED);
						(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&PAwTO_IWSSWhlSpinTimer_mS_M_u32);
					}
				}
			}
			(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&PAwTO_IWSSWhlSpinClrTimer_mS_M_u32);
		}
	}
	else
	{
		/*If the Enable criteria is not met then pass the NTC NTC_Num_VLF_05*/
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_VLF_05, 0x0U, NTC_STATUS_PASSED);
		
	}

	/* Calculate IWSS Computed Spin */
	
	if( PAEnableRqst_Cnt_T_lgc == TRUE )
	{
		PAwTO_IWSSComputedSpin_Cnt_M_u08 = T2_IWSSCOMPSPIN_CNT_U08[PAWhlDirRLStat_Cnt_T_u08][PAWhlDirRRStat_Cnt_T_u08];
	}
	
	
	/** Excessive Vehicle Speed Condition **/
	
	if(PrkAsstFuncPresent_Cnt_T_lgc == TRUE)
	{
		if( NTCPAExcessVspd_Cnt_T_lgc == TRUE )
		{
			(void)Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(PAwTO_ExcessVehSpdClrTimer_mS_M_u32, &ElapsedTime_mS_T_u16);
			
			if( ElapsedTime_mS_T_u16 >= k_PAExcessVehSpdClrTime_mS_u16 )
			{
				/*NTC_Num_VLF_06 is Park Assist Excessive Speed*/
				(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_VLF_06, 0x01U, NTC_STATUS_PASSED);
				(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&PAwTO_ExcessVehSpdClrTimer_mS_M_u32);
			}
			else
			{
				if( VehicleSpeed_Kph_T_f32 > k_PAExcessVehSpd_Kph_f32 )
				{
					/*NTC_Num_VLF_06 is Park Assist Excessive Speed*/
					(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_VLF_06, 0x01U, NTC_STATUS_FAILED);
					(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&PAwTO_ExcessVehSpdClrTimer_mS_M_u32);
				}
			}
			(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&PAwTO_ExcessVehSpdTimer_mS_M_u32);
		}
		else
		{
			if( PAEnableRqst_Cnt_T_lgc == TRUE )
			{
				(void)Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(PAwTO_ExcessVehSpdTimer_mS_M_u32, &ElapsedTime_mS_T_u16);
				
				if( ElapsedTime_mS_T_u16 >= k_PAExcessVehSpdSetTime_mS_u16 )
				{
					/*NTC_Num_VLF_06 is Park Assist Excessive Speed*/
					(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_VLF_06, 0x01U, NTC_STATUS_FAILED);
					(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&PAwTO_ExcessVehSpdTimer_mS_M_u32);
				}
				else
				{
					if( VehicleSpeed_Kph_T_f32 <= k_PAExcessVehSpd_Kph_f32 )
					{
						/*NTC_Num_VLF_06 is Park Assist Excessive Speed*/
						(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_VLF_06, 0x01U, NTC_STATUS_PASSED);
						(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&PAwTO_ExcessVehSpdTimer_mS_M_u32);
					}
				}
			}
			else
			{
				(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&PAwTO_ExcessVehSpdTimer_mS_M_u32);
				(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_VLF_06, 0x01U, NTC_STATUS_PASSED);
			}
			(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&PAwTO_ExcessVehSpdClrTimer_mS_M_u32);
		}
	}
	else
	{
		/*If the Enable criteria is not met then pass the NTC  - NTC_Num_VLF_06*/
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_VLF_06, 0x0U, NTC_STATUS_PASSED);
	}
	
	/** Actual Vehicle Longitudinal Movement and  PPPA Computed Movement Mismatch Condition **/
	
	if(PrkAsstFuncPresent_Cnt_T_lgc == TRUE)
	{
		if( NTCPARationalityChk_Cnt_T_lgc == TRUE )
		{
			(void)Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(PAwTO_MovMismatchClrTimer_mS_M_u32, &ElapsedTime_mS_T_u16);
			
			if( ElapsedTime_mS_T_u16 >= k_PAMovMismatchClrTime_mS_u16 )
			{
				/*NTC_Num_VLF_07 is Park Assist Rational Check*/
				(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_VLF_07, 0x01U, NTC_STATUS_PASSED);
				(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&PAwTO_MovMismatchClrTimer_mS_M_u32);
			}
			else
			{
				if( (VehicleSpeed_Kph_T_f32 > k_PAMovMismatchVSpd_Kph_f32) &&
					( ( (PAManoeuvrePhase_Cnt_u08 == D_MANOEUVREPAHSEBKWD_CNT_U08) &&
						( (TrqOvReverseGearEngage_Cnt_T_lgc == FALSE) ||
						  (PAwTO_IWSSComputedSpin_Cnt_M_u08 != D_BACKWRD_CNT_U08) ) ) ||
					  ( (PAManoeuvrePhase_Cnt_u08 == D_MANOEUVREPAHSEFWD_CNT_U08) &&
						( (TrqOvReverseGearEngage_Cnt_T_lgc == TRUE) ||
						  (PAwTO_IWSSComputedSpin_Cnt_M_u08 != D_FORWARD_CNT_U08) ) ) ) )
				{
					/*NTC_Num_VLF_07 is Park Assist Rational Check*/
					(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_VLF_07, 0x01U, NTC_STATUS_FAILED);
					(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&PAwTO_MovMismatchClrTimer_mS_M_u32);
				}
			}
			(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&PAwTO_MovMismatchTimer_mS_M_u32);
		}
		else
		{
			if( PAEnableRqst_Cnt_T_lgc == TRUE )
			{
				(void)Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(PAwTO_MovMismatchTimer_mS_M_u32, &ElapsedTime_mS_T_u16);
				
				if( ElapsedTime_mS_T_u16 >= k_PAMovMismatchSetTime_mS_u16 )
				{
					/*NTC_Num_VLF_07 is Park Assist Rational Check*/
					(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_VLF_07, 0x01U, NTC_STATUS_FAILED);
					(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&PAwTO_MovMismatchTimer_mS_M_u32);
				}
				else
				{
					if( (VehicleSpeed_Kph_T_f32 > k_PAMovMismatchVSpd_Kph_f32) &&
						( ( (PAManoeuvrePhase_Cnt_u08 == D_MANOEUVREPAHSEBKWD_CNT_U08) &&
							( (TrqOvReverseGearEngage_Cnt_T_lgc == FALSE) ||
							  (PAwTO_IWSSComputedSpin_Cnt_M_u08 != D_BACKWRD_CNT_U08) ) ) ||
						  ( (PAManoeuvrePhase_Cnt_u08 == D_MANOEUVREPAHSEFWD_CNT_U08) &&
							( (TrqOvReverseGearEngage_Cnt_T_lgc == TRUE) ||
							  (PAwTO_IWSSComputedSpin_Cnt_M_u08 != D_FORWARD_CNT_U08) ) ) ) )
					{
						/* do nothing */
					}
					else
					{
						/*NTC_Num_VLF_07 is Park Assist Rational Check*/
						(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_VLF_07, 0x01U, NTC_STATUS_PASSED);
						(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&PAwTO_MovMismatchTimer_mS_M_u32);
					}
				}
			}
			else
			{
				(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&PAwTO_MovMismatchTimer_mS_M_u32);
				(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_VLF_07, 0x01U, NTC_STATUS_PASSED);
			}
			(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&PAwTO_MovMismatchClrTimer_mS_M_u32);
		}
	}
	else
	{
		/*If the Enable criteria is not met then pass the NTC NTC_Num_VLF_07*/
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_VLF_07, 0x0U, NTC_STATUS_PASSED);
	}
	
	/** ESC and IWSS Vehicle Speed Signal Mismatch Condition **/
	
	if(PrkAsstFuncPresent_Cnt_T_lgc == TRUE)
	{
		if( PAEnableRqst_Cnt_T_lgc == TRUE )
		{
			if( (VehicleSpeed_Kph_T_f32 < k_PAExcessVehSpd_Kph_f32) &&
				(IWSSCalcVspd_Kph_T_f32 > k_PAEIWSSChkVspd_Kph_f32) )
			{
				(void)Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(PAwTO_VehicleSpeedMismatchTimer_mS_M_u32, &ElapsedTime_mS_T_u16);
				
				if( ElapsedTime_mS_T_u16 >= k_PAVspdMismatchSetTime_mS_u16 )
				{
					/*NTC_Num_VLF_08 is Park Assist Veh Speed Mismatch*/
					(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_VLF_08, 0x01U, NTC_STATUS_FAILED);
					(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&PAwTO_VehicleSpeedMismatchTimer_mS_M_u32);

				}
			}
			else
			{
				/*NTC_Num_VLF_08 is Park Assist Veh Speed Mismatch*/
				(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&PAwTO_VehicleSpeedMismatchTimer_mS_M_u32);
				(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_VLF_08, 0x01U, NTC_STATUS_PASSED);
			}
		}
		else
		{
			(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&PAwTO_VehicleSpeedMismatchTimer_mS_M_u32);
			(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_VLF_08, 0x01U, NTC_STATUS_PASSED);
		}
	}
	else
	{
		/*If the Enable criteria is not met then pass the NTC NTC_Num_VLF_08*/
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_VLF_08, 0x0U, NTC_STATUS_PASSED);
	}

	/* Configurable End of Runnable Checkpoint */
	Rte_Call_PAwTO_Per2_CP1_CheckpointReached();
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define RTE_STOP_SEC_AP_PAWTO_APPL_CODE
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
