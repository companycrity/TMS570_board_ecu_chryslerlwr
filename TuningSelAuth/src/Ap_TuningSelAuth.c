/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Ap_TuningSelAuth.c
 *     Workspace:  C:/Synergy/TuningSelAuth-zz4r1x/TuningSelAuth/autosar
 *     SW-C Type:  Ap_TuningSelAuth
 *  Generated at:  Wed Oct 24 15:52:59 2012
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nexteer  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  C-Code implementation template for SW-C <Ap_TuningSelAuth>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/* Version Control:
 * Date Created:      Tue Jul 3 10:05:09 2012
 * %version:          4 %
 * %derived_by:       zz4r1x %
 * %date_modified:    Wed Oct 24 15:55:08 2012 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 07/03/12  1        VK        Initial component based design release for FDD SF-23 v001						5793 
 * 07/27/12  1        LWW       Updates for performing tuning selection
 * 09/23/12  3        Selva      Checkpoints added and mempmap macros corrected		                          6252
 * 10/24/12  4        BWL       Update trigger rates                                                          6625
 */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "Rte_Ap_TuningSelAuth.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "CalConstants.h"
#include "filters.h"
#include "GlobalMacro.h"
#include "Ap_TuningSelAuth_Cfg.h"

#define D_10MS_SEC_F32				0.010F

/* Module Internal Variables */
#define TUNINGSELAUTH_START_SEC_VAR_CLEARED_16
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(uint16, AP_TUNINGSELAUTH_VAR_NOINIT) PrevTunSet_Cnt_M_u16;
STATIC VAR(uint16, AP_TUNINGSELAUTH_VAR_NOINIT) PrevTunPers_Cnt_M_u16;
#define TUNINGSELAUTH_STOP_SEC_VAR_CLEARED_16
#include "MemMap.h" /* PRQA S 5087 */

#define TUNINGSELAUTH_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(LPF32KSV_Str, AP_TUNINGSELAUTH_VAR_NOINIT) HwTrqLPFiltSV_HwNm_M_str;
#define TUNINGSELAUTH_STOP_SEC_VAR_CLEARED_UNSPECIFIED
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
 * Float: D_ZERO_ULS_F32 = 0
 * UInt16: D_ZERO_CNT_U16 = 0u
 *
 *********************************************************************************************************************/


#define RTE_START_SEC_AP_TUNINGSELAUTH_APPL_CODE
#include "MemMap.h"

/**********************************************************************************************************************
 *
 * Runnable Entity Name: TuningSelAuth_Init1
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
 *   UInt16 Rte_IRead_TuningSelAuth_Init1_DesiredTunPers_Cnt_u16(void)
 *   UInt16 Rte_IRead_TuningSelAuth_Init1_DesiredTunSet_Cnt_u16(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_TuningSelAuth_Init1_ActiveTunPers_Cnt_u16(UInt16 data)
 *   UInt16 *Rte_IWriteRef_TuningSelAuth_Init1_ActiveTunPers_Cnt_u16(void)
 *   void Rte_IWrite_TuningSelAuth_Init1_ActiveTunSet_Cnt_u16(UInt16 data)
 *   UInt16 *Rte_IWriteRef_TuningSelAuth_Init1_ActiveTunSet_Cnt_u16(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_TUNINGSELAUTH_APPL_CODE) TuningSelAuth_Init1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: TuningSelAuth_Init1
 *********************************************************************************************************************/
	VAR(uint16, AUTOMATIC) DesiredTunPers_Cnt_T_u16;
	VAR(uint16, AUTOMATIC) DesiredTunSet_Cnt_T_u16;

	DesiredTunPers_Cnt_T_u16 = Rte_IRead_TuningSelAuth_Init1_DesiredTunPers_Cnt_u16();
	DesiredTunSet_Cnt_T_u16 = Rte_IRead_TuningSelAuth_Init1_DesiredTunSet_Cnt_u16();

	if (DesiredTunPers_Cnt_T_u16 >= TableSize_m(T_TunPersSelectionTbl_Ptr_Str[0]))
	{
		DesiredTunPers_Cnt_T_u16 = 0U;
	}

	if (DesiredTunSet_Cnt_T_u16 >= TableSize_m(T_TunSetSelectionTbl_Ptr_Str))
	{
		DesiredTunSet_Cnt_T_u16 = 0U;
	}

	TunPer_Ptr_Str = T_TunPersSelectionTbl_Ptr_Str[DesiredTunSet_Cnt_T_u16][DesiredTunPers_Cnt_T_u16];
	TunSet_Ptr_Str = T_TunSetSelectionTbl_Ptr_Str[DesiredTunSet_Cnt_T_u16];
	
	Rte_IWrite_TuningSelAuth_Init1_ActiveTunPers_Cnt_u16(DesiredTunPers_Cnt_T_u16);
	Rte_IWrite_TuningSelAuth_Init1_ActiveTunSet_Cnt_u16(DesiredTunSet_Cnt_T_u16);
	
	PrevTunPers_Cnt_M_u16 = DesiredTunPers_Cnt_T_u16;
	PrevTunSet_Cnt_M_u16 = DesiredTunSet_Cnt_T_u16;

	/* Low pass filter init */
	LPF_KUpdate_f32_m(k_TunSelHwTrqLPFKn_Hz_f32, D_10MS_SEC_F32, &HwTrqLPFiltSV_HwNm_M_str);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: TuningSelAuth_Per1
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
 *   UInt16 Rte_IRead_TuningSelAuth_Per1_DesiredTunPers_Cnt_u16(void)
 *   UInt16 Rte_IRead_TuningSelAuth_Per1_DesiredTunSet_Cnt_u16(void)
 *   Float Rte_IRead_TuningSelAuth_Per1_HwTorque_HwNm_f32(void)
 *   Float Rte_IRead_TuningSelAuth_Per1_VehicleSpeed_Kph_f32(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_TuningSelAuth_Per1_ActiveTunPers_Cnt_u16(UInt16 data)
 *   UInt16 *Rte_IWriteRef_TuningSelAuth_Per1_ActiveTunPers_Cnt_u16(void)
 *   void Rte_IWrite_TuningSelAuth_Per1_ActiveTunSet_Cnt_u16(UInt16 data)
 *   UInt16 *Rte_IWriteRef_TuningSelAuth_Per1_ActiveTunSet_Cnt_u16(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_TUNINGSELAUTH_APPL_CODE) TuningSelAuth_Per1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: TuningSelAuth_Per1
 *********************************************************************************************************************/

	VAR(float32, AUTOMATIC) HwTorque_HwNm_T_f32;
	VAR(float32, AUTOMATIC) VehicleSpeed_Kph_T_f32;
	VAR(float32, AUTOMATIC) HwTorqueFilt_HwNm_T_f32;
	VAR(uint16, AUTOMATIC) DesiredTunPers_Cnt_T_u16;
	VAR(uint16, AUTOMATIC) DesiredTunSet_Cnt_T_u16;
    /* Configurable Start of Runnable Checkpoint */
	Rte_Call_TuningSelAuth_Per1_CP0_CheckpointReached();

	DesiredTunPers_Cnt_T_u16 = Rte_IRead_TuningSelAuth_Per1_DesiredTunPers_Cnt_u16();
	DesiredTunSet_Cnt_T_u16 = Rte_IRead_TuningSelAuth_Per1_DesiredTunSet_Cnt_u16();
	HwTorque_HwNm_T_f32 = Rte_IRead_TuningSelAuth_Per1_HwTorque_HwNm_f32();
	VehicleSpeed_Kph_T_f32 = Rte_IRead_TuningSelAuth_Per1_VehicleSpeed_Kph_f32();

	HwTorqueFilt_HwNm_T_f32 = LPF_OpUpdate_f32_m(HwTorque_HwNm_T_f32, &HwTrqLPFiltSV_HwNm_M_str);

	if ((Abs_f32_m(HwTorqueFilt_HwNm_T_f32) <= k_TunSelHwTrqThresh_HwNm_f32) && (VehicleSpeed_Kph_T_f32 <= k_TunSelVehSpdThresh_Kph_f32))
	{
		if (DesiredTunPers_Cnt_T_u16 >= TableSize_m(T_TunPersSelectionTbl_Ptr_Str[0]))
		{
			DesiredTunPers_Cnt_T_u16 = PrevTunPers_Cnt_M_u16;
		}

		if (DesiredTunSet_Cnt_T_u16 >= TableSize_m(T_TunSetSelectionTbl_Ptr_Str))
		{
			DesiredTunSet_Cnt_T_u16 = PrevTunSet_Cnt_M_u16;
		}

		TunPer_Ptr_Str = T_TunPersSelectionTbl_Ptr_Str[DesiredTunSet_Cnt_T_u16][DesiredTunPers_Cnt_T_u16];
		TunSet_Ptr_Str = T_TunSetSelectionTbl_Ptr_Str[DesiredTunSet_Cnt_T_u16];

		Rte_IWrite_TuningSelAuth_Per1_ActiveTunPers_Cnt_u16(DesiredTunPers_Cnt_T_u16);
		Rte_IWrite_TuningSelAuth_Per1_ActiveTunSet_Cnt_u16(DesiredTunSet_Cnt_T_u16);

		PrevTunPers_Cnt_M_u16 = DesiredTunPers_Cnt_T_u16;
		PrevTunSet_Cnt_M_u16 = DesiredTunSet_Cnt_T_u16;
	}
	else
	{
		Rte_IWrite_TuningSelAuth_Per1_ActiveTunPers_Cnt_u16(PrevTunPers_Cnt_M_u16);
		Rte_IWrite_TuningSelAuth_Per1_ActiveTunSet_Cnt_u16(PrevTunSet_Cnt_M_u16);
	}
    /* Configurable End of Runnable Checkpoint */
    Rte_Call_TuningSelAuth_Per1_CP1_CheckpointReached();

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define RTE_STOP_SEC_AP_TUNINGSELAUTH_APPL_CODE
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
