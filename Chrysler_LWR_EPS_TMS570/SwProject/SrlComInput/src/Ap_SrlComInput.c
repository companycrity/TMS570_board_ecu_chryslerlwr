


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
 *          File:  Ap_SrlComInput.c
 *     Workspace:  C:/Documents and Settings/sz1dx6/My Documents/Synergy/ccm_wa/sz1dx61/Chrysler_LWR_EPS_TMS570/SwProject/SrlComInput/autosar
 *     SW-C Type:  Ap_SrlComInput
 *  Generated at:  Fri Apr 26 14:25:24 2013
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1 (Beta)
 *       License:  License CBD1010124 valid for CBD1010124 Nexteer  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  C-Code implementation template for SW-C <Ap_SrlComInput>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/* Version Control:
 * Date Created:      Wed Jul 18 12:17:00 2012
 * %version:          79.1.4 %
 * %date_modified:    Thu Mar  6 10:17:04 2014 %
 * %date_modified:    Thu Mar  6 10:17:04 2014 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 07/18/12  1        BG        Initial Version
 * 08/09/12  2        SAH       CMS and NTC updates
 * 09/21/12  3        OT        Anomaly 3814
 * 09/22/12  4        OT        Clean up, apply offset and gain to all signals
 * 09/24/12  5        OT        Change to direct read/write for all inputs/outputs
 * 10/05/12	 6		  SAH		Update EngRPM signal value when message is missing.
 * 12/19/12	 10		  BWL		CanMsgReceived signal for Network Managment									6968
 * 12/19/12	 10		  BWL		Add missing "global" variables.												6968
 *                    M. Story  Updated to SER LWR24989 version 002B
 * 01/05/13	 15		  SAH		Added desired tun set and pers as outputs
 * 01/10/13  16		  BWL		Updates to try to get closer to the SER
 * 01/11/13  17		  SR		Clear Reset response required flag in Init function if it is set & QAC fixes.   7074
 * 01/23/13  18       M. Story  Bench test fixes
 * 01/23/13  19       BWL       Moved reset response to appdesc												7128
 * 02/17/13  20       M. Story  Changes for release 02.00.07. Anomaly 4424, 4423, 4389, 4408, 4401
 * 02/20/13  21       M. Story  Anomaly 4461
 * 02/21/13  22       M. Story  Anomaly fixes for 02.00.07
 * 02/21/13  23       M. Story  Moved type H decloration
 * 02/22/13  23       DD		Slew function for DST, PA, and HaLF - NTC18C 18D 18E 18F - Cleanup
 * 02/25/13  24       M. Story  Anomaly 4510
 * 03/05/13  26       M. Story  Anomaly 4543 ESP_A5 WhlPlsCnt_RR never sets true
 * 03/15/13  27       M. Story  Anomaly 4552 NTC 199 should be set when Park Assist state indicates ACTIVE, 4532, 4531
 * 04/12/13  28		  Srikanth  Anomaly 4757 Alligning DID A001,Anomaly 4769 - IWSS_CalcVSpd calculation		CR7798
 * 04/15/13  29       M. Story  Anomaly 4761 VehSpdValid incorrect                                              CR7838
 * 04/18/13  30       M. Story  Anomaly 4803                                                                    CR7934
 * 04/29/13  31       M. Story  Updates for ver 03.00.00 SER 3B
 * 05/02/13  32       SAH 	 	Integration updates for NTCFailed calls
 * 05/03/13  33       M. Story  Modify Tuning Select in 0x3f5
 * 05/06/13  34       M. Story  Updates for 03.0.01
 * 05/29/13  35       M. Story  Updates for 03.0.02
 * 06/14/13  37       M. Story  Updates for 03.0.03
 * 06/14/13  38       M. Story  Updates for 03.0.04
 * 06/14/13  39       M. Story  Updates for Anomaly 5189
 * 07/09/13  41       M. Story  Updates for Anomaly 5197
 * 07/11/13  42       M. Story  Added Manual VehSpeed Scom function
 * 07/12/13  43       M. Story  Removed slew functionality
 * 07/17/13  44       M. Story  Anomaly 5245
 * 07/25/13  45       M. Story  Anomaly 4603
 * 07/30/13  46       M. Story  Anomaly 5266
 * 07/31/13  47       M. Story  Anomaly 5339, 5324
 * 08/01/13  48       JJW       Added checpoints, corrected Crc.h include typo whihc was incorrectly including the 
 *                              peripheral register defs instead of the Autosar Crc BSW API's
 * 08/01/13	 49		  SAH		Removed NetCfg logic from default veh spd processing.
 * 08/02/13  50       M. Story  Anomaly 5269, 5356, 5357, 5359, 5358
 * 08/05/13  51       M. Story  Anomaly 5373, 5324, 5390, 4223,
 * 08/13/13	 52		  SAH 		Added suspend and resume interrupts around writing of vehspd and vehspd valid
 * 08/19/13	 53		  M. Story  Anomaly 5431,5420
 * 08/19/13	 55		  M. Story  Anomaly 5405, 5420, 5431, 5434, 5446, 5459, 5460, 5476, 5474, 5474 ,5477, 5478, 5479
 * 09/16/13  56       M. Story  Anomaly 4749, 4699, 4701, 4700
 * 09/25/13  57       M. Story  Changes for release 01.00.01
 * 10/04/13  58       M. Story  Changes for 01.00.02
 * 10/08/13  59       NRAR      Changes made to all NTC's as per Anom 5463, 5464,5468,5465,5673,5674,5675,5682
 * 10/10/13  60       M. Story  Anomnalies 5716, 5768, 5818, 5819
 * 11/10/13  61       NRAR      Somemore changes made to NTC's 18C,D,E,F,188 along with the changes done in Ver 59
 * 14/10/13  62       NRAR      NTC189 set to PASSED when DSTFuncPresent is FALSE
 * 22/10/13  63,64    NRAR      NTC's fixed
 * 10/22/13  65		  SAH		Updated the MEC input used in VehSpd message
 * 11/04/13  66       M. Story  Updated Tuning select.
 * 11/07/13  67       M. Story  ODO anomaly fix
 * 11/08/13  68       NRAR      Fixes for DST and HALT NTC's
 * 11/20/13  69       M. Story  Updates for L 02.00.00 and WR 01,00,04
 * 11/22/13  70       NRAR      Anom 6037 fixes and corrected NTC's 18a, 18b
 * 11/25/13  71       M. STory  Anomaly 6093 Half torq polarity
 * 01/05/13  72       M. Story  Corrected VIN odometer anomaly 6128
 * 01/08/14  73       M. Story  Anomaly 6192, 6193
 * 01/10/14  74       M. Story QAC fix
 * 01/14/14  75       M. Story Anomalies 6207 6209
 * 02/04/14  76       M. Story SER 7A updates
 * 02/04/14  77       M. Story Anomaly 6342
 * 02/20/14  78       M. Story Anomalies 6355, 6358, 6364, 6365, 6366, 6386, 6388.
 * 03/05/14  79       M. Story Anomalies 6434, 6436
 * 04/29/14  79.1.1   M. Story QAC fixes
 * 05/12/14  79.1.2   SAH	   Updates to NTCs E9 and 194
 * 05/20/14  79.1.3   SAH	   Added PrevHaLFTrqOvRqst and PrevHaLFEnableRqst global outputs
 * 08/26/14  79.1.4   SAH	   Updated NTC 0x1DF to clear bit from HaLFErrInterfaceActive_Cnt_M_bit when a message is received.
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
  Volt_f32 of Port Interface Vecu_Volt_f32
    This port prototype is inteded to communicate voltage signals that represent the ecu supplied voltage.  This signal has a lower limit, which is non-zero, to allow users of the signal to use it as a denominator in an expression without requiring a divide by 0 check.


 Operation Prototypes:
 =====================
  DtrmnElapsedTime_mS_u16 of Port Interface SystemTime
    Nexteer SystemTime Service

 *********************************************************************************************************************/

/* PRQA S 759 EOF */
/* PRQA S 3200 EOF */
/* PRQA S 3138 EOF */ /* Csused by supplied macro calls to Vector code */

#include "Rte_Ap_SrlComInput.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "Ap_SrlComInput_Cfg.h"

#include "v_inc.h"
#include "fixmath.h"
#include "CalConstants.h"
#include "GlobalMacro.h"
#include "string.h"
#include "Ap_DfltConfigData.h"
#include "Crc.h"
#include "Rte_Type.h"
#include "desc.h"
#include "math.h"
#include "ApplCallbacks.h"
#include "Os.h"
#include <float.h>
#include "EPS_DiagSrvcs_SrvcLUTbl.h"

#define D_TUNNINGSETOFFSET_CNT_U16			0x1EU

#define D_CRCINIT_CNT_U8					0xFFu
#define D_CRCXORVALUE_CNT_U8				0xFFu
#define D_COUNTERCYCLE16_CNT_U16			0x10u

#define D_VEHSPEEDNOTAVAILABLE_CNT_U16		0xFFFFu
#define D_VEHSPEEDSCALE_KPH_F32				0.0078125f
#define D_LRWSCALE_HWDEG_F32				0.5f
#define D_LRWOFFSET_HWDEG_F32				2048.0f
#define D_LRWRHPSCALE_HWDEG_F32				0.1f
#define D_LRWRHPOFFSET_HWDEG_F32			0.4f
#define D_TORQOVERLAYSTRREQOFF_CNT_F32  	8.0f
#define D_MTRTORQOVERLAYSTRREQ_CNT_F32      2.0f
#define D_LRWOFF_CNT_F32 					2048.0f
#define D_LRWRHPOFF_CNT_F32 				0.4f
#define D_TOREQOFF_CNT_F32 				    8.0f
#define D_VEHCFGSTATPROG_CNT_U16            0x01u
#define D_IWSSALCVSPD_CNT_F32				(3.6f/k_IWSSVSpdConst_Cnt_f32)
#define D_VEHCFG4STATPROG_CNT_U16			1U
#define D_NETCFGSTATPROG_CNT_U16			1U
#define D_ECUCFGSTATPROG_CNT_U16			1U
#define D_ODOSCALE_CNT_F32					((float32).1)
#define D_INVALIDODO_U32					0x00FFFFFFU

#define D_MTRTQOVLYSTRREQRES_f32			0.001953125f

/* List of flags for Half and DST Fault active */
#define D_SYSFLTACTNTCCLR_CNT_U16			0x0000U

#define D_SYSFLTACTNTC13A_CNT_U16			(0x0001U   << 	0)		/* VehSpd NTC */
#define D_SYSFLTACTNTC13B_CNT_U16			(0x0001U   << 	1)
#define D_SYSFLTACTNTC192_CNT_U16			(0x0001U   << 	2)		/* Half  NTC */
#define D_SYSFLTACTNTC194_CNT_U16			(0x0001U   << 	3)
#define D_SYSFLTACTNTC193_CNT_U16			(0x0001U   << 	4)
#define D_SYSFLTACTNTC195_CNT_U16			(0x0001U   << 	5)
#define D_SYSFLTACTNTC196_CNT_U16			(0x0001U   << 	6)
#define D_SYSFLTACTNTC1C6_CNT_U16			(0x0001U   << 	7)

#define D_SYSFLTACTNTC19A_CNT_U16			(0x0001U   << 	8)	/* Park ASSIST Torque Overlay NTC */
#define D_SYSFLTACTNTC19B_CNT_U16			(0x0001U   << 	9)
#define D_SYSFLTACTNTC19C_CNT_U16			(0x0001U   << 	10)
#define D_SYSFLTACTNTC19D_CNT_U16			(0x0001U   << 	11)
#define D_SYSFLTACTNTC1B6_CNT_U16			(0x0001U   << 	12)
#define D_SYSFLTACTNTC0EE_CNT_U16			(0x0001U   << 	13)
#define D_SYSFLTACTNTC0E9_CNT_U16			(0x0001U   << 	14)

#define D_ERRINTACTNTCCLR_CNT_U32			0x00000000U					/* PAErrInterfaceActive_Cnt_M_bit*/
#define D_ERRINTACTNTC100_CNT_U32			(0x00000001U   << 	1)		/* BUS OFF*/
#define D_ERRINTACTNTC138_CNT_U32			(0x00000001U   << 	2)		/* VehSpd INVALID*/
#define D_ERRINTACTNTC190_CNT_U32			(0x00000001U   << 	3)   	/* HALFSystemSts*/
#define D_ERRINTACTNTC191_CNT_U32			(0x00000001U   << 	4)	   	/* Missing half 292*/
#define D_ERRINTACTNTC199_CNT_U32			(0x00000001U   << 	5)		/* Missing PARK ASSIST half 29F*/
#define D_ERRINTACTNTC120_CNT_U32			(0x00000001U   << 	6)		/* Invalid SCCM_STW_ANGL_STAT */
#define D_ERRINTACTNTC121_CNT_U32			(0x00000001U   << 	7)		/* Missing SCCM_STW_ANGL_STAT */
#define D_ERRINTACTNTC139_CNT_U32			(0x00000001U   << 	8)		/* Missing VehSpeed */
#define D_ERRINTACTNTC124_CNT_U32			(0x00000001U   << 	9)		/* Steering Angle Sensor Rationality  */
#define D_ERRINTACTNTC1B9_CNT_U32			(0x00000001U   << 	10)		/* Missing CBC_PT1 Message */
#define D_ERRINTACTNTC1A8_CNT_U32			(0x00000001U   << 	11)		/* Invalid TRNS_STAT Message */
#define D_ERRINTACTNTC1DE_CNT_U32			(0x00000001U   << 	12)		/* Invalid TRNS_SPD Message */
#define D_ERRINTACTNTC1DF_CNT_U32			(0x00000001U   << 	13)		/* Missing TRNS_SPD Message */
#define D_ERRINTACTNTC1C8_CNT_U32			(0x00000001U   << 	14)		/* Invalid ESP_A5 Message */
#define D_ERRINTACTNTC1D0_CNT_U32			(0x00000001U   << 	15)		/* Invalid ESP_A6 Message */
#define D_ERRINTACTNTC170_CNT_U32			(0x00000001U   << 	16)		/* Implausible Tire Circumference */
#define D_ERRINTACTNTC1A9_CNT_U32			(0x00000001U   << 	17)		/* Missing TRNS_STAT Message */

#define D_DSTREVGRVLDCNTLCLR_CNT_u16		0x0000U
#define D_DSTREVGRVLDCNTL1B9_CNT_u16		(0x0001U   << 	0)		/* Missing CBC_PT1 Message  */
#define D_DSTREVGRVLDCNTL1A8_CNT_u16		(0x0001U   << 	1)		/* Invalid TRNS_STAT Message */
#define D_DSTREVGRVLDCNTL1A9_CNT_u16		(0x0001U   << 	2)		/* Missing TRNS_STAT Message  */

#define D_DSTERRCNTRCLCLR_CNT_u16			0x0000U /* DSTErrCntrRecvLevel_Cnt_M_bit*/
#define D_DSTERRCNTRCLGR0_CNT_u16			0x0001U
#define D_DSTERRCNTRCLTH1_CNT_u16			0x0002U
#define D_DSTERRCNTRCLTH2_CNT_u16			0x0004U

#define D_DSTERRCPTLEV0_CNT_U8			0U /* DSTErrCntrRecvLevel_Cnt_u08*/
#define D_DSTERRCPTLEV1_CNT_U8			1U 
#define D_DSTERRCPTLEV2_CNT_U8			2U
#define D_DSTERRCPTLEV3_CNT_U8			3U 

#define D_PASTATEINACTIVE_CNT_U08		((uint8)0U)
#define D_PASTATEACTIVE_CNT_U08			((uint8)1U)
#define D_PASTATEINHIBITED_CNT_U08		((uint8)2U)
#define D_PASTATERECOVERABLE_CNT_U08	((uint8)3U)

#define D_HALFSYSSTSNOTFAULTED_U16		0U
#define D_HALFSYSSTSFAULTED_U16			1U

#define D_HALFSTATEINACTIVE_CNT_U08		((uint8)0U)
#define D_HALFSTATEACTIVE_CNT_U08		((uint8)1U)
#define D_HALFSTATEINHIBITED_CNT_U08	((uint8)2U)
#define D_HALFSTATERECOVERABLE_CNT_U08	((uint8)3U)

#define TOCSTATE_OFF 					(0U)
#define TOCSTATE_TNA 					(1U)
#define TOCSTATE_PNA 					(2U)
#define TOCSTATE_READY 					(3U)
#define TOCSTATE_REQUESTDENIED 			(4U)
#define TOCSTATE_ACTIVEMODE05 			(5U)
#define TOCSTATE_ACTIVEMODE06 			(6U)
#define TOCSTATE_ACTIVEMODE07 			(7U)
#define TOCSTATE_NOTAVAILABLE 			(8U)

#define D_VCMODELYEARSNA_CNT_U08		((uint8)0x3FU)
#define D_VCVEHLINESNA_CNT_U08			((uint8)0xFFU)
#define D_VCCOUNTRYSNA_CNT_U08			((uint8)0x1FU)
#define D_VCBODYSTYLESNA_CNT_U08		((uint8)0x0FU)

#define D_ESSENGSTDSBL_CNT_U08			((uint8)0x07U)
#define D_ESSENGSTSTPRTCT_CNT_U08		((uint8)0x05U)
#define D_ESSENGSTSNA_CNT_U08			((uint8)0x0FU)
#define D_MAXWHEELFREQ_CNT_F32			(55.48f)

#define D_CFGFEATURE_CNT_U08			((uint8)0x68)
#define D_CFGSTATRQ_CNT_U08				((uint8)0x03)
#define D_CFGSETHI_CNT_U08              ((uint8)0x02)

#define D_AUTOTRANS_CNT_U8				((uint8)0x01)
#define D_MANTRANS_CNT_U8				((uint8)0x00)

#define D_TESTMODE_CNT_U08				0xFF
#define D_VINSIZE_CNT_U08				(17u)

#define D_WHLRPMVEHSPLIM_KPH_F32		(0.4f)
#define RESET_RESPONSE_ECURESET_REQUIRED	((uint8)2U)
#define RESET_RESPONSE_NOT_REQUIRED			((uint8)0U)

#define D_TUNINGPERFORMED_CNT_U16	((uint16)0xA5A5U)
#define D_TIRECIRCUMFSAVD_CNT_U16	((uint16)0xA5A5U)


STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR_INIT) DSTActiveStartTime_mS_M_u32;
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR_INIT) DSTXorCptNTC18F_Cnt_M_u16;

STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR_INIT) VehSpdVldStartTime_mS_M_u32;
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR_INIT) VehSpdMisMsgStartTime_mS_M_u32;
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR_INIT) IgnStatVldStartTime_mS_M_u32;
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR_INIT) IgnStatMisMsgStartTime_mS_M_u32;
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR_INIT) EngRPMVldStartTime_mS_M_u32;
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR_INIT) EngRPMMisMsgStartTime_mS_M_u32;
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR_INIT) SWAVldStartTime_mS_M_u32;
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR_INIT) SWAMisMsgStartTime_mS_M_u32;
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR_INIT) DSTTOCMisMsgStartTime_mS_M_u32;
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR_INIT) NETCFGPTMisMsgStartTime_mS_M_u32;
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR_INIT) HalfMisMsgStartTime_mS_M_u32;
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR_INIT) PTSMisMsgStartTime_mS_M_u32;
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR_INIT) PrevMC_29Fh_Cnt_M_u16;
STATIC VAR(uint16,  AP_SRLCOMINPUT_VAR_INIT) PTSTrqOverlayAcc_Cnt_M_u16;
STATIC VAR(uint16,  AP_SRLCOMINPUT_VAR_INIT) PSTTrqOvrlChngeLmt_Cnt_M_u16;
STATIC VAR(boolean, AP_SRLCOMINPUT_VAR_INIT) PrevVC_PPPA_PrsntTypH_Cnt_M_lgc;
STATIC VAR(uint16,  AP_SRLCOMINPUT_VAR_INIT) DSTTOCMsgCntAcc_Cnt_M_u16;
STATIC VAR(uint16,  AP_SRLCOMINPUT_VAR_INIT) DSTTOCMsgTmrAcc_Cnt_M_u16;
STATIC VAR(uint16,  AP_SRLCOMINPUT_VAR_INIT) MC_29Fh_Bad_Cnt_M_u16;
STATIC VAR(uint16,  AP_SRLCOMINPUT_VAR_INIT) MC_292h_Bad_Cnt_M_u16;
STATIC VAR(uint16,  AP_SRLCOMINPUT_VAR_INIT) PrevMC_292h_Cnt_M_u16;
STATIC VAR(float32, AP_SRLCOMINPUT_VAR_INIT) PrevMtrTorqOverlayStrReq_Cnt_M_f32;
STATIC VAR(uint16,  AP_SRLCOMINPUT_VAR_INIT) PrevVC_TIRE_CIRCUMF_mm_M_u16;
STATIC VAR(uint16,  AP_SRLCOMINPUT_VAR_INIT) VC_TIRE_CIRCUMF_mm_M_u16;
STATIC VAR(uint16,  AP_SRLCOMINPUT_VAR_INIT) PrevWhlPlsCnt_RL_Cnt_M_u16;
STATIC VAR(uint16,  AP_SRLCOMINPUT_VAR_INIT) PrevWhlPlsCnt_RR_Cnt_M_u16;
STATIC VAR(uint16,  AP_SRLCOMINPUT_VAR_INIT) TempWhlPlsCnt_RL_Cnt_M_u16;
STATIC VAR(uint16,  AP_SRLCOMINPUT_VAR_INIT) TempWhlPlsCnt_RR_Cnt_M_u16;
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR_INIT) HalfMaxTrqStartTime_mS_M_u32;
STATIC VAR(uint16,  AP_SRLCOMINPUT_VAR_INIT) PrevHaLFPresent_Cnt_M_lgc;
STATIC VAR(uint16,  AP_SRLCOMINPUT_VAR_INIT) PAIntSystemFltActive_Cnt_M_bit;
STATIC VAR(uint16,  AP_SRLCOMINPUT_VAR_INIT) HaLFIntSystemFltActive_Cnt_M_bit;
STATIC VAR(uint16,  AP_SRLCOMINPUT_VAR_INIT) PrevMC_11Ch_Cnt_M_u16;
STATIC VAR(uint16,  AP_SRLCOMINPUT_VAR_INIT) MC_11Ch_Bad_Cnt_M_u16;
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR_INIT) PAErrInterfaceActive_Cnt_M_bit;
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR_INIT) HaLFErrInterfaceActive_Cnt_M_bit;
STATIC VAR(uint16,  AP_SRLCOMINPUT_VAR_INIT) DSTRevGearValid_Cnt_M_bit;





STATIC VAR(uint16,  AP_SRLCOMINPUT_VAR_INIT) HaLFTrqOvrlChngeAcc_Cnt_M_u16;
STATIC VAR(uint16,  AP_SRLCOMINPUT_VAR_INIT) CRC294DiagAcc_Cnt_M_u16;
STATIC VAR(float32, AP_SRLCOMINPUT_VAR_INIT) PSTTrqOvrlSlewLmt_Nm_M_f32;
STATIC VAR(float32, AP_SRLCOMINPUT_VAR_INIT) HaLFTrqOvrlSlewLmt_Nm_M_f32;
STATIC VAR(float32, AP_SRLCOMINPUT_VAR_INIT) DSTTrqOvrlSlewLmt_Nm_M_f32;
STATIC VAR(uint16,  AP_SRLCOMINPUT_VAR_INIT) CRC11CDiagAcc_Cnt_M_u16;
STATIC VAR(uint16,  AP_SRLCOMINPUT_VAR_INIT) CRC29FDiagAcc_Cnt_M_u16;
STATIC VAR(uint16,  AP_SRLCOMINPUT_VAR_INIT) CRC292DiagAcc_Cnt_M_u16;
STATIC VAR(uint16,  AP_SRLCOMINPUT_VAR_INIT) PrevMC_294h_Cnt_M_u16;
STATIC VAR(uint16,  AP_SRLCOMINPUT_VAR_INIT) DSTErrCntrRecvLevel_Cnt_M_bit;


STATIC VAR(float32,  AP_SRLCOMINPUT_VAR_INIT) HaLFTrqOvCmdRqst_MtrNm_M_f32;
STATIC VAR(float32,  AP_SRLCOMINPUT_VAR_INIT) PATrqOvCmdRqst_HwNm_M_f32;
STATIC VAR(float32, AP_SRLCOMINPUT_VAR_INIT) TO_Req_HwNm_M_f32;
STATIC VAR(uint16,  AP_SRLCOMINPUT_VAR_INIT) PrevDSTPresent_Cnt_M_lgc;
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR_INIT) ESP4AMisMsgStartTime_mS_M_u32;
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR_INIT) BattVoltInvMsgStartTime_mS_M_u32;
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR_INIT) ECMA3MisMsgStartTime_mS_M_u32;
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR_INIT) ESP4AInvMsgStartTime_mS_M_u32;
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR_INIT) IC1AInvMsgStartTime_mS_M_u32;
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR_INIT) IC1AMisMsgStartTime_mS_M_u32;
STATIC VAR(uint16,  AP_SRLCOMINPUT_VAR_INIT) NET_CFG_STAT_PT_Cnt_M_u16;
STATIC VAR(boolean, AP_SRLCOMINPUT_VAR_INIT) PrevNetCfg_PTS_Cnt_M_lgc;
STATIC VAR(boolean, AP_SRLCOMINPUT_VAR_INIT) PrevNetCfg_HaLF_Cnt_M_lgc;
STATIC VAR(boolean, AP_SRLCOMINPUT_VAR_INIT) PrevNetCfg_ESC_Cnt_M_lgc;
STATIC VAR(boolean, AP_SRLCOMINPUT_VAR_INIT) PrevNetCfg_CBC_Cnt_M_lgc;
STATIC VAR(boolean, AP_SRLCOMINPUT_VAR_INIT) PrevNetCfg_ECM_Cnt_M_lgc;
STATIC VAR(boolean, AP_SRLCOMINPUT_VAR_INIT) PrevNetCfg_IC_Cnt_M_lgc;
STATIC VAR(boolean, AP_SRLCOMINPUT_VAR_INIT) PrevNetCfg_SCCM_Cnt_M_lgc;
STATIC VAR(boolean, AP_SRLCOMINPUT_VAR_INIT) PrevNetCfg_TCM_Cnt_M_lgc;
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR_INIT) BattVoltMisMsgStartTime_mS_M_u32;
STATIC VAR(uint8,  AP_SRLCOMINPUT_VAR_INIT) PrevVCBodyStyle_Cnt_M_u08;
STATIC VAR(uint8,  AP_SRLCOMINPUT_VAR_INIT) PrevVCCountry_Cnt_M_u08;
STATIC VAR(uint8,  AP_SRLCOMINPUT_VAR_INIT) PrevVCModelYear_Cnt_M_u08;
STATIC VAR(uint8,  AP_SRLCOMINPUT_VAR_INIT) PrevVCVehLine_Cnt_M_u08;
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR_INIT) VehCfg1InvMsgStartTime_mS_M_u32;
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR_INIT) VehCfg1MisMsgStartTime_mS_M_u32;
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR_INIT) VINInvMsgStartTime_mS_M_u32;
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR_INIT) VINMisMsgStartTime_mS_M_u32;
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR_INIT) CBCNodeAbsStartTime_mS_M_u32;
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR_INIT) BattVoltHighRecTime_mS_M_u32;
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR_INIT) BattVoltHighStartTime_mS_M_u32;
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR_INIT) BattVoltLowRecTime_mS_M_u32;
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR_INIT) BattVoltLowStartTime_mS_M_u32;
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR_INIT) DSLNodeAbsStartTime_mS_M_u32;
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR_INIT) StrWhlAnglRatStartTime_mS_M_u32;
STATIC VAR(float32, AP_SRLCOMINPUT_VAR_INIT) VehAccel_Y_Cnt_M_f32;
STATIC VAR(float32, AP_SRLCOMINPUT_VAR_INIT) VehAccel_X_Cnt_M_f32;
STATIC VAR(float32, AP_SRLCOMINPUT_VAR_INIT) VehSpd_Kph_M_f32;
STATIC VAR(uint16,  AP_SRLCOMINPUT_VAR_INIT) PrevHALFSystemSts_Cnt_M_u16;
STATIC VAR(uint8,   AP_SRLCOMINPUT_VAR_INIT) PrevVINData_Cnt_M_u08[17];
STATIC VAR(float32, AP_SRLCOMINPUT_VAR_INIT) StrgWhlAngl_M_f32;
STATIC VAR(uint8,   AP_SRLCOMINPUT_VAR_INIT) VINRxCount_Cnt_M_u08[3];
STATIC VAR(boolean, AP_SRLCOMINPUT_VAR_INIT) EnableTorqueOverlay_Cnt_M_lgc;
STATIC VAR(boolean, AP_SRLCOMINPUT_VAR_INIT) CurrentVINPending_Cnt_M_lgc;
STATIC VAR(boolean, AP_SRLCOMINPUT_VAR_INIT) StartVinOdo_Cnt_M_lgc;
STATIC VAR(float32, AP_SRLCOMINPUT_VAR_INIT) CurrentVinPendingStart_Km_M_f32;
STATIC VAR(boolean, AP_SRLCOMINPUT_VAR_INIT) PrevEngON_Cnt_M_lgc;
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR_INIT) WHEELSPEED2MisMsgStartTime_mS_M_u32;
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR_INIT) WHEELSPEED2InvMsgStartTime_mS_M_u32;
STATIC VAR(uint16,  AP_SRLCOMINPUT_VAR_INIT) WRSFaultStatus_Cnt_M_b16;
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR_INIT) EngCfgMisMsgStartTime_mS_M_u32;
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR_INIT) EngOilTempMisMsgStartTime_mS_M_u32;
STATIC VAR(uint8,   AP_SRLCOMINPUT_VAR_INIT) TrnsmsnType_Cnt_M_u8;
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR_INIT) TRNSSTATMisMsgStartTime_mS_M_u32;
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR_INIT) TRNSSTATInvMsgStartTime_mS_M_u32;
STATIC VAR(uint16,  AP_SRLCOMINPUT_VAR_INIT) PrevDesiredTunSet_Cnt_M_u16;
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR_INIT) RevGearTempMisMsgStartTime_mS_M_u32;
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR_INIT) VehCfg5MisMsgStartTime_mS_M_u32;
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR_INIT) ECMA3InvMsgStartTime_mS_M_u32;
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR_INIT) ESPA5MisMsgStartTime_mS_M_u32;
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR_INIT) ESPA5VldStartTime_mS_M_u32;
STATIC VAR(boolean,  AP_SRLCOMINPUT_VAR_INIT) VCTireCircRcvd_Cnt_M_Lgc;
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR_INIT) ESPA6MisMsgStartTime_mS_M_u32;
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR_INIT) ESPA6VldStartTime_mS_M_u32;
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR_INIT) TireCircRcvdStartTime_mS_M_u32;
STATIC VAR(uint16,  AP_SRLCOMINPUT_VAR_INIT) TrqOvrlMaxChngeAcc_Cnt_M_u16;
STATIC VAR(boolean,  AP_SRLCOMINPUT_VAR_INIT) CntrlDTCReset_M_lgc;
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR_INIT) EcuCfg6MsgStartTime_mS_M_u32;
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR_INIT) VehCfg7MisMsgStartTime_mS_M_u32;
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR_INIT) CfgRQCMisMsgStartTime_mS_M_u32;
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR_INIT) CfgRQMisMsgStartTime_mS_M_u32;
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR_INIT) EcuCfg6InvMsgStartTime_mS_M_u32;
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR_INIT) GWLINIC2InvMsgStartTime_mS_M_u32;
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR_INIT) GWLINIC2MisMsgStartTime_mS_M_u32;
STATIC VAR(float32, AP_SRLCOMINPUT_VAR_INIT) PrevTOReq_HwNm_M_f32;
STATIC VAR(float32, AP_SRLCOMINPUT_VAR_INIT) TrqBandHi_Nm_M_f32;
STATIC VAR(float32, AP_SRLCOMINPUT_VAR_INIT) TrqBandLow_Nm_M_f32;
STATIC VAR(boolean,  AP_SRLCOMINPUT_VAR_INIT) TrqBndEstab_Cnt_M_lgc;
STATIC VAR(uint32, AP_SRLCOMINPUT_VAR_INIT) TrqStckStartTime_mS_M_u32;
STATIC VAR(boolean,  AP_SRLCOMINPUT_VAR_INIT) DSTExtSystemFltActive_Cnt_M_lgc;
STATIC VAR(uint32, AP_SRLCOMINPUT_VAR_INIT) DSTTOCInvMsgStartTime_mS_M_u32;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR_INIT) PerMisMchFlt_Cnt_M_u16;
STATIC VAR(float32, AP_SRLCOMINPUT_VAR_INIT) PrevMtrTrqOvrlyStrngReq_Nm_M_f32;
STATIC VAR(float32, AP_SRLCOMINPUT_VAR_INIT) MtrTrqOvrlyStrRqMax_Nm_M_f32;
STATIC VAR(boolean,  AP_SRLCOMINPUT_VAR_INIT) ManualVehSpdOvrRide_Cnt_M_lgc;
STATIC VAR(float32, AP_SRLCOMINPUT_VAR_INIT) ManualVehSpd_Kph_M_f32;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR_INIT) TOC_Sts_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR_INIT) PrevDesiredTunPers_Cnt_M_u16;
STATIC VAR(float32, AP_SRLCOMINPUT_VAR_INIT)HalfTrqMax_Nm_M_f32;
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR_INIT) HndsOnDrngPPAStartTime_mS_M_u32;
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR_INIT) TuningPerformedStartTime_mS_M_u32;
STATIC VAR(boolean,  AP_SRLCOMINPUT_VAR_INIT) EC_SteeringIvld_Cnt_M_lgc;
STATIC VAR(boolean,  AP_SRLCOMINPUT_VAR_INIT) SpStPrsnt_Cnt_M_lgc;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR_INIT) Gear_Cnt_M_u16;
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR_INIT) TRNSSPDMisMsgStartTime_mS_M_u32;
STATIC VAR(uint32,  AP_SRLCOMINPUT_VAR_INIT) GrInvMsgStartTime_mS_M_u32;
STATIC VAR(boolean,  AP_SRLCOMINPUT_VAR_INIT) DiagNTC124Set_Cnt_M_lgc;
STATIC VAR(uint8,   AP_SRLCOMINPUT_VAR_INIT) DSTState_Cnt_M_u8;
STATIC VAR(boolean,   AP_SRLCOMINPUT_VAR_INIT) EnableRqst_Cnt_M_lgc;

/* Data to be saved into EEPROM */
#define SRLCOMINPUT_START_SEC_VAR_SAVED_ZONEH_16
#include "MemMap.h"
STATIC VAR(uint16,  AP_SRLCOMINPUT_VAR_NOINIT) TuningSetForNextCycleTypH_Cnt_M_u16;
STATIC VAR(uint16,  AP_SRLCOMINPUT_VAR_NOINIT) TuningPerformedTypH_Cnt_M_u16;
STATIC VAR(uint16,  AP_SRLCOMINPUT_VAR_NOINIT) VCTireCircSavedTypH_Cnt_U16;
STATIC VAR(uint16,  AP_SRLCOMINPUT_VAR_NOINIT) VC_TIRE_CIRCUMFTypH_mm_u16;

#define SRLCOMINPUT_STOP_SEC_VAR_SAVED_ZONEH_16
#include "MemMap.h"
#define SRLCOMINPUT_START_SEC_VAR_SAVED_ZONEH_8
#include "MemMap.h"
STATIC VAR(boolean,  AP_SRLCOMINPUT_VAR_NOINIT) HaLFFuncPresentTypH_Cnt_M_lgc;
STATIC VAR(boolean,  AP_SRLCOMINPUT_VAR_NOINIT) DSTFuncPresentTypH_Cnt_M_lgc;
STATIC VAR(boolean,  AP_SRLCOMINPUT_VAR_NOINIT) VC_PPPA_PrsntTypH_Cnt_M_lgc;
STATIC VAR(uint8,    AP_SRLCOMINPUT_VAR_NOINIT) DesiredTunPersTypH_Cnt_M_u08;
STATIC VAR(boolean,  AP_SRLCOMINPUT_VAR_NOINIT) NetCfg_PTSTypH_Cnt_M_lgc;
STATIC VAR(boolean,  AP_SRLCOMINPUT_VAR_NOINIT) NetCfg_HaLFTypH_Cnt_M_lgc;
STATIC VAR(boolean,  AP_SRLCOMINPUT_VAR_NOINIT) NetCfg_ESCTypH_Cnt_M_lgc;
STATIC VAR(boolean,  AP_SRLCOMINPUT_VAR_NOINIT) NetCfg_CBCTypH_Cnt_M_lgc;
STATIC VAR(boolean,  AP_SRLCOMINPUT_VAR_NOINIT) NetCfg_ECMTypH_Cnt_M_lgc;
STATIC VAR(boolean,  AP_SRLCOMINPUT_VAR_NOINIT) NetCfg_ICTypH_Cnt_M_lgc;
STATIC VAR(boolean,  AP_SRLCOMINPUT_VAR_NOINIT) NetCfg_SCCMTypH_Cnt_M_lgc;
STATIC VAR(boolean,  AP_SRLCOMINPUT_VAR_NOINIT) NetCfg_TCMTypH_Cnt_M_lgc;
STATIC VAR(boolean,  AP_SRLCOMINPUT_VAR_NOINIT) NetCfgStatRcvdTypH_PT_Cnt_M_lgc;
#define SRLCOMINPUT_STOP_SEC_VAR_SAVED_ZONEH_8
#include "MemMap.h"

/* PRQA S 3221 91 */ /* Suppressed per MISRA 2004 Compliance guidline */
STATIC FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) ReadECM_A1(void);
STATIC FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) ReadCBC_PT2(void);
STATIC FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) ReadPTS_StrCtrl(void);
STATIC FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) ReadESP_A5(void);
STATIC FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) ReadESP_A6(void);
STATIC FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) ReadVehCfg5(void);
STATIC FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) ReadHALF_MTO_SteerControl(void);
STATIC FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) ReadNET_CFG_PT(void);
STATIC FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) ReadSCCM_STW_ANGL_STAT(void);
STATIC FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) ReadEcuCfg6(void);
STATIC FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) ReadDST_TOC(void);
STATIC FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) ReadESP_A8(void);
STATIC FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) ReadTRNSSTAT(void);
STATIC FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) ReadVehCfg4(void);
STATIC FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) ReadBATTVOLT(void);
STATIC FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) ReadVehCfg1(void);
STATIC FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) ReadENGCFG(void);
STATIC FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) ReadVIN(void);
STATIC FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) ReadICA1(void);
STATIC FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) ReadECMA3(void);
STATIC FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) ReadESP_A4(void);
STATIC FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) ReadWHEELSPEED2 (void);
STATIC FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) ReadCfgRQ(void);
STATIC FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) ReadCfgRQC(void);
STATIC FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) ReadGWLinIC2 (void);
STATIC FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) ReadEcmIndicators(void);
STATIC FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) ReadVehCfg7(void);
STATIC FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) ReadCBC_PT1(void);
STATIC FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) ReadTRNSSPD(void);

STATIC FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) ClearHALFNTC_MessageNotRcvd(void);
STATIC FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) ClearHALFNTC_RcvdMesgNotValid(void);
STATIC FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) ClearPTSNTC_MessageNotRcvd(void);
STATIC FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) ClearPTSNTC_RcvdMesgNotValid(void);
STATIC FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) ClearDSTTOCNTC_MessageNotRcvd(void);
STATIC FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) ClearDSTTOCNTC_RcvdMesgNotValid(void);

/* Library Function */
STATIC FUNC(boolean, RTE_AP_SRLCOMINPUT_APPL_CODE) IsCRC8Valid(P2VAR(uint8, AUTOMATIC, AUTOMATIC) Buffer_Ptr_T_u8, VAR(uint32, AUTOMATIC) BufferSize_Cnt_T_u32, VAR(uint8, AUTOMATIC) ExpectedCRC_Cnt_T_u8);


/* DST Functions*/
STATIC FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) DSTDiagNTC188( VAR(float32, AUTOMATIC) TO_Req_HwNm_T_f32 );
STATIC FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) DiagNTC189( VAR(uint16, AUTOMATIC) ElapsedTime_mS_T_u16 );
STATIC FUNC(boolean, RTE_AP_SRLCOMINPUT_APPL_CODE) DiagCRC294( VAR(tDST_TOC, AUTOMATIC) DST_TOC_T_str );			 	 /*NTC18A CRC */
STATIC FUNC(boolean, RTE_AP_SRLCOMINPUT_APPL_CODE) DiagNTC18B( VAR(uint16, AUTOMATIC) MC_294h_Cnt_T_u16 );			 	 /*NTC18B Progress counter*/
STATIC FUNC(boolean, RTE_AP_SRLCOMINPUT_APPL_CODE) DSTDiagNTC18CReqOutOfRange( VAR(float32, AUTOMATIC) TO_Req_HwNm_T_f32 );			 /*NTC18C out of range*/
STATIC FUNC(float32, RTE_AP_SRLCOMINPUT_APPL_CODE) DSTDiagNTC18DDeltaOutOfRange( VAR(float32, AUTOMATIC) TO_Req_Cnt_T_f32 );			 /*NTC18D delta out of range*/
STATIC FUNC(boolean, RTE_AP_SRLCOMINPUT_APPL_CODE) DSTDiagNTC18EMaxActiveTime( VAR(uint8, AUTOMATIC) TOCSts_T_Cnt_u8 );			 /*NTC18E max DST ACTIVE */
STATIC FUNC(boolean, RTE_AP_SRLCOMINPUT_APPL_CODE) DSTDiagNTC18FRawXORTest( VAR(uint16, AUTOMATIC) RawTO_Req_Nm_T_u16 );			 /*NTC18F EX OR TEST */
STATIC FUNC(boolean, RTE_AP_SRLCOMINPUT_APPL_CODE) DSTDiagCondtions18CDF( VAR(uint8, AUTOMATIC) DSTState_T_Cnt_u8,
																		  VAR(uint8, AUTOMATIC) DST_TOCState_T_Cnt_u8 );

/* HALF FUNCTIONS */
STATIC FUNC(boolean, RTE_AP_SRLCOMINPUT_APPL_CODE) DiagCRC292( VAR(tHaLF_StrCtrl, AUTOMATIC) HaLF_StrCtrl_T_str );
STATIC FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) DiagNTC190( VAR(uint16, AUTOMATIC) MTO_HALFSystemSts_Cnt_T_u16 );
STATIC FUNC(boolean, RTE_AP_SRLCOMINPUT_APPL_CODE) DiagNTC193( VAR(uint16, AUTOMATIC) MC_292h_Cnt_T_u16 );
STATIC FUNC(boolean, RTE_AP_SRLCOMINPUT_APPL_CODE) DiagNTC194( VAR(float32, AUTOMATIC) MotorTorqueOverlaySteeringReq_Cnt_T_f32,
															VAR(uint8, AUTOMATIC) HaLFState_Cnt_T_u08);
STATIC FUNC(float32, RTE_AP_SRLCOMINPUT_APPL_CODE) DiagNTC195( VAR(float32, AUTOMATIC) MotorTorqueOverlaySteeringReq_HwNm_T_f32,
															VAR(uint8, AUTOMATIC) HaLFState_Cnt_T_u08);
STATIC FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) DiagNTC196( VAR(uint8, AUTOMATIC) HaLFState_Cnt_T_u08, VAR(float32, AUTOMATIC) HaLFStateReq_Nm_T_f32 );
STATIC FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) DiagNTC1C6( VAR(boolean, AUTOMATIC) MotorTorqueOverlayIntActivation_Cnt_T_lgc );

/* Veh Speed Functions*/
STATIC FUNC(boolean, RTE_AP_SRLCOMINPUT_APPL_CODE) DiagCRC11C( VAR(tVEH_SPEED_PKT, AUTOMATIC) ESPA8_T_str ); /*CRC*/
STATIC FUNC(boolean, RTE_AP_SRLCOMINPUT_APPL_CODE) DiagNTC13B_MC11C( VAR(uint16, AUTOMATIC) MC_11Ch_Cnt_T_u16 );	/*Progress counter */


/* PARK ASSIST FUNCTIONS */
STATIC FUNC(boolean, RTE_AP_SRLCOMINPUT_APPL_CODE) DiagCRC29F( VAR(tPTS_StrCtrl, AUTOMATIC) PTS_StrCtrl_T_str );
STATIC FUNC(boolean, RTE_AP_SRLCOMINPUT_APPL_CODE) DiagNTC19B( VAR(uint16, AUTOMATIC) MC_29Fh_Cnt_T_u16 );
STATIC FUNC(boolean, RTE_AP_SRLCOMINPUT_APPL_CODE) DiagNTC19C( VAR(float32, AUTOMATIC) TorqueOverlaySteeringReq_HwNm_T_f32 );
STATIC FUNC(float32, RTE_AP_SRLCOMINPUT_APPL_CODE) DiagNTC19D( VAR(float32, AUTOMATIC) TorqueOverlaySteeringReq_HwNm_T_f32 );
STATIC FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) DiagNTC1B6( VAR(boolean, AUTOMATIC) TorqueOverlayIntActivation_Cnt_T_lgc );
STATIC FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) DiagNTC0EE( VAR(uint8, AUTOMATIC) HALFDriveStyleSts_Cnt_T_u08,VAR(uint8, AUTOMATIC) HaLFState_Cnt_T_u08 );
STATIC FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) DiagNTC0E9( VAR(float32, AUTOMATIC) MotorTorqueOverlaySteeringReq_HwNm_T_f32,VAR(uint8, AUTOMATIC) HaLFState_Cnt_T_u08);
STATIC FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) DiagNTC0EF( VAR(uint16, AUTOMATIC) DSTTorqueOverlayIntActivated_Cnt_T_lgc );

STATIC FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) DiagNTC14E( VAR(float32, AUTOMATIC) BattVolt_Volt_T_f32 );
STATIC FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) DiagNTC14F( VAR(float32, AUTOMATIC) BattVolt_Volt_T_f32 );
STATIC FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) DiagNTC102(void);
STATIC FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) DiagNTC104(void);
STATIC FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) DiagNTC124(void);
STATIC FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) DiagNTC170(void);
STATIC FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) ResetTimers(void);
STATIC FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) VehSpdOverRide(void);
STATIC FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) DiagNTC091(void);
STATIC FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) DiagNTC1F5(void);

STATIC FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_WriteBits(uint32 Data_T_Cnt_u32, uint8* Buffer_T_Cnt_u08, uint16 StartBit_Cnt_T_u16, uint16 EndBit_Cnt_T_u16);

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
 *   FLTINJ_TRQOVLSTA_LKAFAULT (91U)
 *   FLTINJ_TRQARBLIM_LKACMD (101U)
 *   FLTINJ_DDASTFACTRQST_DRVDYNCTRL (150U)
 *   FLTINJ_DDDMPFACTRQST_DRVDYNCTRL (151U)
 *   FLTINJ_DDRTNFACTRQST_DRVDYNCTRL (152U)
 *   FLTINJ_OUTPUTRAMPMULT_LMTCOD (153U)
 *   FLTINJ_ASSTEOTLIMIT_LMTCOD (154U)
 *   FLTINJ_SRLCOMVEHLONACCEL_SGNLCOND (155U)
 *   FLTINJ_ANAHWTORQUE (156U)
 *   FLTINJ_MTRVEL (160U)
 *   FLTINJ_PRKASTMFGSERVCH2_PRKASSISTCMD (200U)
 *   FLTINJ_PRKASTMFGSERVCH2_LRNPNCNTR (201U)
 * ManufModeType: Enumeration of integer in interval [0...2] with enumerators
 *   ProductionMode (0U)
 *   ManufacturingMode (1U)
 *   EngineeringMode (2U)
 * NTCNumber: Enumeration of integer in interval [0...511] with enumerators
 *   NTC_Num_FlashWrapperLgcFlt (1U)
 *   NTC_Num_FlashECCCorr (2U)
 *   NTC_Num_FlashECCMemFlt (3U)
 *   NTC_Num_FlashCRCMemFault (4U)
 *   NTC_Num_NvMBlkDftActA (6U)
 *   NTC_Num_NvMBlkDftActB (7U)
 *   NTC_Num_NvMBlkDftActC (8U)
 *   NTC_Num_CurrentSensorCalOutOfRange (9U)
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
 *   NTC_Num_HWACrossChecks (108U)
 *   NTC_Num_HWASnsrCommFault (109U)
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
 *   NTC_Num_InvalidMsg_ESP_A6 (464U)
 *   NTC_Num_MissingMsg_ESP_A6 (465U)
 *   NTC_Num_InvalidMsg_Wheel_Speed_2 (466U)
 *   NTC_Num_MissingMsg_Wheel_Speed_2 (467U)
 *   NTC_Num_InvalidMsg_GW_LIN_I_C2 (468U)
 *   NTC_Num_MissingMsg_GW_LIN_I_C2 (469U)
 *   NTC_Num_InvalidMsg_EcuCfg6 (470U)
 *   NTC_Num_MissingMsg_EcuCfg6 (471U)
 *   NTC_Num_InvalidMsg_VehCfg7 (472U)
 *   NTC_Num_MissingMsg_VehCfg7 (473U)
 *   NTC_Num_MissingMsg_CFG_RQ (474U)
 *   NTC_Num_MissingMsg_CFG_RQ_C (475U)
 *   NTC_Num_MissingMsg_ORC_YRS_DATA (476U)
 *   NTC_Num_InvalidMsg_ORC_YRS_DATA (477U)
 *   NTC_Num_MissingMsg_AK (481U)
 *   NTC_Num_MissingMsg_AL (489U)
 *   NTC_Num_SysConsistencyVerf (496U)
 *   NTC_Num_ConfigMisMatch (497U)
 *   NTC_Num_CalNotPrgmd (498U)
 *   NTC_Num_TunSetNotPrgmd (499U)
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
 * TOC_STATE: Enumeration of integer in interval [0...255] with enumerators
 *   TOCSTATE_OFF (0U)
 *   TOCSTATE_TNA (1U)
 *   TOCSTATE_PNA (2U)
 *   TOCSTATE_READY (3U)
 *   TOCSTATE_REQUESTDENIED (4U)
 *   TOCSTATE_ACTIVEMODE05 (5U)
 *   TOCSTATE_ACTIVEMODE06 (6U)
 *   TOCSTATE_ACTIVEMODE07 (7U)
 *   TOCSTATE_NOTAVAILABLE (8U)
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


#define RTE_START_SEC_AP_SRLCOMINPUT_APPL_CODE
#include "MemMap.h"

/**********************************************************************************************************************
 *
 * Runnable Entity Name: FaultInjection_FltInjection
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <FltInjection> of PortPrototype <FltInjection>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void FaultInjection_FltInjection(Float *SignalPath_Uls_f32, FltInjectionLocType LocationKey_Cnt_enum)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) FaultInjection_FltInjection(P2VAR(Float, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) SignalPath_Uls_f32, FltInjectionLocType LocationKey_Cnt_enum)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: FaultInjection_FltInjection
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: HaLFState_SCom_Transition
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Transition> of PortPrototype <HaLFState_SCom>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void HaLFState_SCom_Transition(UInt8 State_Cnt_T_u08)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) HaLFState_SCom_Transition(UInt8 State_Cnt_T_u08)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: HaLFState_SCom_Transition
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: PrkAssistState_SCom_Transition
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Transition> of PortPrototype <PrkAssistState_SCom>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void PrkAssistState_SCom_Transition(UInt8 State_Cnt_T_u08)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) PrkAssistState_SCom_Transition(UInt8 State_Cnt_T_u08)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: PrkAssistState_SCom_Transition
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput_Init
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_Init(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SrlComInput_Init
 *********************************************************************************************************************/
	
	VAR(uint32,  AUTOMATIC) SystemTime_mS_T_u32;
	
	/* Initialize NVM data */
	Rte_Write_Ap_SrlComInput_HaLFFuncPresent_Cnt_lgc(HaLFFuncPresentTypH_Cnt_M_lgc);
	Rte_Write_Ap_SrlComInput_PrkAsstFuncPresent_Cnt_lgc(VC_PPPA_PrsntTypH_Cnt_M_lgc);
	Rte_Write_Ap_SrlComInput_DSTFuncPresent_Cnt_lgc(DSTFuncPresentTypH_Cnt_M_lgc);
	if (TuningSetForNextCycleTypH_Cnt_M_u16 > D_NUMOFTUNSETS_CNT_U16)
	{
		TuningSetForNextCycleTypH_Cnt_M_u16 = 0U;
	}

	SrlComInput_WriteBits(TuningSetForNextCycleTypH_Cnt_M_u16,T_A001InternalBusSig_Cnt_u8,196U,199U);

	Rte_Write_Ap_SrlComInput_DesiredTunSet_Cnt_u16(TuningSetForNextCycleTypH_Cnt_M_u16);
	Rte_Write_DesiredTunPers_Cnt_u16(DesiredTunPersTypH_Cnt_M_u08);

	Rte_Call_SystemTime_GetSystemTime_mS_u32(&SystemTime_mS_T_u32);
	
	DSTActiveStartTime_mS_M_u32 = SystemTime_mS_T_u32;
	SWAVldStartTime_mS_M_u32 = SystemTime_mS_T_u32;
	SWAMisMsgStartTime_mS_M_u32 = SystemTime_mS_T_u32;
	EngRPMVldStartTime_mS_M_u32 = SystemTime_mS_T_u32;
	EngRPMMisMsgStartTime_mS_M_u32 = SystemTime_mS_T_u32;
	IgnStatVldStartTime_mS_M_u32 = SystemTime_mS_T_u32;
	IgnStatMisMsgStartTime_mS_M_u32 = SystemTime_mS_T_u32;
	VehSpdVldStartTime_mS_M_u32 = SystemTime_mS_T_u32;
	VehSpdMisMsgStartTime_mS_M_u32 = SystemTime_mS_T_u32;
	PTSMisMsgStartTime_mS_M_u32 = SystemTime_mS_T_u32;
	HalfMisMsgStartTime_mS_M_u32 = SystemTime_mS_T_u32;
	NETCFGPTMisMsgStartTime_mS_M_u32 = SystemTime_mS_T_u32;
	DSTTOCMisMsgStartTime_mS_M_u32 = SystemTime_mS_T_u32;
	HalfMaxTrqStartTime_mS_M_u32 = SystemTime_mS_T_u32;
	ESP4AMisMsgStartTime_mS_M_u32 = SystemTime_mS_T_u32;
	
	EcuCfg6MsgStartTime_mS_M_u32 = SystemTime_mS_T_u32;
	VehCfg7MisMsgStartTime_mS_M_u32 = SystemTime_mS_T_u32;
	CfgRQCMisMsgStartTime_mS_M_u32 = SystemTime_mS_T_u32;
	CfgRQMisMsgStartTime_mS_M_u32 = SystemTime_mS_T_u32;
	EcuCfg6InvMsgStartTime_mS_M_u32 = SystemTime_mS_T_u32;
	GWLINIC2InvMsgStartTime_mS_M_u32 = SystemTime_mS_T_u32;
	GWLINIC2MisMsgStartTime_mS_M_u32 = SystemTime_mS_T_u32;
	HndsOnDrngPPAStartTime_mS_M_u32 = SystemTime_mS_T_u32;
	TuningPerformedStartTime_mS_M_u32 = SystemTime_mS_T_u32;
	TRNSSPDMisMsgStartTime_mS_M_u32 = SystemTime_mS_T_u32;
	GrInvMsgStartTime_mS_M_u32 = SystemTime_mS_T_u32;

	/* NTC for Delta */
	PSTTrqOvrlSlewLmt_Nm_M_f32 = 	k_PSTTrqOvrlSlewLmt_NmpS_f32/100.0f;
	HaLFTrqOvrlSlewLmt_Nm_M_f32 = 	k_HaLFTrqOvrlSlewLmtNrm_NmpS_f32/100.0f;
	DSTTrqOvrlSlewLmt_Nm_M_f32 = 	k_DSTTrqOvrlSlewLmt_NmpS_f32/100.0f;

	MC_292h_Bad_Cnt_M_u16 = 0U;

	PAIntSystemFltActive_Cnt_M_bit = D_SYSFLTACTNTCCLR_CNT_U16;
	PAErrInterfaceActive_Cnt_M_bit = D_ERRINTACTNTCCLR_CNT_U32;
	HaLFErrInterfaceActive_Cnt_M_bit = D_ERRINTACTNTCCLR_CNT_U32;
	HaLFIntSystemFltActive_Cnt_M_bit = D_SYSFLTACTNTCCLR_CNT_U16;
	DSTErrCntrRecvLevel_Cnt_M_bit = D_DSTERRCNTRCLCLR_CNT_u16;
	DSTRevGearValid_Cnt_M_bit = D_DSTREVGRVLDCNTLCLR_CNT_u16;

	PrevVCModelYear_Cnt_M_u08 = D_VCMODELYEARSNA_CNT_U08;
	PrevVCVehLine_Cnt_M_u08 = D_VCVEHLINESNA_CNT_U08;
	PrevVCCountry_Cnt_M_u08 = D_VCCOUNTRYSNA_CNT_U08;
	PrevVCBodyStyle_Cnt_M_u08 = D_VCBODYSTYLESNA_CNT_U08;

	EnableTorqueOverlay_Cnt_M_lgc = TRUE;
	VCTireCircRcvd_Cnt_M_Lgc = FALSE;

	MtrTrqOvrlyStrRqMax_Nm_M_f32 = k_MtrTrqOvrlyStrRqMax_Nm_f32;

	PrevDesiredTunPers_Cnt_M_u16 = DesiredTunPersTypH_Cnt_M_u08;

	if(VCTireCircSavedTypH_Cnt_U16 == D_TIRECIRCUMFSAVD_CNT_U16)
	{
		VC_TIRE_CIRCUMF_mm_M_u16 = VC_TIRE_CIRCUMFTypH_mm_u16;
	}
	
	if(Nvm_VINOdometer_Cnt_u8[1] != TRUE)
	{
		StartVinOdo_Cnt_M_lgc = TRUE;
	}

	/*NTC's are initalized to PASS at startup if testenable depends on Transition states. Else if transition to diff state in next cycle NTC read will return status as 0A*/
	Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DataRateFltMsg_Z, 0x01, NTC_STATUS_PASSED);/*NTC18D*/
	Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DataRngFltMsg_Z, 0x01, NTC_STATUS_PASSED);/*NTC18C*/
	Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DSTXORActive, 0x01, NTC_STATUS_PASSED);/*NTC18F*/
	Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DataOtherFltMsg_Z, 0x01, NTC_STATUS_PASSED);/*NTC18e*/
	Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_Z, 0x01, NTC_STATUS_PASSED);/*NTC188*/
	Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_PgrsCntFltMsg_Z, 0x01, NTC_STATUS_PASSED); /*NTC18b*/
	Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_CRCFltMsg_Z, 0x01, NTC_STATUS_PASSED);/*NTC18a*/

	Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_VLF_14, 0x01, NTC_STATUS_PASSED);/*NTCEE*/
	Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DataOtherFltMsg_AA, 0x01, NTC_STATUS_PASSED);/*NTC196*/
	Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_VLF_09, 0x01, NTC_STATUS_PASSED);/*NTCE9*/
	Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DataRngFltMsg_AA, 0x01, NTC_STATUS_PASSED);/*NTC194*/
	Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DataRngFltMsg_AB, 0x01, NTC_STATUS_PASSED); /*NTC19c*/
	Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DataRateFltMsg_AB, 0x01, NTC_STATUS_PASSED);/*NTC19d*/
	

	DescEnableCommunication();
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput_Per1
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
 *   Std_ReturnType Rte_Read_AnaHwTorque_HwNm_f32(Float *data)
 *   Std_ReturnType Rte_Read_DSTSlewStart_Cnt_lgc(Boolean *data)
 *   Std_ReturnType Rte_Read_DSTState_Cnt_u08(UInt8 *data)
 *   Std_ReturnType Rte_Read_DefaultVehSpd_Cnt_lgc(Boolean *data)
 *   Std_ReturnType Rte_Read_EstFric_HwNm_f32(Float *data)
 *   Std_ReturnType Rte_Read_HaLFState_Cnt_u08(UInt8 *data)
 *   Std_ReturnType Rte_Read_HaLFSuspend_Cnt_lgc(Boolean *data)
 *   Std_ReturnType Rte_Read_HandsOnDetect_Cnt_lgc(Boolean *data)
 *   Std_ReturnType Rte_Read_MEC_Cnt_enum(ManufModeType *data)
 *   Std_ReturnType Rte_Read_PABoostCurveSwitch_Cnt_lgc(Boolean *data)
 *   Std_ReturnType Rte_Read_PrkAssistState_Cnt_u08(UInt8 *data)
 *   Std_ReturnType Rte_Read_PrkAssistSuspend_Cnt_lgc(Boolean *data)
 *   Std_ReturnType Rte_Read_RxMsgsSrlComSvcDft_Cnt_lgc(Boolean *data)
 *   Std_ReturnType Rte_Read_StrClmTrq_HwNm_f32(Float *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_AirTempOutside_DegC_f32(Float data)
 *   Std_ReturnType Rte_Write_AmbTempAvg_DegC_f32(Float data)
 *   Std_ReturnType Rte_Write_BattVolt_Volt_f32(Float data)
 *   Std_ReturnType Rte_Write_CMDIgnStat_Cnt_u08(UInt8 data)
 *   Std_ReturnType Rte_Write_CanMsgReceived_Cnt_lgc(Boolean data)
 *   Std_ReturnType Rte_Write_CfgStatRQ_Cnt_u08(UInt8 data)
 *   Std_ReturnType Rte_Write_DSTEOLDisable_Cnt_lgc(Boolean data)
 *   Std_ReturnType Rte_Write_DSTEnableRqst_Cnt_lgc(Boolean data)
 *   Std_ReturnType Rte_Write_DSTErrCntrRecvLevel_Cnt_u08(UInt8 data)
 *   Std_ReturnType Rte_Write_DSTExtSystemFltActive_Cnt_lgc(Boolean data)
 *   Std_ReturnType Rte_Write_DSTFuncPresent_Cnt_lgc(Boolean data)
 *   Std_ReturnType Rte_Write_DSTRevGearValid_Cnt_lgc(Boolean data)
 *   Std_ReturnType Rte_Write_DSTTOCState_Uls_enum(TOC_STATE data)
 *   Std_ReturnType Rte_Write_DSTTrqOvCmdRqst_HwNm_f32(Float data)
 *   Std_ReturnType Rte_Write_DSTTrqOvRqstValid_Cnt_lgc(Boolean data)
 *   Std_ReturnType Rte_Write_DesiredTunPers_Cnt_u16(UInt16 data)
 *   Std_ReturnType Rte_Write_DesiredTunPersTypH_Cnt_u08(UInt8 data)
 *   Std_ReturnType Rte_Write_DesiredTunSet_Cnt_u16(UInt16 data)
 *   Std_ReturnType Rte_Write_EPS_Mode_Req_Cnt_u08(UInt8 data)
 *   Std_ReturnType Rte_Write_EngOilTemp_DegC_f32(Float data)
 *   Std_ReturnType Rte_Write_EngRPM_Cnt_u16(UInt16 data)
 *   Std_ReturnType Rte_Write_EssEngStop_Cnt_lgc(Boolean data)
 *   Std_ReturnType Rte_Write_HaLFEnableRqst_Cnt_lgc(Boolean data)
 *   Std_ReturnType Rte_Write_HaLFErrInterfaceActive_Cnt_lgc(Boolean data)
 *   Std_ReturnType Rte_Write_HaLFExtSystemFltActive_Cnt_lgc(Boolean data)
 *   Std_ReturnType Rte_Write_HaLFFuncPresent_Cnt_lgc(Boolean data)
 *   Std_ReturnType Rte_Write_HaLFIntSystemFltActive_Cnt_lgc(Boolean data)
 *   Std_ReturnType Rte_Write_HaLFSWATrqFail_Cnt_lgc(Boolean data)
 *   Std_ReturnType Rte_Write_HaLFTrqOvCmdRqst_MtrNm_f32(Float data)
 *   Std_ReturnType Rte_Write_HalfTrqOvRvrsGearEngage_Cnt_lgc(Boolean data)
 *   Std_ReturnType Rte_Write_IWSSCalcVspd_Kph_f32(Float data)
 *   Std_ReturnType Rte_Write_NET_CFG_STAT_PT_Cnt_u16(UInt16 data)
 *   Std_ReturnType Rte_Write_ODO_HwNmSq_f32(Float data)
 *   Std_ReturnType Rte_Write_PAEnableRqst_Cnt_lgc(Boolean data)
 *   Std_ReturnType Rte_Write_PAErrInterfaceActive_Cnt_lgc(Boolean data)
 *   Std_ReturnType Rte_Write_PAExtSystemFltActive_Cnt_lgc(Boolean data)
 *   Std_ReturnType Rte_Write_PAIntSystemFltActive_Cnt_lgc(Boolean data)
 *   Std_ReturnType Rte_Write_PAManoeuvrePhase_Cnt_u08(UInt8 data)
 *   Std_ReturnType Rte_Write_PATrqOvCmdRqst_HwNm_f32(Float data)
 *   Std_ReturnType Rte_Write_PAWheelCriteriaMet_Cnt_lgc(Boolean data)
 *   Std_ReturnType Rte_Write_PAWhlDirRLStat_Cnt_u08(UInt8 data)
 *   Std_ReturnType Rte_Write_PAWhlDirRRStat_Cnt_u08(UInt8 data)
 *   Std_ReturnType Rte_Write_PAWhlPlsCntRLValid_Cnt_lgc(Boolean data)
 *   Std_ReturnType Rte_Write_PAWhlPlsCntRRValid_Cnt_lgc(Boolean data)
 *   Std_ReturnType Rte_Write_PrevHaLFEnableRqst_Cnt_lgc(Boolean data)
 *   Std_ReturnType Rte_Write_PrevHaLFTrqOvCmdRqst_MtrNm_f32(Float data)
 *   Std_ReturnType Rte_Write_PrkAsstFuncPresent_Cnt_lgc(Boolean data)
 *   Std_ReturnType Rte_Write_SpStPrsnt_Cnt_lgc(Boolean data)
 *   Std_ReturnType Rte_Write_SrlComLWhlSpd_Hz_f32(Float data)
 *   Std_ReturnType Rte_Write_SrlComLWhlSpdVld_Cnt_lgc(Boolean data)
 *   Std_ReturnType Rte_Write_SrlComRWhlSpd_Hz_f32(Float data)
 *   Std_ReturnType Rte_Write_SrlComRWhlSpdVld_Cnt_lgc(Boolean data)
 *   Std_ReturnType Rte_Write_SrlComVehSpd_Kph_f32(Float data)
 *   Std_ReturnType Rte_Write_SrlComVehSpdValid_Cnt_lgc(Boolean data)
 *   Std_ReturnType Rte_Write_StrgWhlAngl_HwDeg_f32(Float data)
 *   Std_ReturnType Rte_Write_StrgWhlAnglValid_Cnt_lgc(Boolean data)
 *   Std_ReturnType Rte_Write_TrqOvReverseGearEngage_Cnt_lgc(Boolean data)
 *   Std_ReturnType Rte_Write_VCBodyStyle_Cnt_u08(UInt8 data)
 *   Std_ReturnType Rte_Write_VCCountry_Cnt_u08(UInt8 data)
 *   Std_ReturnType Rte_Write_VCModelYear_Cnt_u08(UInt8 data)
 *   Std_ReturnType Rte_Write_VCVehLine_Cnt_u08(UInt8 data)
 *   Std_ReturnType Rte_Write_VehAccel_KphpS_f32(Float data)
 *   Std_ReturnType Rte_Write_VehAccelX_KphpS_f32(Float data)
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
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_GetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 *Status_Ptr_T_u08)
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
 *   Std_ReturnType Rte_Call_SrlComInput_Per1_CP0_CheckpointReached(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_WdgM_CheckpointReached_E_NOT_OK
 *   Std_ReturnType Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(UInt32 InitialTime, UInt16 *ElapsedTime)
 *     Synchronous Service Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_SystemTime_DtrmnElapsedTime_mS_u32(UInt32 InitialTime, UInt32 *ElapsedTime)
 *     Synchronous Service Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_SystemTime_GetSystemTime_mS_u32(UInt32 *CurrentTime)
 *     Synchronous Service Invocation. Timeout: None
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_Per1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SrlComInput_Per1
 *********************************************************************************************************************/

	 VAR(boolean, AUTOMATIC) BusOffPresent_Cnt_T_lgc;
	 VAR(boolean, AUTOMATIC) RxMsgsSrlComSvcDft_Cnt_T_lgc = FALSE;

	/*Enable Bus Communication so that a positive response to a hard reset can be attempted.*/
	/*TODO figure out what the prerequisite for this is, so this only needs to be called once.*/

	/* Configurable Start of Runnable Checkpoint */
	Rte_Call_SrlComInput_Per1_CP0_CheckpointReached();
	if(TRUE == CDD_CntrlDTCReset_G_lgc)
	{
		if(FALSE == CntrlDTCReset_M_lgc)
		{
			ResetTimers();
			CntrlDTCReset_M_lgc = TRUE;
		}
	}
	else
	{
		CntrlDTCReset_M_lgc = FALSE;
	}

	Rte_Call_NxtrDiagMgr_GetNTCStatus(NTC_Num_BusOffCh1, &BusOffPresent_Cnt_T_lgc);
	if ((TRUE == BusOffPresent_Cnt_T_lgc) && ( FALSE == CDD_DctvFailSafeRctnsCnt_G_lgc))
	{
		HaLFErrInterfaceActive_Cnt_M_bit |= D_ERRINTACTNTC100_CNT_U32;
		PAErrInterfaceActive_Cnt_M_bit   |= D_ERRINTACTNTC100_CNT_U32;
	}
	else
	{
		HaLFErrInterfaceActive_Cnt_M_bit &= ~D_ERRINTACTNTC100_CNT_U32;
		PAErrInterfaceActive_Cnt_M_bit   &= ~D_ERRINTACTNTC100_CNT_U32;
	}


	Rte_Read_Ap_SrlComInput_RxMsgsSrlComSvcDft_Cnt_lgc(&RxMsgsSrlComSvcDft_Cnt_T_lgc);

	if( FALSE == RxMsgsSrlComSvcDft_Cnt_T_lgc)
	{
		ReadNET_CFG_PT();

		if(TRUE == NetCfgStatRcvdTypH_PT_Cnt_M_lgc )
		{
			if(TRUE == NetCfg_PTSTypH_Cnt_M_lgc) /*ESC PTS present */
			{
				ReadPTS_StrCtrl();
			}
			else
			{
				/*This function will set all NTC to pass if message is not received*/
				ClearPTSNTC_MessageNotRcvd();
				/*Clear MISSING MESSG NTC when NetCfg node is not present*/
				Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_MissingMsg_AB, 0x01, NTC_STATUS_PASSED); /*NTC199*/
			}

			if( TRUE == NetCfg_HaLFTypH_Cnt_M_lgc)/*HALF ECU present DST */
			{
				ReadHALF_MTO_SteerControl();
			}
			else
			{
				/*This function will set all NTC to pass if message is not received*/
				ClearHALFNTC_MessageNotRcvd();

				/*Clear MISSING MESSG NTC when NetCfg node is not present*/
				Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_MissingMsg_AA, 0x01, NTC_STATUS_PASSED);
			}


			if(TRUE == NetCfg_ESCTypH_Cnt_M_lgc)
			{
				ReadESP_A4();
				ReadESP_A5();
				ReadESP_A6();
				ReadWHEELSPEED2();
				ReadDST_TOC();/*ESC ECU present DST */
			}
			else
			{
				/*Clear MISSING MESSG and InvalidMsg NTC when NetCfg node esp A4 is not present*/
				Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_MissingMsg_Q, 0x01, NTC_STATUS_PASSED);
				Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_Q, 0x01, NTC_STATUS_PASSED);

				/*Clear MISSING MESSG NTC and InvalidMsg when NetCfg node ESP_A5 is not present */
				Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_MissingMsg_AH, 0x01, NTC_STATUS_PASSED);
				Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_AH, 0x01, NTC_STATUS_PASSED);

				/*Clear MISSING MESSG NTC and InvalidMsg when NetCfg node ESP_A6 is not present */
				Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_MissingMsg_ESP_A6, 0x01, NTC_STATUS_PASSED);
				Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_ESP_A6, 0x01, NTC_STATUS_PASSED);

				/*Clear MISSING MESSG NTC and InvalidMsg when NetCfg node WHEELSPEED2 is not present */
				Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_MissingMsg_Wheel_Speed_2, 0x01, NTC_STATUS_PASSED);/*NTC1d3*/
				Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_Wheel_Speed_2, 0x01, NTC_STATUS_PASSED);


				/*This function will set all NTC to pass if DSTTOC message is not received*/
				ClearDSTTOCNTC_MessageNotRcvd();
				/*Clear Missing message NTC*/
				Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_MissingMsg_Z, 0x01, NTC_STATUS_PASSED); /*NTC189*/



			}

			if(TRUE == NetCfg_CBCTypH_Cnt_M_lgc)
			{
				ReadCBC_PT2();
				ReadCfgRQ(); /*NTC 1DA is set in this, but is not required as per SER*/

				ReadCBC_PT1();
				ReadVehCfg4();

				ReadVehCfg5();
				DiagNTC102();
			}
			else
			{
				/*Clear MISSING MESSG NTC and InvalidMsg when NetCfg node CBC_PT2 is not present */
				Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_MissingMsg_O, 0x01, NTC_STATUS_PASSED);/*NTC131*/
				Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_O, 0x01, NTC_STATUS_PASSED);/*NTC130 not underNetCFg*/

				/*Missing message for CBDPT1*/
				Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_MissingMsg_AF, 0x01, NTC_STATUS_PASSED);

				/*Missing message for VehCfg5*/
				Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_MissingMsg_V, 0x01, NTC_STATUS_PASSED);



			}
			ReadBATTVOLT();
			ReadGWLinIC2(); /*1D5 uses netcfg and is handled inside this func*/
			ReadVehCfg7(); /*1D9 uses netcfgg and is handled inside this func*/
			ReadVehCfg1();/*179 uses netcfg and is handled inside this func*/
			ReadEcuCfg6();/*1D7 uses netcfg and is handled inside this func*/

			if(TRUE == NetCfg_ECMTypH_Cnt_M_lgc)
			{
				ReadEcmIndicators();
				ReadECMA3();
			}
			else
			{
				/*Missing message NTC for EcmIndicators*/
				Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_MissingMsg_Y, 0x01, NTC_STATUS_PASSED);/*NTC181*/

				Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_MissingMsg_S, 0x01, NTC_STATUS_PASSED); /*NTC151*/
				Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_AE, 0x01, NTC_STATUS_PASSED); /*NTC1b0*/
			}

			if(TRUE == NetCfg_TCMTypH_Cnt_M_lgc)
			{
				ReadTRNSSTAT();
				ReadTRNSSPD();
			}
			else
			{
				/*Clear MISSING MESSG NTC and InvalidMsg when NetCfg node TrnsStat is not present */
				Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_AD, 0x01, NTC_STATUS_PASSED);/*NTC1a8*/
				Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_MissingMsg_AD, 0x01, NTC_STATUS_PASSED); /*NTC1a9*/
				Rte_Call_NxtrDiagMgr_SetNTCStatus(0x1DEu, 0x01, NTC_STATUS_PASSED); /*NTC1DE*/
			}


			if(TRUE == NetCfg_ICTypH_Cnt_M_lgc)
			{
				ReadICA1();
				ReadCfgRQC(); /* NTC 1DB is not required as per SER */


			}
			else
			{
				/*Clear MISSING MESSG NTC and InvalidMsg when ICA1 node TrnsStat is not present */
				Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_T, 0x01, NTC_STATUS_PASSED);/*NTC158*/
				Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_MissingMsg_T, 0x01, NTC_STATUS_PASSED); /*NTC159*/
			}

			ReadSCCM_STW_ANGL_STAT();/* 121 needs netcfg and is handle inside this function*/

		}

		ReadESP_A8();
		ReadECM_A1();
		ReadENGCFG();
		ReadVIN();
		DiagNTC102();
		DiagNTC104();
		DiagNTC124();
		DiagNTC170();
	}
	else
	{
		VehSpdOverRide();
	}

	DiagNTC091();
	DiagNTC1F5();
	if (((PAIntSystemFltActive_Cnt_M_bit != 0) && (VC_PPPA_PrsntTypH_Cnt_M_lgc == TRUE))||
			((PAIntSystemFltActive_Cnt_M_bit & D_SYSFLTACTNTC1B6_CNT_U16)!= 0))
	{
		Rte_Write_Ap_SrlComInput_PAIntSystemFltActive_Cnt_lgc(TRUE);
	}
	else
	{
		Rte_Write_Ap_SrlComInput_PAIntSystemFltActive_Cnt_lgc(FALSE);
	}

	if (((HaLFIntSystemFltActive_Cnt_M_bit != 0) && (HaLFFuncPresentTypH_Cnt_M_lgc == TRUE))||
			((HaLFIntSystemFltActive_Cnt_M_bit & D_SYSFLTACTNTC1C6_CNT_U16)!= 0))
	{
		Rte_Write_Ap_SrlComInput_HaLFIntSystemFltActive_Cnt_lgc(TRUE);
	}
	else
	{
		Rte_Write_Ap_SrlComInput_HaLFIntSystemFltActive_Cnt_lgc(FALSE);
	}

	/* ErrInterfaceActive for PRKASSIT function  NTC	 */
	if((PAErrInterfaceActive_Cnt_M_bit != D_ERRINTACTNTCCLR_CNT_U32)&& (VC_PPPA_PrsntTypH_Cnt_M_lgc == TRUE))
	{
		 Rte_Write_Ap_SrlComInput_PAErrInterfaceActive_Cnt_lgc(TRUE);
	}
	else
	{
		 Rte_Write_Ap_SrlComInput_PAErrInterfaceActive_Cnt_lgc(FALSE);
	}

	/* DSTRevGearValid for PRKASSIT function */
	if(DSTRevGearValid_Cnt_M_bit != D_DSTREVGRVLDCNTLCLR_CNT_u16)
	{
		Rte_Write_Ap_SrlComInput_DSTRevGearValid_Cnt_lgc(TRUE);
	}
	else
	{
		Rte_Write_Ap_SrlComInput_DSTRevGearValid_Cnt_lgc(FALSE);
	}

	/* ErrInterfaceActive for HALF function  NTC	 */
	if((HaLFErrInterfaceActive_Cnt_M_bit != D_ERRINTACTNTCCLR_CNT_U32)&& (HaLFFuncPresentTypH_Cnt_M_lgc == TRUE))
	{
		Rte_Write_Ap_SrlComInput_HaLFErrInterfaceActive_Cnt_lgc(TRUE);
	}
	else
	{
		Rte_Write_Ap_SrlComInput_HaLFErrInterfaceActive_Cnt_lgc(FALSE);
	}

	/* ErrCntr associated with DST messages NTC 189 18A 18B	 */
	if( 0 != (DSTErrCntrRecvLevel_Cnt_M_bit & D_DSTERRCNTRCLTH2_CNT_u16))
	{
		Rte_Write_Ap_SrlComInput_DSTErrCntrRecvLevel_Cnt_u08((uint8)D_DSTERRCPTLEV3_CNT_U8);
	}
	else if(0 != (DSTErrCntrRecvLevel_Cnt_M_bit & D_DSTERRCNTRCLTH1_CNT_u16))
	{
		Rte_Write_Ap_SrlComInput_DSTErrCntrRecvLevel_Cnt_u08((uint8)D_DSTERRCPTLEV2_CNT_U8);
	}
	else if(0 != (DSTErrCntrRecvLevel_Cnt_M_bit & D_DSTERRCNTRCLGR0_CNT_u16))
	{
		Rte_Write_Ap_SrlComInput_DSTErrCntrRecvLevel_Cnt_u08((uint8) D_DSTERRCPTLEV1_CNT_U8);
	}
	else
	{
		Rte_Write_Ap_SrlComInput_DSTErrCntrRecvLevel_Cnt_u08((uint8)D_DSTERRCPTLEV0_CNT_U8);
	}

	Rte_Write_Ap_SrlComInput_DesiredTunPersTypH_Cnt_u08(DesiredTunPersTypH_Cnt_M_u08);

	/* Other Signals */

	SrlComInput_WriteBits(VC_PPPA_PrsntTypH_Cnt_M_lgc,T_A002InternalBusSig_Cnt_u8,40U,40U);
	
	/* Configurable End of Runnable Checkpoint */
	Rte_Call_SrlComInput_Per1_CP1_CheckpointReached();
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define RTE_STOP_SEC_AP_SRLCOMINPUT_APPL_CODE
#include "MemMap.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

STATIC FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) ReadECM_A1(void)
{	/* Engine RPM Message ECM_A1 - 0x108 */

	VAR(uint16,  AUTOMATIC) ElapsedTime_mS_T_u16;
	VAR(tECM_A1_PKT, AUTOMATIC) ECMA1_T_str;
	VAR(uint16,      AUTOMATIC) EngRPM_Cnt_T_u16;
	VAR(boolean, AUTOMATIC) EngON_Cnt_T_lgc = FALSE;

	if (TRUE == Ind_ECM_A1_PKT)
	{
		Ind_ECM_A1_PKT = FALSE;
		/* PRQA S 3138 1 */
		dbkGetRxSyncECM_A1_PKT(ECMA1_T_str)
		/* PRQA S 1281 2 */ /* Caused by definition in vector macro */
		EngRPM_Cnt_T_u16 = GetValueRxEngRPM(ECMA1_T_str);
		
		Rte_Call_SystemTime_GetSystemTime_mS_u32(&EngRPMMisMsgStartTime_mS_M_u32);
		Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_MissingMsg_N, 0x01, NTC_STATUS_PASSED);

		if (0xFFFFU != EngRPM_Cnt_T_u16)
		{	
			Rte_Write_EngRPM_Cnt_u16(EngRPM_Cnt_T_u16);
			
			Rte_Call_SystemTime_GetSystemTime_mS_u32(&EngRPMVldStartTime_mS_M_u32);
			Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_N, 0x01, NTC_STATUS_PASSED);

			if (( EngRPM_Cnt_T_u16 > 300u) || ((EngRPM_Cnt_T_u16 > 50u) && (PrevEngON_Cnt_M_lgc == TRUE)))
			{
				EngON_Cnt_T_lgc = TRUE;
			}
		}
		else
		{
			Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(EngRPMVldStartTime_mS_M_u32, &ElapsedTime_mS_T_u16);
			if (ElapsedTime_mS_T_u16 > k_EngRPMValTimeOut_mS_u16p0)
			{
/*NTC128*/		Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_N, 0x01, NTC_STATUS_FAILED);
				Rte_Write_EngRPM_Cnt_u16(0);		
			}
		}

		/*Per DID A001 - EPS Internal and Bussed Signals*/
		SrlComInput_WriteBits((uint32)EngRPM_Cnt_T_u16,T_A001InternalBusSig_Cnt_u8,144U,159U);
		Rte_Write_Ap_SrlComInput_CanMsgReceived_Cnt_lgc(TRUE);
	}
	else
	{
		Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(EngRPMMisMsgStartTime_mS_M_u32, &ElapsedTime_mS_T_u16);
		if (ElapsedTime_mS_T_u16 > k_EngRPMMisMsgTimeOut_mS_u16p0)
		{
			Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_N, 0x01, NTC_STATUS_PASSED);
			EngRPM_Cnt_T_u16 = 0x0000;
			Rte_Write_EngRPM_Cnt_u16(EngRPM_Cnt_T_u16);
			if(TRUE == NetCfg_ECMTypH_Cnt_M_lgc)
			{
				/*NTC129*/	Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_MissingMsg_N, 0x01, NTC_STATUS_FAILED);
			}
			else
			{
				Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_MissingMsg_N, 0x01, NTC_STATUS_PASSED);
			}

		}
	}

	SrlComInput_WriteBits((uint32)EngON_Cnt_T_lgc,T_A001InternalBusSig_Cnt_u8,167U,167U);

	PrevEngON_Cnt_M_lgc = EngON_Cnt_T_lgc;

}


STATIC FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) ReadCBC_PT2(void)
{	/* Customer DTC Inhibit message CBC_PT2 - 0x112 */

	VAR(tVehStart_PKT, AUTOMATIC) CBCPT2_T_str;
	VAR(uint8,         AUTOMATIC) CMDIgnStat_Cnt_T_u08;
	VAR(uint16,        AUTOMATIC) ElapsedTime_mS_T_u16;
	VAR(uint8,		   AUTOMATIC) CMDLclIgnStat_Cnt_u08;
	
	if (TRUE == Ind_VehStart_PKT)
	{
		Ind_VehStart_PKT = FALSE;
		/* PRQA S 3138 1*/
		dbkGetRxSyncVehStart_PKT(CBCPT2_T_str);
		CMDIgnStat_Cnt_T_u08 = GetValueRxCmdIgnStat(CBCPT2_T_str);
		
		Rte_Call_SystemTime_GetSystemTime_mS_u32(&IgnStatMisMsgStartTime_mS_M_u32);
		Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_MissingMsg_O, 0x01, NTC_STATUS_PASSED);
		
		/*Per DID A001 - EPS Internal and Bussed Signals*/
		SrlComInput_WriteBits((uint32)CMDIgnStat_Cnt_T_u08,T_A001InternalBusSig_Cnt_u8,164U,166U);

		if (0x07U != CMDIgnStat_Cnt_T_u08)
		{
			Rte_Write_CMDIgnStat_Cnt_u08(CMDIgnStat_Cnt_T_u08);
			
			Rte_Call_SystemTime_GetSystemTime_mS_u32(&IgnStatVldStartTime_mS_M_u32);
			Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_O, 0x01, NTC_STATUS_PASSED);

			switch(CMDIgnStat_Cnt_T_u08)
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

			FrfmSetBusReceivedIgnitionStatus(CMDLclIgnStat_Cnt_u08);
		}
		else
		{
			Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(IgnStatVldStartTime_mS_M_u32, &ElapsedTime_mS_T_u16);
			if (ElapsedTime_mS_T_u16 > k_IgnStatValTimeOut_mS_u16p0)
			{
/*NTC130*/		Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_O, 0x01, NTC_STATUS_FAILED);
			}
		}
		
		Rte_Write_Ap_SrlComInput_CanMsgReceived_Cnt_lgc(TRUE);
	}
	else
	{

		Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(IgnStatMisMsgStartTime_mS_M_u32, &ElapsedTime_mS_T_u16);
		if (ElapsedTime_mS_T_u16 > k_IgnStatMisMsgTimeOut_mS_u16p0)
		{
			Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_O, 0x01, NTC_STATUS_PASSED);
/*NTC131*/	Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_MissingMsg_O, 0x01, NTC_STATUS_FAILED);
		}
	}

}


STATIC FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) ReadESP_A8(void)
{	/* Vehicle Speed Message ESP_A8 - 0x11C */

	VAR(boolean, AUTOMATIC) DefaultVehSpd_Cnt_T_lgc;
	VAR(tVEH_SPEED_PKT, AUTOMATIC) ESPA8_T_str;
	VAR(uint16, AUTOMATIC) VehSpd_Cnt_T_u16;
	VAR(uint16, AUTOMATIC) MC_11Ch_Cnt_T_u16;
	VAR(uint16, AUTOMATIC) ElapsedTime_mS_T_u16;
	VAR(boolean,  AUTOMATIC) ReceivedDataValid_Cnt_T_lgc = TRUE;
	VAR(boolean,  AUTOMATIC) SrlComVehSpeedValid_Cnt_T_lgc = FALSE;
	VAR(uint16, AUTOMATIC) tempVar16;


	if (TRUE == Ind_VEH_SPEED_PKT)
	{
		Ind_VEH_SPEED_PKT = FALSE;
		/* PRQA S 3138 1*/
		dbkGetRxSyncVEH_SPEED_PKT(ESPA8_T_str);
		Rte_Call_SystemTime_GetSystemTime_mS_u32(&VehSpdMisMsgStartTime_mS_M_u32);
		Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_MissingMsg_P, 0x01, NTC_STATUS_PASSED);
		HaLFErrInterfaceActive_Cnt_M_bit &= ~D_ERRINTACTNTC139_CNT_U32;

		/* PRQA S 1281 2 */ /* Caused by definition in vector macro */
		ReceivedDataValid_Cnt_T_lgc &= DiagCRC11C(ESPA8_T_str);
		/*NTC13B*/

		MC_11Ch_Cnt_T_u16 = GetValueRxMC_VEH_SPEED(ESPA8_T_str);
		ReceivedDataValid_Cnt_T_lgc &= DiagNTC13B_MC11C(MC_11Ch_Cnt_T_u16);



		if (TRUE == ReceivedDataValid_Cnt_T_lgc)
		{
			/* PRQA S 1281 2 */ /* Caused by definition in vector macro */
			VehSpd_Cnt_T_u16 = GetValueRxVEH_SPEED(ESPA8_T_str);
		
			/*Per DID 0xA001 - EPS Internal and Bussed Signals*/
			SrlComInput_WriteBits((uint32)VehSpd_Cnt_T_u16,T_A001InternalBusSig_Cnt_u8,24U,39U);

			if (D_VEHSPEEDNOTAVAILABLE_CNT_U16 != VehSpd_Cnt_T_u16)
			{
				VehSpd_Kph_M_f32 = (float32)VehSpd_Cnt_T_u16 * D_VEHSPEEDSCALE_KPH_F32;
				SrlComVehSpeedValid_Cnt_T_lgc = TRUE;

				Rte_Call_SystemTime_GetSystemTime_mS_u32(&VehSpdVldStartTime_mS_M_u32);
				Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_P, 0x01, NTC_STATUS_PASSED);

				/*Clear the error interface bits for invalid vehicle speed for HaLF & PA.*/
				PAErrInterfaceActive_Cnt_M_bit &= ~D_ERRINTACTNTC138_CNT_U32;
				HaLFErrInterfaceActive_Cnt_M_bit &= ~D_ERRINTACTNTC138_CNT_U32;

			}
			else
			{
				Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(VehSpdVldStartTime_mS_M_u32, &ElapsedTime_mS_T_u16);
				if (ElapsedTime_mS_T_u16 > k_VehSpdValTimeOut_mS_u16p0)
				{
/*NTC138*/			Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_P, 0x01, NTC_STATUS_FAILED);
					PAErrInterfaceActive_Cnt_M_bit |= D_ERRINTACTNTC138_CNT_U32;
					HaLFErrInterfaceActive_Cnt_M_bit |= D_ERRINTACTNTC138_CNT_U32;
				}
			}
		}
		else
		{
			Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_P, 0x01, NTC_STATUS_PASSED);
		}


		Rte_Write_Ap_SrlComInput_CanMsgReceived_Cnt_lgc(TRUE);
	}
	else
	{
		Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(VehSpdMisMsgStartTime_mS_M_u32, &ElapsedTime_mS_T_u16);
		if (ElapsedTime_mS_T_u16 > k_VehSpdMisMsgTimeOut_mS_u16p0)
		{
			Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_CRCFltMsg_P, 0x01, NTC_STATUS_PASSED);/*NTC13A*/
			Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_PgrsCntFltMsg_P, 0x01, NTC_STATUS_PASSED);/*NTC13B*/
			Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_P, 0x01, NTC_STATUS_PASSED);/*NTC138*/
			MC_11Ch_Bad_Cnt_M_u16 = 0;
			if(TRUE == NetCfg_ESCTypH_Cnt_M_lgc)
			{
/*NTC139*/		Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_MissingMsg_P, 0x01, NTC_STATUS_FAILED);
			}
			else
			{
				Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_MissingMsg_P, 0x01, NTC_STATUS_PASSED);
			}
			Rte_Write_SrlComVehSpdValid_Cnt_lgc(FALSE);
			if (TRUE == VC_PPPA_PrsntTypH_Cnt_M_lgc)
			{
				PAErrInterfaceActive_Cnt_M_bit |= D_ERRINTACTNTC139_CNT_U32;
			}
			if (TRUE == HaLFFuncPresentTypH_Cnt_M_lgc)
			{
				HaLFErrInterfaceActive_Cnt_M_bit |= D_ERRINTACTNTC139_CNT_U32;
			}
		}
		else
		{
			PAErrInterfaceActive_Cnt_M_bit &= ~D_ERRINTACTNTC139_CNT_U32;
			HaLFErrInterfaceActive_Cnt_M_bit &= ~D_ERRINTACTNTC139_CNT_U32;
		}
	}
	

	/* default vehicle speed is set by diagMgr in fault Response table */
	Rte_Read_DefaultVehSpd_Cnt_lgc(&DefaultVehSpd_Cnt_T_lgc);


	if (ManualVehSpdOvrRide_Cnt_M_lgc == TRUE)
	{
		VehSpdOverRide();
	}
	else
	{
		if ((DefaultVehSpd_Cnt_T_lgc == TRUE) || ((FALSE == NetCfg_ESCTypH_Cnt_M_lgc) && (NxtrMEC_Uls_G_enum == ProductionMode)))
		{
			SuspendAllInterrupts();
			Rte_Write_SrlComVehSpdValid_Cnt_lgc(FALSE);
			VehSpd_Kph_M_f32 = FPM_FixedToFloat_m( k_DefaultVehSpd_Kph_u9p7, u9p7_T);
			ResumeAllInterrupts();
		}
		else
		{
			if(TRUE == SrlComVehSpeedValid_Cnt_T_lgc)
			{
				SuspendAllInterrupts();
				Rte_Write_SrlComVehSpdValid_Cnt_lgc(TRUE);
				ResumeAllInterrupts();
			}
		}
	}
	/*Per DID 0xA001 - EPS Internal and Bussed Signals*/

	Rte_Write_SrlComVehSpd_Kph_f32(VehSpd_Kph_M_f32);
	/* PRQA S 4395 1 */ /* Cast being done in macro */
	tempVar16 = (-1 * (FPM_FloatToFixed_m((VehSpd_Kph_M_f32 / 0.0078125), u16p0_T)));
	SrlComInput_WriteBits(tempVar16,T_A001InternalBusSig_Cnt_u8,40U,55U);
}

/* PRQA S 3673 2 */ /* The call to function Crc_CalculateCRC8 requires the P2VAR type */
STATIC FUNC(boolean, RTE_AP_SRLCOMINPUT_APPL_CODE) IsCRC8Valid(P2VAR(uint8, AUTOMATIC, AUTOMATIC) Buffer_Ptr_T_u8, VAR(uint32, AUTOMATIC) BufferSize_Cnt_T_u32, VAR(uint8, AUTOMATIC) ExpectedCRC_Cnt_T_u8)
{
	VAR(uint8,  AUTOMATIC) CalculatedCRC_T_u8;
	VAR(boolean,  AUTOMATIC) IsCRCOK_Cnt_T_lgc = FALSE;
	CalculatedCRC_T_u8 = Crc_CalculateCRC8(Buffer_Ptr_T_u8, BufferSize_Cnt_T_u32, D_CRCINIT_CNT_U8);
	CalculatedCRC_T_u8 ^= D_CRCXORVALUE_CNT_U8;
	if (CalculatedCRC_T_u8 == ExpectedCRC_Cnt_T_u8)
	{
		IsCRCOK_Cnt_T_lgc = TRUE;
	}

	return IsCRCOK_Cnt_T_lgc;
}

STATIC FUNC(boolean, RTE_AP_SRLCOMINPUT_APPL_CODE) DiagCRC11C( VAR(tVEH_SPEED_PKT, AUTOMATIC) ESPA8_T_str )
{

	VAR(boolean,  AUTOMATIC) ReceivedDataValid_Cnt_T_lgc;

	ReceivedDataValid_Cnt_T_lgc = IsCRC8Valid(ESPA8_T_str.c, 7, GetValueRxCRC_VEH_SPEED(ESPA8_T_str));

	if( FALSE == ReceivedDataValid_Cnt_T_lgc)
	{
		CRC11CDiagAcc_Cnt_M_u16++;
	}
	else
	{
		CRC11CDiagAcc_Cnt_M_u16 = 0U;
	}

	if (CRC11CDiagAcc_Cnt_M_u16 > k_CRC11CDiagMsg_Cnt_u16)
	{
/*NTC13A*/Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_CRCFltMsg_P, 0x01, NTC_STATUS_FAILED);

			HaLFIntSystemFltActive_Cnt_M_bit |= D_SYSFLTACTNTC13A_CNT_U16;
			PAIntSystemFltActive_Cnt_M_bit |= D_SYSFLTACTNTC13A_CNT_U16;

	}
	else
	{
		Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_CRCFltMsg_P, 0x01, NTC_STATUS_PASSED);
		HaLFIntSystemFltActive_Cnt_M_bit &= ~D_SYSFLTACTNTC13A_CNT_U16;
		PAIntSystemFltActive_Cnt_M_bit &= ~D_SYSFLTACTNTC13A_CNT_U16;

	}
	return ReceivedDataValid_Cnt_T_lgc;
}

STATIC FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) ReadPTS_StrCtrl(void)
{	/* PTS_StrCntl - 0x29f */

	VAR(tPTS_StrCtrl, AUTOMATIC) PTS_StrCtrl_T_str;
	VAR(boolean, AUTOMATIC) TorqueOverlayIntActivation_Cnt_T_lgc;
	VAR(uint16, AUTOMATIC) RawTorqueOverlaySteeringReq_HwNm_T_u16;
	VAR(float32, AUTOMATIC) TorqueOverlaySteeringReq_HwNm_T_f32;
	VAR(uint8, AUTOMATIC) ManeuverPhase_Cnt_T_u08;
	VAR(boolean, AUTOMATIC) PTSSystemFault_Cnt_T_lgc;
	VAR(uint16, AUTOMATIC) MC_29Fh_Cnt_T_u16;
	VAR(uint16, AUTOMATIC) ElapsedTime_mS_T_u16;
	VAR(uint8, AUTOMATIC) PrkAssistState_Cnt_T_u08;
	VAR(boolean,  AUTOMATIC) ReceivedDataValid_Cnt_T_lgc = TRUE;
	VAR(boolean,  AUTOMATIC) MissingMsgM_Cnt_T_lgc = FALSE;
	VAR(boolean,  AUTOMATIC) InvalidMsgM_Cnt_T_lgc = FALSE;
	VAR(boolean,  AUTOMATIC) DataRngFltMsgM_Cnt_T_lgc = FALSE;
	VAR(uint8, AUTOMATIC) PTSDriveStyleReqSts_Cnt_T_u08;

	Rte_Read_Ap_SrlComInput_PrkAssistState_Cnt_u08(&PrkAssistState_Cnt_T_u08);

	if (TRUE == Ind_PTS_StrCtrl)
	{
		Ind_PTS_StrCtrl = FALSE;
		/* PRQA S 3138 1*/
		dbkGetRxSyncPTS_StrCtrl(PTS_StrCtrl_T_str);
		Rte_Call_SystemTime_GetSystemTime_mS_u32(&PTSMisMsgStartTime_mS_M_u32);
		Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_MissingMsg_AB, 0x01, NTC_STATUS_PASSED);
		PAErrInterfaceActive_Cnt_M_bit &= ~D_ERRINTACTNTC199_CNT_U32;

		/*NTC19A*/
		ReceivedDataValid_Cnt_T_lgc &= DiagCRC29F(PTS_StrCtrl_T_str);
		/*NTC19B*/
		MC_29Fh_Cnt_T_u16 = GetValueRxMC_29Fh(PTS_StrCtrl_T_str);
		ReceivedDataValid_Cnt_T_lgc &=  DiagNTC19B(MC_29Fh_Cnt_T_u16);


		if (ReceivedDataValid_Cnt_T_lgc == TRUE)
		{
			PTSDriveStyleReqSts_Cnt_T_u08 = GetValueRxPTSDriveStyleReqSts(PTS_StrCtrl_T_str);
			SrlComInput_WriteBits(PTSDriveStyleReqSts_Cnt_T_u08,T_A002InternalBusSig_Cnt_u8,4U,4U);
			if((0x01U == PTSDriveStyleReqSts_Cnt_T_u08) && (D_PASTATEACTIVE_CNT_U08 == PrkAssistState_Cnt_T_u08))
			{
				TuningSetForNextCycleTypH_Cnt_M_u16 = k_PTSDrStylTunSet_Cnt_u16;
			}

			ManeuverPhase_Cnt_T_u08 = GetValueRxManeuverPhase(PTS_StrCtrl_T_str);
			SrlComInput_WriteBits(ManeuverPhase_Cnt_T_u08,T_A002InternalBusSig_Cnt_u8,3U,3U);
			SrlComInput_WriteBits(0x00U,T_A002InternalBusSig_Cnt_u8,0U,2U);

			PTSSystemFault_Cnt_T_lgc = GetValueRxPTSSystemFault(PTS_StrCtrl_T_str);
			SrlComInput_WriteBits(PTSSystemFault_Cnt_T_lgc,T_A002InternalBusSig_Cnt_u8,47U,47U);

			TorqueOverlayIntActivation_Cnt_T_lgc = GetValueRxTorqueOverlayIntActivation(PTS_StrCtrl_T_str);
			SrlComInput_WriteBits(TorqueOverlayIntActivation_Cnt_T_lgc,T_A002InternalBusSig_Cnt_u8,7U,7U);

			RawTorqueOverlaySteeringReq_HwNm_T_u16 = GetValueRxTorqueOverlaySteeringReq(PTS_StrCtrl_T_str);
			SrlComInput_WriteBits(RawTorqueOverlaySteeringReq_HwNm_T_u16,T_A002InternalBusSig_Cnt_u8,8U,23U);

			TorqueOverlaySteeringReq_HwNm_T_f32 = FPM_FixedToFloat_m(RawTorqueOverlaySteeringReq_HwNm_T_u16, u9p7_T);
			TorqueOverlaySteeringReq_HwNm_T_f32 = TorqueOverlaySteeringReq_HwNm_T_f32 - D_TORQOVERLAYSTRREQOFF_CNT_F32;
			TorqueOverlaySteeringReq_HwNm_T_f32 = k_TorqOvrlStrReqPol_Cnt_f32 * TorqueOverlaySteeringReq_HwNm_T_f32;

			DiagNTC0EF(TorqueOverlayIntActivation_Cnt_T_lgc);
			DiagNTC1B6(TorqueOverlayIntActivation_Cnt_T_lgc);
			if ( TRUE == VC_PPPA_PrsntTypH_Cnt_M_lgc)
			{

				if (D_PASTATEACTIVE_CNT_U08 == PrkAssistState_Cnt_T_u08)
				{
/*NTC19C*/			DiagNTC19C(TorqueOverlaySteeringReq_HwNm_T_f32);
/*NTC19D*/			PATrqOvCmdRqst_HwNm_M_f32 = DiagNTC19D(TorqueOverlaySteeringReq_HwNm_T_f32);
				}
			
				Rte_Write_Ap_SrlComInput_PAManoeuvrePhase_Cnt_u08(ManeuverPhase_Cnt_T_u08);
				Rte_Write_Ap_SrlComInput_PAExtSystemFltActive_Cnt_lgc(PTSSystemFault_Cnt_T_lgc);

				Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_MissingMsg_M, &MissingMsgM_Cnt_T_lgc);
				Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_InvalidMsg_M, &InvalidMsgM_Cnt_T_lgc);
				Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_DataRngFltMsg_M, &DataRngFltMsgM_Cnt_T_lgc);

				if((TRUE == TorqueOverlayIntActivation_Cnt_T_lgc) &&
						(TRUE == EnableTorqueOverlay_Cnt_M_lgc) &&
						(FALSE == MissingMsgM_Cnt_T_lgc)&&
						(FALSE == InvalidMsgM_Cnt_T_lgc)&&
						(FALSE == DataRngFltMsgM_Cnt_T_lgc))
				{
					Rte_Write_Ap_SrlComInput_PAEnableRqst_Cnt_lgc(TRUE);
				}
				else
				{
					Rte_Write_Ap_SrlComInput_PAEnableRqst_Cnt_lgc(FALSE);
				}

			} /* if ( TRUE == VC_PPPA_PrsntTypH_Cnt_M_lgc) */
			else
			{
				Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DataRngFltMsg_AB, 0x01, NTC_STATUS_PASSED);/*NTC19c*/
				Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DataRateFltMsg_AB, 0x01, NTC_STATUS_PASSED);/*NTC19d*/
			}
		} /*if (ReceivedDataValid_Cnt_T_lgc == TRUE)*/
		else
		{
			ClearPTSNTC_RcvdMesgNotValid();
		}
		Rte_Write_Ap_SrlComInput_CanMsgReceived_Cnt_lgc(TRUE);
	}
	else
	{


		Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(PTSMisMsgStartTime_mS_M_u32, &ElapsedTime_mS_T_u16);
		if ((ElapsedTime_mS_T_u16 > k_PSTMisMsgTimeOut_mS_u16p0))
		{
			ClearPTSNTC_MessageNotRcvd();
			MC_29Fh_Bad_Cnt_M_u16 = 0;

			if ((	(D_PASTATEACTIVE_CNT_U08 == PrkAssistState_Cnt_T_u08)||
					(D_PASTATERECOVERABLE_CNT_U08 == PrkAssistState_Cnt_T_u08)||
					(D_PASTATEINACTIVE_CNT_U08 == PrkAssistState_Cnt_T_u08)) &&
				( TRUE == VC_PPPA_PrsntTypH_Cnt_M_lgc))
			{
				PAErrInterfaceActive_Cnt_M_bit |= D_ERRINTACTNTC199_CNT_U32;
				/*NTC199*/	Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_MissingMsg_AB, 0x01, NTC_STATUS_FAILED);
			}
			else
			{
				/*NTC199*/	Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_MissingMsg_AB, 0x01, NTC_STATUS_PASSED);
			}
		}

	}

	Rte_Write_Ap_SrlComInput_PATrqOvCmdRqst_HwNm_f32(PATrqOvCmdRqst_HwNm_M_f32);
}


STATIC FUNC(boolean, RTE_AP_SRLCOMINPUT_APPL_CODE) DiagNTC19C( VAR(float32, AUTOMATIC) TorqueOverlaySteeringReq_HwNm_T_f32 )
{
	VAR(boolean,  AUTOMATIC) IsCmdValid_Cnt_T_lgc = TRUE;

	if(Abs_f32_m(TorqueOverlaySteeringReq_HwNm_T_f32) > k_PSTTrqOvrlRange_Cnt_f32)
	{
		PTSTrqOverlayAcc_Cnt_M_u16 = DiagPStep_m(PTSTrqOverlayAcc_Cnt_M_u16, k_PSTTrqOvrlRangeDiag_Cnt_str);
		IsCmdValid_Cnt_T_lgc = FALSE;
	}
	else
	{
		PTSTrqOverlayAcc_Cnt_M_u16 = DiagNStep_m(PTSTrqOverlayAcc_Cnt_M_u16, k_PSTTrqOvrlRangeDiag_Cnt_str);

	}

	if (TRUE == DiagFailed_m( PTSTrqOverlayAcc_Cnt_M_u16, k_PSTTrqOvrlRangeDiag_Cnt_str))
	{
		Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DataRngFltMsg_AB, 0x01, NTC_STATUS_FAILED);
		PAIntSystemFltActive_Cnt_M_bit |= D_SYSFLTACTNTC19C_CNT_U16;

	}
	else
	{
		Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DataRngFltMsg_AB, 0x01, NTC_STATUS_PASSED);
		PAIntSystemFltActive_Cnt_M_bit &= ~D_SYSFLTACTNTC19C_CNT_U16;
	}
	return IsCmdValid_Cnt_T_lgc;
}


STATIC FUNC(float32, RTE_AP_SRLCOMINPUT_APPL_CODE) DiagNTC19D( VAR(float32, AUTOMATIC) TorqueOverlaySteeringReq_HwNm_T_f32 )
{
	VAR(float32,  AUTOMATIC) PATrqOvCmdRqst_HwNm_T_f32;

	if(Abs_f32_m(TorqueOverlaySteeringReq_HwNm_T_f32 - PATrqOvCmdRqst_HwNm_M_f32) > PSTTrqOvrlSlewLmt_Nm_M_f32)
	{
		PSTTrqOvrlChngeLmt_Cnt_M_u16 = DiagPStep_m(PSTTrqOvrlChngeLmt_Cnt_M_u16, k_PSTTrqOvrlSlewLmtDiag_Cnt_str);

		if((PATrqOvCmdRqst_HwNm_M_f32 - TorqueOverlaySteeringReq_HwNm_T_f32)  > 0.0f)
		{
			PATrqOvCmdRqst_HwNm_T_f32 = PATrqOvCmdRqst_HwNm_M_f32 - PSTTrqOvrlSlewLmt_Nm_M_f32;
		}
		else
		{
			PATrqOvCmdRqst_HwNm_T_f32 = PATrqOvCmdRqst_HwNm_M_f32 + PSTTrqOvrlSlewLmt_Nm_M_f32;

		}
	}
	else
	{
		PSTTrqOvrlChngeLmt_Cnt_M_u16 = DiagNStep_m(PSTTrqOvrlChngeLmt_Cnt_M_u16, k_PSTTrqOvrlSlewLmtDiag_Cnt_str);
		PATrqOvCmdRqst_HwNm_T_f32 = TorqueOverlaySteeringReq_HwNm_T_f32;
	}

	if (TRUE == DiagFailed_m( PSTTrqOvrlChngeLmt_Cnt_M_u16, k_PSTTrqOvrlSlewLmtDiag_Cnt_str))
	{
		Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DataRateFltMsg_AB, 0x01, NTC_STATUS_FAILED);
		PAIntSystemFltActive_Cnt_M_bit |= D_SYSFLTACTNTC19D_CNT_U16;
	}
	else
	{
		Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DataRateFltMsg_AB, 0x01, NTC_STATUS_PASSED);
		PAIntSystemFltActive_Cnt_M_bit &= ~D_SYSFLTACTNTC19D_CNT_U16;
	}
	return PATrqOvCmdRqst_HwNm_T_f32;
}

STATIC FUNC(boolean, RTE_AP_SRLCOMINPUT_APPL_CODE) DiagNTC19B( VAR(uint16, AUTOMATIC) MC_29Fh_Cnt_T_u16 )
{

	VAR(boolean,  AUTOMATIC) CounterValid_T_Cnt_lgc = TRUE;


	if (((PrevMC_29Fh_Cnt_M_u16 + 1) % D_COUNTERCYCLE16_CNT_U16) != MC_29Fh_Cnt_T_u16  )
	{
		MC_29Fh_Bad_Cnt_M_u16++;
		CounterValid_T_Cnt_lgc = FALSE;
	}
	else
	{
		MC_29Fh_Bad_Cnt_M_u16 = 0u;
	}

	PrevMC_29Fh_Cnt_M_u16 = MC_29Fh_Cnt_T_u16;

	if(MC_29Fh_Bad_Cnt_M_u16 >= k_MC29FhMsg_Cnt_u16)
	{
		Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_PgrsCntFltMsg_AB, 0x01, NTC_STATUS_FAILED);
		PAIntSystemFltActive_Cnt_M_bit |= D_SYSFLTACTNTC19B_CNT_U16;
	}
	else
	{
		Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_PgrsCntFltMsg_AB, 0x01, NTC_STATUS_PASSED);
		PAIntSystemFltActive_Cnt_M_bit &= ~D_SYSFLTACTNTC19B_CNT_U16;
	}
	return CounterValid_T_Cnt_lgc;

}

STATIC FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) DiagNTC1B6( VAR(boolean, AUTOMATIC) TorqueOverlayIntActivation_Cnt_T_lgc )
{
	if((VC_PPPA_PrsntTypH_Cnt_M_lgc == FALSE) && (TRUE == TorqueOverlayIntActivation_Cnt_T_lgc))
	{
		Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DataOtherFltMsg_AE, 0x01, NTC_STATUS_FAILED);
		PAIntSystemFltActive_Cnt_M_bit |= D_SYSFLTACTNTC1B6_CNT_U16;
	}
	else
	{
		Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DataOtherFltMsg_AE, 0x01, NTC_STATUS_PASSED);
		PAIntSystemFltActive_Cnt_M_bit &= ~D_SYSFLTACTNTC1B6_CNT_U16;
	}

}

STATIC FUNC(boolean, RTE_AP_SRLCOMINPUT_APPL_CODE) DiagCRC29F( VAR(tPTS_StrCtrl, AUTOMATIC) PTS_StrCtrl_T_str )
{

	VAR(boolean,  AUTOMATIC) ReceivedDataValid_Cnt_T_lgc;


	ReceivedDataValid_Cnt_T_lgc = IsCRC8Valid(PTS_StrCtrl_T_str.c, 7, GetValueRxCRC_29Fh(PTS_StrCtrl_T_str));
	if( FALSE == ReceivedDataValid_Cnt_T_lgc)
	{
		CRC29FDiagAcc_Cnt_M_u16++;
	}
	else
	{
		CRC29FDiagAcc_Cnt_M_u16 = 0U;
	}

	if (CRC29FDiagAcc_Cnt_M_u16 > k_CRC29FDiagMsg_Cnt_u16)
	{
		Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_CRCFltMsg_AB, 0x01, NTC_STATUS_FAILED);
		PAIntSystemFltActive_Cnt_M_bit |= D_SYSFLTACTNTC19A_CNT_U16;
	}
	else
	{
		Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_CRCFltMsg_AB, 0x01, NTC_STATUS_PASSED);
		PAIntSystemFltActive_Cnt_M_bit &= ~D_SYSFLTACTNTC19A_CNT_U16;
	}
	return ReceivedDataValid_Cnt_T_lgc;
}

STATIC FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) ReadVehCfg4(void)
{	/* VehCfg4 - 0x3EB */

	VAR(tVehCfg4_Pkt, AUTOMATIC) VehCfg4_Pkt_T_str;
	VAR(uint16, AUTOMATIC) VC_VehCfg4_Stat_Cnt_T_u16;
	VAR(uint16, AUTOMATIC) VC_TIRE_CIRCUMF_mm_T_u16;

	if (TRUE == Ind_VehCfg4_Pkt)
	{
		Ind_VehCfg4_Pkt = FALSE;
		/* PRQA S 3138 1*/
		dbkGetRxSyncVehCfg4_Pkt(VehCfg4_Pkt_T_str);

		/* PRQA S 1281 2 */ /* Caused by definition in vector macro */
		VC_VehCfg4_Stat_Cnt_T_u16 = GetValueRxVC_VehCfg4_Stat(VehCfg4_Pkt_T_str);
		VC_TIRE_CIRCUMF_mm_T_u16 = GetValueRxVC_TIRE_CIRCUMF(VehCfg4_Pkt_T_str);
		SrlComInput_WriteBits(VC_TIRE_CIRCUMF_mm_T_u16,T_A002InternalBusSig_Cnt_u8,112U,127U);

		if((VC_VehCfg4_Stat_Cnt_T_u16 == D_VEHCFG4STATPROG_CNT_U16)&&
			(VC_TIRE_CIRCUMF_mm_T_u16 == PrevVC_TIRE_CIRCUMF_mm_M_u16) &&
			(VC_TIRE_CIRCUMF_mm_T_u16 != VC_TIRE_CIRCUMF_mm_M_u16) &&
			(VC_TIRE_CIRCUMF_mm_T_u16 != 0xFFFFU))
		{
			VC_TIRE_CIRCUMF_mm_M_u16 = VC_TIRE_CIRCUMF_mm_T_u16;
			VCTireCircRcvd_Cnt_M_Lgc = TRUE;
			VC_TIRE_CIRCUMFTypH_mm_u16 = VC_TIRE_CIRCUMF_mm_T_u16;
			VCTireCircSavedTypH_Cnt_U16 = D_TIRECIRCUMFSAVD_CNT_U16;
		}
		PrevVC_TIRE_CIRCUMF_mm_M_u16 = VC_TIRE_CIRCUMF_mm_T_u16;
		
		Rte_Write_Ap_SrlComInput_CanMsgReceived_Cnt_lgc(TRUE);
	}
}

STATIC FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) DiagNTC170(void)
{
	VAR(uint16, AUTOMATIC) ElapsedTime_mS_T_u16;
	VAR(ManufModeType, AUTOMATIC) MEC_Cnt_T_enum;

	Rte_Read_Ap_SrlComInput_MEC_Cnt_enum(&MEC_Cnt_T_enum);

	if((TRUE == VC_PPPA_PrsntTypH_Cnt_M_lgc) && ((MEC_Cnt_T_enum == ProductionMode) || (MEC_Cnt_T_enum == EngineeringMode)))
	{
		if((TRUE == VCTireCircRcvd_Cnt_M_Lgc) || (VCTireCircSavedTypH_Cnt_U16 == D_TIRECIRCUMFSAVD_CNT_U16))
		{
			Rte_Call_SystemTime_GetSystemTime_mS_u32(&TireCircRcvdStartTime_mS_M_u32);
			Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_W, 0x01, NTC_STATUS_PASSED);
			PAErrInterfaceActive_Cnt_M_bit &= ~D_ERRINTACTNTC170_CNT_U32;		}
		else
		{
			Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(TireCircRcvdStartTime_mS_M_u32, &ElapsedTime_mS_T_u16);
			if (ElapsedTime_mS_T_u16 > k_TireCircRcvdTimeOut_mS_u16p0)
			{
	/*NTC170*/	Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_W, 0x01, NTC_STATUS_FAILED);
				PAErrInterfaceActive_Cnt_M_bit |= D_ERRINTACTNTC170_CNT_U32;
			}
		}
	}
	else
	{
		Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_W, 0x01, NTC_STATUS_PASSED); /*170- confirm if need timer*/
	}
}

STATIC FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) ReadESP_A5(void)
{	/* ESP_A5 - 0x124 */

	VAR(tESP_WHL_PULS, AUTOMATIC) EPS_WHL_PULS_T_str;

	VAR(uint16, AUTOMATIC) WhlPlsCnt_RL_Cnt_T_u16;
	VAR(uint16, AUTOMATIC) WhlPlsCnt_RR_Cnt_T_u16;
	VAR(uint16, AUTOMATIC) WhlPlsCntX_mm_T_u16;
	VAR(float32, AUTOMATIC) IWSS_CalcVSpd_Cnt_T_f32;
	VAR(boolean, AUTOMATIC)	PAWhlPlsCntRLValid_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC)	PAWhlPlsCntRRValid_Cnt_T_lgc;
	VAR(uint8, AUTOMATIC) PrkAssistState_Cnt_T_u08;
	VAR(uint16, AUTOMATIC) ElapsedTime_mS_T_u16;

	Rte_Read_Ap_SrlComInput_PrkAssistState_Cnt_u08(&PrkAssistState_Cnt_T_u08);

	if (TRUE == Ind_ESP_WHL_PULS)
	{
		Ind_ESP_WHL_PULS = FALSE;
		/* PRQA S 3138 1*/
		dbkGetRxSyncESP_WHL_PULS(EPS_WHL_PULS_T_str);

		Rte_Call_SystemTime_GetSystemTime_mS_u32(&ESPA5MisMsgStartTime_mS_M_u32);
		Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_MissingMsg_AH, 0x01, NTC_STATUS_PASSED);

		WhlPlsCnt_RL_Cnt_T_u16 = GetValueRxWhlPlsCnt_RL(EPS_WHL_PULS_T_str);
		WhlPlsCnt_RR_Cnt_T_u16 = GetValueRxWhlPlsCnt_RR(EPS_WHL_PULS_T_str);
		SrlComInput_WriteBits(WhlPlsCnt_RL_Cnt_T_u16,T_A002InternalBusSig_Cnt_u8,96U,103U);
		SrlComInput_WriteBits(WhlPlsCnt_RR_Cnt_T_u16,T_A002InternalBusSig_Cnt_u8,104U,111U);


		if((WhlPlsCnt_RL_Cnt_T_u16 != 0xFFU) && (WhlPlsCnt_RR_Cnt_T_u16 != 0xFFU))
		{
			Rte_Call_SystemTime_GetSystemTime_mS_u32(&ESPA5VldStartTime_mS_M_u32);
			Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_AH, 0x01, NTC_STATUS_PASSED);

			/*TODO If the first time this message is received PA is active, PrevWhlPlsCnt is garbage.*/
			if(D_PASTATEINACTIVE_CNT_U08 != PrkAssistState_Cnt_T_u08)
			{
				WhlPlsCntX_mm_T_u16 = ((WhlPlsCnt_RL_Cnt_T_u16 - PrevWhlPlsCnt_RL_Cnt_M_u16) +
										(WhlPlsCnt_RR_Cnt_T_u16 - PrevWhlPlsCnt_RR_Cnt_M_u16))*
										(VC_TIRE_CIRCUMF_mm_M_u16);

				IWSS_CalcVSpd_Cnt_T_f32 = (float32)WhlPlsCntX_mm_T_u16 * D_IWSSALCVSPD_CNT_F32;
			}
			if(TempWhlPlsCnt_RL_Cnt_M_u16 != WhlPlsCnt_RL_Cnt_T_u16)
			{
				PrevWhlPlsCnt_RL_Cnt_M_u16 = TempWhlPlsCnt_RL_Cnt_M_u16;
			}

			if(TempWhlPlsCnt_RR_Cnt_M_u16 != WhlPlsCnt_RR_Cnt_T_u16)
			{
				PrevWhlPlsCnt_RR_Cnt_M_u16 = TempWhlPlsCnt_RR_Cnt_M_u16;
			}

			TempWhlPlsCnt_RL_Cnt_M_u16 = WhlPlsCnt_RL_Cnt_T_u16;
			TempWhlPlsCnt_RR_Cnt_M_u16 = WhlPlsCnt_RR_Cnt_T_u16;
			PAWhlPlsCntRLValid_Cnt_T_lgc = TRUE;
			PAWhlPlsCntRRValid_Cnt_T_lgc = TRUE;

			Rte_Write_Ap_SrlComInput_IWSSCalcVspd_Kph_f32(IWSS_CalcVSpd_Cnt_T_f32);
		}
		else
		{
			Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(ESPA5VldStartTime_mS_M_u32, &ElapsedTime_mS_T_u16);
			if ((ElapsedTime_mS_T_u16 > k_ESPA5ValTimeOut_mS_u16p0) && (VC_PPPA_PrsntTypH_Cnt_M_lgc!= FALSE))
			{
/*NTC1C8*/			Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_AH, 0x01, NTC_STATUS_FAILED);
					PAErrInterfaceActive_Cnt_M_bit |= D_ERRINTACTNTC1C8_CNT_U32;

					if(WhlPlsCnt_RL_Cnt_T_u16 == 0xFFU)
					{
						PAWhlPlsCntRLValid_Cnt_T_lgc = FALSE;
					}
					if(WhlPlsCnt_RR_Cnt_T_u16 == 0xFFU)
					{
						PAWhlPlsCntRRValid_Cnt_T_lgc = FALSE;
					}
			}
			else
			{
				Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_AH, 0x01, NTC_STATUS_PASSED);
				PAErrInterfaceActive_Cnt_M_bit &= ~D_ERRINTACTNTC1C8_CNT_U32;
			}
		}

		Rte_Write_Ap_SrlComInput_PAWhlPlsCntRLValid_Cnt_lgc(PAWhlPlsCntRLValid_Cnt_T_lgc);
		Rte_Write_Ap_SrlComInput_PAWhlPlsCntRRValid_Cnt_lgc(PAWhlPlsCntRRValid_Cnt_T_lgc);

		Rte_Write_Ap_SrlComInput_CanMsgReceived_Cnt_lgc(TRUE);
	}
	else
	{

		Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(ESPA5MisMsgStartTime_mS_M_u32, &ElapsedTime_mS_T_u16);
		if (ElapsedTime_mS_T_u16 > k_ESPA5MsgTimeOut_mS_u16p0)
		{
			Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_AH, 0x01, NTC_STATUS_PASSED);
/*NTC1C9*/	Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_MissingMsg_AH, 0x01, NTC_STATUS_FAILED);
		}
	}
}

STATIC FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) ReadESP_A6(void)
{	/* ESP_A6 - 0x158 */

	VAR(tWHEEL_SPEED, AUTOMATIC) EPS_WHL_SPD_T_str;

	VAR(uint16, AUTOMATIC) WWhlRPM_FL_Cnt_T_u16;
	VAR(uint16, AUTOMATIC) WWhlRPM_FR_Cnt_T_u16;
	VAR(uint16, AUTOMATIC) WWhlRPM_RL_Cnt_T_u16;
	VAR(uint16, AUTOMATIC) WWhlRPM_RR_Cnt_T_u16;
	VAR(uint8, AUTOMATIC) WWhlDir_RL_Stat_Cnt_T_u08;
	VAR(uint8, AUTOMATIC) WWhlDir_RR_Stat_Cnt_T_u08;
	VAR(uint16, AUTOMATIC) ElapsedTime_mS_T_u16;

	if (TRUE == Ind_WHEEL_SPEED)
	{
		Ind_WHEEL_SPEED = FALSE;
		/* PRQA S 3138 1*/
		dbkGetRxSyncWHEEL_SPEED(EPS_WHL_SPD_T_str);

		Rte_Call_SystemTime_GetSystemTime_mS_u32(&ESPA6MisMsgStartTime_mS_M_u32);
		Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_MissingMsg_ESP_A6, 0x01, NTC_STATUS_PASSED);

		WWhlRPM_FL_Cnt_T_u16 = GetValueRxWhlRPM_FL(EPS_WHL_SPD_T_str);
		WWhlRPM_FR_Cnt_T_u16 = GetValueRxWhlRPM_FR(EPS_WHL_SPD_T_str);
		WWhlRPM_RL_Cnt_T_u16 = GetValueRxWhlRPM_RL(EPS_WHL_SPD_T_str);
		WWhlRPM_RR_Cnt_T_u16 = GetValueRxWhlRPM_RR(EPS_WHL_SPD_T_str);
		WWhlDir_RL_Stat_Cnt_T_u08 = GetValueRxWhlDir_RL_Stat(EPS_WHL_SPD_T_str);
		WWhlDir_RR_Stat_Cnt_T_u08 = GetValueRxWhlDir_RR_Stat(EPS_WHL_SPD_T_str);

		SrlComInput_WriteBits(WWhlRPM_RL_Cnt_T_u16,T_A002InternalBusSig_Cnt_u8,48U,63U);
		SrlComInput_WriteBits(WWhlDir_RL_Stat_Cnt_T_u08,T_A002InternalBusSig_Cnt_u8,70U,71U);
		SrlComInput_WriteBits(0x00U,T_A002InternalBusSig_Cnt_u8,64U,69U);
		SrlComInput_WriteBits(WWhlRPM_RR_Cnt_T_u16,T_A002InternalBusSig_Cnt_u8,72U,87U);
		SrlComInput_WriteBits(WWhlDir_RR_Stat_Cnt_T_u08,T_A002InternalBusSig_Cnt_u8,94U,95U);
		SrlComInput_WriteBits(0x00U,T_A002InternalBusSig_Cnt_u8,88U,93U);

		if((WWhlDir_RR_Stat_Cnt_T_u08 != 0x03U) && (WWhlDir_RL_Stat_Cnt_T_u08 != 0x03U))
		{
			Rte_Call_SystemTime_GetSystemTime_mS_u32(&ESPA6VldStartTime_mS_M_u32);
			Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_ESP_A6, 0x01, NTC_STATUS_PASSED);

			SrlComInput_WriteBits((uint32)WWhlRPM_FL_Cnt_T_u16,T_A001InternalBusSig_Cnt_u8,256U,271U);
			SrlComInput_WriteBits((uint32)WWhlRPM_FR_Cnt_T_u16,T_A001InternalBusSig_Cnt_u8,272U,287U);

			Rte_Write_Ap_SrlComInput_CanMsgReceived_Cnt_lgc(TRUE);

			if((WWhlRPM_RR_Cnt_T_u16 == 0x0U)&&
					(WWhlRPM_RL_Cnt_T_u16 == 0x0U)&&
					(WWhlDir_RL_Stat_Cnt_T_u08 == 0x0U)&&
					(WWhlDir_RR_Stat_Cnt_T_u08 == 0x0U)&&
					(VehSpd_Kph_M_f32 < D_WHLRPMVEHSPLIM_KPH_F32))
			{
				Rte_Write_Ap_SrlComInput_PAWheelCriteriaMet_Cnt_lgc(TRUE);
			}
			else
			{
				Rte_Write_Ap_SrlComInput_PAWheelCriteriaMet_Cnt_lgc(FALSE);
			}

			Rte_Write_Ap_SrlComInput_PAWhlDirRLStat_Cnt_u08(WWhlDir_RL_Stat_Cnt_T_u08);
			Rte_Write_Ap_SrlComInput_PAWhlDirRRStat_Cnt_u08(WWhlDir_RR_Stat_Cnt_T_u08);
		}
		else
		{
			Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(ESPA6VldStartTime_mS_M_u32, &ElapsedTime_mS_T_u16);
			if ((ElapsedTime_mS_T_u16 > k_ESPA6ValTimeOut_mS_u16p0)  && (VC_PPPA_PrsntTypH_Cnt_M_lgc == TRUE))
			{
/*NTC1D0*/			Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_ESP_A6, 0x01, NTC_STATUS_FAILED);
					PAErrInterfaceActive_Cnt_M_bit |= D_ERRINTACTNTC1D0_CNT_U32;
			}
			else
			{
				Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_ESP_A6, 0x01, NTC_STATUS_PASSED);
				PAErrInterfaceActive_Cnt_M_bit &= ~D_ERRINTACTNTC1D0_CNT_U32;
			}
		}
	}
	else
	{

		Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(ESPA6MisMsgStartTime_mS_M_u32, &ElapsedTime_mS_T_u16);
		if (ElapsedTime_mS_T_u16 > k_ESPA6MsgTimeOut_mS_u16p0)
		{
			Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_ESP_A6, 0x01, NTC_STATUS_PASSED);
/*NTC1D1*/	Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_MissingMsg_ESP_A6, 0x01, NTC_STATUS_FAILED);
		}
	}

}

STATIC FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) ReadVehCfg5(void)
{	/* VehCfg5 - 0x44A */

	VAR(tVehCfg5_Pkt, AUTOMATIC) VehCfg5_T_str;

	VAR(uint16,  AUTOMATIC) VC_VehCfg5_Stat_Cnt_T_u16;
	VAR(boolean, AUTOMATIC) VC_PPPA_Prsnt_Cnt_T_lgc;
	VAR(uint16, AUTOMATIC) ElapsedTime_mS_T_u16;

	if (TRUE == Ind_VehCfg5_Pkt)
	{
		Ind_VehCfg5_Pkt = FALSE;
		/* PRQA S 3138 1*/
		dbkGetRxSyncVehCfg5_Pkt(VehCfg5_T_str);

		Rte_Call_SystemTime_GetSystemTime_mS_u32(&VehCfg5MisMsgStartTime_mS_M_u32);
		Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_MissingMsg_V, 0x01, NTC_STATUS_PASSED);

		VC_VehCfg5_Stat_Cnt_T_u16 = GetValueRxVC_VehCfg5_Stat(VehCfg5_T_str);
		VC_PPPA_Prsnt_Cnt_T_lgc = GetValueRxVC_PPPA_Prsnt(VehCfg5_T_str);

		if((VC_VehCfg5_Stat_Cnt_T_u16 == D_VEHCFGSTATPROG_CNT_U16)&&
			(VC_PPPA_Prsnt_Cnt_T_lgc == PrevVC_PPPA_PrsntTypH_Cnt_M_lgc) &&
			(VC_PPPA_Prsnt_Cnt_T_lgc != VC_PPPA_PrsntTypH_Cnt_M_lgc))
		{
			VC_PPPA_PrsntTypH_Cnt_M_lgc = VC_PPPA_Prsnt_Cnt_T_lgc;
		}
		PrevVC_PPPA_PrsntTypH_Cnt_M_lgc = VC_PPPA_Prsnt_Cnt_T_lgc;
		
		Rte_Write_Ap_SrlComInput_CanMsgReceived_Cnt_lgc(TRUE);
	}
	else
	{
		Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(VehCfg5MisMsgStartTime_mS_M_u32, &ElapsedTime_mS_T_u16);
		if (ElapsedTime_mS_T_u16 > k_VehCfg5MsgTimeOut_mS_u16p0)
		{
/*NTC169*/	Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_MissingMsg_V, 0x01, NTC_STATUS_FAILED);
		}
	}


	Rte_Write_Ap_SrlComInput_PrkAsstFuncPresent_Cnt_lgc(VC_PPPA_PrsntTypH_Cnt_M_lgc);
}

STATIC FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) ReadHALF_MTO_SteerControl(void)
{	/* HALF_MTO_SteerControl - 0x292 */

	VAR(tHaLF_StrCtrl, AUTOMATIC) HaLF_StrCtrl_T_str;

	VAR(uint16, AUTOMATIC) MTO_HALFSystemSts_Cnt_T_u16;
	VAR(boolean, AUTOMATIC) MotorTorqueOverlayIntActivation_Cnt_T_lgc;
	VAR(uint16, AUTOMATIC) RawMotorTorqueOverlaySteeringReq_Nm_T_u16;
	VAR(float32, AUTOMATIC) MotorTorqueOverlaySteeringReq_Nm_T_f32;
	VAR(uint16, AUTOMATIC) MC_292h_Cnt_T_u16;
	VAR(uint16, AUTOMATIC) ElapsedTime_mS_T_u16;
	VAR(uint8, AUTOMATIC) HaLFState_Cnt_T_u08;
	VAR(boolean, AUTOMATIC) MTO_HALFSystemSts_Cnt_T_lgc;
	VAR(boolean,  AUTOMATIC) ReceivedDataValid_Cnt_T_lgc = TRUE;
	VAR(uint8, AUTOMATIC) HALFDriveStyleSts_Cnt_T_u08;

	Rte_Read_Ap_SrlComInput_HaLFState_Cnt_u08(&HaLFState_Cnt_T_u08);

	if (TRUE == Ind_HaLF_StrCtrl)
	{
		Ind_HaLF_StrCtrl = FALSE;
		/* PRQA S 3138 1*/
		dbkGetRxSyncHaLF_StrCtrl(HaLF_StrCtrl_T_str);

		Rte_Call_SystemTime_GetSystemTime_mS_u32(&HalfMisMsgStartTime_mS_M_u32);
		Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_MissingMsg_AA, 0x01, NTC_STATUS_PASSED);

		HaLFErrInterfaceActive_Cnt_M_bit &= ~D_ERRINTACTNTC191_CNT_U32;

		/*NTC192*/
		ReceivedDataValid_Cnt_T_lgc &= DiagCRC292(HaLF_StrCtrl_T_str);
		/*NTC193*/
		MC_292h_Cnt_T_u16 = GetValueRxMC_292h(HaLF_StrCtrl_T_str);
		ReceivedDataValid_Cnt_T_lgc &= DiagNTC193(MC_292h_Cnt_T_u16);

		if (TRUE == ReceivedDataValid_Cnt_T_lgc)
		{
			MTO_HALFSystemSts_Cnt_T_u16 = GetValueRxMTO_HALFSystemSts(HaLF_StrCtrl_T_str);
			SrlComInput_WriteBits(MTO_HALFSystemSts_Cnt_T_u16,T_A003InternalBusSig_Cnt_u8,5U,5U);
			MotorTorqueOverlayIntActivation_Cnt_T_lgc = GetValueRxMotorTorqueOverlayIntActivation(HaLF_StrCtrl_T_str);
			SrlComInput_WriteBits(MotorTorqueOverlayIntActivation_Cnt_T_lgc,T_A003InternalBusSig_Cnt_u8,7U,7U);

			HALFDriveStyleSts_Cnt_T_u08 = GetValueRxMTO_HALFDriveStyleSts(HaLF_StrCtrl_T_str);
			SrlComInput_WriteBits(HALFDriveStyleSts_Cnt_T_u08,T_A003InternalBusSig_Cnt_u8,45U,47U);

			RawMotorTorqueOverlaySteeringReq_Nm_T_u16 = GetValueRxMotorTorqueOverlaySteeringReq(HaLF_StrCtrl_T_str);
			SrlComInput_WriteBits(RawMotorTorqueOverlaySteeringReq_Nm_T_u16,T_A003InternalBusSig_Cnt_u8,8U,23U);
			MotorTorqueOverlaySteeringReq_Nm_T_f32 = FPM_FixedToFloat_m(RawMotorTorqueOverlaySteeringReq_Nm_T_u16,u7p9_T);
			MotorTorqueOverlaySteeringReq_Nm_T_f32 = k_MtrTorqOvrlStrReqPol_Cnt_f32 * (MotorTorqueOverlaySteeringReq_Nm_T_f32 - D_MTRTORQOVERLAYSTRREQ_CNT_F32);

			SrlComInput_WriteBits(HaLFFuncPresentTypH_Cnt_M_lgc,T_A003InternalBusSig_Cnt_u8,41U,41U);
			SrlComInput_WriteBits(0x00U,T_A003InternalBusSig_Cnt_u8,40U,40U);

			/*If Transition is to Inactive or recoverabale state without going thru Active state then no need of HalfFuncPresent*/
			if((D_HALFSTATEINACTIVE_CNT_U08 == HaLFState_Cnt_T_u08) ||
					(D_HALFSTATERECOVERABLE_CNT_U08 == HaLFState_Cnt_T_u08) )
			{
			/*NTC194*/		DiagNTC194( MotorTorqueOverlaySteeringReq_Nm_T_f32, HaLFState_Cnt_T_u08 );
			}
/*NTC1C6*/	DiagNTC1C6(MotorTorqueOverlayIntActivation_Cnt_T_lgc); /* DIAG HALF PRESENT */

			if (TRUE == HaLFFuncPresentTypH_Cnt_M_lgc )
			{
/*NTC190*/		DiagNTC190(MTO_HALFSystemSts_Cnt_T_u16);

				/*If going to Inactive or recoverable state through Active state then we neeed to have Halffuncpresent true*/
				if((D_HALFSTATEINACTIVE_CNT_U08 == HaLFState_Cnt_T_u08) ||
					(D_HALFSTATERECOVERABLE_CNT_U08 == HaLFState_Cnt_T_u08)||
					(D_HALFSTATEACTIVE_CNT_U08 == HaLFState_Cnt_T_u08))
				{
/*NTC194*/		DiagNTC194( MotorTorqueOverlaySteeringReq_Nm_T_f32, HaLFState_Cnt_T_u08 );
				}
				Rte_Write_Ap_SrlComInput_PrevHaLFTrqOvCmdRqst_MtrNm_f32(HaLFTrqOvCmdRqst_MtrNm_M_f32);
/*NTC195*/		HaLFTrqOvCmdRqst_MtrNm_M_f32 = DiagNTC195( MotorTorqueOverlaySteeringReq_Nm_T_f32, HaLFState_Cnt_T_u08 );
/*NTC196*/		DiagNTC196( HaLFState_Cnt_T_u08, MotorTorqueOverlaySteeringReq_Nm_T_f32);
/*NTC0E9*/		if(TRUE == NetCfg_ESCTypH_Cnt_M_lgc)
				{
					DiagNTC0E9(MotorTorqueOverlaySteeringReq_Nm_T_f32,HaLFState_Cnt_T_u08);
				}
/*NTC0EE*/		DiagNTC0EE(HALFDriveStyleSts_Cnt_T_u08,HaLFState_Cnt_T_u08);

				if(MTO_HALFSystemSts_Cnt_T_u16 == 0U)
				{
					MTO_HALFSystemSts_Cnt_T_lgc = FALSE;
				}
				else
				{
					MTO_HALFSystemSts_Cnt_T_lgc = TRUE;
				}

				Rte_Write_Ap_SrlComInput_HaLFExtSystemFltActive_Cnt_lgc(MTO_HALFSystemSts_Cnt_T_lgc);

				Rte_Write_Ap_SrlComInput_PrevHaLFEnableRqst_Cnt_lgc(EnableRqst_Cnt_M_lgc);
				if((TRUE == MotorTorqueOverlayIntActivation_Cnt_T_lgc) && (TRUE == EnableTorqueOverlay_Cnt_M_lgc))
				{
					Rte_Write_Ap_SrlComInput_HaLFEnableRqst_Cnt_lgc(TRUE);
					EnableRqst_Cnt_M_lgc = TRUE;
				}
				else
				{
					Rte_Write_Ap_SrlComInput_HaLFEnableRqst_Cnt_lgc(FALSE);
					EnableRqst_Cnt_M_lgc = FALSE;
				}
			}
			else
			{
				Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_AA, 0x01, NTC_STATUS_PASSED);
			}
			PrevMtrTorqOverlayStrReq_Cnt_M_f32 = MotorTorqueOverlaySteeringReq_Nm_T_f32;
		}
		else
		{
			ClearHALFNTC_RcvdMesgNotValid();

		}
		
	Rte_Write_Ap_SrlComInput_CanMsgReceived_Cnt_lgc(TRUE);
	}
	else
	{


		Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(HalfMisMsgStartTime_mS_M_u32, &ElapsedTime_mS_T_u16);
		if (ElapsedTime_mS_T_u16 > k_HalfMsgTimeOut_mS_u16p0)
		{
			ClearHALFNTC_MessageNotRcvd();/* all NTC's should need HalfFuncPresent To be true ??*/
			MC_292h_Bad_Cnt_M_u16 = 0;

			if(TRUE == HaLFFuncPresentTypH_Cnt_M_lgc )
			{
/*NTC191*/	Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_MissingMsg_AA, 0x01, NTC_STATUS_FAILED);
			}
			else
			{
			Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_MissingMsg_AA, 0x01, NTC_STATUS_PASSED);
			}
			HaLFErrInterfaceActive_Cnt_M_bit |= D_ERRINTACTNTC191_CNT_U32;

		}
	}
	Rte_Write_Ap_SrlComInput_HaLFTrqOvCmdRqst_MtrNm_f32(HaLFTrqOvCmdRqst_MtrNm_M_f32);
}

STATIC FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) DiagNTC0E9( VAR(float32, AUTOMATIC) MotorTorqueOverlaySteeringReq_HwNm_T_f32,VAR(uint8, AUTOMATIC) HaLFState_Cnt_T_u08)
{
	if((HaLFState_Cnt_T_u08 == D_HALFSTATEACTIVE_CNT_U08) && (( DSTState_Cnt_M_u8 == TOCSTATE_ACTIVEMODE05) ||
			( DSTState_Cnt_M_u8 == TOCSTATE_ACTIVEMODE06) || ( DSTState_Cnt_M_u8 == TOCSTATE_ACTIVEMODE07)))

	{
		if (Abs_f32_m(MotorTorqueOverlaySteeringReq_HwNm_T_f32 - PrevMtrTrqOvrlyStrngReq_Nm_M_f32) > MtrTrqOvrlyStrRqMax_Nm_M_f32)
		{
			Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_VLF_09, 0x01, NTC_STATUS_FAILED);
			MtrTrqOvrlyStrRqMax_Nm_M_f32 = MtrTrqOvrlyStrRqMax_Nm_M_f32 - k_MaxHlfRmpOutRt_Nm_F32;
			HaLFIntSystemFltActive_Cnt_M_bit |= D_SYSFLTACTNTC0E9_CNT_U16;

			if( MtrTrqOvrlyStrRqMax_Nm_M_f32 < k_MaxHlfRmpOutRt_Nm_F32)
			{
				MtrTrqOvrlyStrRqMax_Nm_M_f32 = 0.0f;
			}
		}
		else
		{
			Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_VLF_09, 0x01, NTC_STATUS_PASSED);
			MtrTrqOvrlyStrRqMax_Nm_M_f32 = k_MtrTrqOvrlyStrRqMax_Nm_f32;
			HaLFIntSystemFltActive_Cnt_M_bit &= ~D_SYSFLTACTNTC0E9_CNT_U16;

		}
	}
	PrevMtrTrqOvrlyStrngReq_Nm_M_f32 = MotorTorqueOverlaySteeringReq_HwNm_T_f32;

}
STATIC FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) DiagNTC196( VAR(uint8, AUTOMATIC) HaLFState_Cnt_T_u08, VAR(float32, AUTOMATIC) HaLFStateReq_Nm_T_f32 )
{
	VAR(uint32, AUTOMATIC) MaxTrqElapsedTime_mS_T_u32;

	if(HaLFState_Cnt_T_u08 == D_HALFSTATEACTIVE_CNT_U08)
	{
		/* PRQA S 3415 2*/ /* Abs_f32_m is a macro, function side effects are not a risk */
		if(( Abs_f32_m( HaLFStateReq_Nm_T_f32) > (k_MsgMaxHalfTorqTO_Nm_f32 - D_MTRTQOVLYSTRREQRES_f32))&&
				( Abs_f32_m( HaLFStateReq_Nm_T_f32) < (k_MsgMaxHalfTorqTO_Nm_f32 + D_MTRTQOVLYSTRREQRES_f32)))

		{
			Rte_Call_SystemTime_DtrmnElapsedTime_mS_u32(HalfMaxTrqStartTime_mS_M_u32, &MaxTrqElapsedTime_mS_T_u32);
			if(MaxTrqElapsedTime_mS_T_u32 > k_MsgMaxHalfTorqTO_mS_u32p0)
			{
				Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DataOtherFltMsg_AA, 0x01, NTC_STATUS_FAILED);
				HaLFIntSystemFltActive_Cnt_M_bit |= D_SYSFLTACTNTC196_CNT_U16;
			}
		}
		else
		{
			Rte_Call_SystemTime_GetSystemTime_mS_u32(&HalfMaxTrqStartTime_mS_M_u32);
			Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DataOtherFltMsg_AA, 0x01, NTC_STATUS_PASSED);
			HaLFIntSystemFltActive_Cnt_M_bit &= ~D_SYSFLTACTNTC196_CNT_U16;
		}
	}
/*	else
	{
		Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DataOtherFltMsg_AA, 0x01, NTC_STATUS_PASSED);
	}*/
}

STATIC FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) DiagNTC0EE( VAR(uint8, AUTOMATIC) HALFDriveStyleSts_Cnt_T_u08,VAR(uint8, AUTOMATIC) HaLFState_Cnt_T_u08 )
{
	if(HaLFState_Cnt_T_u08 == D_HALFSTATEACTIVE_CNT_U08)
		{
		/* PRQA S 4445 1*/
		if(Abs_f32_m(DesiredTunPersTypH_Cnt_M_u08 - HALFDriveStyleSts_Cnt_T_u08) > k_PerMisMchFltThr_Cnt_u08)
		{
			PerMisMchFlt_Cnt_M_u16++;
			if(PerMisMchFlt_Cnt_M_u16 > k_PerMisMchCntLmt_Cnt_u16)
			{
				Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_VLF_14, 0x01, NTC_STATUS_FAILED);
				HaLFIntSystemFltActive_Cnt_M_bit |= D_SYSFLTACTNTC0EE_CNT_U16;
			}
			else
			{
				Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_VLF_14, 0x01, NTC_STATUS_PASSED);
			}
		}
		else
		{
			Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_VLF_14, 0x01, NTC_STATUS_PASSED);
			PerMisMchFlt_Cnt_M_u16 = 0;
			HaLFIntSystemFltActive_Cnt_M_bit &= ~D_SYSFLTACTNTC0EE_CNT_U16;
		}
	}
}


STATIC FUNC(float32, RTE_AP_SRLCOMINPUT_APPL_CODE) DiagNTC195( VAR(float32, AUTOMATIC) MotorTorqueOverlaySteeringReq_HwNm_T_f32,
															VAR(uint8, AUTOMATIC) HaLFState_Cnt_T_u08)
{
	VAR(float32,  AUTOMATIC) HaLFTrqOvCmdRqst_MtrNm_T_f32;

	HaLFTrqOvCmdRqst_MtrNm_T_f32 = MotorTorqueOverlaySteeringReq_HwNm_T_f32;

	if(D_HALFSTATEACTIVE_CNT_U08 == HaLFState_Cnt_T_u08)
	{
		if(Abs_f32_m(MotorTorqueOverlaySteeringReq_HwNm_T_f32 - PrevMtrTorqOverlayStrReq_Cnt_M_f32) > HaLFTrqOvrlSlewLmt_Nm_M_f32)
		{
			HaLFTrqOvrlChngeAcc_Cnt_M_u16 = DiagPStep_m(HaLFTrqOvrlChngeAcc_Cnt_M_u16, k_HaLFTrqOvrlSlewDiag_Cnt_str);

			if((PrevMtrTorqOverlayStrReq_Cnt_M_f32 - MotorTorqueOverlaySteeringReq_HwNm_T_f32)  > 0.0f)
			{
				HaLFTrqOvCmdRqst_MtrNm_T_f32 = PrevMtrTorqOverlayStrReq_Cnt_M_f32 - HaLFTrqOvrlSlewLmt_Nm_M_f32;
			}
			else
			{
				HaLFTrqOvCmdRqst_MtrNm_T_f32 = PrevMtrTorqOverlayStrReq_Cnt_M_f32 + HaLFTrqOvrlSlewLmt_Nm_M_f32;

			}
		}
		else
		{
			HaLFTrqOvrlChngeAcc_Cnt_M_u16 = DiagNStep_m(HaLFTrqOvrlChngeAcc_Cnt_M_u16, k_HaLFTrqOvrlSlewDiag_Cnt_str);
		}

		if (DiagFailed_m( HaLFTrqOvrlChngeAcc_Cnt_M_u16, k_HaLFTrqOvrlSlewDiag_Cnt_str) == TRUE)
		{
			Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DataRateFltMsg_AA, 0x01, NTC_STATUS_FAILED);
			HaLFIntSystemFltActive_Cnt_M_bit |= D_SYSFLTACTNTC195_CNT_U16;

		}
		else
		{
			Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DataRateFltMsg_AA, 0x01, NTC_STATUS_PASSED);
			HaLFIntSystemFltActive_Cnt_M_bit &= ~D_SYSFLTACTNTC195_CNT_U16;
		}
	}
	return HaLFTrqOvCmdRqst_MtrNm_T_f32;
}
STATIC FUNC(boolean, RTE_AP_SRLCOMINPUT_APPL_CODE) DiagNTC194( VAR(float32, AUTOMATIC) MotorTorqueOverlaySteeringReq_Cnt_T_f32,
																	VAR(uint8, AUTOMATIC) HaLFState_Cnt_T_u08)
{
	VAR(boolean,  AUTOMATIC) IsCmdValid_Cnt_T_lgc = TRUE;
	
		if(Abs_f32_m(MotorTorqueOverlaySteeringReq_Cnt_T_f32) > HalfTrqMax_Nm_M_f32)
		{
			IsCmdValid_Cnt_T_lgc = FALSE;

				if(Abs_f32_m(PrevMtrTorqOverlayStrReq_Cnt_M_f32) > HalfTrqMax_Nm_M_f32)
				{
					Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DataRngFltMsg_AA, 0x01, NTC_STATUS_FAILED);
					HaLFIntSystemFltActive_Cnt_M_bit |= D_SYSFLTACTNTC194_CNT_U16;
				}
				else
				{
					Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DataRngFltMsg_AA, 0x01, NTC_STATUS_PASSED);
				}


		}
		else
		{
			Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DataRngFltMsg_AA, 0x01, NTC_STATUS_PASSED);
			HaLFIntSystemFltActive_Cnt_M_bit &=~ D_SYSFLTACTNTC194_CNT_U16;

		}
	
	return IsCmdValid_Cnt_T_lgc;
}

STATIC FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) DiagNTC1C6( VAR(boolean, AUTOMATIC) MotorTorqueOverlayIntActivation_Cnt_T_lgc )
{
	if((FALSE == HaLFFuncPresentTypH_Cnt_M_lgc) &&
			(TRUE == MotorTorqueOverlayIntActivation_Cnt_T_lgc))
	{
		Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DataOtherFltMsg_AG, 0x01, NTC_STATUS_FAILED);
		HaLFIntSystemFltActive_Cnt_M_bit |= D_SYSFLTACTNTC1C6_CNT_U16;

	}
	else
	{
		Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DataOtherFltMsg_AG, 0x01, NTC_STATUS_PASSED);
		HaLFIntSystemFltActive_Cnt_M_bit &= ~D_SYSFLTACTNTC1C6_CNT_U16;
	}
}

STATIC FUNC(boolean, RTE_AP_SRLCOMINPUT_APPL_CODE) DiagNTC193( VAR(uint16, AUTOMATIC) MC_292h_Cnt_T_u16 )
{
	VAR(boolean,  AUTOMATIC) CounterValid_T_Cnt_lgc = TRUE;


	if ((((PrevMC_292h_Cnt_M_u16 + 1) % D_COUNTERCYCLE16_CNT_U16) == MC_292h_Cnt_T_u16  ) ||
			(((PrevMC_292h_Cnt_M_u16 + 2) % D_COUNTERCYCLE16_CNT_U16) == MC_292h_Cnt_T_u16 ))
	{
		MC_292h_Bad_Cnt_M_u16 = 0u;
	}
	else
	{
		MC_292h_Bad_Cnt_M_u16++;
		CounterValid_T_Cnt_lgc = FALSE;
	}

	PrevMC_292h_Cnt_M_u16 = MC_292h_Cnt_T_u16;

	if(MC_292h_Bad_Cnt_M_u16 >= k_MC292hMsg_Cnt_u16)
	{
		Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_PgrsCntFltMsg_AA, 0x01, NTC_STATUS_FAILED);
		HaLFIntSystemFltActive_Cnt_M_bit |= D_SYSFLTACTNTC193_CNT_U16;

	}
	else
	{
		Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_PgrsCntFltMsg_AA, 0x01, NTC_STATUS_PASSED);
		HaLFIntSystemFltActive_Cnt_M_bit &= ~D_SYSFLTACTNTC193_CNT_U16;

	}

	return CounterValid_T_Cnt_lgc;
}

STATIC FUNC(boolean, RTE_AP_SRLCOMINPUT_APPL_CODE) DiagNTC13B_MC11C( VAR(uint16, AUTOMATIC) MC_11Ch_Cnt_T_u16 )
{
	VAR(boolean,  AUTOMATIC) CounterValid_T_Cnt_lgc = TRUE;
	if (((PrevMC_11Ch_Cnt_M_u16 + 1) % D_COUNTERCYCLE16_CNT_U16) != MC_11Ch_Cnt_T_u16  )
	{
		MC_11Ch_Bad_Cnt_M_u16++;
		CounterValid_T_Cnt_lgc = FALSE;
	}
	else
	{
		MC_11Ch_Bad_Cnt_M_u16 = 0;
	}
	PrevMC_11Ch_Cnt_M_u16 = MC_11Ch_Cnt_T_u16;

	if(MC_11Ch_Bad_Cnt_M_u16 >= k_MC11ChMsg_Cnt_u16)
	{
		Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_PgrsCntFltMsg_P, 0x01, NTC_STATUS_FAILED);

			HaLFIntSystemFltActive_Cnt_M_bit |= D_SYSFLTACTNTC13B_CNT_U16;
			PAIntSystemFltActive_Cnt_M_bit |= D_SYSFLTACTNTC13B_CNT_U16;

	}
	else
	{
		Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_PgrsCntFltMsg_P, 0x01, NTC_STATUS_PASSED);
		HaLFIntSystemFltActive_Cnt_M_bit &= ~D_SYSFLTACTNTC13B_CNT_U16;
		PAIntSystemFltActive_Cnt_M_bit &= ~D_SYSFLTACTNTC13B_CNT_U16;
	}


	return CounterValid_T_Cnt_lgc;
}


STATIC FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) DiagNTC190( VAR(uint16, AUTOMATIC) MTO_HALFSystemSts_Cnt_T_u16 )
{
	if((D_HALFSYSSTSFAULTED_U16 == MTO_HALFSystemSts_Cnt_T_u16)&&
			(D_HALFSYSSTSFAULTED_U16 == PrevHALFSystemSts_Cnt_M_u16))
	{
		Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_AA, 0x01, NTC_STATUS_FAILED);
		HaLFErrInterfaceActive_Cnt_M_bit |= D_ERRINTACTNTC190_CNT_U32;
	}
	else
	{
		Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_AA, 0x01, NTC_STATUS_PASSED);
		HaLFErrInterfaceActive_Cnt_M_bit  &= ~D_ERRINTACTNTC190_CNT_U32;
	}

	PrevHALFSystemSts_Cnt_M_u16 = MTO_HALFSystemSts_Cnt_T_u16;
}

STATIC FUNC(boolean, RTE_AP_SRLCOMINPUT_APPL_CODE) DiagCRC292( VAR(tHaLF_StrCtrl, AUTOMATIC) HaLF_StrCtrl_T_str )
{
	VAR(boolean,  AUTOMATIC) ReceivedDataValid_Cnt_T_lgc;

	ReceivedDataValid_Cnt_T_lgc = IsCRC8Valid(HaLF_StrCtrl_T_str.c, 5, GetValueRxCRC_292h(HaLF_StrCtrl_T_str));

	if( FALSE == ReceivedDataValid_Cnt_T_lgc)
	{
		CRC292DiagAcc_Cnt_M_u16++;
	}
	else
	{
		CRC292DiagAcc_Cnt_M_u16 = 0U;
	}

	if (CRC292DiagAcc_Cnt_M_u16 > k_CRC292DiagMsg_Cnt_u16)
	{
		Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_CRCFltMsg_AA, 0x01, NTC_STATUS_FAILED);
		HaLFIntSystemFltActive_Cnt_M_bit |= D_SYSFLTACTNTC192_CNT_U16;
	}
	else
	{
		Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_CRCFltMsg_AA, 0x01, NTC_STATUS_PASSED);
		HaLFIntSystemFltActive_Cnt_M_bit &= ~D_SYSFLTACTNTC192_CNT_U16;
	}
	return ReceivedDataValid_Cnt_T_lgc;
}

STATIC FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) ReadNET_CFG_PT(void)
{	/* NET_CFG_PT - 0x3E4 */

	VAR(tNET_CFG_DATA_PT, AUTOMATIC) NET_CFG_DATA_PT_T_str;

	VAR(boolean, AUTOMATIC) NetCfg_PTS_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) NetCfg_HaLF_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) NetCfg_ESC_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) NetCfg_CBC_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) NetCfg_ECM_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) NetCfg_IC_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) NetCfg_SCCM_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) NetCfg_TCM_Cnt_T_lgc;

	VAR(uint16, AUTOMATIC) ElapsedTime_mS_T_u16;


	if (TRUE == Ind_NET_CFG_DATA_PT)
	{
		Ind_NET_CFG_DATA_PT = FALSE;

		/* PRQA S 3138 1*/
		dbkGetRxSyncNET_CFG_DATA_PT(NET_CFG_DATA_PT_T_str);

		NET_CFG_STAT_PT_Cnt_M_u16 = GetValueRxNET_CFG_STAT_PT(NET_CFG_DATA_PT_T_str);
		NetCfg_HaLF_Cnt_T_lgc = GetValueRxNetCfg_HaLF(NET_CFG_DATA_PT_T_str);
		NetCfg_PTS_Cnt_T_lgc = GetValueRxNetCfg_PTS(NET_CFG_DATA_PT_T_str);
		NetCfg_ESC_Cnt_T_lgc = GetValueRxNetCfg_ESC(NET_CFG_DATA_PT_T_str);
		NetCfg_CBC_Cnt_T_lgc = GetValueRxNetCfg_CBC_PT(NET_CFG_DATA_PT_T_str);
		NetCfg_ECM_Cnt_T_lgc = GetValueRxNetCfg_ECM(NET_CFG_DATA_PT_T_str);
		NetCfg_IC_Cnt_T_lgc = GetValueRxNetCfg_IC(NET_CFG_DATA_PT_T_str);
		NetCfg_SCCM_Cnt_T_lgc = GetValueRxNetCfg_SCCM(NET_CFG_DATA_PT_T_str);
		NetCfg_TCM_Cnt_T_lgc = GetValueRxNetCfg_TCM(NET_CFG_DATA_PT_T_str);

		Rte_Call_SystemTime_GetSystemTime_mS_u32(&NETCFGPTMisMsgStartTime_mS_M_u32);
		Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_MissingMsg_W, 0x01, NTC_STATUS_PASSED);

		if(D_NETCFGSTATPROG_CNT_U16 == NET_CFG_STAT_PT_Cnt_M_u16)
		{
			NetCfgStatRcvdTypH_PT_Cnt_M_lgc = TRUE;
			Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DataOtherFltMsg_W, 0x01, NTC_STATUS_PASSED);

			if( NetCfg_PTS_Cnt_T_lgc == PrevNetCfg_PTS_Cnt_M_lgc)
			{
				NetCfg_PTSTypH_Cnt_M_lgc = NetCfg_PTS_Cnt_T_lgc;
			}
			PrevNetCfg_PTS_Cnt_M_lgc = NetCfg_PTS_Cnt_T_lgc;

			if( NetCfg_HaLF_Cnt_T_lgc == PrevNetCfg_HaLF_Cnt_M_lgc)
			{
				NetCfg_HaLFTypH_Cnt_M_lgc = NetCfg_HaLF_Cnt_T_lgc;
			}
			PrevNetCfg_HaLF_Cnt_M_lgc = NetCfg_HaLF_Cnt_T_lgc;

			if( NetCfg_ESC_Cnt_T_lgc == PrevNetCfg_ESC_Cnt_M_lgc)
			{
				NetCfg_ESCTypH_Cnt_M_lgc = NetCfg_ESC_Cnt_T_lgc;
			}
			PrevNetCfg_ESC_Cnt_M_lgc = NetCfg_ESC_Cnt_T_lgc;

			if( NetCfg_CBC_Cnt_T_lgc == PrevNetCfg_CBC_Cnt_M_lgc)
			{
				NetCfg_CBCTypH_Cnt_M_lgc = NetCfg_CBC_Cnt_T_lgc;
			}
			PrevNetCfg_CBC_Cnt_M_lgc = NetCfg_CBC_Cnt_T_lgc;

			if( NetCfg_ECM_Cnt_T_lgc == PrevNetCfg_ECM_Cnt_M_lgc)
			{
				NetCfg_ECMTypH_Cnt_M_lgc = NetCfg_ECM_Cnt_T_lgc;
			}
			PrevNetCfg_ECM_Cnt_M_lgc = NetCfg_ECM_Cnt_T_lgc;

			if( NetCfg_IC_Cnt_T_lgc == PrevNetCfg_IC_Cnt_M_lgc)
			{
				NetCfg_ICTypH_Cnt_M_lgc = NetCfg_IC_Cnt_T_lgc;
			}
			PrevNetCfg_IC_Cnt_M_lgc = NetCfg_IC_Cnt_T_lgc;

			if( NetCfg_SCCM_Cnt_T_lgc == PrevNetCfg_SCCM_Cnt_M_lgc)
			{
				NetCfg_SCCMTypH_Cnt_M_lgc = NetCfg_SCCM_Cnt_T_lgc;
			}
			PrevNetCfg_SCCM_Cnt_M_lgc = NetCfg_SCCM_Cnt_T_lgc;

			if( NetCfg_TCM_Cnt_T_lgc == PrevNetCfg_TCM_Cnt_M_lgc)
			{
				NetCfg_TCMTypH_Cnt_M_lgc = NetCfg_TCM_Cnt_T_lgc;
			}
			PrevNetCfg_TCM_Cnt_M_lgc = NetCfg_TCM_Cnt_T_lgc;
		}
		else
		{
/*NTC176*/	Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DataOtherFltMsg_W, 0x01, NTC_STATUS_PASSED);
		}
		
		if (NetCfgStatRcvdTypH_PT_Cnt_M_lgc == FALSE)
		{
/*NTC176*/	Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DataOtherFltMsg_W, 0x01, NTC_STATUS_FAILED);
		}
		else
		{
/*NTC176*/	Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DataOtherFltMsg_W, 0x01, NTC_STATUS_PASSED);
		}
		/*how to chndle NTC 176 when IF cond is failed ??*/

		Rte_Write_Ap_SrlComInput_NET_CFG_STAT_PT_Cnt_u16(NET_CFG_STAT_PT_Cnt_M_u16);
		Rte_Write_Ap_SrlComInput_CanMsgReceived_Cnt_lgc(TRUE);
	}
	else
	{
		Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(NETCFGPTMisMsgStartTime_mS_M_u32, &ElapsedTime_mS_T_u16);
		if (ElapsedTime_mS_T_u16 > k_NETCFGMsgTimeOut_mS_u16p0)

		{
/*NTC176*/	Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DataOtherFltMsg_W, 0x01, NTC_STATUS_PASSED);
			if((TRUE == NetCfg_CBCTypH_Cnt_M_lgc) && (TRUE == NetCfgStatRcvdTypH_PT_Cnt_M_lgc))
			{
/*NTC171*/		Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_MissingMsg_W, 0x01, NTC_STATUS_FAILED);
			}
			else
		    {
				Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_MissingMsg_W, 0x01, NTC_STATUS_PASSED);
		    }
		}

	}
}

STATIC FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) ReadSCCM_STW_ANGL_STAT(void)
{	/* SCCM_STW_ANGL_STAT - 0x102 */

	VAR(tLRW_ST, AUTOMATIC) SCCMSTWANGLSTAT_T_str;

	VAR(uint16,  AUTOMATIC) LRW_Cnt_T_u16;
	VAR(float32, AUTOMATIC) LRW_HwDeg_T_f32;
	VAR(uint16,  AUTOMATIC) VLRW_Cnt_T_u16;
	VAR(float32, AUTOMATIC) LRWRHP_HwDeg_T_f32;
	VAR(uint16,  AUTOMATIC) LRWRHP_Cnt_T_u16;
	VAR(uint16,  AUTOMATIC) ElapsedTime_mS_T_u16;

	if (TRUE == Ind_LRW_ST)
	{
		Ind_LRW_ST = FALSE;
		/* PRQA S 3138 1*/
		dbkGetRxSyncLRW_ST(SCCMSTWANGLSTAT_T_str);
		LRW_Cnt_T_u16 = GetValueRxLRW(SCCMSTWANGLSTAT_T_str);
		VLRW_Cnt_T_u16 = GetValueRxVLRW(SCCMSTWANGLSTAT_T_str);
		LRWRHP_Cnt_T_u16 = GetValueRxLRW_RHP(SCCMSTWANGLSTAT_T_str);

		Rte_Call_SystemTime_GetSystemTime_mS_u32(&SWAMisMsgStartTime_mS_M_u32);
		Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_MissingMsg_M, 0x01, NTC_STATUS_PASSED);

		PAErrInterfaceActive_Cnt_M_bit &= ~D_ERRINTACTNTC121_CNT_U32;
		HaLFErrInterfaceActive_Cnt_M_bit &= ~D_ERRINTACTNTC121_CNT_U32;

		if (0x3FFFU != LRW_Cnt_T_u16)
		{
			LRW_HwDeg_T_f32 = ((float32)LRW_Cnt_T_u16 * D_LRWSCALE_HWDEG_F32) - D_LRWOFFSET_HWDEG_F32;
			LRWRHP_HwDeg_T_f32 = ((float32)LRWRHP_Cnt_T_u16 * D_LRWRHPSCALE_HWDEG_F32) - D_LRWRHPOFFSET_HWDEG_F32;
			StrgWhlAngl_M_f32 = (LRW_HwDeg_T_f32 + LRWRHP_HwDeg_T_f32) * ((float32)k_StrgWhlAnglPol_s08);
			Rte_Write_StrgWhlAngl_HwDeg_f32(StrgWhlAngl_M_f32);

			if(TRUE == DiagNTC124Set_Cnt_M_lgc)
			{
				Rte_Write_StrgWhlAnglValid_Cnt_lgc(FALSE);
			}
			else
			{
				Rte_Write_StrgWhlAnglValid_Cnt_lgc(TRUE);
			}

			PAErrInterfaceActive_Cnt_M_bit &= ~D_ERRINTACTNTC120_CNT_U32;
			HaLFErrInterfaceActive_Cnt_M_bit &= ~D_ERRINTACTNTC120_CNT_U32;

			Rte_Call_SystemTime_GetSystemTime_mS_u32(&SWAVldStartTime_mS_M_u32);
			Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_M, 0x01, NTC_STATUS_PASSED);
		}
		else
		{
			Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(SWAVldStartTime_mS_M_u32, &ElapsedTime_mS_T_u16);
			if (ElapsedTime_mS_T_u16 > k_SWAValTimeOut_mS_u16p0)
			{
				Rte_Write_StrgWhlAnglValid_Cnt_lgc(FALSE);
				Rte_Write_Ap_SrlComInput_HaLFSWATrqFail_Cnt_lgc(TRUE);

				PAErrInterfaceActive_Cnt_M_bit |= D_ERRINTACTNTC120_CNT_U32;
				HaLFErrInterfaceActive_Cnt_M_bit |= D_ERRINTACTNTC120_CNT_U32;

/*NTC120*/		Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_M, 0x01, NTC_STATUS_FAILED);
			}
		}

		/*Per DID A001 - EPS Internal and Bussed Signals*/
		SrlComInput_WriteBits((uint32)LRW_Cnt_T_u16,T_A001InternalBusSig_Cnt_u8,56U,71U);

		SrlComInput_WriteBits((uint32)VLRW_Cnt_T_u16,T_A001InternalBusSig_Cnt_u8,88U,103U);

		Rte_Write_Ap_SrlComInput_CanMsgReceived_Cnt_lgc(TRUE);
	}
	else
	{

		Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(SWAMisMsgStartTime_mS_M_u32, &ElapsedTime_mS_T_u16);
		if (ElapsedTime_mS_T_u16 > k_SWAMisMsgTimeOut_mS_u16p0)
		{
			Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_M, 0x01, NTC_STATUS_PASSED);
			Rte_Write_StrgWhlAnglValid_Cnt_lgc(FALSE);
			Rte_Write_Ap_SrlComInput_HaLFSWATrqFail_Cnt_lgc(TRUE);

			PAErrInterfaceActive_Cnt_M_bit |= D_ERRINTACTNTC121_CNT_U32;
			HaLFErrInterfaceActive_Cnt_M_bit |= D_ERRINTACTNTC121_CNT_U32;
			if(TRUE == NetCfg_SCCMTypH_Cnt_M_lgc)
			{
/*NTC121*/	Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_MissingMsg_M, 0x01, NTC_STATUS_FAILED);
			}
			else
			{
/*NTC121*/	Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_MissingMsg_M, 0x01, NTC_STATUS_PASSED);
			}

		}
	}
}

STATIC FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) ReadEcuCfg6(void)
{	/* EcuCfg6 - 0x3F5 */

	VAR(tEC_ECUCfg6_Stat, AUTOMATIC) EC_ECUCfg6_Stat_T_str;
	VAR(tEC_Steering, AUTOMATIC) EC_Steering_Stat_T_str;

	VAR(uint16, AUTOMATIC) ECUCfg6_Stat_Cnt_T_u16;
	VAR(uint16, AUTOMATIC) Steering_Cnt_T_u16;
	VAR(uint16, AUTOMATIC) DesiredTuning_Cnt_u16;
	VAR(uint16,  AUTOMATIC) ElapsedTime_mS_T_u16;
	VAR(uint16,  AUTOMATIC) i;

	if (TRUE == Ind_EC_ECUCfg6_Stat)
	{
		Ind_EC_ECUCfg6_Stat = FALSE;
		/* PRQA S 3138 1*/
		dbkGetRxSyncEC_ECUCfg6_Stat(EC_ECUCfg6_Stat_T_str);
		/* PRQA S 3138 1*/
		dbkGetRxSyncEC_Steering(EC_Steering_Stat_T_str);

		Rte_Call_SystemTime_GetSystemTime_mS_u32(&EcuCfg6MsgStartTime_mS_M_u32);
		Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_MissingMsg_EcuCfg6, 0x01, NTC_STATUS_PASSED);

		/* PRQA S 1281 2 */ /* Caused by definition in vector macro */
		ECUCfg6_Stat_Cnt_T_u16 = GetValueRxEC_ECUCfg6_Stat(EC_ECUCfg6_Stat_T_str);
		Steering_Cnt_T_u16 = GetValueRxEC_Steering(EC_Steering_Stat_T_str);

		if(ECUCfg6_Stat_Cnt_T_u16 == 0x01U)
		{
			Rte_Call_SystemTime_GetSystemTime_mS_u32(&EcuCfg6InvMsgStartTime_mS_M_u32);
			Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_EcuCfg6, 0x01, NTC_STATUS_PASSED);


			if((Steering_Cnt_T_u16 != 0x00U) && (Steering_Cnt_T_u16 != 0xFFU))
			{
				for(i = 0; i < D_NUMOFTUNSETS_CNT_U16; i++)
				{
					if(k_DesiredTuning_Cnt_u16[0][i] == Steering_Cnt_T_u16)
					{
						DesiredTuning_Cnt_u16 = k_DesiredTuning_Cnt_u16[1][i];
						i = D_NUMOFTUNSETS_CNT_U16;
						EC_SteeringIvld_Cnt_M_lgc = FALSE;
					}
					else
					{
						DesiredTuning_Cnt_u16 = 0;
						EC_SteeringIvld_Cnt_M_lgc = TRUE;
					}
				}

				if((DesiredTuning_Cnt_u16 >= 0U) &&
						(DesiredTuning_Cnt_u16 < D_NUMOFTUNSETS_CNT_U16)&&
						(EC_SteeringIvld_Cnt_M_lgc == FALSE))
				{

					if((ECUCfg6_Stat_Cnt_T_u16 == D_ECUCFGSTATPROG_CNT_U16) &&
						(DesiredTuning_Cnt_u16 == PrevDesiredTunSet_Cnt_M_u16))
					{

						if(TuningPerformedTypH_Cnt_M_u16 != D_TUNINGPERFORMED_CNT_U16)
						{
							TuningSetForNextCycleTypH_Cnt_M_u16 = DesiredTuning_Cnt_u16;
							TuningPerformedTypH_Cnt_M_u16 = D_TUNINGPERFORMED_CNT_U16;

						}
						else
						{
							if(DesiredTuning_Cnt_u16 != TuningSetForNextCycleTypH_Cnt_M_u16)
							{
								TuningSetForNextCycleTypH_Cnt_M_u16 = DesiredTuning_Cnt_u16;
							}
						}
					}

						PrevDesiredTunSet_Cnt_M_u16 = DesiredTuning_Cnt_u16;
				}
				else
				{
					EC_SteeringIvld_Cnt_M_lgc = TRUE;
				}
			}
			else
			{
				EC_SteeringIvld_Cnt_M_lgc = TRUE;
			}
		}
		else
		{
			Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(EcuCfg6InvMsgStartTime_mS_M_u32, &ElapsedTime_mS_T_u16);
			if (ElapsedTime_mS_T_u16 > k_EcuCfg6InvMsgTimeOut_mS_u16p0)
			{
	/*NTC1D6*/	Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_EcuCfg6, 0x01, NTC_STATUS_FAILED);
			}
		}
		/*Per DID 0xA001 - EPS Internal and Bussed Signals*/
		SrlComInput_WriteBits((uint32)Steering_Cnt_T_u16,T_A001InternalBusSig_Cnt_u8,184U,191U);

		Rte_Write_Ap_SrlComInput_CanMsgReceived_Cnt_lgc(TRUE);
	}
	else
	{
		Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(EcuCfg6MsgStartTime_mS_M_u32, &ElapsedTime_mS_T_u16);
		if (ElapsedTime_mS_T_u16 > k_EcuCfg6MsgTimeOut_mS_u16p0)
		{
			/*NTC1D6*/	Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_EcuCfg6, 0x01, NTC_STATUS_PASSED);/*NTC1D6*/

			if(TRUE == NetCfg_CBCTypH_Cnt_M_lgc)
			{
/*NTC1D7*/	Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_MissingMsg_EcuCfg6, 0x01, NTC_STATUS_FAILED);
			}
			else
			{
/*NTC1D7*/	Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_MissingMsg_EcuCfg6, 0x01, NTC_STATUS_PASSED);
			}
		}
	}

}

STATIC FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) DiagNTC1F5(void)
{
	VAR(uint16,  AUTOMATIC) ElapsedTime_mS_T_u16;
	VAR(ManufModeType, AUTOMATIC) MEC_Cnt_T_enum;

	Rte_Read_Ap_SrlComInput_MEC_Cnt_enum(&MEC_Cnt_T_enum);

	if (D_TUNINGPERFORMED_CNT_U16 == TuningPerformedTypH_Cnt_M_u16)
	{
		Rte_Call_SystemTime_GetSystemTime_mS_u32(&TuningPerformedStartTime_mS_M_u32);
		Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_EOLVehTunNtPerf, 0x01, NTC_STATUS_PASSED);
	}
	else
	{
		Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(TuningPerformedStartTime_mS_M_u32, &ElapsedTime_mS_T_u16);
		if ((ElapsedTime_mS_T_u16 > k_TuningPerformedTimeOut_mS_u16p0) &&
			((MEC_Cnt_T_enum == ProductionMode) ||
			(MEC_Cnt_T_enum == EngineeringMode)))
		{
/*NTC1F5*/	Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_EOLVehTunNtPerf, 0x01, NTC_STATUS_FAILED);
			TuningSetForNextCycleTypH_Cnt_M_u16 = 0;
		}
	}

}

STATIC FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) ReadDST_TOC(void)
{	/* DST_TOC - 0x294 */

	VAR(tDST_TOC, AUTOMATIC) DST_TOC_T_str;

	VAR(uint16, AUTOMATIC) TOC_Fault_Cnt_T_u16;
	VAR(uint16, AUTOMATIC) TOC_Act_Req_Cnt_T_u16;
	VAR(boolean,  AUTOMATIC) TOC_Act_Req_Cnt_T_lgc;
	VAR(uint16, AUTOMATIC) RawTO_Req_HwNm_T_u16;
	VAR(float32, AUTOMATIC) TO_Req_HwNm_T_f32;
	VAR(boolean,  AUTOMATIC) MsgCmdProcessed_Cnt_T_lgc = FALSE;
	VAR(boolean,  AUTOMATIC) DSTExtSystemFltActive_Cnt_T_lgc;

	VAR(uint16, AUTOMATIC) TOC_Sts_Cnt_T_u16;
	VAR(uint16, AUTOMATIC) MC_294h_Cnt_T_u16;
	VAR(uint16,  AUTOMATIC) ElapsedTime_mS_T_u16;
	VAR(uint8,  AUTOMATIC) DSTState_T_Cnt_u8;
	VAR(boolean,  AUTOMATIC) ReceivedDataValid_Cnt_T_lgc = TRUE;

	Rte_Read_Ap_SrlComInput_DSTState_Cnt_u08(&DSTState_T_Cnt_u8);
	DSTState_Cnt_M_u8 = DSTState_T_Cnt_u8;

	if (TRUE == Ind_DST_TOC) /* DST processing - on process */
	{
		Ind_DST_TOC = FALSE;
		/* PRQA S 3138 1*/
		dbkGetRxSyncDST_TOC(DST_TOC_T_str);
		Rte_Call_SystemTime_GetSystemTime_mS_u32(&DSTTOCMisMsgStartTime_mS_M_u32);

		Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_MissingMsg_Z, 0x01, NTC_STATUS_PASSED);

		DSTErrCntrRecvLevel_Cnt_M_bit = D_DSTERRCNTRCLCLR_CNT_u16; /*clear bits only if the 3 NTCs are tested*/


		/*NTC18A*/
		ReceivedDataValid_Cnt_T_lgc &= DiagCRC294(DST_TOC_T_str);
		/*MTC18B*/
		MC_294h_Cnt_T_u16 = GetValueRxMC_294h(DST_TOC_T_str);
		ReceivedDataValid_Cnt_T_lgc &= DiagNTC18B( MC_294h_Cnt_T_u16 );

		if (TRUE == ReceivedDataValid_Cnt_T_lgc)
		{
			MsgCmdProcessed_Cnt_T_lgc = TRUE;
			TOC_Fault_Cnt_T_u16 = GetValueRxTOC_Fault(DST_TOC_T_str);
			SrlComInput_WriteBits(TOC_Fault_Cnt_T_u16,T_A004InternalBusSig_Cnt_u8,54U,55U);
			TOC_Act_Req_Cnt_T_u16 = GetValueRxTOC_Act_Req(DST_TOC_T_str);
			SrlComInput_WriteBits(TOC_Act_Req_Cnt_T_u16,T_A004InternalBusSig_Cnt_u8,6U,7U);


			if (TOC_Act_Req_Cnt_T_u16 == 0x01U)
			{
				TOC_Act_Req_Cnt_T_lgc = TRUE;
			}
			else
			{
				TOC_Act_Req_Cnt_T_lgc = FALSE;
			}

			RawTO_Req_HwNm_T_u16 = GetValueRxTO_Req(DST_TOC_T_str);
			SrlComInput_WriteBits(RawTO_Req_HwNm_T_u16,T_A004InternalBusSig_Cnt_u8,16U,31U);

			TO_Req_HwNm_T_f32 = FPM_FixedToFloat_m(RawTO_Req_HwNm_T_u16,u9p7_T);
			TO_Req_HwNm_T_f32 = TO_Req_HwNm_T_f32 - D_TOREQOFF_CNT_F32;
			TO_Req_HwNm_T_f32 = TO_Req_HwNm_T_f32 * k_TOReqPol_Cnt_f32;

			TOC_Sts_Cnt_T_u16 = GetValueRxTOC_Sts(DST_TOC_T_str);
			SrlComInput_WriteBits(TOC_Sts_Cnt_T_u16,T_A004InternalBusSig_Cnt_u8,2U,5U);
			SrlComInput_WriteBits(0x00U,T_A004InternalBusSig_Cnt_u8,0U,1U);
			SrlComInput_WriteBits(DSTFuncPresentTypH_Cnt_M_lgc,T_A004InternalBusSig_Cnt_u8,52U,52U);
			SrlComInput_WriteBits(0x00U,T_A004InternalBusSig_Cnt_u8,48U,51U);

			if (TRUE == DSTFuncPresentTypH_Cnt_M_lgc)
			{
				if((TOC_Fault_Cnt_T_u16 == 0x03u ) ||
					(TOC_Act_Req_Cnt_T_u16 == 0x03u) ||
					(TOC_Sts_Cnt_T_u16 == 0x0Fu) ||
					(RawTO_Req_HwNm_T_u16 == 0x7FFu))
				{
					Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(DSTTOCInvMsgStartTime_mS_M_u32, &ElapsedTime_mS_T_u16);
					if (ElapsedTime_mS_T_u16 > k_DSTTOCInvMsgTimeOut_mS_u16p0)
					{
			/*NTC1C0*/	Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_AG, 0x01, NTC_STATUS_FAILED);
					}
				}
				else
				{
					Rte_Call_SystemTime_GetSystemTime_mS_u32(&DSTTOCInvMsgStartTime_mS_M_u32);
					Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_AG, 0x01, NTC_STATUS_PASSED);

					if ( TRUE == DSTDiagCondtions18CDF(DSTState_T_Cnt_u8 , (uint8)TOC_Sts_Cnt_T_u16))
					{
						MsgCmdProcessed_Cnt_T_lgc &= DSTDiagNTC18FRawXORTest( RawTO_Req_HwNm_T_u16 );
					}
					if( RawTO_Req_HwNm_T_u16 == 0x7FFU)
					{
						Rte_Write_Ap_SrlComInput_DSTTrqOvRqstValid_Cnt_lgc(FALSE);
					}
					else
					{
						Rte_Write_Ap_SrlComInput_DSTTrqOvRqstValid_Cnt_lgc(TRUE);

					}

					if((TOC_Fault_Cnt_T_u16 == 0U) && (TRUE != DSTExtSystemFltActive_Cnt_M_lgc))
					{
						DSTExtSystemFltActive_Cnt_T_lgc = FALSE;
					}
					else
					{
						DSTExtSystemFltActive_Cnt_T_lgc = TRUE;
					}

					if(0x0FU == TOC_Sts_Cnt_T_u16)
					{
					TOC_Sts_Cnt_T_u16 = TOCSTATE_NOTAVAILABLE;
					}

					Rte_Write_Ap_SrlComInput_DSTTOCState_Uls_enum((uint8)TOC_Sts_Cnt_T_u16);


					if((TRUE == TOC_Act_Req_Cnt_T_lgc) && (TRUE == EnableTorqueOverlay_Cnt_M_lgc))
					{
						Rte_Write_Ap_SrlComInput_DSTEnableRqst_Cnt_lgc(TRUE);
					}
					else
					{
						Rte_Write_Ap_SrlComInput_DSTEnableRqst_Cnt_lgc(FALSE);
					}
					/*Run NTC 0x18C 0x18D 0x18F */
					if (MsgCmdProcessed_Cnt_T_lgc == TRUE)
					{
						if ( TRUE == DSTDiagCondtions18CDF(DSTState_T_Cnt_u8 , (uint8)TOC_Sts_Cnt_T_u16))
						{
							if( TRUE == DSTDiagNTC18CReqOutOfRange(  TO_Req_HwNm_T_f32 ))
							{
								TO_Req_HwNm_M_f32 = DSTDiagNTC18DDeltaOutOfRange(  TO_Req_HwNm_T_f32 );
							}
							else
							{
								/*Set NTC's 18C, 18D to PASSED when above IF condition is not true*/
								Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DataRateFltMsg_Z, 0x01, NTC_STATUS_PASSED);/*NTC18D*/
							}
						}
					}
					else
					{
						/*Set NTC's 18C, 18D to PASSED when MsgCmdProcessed is FALSE */
						Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DataRateFltMsg_Z, 0x01, NTC_STATUS_PASSED);/*NTC18D*/
						Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DataRngFltMsg_Z, 0x01, NTC_STATUS_PASSED);/*NTC18C*/
					}

					if (TOCSTATE_OFF != TOC_Sts_Cnt_T_u16)
					{
						if((RawTO_Req_HwNm_T_u16 != 0x400u) &&
							(((TOCSTATE_ACTIVEMODE05 != TOC_Sts_Cnt_T_u16) &&
							(TOCSTATE_ACTIVEMODE06 != TOC_Sts_Cnt_T_u16) &&
							(TOCSTATE_ACTIVEMODE07 != TOC_Sts_Cnt_T_u16)) ||
							(TOC_Act_Req_Cnt_T_lgc != TRUE)))
						{
/*NTC0EB*/					Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_VLF_11, 0x01, NTC_STATUS_FAILED);
						}
						else
						{
							Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_VLF_11, 0x01, NTC_STATUS_PASSED);
						}
					}
					else
					{
						Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_VLF_11, 0x01, NTC_STATUS_PASSED);
					}

					if((DSTFuncPresentTypH_Cnt_M_lgc == TRUE ) && (TOC_Sts_Cnt_T_u16 > TOCSTATE_ACTIVEMODE07))
					{
/*NTC0EC*/				Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_VLF_12, 0x01, NTC_STATUS_FAILED);
					}
					else
					{
						Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_VLF_12, 0x01, NTC_STATUS_PASSED);
					}

					DSTExtSystemFltActive_Cnt_M_lgc = DSTExtSystemFltActive_Cnt_T_lgc;
					Rte_Write_Ap_SrlComInput_DSTExtSystemFltActive_Cnt_lgc(DSTExtSystemFltActive_Cnt_T_lgc);
				}
			}/*DST Func Present*/
			else
			{
				Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_VLF_12, 0x01, NTC_STATUS_PASSED); /*NTCEC*/
				Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_VLF_11, 0x01, NTC_STATUS_PASSED);/*NTCEB*/
				Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DataRateFltMsg_Z, 0x01, NTC_STATUS_PASSED);/*NTC18D*/
				Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DataRngFltMsg_Z, 0x01, NTC_STATUS_PASSED);/*NTC18C*/
				Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_AG, 0x01, NTC_STATUS_PASSED);/*NTC1C0*/
				Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DSTXORActive, 0x01, NTC_STATUS_PASSED);/*NTC18F*/

			}

			if((DSTFuncPresentTypH_Cnt_M_lgc == FALSE ) && (TRUE == TOC_Act_Req_Cnt_T_lgc))
			{
/*NTC0EA*/		Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_VLF_10, 0x01, NTC_STATUS_FAILED);
			}
			else
			{
				Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_VLF_10, 0x01, NTC_STATUS_PASSED);
			}

			TOC_Sts_Cnt_M_u16 = TOC_Sts_Cnt_T_u16;
		} /*DataValid */

		else
		{
			ClearDSTTOCNTC_RcvdMesgNotValid();
		}

		Rte_Write_Ap_SrlComInput_CanMsgReceived_Cnt_lgc (TRUE);

		if ( TRUE == DSTDiagCondtions18CDF(DSTState_T_Cnt_u8 , (uint8)TOC_Sts_Cnt_T_u16))
		{
			DSTDiagNTC18EMaxActiveTime(DSTState_T_Cnt_u8);
			DSTDiagNTC188(TO_Req_HwNm_T_f32);
		}
	

		PrevTOReq_HwNm_M_f32 = TO_Req_HwNm_T_f32;
	} /*Ind Reveiced */
	else
	{
		/*Diag Missing message*/
		Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(DSTTOCMisMsgStartTime_mS_M_u32, &ElapsedTime_mS_T_u16);
		if(ElapsedTime_mS_T_u16 > k_DSTMisMsgThr0_ms_u16)
		{
		ClearDSTTOCNTC_MessageNotRcvd();
		}
		if (TRUE == DSTFuncPresentTypH_Cnt_M_lgc)
		{
			DiagNTC189( ElapsedTime_mS_T_u16 );
		}
		else
		{
			Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_MissingMsg_Z, 0x01, NTC_STATUS_PASSED);
		}


	}

	Rte_Write_Ap_SrlComInput_DSTTrqOvCmdRqst_HwNm_f32(TO_Req_HwNm_M_f32);




	/*Clear Pstep/NStep counter and DSTErrCounter in case of DST OFF or no DST FUNCTION*/
	if ((  TOCSTATE_OFF == 	DSTState_T_Cnt_u8)
		||(TOCSTATE_PNA == 	DSTState_T_Cnt_u8))
	{
		/*Clear NTCs  */
		CRC294DiagAcc_Cnt_M_u16 = 0U;	/*18A*/
		DSTTOCMsgCntAcc_Cnt_M_u16 =0;	/*18B*/
	}

}

STATIC FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) DSTDiagNTC188( VAR(float32, AUTOMATIC) TO_Req_HwNm_T_f32 )			 /*NTC188 */
{
	VAR(uint16, AUTOMATIC) ElapsedTime_mS_T_u16;
	VAR(uint16, AUTOMATIC) TrqStckStartTime_mS_T_u16p0;
	VAR(Boolean, AUTOMATIC) NTC188Set_T_lgc;

	if(Abs_f32_m(TO_Req_HwNm_T_f32) > k_TrqStckActv_HwNm_M_f32)
	{
		if((Abs_f32_m(TO_Req_HwNm_T_f32 - PrevTOReq_HwNm_M_f32) < k_StuckTrqBnd_Nm_f32) &&(FALSE == TrqBndEstab_Cnt_M_lgc ))
		{
			TrqBandLow_Nm_M_f32 = PrevTOReq_HwNm_M_f32 - k_StuckTrqBnd_Nm_f32;
			TrqBandHi_Nm_M_f32 = PrevTOReq_HwNm_M_f32 + k_StuckTrqBnd_Nm_f32;
			TrqBndEstab_Cnt_M_lgc = TRUE;
		}

		if(StrgWhlAngl_M_f32 >= k_TrqStckSWA_HwDeg_f32)
		{
			TrqStckStartTime_mS_T_u16p0 = k_TrqStckHiSWATime_mS_u16p0;
		}
		else
		{
			TrqStckStartTime_mS_T_u16p0 = k_TrqStckLowSWATime_mS_u16p0;
		}

		Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_InvalidMsg_Z, &NTC188Set_T_lgc);

		if(NTC188Set_T_lgc == FALSE)
		{
			if(( TO_Req_HwNm_T_f32 > TrqBandLow_Nm_M_f32 ) && (TO_Req_HwNm_T_f32< TrqBandHi_Nm_M_f32 ))
			{
				Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(TrqStckStartTime_mS_M_u32, &ElapsedTime_mS_T_u16);
				if (ElapsedTime_mS_T_u16 > TrqStckStartTime_mS_T_u16p0)
				{
		/*NTC188*/	Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_Z, 0x01, NTC_STATUS_FAILED);
				}
			}
			else
			{
				TrqBndEstab_Cnt_M_lgc = FALSE;
				Rte_Call_SystemTime_GetSystemTime_mS_u32(&TrqStckStartTime_mS_M_u32);
				Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_Z, 0x01, NTC_STATUS_PASSED);
			}
		}
		else
		{
			Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_Z, 0x01, NTC_STATUS_PASSED);
		}
	}
	else
	{
		/*Set NTC 188 to PASSED when TEST ENABLE Criteria is not met */
		Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_Z, 0x01, NTC_STATUS_PASSED);
	}
}

STATIC FUNC(boolean, RTE_AP_SRLCOMINPUT_APPL_CODE) DSTDiagNTC18CReqOutOfRange( VAR(float32, AUTOMATIC) TO_Req_HwNm_T_f32 )			 /*NTC18C out of range*/
{
	VAR(boolean,  AUTOMATIC) IsCmdValid_Cnt_T_lgc = TRUE;

	if (Abs_f32_m(TO_Req_HwNm_T_f32)<= k_DSTTrqMax_HwNm_f32)
	{
		Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DataRngFltMsg_Z, 0x01, NTC_STATUS_PASSED);
	}
	else
	{
		Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DataRngFltMsg_Z, 0x01, NTC_STATUS_FAILED);
		IsCmdValid_Cnt_T_lgc = FALSE;
	}
	return IsCmdValid_Cnt_T_lgc;

}

STATIC FUNC(float32, RTE_AP_SRLCOMINPUT_APPL_CODE) DSTDiagNTC18DDeltaOutOfRange( VAR(float32, AUTOMATIC) TO_Req_Cnt_T_f32 )			 /*NTC18D delta out of range*/
{
	VAR(float32,  AUTOMATIC) TO_Req_HwNm_T_f32;

	if (Abs_f32_m(TO_Req_Cnt_T_f32 - TO_Req_HwNm_M_f32)<=  DSTTrqOvrlSlewLmt_Nm_M_f32)
	{
		TrqOvrlMaxChngeAcc_Cnt_M_u16 = DiagNStep_m(TrqOvrlMaxChngeAcc_Cnt_M_u16, k_TrqOvrlMaxSlewDiag_Cnt_str);
	}
	else
	{
		TrqOvrlMaxChngeAcc_Cnt_M_u16 = DiagPStep_m(TrqOvrlMaxChngeAcc_Cnt_M_u16, k_TrqOvrlMaxSlewDiag_Cnt_str);

		if((TO_Req_HwNm_M_f32 - TO_Req_Cnt_T_f32)  > 0.0f)
		{
			TO_Req_HwNm_T_f32 = TO_Req_HwNm_M_f32 - DSTTrqOvrlSlewLmt_Nm_M_f32;
		}
		else
		{
			TO_Req_HwNm_T_f32 = TO_Req_HwNm_M_f32 + DSTTrqOvrlSlewLmt_Nm_M_f32;

		}
	}

	if((DiagFailed_m( TrqOvrlMaxChngeAcc_Cnt_M_u16, k_TrqOvrlMaxSlewDiag_Cnt_str) == TRUE))
	{
		Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DataRateFltMsg_Z, 0x01, NTC_STATUS_FAILED);
	}
	else
	{
		Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DataRateFltMsg_Z, 0x01, NTC_STATUS_PASSED);
	}

	return TO_Req_HwNm_T_f32;
}

STATIC FUNC(boolean, RTE_AP_SRLCOMINPUT_APPL_CODE) DSTDiagNTC18EMaxActiveTime( VAR(uint8, AUTOMATIC) TOCSts_T_Cnt_u8 )			 /*NTC18E max DST ACTIVE */
{
	VAR(boolean,  AUTOMATIC) IsNTCFailed_Cnt_T_lgc = FALSE;
	VAR(uint32, AUTOMATIC) ElapsedTime_mS_T_u32;

	if((TOCSts_T_Cnt_u8 == TOCSTATE_ACTIVEMODE05)||
	(TOCSts_T_Cnt_u8 == TOCSTATE_ACTIVEMODE06)||
	(TOCSts_T_Cnt_u8 == TOCSTATE_ACTIVEMODE07))
	{
		Rte_Call_SystemTime_DtrmnElapsedTime_mS_u32(DSTActiveStartTime_mS_M_u32, &ElapsedTime_mS_T_u32);
		if (ElapsedTime_mS_T_u32 > k_MaxDSTActiveTime_mS_u32p0)
		{
			Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DataOtherFltMsg_Z, 0x01, NTC_STATUS_FAILED);
			IsNTCFailed_Cnt_T_lgc = TRUE;
		}
	}
	else
	{
		Rte_Call_SystemTime_GetSystemTime_mS_u32(&DSTActiveStartTime_mS_M_u32);
		Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DataOtherFltMsg_Z, 0x01, NTC_STATUS_PASSED);

	}
	return IsNTCFailed_Cnt_T_lgc;

}
STATIC FUNC(boolean, RTE_AP_SRLCOMINPUT_APPL_CODE) DSTDiagNTC18FRawXORTest( VAR(uint16, AUTOMATIC) RawTO_Req_Nm_T_u16 )			 /*NTC18F EX OR TEST */
{
	VAR(boolean,  AUTOMATIC) IsCmdValid_Cnt_T_lgc = TRUE;

	if ( ((RawTO_Req_Nm_T_u16>>9) == 0) || ((RawTO_Req_Nm_T_u16>>9) == 3U) )
	{
		DSTXorCptNTC18F_Cnt_M_u16++;
		IsCmdValid_Cnt_T_lgc = FALSE;
	}
	else
	{
		DSTXorCptNTC18F_Cnt_M_u16 = 0;
	}

	if (DSTXorCptNTC18F_Cnt_M_u16> k_MaxDSTXorCptNTC18F_Cnt_u16)
	{
		Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DSTXORActive, 0x01, NTC_STATUS_FAILED);
	}
	else
	{
		Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DSTXORActive, 0x01, NTC_STATUS_PASSED);
	}
	return IsCmdValid_Cnt_T_lgc;
}



STATIC FUNC(boolean, RTE_AP_SRLCOMINPUT_APPL_CODE) DSTDiagCondtions18CDF( VAR(uint8, AUTOMATIC) DSTState_T_Cnt_u8, VAR(uint8, AUTOMATIC) DST_TOCState_T_Cnt_u8 )
{
	VAR(boolean, AUTOMATIC) MakeDiag18C_Cnt_T_lgc = FALSE;

	if ( 	( DSTState_T_Cnt_u8 == TOCSTATE_ACTIVEMODE05) ||
			( DSTState_T_Cnt_u8 == TOCSTATE_ACTIVEMODE06) ||
			( DSTState_T_Cnt_u8 == TOCSTATE_ACTIVEMODE07))
	{
		if ( 		( DST_TOCState_T_Cnt_u8 == TOCSTATE_ACTIVEMODE05) ||
					( DST_TOCState_T_Cnt_u8 == TOCSTATE_ACTIVEMODE06) ||
					( DST_TOCState_T_Cnt_u8 == TOCSTATE_ACTIVEMODE07) ||
					( DST_TOCState_T_Cnt_u8 == TOCSTATE_READY))
		{
			MakeDiag18C_Cnt_T_lgc = TRUE;
		}
	}
	else
	{
		 if ( DSTState_T_Cnt_u8 == TOCSTATE_READY)
		 {
			if ( 	( DST_TOCState_T_Cnt_u8 == TOCSTATE_ACTIVEMODE05) ||
					( DST_TOCState_T_Cnt_u8 == TOCSTATE_ACTIVEMODE06) ||
					( DST_TOCState_T_Cnt_u8 == TOCSTATE_ACTIVEMODE07))
			{
				MakeDiag18C_Cnt_T_lgc = TRUE;
			}
		 }
	}


	return MakeDiag18C_Cnt_T_lgc;
}

STATIC FUNC(boolean, RTE_AP_SRLCOMINPUT_APPL_CODE) DiagCRC294( VAR(tDST_TOC, AUTOMATIC) DST_TOC_T_str )
{
	VAR(boolean,  AUTOMATIC) ReceivedDataValid_Cnt_T_lgc;

	ReceivedDataValid_Cnt_T_lgc = IsCRC8Valid(DST_TOC_T_str.c, 7, GetValueRxCRC_294h(DST_TOC_T_str));

	if( FALSE == ReceivedDataValid_Cnt_T_lgc)
	{
		CRC294DiagAcc_Cnt_M_u16 = DiagPStep_m(CRC294DiagAcc_Cnt_M_u16,k_CRC294DiagThr2_Cnt_str);
		DSTErrCntrRecvLevel_Cnt_M_bit |= D_DSTERRCNTRCLGR0_CNT_u16;
	}
	else
	{
		CRC294DiagAcc_Cnt_M_u16 = DiagNStep_m(CRC294DiagAcc_Cnt_M_u16,k_CRC294DiagThr2_Cnt_str);
	}

	if(TRUE == DSTFuncPresentTypH_Cnt_M_lgc)
	{
		if(CRC294DiagAcc_Cnt_M_u16 >= k_CRC294DiagThr1_Cnt_u16 )
		{
		Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_CRCFltMsg_Z, 0x01, NTC_STATUS_FAILED);
		DSTErrCntrRecvLevel_Cnt_M_bit  |= D_DSTERRCNTRCLTH1_CNT_u16;
		}
	}
	else
	{
		Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_CRCFltMsg_Z, 0x01, NTC_STATUS_PASSED);
	}



	if (TRUE == DiagFailed_m( CRC294DiagAcc_Cnt_M_u16, k_CRC294DiagThr2_Cnt_str))
	{
		DSTErrCntrRecvLevel_Cnt_M_bit |= D_DSTERRCNTRCLTH2_CNT_u16;
	}
	return ReceivedDataValid_Cnt_T_lgc;

}

STATIC FUNC(boolean, RTE_AP_SRLCOMINPUT_APPL_CODE) DiagNTC18B( VAR(uint16, AUTOMATIC) MC_294h_Cnt_T_u16 )
{
	VAR(boolean,  AUTOMATIC) CounterValid_T_Cnt_lgc = TRUE;


	if ( ((PrevMC_294h_Cnt_M_u16 + 1) % D_COUNTERCYCLE16_CNT_U16) != MC_294h_Cnt_T_u16  )
	{
		DSTTOCMsgCntAcc_Cnt_M_u16 = DiagPStep_m(DSTTOCMsgCntAcc_Cnt_M_u16, k_DSTTOCProgCntDiagThr2_Cnt_str);
		DSTErrCntrRecvLevel_Cnt_M_bit |= D_DSTERRCNTRCLGR0_CNT_u16;
		CounterValid_T_Cnt_lgc = FALSE;
	}
	else
	{
		DSTTOCMsgCntAcc_Cnt_M_u16 = DiagNStep_m(DSTTOCMsgCntAcc_Cnt_M_u16, k_DSTTOCProgCntDiagThr2_Cnt_str);
	}


	if(TRUE == DSTFuncPresentTypH_Cnt_M_lgc)
	{
		if(DSTTOCMsgCntAcc_Cnt_M_u16 > k_DSTTOCProgCntThr1_Cnt_u16)
		{
		Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_PgrsCntFltMsg_Z, 0x01, NTC_STATUS_FAILED);
		DSTErrCntrRecvLevel_Cnt_M_bit |= D_DSTERRCNTRCLTH1_CNT_u16;
		}
	}
	else
	{
		Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_PgrsCntFltMsg_Z, 0x01, NTC_STATUS_PASSED);
	}



	if (DiagFailed_m( DSTTOCMsgCntAcc_Cnt_M_u16, k_DSTTOCProgCntDiagThr2_Cnt_str) == TRUE)
	{

		DSTErrCntrRecvLevel_Cnt_M_bit |= D_DSTERRCNTRCLTH2_CNT_u16;
	}

	PrevMC_294h_Cnt_M_u16 = MC_294h_Cnt_T_u16;
	return CounterValid_T_Cnt_lgc;
}

STATIC FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) DiagNTC189( VAR(uint16, AUTOMATIC) ElapsedTime_mS_T_u16 )
{
	VAR(uint8,  AUTOMATIC) DSTState_T_Cnt_u08;
	VAR(uint16,  AUTOMATIC) Thr0TimeOut_ms_T_u16;
	VAR(uint16,  AUTOMATIC) Thr1StepLevel_Cnt_T_u16;
	VAR(DiagSettings_Str,  AUTOMATIC) Thr2Acc_Cnt_T_str;


	Rte_Read_Ap_SrlComInput_DSTState_Cnt_u08(&DSTState_T_Cnt_u08);


	Thr0TimeOut_ms_T_u16 = k_DSTMisMsgThr0_ms_u16; /* same for active/inactive */

	switch (DSTState_T_Cnt_u08)
	{
		case TOCSTATE_ACTIVEMODE05:
		case TOCSTATE_ACTIVEMODE06:
		case TOCSTATE_ACTIVEMODE07:  /*Active TOC*/
			Thr0TimeOut_ms_T_u16 = k_DSTMisMsgThr0_ms_u16;
			Thr1StepLevel_Cnt_T_u16 = k_DSTTOCActMisMsgThr1_Cnt_u16p0;	/*raise NTC*/
			Thr2Acc_Cnt_T_str = 	k_DSTTOCActMisMsgThr2_Cnt_str;
			break;
		default :
			Thr1StepLevel_Cnt_T_u16 = k_DSTTOCNotActMisMsgThr1_Cnt_u16p0;
			Thr2Acc_Cnt_T_str = 	k_DSTTOCNotActMisMsgThr2_Cnt_str;
			break;
	}



	if (ElapsedTime_mS_T_u16 > Thr0TimeOut_ms_T_u16)
	{

		DSTTOCMsgTmrAcc_Cnt_M_u16 = DiagPStep_m(DSTTOCMsgTmrAcc_Cnt_M_u16, Thr2Acc_Cnt_T_str);
		DSTErrCntrRecvLevel_Cnt_M_bit |= D_DSTERRCNTRCLGR0_CNT_u16;
	}
	else
	{
		DSTTOCMsgTmrAcc_Cnt_M_u16 = DiagNStep_m(DSTTOCMsgTmrAcc_Cnt_M_u16, Thr2Acc_Cnt_T_str);
	}



	if(DSTTOCMsgTmrAcc_Cnt_M_u16 > Thr1StepLevel_Cnt_T_u16)
	{
		
		Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_MissingMsg_Z, 0x01, NTC_STATUS_FAILED);
		DSTErrCntrRecvLevel_Cnt_M_bit |= D_DSTERRCNTRCLTH1_CNT_u16;
	}
	else
	{
		Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_MissingMsg_Z, 0x01, NTC_STATUS_PASSED);
	}

	if (DiagFailed_m( DSTTOCMsgTmrAcc_Cnt_M_u16, Thr2Acc_Cnt_T_str) == TRUE)
	{
		DSTErrCntrRecvLevel_Cnt_M_bit |= D_DSTERRCNTRCLTH2_CNT_u16;
	}
}


STATIC FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) ReadTRNSSTAT(void)
{	/* TRNS_STAT  - 170 */

	VAR(tTRNS_STAT_PKT, AUTOMATIC) TRNS_STAT_PKT_T_str;
	VAR(uint16, AUTOMATIC) VC_PRND_Stat_Cnt_T_u16;
	VAR(uint16, AUTOMATIC) ElapsedTime_mS_T_u16;
	VAR(uint16, AUTOMATIC) InvElapsedTime_mS_T_u16;

	if (TRUE == Ind_TRNS_STAT_PKT)
	{
		Ind_TRNS_STAT_PKT = FALSE;
		/* PRQA S 3138 1*/
		dbkGetRxSyncTRNS_STAT_PKT(TRNS_STAT_PKT_T_str);

		Rte_Call_SystemTime_GetSystemTime_mS_u32(&TRNSSTATMisMsgStartTime_mS_M_u32);
		Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_MissingMsg_AD, 0x01, NTC_STATUS_PASSED);
		DSTRevGearValid_Cnt_M_bit &= ~D_DSTREVGRVLDCNTL1A9_CNT_u16;
		PAErrInterfaceActive_Cnt_M_bit &= ~D_ERRINTACTNTC1A9_CNT_U32;

		VC_PRND_Stat_Cnt_T_u16 = GetValueRxPRND_STAT(TRNS_STAT_PKT_T_str);
		SrlComInput_WriteBits(VC_PRND_Stat_Cnt_T_u16,T_A002InternalBusSig_Cnt_u8,41U,43U);
		SrlComInput_WriteBits(VC_PRND_Stat_Cnt_T_u16,T_A003InternalBusSig_Cnt_u8,42U,44U);

		if(D_AUTOTRANS_CNT_U8 == TrnsmsnType_Cnt_M_u8)
		{
			if (VC_PRND_Stat_Cnt_T_u16 == 0x01U)
			{
				Rte_Write_Ap_SrlComInput_TrqOvReverseGearEngage_Cnt_lgc(TRUE);
			}
			else
			{
				Rte_Write_Ap_SrlComInput_TrqOvReverseGearEngage_Cnt_lgc(FALSE);
			}

			if (Gear_Cnt_M_u16 == 0x0BU)
			{
				Rte_Write_HalfTrqOvRvrsGearEngage_Cnt_lgc(TRUE);
			}
			else
			{
				Rte_Write_HalfTrqOvRvrsGearEngage_Cnt_lgc(FALSE);
			}

		}

		if(TRUE == VC_PPPA_PrsntTypH_Cnt_M_lgc)
		{
		if(VC_PRND_Stat_Cnt_T_u16 != 0x07U) 
		{
			Rte_Call_SystemTime_GetSystemTime_mS_u32(&TRNSSTATInvMsgStartTime_mS_M_u32);
			Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_AD, 0x01, NTC_STATUS_PASSED);
		}
		else
		{
			Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(TRNSSTATInvMsgStartTime_mS_M_u32, &InvElapsedTime_mS_T_u16);
			if (InvElapsedTime_mS_T_u16 > k_TrnsStatInvTimeOut_mS_u16p0)
			{
/*NTC1A8*/		Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_AD, 0x01, NTC_STATUS_FAILED);
				PAErrInterfaceActive_Cnt_M_bit |= D_ERRINTACTNTC1A8_CNT_U32;
				DSTRevGearValid_Cnt_M_bit |= D_DSTREVGRVLDCNTL1A8_CNT_u16;
				Rte_Write_Ap_SrlComInput_TrqOvReverseGearEngage_Cnt_lgc(FALSE);
			}
		}
		}
		else
		{
			Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_AD, 0x01, NTC_STATUS_PASSED);
			PAErrInterfaceActive_Cnt_M_bit &= ~D_ERRINTACTNTC1A8_CNT_U32;
			DSTRevGearValid_Cnt_M_bit &= ~D_DSTREVGRVLDCNTL1A8_CNT_u16;
		}



		/*Per DID A001 - EPS Internal and Bussed Signals*/
		SrlComInput_WriteBits(0x00U,T_A001InternalBusSig_Cnt_u8,296U,300U);
		SrlComInput_WriteBits((uint32)VC_PRND_Stat_Cnt_T_u16,T_A001InternalBusSig_Cnt_u8,301U,303U);

		Rte_Write_Ap_SrlComInput_CanMsgReceived_Cnt_lgc(TRUE);
	}
	else
	{

		Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(TRNSSTATMisMsgStartTime_mS_M_u32, &ElapsedTime_mS_T_u16);
		if (ElapsedTime_mS_T_u16 > k_TrnsStatTimeOut_mS_u16p0)
		{
			Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_AD, 0x01, NTC_STATUS_PASSED);
/*NTC1A9*/		Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_MissingMsg_AD, 0x01, NTC_STATUS_FAILED);
				PAErrInterfaceActive_Cnt_M_bit |= D_ERRINTACTNTC1A9_CNT_U32;
				DSTRevGearValid_Cnt_M_bit |= D_DSTREVGRVLDCNTL1A9_CNT_u16;
		}
	}

}


STATIC FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) ReadWHEELSPEED2 (void)
{	/* WHEEL_SPEED_2   - 0x202 */

	VAR(uint16, AUTOMATIC) WheelRPMFL_Cnt_T_u16;
	VAR(uint16, AUTOMATIC) WheelRPMFR_Cnt_T_u16;
	VAR(float32, AUTOMATIC) WheelRPMFL_Cnt_T_f32;
	VAR(float32, AUTOMATIC) WheelRPMFR_Cnt_T_f32;
	VAR(uint16, AUTOMATIC) ElapsedTime_mS_T_u16;
	VAR(uint16, AUTOMATIC) InvElapsedTime_mS_T_u16;
	VAR(boolean, AUTOMATIC) LeftValid_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) RightValid_Cnt_T_lgc;


	VAR(tWHEEL_SPEED2, AUTOMATIC) WHEEL_SPEED2_T_str;

	if (TRUE == Ind_WHEEL_SPEED2)
	{
		Ind_WHEEL_SPEED2 = FALSE;
		/* PRQA S 3138 1*/
		dbkGetRxSyncWHEEL_SPEED2(WHEEL_SPEED2_T_str);

		/* PRQA S 1281 2 */ /* Caused by definition in vector macro */
		WheelRPMFL_Cnt_T_u16 = GetValueRxWheelRPM_FL(WHEEL_SPEED2_T_str);
		WheelRPMFR_Cnt_T_u16 = GetValueRxWheelRPM_FR(WHEEL_SPEED2_T_str);

		Rte_Call_SystemTime_GetSystemTime_mS_u32(&WHEELSPEED2MisMsgStartTime_mS_M_u32);
		Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_MissingMsg_Wheel_Speed_2, 0x01, NTC_STATUS_PASSED);

		if((WheelRPMFL_Cnt_T_u16 != 0xFFFFU)&& (WheelRPMFR_Cnt_T_u16 != 0xFFFFU))
		{
			Rte_Call_SystemTime_GetSystemTime_mS_u32(&WHEELSPEED2InvMsgStartTime_mS_M_u32);
			Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_Wheel_Speed_2, 0x01, NTC_STATUS_PASSED);

			WheelRPMFL_Cnt_T_f32 = ((float32)WheelRPMFL_Cnt_T_u16 * 0.001953125f);
			WheelRPMFR_Cnt_T_f32 = ((float32)WheelRPMFR_Cnt_T_u16 * 0.001953125f);

			if( WRSFaultStatus_Cnt_M_b16 == 0x00)
			{
				LeftValid_Cnt_T_lgc = TRUE;
			}
			else
			{
				LeftValid_Cnt_T_lgc = FALSE;
			}

			if( WRSFaultStatus_Cnt_M_b16 == 0x00)
			{
				RightValid_Cnt_T_lgc  = TRUE;
			}
			else
			{
				RightValid_Cnt_T_lgc  = FALSE;
			}

			Rte_Write_SrlComLWhlSpdVld_Cnt_lgc(LeftValid_Cnt_T_lgc);
			Rte_Write_SrlComRWhlSpdVld_Cnt_lgc(RightValid_Cnt_T_lgc);
			Rte_Write_SrlComLWhlSpd_Hz_f32(WheelRPMFL_Cnt_T_f32);
			Rte_Write_SrlComRWhlSpd_Hz_f32(WheelRPMFR_Cnt_T_f32);

		}
		else
		{
			Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(WHEELSPEED2InvMsgStartTime_mS_M_u32, &InvElapsedTime_mS_T_u16);
			if (InvElapsedTime_mS_T_u16 > k_WSP2AInvTimeOut_mS_u16p0)
			{
/*NTC1D2*/		Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_Wheel_Speed_2, 0x01, NTC_STATUS_FAILED);
			}
		}

		Rte_Write_Ap_SrlComInput_CanMsgReceived_Cnt_lgc(TRUE);

	}
	else
	{

		Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(WHEELSPEED2MisMsgStartTime_mS_M_u32, &ElapsedTime_mS_T_u16);
		if (ElapsedTime_mS_T_u16 > k_WSP2TimeOut_mS_u16p0)
		{
			Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_Wheel_Speed_2, 0x01, NTC_STATUS_PASSED);
/*NTC1D3*/		Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_MissingMsg_Wheel_Speed_2, 0x01, NTC_STATUS_FAILED);
		}
	}
}

STATIC FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) ReadESP_A4(void)
{	/* ESP_A4  - 0x14c */

	VAR(tVehAccel_Y, AUTOMATIC) VehAccel_Y_str;
	VAR(tVehAccel_X, AUTOMATIC) VehAccel_X_str;
	VAR(uint16, AUTOMATIC) VehAccel_X_Cnt_T_u16;
	VAR(uint16, AUTOMATIC) VehAccel_Y_Cnt_T_u16;
	VAR(uint16, AUTOMATIC) ElapsedTime_mS_T_u16;
	VAR(uint16, AUTOMATIC) InvElapsedTime_mS_T_u16;

	if (TRUE == Ind_VehAccel_Y)
	{
		Ind_VehAccel_Y = FALSE;

		/* PRQA S 3138 2*/
		dbkGetRxSyncVehAccel_Y(VehAccel_Y_str);
		dbkGetRxSyncVehAccel_X(VehAccel_X_str);

		VehAccel_Y_Cnt_T_u16 = GetValueRxVehAccel_Y(VehAccel_Y_str);
		VehAccel_X_Cnt_T_u16 = GetValueRxVehAccel_X(VehAccel_X_str);

		Rte_Call_SystemTime_GetSystemTime_mS_u32(&ESP4AMisMsgStartTime_mS_M_u32);
		Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_MissingMsg_Q, 0x01, NTC_STATUS_PASSED);

		if((VehAccel_Y_Cnt_T_u16 != 0xFFU) && (VehAccel_X_Cnt_T_u16 != 0xFFU))
		{
			Rte_Call_SystemTime_GetSystemTime_mS_u32(&ESP4AInvMsgStartTime_mS_M_u32);
			Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_Q, 0x01, NTC_STATUS_PASSED);

			VehAccel_Y_Cnt_M_f32 = ((float32)VehAccel_Y_Cnt_T_u16 * 0.08f) - 10.24f;
			VehAccel_X_Cnt_M_f32 = ((float32)VehAccel_X_Cnt_T_u16 * 0.08f) - 10.24f;

			Rte_Write_VehAccel_KphpS_f32(VehAccel_Y_Cnt_M_f32);
			Rte_Write_VehAccelX_KphpS_f32(VehAccel_X_Cnt_M_f32);
		}
		else
		{
			Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(ESP4AInvMsgStartTime_mS_M_u32, &InvElapsedTime_mS_T_u16);
			if (InvElapsedTime_mS_T_u16 > k_ESP4AInvTimeOut_mS_u16p0)
			{
/*NTC140*/		Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_Q, 0x01, NTC_STATUS_FAILED);
			}
		}

		/*Per DID 0xA001 - EPS Internal and Bussed Signals*/
		SrlComInput_WriteBits((uint32)VehAccel_Y_Cnt_T_u16,T_A001InternalBusSig_Cnt_u8,176U,183U);
		
		Rte_Write_Ap_SrlComInput_CanMsgReceived_Cnt_lgc(TRUE);
	}
	else
	{

		Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(ESP4AMisMsgStartTime_mS_M_u32, &ElapsedTime_mS_T_u16);
		if (ElapsedTime_mS_T_u16 > k_ESP4AMsgTimeOut_mS_u16p0)
		{
			Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_Q, 0x01, NTC_STATUS_PASSED);
/*NTC141*/		Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_MissingMsg_Q, 0x01, NTC_STATUS_FAILED);
				Rte_Write_VehAccel_KphpS_f32(0);
				Rte_Write_VehAccelX_KphpS_f32(0);
		}
	}
}

STATIC FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) ReadECMA3(void)
{	/* ECM_A3  - 0x2F8 */

	VAR(tECM_A3_PKT, AUTOMATIC) tECM_A3_PKT_str;
	VAR(uint8, AUTOMATIC)	ESSENGST_Cnt_T_u08;
	VAR(boolean, AUTOMATIC) EssEngStop_Cnt_T_lgc;
	VAR(uint16, AUTOMATIC) 	ElapsedTime_mS_T_u16;
	VAR(uint16, AUTOMATIC) 	InvElapsedTime_mS_T_u16;

	if (TRUE == Ind_ECM_A3_PKT)
	{
		Ind_ECM_A3_PKT = FALSE;
		/* PRQA S 3138 1*/
		dbkGetRxSyncECM_A3_PKT(tECM_A3_PKT_str);

		Rte_Call_SystemTime_GetSystemTime_mS_u32(&ECMA3MisMsgStartTime_mS_M_u32);
		Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_MissingMsg_S, 0x01, NTC_STATUS_PASSED);

		ESSENGST_Cnt_T_u08 = GetValueRxESS_ENG_ST(tECM_A3_PKT_str);

		if(ESSENGST_Cnt_T_u08 != 0x0FU)
		{

			Rte_Call_SystemTime_GetSystemTime_mS_u32(&ECMA3InvMsgStartTime_mS_M_u32);
			Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_AE, 0x01, NTC_STATUS_PASSED);

			if((D_ESSENGSTDSBL_CNT_U08 == ESSENGST_Cnt_T_u08) ||
					(D_ESSENGSTSTPRTCT_CNT_U08 == ESSENGST_Cnt_T_u08) ||
					(D_ESSENGSTSNA_CNT_U08 == ESSENGST_Cnt_T_u08))
			{
				EssEngStop_Cnt_T_lgc = TRUE;
			}
			else
			{
				EssEngStop_Cnt_T_lgc = FALSE;
			}
		}
		else
		{
			Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(ECMA3InvMsgStartTime_mS_M_u32, &InvElapsedTime_mS_T_u16);
			if ((InvElapsedTime_mS_T_u16 > k_ECMA3InvTimeOut_mS_u16p0) && (TRUE == SpStPrsnt_Cnt_M_lgc))
			{
/*NTC1B0*/		Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_AE, 0x01, NTC_STATUS_FAILED);
			}
		}

		/*Per DID A001 - EPS Internal and Bussed Signals*/
		SrlComInput_WriteBits((uint32)ESSENGST_Cnt_T_u08,T_A001InternalBusSig_Cnt_u8,160U,163U);

		Rte_Write_EssEngStop_Cnt_lgc(EssEngStop_Cnt_T_lgc);
		Rte_Write_Ap_SrlComInput_CanMsgReceived_Cnt_lgc(TRUE);
	}
	else
	{

			Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(ECMA3MisMsgStartTime_mS_M_u32, &ElapsedTime_mS_T_u16);
			if (ElapsedTime_mS_T_u16 > k_ECMA3MsgTimeOut_mS_u16p0)
			{
				Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_AE, 0x01, NTC_STATUS_PASSED);
/*NTC151*/		Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_MissingMsg_S, 0x01, NTC_STATUS_FAILED);
			}

	}
}

STATIC FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) ReadICA1(void)
{	/* IC_A1  - 0x310 */

	VAR(tODO, AUTOMATIC) tODO_PKT_str;
	VAR(uint32, AUTOMATIC) ODO_Cnt_T_u32;
	VAR(uint32, AUTOMATIC) ODORcvd_Cnt_T_u32;
	VAR(float32, AUTOMATIC) ODO_Km_T_f32;
	VAR(uint16, AUTOMATIC) ElapsedTime_mS_T_u16;

	if (TRUE == Ind_ODO)
	{
		Ind_ODO = FALSE;
		/* PRQA S 3138 1*/
		dbkGetRxSyncODO(tODO_PKT_str);
		/* PRQA S 310 2 */ /* Needed due to definition in vector macro */
		ODORcvd_Cnt_T_u32 = *(uint32*) GetValueRxODO(tODO_PKT_str);

		ODO_Cnt_T_u32 = (ODORcvd_Cnt_T_u32>>8); 	/*!!!!!!!!!! Clear LATEST BYTE !!! CAREFULL */

		if (ODO_Cnt_T_u32 < D_INVALIDODO_U32)
		{
			Rte_Call_SystemTime_GetSystemTime_mS_u32(&IC1AInvMsgStartTime_mS_M_u32);
			Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_T, 0x01, NTC_STATUS_PASSED);

			ODO_Km_T_f32 = D_ODOSCALE_CNT_F32 * (float32)ODO_Cnt_T_u32;
			CDD_Odometer_Cnt_u32 = (uint32)ODO_Km_T_f32;

			/*VIN odometer has been started, check if it is finished*/
			if(TRUE == CurrentVINPending_Cnt_M_lgc)
			{
				/* PRQA S 4395 1 */ /* Cast being done in macro */
				Nvm_VINOdometer_Cnt_u8[0] = (uint8)FPM_FloatToFixed_m((ODO_Km_T_f32 - CurrentVinPendingStart_Km_M_f32),u16p0_T);
				NvM_SetRamBlockStatus(NVM_BLOCK_SER_VINODOMETERCOUNTER, TRUE);

				if((ODO_Km_T_f32 - CurrentVinPendingStart_Km_M_f32) >= 5.0F)
				{
					/*Lock the Original VIN*/
					memcpy(Nvm_VINOriginal_Cnt_u8, Nvm_VINCurrent_Cnt_u8, D_VINSIZE_CNT_U08);
					Nvm_VINOdometer_Cnt_u8[0] = 0U;
					Nvm_VINOdometer_Cnt_u8[1] = TRUE; /*RAM block status set when counter begins.*/

					NvM_SetRamBlockStatus(NVM_BLOCK_SER_VINORIGINAL, TRUE);
					NvM_SetRamBlockStatus(NVM_BLOCK_SER_VINODOMETERCOUNTER, TRUE);

					CurrentVINPending_Cnt_M_lgc = FALSE;
				}
			}

			/*Start the VIN odometer counter.*/
			if((TRUE == StartVinOdo_Cnt_M_lgc) && (D_NETCFGSTATPROG_CNT_U16 == NET_CFG_STAT_PT_Cnt_M_u16))
			{
				StartVinOdo_Cnt_M_lgc = FALSE;
				/*Add the VIN odometer counter to the distance traveled.*/
				CurrentVinPendingStart_Km_M_f32 = ODO_Km_T_f32 - (float32)Nvm_VINOdometer_Cnt_u8[0];
				CurrentVINPending_Cnt_M_lgc = TRUE;
			}
		}
		else
		{
			Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(IC1AInvMsgStartTime_mS_M_u32, &ElapsedTime_mS_T_u16);
			if (ElapsedTime_mS_T_u16 > k_IC1AAInvTimeOut_mS_u16p0)
			{
/*NTC158*/		Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_T, 0x01, NTC_STATUS_FAILED);
			}

		}

		Rte_Call_SystemTime_GetSystemTime_mS_u32(&IC1AMisMsgStartTime_mS_M_u32);
		Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_MissingMsg_T, 0x01, NTC_STATUS_PASSED);

		/*Per DID 0xA001 - EPS Internal and Bussed Signals*/
		SrlComInput_WriteBits(ODO_Cnt_T_u32,T_A001InternalBusSig_Cnt_u8,0U,23U);
		
		Rte_Write_Ap_SrlComInput_CanMsgReceived_Cnt_lgc(TRUE);
	}
	else
	{

		Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(IC1AMisMsgStartTime_mS_M_u32, &ElapsedTime_mS_T_u16);
		if (ElapsedTime_mS_T_u16 > k_IC1AMsgTimeOut_mS_u16p0)
		{
			Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_T, 0x01, NTC_STATUS_PASSED);
/*NTC159*/		Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_MissingMsg_T, 0x01, NTC_STATUS_FAILED);
		}

	}
}

STATIC FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) ReadVIN(void)
{	/* VIN  - 0x3E0 */

	VAR(tVIN_INFO, AUTOMATIC) tVIN_INFO_PKT_str;
	VAR(uint16, AUTOMATIC) VINMSG_Cnt_T_u16;
	P2VAR(uint8, AUTOMATIC,RTE_AP_SRLCOMINPUT_APPL_VAR) VINData_Cnt_T_u8;
	VAR(uint16, AUTOMATIC) ElapsedTime_mS_T_u16;
	VAR(uint16, AUTOMATIC) VinCharStrt_Cnt_T_u16;
	VAR(uint16, AUTOMATIC) VinChar_Cnt_T_u16;
	VAR(uint16, AUTOMATIC) VinCharEnd_Cnt_T_u16;
	VAR(boolean, AUTOMATIC) VINMatch_T_lgc;
	VAR(uint8, AUTOMATIC) VINsize_T_u08;

	if (TRUE == Ind_VIN_INFO)
	{
		Ind_VIN_INFO = FALSE;
		/* PRQA S 3138 1*/
		dbkGetRxSyncVIN_INFO(tVIN_INFO_PKT_str);
		VINMSG_Cnt_T_u16 = GetValueRxVIN_MSG(tVIN_INFO_PKT_str);
		VINData_Cnt_T_u8 = GetValueRxVIN_DATA(tVIN_INFO_PKT_str);

		Rte_Call_SystemTime_GetSystemTime_mS_u32(&VINMisMsgStartTime_mS_M_u32);
		Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_MissingMsg_U, 0x01, NTC_STATUS_PASSED);

		if(D_NETCFGSTATPROG_CNT_U16 == NET_CFG_STAT_PT_Cnt_M_u16)
		{
			switch(VINMSG_Cnt_T_u16)
			{
				case 0x00u:
					VinCharStrt_Cnt_T_u16 = 0U;
					VinCharEnd_Cnt_T_u16 = 7U;
					Rte_Call_SystemTime_GetSystemTime_mS_u32(&VINInvMsgStartTime_mS_M_u32);
					Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_U, 0x01, NTC_STATUS_PASSED);
				break;
				case 0x01u:
					VinCharStrt_Cnt_T_u16 = 7U;
					VinCharEnd_Cnt_T_u16 = 14U;
					Rte_Call_SystemTime_GetSystemTime_mS_u32(&VINInvMsgStartTime_mS_M_u32);
					Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_U, 0x01, NTC_STATUS_PASSED);
				break;
				case 0x02u:
					VinCharStrt_Cnt_T_u16 = 14U;
					VinCharEnd_Cnt_T_u16 = 17U;
					Rte_Call_SystemTime_GetSystemTime_mS_u32(&VINInvMsgStartTime_mS_M_u32);
					Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_U, 0x01, NTC_STATUS_PASSED);
				break;
				case 0x03u:
				default:
					VinCharStrt_Cnt_T_u16 = 0U;
					VinCharEnd_Cnt_T_u16 = 0U;
					Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(VINInvMsgStartTime_mS_M_u32, &ElapsedTime_mS_T_u16);
					if (ElapsedTime_mS_T_u16 > k_VINInvTimeOut_mS_u16p0)
					{
/*NTC160*/				Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_U, 0x01, NTC_STATUS_FAILED);
					}
				break;
			}

			if(VINMSG_Cnt_T_u16 < 3U)
			{
				/*If this is the first time this message has been received since a write, copy it to a buffer.*/
				if(0U == VINRxCount_Cnt_M_u08[VINMSG_Cnt_T_u16])
				{
					VINRxCount_Cnt_M_u08[VINMSG_Cnt_T_u16] = 1U;

					for( VinChar_Cnt_T_u16 = VinCharStrt_Cnt_T_u16; VinChar_Cnt_T_u16 < VinCharEnd_Cnt_T_u16; VinChar_Cnt_T_u16++)
					{
						PrevVINData_Cnt_M_u08[VinChar_Cnt_T_u16] = VINData_Cnt_T_u8[VinChar_Cnt_T_u16 - VinCharStrt_Cnt_T_u16];
					}
				}
				else
				/*If this part of the VIN has been received before, make sure the new data matches the old data.*/
				{
					VAR(boolean, AUTOMATIC) VINMismatch_Cnt_T_lgc;
					VINMismatch_Cnt_T_lgc = FALSE;

					for( VinChar_Cnt_T_u16 = VinCharStrt_Cnt_T_u16; VinChar_Cnt_T_u16 < VinCharEnd_Cnt_T_u16; VinChar_Cnt_T_u16++)
					{
						if(PrevVINData_Cnt_M_u08[VinChar_Cnt_T_u16] != VINData_Cnt_T_u8[VinChar_Cnt_T_u16 - VinCharStrt_Cnt_T_u16])
						{
							VINMismatch_Cnt_T_lgc = TRUE;
							PrevVINData_Cnt_M_u08[VinChar_Cnt_T_u16] = VINData_Cnt_T_u8[VinChar_Cnt_T_u16 - VinCharStrt_Cnt_T_u16];
						}
					}

					if(TRUE == VINMismatch_Cnt_T_lgc)
					{
						VINRxCount_Cnt_M_u08[VINMSG_Cnt_T_u16] = 1U;
					}
					else
					{
						VINRxCount_Cnt_M_u08[VINMSG_Cnt_T_u16] = 2U;
					}
				}
			}

			/*If all parts of the VIN have been received at least twice, write the value to NvM*/
			if(	(VINRxCount_Cnt_M_u08[0] > 1U) &&
				(VINRxCount_Cnt_M_u08[1] > 1U) &&
				(VINRxCount_Cnt_M_u08[2] > 1U))
			{
				VINRxCount_Cnt_M_u08[0] = 0U;
				VINRxCount_Cnt_M_u08[1] = 0U;
				VINRxCount_Cnt_M_u08[2] = 0U;

				VINMatch_T_lgc = TRUE;

				for(VINsize_T_u08 = 0; VINsize_T_u08 < D_VINSIZE_CNT_U08; VINsize_T_u08++)
				{
					if(Nvm_VINCurrent_Cnt_u8[VINsize_T_u08] != PrevVINData_Cnt_M_u08[VINsize_T_u08])
					{
						VINMatch_T_lgc = FALSE;
					}
				}

				if(VINMatch_T_lgc == FALSE)
				{
					memcpy(Nvm_VINCurrent_Cnt_u8, PrevVINData_Cnt_M_u08, D_VINSIZE_CNT_U08);
					NvM_SetRamBlockStatus(NVM_BLOCK_SER_VINCURRENT, TRUE);
					/*Per DID 0x0103 - VIN Odometer (Counter) */
					/*If the Original VIN has not been locked yet, start the VIN odometer.*/
					StartVinOdo_Cnt_M_lgc = TRUE;
					CurrentVINPending_Cnt_M_lgc = FALSE;

					if(Nvm_VINOdometer_Cnt_u8[1] != TRUE)
					{
						memcpy(Nvm_VINOriginal_Cnt_u8, Nvm_VINCurrent_Cnt_u8, D_VINSIZE_CNT_U08);
						NvM_SetRamBlockStatus(NVM_BLOCK_SER_VINORIGINAL, TRUE);
						Nvm_VINOdometer_Cnt_u8[0] = 0;
						NvM_SetRamBlockStatus(NVM_BLOCK_SER_VINODOMETERCOUNTER, TRUE);
					}
				}
			}
		}
		else
		{
			Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_U, 0x01, NTC_STATUS_PASSED);/*NTC160*/
		}
		
		Rte_Write_Ap_SrlComInput_CanMsgReceived_Cnt_lgc(TRUE);
	}
	else
	{
		Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(VINMisMsgStartTime_mS_M_u32, &ElapsedTime_mS_T_u16);
		if (ElapsedTime_mS_T_u16 > k_VINMsgTimeOut_mS_u16p0)
		{
			Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_U, 0x01, NTC_STATUS_PASSED);/*NTC160*/
/*NTC161*/		Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_MissingMsg_U, 0x01, NTC_STATUS_FAILED);
		}
	}
}


STATIC FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) ReadENGCFG(void)
{	/* ENG_CFG - 0x3E1 */

	VAR(tENG_CFG, AUTOMATIC) tENG_CFG_str;
	VAR(boolean, AUTOMATIC) SpStPrsnt_Cnt_T_lgc;
	VAR(uint16, AUTOMATIC) ElapsedTime_mS_T_u16;
	VAR(uint8, AUTOMATIC) TransType_Cnt_T_u08;

	if (TRUE == Ind_ENG_CFG)
	{
		Ind_ENG_CFG = FALSE;
		/* PRQA S 3138 1*/
		dbkGetRxSyncENG_CFG(tENG_CFG_str);
		SpStPrsnt_Cnt_T_lgc = GetValueRxSpStPrsnt(tENG_CFG_str);
		TransType_Cnt_T_u08 = GetValueRxTRANS_TYPE(tENG_CFG_str);

		Rte_Call_SystemTime_GetSystemTime_mS_u32(&EngCfgMisMsgStartTime_mS_M_u32);
		Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_MissingMsg_AC, 0x01, NTC_STATUS_PASSED);

		if(TransType_Cnt_T_u08 == 0x01U)
		{
			TrnsmsnType_Cnt_M_u8 = D_AUTOTRANS_CNT_U8;
		}
		else
		{
			TrnsmsnType_Cnt_M_u8 = D_MANTRANS_CNT_U8;
		}


		Rte_Write_Ap_SrlComInput_SpStPrsnt_Cnt_lgc(SpStPrsnt_Cnt_T_lgc);/* used in DID F10B */
		
		/*Per DID A001 - EPS Internal and Bussed Signals*/
		SrlComInput_WriteBits(0x00U,T_A001InternalBusSig_Cnt_u8,288U,289U);
		SrlComInput_WriteBits(SpStPrsnt_Cnt_T_lgc,T_A001InternalBusSig_Cnt_u8,290U,290U);
		SrlComInput_WriteBits(0x00U,T_A001InternalBusSig_Cnt_u8,294U,295U);

		SpStPrsnt_Cnt_M_lgc = SpStPrsnt_Cnt_T_lgc;

		Rte_Write_Ap_SrlComInput_CanMsgReceived_Cnt_lgc(TRUE);
	}
	else
	{
		Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(EngCfgMisMsgStartTime_mS_M_u32, &ElapsedTime_mS_T_u16);
		if (ElapsedTime_mS_T_u16 > k_EngCfgMisMsgTimeOut_mS_u16p0)
		{
			if (TRUE == NetCfg_ECMTypH_Cnt_M_lgc)
			{
/*NTC 1A1*/		Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_MissingMsg_AC, 0x01, NTC_STATUS_FAILED);
			}
			else
			{
/*NTC 1A1*/		Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_MissingMsg_AC, 0x01, NTC_STATUS_PASSED);
			}
		}
	}

}


STATIC FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) ReadVehCfg1(void)
{	/* VehCfg1 - 0x3E8 */

	VAR(tVehCfg1_Pkt, AUTOMATIC) tVehCfg1_Pkt_str;
	VAR(uint16, AUTOMATIC) VehCfg1St_Cnt_T_u16;
	VAR(uint8, AUTOMATIC) VCModelYear_Cnt_T_u08;
	VAR(uint8, AUTOMATIC) VCVehLine_Cnt_T_u08;
	VAR(uint8, AUTOMATIC) VCCountry_Cnt_T_u08;
	VAR(uint8, AUTOMATIC) VCBodyStyle_Cnt_T_u08;
	VAR(uint16, AUTOMATIC) ElapsedTime_mS_T_u16;

	if (TRUE == Ind_VehCfg1_Pkt)
	{
		Ind_VehCfg1_Pkt = FALSE;

		/* PRQA S 3138 1*/
		dbkGetRxSyncVehCfg1_Pkt(tVehCfg1_Pkt_str);

		VehCfg1St_Cnt_T_u16 = GetValueRxVC_VehCfg1_Stat(tVehCfg1_Pkt_str);
		VCModelYear_Cnt_T_u08 = GetValueRxVC_MODEL_YEAR(tVehCfg1_Pkt_str);
		VCVehLine_Cnt_T_u08 = GetValueRxVC_VEH_LINE(tVehCfg1_Pkt_str);
		VCCountry_Cnt_T_u08 = GetValueRxVC_COUNTRY(tVehCfg1_Pkt_str);
		VCBodyStyle_Cnt_T_u08 = GetValueRxVC_BODY_STYLE(tVehCfg1_Pkt_str);

		Rte_Call_SystemTime_GetSystemTime_mS_u32(&VehCfg1MisMsgStartTime_mS_M_u32);
		Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_MissingMsg_X, 0x01, NTC_STATUS_PASSED);

		if(VehCfg1St_Cnt_T_u16 == 0x01U)
		{
			Rte_Call_SystemTime_GetSystemTime_mS_u32(&VehCfg1InvMsgStartTime_mS_M_u32);
			Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_X, 0x01, NTC_STATUS_PASSED);

			if(VehCfg1St_Cnt_T_u16 == 0x01U)
			{
				if(VCModelYear_Cnt_T_u08 == PrevVCModelYear_Cnt_M_u08)
				{
					Nvm_VehicleInfo_Cnt_u8[0] = VCModelYear_Cnt_T_u08;
					NvM_SetRamBlockStatus(NVM_BLOCK_SER_VEHICLEINFO, TRUE);
				}
				PrevVCModelYear_Cnt_M_u08 = VCModelYear_Cnt_T_u08;

				if(VCVehLine_Cnt_T_u08 == PrevVCVehLine_Cnt_M_u08)
				{
					Nvm_VehicleInfo_Cnt_u8[1] = VCVehLine_Cnt_T_u08;
					NvM_SetRamBlockStatus(NVM_BLOCK_SER_VEHICLEINFO, TRUE);
				}
				PrevVCVehLine_Cnt_M_u08 = VCVehLine_Cnt_T_u08;

				if(VCCountry_Cnt_T_u08 == PrevVCCountry_Cnt_M_u08)
				{
					Nvm_VehicleInfo_Cnt_u8[3] = VCCountry_Cnt_T_u08;
					NvM_SetRamBlockStatus(NVM_BLOCK_SER_VEHICLEINFO, TRUE);
				}
				PrevVCCountry_Cnt_M_u08 = VCCountry_Cnt_T_u08;

				if(VCBodyStyle_Cnt_T_u08 == PrevVCBodyStyle_Cnt_M_u08)
				{
					Nvm_VehicleInfo_Cnt_u8[2] = VCBodyStyle_Cnt_T_u08;
					NvM_SetRamBlockStatus(NVM_BLOCK_SER_VEHICLEINFO, TRUE);
				}
				PrevVCBodyStyle_Cnt_M_u08 = VCBodyStyle_Cnt_T_u08;
			}

		}
		else
		{
			Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(VehCfg1InvMsgStartTime_mS_M_u32, &ElapsedTime_mS_T_u16);
			if (ElapsedTime_mS_T_u16 > k_VehCfg1AInvTimeOut_mS_u16p0)
			{
	/*NTC178*/		Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_X, 0x01, NTC_STATUS_FAILED);
			}
		}
		
		Rte_Write_Ap_SrlComInput_CanMsgReceived_Cnt_lgc(TRUE);
	}
	else
	{
		Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(VehCfg1MisMsgStartTime_mS_M_u32, &ElapsedTime_mS_T_u16);
		if (ElapsedTime_mS_T_u16 > k_VehCfg1MsgTimeOut_mS_u16p0)
		{
			Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_X, 0x01, NTC_STATUS_PASSED);/*NTC178*/
			if(TRUE == NetCfg_CBCTypH_Cnt_M_lgc)
			{
/*NTC179*/		Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_MissingMsg_X, 0x01, NTC_STATUS_FAILED);
			}
			else
			{
/*NTC179*/		Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_MissingMsg_X, 0x01, NTC_STATUS_PASSED);
			}
		}
	}

}


STATIC FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) ReadBATTVOLT(void)
{	/* BATT_VOLT (CBC_PT3) - 0x200 */

	VAR(tAirTemp_Outsd, AUTOMATIC) CBCPT3AirTemp_T_str;
	VAR(tAMB_TEMP_AVG,  AUTOMATIC) CBCPT3AmbTemp_T_str;
	VAR(tBATT_VOLT,     AUTOMATIC) CBCPT3BattVolt_T_str;
	VAR(uint16,         AUTOMATIC) BattVolt_Cnt_T_u16;
	VAR(uint16,         AUTOMATIC) ElapsedTime_mS_T_u16;
	VAR(float32,        AUTOMATIC) BattVolt_Volt_T_f32;
	VAR(uint8,          AUTOMATIC) AirTemp_Cnt_T_u08;
	VAR(float32,        AUTOMATIC) AirTemp_DegC_T_f32;
	VAR(uint16,         AUTOMATIC) AmbTemp_Cnt_T_u16;
	VAR(float32,        AUTOMATIC) AmbTemp_DegC_T_f32;



	if (TRUE == Ind_BATT_VOLT)
	{
		Ind_BATT_VOLT = FALSE;
		/* PRQA S 3138 3*/
		dbkGetRxSyncAirTemp_Outsd(CBCPT3AirTemp_T_str);
		/* PRQA S 1281 2 */ /* Caused by definition in vector macro */
		dbkGetRxSyncAMB_TEMP_AVG(CBCPT3AmbTemp_T_str);
		dbkGetRxSyncBATT_VOLT(CBCPT3BattVolt_T_str);

		AirTemp_Cnt_T_u08 = GetValueRxAirTemp_Outsd(CBCPT3AirTemp_T_str);
		/* PRQA S 1281 2 */ /* Caused by definition in vector macro */
		AmbTemp_Cnt_T_u16 = GetValueRxAMB_TEMP_AVG(CBCPT3AmbTemp_T_str);
		BattVolt_Cnt_T_u16 = GetValueRxBATT_VOLT(CBCPT3BattVolt_T_str);

		Rte_Call_SystemTime_GetSystemTime_mS_u32(&BattVoltMisMsgStartTime_mS_M_u32);
		Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_MissingMsg_R, 0x01, NTC_STATUS_PASSED);

		if((BattVolt_Cnt_T_u16 < 0xFFU) && (AirTemp_Cnt_T_u08 < 0xFFU) && (AmbTemp_Cnt_T_u16 < 0xFFFFU))
		{
			Rte_Call_SystemTime_GetSystemTime_mS_u32(&BattVoltInvMsgStartTime_mS_M_u32);
			Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_R, 0x01, NTC_STATUS_PASSED);

			BattVolt_Volt_T_f32 = (float32)BattVolt_Cnt_T_u16 * 0.1f;
			AirTemp_DegC_T_f32 = (((float32)AirTemp_Cnt_T_u08 * 0.5f) - 40.0f);
			AmbTemp_DegC_T_f32 = (((float32)AmbTemp_Cnt_T_u16 * 0.01f) - 40.0f);

			Rte_Write_BattVolt_Volt_f32(BattVolt_Volt_T_f32);
			Rte_Write_AirTempOutside_DegC_f32(AirTemp_DegC_T_f32);
			Rte_Write_AmbTempAvg_DegC_f32(AmbTemp_DegC_T_f32);

/*NTC14E*/	DiagNTC14E(BattVolt_Volt_T_f32);
/*NTC14F*/	DiagNTC14F(BattVolt_Volt_T_f32);

			/*Per DID 0xA001 - EPS Internal and Bussed Signals*/
			SrlComInput_WriteBits(BattVolt_Cnt_T_u16,T_A001InternalBusSig_Cnt_u8,120U,127U);
		}
		else
		{

			Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(BattVoltInvMsgStartTime_mS_M_u32, &ElapsedTime_mS_T_u16);
			if (ElapsedTime_mS_T_u16 > k_BattVoltInvTimeOut_mS_u16p0)
			{
	/*NTC148*/		Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_R, 0x01, NTC_STATUS_FAILED);
			/*14E set to pass*/
			/*14F set to pass*/
			}
		}
		
		Rte_Write_Ap_SrlComInput_CanMsgReceived_Cnt_lgc(TRUE);

	}
	else
	{
		Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(BattVoltMisMsgStartTime_mS_M_u32, &ElapsedTime_mS_T_u16);
		if (ElapsedTime_mS_T_u16 > k_BattVoltMsgTimeOut_mS_u16p0)
		{
			Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DataOtherFltMsg_R, 0x01, NTC_STATUS_PASSED);/*NTC14e*/
			Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DataOtherFlt2Msg_R, 0x01, NTC_STATUS_PASSED);/*NTC14f*/
			Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_R, 0x01, NTC_STATUS_PASSED);/*NTC148*/
			 if (TRUE == NetCfg_CBCTypH_Cnt_M_lgc)
			 {
/*NTC149*/		Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_MissingMsg_R, 0x01, NTC_STATUS_FAILED);
			 }
			 else
			 {
/*NTC149*/		Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_MissingMsg_R, 0x01, NTC_STATUS_PASSED);
			 }

		}
	}

}

STATIC FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) ReadCfgRQ(void)
{	/* CFG_RQ - 0x314 */

	VAR(tCFG_RQ, AUTOMATIC) tCFG_RQ_str;
	VAR(uint16, AUTOMATIC) CfgFeature_Cnt_T_u08;
	VAR(uint16, AUTOMATIC) CfgStatRQ_Cnt_T_u08;
	VAR(uint16, AUTOMATIC) CfgSet_Cnt_T_u08;
	VAR(uint16, AUTOMATIC) ElapsedTime_mS_T_u16;

	if (TRUE == Ind_CFG_RQ)
	{
		Ind_CFG_RQ = FALSE;

		Rte_Call_SystemTime_GetSystemTime_mS_u32(&CfgRQMisMsgStartTime_mS_M_u32);
		Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_MissingMsg_CFG_RQ, 0x01, NTC_STATUS_PASSED);

		/* PRQA S 3138 1*/
		dbkGetRxSyncCFG_RQ(tCFG_RQ_str);

		CfgFeature_Cnt_T_u08 = GetValueRxCFG_FEATURE(tCFG_RQ_str);
		CfgStatRQ_Cnt_T_u08 = GetValueRxCFG_STAT_RQ(tCFG_RQ_str);
		CfgSet_Cnt_T_u08 = GetValueRxCFG_SET(tCFG_RQ_str);

		if((D_CFGFEATURE_CNT_U08 == CfgFeature_Cnt_T_u08) &&
				(D_CFGSTATRQ_CNT_U08 == CfgStatRQ_Cnt_T_u08))
				{
					if( D_CFGSETHI_CNT_U08 >= CfgSet_Cnt_T_u08)
					{
						DesiredTunPersTypH_Cnt_M_u08 = (uint8)CfgSet_Cnt_T_u08;
					}
				}

		Rte_Write_Ap_SrlComInput_CanMsgReceived_Cnt_lgc(TRUE);
		Rte_Write_Ap_SrlComInput_CfgStatRQ_Cnt_u08(CfgStatRQ_Cnt_T_u08);
	}
	else
	{
		Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(CfgRQMisMsgStartTime_mS_M_u32, &ElapsedTime_mS_T_u16);
		if (ElapsedTime_mS_T_u16 > k_CfgRQMisMsgTimeOut_mS_u16p0)
		{
/*NTC1DA*/		Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_MissingMsg_CFG_RQ, 0x01, NTC_STATUS_FAILED);
		}

	}
}

STATIC FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) ReadCfgRQC(void)
{	/* CFG_RQC - 0x316 */

	VAR(tCFG_RQ_C, AUTOMATIC) tCFG_RQ_C_str;
	VAR(uint16, AUTOMATIC) CfgFeatureC_Cnt_T_u08;
	VAR(uint16, AUTOMATIC) CfgStatRQC_Cnt_T_u08;
	VAR(uint16, AUTOMATIC) CfgSetC_Cnt_T_u08;
	VAR(uint16, AUTOMATIC) ElapsedTime_mS_T_u16;

	if (TRUE == Ind_CFG_RQ_C)
	{
		Ind_CFG_RQ_C = FALSE;

		Rte_Call_SystemTime_GetSystemTime_mS_u32(&CfgRQCMisMsgStartTime_mS_M_u32);
		Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_MissingMsg_CFG_RQ_C, 0x01, NTC_STATUS_PASSED);

		/* PRQA S 3138 1*/
		dbkGetRxSyncCFG_RQ_C(tCFG_RQ_C_str);

		CfgFeatureC_Cnt_T_u08 = GetValueRxCFG_FEATURE_C(tCFG_RQ_C_str);
		CfgStatRQC_Cnt_T_u08 = GetValueRxCFG_STAT_RQ_C(tCFG_RQ_C_str);
		CfgSetC_Cnt_T_u08 = GetValueRxCFG_SET_C(tCFG_RQ_C_str);

		if((D_CFGFEATURE_CNT_U08 == CfgFeatureC_Cnt_T_u08) &&
				(D_CFGSTATRQ_CNT_U08 == CfgStatRQC_Cnt_T_u08))
				{
					if( D_CFGSETHI_CNT_U08 >= CfgSetC_Cnt_T_u08)
					{
						DesiredTunPersTypH_Cnt_M_u08 = (uint8)CfgSetC_Cnt_T_u08;
					}
				}

		Rte_Write_Ap_SrlComInput_CanMsgReceived_Cnt_lgc(TRUE);
	}
	else
	{
		Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(CfgRQCMisMsgStartTime_mS_M_u32, &ElapsedTime_mS_T_u16);
		if (ElapsedTime_mS_T_u16 > k_CfgRQCMisMsgTimeOut_mS_u16p0)
		{
/*NTC1DB*/		Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_MissingMsg_CFG_RQ_C, 0x01, NTC_STATUS_FAILED);
		}

	}
}

STATIC FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) ReadGWLinIC2 (void)
{	/* GW_LIN_I_C2 - 31F */

	VAR(tEPS_MODE_REQ, AUTOMATIC) tEPS_MODE_REQ_str;
	VAR(uint8, AUTOMATIC) EPS_Mode_Req_Cnt_T_u08;
	VAR(uint16, AUTOMATIC) ElapsedTime_mS_T_u16;
	VAR(uint8, AUTOMATIC) DesiredTunPers_Cnt_T_u16;
	VAR(float32, AUTOMATIC) AnaHwTorque_HwNm_T_f32;
	VAR(uint8, AUTOMATIC) PrkAssistState_Cnt_T_u08;
	VAR(uint8, AUTOMATIC) HaLFState_Cnt_T_u08;

	Rte_Read_Ap_SrlComInput_AnaHwTorque_HwNm_f32(&AnaHwTorque_HwNm_T_f32);
	Rte_Read_Ap_SrlComInput_PrkAssistState_Cnt_u08(&PrkAssistState_Cnt_T_u08);
	Rte_Read_Ap_SrlComInput_HaLFState_Cnt_u08(&HaLFState_Cnt_T_u08);
	DesiredTunPers_Cnt_T_u16 = PrevDesiredTunPers_Cnt_M_u16;

	if (TRUE == Ind_EPS_MODE_REQ)
	{
		Ind_EPS_MODE_REQ = FALSE;
		/* PRQA S 3138 1*/
		dbkGetRxSyncEPS_MODE_REQ(tEPS_MODE_REQ_str);

		Rte_Call_SystemTime_GetSystemTime_mS_u32(&GWLINIC2MisMsgStartTime_mS_M_u32);
		Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_MissingMsg_GW_LIN_I_C2, 0x01, NTC_STATUS_PASSED);

		EPS_Mode_Req_Cnt_T_u08 = GetValueRxEPS_MODE_REQ(tEPS_MODE_REQ_str);

		if(EPS_Mode_Req_Cnt_T_u08 < 0x07U)
		{
			Rte_Call_SystemTime_GetSystemTime_mS_u32(&GWLINIC2InvMsgStartTime_mS_M_u32);
			Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_GW_LIN_I_C2, 0x01, NTC_STATUS_PASSED);

			switch(EPS_Mode_Req_Cnt_T_u08)
			{
			case 0x00U:
				DesiredTunPers_Cnt_T_u16 = DesiredTunPersTypH_Cnt_M_u08;
				break;
			case 0x01U:
			case 0x02U:
			case 0x03U:
				DesiredTunPersTypH_Cnt_M_u08 = EPS_Mode_Req_Cnt_T_u08 -1U;
				break;
			case 0x04U:
				DesiredTunPers_Cnt_T_u16 = 0x00U;
				break;
			case 0x05U:
				DesiredTunPers_Cnt_T_u16 = 0x01U;
				break;
			case 0x06U:
				DesiredTunPers_Cnt_T_u16 = 0x02U;
				break;
			default:
				break;
			}
		}
		else
		{
			if( EPS_Mode_Req_Cnt_T_u08 == 0x07U)
			{
				DesiredTunPers_Cnt_T_u16 = DesiredTunPersTypH_Cnt_M_u08;
			}

			Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(GWLINIC2InvMsgStartTime_mS_M_u32, &ElapsedTime_mS_T_u16);
			if (ElapsedTime_mS_T_u16 > k_GWLINIC2InvMsgTimeOut_mS_u16p0)
			{
	/*NTC1D4*/		Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_GW_LIN_I_C2, 0x01, NTC_STATUS_FAILED);
			}
		}


		Rte_Write_Ap_SrlComInput_EPS_Mode_Req_Cnt_u08(EPS_Mode_Req_Cnt_T_u08);
		Rte_Write_Ap_SrlComInput_CanMsgReceived_Cnt_lgc(TRUE);

		/* PRQA S 3415 8*/ /* Abs_f32_m is a macro, function side effects are not a risk */
		if((Abs_f32_m(AnaHwTorque_HwNm_T_f32) < k_AnaHwTorquePerLim_HwNm_f32) &&
		  (( TOC_Sts_Cnt_M_u16 != TOCSTATE_ACTIVEMODE05) &&
			( TOC_Sts_Cnt_M_u16 != TOCSTATE_ACTIVEMODE06) &&
			( TOC_Sts_Cnt_M_u16 != TOCSTATE_ACTIVEMODE07) &&
			( TOC_Sts_Cnt_M_u16 != TOCSTATE_READY)) &&
		  (D_PASTATEACTIVE_CNT_U08 != PrkAssistState_Cnt_T_u08) &&
		  ((Abs_f32_m(HaLFTrqOvCmdRqst_MtrNm_M_f32) < k_HaLFTrqPerLim_HwNm_f32)||
			(HaLFState_Cnt_T_u08 != D_HALFSTATEACTIVE_CNT_U08)))
		{
			Rte_Write_DesiredTunPers_Cnt_u16(DesiredTunPers_Cnt_T_u16);
			PrevDesiredTunPers_Cnt_M_u16 = DesiredTunPers_Cnt_T_u16;
		}

		if(DesiredTunPers_Cnt_T_u16 == 0x01U)
		{
			HalfTrqMax_Nm_M_f32 = k_HalfTrqMaxSpt_Nm_f32;
			HaLFTrqOvrlSlewLmt_Nm_M_f32 = k_HaLFTrqOvrlSlewLmtSpt_NmpS_f32/100.0f;
		}
		else
		{
			HalfTrqMax_Nm_M_f32 = k_HalfTrqMaxNrm_Nm_f32;
			HaLFTrqOvrlSlewLmt_Nm_M_f32 = k_HaLFTrqOvrlSlewLmtNrm_NmpS_f32/100.0f;
		}

	}
	else
	{
		Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(GWLINIC2MisMsgStartTime_mS_M_u32, &ElapsedTime_mS_T_u16);
		if (ElapsedTime_mS_T_u16 > k_GWLINIC2MsgTimeOut_mS_u16p0)
		{
			Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_GW_LIN_I_C2, 0x01, NTC_STATUS_PASSED);/*NTC1d4*/
			 if (TRUE == NetCfg_CBCTypH_Cnt_M_lgc)
			 {
/*NTC1D5*/		Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_MissingMsg_GW_LIN_I_C2, 0x01, NTC_STATUS_FAILED);
			 }
			 else
			 {
/*NTC1D5*/		Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_MissingMsg_GW_LIN_I_C2, 0x01, NTC_STATUS_PASSED);
			 }
		}
	}
}

STATIC FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) ReadEcmIndicators(void)
{	/* ECM_INDICATORS  - 0x2A0 */

	VAR(tEngOilTemp, AUTOMATIC) tEngOilTemp_str;
	VAR(uint8, AUTOMATIC) EngOilTemp_Cnt_T_u08;
	VAR(float32, AUTOMATIC) EngOilTemp_Cnt_T_f32;
	VAR(uint16, AUTOMATIC) ElapsedTime_mS_T_u16;

	if (TRUE == Ind_EngOilTemp)
	{
		Ind_EngOilTemp = FALSE;
		/* PRQA S 3138 1*/
		dbkGetRxSyncEngOilTemp(tEngOilTemp_str);

		Rte_Call_SystemTime_GetSystemTime_mS_u32(&EngOilTempMisMsgStartTime_mS_M_u32);
		Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_MissingMsg_Y, 0x01, NTC_STATUS_PASSED);

		EngOilTemp_Cnt_T_u08 = GetValueRxEngOilTemp(tEngOilTemp_str);


		if(EngOilTemp_Cnt_T_u08 < 0xC8U)
		{
			EngOilTemp_Cnt_T_f32 = ((float32)EngOilTemp_Cnt_T_u08 - 40.0f);
		}
		else
		{
			EngOilTemp_Cnt_T_u08 = 0x00;
		}

		Rte_Write_EngOilTemp_DegC_f32(EngOilTemp_Cnt_T_f32);

		Rte_Write_Ap_SrlComInput_CanMsgReceived_Cnt_lgc(TRUE);
	}
	else
	{
		Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(EngOilTempMisMsgStartTime_mS_M_u32, &ElapsedTime_mS_T_u16);
		if (ElapsedTime_mS_T_u16 > k_EngOilTempMsgTimeOut_mS_u16p0)
		{
/*NTC181*/		Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_MissingMsg_Y, 0x01, NTC_STATUS_FAILED);
		}
	}
}

STATIC FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) ReadCBC_PT1  (void)
{	/* CBC_PT1 - 334*/

	VAR(tREV_GEAR, AUTOMATIC) tREV_GEAR_str;
	VAR(uint8, AUTOMATIC) RevGear_Cnt_T_u08;
	VAR(uint16, AUTOMATIC) ElapsedTime_mS_T_u16;

	if (TRUE == Ind_REV_GEAR)
	{
		Ind_REV_GEAR = FALSE;
		/* PRQA S 3138 1*/
		dbkGetRxSyncREV_GEAR(tREV_GEAR_str);

		Rte_Call_SystemTime_GetSystemTime_mS_u32(&RevGearTempMisMsgStartTime_mS_M_u32);
		Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_MissingMsg_AF, 0x01, NTC_STATUS_PASSED);
		PAErrInterfaceActive_Cnt_M_bit &= ~D_ERRINTACTNTC1B9_CNT_U32;
		HaLFErrInterfaceActive_Cnt_M_bit &= ~D_ERRINTACTNTC1B9_CNT_U32;
		DSTRevGearValid_Cnt_M_bit &= ~D_DSTREVGRVLDCNTL1B9_CNT_u16;

		RevGear_Cnt_T_u08 = GetValueRxREV_GEAR(tREV_GEAR_str);

		if(D_MANTRANS_CNT_U8 == TrnsmsnType_Cnt_M_u8)
		{
			if ( RevGear_Cnt_T_u08 == 0x01U)
			{
				Rte_Write_Ap_SrlComInput_TrqOvReverseGearEngage_Cnt_lgc(TRUE);
				Rte_Write_HalfTrqOvRvrsGearEngage_Cnt_lgc(TRUE);
			}
			else
			{
				Rte_Write_Ap_SrlComInput_TrqOvReverseGearEngage_Cnt_lgc(FALSE);
				Rte_Write_HalfTrqOvRvrsGearEngage_Cnt_lgc(FALSE);
			}
		}
	}
	else
	{
		Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(RevGearTempMisMsgStartTime_mS_M_u32, &ElapsedTime_mS_T_u16);
		if (ElapsedTime_mS_T_u16 > k_RevGearMsgTimeOut_mS_u16p0)
		{
/*NTC1B9*/		Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_MissingMsg_AF, 0x01, NTC_STATUS_FAILED);
				PAErrInterfaceActive_Cnt_M_bit |= D_ERRINTACTNTC1B9_CNT_U32;
				HaLFErrInterfaceActive_Cnt_M_bit |= D_ERRINTACTNTC1B9_CNT_U32;
				DSTRevGearValid_Cnt_M_bit |= D_DSTREVGRVLDCNTL1B9_CNT_u16;
				Rte_Write_Ap_SrlComInput_TrqOvReverseGearEngage_Cnt_lgc(FALSE);
		}
	}
}

STATIC FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) ReadVehCfg7(void)
{	/* VehCfg7 - 0x381 */

	VAR(tVehCfg7_Pkt, AUTOMATIC) tVehCfg7_Pkt_str;
	VAR(uint8, AUTOMATIC) VC_LDW_Cnt_T_u08;
	VAR(uint8, AUTOMATIC) VC_DST_Present_Cnt_T_u08;
	VAR(uint16, AUTOMATIC) ElapsedTime_mS_T_u16;

	if (TRUE == Ind_VehCfg7_Pkt)
	{
		Ind_VehCfg7_Pkt = FALSE;

		Rte_Call_SystemTime_GetSystemTime_mS_u32(&VehCfg7MisMsgStartTime_mS_M_u32);
		Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_MissingMsg_VehCfg7, 0x01, NTC_STATUS_PASSED);

		/* PRQA S 3138 1*/
		dbkGetRxSyncVehCfg7_Pkt(tVehCfg7_Pkt_str);
		VC_LDW_Cnt_T_u08 = GetValueRxVC_LDW(tVehCfg7_Pkt_str);
		VC_DST_Present_Cnt_T_u08 = GetValueRxVC_DST_Present(tVehCfg7_Pkt_str);

		if(	(VC_DST_Present_Cnt_T_u08 == PrevDSTPresent_Cnt_M_lgc) &&
			(VC_DST_Present_Cnt_T_u08 != DSTFuncPresentTypH_Cnt_M_lgc))
		{
			DSTFuncPresentTypH_Cnt_M_lgc = VC_DST_Present_Cnt_T_u08;
		}
		PrevDSTPresent_Cnt_M_lgc = (boolean)VC_DST_Present_Cnt_T_u08;

		Rte_Write_Ap_SrlComInput_DSTFuncPresent_Cnt_lgc(DSTFuncPresentTypH_Cnt_M_lgc);

		if(	(VC_LDW_Cnt_T_u08 == PrevHaLFPresent_Cnt_M_lgc) &&
			(VC_LDW_Cnt_T_u08 != (uint16)HaLFFuncPresentTypH_Cnt_M_lgc))
		{
			HaLFFuncPresentTypH_Cnt_M_lgc = (boolean)VC_LDW_Cnt_T_u08;
		}
		PrevHaLFPresent_Cnt_M_lgc = (uint16)VC_LDW_Cnt_T_u08;

		Rte_Write_Ap_SrlComInput_HaLFFuncPresent_Cnt_lgc(HaLFFuncPresentTypH_Cnt_M_lgc);
	}
	else
	{
		Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(VehCfg7MisMsgStartTime_mS_M_u32, &ElapsedTime_mS_T_u16);
		if (ElapsedTime_mS_T_u16 > k_VehCfg7MsgTimeOut_mS_u16p0)
		{
			 if (TRUE == NetCfg_CBCTypH_Cnt_M_lgc)
			 {
/*NTC1D9*/		Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_MissingMsg_VehCfg7, 0x01, NTC_STATUS_FAILED);
			 }
			 else
			 {
/*NTC1D9*/		Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_MissingMsg_VehCfg7, 0x01, NTC_STATUS_PASSED);
			 }
		}
	}

}

STATIC FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) ReadTRNSSPD(void)
{	/* TRNS_SPD  - 0x144 */

	VAR(tGear_Pkt, AUTOMATIC) tGear_PktTag_str;

	VAR(uint16, AUTOMATIC) Gear_Cnt_T_u16;
	VAR(uint16, AUTOMATIC) ElapsedTime_mS_T_u16;

	if (TRUE == Ind_Gear_Pkt)
	{
		Ind_Gear_Pkt = FALSE;

		Rte_Call_SystemTime_GetSystemTime_mS_u32(&TRNSSPDMisMsgStartTime_mS_M_u32);
		Rte_Call_NxtrDiagMgr_SetNTCStatus(0x1DF, 0x01, NTC_STATUS_PASSED);
		HaLFErrInterfaceActive_Cnt_M_bit &= ~D_ERRINTACTNTC1DF_CNT_U32;

		/* PRQA S 3138 1*/
		dbkGetRxSyncGear_Pkt(tGear_PktTag_str);
		Gear_Cnt_T_u16 = GetValueRxGr(tGear_PktTag_str);

		Gear_Cnt_M_u16 = Gear_Cnt_T_u16;

		if ((D_AUTOTRANS_CNT_U8 == TrnsmsnType_Cnt_M_u8) )
		{
			if (0x0BU == Gear_Cnt_M_u16)
			{
				Rte_Write_HalfTrqOvRvrsGearEngage_Cnt_lgc(TRUE);
			}
			else
			{
				Rte_Write_HalfTrqOvRvrsGearEngage_Cnt_lgc(FALSE);
			}
		}

		if((PrevHaLFPresent_Cnt_M_lgc == 0x01u) && (D_AUTOTRANS_CNT_U8 == TrnsmsnType_Cnt_M_u8))
		{
			if(0x0Fu == Gear_Cnt_T_u16)
			{
				Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(GrInvMsgStartTime_mS_M_u32, &ElapsedTime_mS_T_u16);
				if (ElapsedTime_mS_T_u16 > k_GrInvTimeOut_mS_u16p0)
				{
/*NTC1DE*/			Rte_Call_NxtrDiagMgr_SetNTCStatus(0x1DEu, 0x01, NTC_STATUS_FAILED);
					HaLFErrInterfaceActive_Cnt_M_bit |= D_ERRINTACTNTC1DE_CNT_U32;
				}
			}
			else
			{
				Rte_Call_SystemTime_GetSystemTime_mS_u32(&GrInvMsgStartTime_mS_M_u32);
				Rte_Call_NxtrDiagMgr_SetNTCStatus(0x1DEu, 0x01, NTC_STATUS_PASSED);
				HaLFErrInterfaceActive_Cnt_M_bit &= ~D_ERRINTACTNTC1DE_CNT_U32;
			}
		}
		else
		{
			Rte_Call_NxtrDiagMgr_SetNTCStatus(0x1DEu, 0x01, NTC_STATUS_PASSED);
		}
	}
	else
	{
		if((PrevHaLFPresent_Cnt_M_lgc == 0x01u) && (D_AUTOTRANS_CNT_U8 == TrnsmsnType_Cnt_M_u8))
		{
			Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(TRNSSPDMisMsgStartTime_mS_M_u32, &ElapsedTime_mS_T_u16);
			if (ElapsedTime_mS_T_u16 > k_TRNSSPMsgTimeOut_mS_u16p0)
			{
/*NTC1DF*/		Rte_Call_NxtrDiagMgr_SetNTCStatus(0x1DF, 0x01, NTC_STATUS_FAILED);
				HaLFErrInterfaceActive_Cnt_M_bit |= D_ERRINTACTNTC1DF_CNT_U32;
			}
		}
		else
		{
			Rte_Call_NxtrDiagMgr_SetNTCStatus(0x1DFu, 0x01, NTC_STATUS_PASSED);
			HaLFErrInterfaceActive_Cnt_M_bit &= ~D_ERRINTACTNTC1DF_CNT_U32;
		}
	}
}


STATIC FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) DiagNTC14E( VAR(float32, AUTOMATIC) BattVolt_Volt_T_f32 )
{
	VAR(uint16, AUTOMATIC) ElapsedTime_mS_T_u16;

	if( BattVolt_Volt_T_f32 < 10.0f)
	{
		Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(BattVoltLowStartTime_mS_M_u32, &ElapsedTime_mS_T_u16);
		if (ElapsedTime_mS_T_u16 > k_BattMsgVoltLowTimeOut_mS_u16p0)
		{
			Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DataOtherFltMsg_R, 0x01, NTC_STATUS_FAILED);
		}
		Rte_Call_SystemTime_GetSystemTime_mS_u32(&BattVoltLowRecTime_mS_M_u32);
	}
	else
	{
		if(BattVolt_Volt_T_f32 > 10.5f)
		{
			Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(BattVoltLowRecTime_mS_M_u32, &ElapsedTime_mS_T_u16);

			if(ElapsedTime_mS_T_u16 > k_BattMsgVoltLowTimeOut_mS_u16p0)
			{
				Rte_Call_SystemTime_GetSystemTime_mS_u32(&BattVoltLowStartTime_mS_M_u32);
				Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DataOtherFltMsg_R, 0x01, NTC_STATUS_PASSED);
			}
		}

	}

}
STATIC FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) DiagNTC14F( VAR(float32, AUTOMATIC) BattVolt_Volt_T_f32 )
{
	VAR(uint16, AUTOMATIC) ElapsedTime_mS_T_u16;

	if( BattVolt_Volt_T_f32 > 16.0f)
	{
		Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(BattVoltHighStartTime_mS_M_u32, &ElapsedTime_mS_T_u16);
		if (ElapsedTime_mS_T_u16 > k_BattMsgVoltHighTimeOut_mS_u16p0)
		{
			Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DataOtherFlt2Msg_R, 0x01, NTC_STATUS_FAILED);
		}
		Rte_Call_SystemTime_GetSystemTime_mS_u32(&BattVoltHighRecTime_mS_M_u32);
	}
	else
	{
		if(BattVolt_Volt_T_f32 < 15.5f)
		{
			Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(BattVoltHighRecTime_mS_M_u32, &ElapsedTime_mS_T_u16);

			if(ElapsedTime_mS_T_u16 > k_BattMsgVoltHighTimeOut_mS_u16p0)
			{
				Rte_Call_SystemTime_GetSystemTime_mS_u32(&BattVoltHighStartTime_mS_M_u32);
				Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DataOtherFlt2Msg_R, 0x01, NTC_STATUS_PASSED);
			}
		}

	}

}
STATIC FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) DiagNTC102(void)
{
	VAR(boolean, AUTOMATIC) CBCPT1Missing_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) CBCPT2Missing_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) CBCPT3Missing_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) NETCFGMissing_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) VehCfg1Missing_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) EcuCfg6Missing_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) VehCfg5Missing_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) VehCfg7Missing_Cnt_T_lgc;
	VAR(uint16, AUTOMATIC) ElapsedTime_mS_T_u16;

	Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_MissingMsg_AF, &CBCPT1Missing_Cnt_T_lgc);
	Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_MissingMsg_O, &CBCPT2Missing_Cnt_T_lgc);
	Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_MissingMsg_R, &CBCPT3Missing_Cnt_T_lgc);
	Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_MissingMsg_W, &NETCFGMissing_Cnt_T_lgc);
	Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_MissingMsg_X, &VehCfg1Missing_Cnt_T_lgc);
	Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_MissingMsg_V, &VehCfg5Missing_Cnt_T_lgc);
	Rte_Call_NxtrDiagMgr_GetNTCFailed(0x1D7, &EcuCfg6Missing_Cnt_T_lgc);
	Rte_Call_NxtrDiagMgr_GetNTCFailed(0x1D9, &VehCfg7Missing_Cnt_T_lgc);

	if((TRUE == CBCPT1Missing_Cnt_T_lgc) &&
			(TRUE == CBCPT2Missing_Cnt_T_lgc) &&
			(TRUE == CBCPT3Missing_Cnt_T_lgc) &&
			(TRUE == NETCFGMissing_Cnt_T_lgc) &&
			(TRUE == VehCfg1Missing_Cnt_T_lgc) &&
			(TRUE == VehCfg5Missing_Cnt_T_lgc) &&
			(TRUE == VehCfg7Missing_Cnt_T_lgc) &&
			(TRUE == EcuCfg6Missing_Cnt_T_lgc))
	{

		Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(CBCNodeAbsStartTime_mS_M_u32, &ElapsedTime_mS_T_u16);
		if(ElapsedTime_mS_T_u16 > k_CBCNodeAbsTime_mS_u16p0)
		{
			Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_Node1AAbsent, 0x01, NTC_STATUS_FAILED);
		}
	}
	else
	{
		Rte_Call_SystemTime_GetSystemTime_mS_u32(&CBCNodeAbsStartTime_mS_M_u32);
		Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_Node1AAbsent, 0x01, NTC_STATUS_PASSED);
	}
}

STATIC FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) DiagNTC104(void)
{
	VAR(boolean, AUTOMATIC) ECMA1Missing_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) VINMissing_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) EngCfgMissing_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) ECMA3Missing_Cnt_T_lgc;

	VAR(uint16, AUTOMATIC) ElapsedTime_mS_T_u16;

	Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_MissingMsg_N, &ECMA1Missing_Cnt_T_lgc);
	Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_MissingMsg_U, &VINMissing_Cnt_T_lgc);
	Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_MissingMsg_AC, &EngCfgMissing_Cnt_T_lgc);
	Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_MissingMsg_S, &ECMA3Missing_Cnt_T_lgc);



	if((TRUE == ECMA1Missing_Cnt_T_lgc) &&
			(TRUE == VINMissing_Cnt_T_lgc) &&
			(TRUE == ECMA3Missing_Cnt_T_lgc) &&
			(TRUE == EngCfgMissing_Cnt_T_lgc))
	{

		Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(DSLNodeAbsStartTime_mS_M_u32, &ElapsedTime_mS_T_u16);
		if(ElapsedTime_mS_T_u16 > k_DSLNodeAbsTime_mS_u16p0)
		{
			Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_Node1BAbsent, 0x01, NTC_STATUS_FAILED);
		}
	}
	else
	{
		Rte_Call_SystemTime_GetSystemTime_mS_u32(&DSLNodeAbsStartTime_mS_M_u32);
		Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_Node1BAbsent, 0x01, NTC_STATUS_PASSED);
	}
}

STATIC FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) DiagNTC124(void)
{
	VAR(uint16, AUTOMATIC) ElapsedTime_mS_T_u16;
	VAR(float32, AUTOMATIC) StrClmTrq_HwNm_T_f32;

	Rte_Read_StrClmTrq_HwNm_f32(&StrClmTrq_HwNm_T_f32);

	/* PRQA S 3415 1*/ /* Abs_f32_m is a macro, function side effects are not a risk */
	if((Abs_f32_m(VehAccel_Y_Cnt_M_f32) < 2.0f)&& (VehSpd_Kph_M_f32 > 50.0f) && (Abs_f32_m(StrClmTrq_HwNm_T_f32) < 2.0f) && (Abs_f32_m(StrgWhlAngl_M_f32)  > 180.0f))
	{
		Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(StrWhlAnglRatStartTime_mS_M_u32, &ElapsedTime_mS_T_u16);
		if(ElapsedTime_mS_T_u16 > k_StrWhlAnglRatTime_mS_u16p0)
		{	if(TRUE == VC_PPPA_PrsntTypH_Cnt_M_lgc)
			{
				PAErrInterfaceActive_Cnt_M_bit |= D_ERRINTACTNTC124_CNT_U32;
			}
			if(TRUE == HaLFFuncPresentTypH_Cnt_M_lgc)
			{
				HaLFErrInterfaceActive_Cnt_M_bit |= D_ERRINTACTNTC124_CNT_U32;
			}
			Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DataRngFltMsg_M, 0x01, NTC_STATUS_FAILED);

			DiagNTC124Set_Cnt_M_lgc = TRUE;
		}

	}
	else
	{
		Rte_Call_SystemTime_GetSystemTime_mS_u32(&StrWhlAnglRatStartTime_mS_M_u32);
		Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DataRngFltMsg_M, 0x01, NTC_STATUS_PASSED);
		PAErrInterfaceActive_Cnt_M_bit &= ~D_ERRINTACTNTC124_CNT_U32;
		HaLFErrInterfaceActive_Cnt_M_bit &= ~D_ERRINTACTNTC124_CNT_U32;
	}
}

STATIC FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) DiagNTC091(void)
{
	VAR(float32, AUTOMATIC) EstFric_HwNm_T_f32;
	VAR(boolean, AUTOMATIC) VehSpdMissing_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) VehSpdInvld_Cnt_T_lgc;

	Rte_Read_Ap_SrlComInput_EstFric_HwNm_f32(&EstFric_HwNm_T_f32);

	Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_MissingMsg_P, &VehSpdMissing_Cnt_T_lgc);
	Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_InvalidMsg_P, &VehSpdInvld_Cnt_T_lgc);

	if((EstFric_HwNm_T_f32 > k_EstFricLim_HwNm_T_f32) && (FALSE == VehSpdMissing_Cnt_T_lgc) && (FALSE == VehSpdInvld_Cnt_T_lgc))
	{
		Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_HighFriction, 0x01, NTC_STATUS_FAILED);
	}
	else
	{
		Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_HighFriction, 0x01, NTC_STATUS_PASSED);
	}
}

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_SetEnableTorqueOverlay(boolean Enable_Cnt_T_lgc)
{
	EnableTorqueOverlay_Cnt_M_lgc = Enable_Cnt_T_lgc;
}

FUNC(boolean, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_GetEnableTorqueOverlay(void)
{
	return EnableTorqueOverlay_Cnt_M_lgc;
}

STATIC FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) DiagNTC0EF( VAR(uint16, AUTOMATIC) DSTTorqueOverlayIntActivated_Cnt_T_lgc )
{
	VAR(boolean, AUTOMATIC) HandsOnDetect_Cnt_T_lgc;
	VAR(uint16, AUTOMATIC) ElapsedTime_mS_T_u16;

	Rte_Read_HandsOnDetect_Cnt_lgc(&HandsOnDetect_Cnt_T_lgc);

	if((TRUE == HandsOnDetect_Cnt_T_lgc) && (TRUE == DSTTorqueOverlayIntActivated_Cnt_T_lgc))
	{
		Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(HndsOnDrngPPAStartTime_mS_M_u32, &ElapsedTime_mS_T_u16);
		if(ElapsedTime_mS_T_u16 > k_HndsOnDrngPAA_mS_u16)
		{
			Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_VLF_15, 0x01, NTC_STATUS_FAILED);
		}
	}
	else
	{
		Rte_Call_SystemTime_GetSystemTime_mS_u32(&HndsOnDrngPPAStartTime_mS_M_u32);
		Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_VLF_15, 0x01, NTC_STATUS_PASSED);
	}
}
/****************************************************************
 * Description: Write a variable bit length value to a byte array.
 * 		The bit indicies are not required to be byte aligned.
 * Inputs:
 * 		Data_T_Cnt_u32 - The value to be written to the buffer.
 * 		Buffer_T_Cnt_u08 - The buffer being written to.
 * 		StartBit_Cnt_T_u16 - The index of the first bit to be written.
 * 		EndBit_Cnt_T_u16 - The index of the last bit to be written.
 ****************************************************************/
STATIC FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_WriteBits(uint32 Data_T_Cnt_u32, uint8* Buffer_T_Cnt_u08, uint16 StartBit_Cnt_T_u16, uint16 EndBit_Cnt_T_u16)
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
		ByteMask_Cnt_T_u08 = 0xFFU;
		BitsThisByte_Cnt_T_u08 = 8U;

		/* PRQA S 4394 1 */ /* Correct cast being done */
		BitsToShift_Cnt_T_s08 = (sint8)(NumBits_Cnt_T_u08 - (BitsWritten_Cnt_T_u08 + 8U));

		/* Shift right when BitsToShift is positive, otherwise shift left.*/
		if(BitsToShift_Cnt_T_s08 > 0)
		{
			/* PRQA S 4393 1 */ /* Cast being done in macro */
			TempData_Cnt_T_u08 = (uint8)(Data_T_Cnt_u32 >> Abs_s16_m((sint16)BitsToShift_Cnt_T_s08));
		}
		else
		{
			/* PRQA S 4393 1 */ /* Cast being done in macro */
			TempData_Cnt_T_u08 = (uint8)(Data_T_Cnt_u32 << Abs_s16_m((sint16)BitsToShift_Cnt_T_s08));
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
			/* PRQA S 4393 1 */ /* Correct cast being done */
			ByteMask_Cnt_T_u08 &= (uint8)(0xFF << (7U - (EndBit_Cnt_T_u16 % 8U)));
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

STATIC FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) VehSpdOverRide(void)
{
	if (ManualVehSpdOvrRide_Cnt_M_lgc == TRUE)
	{
		SuspendAllInterrupts();
		VehSpd_Kph_M_f32 = ManualVehSpd_Kph_M_f32;
		Rte_Write_SrlComVehSpd_Kph_f32(VehSpd_Kph_M_f32);
		Rte_Write_SrlComVehSpdValid_Cnt_lgc(TRUE);
		ResumeAllInterrupts();
	}
}

STATIC FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) ResetTimers(void)
{
	VAR(uint32,  AUTOMATIC) SystemTime_mS_T_u32;
	Rte_Call_SystemTime_GetSystemTime_mS_u32(&SystemTime_mS_T_u32);

	DSTActiveStartTime_mS_M_u32 = SystemTime_mS_T_u32;
	VehSpdVldStartTime_mS_M_u32 = SystemTime_mS_T_u32;
	VehSpdMisMsgStartTime_mS_M_u32 = SystemTime_mS_T_u32;
	IgnStatVldStartTime_mS_M_u32 = SystemTime_mS_T_u32;
	IgnStatMisMsgStartTime_mS_M_u32 = SystemTime_mS_T_u32;
	EngRPMVldStartTime_mS_M_u32 = SystemTime_mS_T_u32;
	EngRPMMisMsgStartTime_mS_M_u32 = SystemTime_mS_T_u32;
	SWAVldStartTime_mS_M_u32 = SystemTime_mS_T_u32;
	SWAMisMsgStartTime_mS_M_u32 = SystemTime_mS_T_u32;
	DSTTOCMisMsgStartTime_mS_M_u32 = SystemTime_mS_T_u32;
	NETCFGPTMisMsgStartTime_mS_M_u32 = SystemTime_mS_T_u32;
	HalfMisMsgStartTime_mS_M_u32 = SystemTime_mS_T_u32;
	PTSMisMsgStartTime_mS_M_u32 = SystemTime_mS_T_u32;
	HalfMaxTrqStartTime_mS_M_u32 = SystemTime_mS_T_u32;
	ESP4AMisMsgStartTime_mS_M_u32 = SystemTime_mS_T_u32;
	BattVoltInvMsgStartTime_mS_M_u32 = SystemTime_mS_T_u32;
	ECMA3MisMsgStartTime_mS_M_u32 = SystemTime_mS_T_u32;
	ESP4AInvMsgStartTime_mS_M_u32 = SystemTime_mS_T_u32;
	IC1AInvMsgStartTime_mS_M_u32 = SystemTime_mS_T_u32;
	IC1AMisMsgStartTime_mS_M_u32 = SystemTime_mS_T_u32;
	BattVoltMisMsgStartTime_mS_M_u32 = SystemTime_mS_T_u32;
	VehCfg1InvMsgStartTime_mS_M_u32 = SystemTime_mS_T_u32;
	VehCfg1MisMsgStartTime_mS_M_u32 = SystemTime_mS_T_u32;
	VINInvMsgStartTime_mS_M_u32 = SystemTime_mS_T_u32;
	VINMisMsgStartTime_mS_M_u32 = SystemTime_mS_T_u32;
	CBCNodeAbsStartTime_mS_M_u32 = SystemTime_mS_T_u32;
	BattVoltHighRecTime_mS_M_u32 = SystemTime_mS_T_u32;
	BattVoltHighStartTime_mS_M_u32 = SystemTime_mS_T_u32;
	BattVoltLowRecTime_mS_M_u32 = SystemTime_mS_T_u32;
	BattVoltLowStartTime_mS_M_u32 = SystemTime_mS_T_u32;
	DSLNodeAbsStartTime_mS_M_u32 = SystemTime_mS_T_u32;
	StrWhlAnglRatStartTime_mS_M_u32 = SystemTime_mS_T_u32;
	WHEELSPEED2MisMsgStartTime_mS_M_u32 = SystemTime_mS_T_u32;
	WHEELSPEED2InvMsgStartTime_mS_M_u32 = SystemTime_mS_T_u32;
	EngCfgMisMsgStartTime_mS_M_u32 = SystemTime_mS_T_u32;
	EngOilTempMisMsgStartTime_mS_M_u32 = SystemTime_mS_T_u32;
	TRNSSTATMisMsgStartTime_mS_M_u32 = SystemTime_mS_T_u32;
	TRNSSTATInvMsgStartTime_mS_M_u32 = SystemTime_mS_T_u32;
	RevGearTempMisMsgStartTime_mS_M_u32 = SystemTime_mS_T_u32;
	VehCfg5MisMsgStartTime_mS_M_u32 = SystemTime_mS_T_u32;
	ECMA3InvMsgStartTime_mS_M_u32 = SystemTime_mS_T_u32;
	ESPA5MisMsgStartTime_mS_M_u32 = SystemTime_mS_T_u32;
	ESPA5VldStartTime_mS_M_u32 = SystemTime_mS_T_u32;
	ESPA6MisMsgStartTime_mS_M_u32 = SystemTime_mS_T_u32;
	ESPA6VldStartTime_mS_M_u32 = SystemTime_mS_T_u32;
	TireCircRcvdStartTime_mS_M_u32 = SystemTime_mS_T_u32;
}


STATIC FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) ClearHALFNTC_MessageNotRcvd(void)
{
	/*192*/ Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_CRCFltMsg_AA, 0x01, NTC_STATUS_PASSED);
	/*193*/Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_PgrsCntFltMsg_AA, 0x01, NTC_STATUS_PASSED);
	ClearHALFNTC_RcvdMesgNotValid();
}

STATIC FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) ClearHALFNTC_RcvdMesgNotValid(void)
{
	Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_AA, 0x01, NTC_STATUS_PASSED);
	Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DataRngFltMsg_AA, 0x01, NTC_STATUS_PASSED);/*NTC194*/
	Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DataRateFltMsg_AA, 0x01, NTC_STATUS_PASSED);/*NTC195*/
	Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DataOtherFltMsg_AA, 0x01, NTC_STATUS_PASSED);/*NTC196*/
	Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_VLF_09, 0x01, NTC_STATUS_PASSED); /*NTCe9*/
	Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_VLF_14, 0x01, NTC_STATUS_PASSED); /*NTCee*/
	Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DataOtherFltMsg_AG, 0x01, NTC_STATUS_PASSED);
}

STATIC FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) ClearPTSNTC_MessageNotRcvd(void)
{
	Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_CRCFltMsg_AB, 0x01, NTC_STATUS_PASSED);/*NTC19A*/
	Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_PgrsCntFltMsg_AB, 0x01, NTC_STATUS_PASSED);/*NTC19B*/

	ClearPTSNTC_RcvdMesgNotValid();
}
STATIC FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) ClearPTSNTC_RcvdMesgNotValid(void)
{
	Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_VLF_15, 0x01, NTC_STATUS_PASSED);/*NTCEF*/
	Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DataOtherFltMsg_AE, 0x01, NTC_STATUS_PASSED);/*NTC1B6*/
	Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DataRngFltMsg_AB, 0x01, NTC_STATUS_PASSED); /*NTC19C*/
	Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DataRateFltMsg_AB, 0x01, NTC_STATUS_PASSED);/*NTC19D*/
}

STATIC FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) ClearDSTTOCNTC_MessageNotRcvd(void)
{
	Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_CRCFltMsg_Z, 0x01, NTC_STATUS_PASSED);/*NTC18A*/
	Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_PgrsCntFltMsg_Z, 0x01, NTC_STATUS_PASSED);/*NTC18B*/


	ClearDSTTOCNTC_RcvdMesgNotValid();
}

STATIC FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) ClearDSTTOCNTC_RcvdMesgNotValid(void)
{
	Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_AG, 0x01, NTC_STATUS_PASSED);/*NTC1C0*/
	Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DataOtherFltMsg_Z, 0x01, NTC_STATUS_PASSED);/*NTC18E*/
	Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_Z, 0x01, NTC_STATUS_PASSED);/*NTC188*/
	Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_VLF_10, 0x01, NTC_STATUS_PASSED); /*NTCEA*/
	Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_VLF_12, 0x01, NTC_STATUS_PASSED);/*NTCEC*/
	Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_VLF_11, 0x01, NTC_STATUS_PASSED);/*NTCEB*/
	Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DataRateFltMsg_Z, 0x01, NTC_STATUS_PASSED);/*NTC18D*/
	Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DataRngFltMsg_Z, 0x01, NTC_STATUS_PASSED);/*NTC18C*/
	Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DSTXORActive, 0x01, NTC_STATUS_PASSED);/*NTC18F*/

}







/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput_SCom_ManualVehSpd
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <SCom_ManualVehSpd> of PortPrototype <SCom_ManualVehSpd>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void SrlComInput_SCom_ManualVehSpd(Float VehSpd_Kph_f32)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_SCom_ManualVehSpd(Float VehSpd_Kph_f32)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SrlComInput_SCom_ManualVehSpd
 *********************************************************************************************************************/

	ManualVehSpd_Kph_M_f32 = VehSpd_Kph_f32;
	ManualVehSpdOvrRide_Cnt_M_lgc = TRUE;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
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
