/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Ap_LmtCod.c
 *     Workspace:  C:/cmsynergy/CBD_LmtCod_SF38/LmtCod-wz7x3j/LmtCod/autosar/Ap_LmtCod.dcf
 *     SW-C Type:  Ap_LmtCod
 *  Generated at:  Fri May 17 08:57:06 2013
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1 (Beta)
 *       License:  License CBD1010124 valid for CBD1010124 Nexteer  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  C-Code implementation template for SW-C <Ap_LmtCod>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/* Version Control:
 * Date Created:      Fri Dec  2 16:41:06 2011
 * %version:          3 %
 * %derived_by:       wz7x3j %
 * %date_modified:    Fri May 17 09:12:46 2013 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 *           1					Component creation.
 * 09/21/12  2        Selva     checkpoint added                                                              6232 
 * 05/17/13  3        BDO       Update to SF38 v002                                                           8292
 */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "Rte_Ap_LmtCod.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "Ap_LmtCod_Cfg.h"
#include "CalConstants.h"
#include "fixmath.h"
#include "fpmtype.h"
#include "GlobalMacro.h"
#include "Interpolation.h"
 
#define LMTCOD_START_SEC_VAR_CLEARED_32
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(float32, AP_LMTCOD_VAR) CurrAssistEOTGain_Uls_M_f32;
STATIC VAR(float32, AP_LMTCOD_VAR) CurrOutputRampMult_Uls_M_f32;
STATIC VAR(float32, AP_LMTCOD_VAR) CurrAssistEOTLimit_MtrNm_M_f32;
STATIC VAR(float32, AP_LMTCOD_VAR) CurrAssistStallLimit_MtrNm_M_f32;
STATIC VAR(float32, AP_LMTCOD_VAR) CurrAssistVehSpdLimit_MtrNm_M_f32;
STATIC VAR(float32, AP_LMTCOD_VAR) CurrThermalLimit_MtrNm_M_f32;

#define LMTCOD_STOP_SEC_VAR_CLEARED_32
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
 * Float: Real in interval [-FLT_MAX...FLT_MAX] with single precision (standard type)
 *
 * Enumeration Types:
 * ==================
 * FltInjectionLocType: Enumeration of integer in interval [0...255] with enumerators
 *   FLTINJ_ASSIST (1U)
 *   FLTINJ_RETURN (2U)
 *   FLTINJ_DAMPING (3U)
 *   FLTINJ_ASSTSUMNLMT (4U)
 *   FLTINJ_AVGFRICLRN (7U)
 *   FLTINJ_VECU_BATTERYVOLTAGE (8U)
 *   FLTINJ_HYSTCOMP (12U)
 *   FLTINJ_INERTIACOMP (14U)
 *   FLTINJ_EOTDAMPING_ETDMPFW (27U)
 *   FLTINJ_STABILITYCOMP (29U)
 *   FLTINJ_TRQBASEDINRTCOMP (30U)
 *   FLTINJ_SRLCOMVEHSPD_SGNLCOND (33U)
 *   FLTINJ_ASSTFIREWALL (34U)
 *   FLTINJ_ASSTEOTGAIN_LMTCOD (38U)
 *   FLTINJ_DDASTFACTRQST_DRVDYNCTRL (150U)
 *   FLTINJ_DDDMPFACTRQST_DRVDYNCTRL (151U)
 *   FLTINJ_DDRTNFACTRQST_DRVDYNCTRL (152U)
 *   FLTINJ_OUTPUTRAMPMULT_LMTCOD (153U)
 *   FLTINJ_ASSTEOTLIMIT_LMTCOD (154U)
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
 * Float: D_2MS_SEC_F32 = 0.002F
 * Float: D_MTRTRQCMDHILMT_MTRNM_F32 = 8.8F
 * Float: D_ONE_ULS_F32 = 1.0F
 * Float: D_ZERO_ULS_F32 = 0.0F
 *
 *********************************************************************************************************************/


#define RTE_START_SEC_AP_LMTCOD_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: LmtCod_Per1
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
 *   Float Rte_IRead_LmtCod_Per1_AssistEOTGain_Uls_f32(void)
 *   Float Rte_IRead_LmtCod_Per1_AssistEOTLimit_MtrNm_f32(void)
 *   Float Rte_IRead_LmtCod_Per1_AssistStallLimit_MtrNm_f32(void)
 *   Float Rte_IRead_LmtCod_Per1_AssistVehSpdLimit_MtrNm_f32(void)
 *   Float Rte_IRead_LmtCod_Per1_OutputRampMult_Uls_f32(void)
 *   Float Rte_IRead_LmtCod_Per1_ThermalLimit_MtrNm_f32(void)
 *   Float Rte_IRead_LmtCod_Per1_VehicleSpeed_Kph_f32(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_LmtCod_Per1_EOTGainLtd_Uls_f32(Float data)
 *   Float *Rte_IWriteRef_LmtCod_Per1_EOTGainLtd_Uls_f32(void)
 *   void Rte_IWrite_LmtCod_Per1_EOTLimitLtd_MtrNm_f32(Float data)
 *   Float *Rte_IWriteRef_LmtCod_Per1_EOTLimitLtd_MtrNm_f32(void)
 *   void Rte_IWrite_LmtCod_Per1_OutputRampMultLtd_Uls_f32(Float data)
 *   Float *Rte_IWriteRef_LmtCod_Per1_OutputRampMultLtd_Uls_f32(void)
 *   void Rte_IWrite_LmtCod_Per1_StallLimitLtd_MtrNm_f32(Float data)
 *   Float *Rte_IWriteRef_LmtCod_Per1_StallLimitLtd_MtrNm_f32(void)
 *   void Rte_IWrite_LmtCod_Per1_ThermalLimitLtd_MtrNm_f32(Float data)
 *   Float *Rte_IWriteRef_LmtCod_Per1_ThermalLimitLtd_MtrNm_f32(void)
 *   void Rte_IWrite_LmtCod_Per1_VehSpdLimitLtd_MtrNm_f32(Float data)
 *   Float *Rte_IWriteRef_LmtCod_Per1_VehSpdLimitLtd_MtrNm_f32(void)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_FltInjection_SCom_FltInjection(Float *SignalPath_Uls_f32, FltInjectionLocType LocationKey_Cnt_enum)
 *     Synchronous Server Invocation. Timeout: None
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_LMTCOD_APPL_CODE) LmtCod_Per1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: LmtCod_Per1
 *********************************************************************************************************************/
	VAR(float32, AUTOMATIC) AssistEOTGain_Uls_T_f32;
	VAR(float32, AUTOMATIC)	AssistEOTLimit_MtrNm_T_f32;
	VAR(float32, AUTOMATIC)	AssistStallLimit_MtrNm_T_f32;
	VAR(float32, AUTOMATIC)	AssistVehSpdLimit_MtrNm_T_f32;
	VAR(float32, AUTOMATIC)	OutputRampMult_Uls_T_f32;
	VAR(float32, AUTOMATIC)	ThermalLimit_MtrNm_T_f32;
	VAR(float32, AUTOMATIC) VehicleSpeed_Kph_T_f32;
	VAR(uint16,  AUTOMATIC) VehicleSpeed_Kph_T_u9p7;
	VAR(uint16,  AUTOMATIC) GainIncSlew_UlspS_T_u9p7;
	VAR(float32, AUTOMATIC) GainIncSlew_UlspS_T_f32;
	VAR(uint16,  AUTOMATIC) TorqueIncSlew_MtrNmpS_T_u13p3;
	VAR(float32, AUTOMATIC) TorqueIncSlew_MtrNmpS_T_f32;

    /* Configurable Start of Runnable Checkpoint */
	Rte_Call_LmtCod_Per1_CP0_CheckpointReached();
	
	AssistEOTGain_Uls_T_f32 = Rte_IRead_LmtCod_Per1_AssistEOTGain_Uls_f32();
	AssistEOTLimit_MtrNm_T_f32 = Rte_IRead_LmtCod_Per1_AssistEOTLimit_MtrNm_f32();
	AssistStallLimit_MtrNm_T_f32 = Rte_IRead_LmtCod_Per1_AssistStallLimit_MtrNm_f32();
	AssistVehSpdLimit_MtrNm_T_f32 = Rte_IRead_LmtCod_Per1_AssistVehSpdLimit_MtrNm_f32();
	OutputRampMult_Uls_T_f32 = Rte_IRead_LmtCod_Per1_OutputRampMult_Uls_f32();
	ThermalLimit_MtrNm_T_f32 = Rte_IRead_LmtCod_Per1_ThermalLimit_MtrNm_f32();
	VehicleSpeed_Kph_T_f32 = Rte_IRead_LmtCod_Per1_VehicleSpeed_Kph_f32();


	#if (STD_ON == BC_LMTCOD_FAULTINJECTIONPOINT)
	Rte_Call_FltInjection_SCom_FltInjection(&AssistEOTGain_Uls_T_f32, FLTINJ_ASSTEOTGAIN_LMTCOD);
	Rte_Call_FltInjection_SCom_FltInjection(&OutputRampMult_Uls_T_f32, FLTINJ_OUTPUTRAMPMULT_LMTCOD);
	Rte_Call_FltInjection_SCom_FltInjection(&AssistEOTLimit_MtrNm_T_f32, FLTINJ_ASSTEOTLIMIT_LMTCOD);
	#endif

	VehicleSpeed_Kph_T_u9p7 = FPM_FloatToFixed_m(VehicleSpeed_Kph_T_f32, u9p7_T);

	/* Gain Recovery Rate Limit */
	GainIncSlew_UlspS_T_u9p7 = IntplVarXY_u16_u16Xu16Y_Cnt(t_GainIncSlewTblX_Kph_u9p7,
														  t_GainIncSlewTblY_UlspS_u9p7,
														  TableSize_m(t_GainIncSlewTblX_Kph_u9p7),
														  VehicleSpeed_Kph_T_u9p7);

	GainIncSlew_UlspS_T_f32 = FPM_FixedToFloat_m(GainIncSlew_UlspS_T_u9p7, u9p7_T);


	/* Torque Recovery Rate Limit */
	TorqueIncSlew_MtrNmpS_T_u13p3 = IntplVarXY_u16_u16Xu16Y_Cnt(t_TorqueIncSlewTblX_Kph_u9p7,
														  t_TorqueIncSlewTblY_MtrNmpS_u13p3,
														  TableSize_m(t_TorqueIncSlewTblX_Kph_u9p7),
														  VehicleSpeed_Kph_T_u9p7);

	TorqueIncSlew_MtrNmpS_T_f32 = FPM_FixedToFloat_m(TorqueIncSlew_MtrNmpS_T_u13p3, u13p3_T);


	CurrAssistEOTGain_Uls_M_f32 = Limit_m(AssistEOTGain_Uls_T_f32,(CurrAssistEOTGain_Uls_M_f32 -(k_GainDecSlew_UlspS_f32*D_2MS_SEC_F32 )), (CurrAssistEOTGain_Uls_M_f32+(GainIncSlew_UlspS_T_f32*D_2MS_SEC_F32) ));
	CurrOutputRampMult_Uls_M_f32 = Limit_m(OutputRampMult_Uls_T_f32,(CurrOutputRampMult_Uls_M_f32 -(k_GainDecSlew_UlspS_f32*D_2MS_SEC_F32 )), (CurrOutputRampMult_Uls_M_f32+(GainIncSlew_UlspS_T_f32*D_2MS_SEC_F32) ));

	CurrAssistEOTLimit_MtrNm_M_f32 = Limit_m(AssistEOTLimit_MtrNm_T_f32,(CurrAssistEOTLimit_MtrNm_M_f32 -(k_TorqueDecSlew_MtrNmpS_f32*D_2MS_SEC_F32 )), (CurrAssistEOTLimit_MtrNm_M_f32+(TorqueIncSlew_MtrNmpS_T_f32*D_2MS_SEC_F32) ));
	CurrAssistStallLimit_MtrNm_M_f32 = Limit_m(AssistStallLimit_MtrNm_T_f32,(CurrAssistStallLimit_MtrNm_M_f32 -(k_TorqueDecSlew_MtrNmpS_f32*D_2MS_SEC_F32 )), (CurrAssistStallLimit_MtrNm_M_f32+(TorqueIncSlew_MtrNmpS_T_f32*D_2MS_SEC_F32) ));
	CurrAssistVehSpdLimit_MtrNm_M_f32 = Limit_m(AssistVehSpdLimit_MtrNm_T_f32,(CurrAssistVehSpdLimit_MtrNm_M_f32 -(k_TorqueDecSlew_MtrNmpS_f32*D_2MS_SEC_F32 )), (CurrAssistVehSpdLimit_MtrNm_M_f32+(TorqueIncSlew_MtrNmpS_T_f32*D_2MS_SEC_F32) ));
	CurrThermalLimit_MtrNm_M_f32 = Limit_m(ThermalLimit_MtrNm_T_f32,(CurrThermalLimit_MtrNm_M_f32 -(k_TorqueDecSlew_MtrNmpS_f32*D_2MS_SEC_F32 )), (CurrThermalLimit_MtrNm_M_f32+(TorqueIncSlew_MtrNmpS_T_f32*D_2MS_SEC_F32) ));


	Rte_IWrite_LmtCod_Per1_EOTGainLtd_Uls_f32(CurrAssistEOTGain_Uls_M_f32);
	Rte_IWrite_LmtCod_Per1_EOTLimitLtd_MtrNm_f32(CurrAssistEOTLimit_MtrNm_M_f32);
	Rte_IWrite_LmtCod_Per1_OutputRampMultLtd_Uls_f32(CurrOutputRampMult_Uls_M_f32);
	Rte_IWrite_LmtCod_Per1_StallLimitLtd_MtrNm_f32(CurrAssistStallLimit_MtrNm_M_f32);
	Rte_IWrite_LmtCod_Per1_ThermalLimitLtd_MtrNm_f32(CurrThermalLimit_MtrNm_M_f32);
	Rte_IWrite_LmtCod_Per1_VehSpdLimitLtd_MtrNm_f32(CurrAssistVehSpdLimit_MtrNm_M_f32);

    /* Configurable End of Runnable Checkpoint */
    Rte_Call_LmtCod_Per1_CP1_CheckpointReached();

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define RTE_STOP_SEC_AP_LMTCOD_APPL_CODE
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
