


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
 *          File:  Ap_VehPwrMd.c
 *     Workspace:  C:/Synergy/Chrysler_LWR_EPS_TMS570-zz4r1x/Chrysler_LWR_EPS_TMS570/SwProject/VehPwrMd/autosar
 *     SW-C Type:  Ap_VehPwrMd
 *  Generated at:  Thu Jan  3 16:14:29 2013
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1 (Beta)
 *       License:  License CBD1010124 valid for CBD1010124 Nexteer  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  C-Code implementation template for SW-C <Ap_VehPwrMd>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/* Version Control:
 * Date Created:      Wed Apr 13 12:17:00 2011
 * %version:          20 %
 * %derived_by:       sz1dx6 %
 * %date_modified:    Fri Jan 10 15:34:33 2014 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 01/24/12  1        LWW       Initial Synergy Version
 * 07/31/12	 2		  SAH		Initial Chrysler version based off SER
 * 08/12/12  3		  SAH		Updated to include def vehspd and invalid RPM logic
 * 11/12/12	 4		  SAH		Removed PwrDwn and Trans functions, they are handled in StaMds.
 * 12/19/12	 5		  SAH		Removed default vehspd input.
 * 20/17/13  6        M. Story  Anomaly 4414
 * 02/22/13  8        M. Story  Added Eng Start/stop
 * 04/12/13  9        M. Story  Anomaly 4761
 * 04/12/13 10        M. Story  CR8711 add TWaitBusSleep
 * 08/10/13 11        M. Story  Anomaly 9355
 * 10/04/13 12        M. Story  Anomaly 5589
 * 11/26/13 13        M. Story  Added Ramp Logic
 * 12/03/13 14        M. Story  Anomaly 6126
 * 12/05/13 15        M. Story  Anomaly 6131
 * 12/05/13 17        SAH		Added NMGetStatus to A term logic for 0xBF issue
 * 12/05/13 18        SAH		Updated comments and removed unused #define
 * 12/13/13 19        SAH		Removed Aterm from ramp logic
 * 01/10/14 20        M. Story  Anomaly 6206
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "Rte_Ap_VehPwrMd.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "Ap_VehPwrMd_Cfg.h"
#include "CalConstants.h"
#include "Dem.h"
#include "n_onmdef.h"
#include "Ap_DfltConfigData.h"
#include "desc.h"

#define D_ENGONRPM_CNT_U16		0x12CU
#define D_ENGRPMINVLD_CNT_U16	0xFFFFU

#define VEHPWRMD_START_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h"
STATIC VAR(boolean, AP_VEHPWRMD_VAR) CTermActive_Cnt_M_lgc;
STATIC VAR(boolean, AP_VEHPWRMD_VAR) CTermRampedDown_Cnt_M_lgc;
#define VEHPWRMD_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h"

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
 *
 * Enumeration Types:
 * ==================
 * EcuM_StateType: Enumeration of integer in interval [16...255] with enumerators
 *   ECUM_STATE_STARTUP (16U)
 *   ECUM_STATE_STARTUP_ONE (17U)
 *   ECUM_STATE_STARTUP_TWO (18U)
 *   ECUM_STATE_WAKEUP (32U)
 *   ECUM_STATE_WAKEUP_ONE (33U)
 *   ECUM_STATE_WAKEUP_VALIDATION (34U)
 *   ECUM_STATE_WAKEUP_REACTION (35U)
 *   ECUM_STATE_WAKEUP_TWO (36U)
 *   ECUM_STATE_WAKEUP_WAKESLEEP (37U)
 *   ECUM_STATE_WAKEUP_TTII (38U)
 *   ECUM_STATE_RUN (48U)
 *   ECUM_STATE_APP_RUN (50U)
 *   ECUM_STATE_APP_POST_RUN (51U)
 *   ECUM_STATE_SHUTDOWN (64U)
 *   ECUM_STATE_PREP_SHUTDOWN (68U)
 *   ECUM_STATE_GO_SLEEP (73U)
 *   ECUM_STATE_GO_OFF_ONE (77U)
 *   ECUM_STATE_GO_OFF_TWO (78U)
 *   ECUM_STATE_SLEEP (80U)
 *   ECUM_STATE_OFF (128U)
 *   ECUM_STATE_RESET (144U)
 *   ECUM_STATE_ERROR (255U)
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
 * Float: D_ONE_ULS_F32 = 1.0F
 * Float: D_ZERO_ULS_F32 = 0.0F
 * UInt16: D_ONE_CNT_U16 = 1U
 *
 *********************************************************************************************************************/


#define RTE_START_SEC_AP_VEHPWRMD_APPL_CODE
#include "MemMap.h"

/**********************************************************************************************************************
 *
 * Runnable Entity Name: VehPwrMd_Init1
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
 *   void Rte_IWrite_VehPwrMd_Init1_OperRampRate_XpmS_f32(Float data)
 *   Float *Rte_IWriteRef_VehPwrMd_Init1_OperRampRate_XpmS_f32(void)
 *   void Rte_IWrite_VehPwrMd_Init1_OperRampValue_Uls_f32(Float data)
 *   Float *Rte_IWriteRef_VehPwrMd_Init1_OperRampValue_Uls_f32(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_VEHPWRMD_APPL_CODE) VehPwrMd_Init1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: VehPwrMd_Init1
 *********************************************************************************************************************/
	Rte_IWrite_VehPwrMd_Init1_OperRampRate_XpmS_f32(k_RampDnRt_UlspmS_f32);
	Rte_IWrite_VehPwrMd_Init1_OperRampValue_Uls_f32(D_ZERO_ULS_F32);
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: VehPwrMd_Per1
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
 *   Boolean Rte_IRead_VehPwrMd_Per1_DefaultVehSpd_Cnt_lgc(void)
 *   Boolean Rte_IRead_VehPwrMd_Per1_EngONSrlComSvcDft_Cnt_lgc(void)
 *   UInt16 Rte_IRead_VehPwrMd_Per1_EngRPM_Cnt_u16(void)
 *   Boolean Rte_IRead_VehPwrMd_Per1_EssEngStop_Cnt_lgc(void)
 *   Boolean Rte_IRead_VehPwrMd_Per1_SpStPrsnt_Cnt_lgc(void)
 *   Boolean Rte_IRead_VehPwrMd_Per1_VehSpdValid_Cnt_lgc(void)
 *   Float Rte_IRead_VehPwrMd_Per1_VehSpd_Kph_f32(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_VehPwrMd_Per1_ATermActive_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_VehPwrMd_Per1_ATermActive_Cnt_lgc(void)
 *   void Rte_IWrite_VehPwrMd_Per1_CTermActive_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_VehPwrMd_Per1_CTermActive_Cnt_lgc(void)
 *   void Rte_IWrite_VehPwrMd_Per1_OperRampRate_XpmS_f32(Float data)
 *   Float *Rte_IWriteRef_VehPwrMd_Per1_OperRampRate_XpmS_f32(void)
 *   void Rte_IWrite_VehPwrMd_Per1_OperRampValue_Uls_f32(Float data)
 *   Float *Rte_IWriteRef_VehPwrMd_Per1_OperRampValue_Uls_f32(void)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_EpsEn_OP_GET(IoHwAb_BoolType *signal)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EpsEn_E_NOT_OK
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_VEHPWRMD_APPL_CODE) VehPwrMd_Per1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: VehPwrMd_Per1
 *********************************************************************************************************************/


	VAR(boolean, AUTOMATIC) EngONSrlComSvcDft_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) EPSEn_Cnt_T_lgc;
	VAR(float32, AUTOMATIC) OperRampRate_XpmS_T_f32;
	VAR(float32, AUTOMATIC) OperRampValue_Uls_T_f32;
	VAR(boolean, AUTOMATIC) ATermActive_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) VehSpdValid_Cnt_T_lgc;
	VAR(float32, AUTOMATIC) VehSpd_Kph_T_f32;
	VAR(uint16, AUTOMATIC) EngRPM_Cnt_T_u16;
	VAR(boolean, AUTOMATIC)	EssEngStop_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) SpStPrsnt_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) RampDown_Cnt_T_lgc;
	VAR(NmStatusType, AUTOMATIC) NMState_Cnt_T_u8;
	
	/* Configurable Start of Runnable Checkpoint */
	Rte_Call_VehPwrMd_Per1_CP0_CheckpointReached();

	EngONSrlComSvcDft_Cnt_T_lgc = Rte_IRead_VehPwrMd_Per1_EngONSrlComSvcDft_Cnt_lgc();
	EngRPM_Cnt_T_u16 = Rte_IRead_VehPwrMd_Per1_EngRPM_Cnt_u16();
	Rte_Call_EpsEn_OP_GET(&EPSEn_Cnt_T_lgc);
	VehSpdValid_Cnt_T_lgc = Rte_IRead_VehPwrMd_Per1_VehSpdValid_Cnt_lgc();
	VehSpd_Kph_T_f32 = Rte_IRead_VehPwrMd_Per1_VehSpd_Kph_f32();
	EssEngStop_Cnt_T_lgc = Rte_IRead_VehPwrMd_Per1_EssEngStop_Cnt_lgc();
	SpStPrsnt_Cnt_T_lgc = Rte_IRead_VehPwrMd_Per1_SpStPrsnt_Cnt_lgc();
	NMState_Cnt_T_u8 = NmGetStatus();
	
	/* A Bit Logic */
	if ((FALSE == EPSEn_Cnt_T_lgc) &&
			((TRUE == DPMShutDownState_Cnt_lgc)||
					(kDescStateSessionNexteer_Mode == DescGetStateSession()) ||
					(kDescStateSessionExtendedDiagnostic == DescGetStateSession()) ||
										(FALSE == (NmStateRingStable( NMState_Cnt_T_u8 )))))
	{
		ATermActive_Cnt_T_lgc = FALSE;
	}
	else
	{
		ATermActive_Cnt_T_lgc = TRUE;
	}

	/* C Bit Logic */
	/* Ramp Logic */

	/* C Bit Logic */
	if(TRUE == EngONSrlComSvcDft_Cnt_T_lgc)
	{
		CTermActive_Cnt_M_lgc = TRUE;
	}
	else /* Engine On defeat service is disabled.*/
	{
		/* Ramp using Start/Stop per ESS_ENG_ST */
		if(TRUE == SpStPrsnt_Cnt_T_lgc)
		{
			if((TRUE == CTermActive_Cnt_M_lgc) &&
					(TRUE == EssEngStop_Cnt_T_lgc) &&
					((TRUE == VehSpdValid_Cnt_T_lgc) && (VehSpd_Kph_T_f32 <= k_VehSpdAstLmt_Kph_f32)) &&
					((EngRPM_Cnt_T_u16 < D_ENGONRPM_CNT_U16) && (EngRPM_Cnt_T_u16 != D_ENGRPMINVLD_CNT_U16)))
			{
				CTermRampedDown_Cnt_M_lgc = TRUE;
				CTermActive_Cnt_M_lgc = FALSE;
			}

			/*Assist has not been ramped down
			 * Determine if it should be ramped up based on the Customer Vector Definition.*/
			if(FALSE == CTermRampedDown_Cnt_M_lgc)
			{
				if((TRUE == EPSEn_Cnt_T_lgc) &&
						((EngRPM_Cnt_T_u16 >= D_ENGONRPM_CNT_U16) && (EngRPM_Cnt_T_u16 != D_ENGRPMINVLD_CNT_U16)))
				{
					CTermActive_Cnt_M_lgc = TRUE;
				}
			}
			/*Assist has been ramped down per ESS_ENG_ST
			 * Determine when to ramp up using the requirements for that signal.*/
			else
			{
				if((FALSE == EssEngStop_Cnt_T_lgc) ||
					(FALSE == VehSpdValid_Cnt_T_lgc) ||
					(VehSpd_Kph_T_f32 > k_VehSpdAstLmt_Kph_f32) ||
					((EngRPM_Cnt_T_u16 >= D_ENGONRPM_CNT_U16) &&
					(EngRPM_Cnt_T_u16 != D_ENGRPMINVLD_CNT_U16)))
				{
					CTermActive_Cnt_M_lgc = TRUE;
				}
			}
		}
		else /*Ramp without Start/Stop per Customer Vector Definition*/
		{
			if((TRUE == EPSEn_Cnt_T_lgc) &&
					(( (TRUE == VehSpdValid_Cnt_T_lgc) &&
						(VehSpd_Kph_T_f32 > k_VehSpdAstLmt_Kph_f32)) ||
						((EngRPM_Cnt_T_u16 >= D_ENGONRPM_CNT_U16)
						&& (EngRPM_Cnt_T_u16 != D_ENGRPMINVLD_CNT_U16))) )
			{
				CTermActive_Cnt_M_lgc = TRUE;
			}

			if((FALSE == EPSEn_Cnt_T_lgc) &&
					((EngRPM_Cnt_T_u16 < D_ENGONRPM_CNT_U16) || (EngRPM_Cnt_T_u16 == D_ENGRPMINVLD_CNT_U16)) &&
					((VehSpd_Kph_T_f32 < k_VehSpdAstLmt_Kph_f32) || (FALSE == VehSpdValid_Cnt_T_lgc)))
			{
				CTermActive_Cnt_M_lgc = FALSE;
			}
		}
	}

	/* Ramp Logic */
	/* TODO: Implement Proper Ramping logic once it is clarified in SER */
	if (FALSE == CTermActive_Cnt_M_lgc)
	{
		OperRampRate_XpmS_T_f32 = k_RampDnRt_UlspmS_f32;
		OperRampValue_Uls_T_f32 = D_ZERO_ULS_F32;
	}
	else
	{
		OperRampRate_XpmS_T_f32 = k_RampUpRtLoSpd_UlspmS_f32;
		OperRampValue_Uls_T_f32 = D_ONE_ULS_F32;
	}
	
	Rte_IWrite_VehPwrMd_Per1_OperRampRate_XpmS_f32(OperRampRate_XpmS_T_f32);
	Rte_IWrite_VehPwrMd_Per1_OperRampValue_Uls_f32(OperRampValue_Uls_T_f32);
 	
	Rte_IWrite_VehPwrMd_Per1_ATermActive_Cnt_lgc(ATermActive_Cnt_T_lgc);
	Rte_IWrite_VehPwrMd_Per1_CTermActive_Cnt_lgc(CTermActive_Cnt_M_lgc);
	
	/* Configurable End of Runnable Checkpoint */
	Rte_Call_VehPwrMd_Per1_CP1_CheckpointReached();
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define RTE_STOP_SEC_AP_VEHPWRMD_APPL_CODE
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
