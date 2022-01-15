/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Ap_SrlComOutput.c
 *     Workspace:  C:/_swb/Chrysler/Chrysler_LWR_EPS_TMS570-cz7lt6/Chrysler_LWR_EPS_TMS570/Tools/AsrProject/Config/DCF/EPS.dcf
 *     SW-C Type:  Ap_SrlComOutput
 *  Generated at:  Mon Dec 17 13:28:14 2012
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1 (Beta)
 *       License:  License CBD1010124 valid for CBD1010124 Nexteer  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  C-Code implementation template for SW-C <Ap_SrlComOutput>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/* Version Control:
 * Date Created:      Mon Aug 13 12:17:00 2012
 * %version:          37 %
 * %derived_by:       sz1dx6 %
 * %date_modified:    Thu Feb 27 13:37:27 2014 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 08/31/12  2        SAH		Updated StrClmTrq output signal
 * 09/14/12  3        SAH		Updated StrClmTrq output signal correctly this time.
 * 09/22/12  4        OT        Clean up, apply offset and gain, calculate checksum for EPS_1
 * 10/05/12	 5		  SAH		Update message counter range to go from 0-15(messae 0x220).
 * 12/18/12	 10		  KJS		Updated all signals and implemented missing features per the SER.
 * 12/18/12	 11		  BWL		Network Management update.
 * 12/19/12	 12		  SAH		Name changes and System time updates.
 * 01/28/13	 15		  SAH		Removed call to CCL_task
 * 01/30/13	 16		  SAH		Removed call to CCLinitPowerOn
 * 02/18/13  17       M. Story  Corrected CRC
 * 02/21/13  18       DD		Corrected 221 msg and CRC - unused bits set to 1
 * 04/12/13  20		  Srikanth  Anomaly 4757 - Alligning DID A001,Anomaly 4744 - Initializing signals      CR7798
 *                              in message AwakeEPS_T_str
 *
 * 04/15/13  21       M. Story  Anomaly 4445 and 4684
 * 04/18/13  22       M. Story  Anomaly 4838
 * 04/25/13  23       M. Story  update for CLWR v3 and dbc 1313
 * 06/16/13  25       M. Story  Anomaly 5014
 * 06/16/13  28       SAH		Changed Cfg_stat_req from u16 to u8 to match srlcominput
 * 08/10/13  29       M. Story  Anomaly 5416
 * 08/12/13  30       M. Story  Create constant for GotoMode
 * 9/16/13   31       M. Story  Anomaly 4749, 4699, 4701, 4700
 * 10/15/13  33       M. Story  Anomaly 5610
 * 10/15/13  34       SAH		Fixed Rte read issues
 * 11/28/13  36       M. Story  Correct commenting error
 * 02/27/14  37       M. Story  Anomaly 6408
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "Rte_Ap_SrlComOutput.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
 

#include "Rte_Type.h"
#include "v_inc.h"
#include "nm_basic.h"
#include "fixmath.h"
#include "GlobalMacro.h"
#include "CalConstants.h"
#include "ccl_inc.h"
#include "nm_udata.h"
#include "dbk_par.h"
#include "desc.h"
#include "dem.h" /* Required for CTC analysis */
#include "Ap_DfltConfigData.h"
#include "crc.h"
#include "n_onmdef.h"
#include "dpm.h"
#include "float.h"

/* EPS_A1 enum lists */
enum EPSA1_AsstStat{
	EPSA1_AsstStat_Active 		= 0x00U,
	EPSA1_AsstStat_Off			= 0x01U,
	EPSA1_AsstStat_ThrmRed		= 0x02U,
	EPSA1_AsstStat_SigNotAval	= 0x07U
};

enum EPSA1_WarnDisp{
	EPSA1_WarnDisp_FuncActive		= 0x00U,
	EPSA1_WarnDisp_ServPwrSteer		= 0x01U,
	EPSA1_WarnDisp_PwrSteerOvTmp	= 0x02U,
	EPSA1_WarnDisp_ServReqdHighPri	= 0x03U,
	EPSA1_WarnDisp_SigNotAval		= 0x07U
};

/* EPS_Curr */
#define D_SUPPLYCURROFFSET_ULS_F32	(50.0F)
#define D_EPSCURR_HILMT_AMP_F32		(203.0F)
#define D_EPSCURR_LOLMT_AMP_F32		(-50.0F)

/* EPS_2 Constants/Enums */
#define D_CRCINIT_CNT_U8					0xFFu
#define D_CRCXORVALUE_CNT_U8				0xFFu
#define D_COUNTERCYCLE16_CNT_U16			0x10u
#define D_UNUSED0MSG221_CNT_U8				0xFFu

/* Steering Column Torque */
#define D_STRCLMTRQLOLIMIT_HWNM_F32			(-8.0F)
#define D_STRCLMTRQHILIMIT_HWNM_F32			(7.9765625F)
#define D_STRCLMTRQOFFSET_HWNM_F32			(8.0F)
#define D_STRCLMTRQ_SIGNOTAVAL_CNTS_U16		(0x07FFU)

/* Assist Torque Limits */
#define D_ASSTTRQ_HILMT_HWNM_F32 			(104.65F)
#define D_ASSTTRQ_LOLMT_HWNM_F32			(-100.0F)
#define D_ASSTTRQ_OFFSET_HWNM_F32			(100.0F)
#define D_ASSTTRQ_ENGTOCNTS_SCALE_HWNM_F32	(20.0F)	/* Going from Eng to Counts -> Eng/0.05=Cnts or Eng*20=Cnts */

/* EPS_2 Constants/Enums */

/* Steering Column Torque */
#define D_STRCLMTRQLOLIMIT_HWNM_F32			(-8.0F)
#define D_STRCLMTRQHILIMIT_HWNM_F32			(7.9765625F)
#define D_STRCLMTRQOFFSET_HWNM_F32			(8.0F)
#define D_STRCLMTRQ_SIGNOTAVAL_CNTS_U16		(0x07FFU)

/* HALF Torque Overlay States */
#define D_HALFSTATEINACTIVE_CNT_U08		((uint8)0U)
#define D_HALFSTATEACTIVE_CNT_U08		((uint8)1U)
#define D_HALFSTATEINHIBITED_CNT_U08	((uint8)2U)
#define D_HALFSTATERECOVERABLE_CNT_U08	((uint8)3U)

/* Active Function Bits */
#define D_PPPAFUNCBIT_CNT_U08	0x01
#define D_DSTFUNCBIT_CNT_U08	0x02
#define D_HALFFUNCBIT_CNT_U08	0x04

/* Park Assist State */
#define D_PASTATEINACTIVE_CNT_U08		((uint8)0U)
#define D_PASTATEACTIVE_CNT_U08			((uint8)1U)
#define D_PASTATEINHIBITED_CNT_U08		((uint8)2U)
#define D_PASTATERECOVERABLE_CNT_U08	((uint8)3U)

/* EPS Motor Torque */
#define D_EPSMTRTRQ_HILMT_MTRNM_F32			(1.998046875F)
#define D_EPSMTRTRQ_LOLMT_MTRNM_F32			(-2.0F)
#define D_EPSMTRTRQ_OFFSET_ULS_F32			(2.0F)
#define D_EPSMTRTRQ_SIGNOTAVAL_CNT_U16	((uint16)0xFFFFU)

/* Network Manager */
#define D_NMAWAKENWST_CNT_U08			((uint8)0x01U)
#define D_NMAWAKEDIAGACTV_CNT_U08		((uint8)0x02U)
#define D_NMAWAKERAMPOUT_CNT_U08		((uint8)0x04U)
#define D_NMAWAKEVSSHIGH_CNT_U08		((uint8)0x08U)
#define D_NMAWAKEENGRPMHIGH_CNT_U08		((uint8)0x10U)
#define D_NMAWAKEIGNHIGH_CNT_U08		((uint8)0x20U)
#define D_NMSTARTUPSLEEPDELAY_MS_U32	((uint32)5000U)
#define D_NMWAKEUPREASONIGN_CNT_U08		((uint8)0x01U)

#define D_TXAWAKE_NWST_CNT_U08				(0x01U   << 	0)
#define D_TXAWAKE_DIAGACTIVE_CNT_U08		(0x01U   << 	1)
#define D_TXAWAKE_RAMPOUT_CNT_U08			(0x01U   << 	2)
#define D_TXAWAKE_VSSHIGH_CNT_U08			(0x01U   << 	3)
#define D_TXAWAKE_ENGRPM_CNT_U08			(0x01U   << 	4)
#define D_TXAWAKE_IGNHIGH_CNT_U08			(0x01U   << 	5)
#define D_SLEEPINDICATORCLEAR_U08           (0x00U)

#define D_SLEEPSTATE_U08                    (0x00U)

#define D_ENGONRPM_CNT_U16		0x12CU
#define D_ENGRPMINVLD_CNT_U16	0xFFFFU

#define TOCSTATE_PNA (2U)

#define SRLCOMOUTPUT_START_SEC_VAR_CLEARED_BOOLEAN

/***************************************************************************/
/* Function prototypes and external macros                                 */
/***************************************************************************/
#define NmStateRingStable(state)          (((state)   & 0x01) ? 1 : 0)
#define NmStateBusError(state)            (((state)   & 0x02) ? 1 : 0)
#define NmStateActive(state)              (((state)   & 0x04) ? 1 : 0)
#define NmStatePassive(state)             (((state)   & 0x04) ? 0 : 1)
#define NmStateLimphome(state)            (((state)   & 0x08) ? 1 : 0)
#define NmStateBusSleep(state)            (((state)   & 0x10) ? 1 : 0)
#define NmStateWaitBusSleep(state)        (((state)   & 0x20) ? 1 : 0)
#define NmStateTxRingDataAllowed(state)   (((state)   & 0x40) ? 1 : 0)
#define NmStateBusSleepInd(state)         (((state)   & 0x80) ? 1 : 0)
#define NmStateBusWakeUp(state)           (((state)   & 0x80) ? 0 : 1)
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(boolean,  AUTOMATIC) NMBusWaitSleepCancel_Cnt_M_lgc;
STATIC VAR(boolean,  AUTOMATIC) CanMsgReceived_Cnt_M_lgc;
STATIC VAR(boolean,  AUTOMATIC) MtrTrqValid_Cnt_M_lgc;
#define SRLCOMOUTPUT_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h" /* PRQA S 5087 */

#define SRLCOMOUTPUT_START_SEC_VAR_CLEARED_8
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(uint8,   AUTOMATIC) MCEPS1_Cnt_M_u08;
STATIC VAR(uint8,  AP_SRLCOMINPUT_VAR_INIT) SleepIndicator_Cnt_M_bit;
#define SRLCOMOUTPUT_STOP_SEC_VAR_CLEARED_8
#include "MemMap.h" /* PRQA S 5087 */

#define SRLCOMOUTPUT_START_SEC_VAR_CLEARED_32
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(uint32,  AUTOMATIC) NMFirstMsg_mS_M_u32;
STATIC VAR(uint32,  AUTOMATIC) NMBusWaitSleepCancel_mS_M_u32;
STATIC VAR(tEPS_1_PKT,  AUTOMATIC) EPS1_M_str;
#define SRLCOMOUTPUT_STOP_SEC_VAR_CLEARED_32
#include "MemMap.h" /* PRQA S 5087 */

/* Local functions */
STATIC INLINE FUNC(void, AP_SRLCOMOUTPUT_CODE) CalcCRC_EPS_1( void);
STATIC FUNC(uint8, AP_SRLCOMOUTPUT_CODE) DetermineWarnDisp(void);
STATIC FUNC(uint16, AP_SRLCOMOUTPUT_CODE) ScaleSignal_u16(	VAR(float32, AUTOMATIC) Signal_Uls_T_f32, VAR(float32, AUTOMATIC) LoLmt_Uls_T_f32,
															VAR(float32, AUTOMATIC) HiLmt_Uls_T_f32, VAR(float32, AUTOMATIC) Scale_Uls_T_f32,
															VAR(float32, AUTOMATIC) Offset_Uls_T_f32);
STATIC FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComOutput_WriteBits(uint32 Data_T_Cnt_u32, uint8* Buffer_T_Cnt_u08, uint16 StartBit_Cnt_T_u16, uint16 EndBit_Cnt_T_u16);
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
 * Boolean: D_TRUE_CNT_LGC = TRUE
 * Double: D_SFINVMILLI_ULS_F32 = 1000
 * Float: D_100MS_SEC_F32 = 0.1F
 * Float: D_180OVRPI_ULS_F32 = 57.295779513082F
 * Float: D_2MS_MS_F32 = 0.002F
 * Float: D_2MS_SEC_F32 = 0.002F
 * Float: D_2PI_ULS_F32 = 6.2831853071796F
 * Float: D_MSECPERSEC_ULS_F32 = 1000.0F
 * Float: D_MTRCTRLHIGHLMT_VOLTS_F32 = 18.0F
 * Float: D_MTRCTRLLOWLMT_VOLTS_F32 = 9.0F
 * Float: D_MTRTRQCMDHILMT_MTRNM_F32 = 8.8F
 * Float: D_MTRTRQCMDLOLMT_MTRNM_F32 = -8.8F
 * Float: D_MTRTRQCMLOLMT_MTRNM_F32 = -8.8F
 * Float: D_ONE_ULS_F32 = 1.0F
 * Float: D_PIOVR180_ULS_F32 = 0.0174532925199F
 * Float: D_PI_ULS_F32 = 3.1415926535898F
 * Float: D_RADPERREV_ULS_F32 = 6.28318530718F
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
 * UInt16: D_RACKTOVEHCNTRUNLEARNED_CNT_U16 = 4095U
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


#define RTE_START_SEC_AP_SRLCOMOUTPUT_APPL_CODE
#include "MemMap.h"

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComOutput_Init1
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
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMOUTPUT_APPL_CODE) SrlComOutput_Init1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SrlComOutput_Init1
 *********************************************************************************************************************/
    
	
	VAR(tEPS_A1_PKT, AUTOMATIC) EPSA1_T_str;
	VAR(tWakeup_EPS, AUTOMATIC) WakeupEPS_T_str;
	
	
	/* Set Default Messages */
	
	EPSA1_T_str.s.unused0 = 0x00;
	SetValueTxEPS_AsstStat(EPSA1_T_str, 0x01U);
	SetValueTxEPS_Warn_Disp_Rq(EPSA1_T_str, 0x00);
	EPSA1_T_str.s.unused1 = 0x00;
	EPSA1_T_str.s.unused2 = 0x00;
	SetValueTxEPS_Curr(EPSA1_T_str, 0xFFU);
	EPSA1_T_str.s.unused3 = 0x00;
	EPSA1_T_str.s.unused4 = 0x00;
	EPSA1_T_str.s.unused5 = 0x00;
	EPSA1_T_str.s.unused6 = 0x00;

	dbkPutTxEPS_A1_PKT(EPSA1_T_str);

	CclEnableCommunication();
	DpmExternalRequest(DPM_EPS);

	SetValueTxWakeupRsn_EPS(WakeupEPS_T_str, D_NMWAKEUPREASONIGN_CNT_U08);
	SetValueTxWakeupCnt(WakeupEPS_T_str, 0x00);
	WakeupEPS_T_str.s.unused0 = 0x00;
	nmpduPutWakeup_EPS(WakeupEPS_T_str);
	
	SetValueTxTOI_Act_Sts(EPS1_M_str, 0x00);
	SetValueTxStrClmTrqVD(EPS1_M_str, 0x00);
	SetValueTxStrClmTrq(EPS1_M_str, 0x07FFU);
	SetValueTxAssistanceTorque(EPS1_M_str, 0x00);
	SetValueTxPTSDriveStyleSts(EPS1_M_str, 0x00);
	SetValueTxDSTTorqueOverlayFault(EPS1_M_str, 0x00);
	SetValueTxHALFTorqueOverlayFault(EPS1_M_str, 0x00);
	SetValueTxHALFTorqueOverlayIntActivated(EPS1_M_str, 0x00);
	SetValueTxEPSMotorTorque(EPS1_M_str, 0x00);
	SetValueTxEPSMotorTorqueValidData(EPS1_M_str, 0x00);
	SetValueTxEPSHandsOnRecognition(EPS1_M_str, 0x00);
	SetValueTxEPSTemporaryDeactivationLDW(EPS1_M_str, 0x00);
	SetValueTxPTSTorqueOverlayFault(EPS1_M_str, 0x00);
	SetValueTxPTSTorqueOverlayIntActivated(EPS1_M_str, 0x00);
	SleepIndicator_Cnt_M_bit = 0x00U;

	SetValueTxMC_EPS_1(EPS1_M_str, MCEPS1_Cnt_M_u08);
	CalcCRC_EPS_1();
	dbkPutTxEPS_1_PKT(EPS1_M_str);
	
	
	Rte_Call_SystemTime_GetSystemTime_mS_u32(&NMFirstMsg_mS_M_u32);
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComOutput_Per1
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
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_ActiveFunctionBits_Cnt_u08(UInt8 *data)
 *   Std_ReturnType Rte_Read_ActiveTunSet_Cnt_u16(UInt16 *data)
 *   Std_ReturnType Rte_Read_DSTEOLDisable_Cnt_lgc(Boolean *data)
 *   Std_ReturnType Rte_Read_DSTExtSystemFltActive_Cnt_lgc(Boolean *data)
 *   Std_ReturnType Rte_Read_DSTState_Cnt_u08(UInt8 *data)
 *   Std_ReturnType Rte_Read_HaLFState_Cnt_u08(UInt8 *data)
 *   Std_ReturnType Rte_Read_HaLFSuspend_Cnt_lgc(Boolean *data)
 *   Std_ReturnType Rte_Read_HandsOnDetect_Cnt_lgc(Boolean *data)
 *   Std_ReturnType Rte_Read_HwTrq_HwNm_f32(Float *data)
 *   Std_ReturnType Rte_Read_PrkAssistState_Cnt_u08(UInt8 *data)
 *   Std_ReturnType Rte_Read_PrkAssistSuspend_Cnt_lgc(Boolean *data)
 *   Std_ReturnType Rte_Read_SrlComHwTrqValid_Cnt_lgc(Boolean *data)
 *   Std_ReturnType Rte_Read_SupplyCurrent_Amp_f32(Float *data)
 *
 *   Implicit S/R API:
 *   -----------------
 *   UInt16 Rte_IRead_SrlComOutput_Per1_EngRPM_Cnt_u16(void)
 *   Boolean Rte_IRead_SrlComOutput_Per1_RampDwnStatusComplete_Cnt_lgc(void)
 *   Boolean Rte_IRead_SrlComOutput_Per1_VehSpdValid_Cnt_lgc(void)
 *   Float Rte_IRead_SrlComOutput_Per1_VehSpd_Kph_f32(void)
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
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_GetNTCFailed(NTCNumber NTC_Cnt_T_enum, Boolean *NTCFailed_Ptr_T_lgc)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMOUTPUT_APPL_CODE) SrlComOutput_Per1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SrlComOutput_Per1
 *********************************************************************************************************************/
	
	/* NMPDU */
	VAR(tAwake_EPS, AUTOMATIC) AwakeEPS_T_str;

	/* NMPDU Support Variables */
	VAR(boolean, AUTOMATIC) RampStatusComplete_T_Cnt_lgc;
	VAR(boolean, AUTOMATIC) VehSpdValid_Cnt_T_lgc;
	VAR(float32, AUTOMATIC) VehSpd_Kph_T_f32;
	VAR(uint16, AUTOMATIC) EngRPM_Cnt_T_u16;
	VAR(boolean, AUTOMATIC) CanMsgReceived_Cnt_T_lgc;
	VAR(float32, AUTOMATIC) OutputRampMult_Uls_T_f32;

	/* EPS_A1 */
	VAR(tEPS_A1_PKT, AUTOMATIC) EPSA1_T_str;

	/* EPS_A1 Support Variables */
	VAR(uint8, AUTOMATIC) EPSAsstStat_Cnt_T_u08;
	VAR(uint8, AUTOMATIC) EPSWarnDispRq_Cnt_T_u08;
	VAR(uint8, AUTOMATIC) EPSCurr_Cnt_T_u08;
	VAR(Rte_ModeType_StaMd_Mode, AUTOMATIC) SysState_Cnt_T_Enum;
	VAR(boolean, AUTOMATIC) AbsTempThermLimit_Cnt_T_lgc;
	VAR(float32, AUTOMATIC) SupplyCurrent_Amp_T_f32;


	/* EPS_1 Support Variables */
	VAR(uint8, AUTOMATIC) DSTState_Cnt_T_u08;
	VAR(boolean, AUTOMATIC) SrlComHwTrqVld_Cnt_T_lgc;
	VAR(uint16, AUTOMATIC) StrClmTrq_Cnt_T_u16;
	VAR(float32, AUTOMATIC) AnaHwTorque_HwNm_T_f32;
	VAR(uint8, AUTOMATIC) DSTTOIFaulted_Cnt_T_u08;
	VAR(uint8, AUTOMATIC) HaLFState_Cnt_T_u08;
	VAR(uint8, AUTOMATIC) ActiveFuncBits_Cnt_T_u08;
	VAR(uint16, AUTOMATIC) AssistanceTrq_HwNm_T_u16;
	VAR(float32, AUTOMATIC) AssistanceTrq_HwNm_T_f32;
	VAR(float32, AUTOMATIC) SumLimTrqCmd_MtrNM_T_f32;
	VAR(uint16, AUTOMATIC) EPSMotorTrq_MtrNm_T_u16;
	VAR(float32, AUTOMATIC) EPSMotorTrq_MtrNm_T_f32;
	VAR(boolean, AUTOMATIC) HandsOnDetect_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) PASuspend_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) HaLFSuspend_Cnt_T_lgc;
	VAR(uint8, AUTOMATIC) PAState_Cnt_T_u08;
	VAR(boolean, AUTOMATIC) NonRecFltActive_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) RecFltActive_Cnt_T_lgc;
	VAR(uint8, AUTOMATIC) CFG_STAT_RQ_Cnt_T_u08;
	VAR(boolean, AUTOMATIC) EPSEn_Cnt_T_lgc;
	VAR(uint16, AUTOMATIC) DesiredTunPers_Cnt_T_u16;
	VAR(boolean, AUTOMATIC)CTermActive_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC)SpStPrsnt_Cnt_T_lgc;

    /* Network Management Message 41A*/
    Rte_Read_EngRPM_Cnt_u16(&EngRPM_Cnt_T_u16);
    Rte_Read_VehicleSpeed_Kph_f32(&VehSpd_Kph_T_f32);
    Rte_Read_SrlComVehSpdValid_Cnt_lgc(&VehSpdValid_Cnt_T_lgc);
    Rte_Read_RampDwnStatusComplete_Cnt_lgc(&RampStatusComplete_T_Cnt_lgc);
	Rte_Read_Ap_SrlComOutput_CanMsgReceived_Cnt_lgc(&CanMsgReceived_Cnt_T_lgc);
	Rte_Read_Ap_SrlComOutput_OutputRampMult_Uls_f32(&OutputRampMult_Uls_T_f32);

    AwakeEPS_T_str.c[0] = 0x00;
	AwakeEPS_T_str.c[1] = 0x00;
	AwakeEPS_T_str.c[2] = 0x00;
    SetBitTxAwake_NwSt(AwakeEPS_T_str);


	/* Signal - Awake Rampout */
    if((OutputRampMult_Uls_T_f32 > FLT_EPSILON) && (OutputRampMult_Uls_T_f32 < (1 - FLT_EPSILON)))
    {
    	SetBitTxAwake_Rampout(AwakeEPS_T_str);
    	SleepIndicator_Cnt_M_bit |= D_TXAWAKE_RAMPOUT_CNT_U08;
   }
    else
    {
    	ClearBitTxAwake_Rampout(AwakeEPS_T_str);
    	SleepIndicator_Cnt_M_bit &= ~D_TXAWAKE_RAMPOUT_CNT_U08;
    }

    /* Signal - VSS high */
    if((TRUE == VehSpdValid_Cnt_T_lgc) && (VehSpd_Kph_T_f32 > k_VehSpdAstLmt_Kph_f32))
    {
    	SetBitTxAwake_VSS_high(AwakeEPS_T_str);
    	SleepIndicator_Cnt_M_bit |= D_TXAWAKE_VSSHIGH_CNT_U08;
    }
    else
    {
    	ClearBitTxAwake_VSS_high(AwakeEPS_T_str);
    	SleepIndicator_Cnt_M_bit &= ~D_TXAWAKE_VSSHIGH_CNT_U08;
    }

    /* Signal - Engine RPM high */
    if((EngRPM_Cnt_T_u16 > D_ENGONRPM_CNT_U16) && (EngRPM_Cnt_T_u16 != D_ENGRPMINVLD_CNT_U16))
    {
    	SetBitTxAwake_EngRPM_high(AwakeEPS_T_str);
    	SleepIndicator_Cnt_M_bit |= D_TXAWAKE_ENGRPM_CNT_U08;
    }
    else
    {
    	ClearBitTxAwake_EngRPM_high(AwakeEPS_T_str);
    	SleepIndicator_Cnt_M_bit &= ~D_TXAWAKE_ENGRPM_CNT_U08;
    }

    /* Signal - Ignition High */
    IoHwAb_GetEpsEn(&EPSEn_Cnt_T_lgc);

	if(TRUE == EPSEn_Cnt_T_lgc)
    {
    	SetBitTxAwake_IgnHigh(AwakeEPS_T_str);
    	SleepIndicator_Cnt_M_bit |= D_TXAWAKE_IGNHIGH_CNT_U08;
    }
    else
    {
    	ClearBitTxAwake_IgnHigh(AwakeEPS_T_str);
    	SleepIndicator_Cnt_M_bit &= ~D_TXAWAKE_IGNHIGH_CNT_U08;
    }

	/*If the first can message has been received, and the timer hasn't expired, set NtSt.*/
	if((TRUE == CanMsgReceived_Cnt_T_lgc) && (FALSE == CanMsgReceived_Cnt_M_lgc))
	{
		VAR(uint32,  AUTOMATIC) ElapsedTime_mS_T_u32;
		
		Rte_Call_SystemTime_DtrmnElapsedTime_mS_u32(NMFirstMsg_mS_M_u32, &ElapsedTime_mS_T_u32);
		
		if(ElapsedTime_mS_T_u32 >= D_NMSTARTUPSLEEPDELAY_MS_U32)
		{
			CanMsgReceived_Cnt_M_lgc = TRUE;
			ClearBitTxAwake_NwSt(AwakeEPS_T_str);
	    	SleepIndicator_Cnt_M_bit &= ~D_TXAWAKE_NWST_CNT_U08;
		}
		else
		{
			SetBitTxAwake_NwSt(AwakeEPS_T_str);
		   	SleepIndicator_Cnt_M_bit |= D_TXAWAKE_NWST_CNT_U08;
		 }
	}
	else
	{
		Rte_Call_SystemTime_GetSystemTime_mS_u32(&NMFirstMsg_mS_M_u32);
		ClearBitTxAwake_NwSt(AwakeEPS_T_str);
    	SleepIndicator_Cnt_M_bit &= ~D_TXAWAKE_NWST_CNT_U08;
	}

	/*If a bus sleep was canceled within D_NMSTARTUPSLEEPDELAY_MS_U32, set the NwSt bit.*/
	if(TRUE == NMBusWaitSleepCancel_Cnt_M_lgc)
	{
		VAR(uint32,  AUTOMATIC) ElapsedTime_mS_T_u32;

		Rte_Call_SystemTime_DtrmnElapsedTime_mS_u32(NMBusWaitSleepCancel_mS_M_u32, &ElapsedTime_mS_T_u32);
		if(ElapsedTime_mS_T_u32 >= D_NMSTARTUPSLEEPDELAY_MS_U32)
		{
			NMBusWaitSleepCancel_Cnt_M_lgc = FALSE;
		}
		else
		{
			SetBitTxAwake_NwSt(AwakeEPS_T_str);
		   	SleepIndicator_Cnt_M_bit |= D_TXAWAKE_NWST_CNT_U08;
		}
	}

	nmpduPutAwake_EPS(AwakeEPS_T_str);

	if(SleepIndicator_Cnt_M_bit == D_SLEEPINDICATORCLEAR_U08)
	{
		DpmLocalRequest(DPM_EPS);
	}
	else
	{
		DpmExternalRequest(DPM_EPS);
	}

	/*Per DID A001 - EPS Internal and Bussed Signals*/
	/*These bits could be set as a single block.*/
	SrlComOutput_WriteBits(GetValueTxAwake_Diag_Actv(AwakeEPS_T_str),T_A001InternalBusSig_Cnt_u8,295u,295u);
	SrlComOutput_WriteBits(GetValueTxAwake_Rampout(AwakeEPS_T_str),T_A001InternalBusSig_Cnt_u8,294u,294u);
	SrlComOutput_WriteBits(GetValueTxAwake_VSS_high(AwakeEPS_T_str),T_A001InternalBusSig_Cnt_u8,293u,293u);
	SrlComOutput_WriteBits(GetValueTxAwake_EngRPM_high(AwakeEPS_T_str),T_A001InternalBusSig_Cnt_u8,292u,292u);
	SrlComOutput_WriteBits(GetValueTxAwake_IgnHigh(AwakeEPS_T_str),T_A001InternalBusSig_Cnt_u8,291u,291u);


	/*************************************
	 * EPS Status Message EPS_A1 - 0x12C *
	 ************************************/

	/* Signal - EPS_AsstStat */
	SysState_Cnt_T_Enum = Rte_Mode_SystemState_Mode();
	Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_AbsTempThermLimit, &AbsTempThermLimit_Cnt_T_lgc);
	Rte_Read_CTermActive_Cnt_lgc(&CTermActive_Cnt_T_lgc);
	Rte_Read_SpStPrsnt_Cnt_lgc(&SpStPrsnt_Cnt_T_lgc);

	if( SysState_Cnt_T_Enum == RTE_MODE_StaMd_Mode_OPERATE )
	{
		if (TRUE == AbsTempThermLimit_Cnt_T_lgc)
		{
		   EPSAsstStat_Cnt_T_u08 = EPSA1_AsstStat_ThrmRed; /* Assist Reduced Thermal */
		}
		else
		{
			if((TRUE == SpStPrsnt_Cnt_T_lgc) && (FALSE == CTermActive_Cnt_T_lgc))
			{
				EPSAsstStat_Cnt_T_u08 = EPSA1_AsstStat_Active; /* Assist Active */
			}
		}
	}
	else
	{
		/* Warm Init or Disabled State */
		EPSAsstStat_Cnt_T_u08 = EPSA1_AsstStat_Off; /* Assist Off */
	}

	/* Signal - EPS_WarnDisp */
	EPSWarnDispRq_Cnt_T_u08 = DetermineWarnDisp();


	/* Signal - EPS_Curr */
	Rte_Read_SupplyCurrent_Amp_f32(&SupplyCurrent_Amp_T_f32);
	EPSCurr_Cnt_T_u08 = (uint8)ScaleSignal_u16(	SupplyCurrent_Amp_T_f32, D_EPSCURR_LOLMT_AMP_F32,
												D_EPSCURR_HILMT_AMP_F32, FLOATTOFIXED_s15p0_T,
												D_SUPPLYCURROFFSET_ULS_F32);

	/*Per DID \0xA001 - EPS Internal and Bussed Signals*/
	SrlComOutput_WriteBits(EPSCurr_Cnt_T_u08,T_A001InternalBusSig_Cnt_u8,248u,255u);
	SrlComOutput_WriteBits(EPSWarnDispRq_Cnt_T_u08,	T_A001InternalBusSig_Cnt_u8,170u,172u);
	SrlComOutput_WriteBits(EPSAsstStat_Cnt_T_u08,T_A001InternalBusSig_Cnt_u8,173u,175u);
	SrlComOutput_WriteBits(0x00U,T_A001InternalBusSig_Cnt_u8,168u,169u);

	/* Update message structure */
	EPSA1_T_str.s.unused0 = 0x00;
	SetValueTxEPS_AsstStat(EPSA1_T_str, EPSAsstStat_Cnt_T_u08);
	SetValueTxEPS_Warn_Disp_Rq(EPSA1_T_str, EPSWarnDispRq_Cnt_T_u08);
	SetValueTxPS_SysType(EPSA1_T_str, 0x01U);	/* Hard Coded value of 1 per SER */
	EPSA1_T_str.s.unused1 = 0x00;
	EPSA1_T_str.s.unused2 = 0x00;

	Rte_Read_Ap_SrlComOutput_DesiredTunPersTypH_Cnt_u08(&CFG_STAT_RQ_Cnt_T_u08);
	SetValueTxEPS_MODE_CFG_STAT(EPSA1_T_str, CFG_STAT_RQ_Cnt_T_u08);

	Rte_Read_Ap_SrlComOutput_DesiredTunPers_Cnt_u16(&DesiredTunPers_Cnt_T_u16);
	SetValueTxEPS_MODE_STAT(EPSA1_T_str, DesiredTunPers_Cnt_T_u16);

	SetValueTxEPS_Curr(EPSA1_T_str, EPSCurr_Cnt_T_u08);
	EPSA1_T_str.s.unused3 = 0x00;
	EPSA1_T_str.s.unused4 = 0x00;
	EPSA1_T_str.s.unused5 = 0x00;
	EPSA1_T_str.s.unused6 = 0x00;

	/* Write final output for message EPS_A1 */
	dbkPutTxEPS_A1_PKT(EPSA1_T_str);
	
	/************************************
	 * EPS Status Message EPS_1 - 0x220 *
	 ***********************************/

	/* Signal - TOI_Act_Sts */
	Rte_Read_DSTState_Cnt_u08(&DSTState_Cnt_T_u08);
	SetValueTxTOI_Act_Sts(EPS1_M_str, DSTState_Cnt_T_u08);
	SrlComOutput_WriteBits(DSTState_Cnt_T_u08,T_A004InternalBusSig_Cnt_u8,12u,15u);
	SrlComOutput_WriteBits(0x00U,T_A004InternalBusSig_Cnt_u8,8u,11u);

	/* Signal - Steering Column Torque Valid Data */
	Rte_Read_SrlComHwTrqValid_Cnt_lgc(&SrlComHwTrqVld_Cnt_T_lgc);
	SetValueTxStrClmTrqVD(EPS1_M_str, SrlComHwTrqVld_Cnt_T_lgc);

	/* Signal - Steering Column Torque */
	if(SrlComHwTrqVld_Cnt_T_lgc == FALSE)
	{
		StrClmTrq_Cnt_T_u16 = D_STRCLMTRQ_SIGNOTAVAL_CNTS_U16;
	}
	else
	{
		Rte_Read_HwTrq_HwNm_f32(&AnaHwTorque_HwNm_T_f32);
		AnaHwTorque_HwNm_T_f32 = (AnaHwTorque_HwNm_T_f32 * ((float32)k_StrClmTrqPolarity_Cnt_s08));
		StrClmTrq_Cnt_T_u16 = ScaleSignal_u16( AnaHwTorque_HwNm_T_f32, D_STRCLMTRQLOLIMIT_HWNM_F32,
											   D_STRCLMTRQHILIMIT_HWNM_F32, FLOATTOFIXED_s8p7_T,
											   D_STRCLMTRQOFFSET_HWNM_F32);
	}
	SetValueTxStrClmTrq(EPS1_M_str, StrClmTrq_Cnt_T_u16);

	/* Signal - PTS Drive Style Sts */
	/*Rte_Read_Ap_SrlComOutput_ActiveTunSet_Cnt_u16(&ActiveTunSet_Cnt_T_u16);
	if(0U == ActiveTunSet_Cnt_T_u16) TODO TBD*/

	Rte_Read_ActiveFunctionBits_Cnt_u08(&ActiveFuncBits_Cnt_T_u08);
	if((ActiveFuncBits_Cnt_T_u08 & D_PPPAFUNCBIT_CNT_U08) == D_PPPAFUNCBIT_CNT_U08)
	{
		SetValueTxPTSDriveStyleSts(EPS1_M_str, TRUE);
		SrlComOutput_WriteBits(TRUE,T_A002InternalBusSig_Cnt_u8,5u,5u);
	}
	else
	{
		SetValueTxPTSDriveStyleSts(EPS1_M_str, FALSE);
		SrlComOutput_WriteBits(FALSE,T_A002InternalBusSig_Cnt_u8,5u,5u);
	}

	/* Signal - DST Torque Overlay Fault */
	Rte_Read_DSTState_Cnt_u08(&DSTState_Cnt_T_u08);
	if(TOCSTATE_PNA == DSTState_Cnt_T_u08  )
	{
		DSTTOIFaulted_Cnt_T_u08 = TRUE;
	}
	else
	{
		DSTTOIFaulted_Cnt_T_u08 = FALSE;
	}
	SetValueTxDSTTorqueOverlayFault(EPS1_M_str, DSTTOIFaulted_Cnt_T_u08);
	SrlComOutput_WriteBits(DSTTOIFaulted_Cnt_T_u08,T_A004InternalBusSig_Cnt_u8,53u,53u);


	/* Signal - HALF Torque Overlay Fault */
	Rte_Read_HaLFState_Cnt_u08(&HaLFState_Cnt_T_u08);
	if(HaLFState_Cnt_T_u08 == D_HALFSTATEINHIBITED_CNT_U08)
	{
		SetValueTxHALFTorqueOverlayFault(EPS1_M_str, TRUE);
		SrlComOutput_WriteBits(TRUE,T_A003InternalBusSig_Cnt_u8,3U,3U);
	}
	else
	{
		SetValueTxHALFTorqueOverlayFault(EPS1_M_str, FALSE);
		SrlComOutput_WriteBits(FALSE,T_A003InternalBusSig_Cnt_u8,3U,3U);
	}

	/* Signal - HALF Torque Overlay Inactive */
	Rte_Read_ActiveFunctionBits_Cnt_u08(&ActiveFuncBits_Cnt_T_u08);
	if((ActiveFuncBits_Cnt_T_u08 & D_HALFFUNCBIT_CNT_U08) == D_HALFFUNCBIT_CNT_U08)
	{
		SetValueTxHALFTorqueOverlayIntActivated(EPS1_M_str, TRUE);
		SrlComOutput_WriteBits(TRUE,T_A003InternalBusSig_Cnt_u8,6U,6U);
	}
	else
	{
		SetValueTxHALFTorqueOverlayIntActivated(EPS1_M_str, FALSE);
		SrlComOutput_WriteBits(FALSE,T_A003InternalBusSig_Cnt_u8,6U,6U);
	}

	/* Signal - Assistance Torque */
	Rte_Read_SumLmtTrqCmd_MtrNm_f32(&AssistanceTrq_HwNm_T_f32);
	AssistanceTrq_HwNm_T_f32 = ((AssistanceTrq_HwNm_T_f32 * k_InvGearRatio_Uls_f32) * ((float32)k_StrClmTrqPolarity_Cnt_s08));
	AssistanceTrq_HwNm_T_u16 = ScaleSignal_u16(AssistanceTrq_HwNm_T_f32, D_ASSTTRQ_LOLMT_HWNM_F32,
											D_ASSTTRQ_HILMT_HWNM_F32, D_ASSTTRQ_ENGTOCNTS_SCALE_HWNM_F32,
											D_ASSTTRQ_OFFSET_HWNM_F32);
	SetValueTxAssistanceTorque(EPS1_M_str, AssistanceTrq_HwNm_T_u16);
	SrlComOutput_WriteBits(AssistanceTrq_HwNm_T_u16,T_A002InternalBusSig_Cnt_u8,24u,39u);
	SrlComOutput_WriteBits(AssistanceTrq_HwNm_T_u16,T_A004InternalBusSig_Cnt_u8,32u,47u);

	/* Signal - DST Torque Overlay Inactive */
	Rte_Read_ActiveFunctionBits_Cnt_u08(&ActiveFuncBits_Cnt_T_u08);
	if((ActiveFuncBits_Cnt_T_u08 & D_DSTFUNCBIT_CNT_U08) == D_DSTFUNCBIT_CNT_U08)
	{
		SetValueTxDSTTorqueOverlayIntActivated(EPS1_M_str, TRUE);
	}
	else
	{
		SetValueTxDSTTorqueOverlayIntActivated(EPS1_M_str, FALSE);
	}

	/*Signal - EPSTemporaryDeactivationLDW */
	Rte_Read_HaLFSuspend_Cnt_lgc(&HaLFSuspend_Cnt_T_lgc);
	if ( TRUE == HaLFSuspend_Cnt_T_lgc)
	{
		 SetValueTxEPSTemporaryDeactivationLDW(EPS1_M_str, TRUE);
		 SrlComOutput_WriteBits(TRUE,T_A002InternalBusSig_Cnt_u8,2u,2u);
		 SrlComOutput_WriteBits(TRUE,T_A003InternalBusSig_Cnt_u8,4u,4u);
	}
	else
	{
		 SetValueTxEPSTemporaryDeactivationLDW(EPS1_M_str, FALSE);
		 SrlComOutput_WriteBits(FALSE,T_A002InternalBusSig_Cnt_u8,2u,2u);
		 SrlComOutput_WriteBits(FALSE,T_A003InternalBusSig_Cnt_u8,4u,4u);
	}

	/*Per DID 0xA001 - EPS Internal and Bussed Signals*/
	SrlComOutput_WriteBits(SrlComHwTrqVld_Cnt_T_lgc,T_A001InternalBusSig_Cnt_u8,195u,195u);
	SrlComOutput_WriteBits(0x00U,T_A001InternalBusSig_Cnt_u8,192u,194u);
	SrlComOutput_WriteBits(StrClmTrq_Cnt_T_u16,T_A001InternalBusSig_Cnt_u8,200u,215u);
	SrlComOutput_WriteBits(AssistanceTrq_HwNm_T_u16,T_A001InternalBusSig_Cnt_u8,216u,231u);

	/* Signal - EPS motor Torque Valid Data */
	Rte_Read_DiagStsRecRmpToZeroFltPres_Cnt_lgc(&RecFltActive_Cnt_T_lgc);
	Rte_Read_DiagStsNonRecRmpToZeroFltPres_Cnt_lgc(&NonRecFltActive_Cnt_T_lgc);

	if((RecFltActive_Cnt_T_lgc == TRUE) || (NonRecFltActive_Cnt_T_lgc == TRUE))
	{
		MtrTrqValid_Cnt_M_lgc = FALSE;
	}
	else
	{
		MtrTrqValid_Cnt_M_lgc = TRUE;
	}
	SetValueTxEPSMotorTorqueValidData(EPS1_M_str, MtrTrqValid_Cnt_M_lgc);
	SrlComOutput_WriteBits(MtrTrqValid_Cnt_M_lgc,T_A003InternalBusSig_Cnt_u8,2u,2u);
	SrlComOutput_WriteBits(0x00U,T_A003InternalBusSig_Cnt_u8,0u,1u);


	/* Signal - EPS motor Torque */
	Rte_Read_SumLmtTrqCmd_MtrNm_f32(&SumLimTrqCmd_MtrNM_T_f32);
	EPSMotorTrq_MtrNm_T_f32 = (SumLimTrqCmd_MtrNM_T_f32 * (float32)k_StrClmTrqPolarity_Cnt_s08);

	if(MtrTrqValid_Cnt_M_lgc == FALSE)
	{
		/* Invalid Mtr Trq */
		SetValueTxEPSMotorTorque(EPS1_M_str, D_EPSMTRTRQ_SIGNOTAVAL_CNT_U16);
		SrlComOutput_WriteBits(D_EPSMTRTRQ_SIGNOTAVAL_CNT_U16,T_A003InternalBusSig_Cnt_u8,24u,39u);
	}
	else
	{
		/* Valid Mtr Trq */
		EPSMotorTrq_MtrNm_T_u16 = ScaleSignal_u16(	EPSMotorTrq_MtrNm_T_f32, D_EPSMTRTRQ_LOLMT_MTRNM_F32,
													D_EPSMTRTRQ_HILMT_MTRNM_F32, FLOATTOFIXED_s6p9_T,
													D_EPSMTRTRQ_OFFSET_ULS_F32);
		SetValueTxEPSMotorTorque(EPS1_M_str, EPSMotorTrq_MtrNm_T_u16);
		SrlComOutput_WriteBits(EPSMotorTrq_MtrNm_T_u16,T_A003InternalBusSig_Cnt_u8,24u,39u);
	}

	/* Signal - EPS Hands On Recognition */
	Rte_Read_HandsOnDetect_Cnt_lgc(&HandsOnDetect_Cnt_T_lgc);
	SetValueTxEPSHandsOnRecognition(EPS1_M_str, HandsOnDetect_Cnt_T_lgc);
	SrlComOutput_WriteBits(HandsOnDetect_Cnt_T_lgc,T_A002InternalBusSig_Cnt_u8,46u,46u);

	/* Signal - deactivation of the PSCM Torque Overlay function */
	Rte_Read_PrkAssistSuspend_Cnt_lgc(&PASuspend_Cnt_T_lgc);
	if( TRUE == PASuspend_Cnt_T_lgc)
	{
		SetValueTxEPSTemporaryDeactivationPPPA(EPS1_M_str, TRUE);
		SrlComOutput_WriteBits(TRUE,T_A002InternalBusSig_Cnt_u8,45u,45u);

	}
	else
	{
		SetValueTxEPSTemporaryDeactivationPPPA(EPS1_M_str, FALSE);
		SrlComOutput_WriteBits(FALSE,T_A002InternalBusSig_Cnt_u8,45u,45u);
	}

	/* Signal - PTS Torque Overlay Fault */
	Rte_Read_PrkAssistState_Cnt_u08(&PAState_Cnt_T_u08);
	if(PAState_Cnt_T_u08 == D_PASTATEINHIBITED_CNT_U08) 
	{
		SetValueTxPTSTorqueOverlayFault(EPS1_M_str, TRUE);
		SrlComOutput_WriteBits(TRUE,T_A002InternalBusSig_Cnt_u8,44u,44u);
	}
	else
	{
		SetValueTxPTSTorqueOverlayFault(EPS1_M_str, FALSE);
		SrlComOutput_WriteBits(FALSE,T_A002InternalBusSig_Cnt_u8,44u,44u);
	}

	/* Signal - PTS Torque Overlay Int Activated */
	Rte_Read_ActiveFunctionBits_Cnt_u08(&ActiveFuncBits_Cnt_T_u08);
	if((ActiveFuncBits_Cnt_T_u08 & D_PPPAFUNCBIT_CNT_U08) == D_PPPAFUNCBIT_CNT_U08)
	{
		SetValueTxPTSTorqueOverlayIntActivated(EPS1_M_str, TRUE);
		SrlComOutput_WriteBits(TRUE,T_A002InternalBusSig_Cnt_u8,6u,6u);
	}
	else
	{
		SetValueTxPTSTorqueOverlayIntActivated(EPS1_M_str, FALSE);
		SrlComOutput_WriteBits(FALSE,T_A002InternalBusSig_Cnt_u8,6u,6u);
	}

	SetValueTxMC_EPS_1(EPS1_M_str, MCEPS1_Cnt_M_u08);
	CalcCRC_EPS_1();
	dbkPutTxEPS_1_PKT(EPS1_M_str);


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define RTE_STOP_SEC_AP_SRLCOMOUTPUT_APPL_CODE
#include "MemMap.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * Function: 	CalcCRC_EPS_1
 *
 * Inputs:		Pointer to EPS1_M_str
 *
 * Outputs: 	None, sets the value for the CRC byte in the message
 *
 * This function calculates the CRC for the EPS_2 message.
 **********************************************************************************************************************/
STATIC INLINE FUNC(void, AP_SRLCOMOUTPUT_CODE) CalcCRC_EPS_1( void )
		{
			VAR(uint8,  AUTOMATIC) CalculatedCRC_T_u8;
			
			EPS1_M_str.s.unused0 = D_UNUSED0MSG221_CNT_U8;
			CalculatedCRC_T_u8 = Crc_CalculateCRC8(EPS1_M_str.c, 7, D_CRCINIT_CNT_U8);
			CalculatedCRC_T_u8 ^= D_CRCXORVALUE_CNT_U8;
			SetValueTxCRC_EPS_1(EPS1_M_str, CalculatedCRC_T_u8);
		}


/**********************************************************************************************************************
 * Function: 	DetermineWarnDisp
 *
 * Inputs:		N/A
 *
 * Outputs: 	Value for signal EPSA1_WarnDisp
 *
 * This function determines the warning display value based on the current
 * customer trouble codes present on the system and the requirements defined in the
 * SER.
 *
 * Note: As of 12/15/12, this is current with the information in the NTC - CTC table in SER 02A.
 *********************************************************************************************************************/
STATIC FUNC(uint8, AP_SRLCOMOUTPUT_CODE) DetermineWarnDisp(void)
{
	/* Local Variables */
	VAR(boolean, AUTOMATIC) LgcTestVal_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) NTCFailed_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) EPSModIntFault_Cnt_T_lgc;
	VAR(uint8, AUTOMATIC) WarnDispVal_Cnt_T_u08;
	VAR(uint8, AUTOMATIC) index;

	VAR(uint8, AUTOMATIC) FinalOutput_Cnt_T_u08 = EPSA1_WarnDisp_FuncActive;

	for(index = 0; index < kFrfmNumDtc; index++)
	{
		Dem_GetEventFailed(index, &LgcTestVal_Cnt_T_lgc);

		if(LgcTestVal_Cnt_T_lgc == TRUE)
		{
			/* If the DTC matches this first group of IF statements, then final warning display value depends
			 * on which NTC set the event. */

			/* Battery Voltage faults - Function Active or Service Req'd */
			switch(index)
			{
			case FRFM_DTC_612916:
			{
				Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_ExVoltageLow, &NTCFailed_Cnt_T_lgc);
				if(NTCFailed_Cnt_T_lgc == TRUE)
				{
					WarnDispVal_Cnt_T_u08 = EPSA1_WarnDisp_FuncActive;
				}
				else
				{
					WarnDispVal_Cnt_T_u08 = EPSA1_WarnDisp_ServReqdHighPri;
				}
			}
			break;

			/* ECU Overtemp - Power Steering Overtemp or Service Power Steering */
			case FRFM_DTC_621000:
			{
				Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_DutyCycleExceeded, &NTCFailed_Cnt_T_lgc);
				if(NTCFailed_Cnt_T_lgc == TRUE)
				{
					WarnDispVal_Cnt_T_u08 = EPSA1_WarnDisp_PwrSteerOvTmp;
				}
				else
				{
					WarnDispVal_Cnt_T_u08 = EPSA1_WarnDisp_ServPwrSteer;
				}
			}
			break;

			/* EPS Module Internal - Service Power Steering or Service Req'd High Priority*/
			case FRFM_DTC_621700:
			{
				EPSModIntFault_Cnt_T_lgc = 0; /* Clear variable before starting */

				Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_Thermistor, &NTCFailed_Cnt_T_lgc);
				EPSModIntFault_Cnt_T_lgc |= NTCFailed_Cnt_T_lgc;

				Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_OnStateSingleFET, &NTCFailed_Cnt_T_lgc);
				EPSModIntFault_Cnt_T_lgc |= NTCFailed_Cnt_T_lgc;

				Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_KinematicIntDiag, &NTCFailed_Cnt_T_lgc);
				EPSModIntFault_Cnt_T_lgc |= NTCFailed_Cnt_T_lgc;

				Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_TrqSensorScaleNotSet, &NTCFailed_Cnt_T_lgc);
				EPSModIntFault_Cnt_T_lgc |= NTCFailed_Cnt_T_lgc;

				Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_TrqSensorNotTrimmed, &NTCFailed_Cnt_T_lgc);
				EPSModIntFault_Cnt_T_lgc |= NTCFailed_Cnt_T_lgc;

				if(EPSModIntFault_Cnt_T_lgc == TRUE)
				{
					WarnDispVal_Cnt_T_u08 = EPSA1_WarnDisp_ServPwrSteer;
				}
				else
				{
					WarnDispVal_Cnt_T_u08 = EPSA1_WarnDisp_ServReqdHighPri;
				}
			}
			break;
			/* Remaining checks are for other DTC values. Since they are not shared between
			 * two output values, a generic test is performed. */

			/* Warning Service Power Steering Check */
			case FRFM_DTC_55C100:
			case FRFM_DTC_621900:
			case FRFM_DTC_C00200:
			case FRFM_DTC_620600:
			{
				WarnDispVal_Cnt_T_u08 = EPSA1_WarnDisp_ServPwrSteer;
			}
			break;

			/* Service Required - High Priority */
			case FRFM_DTC_612917:
			case FRFM_DTC_D60100:
			case FRFM_DTC_55DB00:
			{
				WarnDispVal_Cnt_T_u08 = EPSA1_WarnDisp_ServReqdHighPri;
			}
			break;

			/* No addition checks for Power Steering Overtemp, that is done above */
			/* EPS Function Active */
			case FRFM_DTC_612A85:
			case FRFM_DTC_612A84:
			case FRFM_DTC_D41500:
			case FRFM_DTC_C14000:
			case FRFM_DTC_C15500:
			case FRFM_DTC_C21200:
			case FRFM_DTC_C15900:
			case FRFM_DTC_D21500:
			case FRFM_DTC_D44700:
			case FRFM_DTC_C42200:
			case FRFM_DTC_C10000:
			case FRFM_DTC_C41500:
			case FRFM_DTC_D48D00:
			case FRFM_DTC_612800:
			{
				WarnDispVal_Cnt_T_u08 = EPSA1_WarnDisp_FuncActive;
			}
			break;

			default:
			{
				WarnDispVal_Cnt_T_u08 = EPSA1_WarnDisp_FuncActive;
			}
			break;
			}
			/* Update outputs */
			if(WarnDispVal_Cnt_T_u08 == EPSA1_WarnDisp_ServReqdHighPri)
			{
				FinalOutput_Cnt_T_u08 = WarnDispVal_Cnt_T_u08;
			}

			if(WarnDispVal_Cnt_T_u08 > FinalOutput_Cnt_T_u08)
			{
				/* Update output with higher value */
				FinalOutput_Cnt_T_u08 = WarnDispVal_Cnt_T_u08;
			}
		}
	}

	return FinalOutput_Cnt_T_u08;
}

/**********************************************************************************************************************
 * Function: 	ScaleSignal_u16
 *
 * Inputs:		Signal to be scaled, Limits, Scale and offset
 *
 * Outputs: 	returns scaled and limited signal
 *
 * Scales and limits the input signal based on the passed input parameters
 *
 *********************************************************************************************************************/
STATIC FUNC(uint16, AP_SRLCOMOUTPUT_CODE) ScaleSignal_u16(	VAR(float32, AUTOMATIC) Signal_Uls_T_f32, VAR(float32, AUTOMATIC) LoLmt_Uls_T_f32,
															VAR(float32, AUTOMATIC) HiLmt_Uls_T_f32, VAR(float32, AUTOMATIC) Scale_Uls_T_f32,
															VAR(float32, AUTOMATIC) Offset_Uls_T_f32)
{
	VAR(uint16, AUTOMATIC) Signal_Cnt_T_u16;

	Signal_Uls_T_f32 = Limit_m(Signal_Uls_T_f32, LoLmt_Uls_T_f32, HiLmt_Uls_T_f32);
	Signal_Uls_T_f32 = (Signal_Uls_T_f32 + Offset_Uls_T_f32) * Scale_Uls_T_f32;
	Signal_Cnt_T_u16 = (uint16)Signal_Uls_T_f32;

	return(Signal_Cnt_T_u16);
}


/**********************************************************************************************************************
 * Function: 	EPS1_PKTConfirmation
 *
 * Inputs:		N/A
 *
 * Outputs: 	N/A
 *
 * Callback function once the message has been transmitted. The message counter
 * is increased after every successful transmission. Range is 0 to 15 and repeats.
 *
 *********************************************************************************************************************/
FUNC(void, AP_SRLCOMOUTPUT_CODE) EPS1_PKTConfirmation(void)
{
	if(TRUE == (Boolean)Conf_EPS_1_PKT)
	{
		Conf_EPS_1_PKT = FALSE;
		MCEPS1_Cnt_M_u08 = (MCEPS1_Cnt_M_u08 + 1) % D_COUNTERCYCLE16_CNT_U16;

		SetValueTxMC_EPS_1(EPS1_M_str, MCEPS1_Cnt_M_u08);
		CalcCRC_EPS_1();
		dbkPutTxEPS_1_PKT(EPS1_M_str);

	}
	return;
}

FUNC(void, AP_SRLCOMOUTPUT_CODE) ApplCclComStart(void)
{
	/*If the ECU has received messages in the past, this cannot be the first time the CCL is started.*/
	if(TRUE == CanMsgReceived_Cnt_M_lgc)
	{
		NMBusWaitSleepCancel_Cnt_M_lgc = TRUE;
		Rte_Call_SystemTime_GetSystemTime_mS_u32(&NMBusWaitSleepCancel_mS_M_u32);
	}
}

FUNC(boolean, RTE_AP_SRLCOMOUTPUT_APPL_CODE) SrlComOutput_GetMotorTorqueValid(void)
{
	return MtrTrqValid_Cnt_M_lgc;
}

/*Copied from SrlComInput*/
STATIC FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComOutput_WriteBits(uint32 Data_T_Cnt_u32, uint8* Buffer_T_Cnt_u08, uint16 StartBit_Cnt_T_u16, uint16 EndBit_Cnt_T_u16)
{

	VAR(uint16, AUTOMATIC) BufferIndex_Cnt_T_u16;
	VAR(uint8,  AUTOMATIC) ByteMask_Cnt_T_u08;
	VAR(uint8,  AUTOMATIC) TempData_Cnt_T_u08;
	VAR(uint8,  AUTOMATIC) BitsWritten_Cnt_T_u08;
	VAR(uint8,  AUTOMATIC) BitsThisByte_Cnt_T_u08;
	VAR(uint8,  AUTOMATIC) NumBits_Cnt_T_u08;
	VAR(uint16, AUTOMATIC) SwapBit_Cnt_T_u08;
	VAR(sint8,  AUTOMATIC) BitsToShift_Cnt_T_s08;

	if(StartBit_Cnt_T_u16 > EndBit_Cnt_T_u16)
	{
		SwapBit_Cnt_T_u08 = EndBit_Cnt_T_u16;
		EndBit_Cnt_T_u16 = StartBit_Cnt_T_u16;
		StartBit_Cnt_T_u16 = SwapBit_Cnt_T_u08;
	}

	BitsWritten_Cnt_T_u08 = 0U;
	NumBits_Cnt_T_u08 = (uint8)((EndBit_Cnt_T_u16 - StartBit_Cnt_T_u16) + 1U);
	BufferIndex_Cnt_T_u16 = StartBit_Cnt_T_u16 / 8U;

	while(BitsWritten_Cnt_T_u08 < NumBits_Cnt_T_u08)
	{
		ByteMask_Cnt_T_u08 = 0xFF;
		BitsThisByte_Cnt_T_u08 = 8;

		BitsToShift_Cnt_T_s08 = (sint8)(NumBits_Cnt_T_u08 - (BitsWritten_Cnt_T_u08 + 8U));

		/* Shift right when BitsToShift is positive, otherwise shift left.*/
		if(BitsToShift_Cnt_T_s08 > 0)
		{
			TempData_Cnt_T_u08 = (uint8)(Data_T_Cnt_u32 >> Abs_s16_m(BitsToShift_Cnt_T_s08));
		}
		else
		{
			TempData_Cnt_T_u08 = (uint8)(Data_T_Cnt_u32 << Abs_s16_m(BitsToShift_Cnt_T_s08));
		}

		/*If this is the first byte, shift to match the offset into the byte.*/
		if(0U == BitsWritten_Cnt_T_u08)
		{
			ByteMask_Cnt_T_u08 >>= StartBit_Cnt_T_u16 % 8U;
			TempData_Cnt_T_u08 >>= StartBit_Cnt_T_u16 % 8U;
			BitsThisByte_Cnt_T_u08 -= (uint8)(StartBit_Cnt_T_u16 % 8U);
		}


		/*If this is the last byte, shift to match the end.*/
		if(BufferIndex_Cnt_T_u16 == (EndBit_Cnt_T_u16 / 8U))
		{
			ByteMask_Cnt_T_u08 &= 0xFF << (7U - (EndBit_Cnt_T_u16 % 8U));
			BitsThisByte_Cnt_T_u08 -= (uint8)(7U - (EndBit_Cnt_T_u16 % 8U));
		}

		/*Clear the old data in the buffer.*/
		Buffer_T_Cnt_u08[BufferIndex_Cnt_T_u16] &= ~ByteMask_Cnt_T_u08;

		/*Write the new data*/
		TempData_Cnt_T_u08 &= ByteMask_Cnt_T_u08;
		Buffer_T_Cnt_u08[BufferIndex_Cnt_T_u16] |= TempData_Cnt_T_u08;

		/*Prepare for the next loop.*/
		BitsWritten_Cnt_T_u08 += BitsThisByte_Cnt_T_u08;
		BufferIndex_Cnt_T_u16++;
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
