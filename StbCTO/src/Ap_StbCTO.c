/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Ap_StbCTO.c
 *     Workspace:  C:/Synergy/working_projects/ESG_Dev_65/StbCTO/StbCTO/autosar
 *     SW-C Type:  Ap_StbCTO
 *  Generated at:  Thu Jan 23 15:19:05 2014
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nexteer  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  C-Code implementation template for SW-C <Ap_StbCTO>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/* Version Control:
 * Date Created:      Tue Nov 15 15:41:24 2011
 * %version:          13 %
 * %derived_by:       bz1q07 %
 * %date_modified:    Thu Jan 23 14:13:35 2014 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 11/26/12  1        NRAR     Initial component FDD 40C ver002                                                 6603
 * 11/26/12  2        NRAR     updated source version
 * 11/27/12  3        NRAR     Ports for DSTState and DSTTrqOvCmdRqst is updated to match with HaLF and FDD     6603
 * 02/23/13  4-5      DD	   Correct anomaly 4476 and 4477 (DST Active and Request Denied cpt) 				7438
 * 02/23/13  6	      DD	   Correct transition ACTIVE==>REQUEST DENIED						 				7473
 * 04/12/13  7        Srikanth Anomaly 4787 - Correction in DST state initialization							7907
 * 05/08/13  8        BDO      Update to FDD 40C v004, v005														8231
 * 05/28/13  9        BDO      UTP updates - StbCTO_DSTSt_Active(), StartAndStopTimer() 						8231
 * 07/09/13  10       SP       Update to CF 08B v001															8738
 * 10/07/13  11       MR       Added logic to pass the NTCs if the enable criteria is FALSE, And added
 *                             AbsDSTTrqOvCmdRqst_HwNm_T_f32 in StbCTO_DSTSt_Ready to fix the QAC Warning       9800
 * 10/22/13   12      MR       Added logic to pass the NTC as per FDD version CF08B Ver4. 					    10569
 * 01/23/14  13       VT       Updated to CF-08B v005															11193
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

#include "Rte_Ap_StbCTO.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "Ap_StbCTO_Cfg.h"
#include "CalConstants.h"
#include "GlobalMacro.h"
#include <float.h>
 

 
#define STBCTO_START_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(boolean, AP_STBCTO_VAR_NOINIT) DSTVspdActive_Cnt_M_lgc;
STATIC VAR(boolean, AP_STBCTO_VAR_NOINIT) DSTBkwdMotionAbsent_Cnt_M_lgc;
STATIC VAR(boolean, AP_STBCTO_VAR_NOINIT) VehExtCondDSTActive_Cnt_M_lgc;
STATIC VAR(boolean, AP_STBCTO_VAR_NOINIT) IntCondDSTEnable_Cnt_M_lgc;
STATIC VAR(boolean, AP_STBCTO_VAR_NOINIT) LoSpdInactive_Cnt_M_lgc;
STATIC VAR(boolean, AP_STBCTO_VAR_NOINIT) HiSpdInactive_Cnt_M_lgc;
STATIC VAR(boolean, AP_STBCTO_VAR_NOINIT) DiagStsNonRecRmpToZeroFltPres_Cnt_M_lgc;
STATIC VAR(boolean, AP_STBCTO_VAR_NOINIT) DiagStsRecRmpToZeroFltPres_Cnt_M_lgc;
STATIC VAR(boolean, AP_STBCTO_VAR_NOINIT) StartTNATimer_Cnt_M_lgc;
STATIC VAR(boolean, AP_STBCTO_VAR_NOINIT) StartRDTimer_Cnt_M_lgc;
STATIC VAR(boolean, AP_STBCTO_VAR_NOINIT) DSTActive_Cnt_M_lgc;
#define STBCTO_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h" /* PRQA S 5087 */

#define STBCTO_START_SEC_VAR_NOINIT_32
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(uint32, AP_STBCTO_VAR_NOINIT) DSTInternalCondTimer_mS_M_u32;
STATIC VAR(uint32, AP_STBCTO_VAR_NOINIT) DSTBkwdMotionTime_mS_M_u32;
#define STBCTO_STOP_SEC_VAR_NOINIT_32
#include "MemMap.h" /* PRQA S 5087 */

#define STBCTO_START_SEC_VAR_CLEARED_32
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(uint32, AP_STBCTO_VAR) DSTRDTimer_M_mS_u32;
STATIC VAR(uint32, AP_STBCTO_VAR) DSTTNATimer_M_mS_u32;
STATIC VAR(uint32, AP_STBCTO_VAR) activeTimer_mS_M_u32;
STATIC VAR(uint32, AP_STBCTO_VAR) InactiveTimer_mS_M_u32;
#define STBCTO_STOP_SEC_VAR_CLEARED_32
#include "MemMap.h" /* PRQA S 5087 */

#define STBCTO_START_SEC_VAR_CLEARED_8
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(uint8, AP_STBCTO_VAR) RDStateCounter_Cnt_M_u08;
#define STBCTO_STOP_SEC_VAR_CLEARED_8
#include "MemMap.h" /* PRQA S 5087 */



/* == PROTOTYPES =============================================== */

STATIC FUNC(void, AP_STBCTO_CODE) StbCTO_DSTSt_NotAvailable(P2VAR(boolean, AUTOMATIC, AUTOMATIC)DSTActive_T_lgc, P2VAR(boolean, AUTOMATIC, AUTOMATIC)DSTSlewStart_T_lgc );
STATIC FUNC(void, AP_STBCTO_CODE) StbCTO_DSTSt_Off(P2VAR(boolean, AUTOMATIC, AUTOMATIC)DSTActive_T_lgc, P2VAR(boolean, AUTOMATIC, AUTOMATIC)DSTSlewStart_T_lgc );
STATIC FUNC(void, AP_STBCTO_CODE) StbCTO_DSTSt_TNA(P2VAR(boolean, AUTOMATIC, AUTOMATIC)DSTActive_T_lgc, P2VAR(boolean, AUTOMATIC, AUTOMATIC)DSTSlewStart_T_lgc );
STATIC FUNC(void, AP_STBCTO_CODE) StbCTO_DSTSt_PNA(P2VAR(boolean, AUTOMATIC, AUTOMATIC)DSTActive_T_lgc, P2VAR(boolean, AUTOMATIC, AUTOMATIC)DSTSlewStart_T_lgc );
STATIC FUNC(void, AP_STBCTO_CODE) StbCTO_DSTSt_Ready(P2VAR(boolean, AUTOMATIC, AUTOMATIC)DSTActive_T_lgc, P2VAR(boolean, AUTOMATIC, AUTOMATIC)DSTSlewStart_T_lgc );
STATIC FUNC(void, AP_STBCTO_CODE) StbCTO_DSTSt_RequestDenied(P2VAR(boolean, AUTOMATIC, AUTOMATIC)DSTActive_T_lgc, P2VAR(boolean, AUTOMATIC, AUTOMATIC)DSTSlewStart_T_lgc );
STATIC FUNC(void, AP_STBCTO_CODE) StbCTO_DSTSt_Active(P2VAR(boolean, AUTOMATIC, AUTOMATIC)DSTActive_T_lgc, P2VAR(boolean, AUTOMATIC, AUTOMATIC)DSTSlewStart_T_lgc );
STATIC FUNC(void, AP_STBCTO_CODE) StartAndStopTimer(VAR(uint32, AUTOMATIC) StartTime_mS_T_u32, 
                                                    VAR(uint16, AUTOMATIC) TimeOut_mS_T_u16,
													P2VAR(boolean, boolean, AUTOMATIC) StartTimer_Cnt_T_lgc);

typedef void(*DSTHandler_T)(boolean*DSTActive_T_lgc,boolean*DSTSlewStart_T_lgc);
STATIC CONST(DSTHandler_T, AP_STBCTO_CODE) t_DSTStates_Cnt_Fn[] = 
{
	&StbCTO_DSTSt_Off,				/* DST_STATE_OFF */
	&StbCTO_DSTSt_TNA,				/* DST_STATE_TNA */
	&StbCTO_DSTSt_PNA,				/* DST_STATE_PNA */
	&StbCTO_DSTSt_Ready,			/* DST_STATE_READY */
	&StbCTO_DSTSt_RequestDenied,	/* DST_STATE_REQUESTDENIED */
	&StbCTO_DSTSt_Active,			/* DST_STATE_ACTIVEMODE5 05*/
	&StbCTO_DSTSt_Active,			/* DST_STATE_ACTIVEMODE6 06*/
	&StbCTO_DSTSt_Active,    		/* DST_STATE_ACTIVEMODE7 07*/
	&StbCTO_DSTSt_NotAvailable		/* DST_STATE_NOTAPPLICABLE */
};



#define STBCTO_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(TOC_STATE,  AP_STBCTO_VAR) DSTState_Cnt_M_enum;
#define STBCTO_STOP_SEC_VAR_CLEARED_UNSPECIFIED
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
 * TOC_STATE: Enumeration of integer in interval [0...255] with enumerators
 *   TOCSTATE_OFF (0u)
 *   TOCSTATE_TNA (1u)
 *   TOCSTATE_PNA (2u)
 *   TOCSTATE_READY (3u)
 *   TOCSTATE_REQUESTDENIED (4u)
 *   TOCSTATE_ACTIVEMODE05 (5u)
 *   TOCSTATE_ACTIVEMODE06 (6u)
 *   TOCSTATE_ACTIVEMODE07 (7u)
 *   TOCSTATE_NOTAVAILABLE (8u)
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
 * Float: D_2MS_SEC_F32 = 0.002
 * Float: D_2PI_ULS_F32 = 6.2831853071796
 * Float: D_MTRTRQCMDHILMT_MTRNM_F32 = 8.8
 * Float: D_ONE_ULS_F32 = 1
 * Float: D_PIOVR180_ULS_F32 = 0.0174532925199
 * Float: D_ZERO_ULS_F32 = 0
 * UInt8: D_ONE_CNT_U8 = 1u
 * UInt8: D_ZERO_CNT_U8 = 0u
 *
 *********************************************************************************************************************/


#define RTE_START_SEC_AP_STBCTO_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: StbCTO_Init1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_StbCTO_Init1_DSTActive_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_StbCTO_Init1_DSTActive_Cnt_lgc(void)
 *   void Rte_IWrite_StbCTO_Init1_DSTSlewStart_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_StbCTO_Init1_DSTSlewStart_Cnt_lgc(void)
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
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_SystemTime_GetSystemTime_mS_u32(UInt32 *CurrentTime)
 *     Synchronous Service Invocation. Timeout: None
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_STBCTO_APPL_CODE) StbCTO_Init1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: StbCTO_Init1
 *********************************************************************************************************************/
LoSpdInactive_Cnt_M_lgc = TRUE; 
DSTActive_Cnt_M_lgc = FALSE;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: StbCTO_Per1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 2ms
 *     and not in Mode(s) <OFF>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Implicit S/R API:
 *   -----------------
 *   Boolean Rte_IRead_StbCTO_Per1_DSTEnableRqst_Cnt_lgc(void)
 *   UInt8 Rte_IRead_StbCTO_Per1_DSTErrCntrRecvLevel_Cnt_u08(void)
 *   Boolean Rte_IRead_StbCTO_Per1_DSTExtSystemFltActive_Cnt_lgc(void)
 *   Boolean Rte_IRead_StbCTO_Per1_DSTFuncPresent_Cnt_lgc(void)
 *   Boolean Rte_IRead_StbCTO_Per1_DSTRevGearValid_Cnt_lgc(void)
 *   Boolean Rte_IRead_StbCTO_Per1_DSTSlewComplete_Cnt_lgc(void)
 *   TOC_STATE Rte_IRead_StbCTO_Per1_DSTTOCState_Uls_enum(void)
 *   Float Rte_IRead_StbCTO_Per1_DSTTrqOvCmdRqst_HwNm_f32(void)
 *   Boolean Rte_IRead_StbCTO_Per1_DSTTrqOvRqstValid_Cnt_lgc(void)
 *   Boolean Rte_IRead_StbCTO_Per1_DiagRedAssistLowVoltageActive_Cnt_lgc(void)
 *   Boolean Rte_IRead_StbCTO_Per1_DiagStsNonRecRmpToZeroFltPres_Cnt_lgc(void)
 *   Boolean Rte_IRead_StbCTO_Per1_DiagStsRecRmpToZeroFltPres_Cnt_lgc(void)
 *   Float Rte_IRead_StbCTO_Per1_LimitPercentFiltered_Uls_f32(void)
 *   Boolean Rte_IRead_StbCTO_Per1_TOEOLDisable_Cnt_lgc(void)
 *   Boolean Rte_IRead_StbCTO_Per1_TrqOvReverseGearEngage_Cnt_lgc(void)
 *   Boolean Rte_IRead_StbCTO_Per1_VehicleSpeedValid_Cnt_lgc(void)
 *   Float Rte_IRead_StbCTO_Per1_VehicleSpeed_Kph_f32(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_StbCTO_Per1_DSTActive_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_StbCTO_Per1_DSTActive_Cnt_lgc(void)
 *   void Rte_IWrite_StbCTO_Per1_DSTSlewStart_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_StbCTO_Per1_DSTSlewStart_Cnt_lgc(void)
 *   void Rte_IWrite_StbCTO_Per1_DSTState_Cnt_u08(UInt8 data)
 *   UInt8 *Rte_IWriteRef_StbCTO_Per1_DSTState_Cnt_u08(void)
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

FUNC(void, RTE_AP_STBCTO_APPL_CODE) StbCTO_Per1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: StbCTO_Per1
 *********************************************************************************************************************/
 VAR(boolean, AUTOMATIC) TrqOvReverseGearEngage_Cnt_lgc;
 VAR(Rte_ModeType_StaMd_Mode, AUTOMATIC) SysState_Cnt_T_Enum;
 VAR(boolean, AUTOMATIC) DSTSlewStart_Cnt_T_lgc = FALSE;
 VAR(float32, AUTOMATIC) VehicleSpeed_Kph_T_f32; 
 VAR(float32, AUTOMATIC) LimitPercentFiltered_Uls_T_f32;
 VAR(uint16,  AUTOMATIC) ElapsedTime_mS_T_u16;
 VAR(TOC_STATE,  AUTOMATIC) PrevDSTState_Cnt_T_enum;
 VAR(boolean, AUTOMATIC) VehicleSpeedValid_Cnt_T_lgc;
 VAR(boolean, AUTOMATIC) NTCLowBattVtg_Cnt_T_lgc;
 VAR(TOC_STATE, AUTOMATIC) DSTTOCState_Uls_T_enum;
 VAR(boolean, AUTOMATIC) DSTFuncPresent_Cnt_T_lgc;
 VAR(boolean, AUTOMATIC) TOEOLDisable_Cnt_T_lgc;
 VAR(boolean, AUTOMATIC) DSTRevGearValid_Cnt_T_lgc;

 /* Input */
 VAR(boolean, AUTOMATIC) NTCDSTNotPresentCmdNotZero_Cnt_T_lgc;
 VAR(boolean, AUTOMATIC) NTCDSTEnableTrqRqstNotZero_Cnt_T_lgc;
 VAR(boolean, AUTOMATIC) NTCDSTStateRqstDenied_Cnt_T_lgc;
 
 /* Output */
 VAR(boolean, AUTOMATIC) NTCMaxRqstDenied_Cnt_T_lgc;
 VAR(boolean, AUTOMATIC) NTCDSTPresentTNARDTimerExpired_Cnt_T_lgc;

 /*
 *   NTC_Num_VLF_03 (227U)		E3h
 *   NTC_Num_VLF_10 (234U)		EAh
 *   NTC_Num_VLF_11 (235U)		EBh
 *   NTC_Num_VLF_12 (236U)		ECh
 *   NTC_Num_VLF_13 (237U)		EDh
 */
 
/* Configurable Start of Runnable Checkpoint */
 Rte_Call_StbCTO_Per1_CP0_CheckpointReached();
 
/* capture inputs */	
DSTFuncPresent_Cnt_T_lgc = Rte_IRead_StbCTO_Per1_DSTFuncPresent_Cnt_lgc();
TOEOLDisable_Cnt_T_lgc = Rte_IRead_StbCTO_Per1_TOEOLDisable_Cnt_lgc();
DSTTOCState_Uls_T_enum = Rte_IRead_StbCTO_Per1_DSTTOCState_Uls_enum();
	
 SysState_Cnt_T_Enum = Rte_Mode_SystemState_Mode();
 (void)Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_ExVoltageLow, &NTCLowBattVtg_Cnt_T_lgc);
 LimitPercentFiltered_Uls_T_f32 = Rte_IRead_StbCTO_Per1_LimitPercentFiltered_Uls_f32();
 TrqOvReverseGearEngage_Cnt_lgc = Rte_IRead_StbCTO_Per1_TrqOvReverseGearEngage_Cnt_lgc();
 VehicleSpeed_Kph_T_f32 = Rte_IRead_StbCTO_Per1_VehicleSpeed_Kph_f32();
 DiagStsNonRecRmpToZeroFltPres_Cnt_M_lgc = Rte_IRead_StbCTO_Per1_DiagStsNonRecRmpToZeroFltPres_Cnt_lgc();
 DiagStsRecRmpToZeroFltPres_Cnt_M_lgc = Rte_IRead_StbCTO_Per1_DiagStsRecRmpToZeroFltPres_Cnt_lgc();
 VehicleSpeedValid_Cnt_T_lgc = Rte_IRead_StbCTO_Per1_VehicleSpeedValid_Cnt_lgc();
 DSTRevGearValid_Cnt_T_lgc = Rte_IRead_StbCTO_Per1_DSTRevGearValid_Cnt_lgc();
 
(void)Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_VLF_10, &NTCDSTNotPresentCmdNotZero_Cnt_T_lgc);
(void)Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_VLF_11, &NTCDSTEnableTrqRqstNotZero_Cnt_T_lgc);
(void)Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_VLF_12, &NTCDSTStateRqstDenied_Cnt_T_lgc);
(void)Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_VLF_13, &NTCDSTPresentTNARDTimerExpired_Cnt_T_lgc);
	
 PrevDSTState_Cnt_T_enum = DSTState_Cnt_M_enum;

 /* CF 08B - DST Torque Overlay Function - Vehicle Operative Conditions Monitoring */
 /* Check which Inactive region VehSpd is in: Low or High side */

 if(VehicleSpeedValid_Cnt_T_lgc == FALSE)
 {
 	LoSpdInactive_Cnt_M_lgc = FALSE;
 	HiSpdInactive_Cnt_M_lgc = FALSE;
 	DSTVspdActive_Cnt_M_lgc = FALSE;
 }
 else if(VehicleSpeed_Kph_T_f32 < k_DSTVSpdVLL_Kph_f32)
 {
	LoSpdInactive_Cnt_M_lgc = TRUE;
	HiSpdInactive_Cnt_M_lgc = FALSE;
 }
 else
 {
	if(VehicleSpeed_Kph_T_f32 > k_DSTVSpdVHH_Kph_f32)
	{
		HiSpdInactive_Cnt_M_lgc = TRUE;
		LoSpdInactive_Cnt_M_lgc = FALSE;
	}
 }

 
 /*LowSide Inactive: Determination of Active or Inactive VehSpd */
 if( TRUE == LoSpdInactive_Cnt_M_lgc)
 {
	if(TRUE == DSTVspdActive_Cnt_M_lgc )
	{
		if((k_DSTVSpdVLL_Kph_f32 <= VehicleSpeed_Kph_T_f32) && (VehicleSpeed_Kph_T_f32 <= k_DSTVSpdVHH_Kph_f32))
		{
			(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&InactiveTimer_mS_M_u32);
		}
		else
		{
			(void)Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(InactiveTimer_mS_M_u32,&ElapsedTime_mS_T_u16);
			if(ElapsedTime_mS_T_u16 >= k_DSTVehSpdInActvTime_mS_u16)
			{
				DSTVspdActive_Cnt_M_lgc = FALSE;
				(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&InactiveTimer_mS_M_u32);
			}
		}
	}
	else
	{
		if((k_DSTVSpdVLH_Kph_f32 <= VehicleSpeed_Kph_T_f32) && (VehicleSpeed_Kph_T_f32 <= k_DSTVSpdVHH_Kph_f32))
		{
			(void)Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(activeTimer_mS_M_u32,&ElapsedTime_mS_T_u16);
			if(ElapsedTime_mS_T_u16 >= k_DSTVehSpdActvTime_mS_u16)
			{
				DSTVspdActive_Cnt_M_lgc = TRUE;
				(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&activeTimer_mS_M_u32);
			}
		}
		else
		{ 
			(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&activeTimer_mS_M_u32);
		}
	}
 }
 
 
 /*HighSide Inactive: Dtermination of Active or Inactive Veh Speed */
 if(TRUE == HiSpdInactive_Cnt_M_lgc)
 {
	if(TRUE == DSTVspdActive_Cnt_M_lgc)
	{
		if((k_DSTVSpdVLL_Kph_f32 <= VehicleSpeed_Kph_T_f32) && (VehicleSpeed_Kph_T_f32 <= k_DSTVSpdVHH_Kph_f32))
		{
			(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&InactiveTimer_mS_M_u32);
		}
		else
		{
			(void)Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(InactiveTimer_mS_M_u32,&ElapsedTime_mS_T_u16);
			if(ElapsedTime_mS_T_u16 >= k_DSTVehSpdInActvTime_mS_u16)
			{
				DSTVspdActive_Cnt_M_lgc = FALSE;
				(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&InactiveTimer_mS_M_u32);
			}
		}
	}
	else
	{
		if((k_DSTVSpdVLL_Kph_f32 <= VehicleSpeed_Kph_T_f32) && (VehicleSpeed_Kph_T_f32 <= k_DSTVSpdVHL_Kph_f32))
		{
			(void)Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(activeTimer_mS_M_u32,&ElapsedTime_mS_T_u16);
			if(ElapsedTime_mS_T_u16 >= k_DSTVehSpdActvTime_mS_u16)
			{
				DSTVspdActive_Cnt_M_lgc = TRUE;
				(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&activeTimer_mS_M_u32);
			}
		}
		else
		{
			(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&activeTimer_mS_M_u32);
		}
	}
 }	
				

 /* Backward vehicle motion detection */
  if(FALSE == TrqOvReverseGearEngage_Cnt_lgc)
 {
	  (void)Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(DSTBkwdMotionTime_mS_M_u32, &ElapsedTime_mS_T_u16);
	if((ElapsedTime_mS_T_u16 > k_DSTBkwdMotionTime_mS_u16) && (DSTRevGearValid_Cnt_T_lgc == TRUE))
	{
		DSTBkwdMotionAbsent_Cnt_M_lgc = TRUE;
	}
	else
	{	
		DSTBkwdMotionAbsent_Cnt_M_lgc = FALSE;
	}
 }
 else
{
	DSTBkwdMotionAbsent_Cnt_M_lgc = FALSE;
	(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&DSTBkwdMotionTime_mS_M_u32);
}

 /* Determination of VehExtCond_DST_Active*/
 if( ( (RTE_MODE_StaMd_Mode_WARMINIT == SysState_Cnt_T_Enum) || (RTE_MODE_StaMd_Mode_OPERATE == SysState_Cnt_T_Enum)) &&
	 (TRUE == DSTVspdActive_Cnt_M_lgc ) && 
	 (TRUE == DSTBkwdMotionAbsent_Cnt_M_lgc ) )
 {
	VehExtCondDSTActive_Cnt_M_lgc = TRUE;
 }
 else
 {
	VehExtCondDSTActive_Cnt_M_lgc = FALSE;
 }	
 
 
 /* Internal EPS Operative Conditions Monitoring */ 
 if(LimitPercentFiltered_Uls_T_f32 <= k_TrqOverlayLimitPerc_Uls_f32)
 {
	 (void)Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(DSTInternalCondTimer_mS_M_u32, &ElapsedTime_mS_T_u16);
	 if( (RTE_MODE_StaMd_Mode_OPERATE == SysState_Cnt_T_Enum) && 
	 (FALSE == NTCLowBattVtg_Cnt_T_lgc) && 
	 (ElapsedTime_mS_T_u16 > k_TrqOverlaySuspendTime_mS_u16) && 
	 ((FALSE == DiagStsNonRecRmpToZeroFltPres_Cnt_M_lgc) || (FALSE == DiagStsRecRmpToZeroFltPres_Cnt_M_lgc)))
	{
		IntCondDSTEnable_Cnt_M_lgc = TRUE;
	}
	else
	{
		IntCondDSTEnable_Cnt_M_lgc = FALSE;
	}
 }
 else
 {
	 (void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&DSTInternalCondTimer_mS_M_u32);
	IntCondDSTEnable_Cnt_M_lgc = FALSE;
 }
 
 /* Check State of RD and TNA timer*/
  StartAndStopTimer(DSTTNATimer_M_mS_u32,k_DSTTNAMaxTime_mS_u16, &StartTNATimer_Cnt_M_lgc );
  StartAndStopTimer(DSTRDTimer_M_mS_u32,k_DSTRDMaxTime_mS_u16, &StartRDTimer_Cnt_M_lgc);

 /*DST Enable SUb Function- transition states - determine the next state*/	
 t_DSTStates_Cnt_Fn[DSTState_Cnt_M_enum](&DSTActive_Cnt_M_lgc, &DSTSlewStart_Cnt_T_lgc);

 /*DST Torque Request Diagnostic Sub-Function */
 if(	   (DSTState_Cnt_M_enum == TOCSTATE_REQUESTDENIED)
		&& (PrevDSTState_Cnt_T_enum != DSTState_Cnt_M_enum))
 {
	RDStateCounter_Cnt_M_u08 = RDStateCounter_Cnt_M_u08 + D_ONE_CNT_U8;
	
    if ((DSTFuncPresent_Cnt_T_lgc == TRUE) && (RDStateCounter_Cnt_M_u08 >= k_DSTRDStateMaxCount_Cnt_u08))
	{
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_VLF_03, 0x1U, NTC_STATUS_FAILED);
	}
	else
	{
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_VLF_03, 0x0U, NTC_STATUS_PASSED);
	}
 }
 else
 {
 	(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_VLF_03, 0x0U, NTC_STATUS_PASSED);
 } 
	
 /*NTC DSTPresent and TNARDTIMEREXPIRED Sub-Function */
 if((DSTFuncPresent_Cnt_T_lgc == TRUE) && (DSTState_Cnt_M_enum == TOCSTATE_TNA))
 {
	if(((DSTTOCState_Uls_T_enum == TOCSTATE_ACTIVEMODE05) || 
		(DSTTOCState_Uls_T_enum == TOCSTATE_ACTIVEMODE06) || 
		(DSTTOCState_Uls_T_enum == TOCSTATE_ACTIVEMODE07)) && 
		(FALSE == StartRDTimer_Cnt_M_lgc) &&
		(FALSE == StartTNATimer_Cnt_M_lgc))
	{
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_VLF_13, 0x1U, NTC_STATUS_FAILED);
	}
	else
	{
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_VLF_13, 0x0U, NTC_STATUS_PASSED);
	}
 }
 else
 {
	(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_VLF_13, 0x0U, NTC_STATUS_PASSED);
 }	 

  /*Capture Outputs */	
	Rte_IWrite_StbCTO_Per1_DSTSlewStart_Cnt_lgc(DSTSlewStart_Cnt_T_lgc);
    Rte_IWrite_StbCTO_Per1_DSTActive_Cnt_lgc(DSTActive_Cnt_M_lgc);
 	Rte_IWrite_StbCTO_Per1_DSTState_Cnt_u08((uint8)DSTState_Cnt_M_enum);
	
	/* Configurable End of Runnable Checkpoint */
	Rte_Call_StbCTO_Per1_CP1_CheckpointReached();
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define RTE_STOP_SEC_AP_STBCTO_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
STATIC FUNC(void, AP_STBCTO_CODE) StbCTO_DSTSt_NotAvailable( P2VAR(boolean, AUTOMATIC, AUTOMATIC) DSTActive_T_lgc,
                                                              P2VAR(boolean, AUTOMATIC, AUTOMATIC) DSTSlewStart_T_lgc  )
{
	/* do nothing */
	DSTActive_T_lgc = DSTActive_T_lgc;
	DSTSlewStart_T_lgc = DSTSlewStart_T_lgc;
	
}

/*****************************************************************************
 * Handle State:	DST_STATE_INITIALIZED
 *****************************************************************************/
STATIC FUNC(void, AP_DRVDYNENBL_CODE) StbCTO_DSTSt_Off( P2VAR(boolean, AUTOMATIC, AUTOMATIC) DSTActive_T_lgc,
                                                        P2VAR(boolean, AUTOMATIC, AUTOMATIC) DSTSlewStart_T_lgc )
{
	VAR(boolean, AUTOMATIC) DSTFuncPresent_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) TOEOLDisable_Cnt_T_lgc;
	
	
	/* capture inputs */	
	DSTFuncPresent_Cnt_T_lgc = Rte_IRead_StbCTO_Per1_DSTFuncPresent_Cnt_lgc();
	TOEOLDisable_Cnt_T_lgc = Rte_IRead_StbCTO_Per1_TOEOLDisable_Cnt_lgc();
	
	
	/* determine which state transition to make if any */
	if((TRUE == DSTFuncPresent_Cnt_T_lgc) && (FALSE == TOEOLDisable_Cnt_T_lgc))
	{
		DSTState_Cnt_M_enum = TOCSTATE_TNA;
		(*DSTActive_T_lgc) = FALSE;
		(*DSTSlewStart_T_lgc) = FALSE;
		
		/* Initialize TNA timer */
		(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&DSTTNATimer_M_mS_u32);
		StartTNATimer_Cnt_M_lgc = TRUE;
	}
}

/*****************************************************************************
 * Handle State:	DST_STATE_TNA
 *****************************************************************************/
STATIC FUNC(void, AP_STBCTO_CODE) StbCTO_DSTSt_TNA( P2VAR(boolean, AUTOMATIC, AUTOMATIC) DSTActive_T_lgc,
                                                    P2VAR(boolean, AUTOMATIC, AUTOMATIC) DSTSlewStart_T_lgc )
{

	VAR(Rte_ModeType_StaMd_Mode, AUTOMATIC) SystemState_Cnt_T_enum;
	VAR(boolean, AUTOMATIC) DSTSlewComplete_Cnt_T_lgc;
	VAR(uint8, AUTOMATIC) DSTErrCntrRecvLevel_Cnt_T_u08;
	VAR(TOC_STATE, AUTOMATIC) DSTTOCState_Uls_T_enum;
	VAR(boolean, AUTOMATIC) NTCMaxRqstDenied_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) TOEOLDisable_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) NTCDSTNotPresentCmdNotZero_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) NTCDSTEnableTrqRqstNotZero_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) NTCDSTStateRqstDenied_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) NTCDSTPresentTNARDTimerExpired_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) NTCFaultscheckforFalse_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) DSTEnableRqst_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) DSTExtSystemFltActive_Cnt_T_lgc;
		
	/* capture inputs */
	DSTSlewComplete_Cnt_T_lgc = Rte_IRead_StbCTO_Per1_DSTSlewComplete_Cnt_lgc();
	DSTErrCntrRecvLevel_Cnt_T_u08 = Rte_IRead_StbCTO_Per1_DSTErrCntrRecvLevel_Cnt_u08();
	DSTTOCState_Uls_T_enum = Rte_IRead_StbCTO_Per1_DSTTOCState_Uls_enum();
	TOEOLDisable_Cnt_T_lgc = Rte_IRead_StbCTO_Per1_TOEOLDisable_Cnt_lgc();
	DSTEnableRqst_Cnt_T_lgc = Rte_IRead_StbCTO_Per1_DSTEnableRqst_Cnt_lgc();
	
	(void)Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_VLF_10, &NTCDSTNotPresentCmdNotZero_Cnt_T_lgc);
	(void)Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_VLF_11, &NTCDSTEnableTrqRqstNotZero_Cnt_T_lgc);
	(void)Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_VLF_12, &NTCDSTStateRqstDenied_Cnt_T_lgc);
	(void)Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_VLF_13, &NTCDSTPresentTNARDTimerExpired_Cnt_T_lgc);
	DSTExtSystemFltActive_Cnt_T_lgc = Rte_IRead_StbCTO_Per1_DSTExtSystemFltActive_Cnt_lgc();

	SystemState_Cnt_T_enum = Rte_Mode_SystemState_Mode();
	(void)Rte_Call_NxtrDiagMgr_GetNTCActive(NTC_Num_VLF_03, &NTCMaxRqstDenied_Cnt_T_lgc);
	
	if ((FALSE == DSTEnableRqst_Cnt_T_lgc) &&
		(FALSE == DSTExtSystemFltActive_Cnt_T_lgc) &&
		(FALSE == NTCDSTNotPresentCmdNotZero_Cnt_T_lgc) &&
		(FALSE == NTCDSTEnableTrqRqstNotZero_Cnt_T_lgc) &&
		(FALSE == NTCDSTStateRqstDenied_Cnt_T_lgc) &&
		(FALSE == NTCDSTPresentTNARDTimerExpired_Cnt_T_lgc))
		{
			NTCFaultscheckforFalse_Cnt_T_lgc = TRUE;
		}
	else
		{
			NTCFaultscheckforFalse_Cnt_T_lgc = FALSE;
		}
	/* determine which state transition to make if any */
	
	/* T3 */
	if((SystemState_Cnt_T_enum == RTE_MODE_StaMd_Mode_OPERATE) && 
	   (DSTErrCntrRecvLevel_Cnt_T_u08 <= 1U) &&
	   (TRUE == VehExtCondDSTActive_Cnt_M_lgc) &&
	   (TRUE == IntCondDSTEnable_Cnt_M_lgc ) &&
	   (TRUE == DSTSlewComplete_Cnt_T_lgc) &&
	   ((DSTTOCState_Uls_T_enum != TOCSTATE_ACTIVEMODE05) && 
		(DSTTOCState_Uls_T_enum != TOCSTATE_ACTIVEMODE06) && 
		(DSTTOCState_Uls_T_enum != TOCSTATE_ACTIVEMODE07))&&
	   (FALSE == StartRDTimer_Cnt_M_lgc)&&
	   (FALSE == StartTNATimer_Cnt_M_lgc)&&
	   (TRUE == NTCFaultscheckforFalse_Cnt_T_lgc) )
	{
		(*DSTActive_T_lgc) = FALSE;
		DSTState_Cnt_M_enum = TOCSTATE_READY;
		(*DSTSlewStart_T_lgc) = FALSE;
		
	}
	/* T11 */
	else if((DSTErrCntrRecvLevel_Cnt_T_u08 == (3U)) ||
			(TRUE == DiagStsNonRecRmpToZeroFltPres_Cnt_M_lgc) ||
			(TRUE == NTCMaxRqstDenied_Cnt_T_lgc) ||
			(TRUE == NTCDSTPresentTNARDTimerExpired_Cnt_T_lgc))
	{
		(*DSTActive_T_lgc) = FALSE;
		DSTState_Cnt_M_enum = TOCSTATE_PNA;
		(*DSTSlewStart_T_lgc) = TRUE;
	}
	/* T12 */
	else if(((SystemState_Cnt_T_enum == RTE_MODE_StaMd_Mode_DISABLE) && 
	((FALSE == DiagStsNonRecRmpToZeroFltPres_Cnt_M_lgc) && (FALSE == DiagStsRecRmpToZeroFltPres_Cnt_M_lgc)) 
	&& ( TRUE == DSTSlewComplete_Cnt_T_lgc) ) ||
			((TRUE == TOEOLDisable_Cnt_T_lgc) && (TRUE == DSTSlewComplete_Cnt_T_lgc)))
	{
		(*DSTActive_T_lgc) = FALSE;
        DSTState_Cnt_M_enum =TOCSTATE_OFF;
		(*DSTSlewStart_T_lgc) = FALSE;
	}
	else { }
	
}


/*****************************************************************************
 * Handle State:	DST_STATE_PNA
 *****************************************************************************/
STATIC FUNC(void, AP_STBCTO_CODE) StbCTO_DSTSt_PNA( P2VAR(boolean, AUTOMATIC, AUTOMATIC) DSTActive_T_lgc,
                                                    P2VAR(boolean, AUTOMATIC, AUTOMATIC) DSTSlewStart_T_lgc )
{
	VAR(Rte_ModeType_StaMd_Mode, AUTOMATIC) SystemState_Cnt_T_enum;
	VAR(boolean, AUTOMATIC) DSTSlewComplete_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) TOEOLDisable_Cnt_T_lgc;

	
	/* capture inputs */	
	SystemState_Cnt_T_enum = Rte_Mode_SystemState_Mode();
	DSTSlewComplete_Cnt_T_lgc = Rte_IRead_StbCTO_Per1_DSTSlewComplete_Cnt_lgc();
	TOEOLDisable_Cnt_T_lgc = Rte_IRead_StbCTO_Per1_TOEOLDisable_Cnt_lgc();
	
	
	/* determine which state transition to make if any */
	/* T13 */
	if(((SystemState_Cnt_T_enum == RTE_MODE_StaMd_Mode_DISABLE) && (TRUE == DSTSlewComplete_Cnt_T_lgc)) ||
	   ((TRUE == TOEOLDisable_Cnt_T_lgc) && (TRUE == DSTSlewComplete_Cnt_T_lgc)))
	{
		(*DSTActive_T_lgc) = FALSE;
        DSTState_Cnt_M_enum = TOCSTATE_OFF;
		(*DSTSlewStart_T_lgc) = FALSE;
		
	}
}

/*****************************************************************************
 * Handle State:	DST_STATE_READY
 *****************************************************************************/
STATIC FUNC(void, AP_STBCTO_CODE) StbCTO_DSTSt_Ready( P2VAR(boolean, AUTOMATIC, AUTOMATIC) DSTActive_T_lgc,
                                                      P2VAR(boolean, AUTOMATIC, AUTOMATIC) DSTSlewStart_T_lgc )
{

	VAR(boolean, AUTOMATIC) DSTTrqOvRqstValid_Cnt_T_lgc;
	VAR(uint8, AUTOMATIC) DSTErrCntrRecvLevel_Cnt_T_u08;
	VAR(TOC_STATE, AUTOMATIC) DSTTOCState_Uls_T_enum;
	VAR(boolean, AUTOMATIC) DSTExtSystemFltActive_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) DSTEnableRqst_Cnt_T_lgc;
	VAR(float32, AUTOMATIC)	DSTTrqOvCmdRqst_HwNm_T_f32;
	VAR(float32, AUTOMATIC)	AbsDSTTrqOvCmdRqst_HwNm_T_f32;
	VAR(boolean, AUTOMATIC)	TOEOLDisable_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) NTCDSTNotPresentCmdNotZero_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) NTCDSTEnableTrqRqstNotZero_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) NTCDSTStateRqstDenied_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) NTCDSTPresentTNARDTimerExpired_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) NTCFaultscheckforFalse_Cnt_T_lgc;
	
	/* capture inputs */
	DSTTrqOvRqstValid_Cnt_T_lgc = Rte_IRead_StbCTO_Per1_DSTTrqOvRqstValid_Cnt_lgc();
	DSTExtSystemFltActive_Cnt_T_lgc = Rte_IRead_StbCTO_Per1_DSTExtSystemFltActive_Cnt_lgc();
	DSTErrCntrRecvLevel_Cnt_T_u08 = Rte_IRead_StbCTO_Per1_DSTErrCntrRecvLevel_Cnt_u08();
	DSTEnableRqst_Cnt_T_lgc = Rte_IRead_StbCTO_Per1_DSTEnableRqst_Cnt_lgc();
	DSTTOCState_Uls_T_enum = Rte_IRead_StbCTO_Per1_DSTTOCState_Uls_enum();
	DSTTrqOvCmdRqst_HwNm_T_f32 = Rte_IRead_StbCTO_Per1_DSTTrqOvCmdRqst_HwNm_f32();
	TOEOLDisable_Cnt_T_lgc = Rte_IRead_StbCTO_Per1_TOEOLDisable_Cnt_lgc();
	(void)Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_VLF_10, &NTCDSTNotPresentCmdNotZero_Cnt_T_lgc);
	(void)Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_VLF_11, &NTCDSTEnableTrqRqstNotZero_Cnt_T_lgc);
	(void)Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_VLF_12, &NTCDSTStateRqstDenied_Cnt_T_lgc);
	(void)Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_VLF_13, &NTCDSTPresentTNARDTimerExpired_Cnt_T_lgc);
	
	if ((FALSE == NTCDSTNotPresentCmdNotZero_Cnt_T_lgc) &&
		(FALSE == NTCDSTEnableTrqRqstNotZero_Cnt_T_lgc) &&
		(FALSE == NTCDSTStateRqstDenied_Cnt_T_lgc) &&
		(FALSE == NTCDSTPresentTNARDTimerExpired_Cnt_T_lgc))
		{
			NTCFaultscheckforFalse_Cnt_T_lgc = TRUE;
		}
	else
		{
			NTCFaultscheckforFalse_Cnt_T_lgc = FALSE;
		}
		
		AbsDSTTrqOvCmdRqst_HwNm_T_f32 = Abs_f32_m(DSTTrqOvCmdRqst_HwNm_T_f32);

	/* determine which state transition to make if any */
	/* T4 */
	if((AbsDSTTrqOvCmdRqst_HwNm_T_f32  <= k_DSTTrqOvActiveMaxLimit_MtrNm_f32)&&
	   (D_ZERO_CNT_U8 == DSTErrCntrRecvLevel_Cnt_T_u08) &&
	   (TRUE == DSTTrqOvRqstValid_Cnt_T_lgc) &&
	   (FALSE == DSTExtSystemFltActive_Cnt_T_lgc) &&
	   (TRUE == VehExtCondDSTActive_Cnt_M_lgc) &&
	   (TRUE == IntCondDSTEnable_Cnt_M_lgc ) &&
	   (TRUE == DSTEnableRqst_Cnt_T_lgc) &&
	   ((DSTTOCState_Uls_T_enum == TOCSTATE_ACTIVEMODE05) || 
		(DSTTOCState_Uls_T_enum == TOCSTATE_ACTIVEMODE06) || 
		(DSTTOCState_Uls_T_enum == TOCSTATE_ACTIVEMODE07)) &&
	   (TRUE == NTCFaultscheckforFalse_Cnt_T_lgc) )
	{
		(*DSTActive_T_lgc) = TRUE;
		DSTState_Cnt_M_enum = DSTTOCState_Uls_T_enum;
		(*DSTSlewStart_T_lgc) = FALSE;
		
	}
	/* T10 */
	else if((DSTErrCntrRecvLevel_Cnt_T_u08 == 2U) ||
			(FALSE == VehExtCondDSTActive_Cnt_M_lgc) ||
			(FALSE == IntCondDSTEnable_Cnt_M_lgc) ||
			(TRUE == TOEOLDisable_Cnt_T_lgc ) ||
			(TRUE == DSTExtSystemFltActive_Cnt_T_lgc) ||
			(TRUE == NTCDSTNotPresentCmdNotZero_Cnt_T_lgc) ||
			(TRUE == NTCDSTEnableTrqRqstNotZero_Cnt_T_lgc) ||
			(TRUE == NTCDSTStateRqstDenied_Cnt_T_lgc) ||
			(TRUE == NTCDSTPresentTNARDTimerExpired_Cnt_T_lgc))
			
	{
		(*DSTActive_T_lgc) = FALSE;
		DSTState_Cnt_M_enum = TOCSTATE_TNA;
		(*DSTSlewStart_T_lgc) = TRUE;
		/* Intialize Timer */
		(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&DSTTNATimer_M_mS_u32);
		StartTNATimer_Cnt_M_lgc = TRUE;
	}
	/* T14 */
	else if(((DSTTOCState_Uls_T_enum == TOCSTATE_ACTIVEMODE05) || 
			 (DSTTOCState_Uls_T_enum == TOCSTATE_ACTIVEMODE06) || 
		     (DSTTOCState_Uls_T_enum == TOCSTATE_ACTIVEMODE07))&&
		     (AbsDSTTrqOvCmdRqst_HwNm_T_f32 > k_DSTTrqOvActiveMaxLimit_MtrNm_f32))
	{
		(*DSTActive_T_lgc) = FALSE;
        DSTState_Cnt_M_enum = TOCSTATE_REQUESTDENIED;
		(*DSTSlewStart_T_lgc) = TRUE;
		/* TO-DO timer */
		(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&DSTRDTimer_M_mS_u32);
		StartRDTimer_Cnt_M_lgc = TRUE;
		
	}
	else { }
	
}


/*****************************************************************************
 * Handle State:	DST_STATE_ACTIVE
 *****************************************************************************/
STATIC FUNC(void, AP_STBCTO_CODE) StbCTO_DSTSt_Active( P2VAR(boolean, AUTOMATIC, AUTOMATIC) DSTActive_T_lgc,
                                                       P2VAR(boolean, AUTOMATIC, AUTOMATIC) DSTSlewStart_T_lgc )
{

	VAR(boolean, AUTOMATIC) DSTTrqOvRqstValid_Cnt_T_lgc;
	VAR(uint8, AUTOMATIC) DSTErrCntrRecvLevel_Cnt_T_u08;
	VAR(TOC_STATE, AUTOMATIC) DSTTOCState_Uls_T_enum;
	VAR(boolean, AUTOMATIC) DSTExtSystemFltActive_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) DSTEnableRqst_Cnt_T_lgc;
	VAR(float32, AUTOMATIC)	DSTTrqOvCmdRqst_HwNm_T_f32;
	VAR(boolean, AUTOMATIC)	TOEOLDisable_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC)	NTCMaxRqstDenied_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC)	NTCDSTMaxRate_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC)	NTCDSTStuckValue_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC)	NTCDSTMaxTime_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC)	NTCDSTEXOR_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC)	NTCDSTMaxValue_Cnt_T_lgc;
	VAR(float32, AUTOMATIC) AbsDSTTrqOvCmdRqst_HwNm_T_f32;
	VAR(boolean, AUTOMATIC)	NTCDSTEnableTrqRqstNotZero_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC)	NTCDSTStateRqstDenied_Cnt_T_lgc;
	
	
	/* capture inputs */
	DSTTrqOvRqstValid_Cnt_T_lgc = Rte_IRead_StbCTO_Per1_DSTTrqOvRqstValid_Cnt_lgc();
	DSTExtSystemFltActive_Cnt_T_lgc = Rte_IRead_StbCTO_Per1_DSTExtSystemFltActive_Cnt_lgc();
	DSTErrCntrRecvLevel_Cnt_T_u08 = Rte_IRead_StbCTO_Per1_DSTErrCntrRecvLevel_Cnt_u08();
	DSTEnableRqst_Cnt_T_lgc = Rte_IRead_StbCTO_Per1_DSTEnableRqst_Cnt_lgc();
	DSTTOCState_Uls_T_enum = Rte_IRead_StbCTO_Per1_DSTTOCState_Uls_enum();
	DSTTrqOvCmdRqst_HwNm_T_f32 = Rte_IRead_StbCTO_Per1_DSTTrqOvCmdRqst_HwNm_f32();
	TOEOLDisable_Cnt_T_lgc = Rte_IRead_StbCTO_Per1_TOEOLDisable_Cnt_lgc();
	
	AbsDSTTrqOvCmdRqst_HwNm_T_f32 = Abs_f32_m(DSTTrqOvCmdRqst_HwNm_T_f32);
	
	(void)Rte_Call_NxtrDiagMgr_GetNTCActive(NTC_Num_VLF_03, &NTCMaxRqstDenied_Cnt_T_lgc);
	(void)Rte_Call_NxtrDiagMgr_GetNTCActive(NTC_Num_DataRateFltMsg_Z, &NTCDSTMaxRate_Cnt_T_lgc);
	(void)Rte_Call_NxtrDiagMgr_GetNTCActive(NTC_Num_InvalidMsg_Z, &NTCDSTStuckValue_Cnt_T_lgc);
	(void)Rte_Call_NxtrDiagMgr_GetNTCActive(NTC_Num_DataOtherFltMsg_Z, &NTCDSTMaxTime_Cnt_T_lgc);
	(void)Rte_Call_NxtrDiagMgr_GetNTCActive(NTC_Num_DSTXORActive, &NTCDSTEXOR_Cnt_T_lgc);
	(void)Rte_Call_NxtrDiagMgr_GetNTCActive(NTC_Num_DataRngFltMsg_Z, &NTCDSTMaxValue_Cnt_T_lgc);
	(void)Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_VLF_11, &NTCDSTEnableTrqRqstNotZero_Cnt_T_lgc);
	(void)Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_VLF_12, &NTCDSTStateRqstDenied_Cnt_T_lgc);
	


	/* determine which state transition to make if any */
	/* T5 */
	if(((AbsDSTTrqOvCmdRqst_HwNm_T_f32 < FLT_EPSILON) && ((DSTTOCState_Uls_T_enum == TOCSTATE_TNA) || (DSTTOCState_Uls_T_enum == TOCSTATE_OFF))) ||
	   (DSTErrCntrRecvLevel_Cnt_T_u08 == 2u) ||
	   (FALSE == DSTTrqOvRqstValid_Cnt_T_lgc) ||
	   (TRUE == DSTExtSystemFltActive_Cnt_T_lgc) ||
	   (FALSE == VehExtCondDSTActive_Cnt_M_lgc) ||
	   (FALSE == IntCondDSTEnable_Cnt_M_lgc ) ||
	   (DSTTOCState_Uls_T_enum == TOCSTATE_PNA)||
	   (TRUE == TOEOLDisable_Cnt_T_lgc))
	{
		(*DSTActive_T_lgc) = FALSE;
		DSTState_Cnt_M_enum = TOCSTATE_TNA;
		(*DSTSlewStart_T_lgc) = TRUE;
		/* DST_TNA_Timer */
		(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&DSTTNATimer_M_mS_u32);
		StartTNATimer_Cnt_M_lgc = TRUE;
	}
	/* T6 */
	else if((((DSTTOCState_Uls_T_enum == TOCSTATE_ACTIVEMODE05) || 
			  (DSTTOCState_Uls_T_enum == TOCSTATE_ACTIVEMODE06) || 
			  (DSTTOCState_Uls_T_enum == TOCSTATE_ACTIVEMODE07))||
	         ((DSTTOCState_Uls_T_enum == TOCSTATE_READY) &&
     		  (AbsDSTTrqOvCmdRqst_HwNm_T_f32 < FLT_EPSILON))) &&
			(TRUE == NTCDSTMaxRate_Cnt_T_lgc))
	{
		/* Request Denied */
		(*DSTActive_T_lgc) = FALSE;
		DSTState_Cnt_M_enum =TOCSTATE_REQUESTDENIED;
		(*DSTSlewStart_T_lgc) = TRUE;
		/* DST_RD_TIMER */
		(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&DSTRDTimer_M_mS_u32);
		StartRDTimer_Cnt_M_lgc = TRUE;
	}
	/* T7 */
	else if((AbsDSTTrqOvCmdRqst_HwNm_T_f32 < FLT_EPSILON) &&
			(DSTTOCState_Uls_T_enum == TOCSTATE_READY) && 
		    (FALSE == NTCDSTMaxRate_Cnt_T_lgc) &&
			(FALSE == NTCDSTStuckValue_Cnt_T_lgc) &&
			(FALSE == NTCDSTMaxTime_Cnt_T_lgc) &&
			(FALSE == NTCDSTEXOR_Cnt_T_lgc) &&
			(FALSE == NTCDSTMaxValue_Cnt_T_lgc) &&
			(FALSE == NTCDSTEnableTrqRqstNotZero_Cnt_T_lgc) &&
			(FALSE == NTCDSTStateRqstDenied_Cnt_T_lgc) )
	{
		/* Ready */
		DSTState_Cnt_M_enum = TOCSTATE_READY;
		(*DSTActive_T_lgc) = FALSE;
		(*DSTSlewStart_T_lgc) = FALSE;
	}
	/* T15 */
	else if((DSTErrCntrRecvLevel_Cnt_T_u08 == 3U) ||
	        (TRUE == DiagStsNonRecRmpToZeroFltPres_Cnt_M_lgc) ||
			(TRUE == NTCDSTEnableTrqRqstNotZero_Cnt_T_lgc) ||
			(TRUE == NTCDSTStateRqstDenied_Cnt_T_lgc) ||
			(TRUE == NTCDSTStuckValue_Cnt_T_lgc)||
			(TRUE == NTCDSTMaxTime_Cnt_T_lgc)||
			(TRUE == NTCDSTEXOR_Cnt_T_lgc)||
			(TRUE == NTCDSTMaxValue_Cnt_T_lgc))
	{
		/* PNA */
		DSTState_Cnt_M_enum = TOCSTATE_PNA;
		(*DSTActive_T_lgc) = FALSE;
		(*DSTSlewStart_T_lgc) = TRUE;
	}
	else { }
	
}

/*****************************************************************************
 * Handle State:	DST_STATE_REQUESTDENIED
 *****************************************************************************/
STATIC FUNC(void, AP_STBCTO_CODE) StbCTO_DSTSt_RequestDenied( P2VAR(boolean, AUTOMATIC, AUTOMATIC) DSTActive_T_lgc,
                                                              P2VAR(boolean, AUTOMATIC, AUTOMATIC) DSTSlewStart_T_lgc )
{

	VAR(uint8, AUTOMATIC) DSTErrCntrRecvLevel_Cnt_T_u08;
	VAR(boolean, AUTOMATIC) NTCMaxRqstDenied_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC)	TOEOLDisable_Cnt_T_lgc;
			
	/* capture inputs */
	DSTErrCntrRecvLevel_Cnt_T_u08 = Rte_IRead_StbCTO_Per1_DSTErrCntrRecvLevel_Cnt_u08();
	TOEOLDisable_Cnt_T_lgc = Rte_IRead_StbCTO_Per1_TOEOLDisable_Cnt_lgc();
	
	(void)Rte_Call_NxtrDiagMgr_GetNTCActive(NTC_Num_VLF_03, &NTCMaxRqstDenied_Cnt_T_lgc);

	/* determine which state transition to make if any */
	/* T8 */
	if((DSTErrCntrRecvLevel_Cnt_T_u08 == 2u) ||
	   (TRUE == NTCMaxRqstDenied_Cnt_T_lgc) ||
	   (TRUE == TOEOLDisable_Cnt_T_lgc) ||
	   (FALSE == VehExtCondDSTActive_Cnt_M_lgc) ||
	   (FALSE == IntCondDSTEnable_Cnt_M_lgc )||
	   (FALSE == StartRDTimer_Cnt_M_lgc))
	{
		(*DSTActive_T_lgc) = FALSE;
		DSTState_Cnt_M_enum = TOCSTATE_TNA;
		(*DSTSlewStart_T_lgc) = TRUE;
		/* DST_TNA_Timer */
		(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&DSTTNATimer_M_mS_u32);
		StartTNATimer_Cnt_M_lgc = TRUE;
		
	}
		
	
}

STATIC FUNC(void, AP_STBCTO_CODE) StartAndStopTimer(VAR(uint32, AUTOMATIC) StartTime_mS_T_u32, 
                                                     VAR(uint16, AUTOMATIC) TimeOut_mS_T_u16,
													 P2VAR(boolean, boolean, AUTOMATIC) StartTimer_Cnt_T_lgc)
{
	VAR(uint16, AUTOMATIC) ElapsedTime_mS_T_u16;
	
	
    if(TRUE == *StartTimer_Cnt_T_lgc)
	{
    	(void)Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(StartTime_mS_T_u32, &ElapsedTime_mS_T_u16);
	
		if( ElapsedTime_mS_T_u16 >= TimeOut_mS_T_u16 )
		{
			/* stop timer - Timer expired */
			(*StartTimer_Cnt_T_lgc) = FALSE;
		}
		
	}
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
