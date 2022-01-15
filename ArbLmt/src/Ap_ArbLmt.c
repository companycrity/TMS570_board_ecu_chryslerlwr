/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Ap_ArbLmt.c
 *     Workspace:  C:/Synergy_projects/ArbLmt-lz4p8n1/ArbLmt/autosar
 *     SW-C Type:  Ap_ArbLmt
 *  Generated at:  Wed Jul 10 16:37:47 2013
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nexteer  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  C-Code implementation template for SW-C <Ap_ArbLmt>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/* Version Control:
 * Date Created:      Mon Oct 29 11:49:42 2012
 * %version:          6 %
 * %derived_by:       sz1dx6 %
 * %date_modified:    Wed Jul 10 16:21:31 2013 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author    Change Description                                                           SCR #
 * --------  -------  --------  ---------------------------------------------------------------------------  ----------
 * 10/29/12  1        OT        Initial Version (CF-05 v001)                                                 6605
 * 03/22/13  2        M. Story  Anomaly 4668                                                                 7708
 * 05/14/13  3        Jared     Updated to FDD ver 003                                                       8167
 * 05/30/13  4        Jared     UTP Syntactical corrections
 * 07/10/13  5        SP		Updated to CF v004															 8848
 * 3/14/14   6        M. Story  Anomaly 6467																11596
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "Rte_Ap_ArbLmt.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "fixmath.h"
#include "interpolation.h"
#include "Ap_ArbLmt_Cfg.h"
#include "GlobalMacro.h"
#include "CalConstants.h"
#include <float.h>


#define D_4MS_S_F32             0.004f
#define D_PPPAFUNCBIT_CNT_U08   0x01U
#define D_DSTFUNCBIT_CNT_U08    0x02U
#define D_HALFFUNCBIT_CNT_U08   0x04U
#define D_PPPALOLMT_MTRNM_F32   (-0.1f)
#define D_PPPAHILMT_MTRNM_F32   8.8f


#define ARBLMT_START_SEC_VAR_CLEARED_32
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(float32, AP_ARBLMT_VAR) DSTScalarSlew_Uls_M_f32;
STATIC VAR(float32, AP_ARBLMT_VAR) HaLFScalarSlew_Uls_M_f32;
STATIC VAR(float32, AP_ARBLMT_VAR) DSTSlew_HwNm_M_f32;
STATIC VAR(float32, AP_ARBLMT_VAR) HaLFSlew_MtrNm_M_f32;
STATIC VAR(float32, AP_ARBLMT_VAR) PPPASlew_HwNm_M_f32;
#define ARBLMT_STOP_SEC_VAR_CLEARED_32
#include "MemMap.h" /* PRQA S 5087 */

#define ARBLMT_START_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(boolean, AP_ARBLMT_VAR) DSTLowSpdPri_Cnt_M_lgc;
STATIC VAR(boolean, AP_ARBLMT_VAR) PrevDSTActive_Cnt_M_lgc;
STATIC VAR(boolean, AP_ARBLMT_VAR) PrevDSTRampActive_Cnt_M_lgc;
STATIC VAR(boolean, AP_ARBLMT_VAR) PrevHaLFRampActive_Cnt_M_lgc;
STATIC VAR(boolean, AP_ARBLMT_VAR) SlewActive_Cnt_M_lgc;
STATIC VAR(boolean, AP_ARBLMT_VAR) PrevDSTSlewState_Cnt_M_lgc;
STATIC VAR(boolean, AP_ARBLMT_VAR) PrevHaLFSlewState_Cnt_M_lgc;
STATIC VAR(boolean, AP_ARBLMT_VAR) PrevPPPASlewState_Cnt_M_lgc;
#define ARBLMT_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h" /* PRQA S 5087 */


STATIC FUNC(void, AP_ARBLMT_CODE) ArbiterSlewLimit(
        VAR(float32, AUTOMATIC) TrqOvCmdRqst_HwNm_T_f32,
        VAR(boolean, AUTOMATIC) SlewState_Cnt_T_lgc,
        VAR(float32, AUTOMATIC) SlewRate_NmpS_T_f32,
        P2VAR(float32, AUTOMATIC, AUTOMATIC) TrqOvCmdOut_HwNm_T_f32,
        P2VAR(boolean, AUTOMATIC, AUTOMATIC) SlewComplete_Cnt_T_lgc,
        P2VAR(boolean, AUTOMATIC, AUTOMATIC) CmdActive_Cnt_T_lgc,
        P2VAR(float32, AUTOMATIC, AUTOMATIC) Slew_Uls_T_f32,
        P2VAR(boolean, AUTOMATIC, AUTOMATIC) PrevSlewState_Cnt_T_lgc);

STATIC FUNC(void, AP_ARBLMT_CODE) ArbiterPriority(
        VAR(float32, AUTOMATIC) VehSpd_Kph_T_f32,
        VAR(boolean, AUTOMATIC) DSTCmdActive_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) PPPACmdActive_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) HaLFCmdActive_Cnt_T_lgc,
        P2VAR(boolean, AUTOMATIC, AUTOMATIC) HaLFPriActive_Cnt_T_lgc,
        P2VAR(boolean, AUTOMATIC, AUTOMATIC) PPPAPriActive_Cnt_T_lgc,
        P2VAR(boolean, AUTOMATIC, AUTOMATIC) DSTPriActive_Cnt_T_lgc);

STATIC FUNC(void, AP_ARBLMT_CODE) ArbiterRamping(
        VAR(boolean, AUTOMATIC) DSTEnable_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) DSTSlewComplete_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) HaLFEnable_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) HaLFSlewComplete_Cnt_T_lgc,
        P2VAR(float32, AUTOMATIC, AUTOMATIC) DSTScalar_Uls_T_f32,
        P2VAR(float32, AUTOMATIC, AUTOMATIC) HaLFScalar_Uls_T_f32);


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
 * SInt16: Integer in interval [-32768...32767] (standard type)
 * SInt32: Integer in interval [-2147483648...2147483647] (standard type)
 * SInt8: Integer in interval [-128...127] (standard type)
 * UInt16: Integer in interval [0...65535] (standard type)
 * UInt32: Integer in interval [0...4294967295] (standard type)
 * UInt8: Integer in interval [0...255] (standard type)
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
 * Float: D_ONE_ULS_F32 = 1
 * Float: D_PIOVR180_ULS_F32 = 0.0174532925199
 * Float: D_PI_ULS_F32 = 3.1415926535898
 * Float: D_ZERO_ULS_F32 = 0
 * SInt16: D_NEGONE_CNT_S16 = -1
 * SInt16: D_ONE_CNT_S16 = 1
 * SInt16: D_ZERO_CNT_S16 = 0
 * SInt32: D_NEGONE_CNT_S32 = -1
 * SInt32: D_ONE_CNT_S32 = 1
 * SInt32: D_ZERO_CNT_S32 = 0
 * SInt8: D_NEGONE_CNT_S8 = -1
 * SInt8: D_ONE_CNT_S8 = 1
 * SInt8: D_ZERO_CNT_S8 = 0
 * UInt16: D_ONE_CNT_U16 = 1u
 * UInt16: D_ZERO_CNT_U16 = 0u
 * UInt32: D_ONE_CNT_U32 = 1u
 * UInt32: D_ZERO_CNT_U32 = 0u
 * UInt8: D_ONE_CNT_U8 = 1u
 * UInt8: D_ZERO_CNT_U8 = 0u
 *
 *********************************************************************************************************************/


#define RTE_START_SEC_AP_ARBLMT_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: ArbLmt_Per1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 4ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Implicit S/R API:
 *   -----------------
 *   Boolean Rte_IRead_ArbLmt_Per1_DSTActive_Cnt_lgc(void)
 *   UInt8 Rte_IRead_ArbLmt_Per1_DSTState_Cnt_u08(void)
 *   Float Rte_IRead_ArbLmt_Per1_DSTTrqOvCmdRqst_HwNm_f32(void)
 *   Boolean Rte_IRead_ArbLmt_Per1_HaLFActive_Cnt_lgc(void)
 *   UInt8 Rte_IRead_ArbLmt_Per1_HaLFTOState_Cnt_u08(void)
 *   Float Rte_IRead_ArbLmt_Per1_HaLFTrqOvCmdRqst_MtrNm_f32(void)
 *   Float Rte_IRead_ArbLmt_Per1_PATrqOvCmdRqst_HwNm_f32(void)
 *   UInt8 Rte_IRead_ArbLmt_Per1_PrkAssistState_Cnt_u08(void)
 *   Float Rte_IRead_ArbLmt_Per1_VehicleSpeed_Kph_f32(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_ArbLmt_Per1_ActiveFunctionBits_Cnt_u08(UInt8 data)
 *   UInt8 *Rte_IWriteRef_ArbLmt_Per1_ActiveFunctionBits_Cnt_u08(void)
 *   void Rte_IWrite_ArbLmt_Per1_DSTSlewComplete_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_ArbLmt_Per1_DSTSlewComplete_Cnt_lgc(void)
 *   void Rte_IWrite_ArbLmt_Per1_HaLFSlewComplete_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_ArbLmt_Per1_HaLFSlewComplete_Cnt_lgc(void)
 *   void Rte_IWrite_ArbLmt_Per1_IpTrqOvr_HwNm_f32(Float data)
 *   Float *Rte_IWriteRef_ArbLmt_Per1_IpTrqOvr_HwNm_f32(void)
 *   void Rte_IWrite_ArbLmt_Per1_OpTrqOvr_MtrNm_f32(Float data)
 *   Float *Rte_IWriteRef_ArbLmt_Per1_OpTrqOvr_MtrNm_f32(void)
 *   void Rte_IWrite_ArbLmt_Per1_PAReturnSclFct_Uls_f32(Float data)
 *   Float *Rte_IWriteRef_ArbLmt_Per1_PAReturnSclFct_Uls_f32(void)
 *   void Rte_IWrite_ArbLmt_Per1_PICmpDisableLearning_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_ArbLmt_Per1_PICmpDisableLearning_Cnt_lgc(void)
 *   void Rte_IWrite_ArbLmt_Per1_PrkAsstSlewComplete_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_ArbLmt_Per1_PrkAsstSlewComplete_Cnt_lgc(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_ARBLMT_APPL_CODE) ArbLmt_Per1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: ArbLmt_Per1
 *********************************************************************************************************************/

    /* Inputs */
    VAR(boolean, AUTOMATIC) DSTActive_Cnt_T_lgc;
    VAR(boolean, AUTOMATIC) HaLFActive_Cnt_T_lgc;
    VAR(uint8, AUTOMATIC) DSTState_Cnt_T_u08;
    VAR(float32, AUTOMATIC) DSTTrqOvCmdRqst_HwNm_T_f32;
    VAR(float32, AUTOMATIC) HaLFTrqOvCmdRqst_MtrNm_T_f32;
    VAR(uint8, AUTOMATIC) HaLFTOState_Cnt_T_u08;
    VAR(float32, AUTOMATIC) PATrqOvCmdRqst_HwNm_T_f32;
    VAR(boolean, AUTOMATIC) PrkAssistState_Cnt_T_u08;
    VAR(float32, AUTOMATIC) VehicleSpeed_Kph_T_f32;

    /* DST Slew Rate */
    VAR(boolean, AUTOMATIC) DSTSlewState_Cnt_T_lgc;
    VAR(float32, AUTOMATIC) DSTTrqOvCmdOut_HwNm_T_f32;
    VAR(boolean, AUTOMATIC) DSTSlewComplete_Cnt_T_lgc;
    VAR(boolean, AUTOMATIC) DSTCmdActive_Cnt_T_lgc;

    /* HaLF Slew Rate */
    VAR(boolean, AUTOMATIC) HaLFSlewState_Cnt_T_lgc;
    VAR(float32, AUTOMATIC) HaLFTrqOvCmdOut_HwNm_T_f32;
    VAR(boolean, AUTOMATIC) HaLFSlewComplete_Cnt_T_lgc;
    VAR(boolean, AUTOMATIC) HaLFCmdActive_Cnt_T_lgc;

    /* PPPA Slew Rate */
    VAR(boolean, AUTOMATIC) PPPASlewState_Cnt_T_lgc;
    VAR(float32, AUTOMATIC) PPPATrqOvCmdOut_HwNm_T_f32;
    VAR(boolean, AUTOMATIC) PPPASlewComplete_Cnt_T_lgc;
    VAR(boolean, AUTOMATIC) PPPACmdActive_Cnt_T_lgc;

    /* Priority */
    VAR(boolean, AUTOMATIC) HaLFPriActive_Cnt_T_lgc;
    VAR(boolean, AUTOMATIC) PPPAPriActive_Cnt_T_lgc;
    VAR(boolean, AUTOMATIC) DSTPriActive_Cnt_T_lgc;

    /* Ramping */
    VAR(float32, AUTOMATIC) DSTScalar_Uls_T_f32;
    VAR(float32, AUTOMATIC) HaLFScalar_Uls_T_f32;

    /* Arbiter */
    VAR(sint16, AUTOMATIC) VehicleSpeed_Kph_T_s8p7;
    VAR(uint16, AUTOMATIC) PPPATrqOvCmdOut_HwNm_T_u8p8;
    VAR(sint16, AUTOMATIC) PPPAMtrNm_MtrNm_T_s4p11;
    VAR(float32, AUTOMATIC) PPPAMtrNm_MtrNm_T_f32;
	VAR(boolean, AUTOMATIC) PICmpDisableLearning_Cnt_T_lgc;

    /* Outputs */
    VAR(uint8,   AUTOMATIC) ActiveFunctionBits_Cnt_T_u08;
    VAR(float32, AUTOMATIC) IpTrqOvr_HwNm_T_f32;
    VAR(float32, AUTOMATIC) OpTrqOvr_MtrNm_T_f32;
    VAR(float32, AUTOMATIC) PAReturnSclFct_Uls_T_f32;


    /* Configurable Start of Runnable Checkpoint */
    Rte_Call_ArbLmt_Per1_CP0_CheckpointReached();

    /* Store Module Inputs to Local Copies */
    DSTActive_Cnt_T_lgc = Rte_IRead_ArbLmt_Per1_DSTActive_Cnt_lgc();
    HaLFActive_Cnt_T_lgc = Rte_IRead_ArbLmt_Per1_HaLFActive_Cnt_lgc();
    DSTState_Cnt_T_u08 = Rte_IRead_ArbLmt_Per1_DSTState_Cnt_u08();
    DSTTrqOvCmdRqst_HwNm_T_f32 = Rte_IRead_ArbLmt_Per1_DSTTrqOvCmdRqst_HwNm_f32();
    HaLFTrqOvCmdRqst_MtrNm_T_f32 = Rte_IRead_ArbLmt_Per1_HaLFTrqOvCmdRqst_MtrNm_f32();
    HaLFTOState_Cnt_T_u08 = Rte_IRead_ArbLmt_Per1_HaLFTOState_Cnt_u08();
    PATrqOvCmdRqst_HwNm_T_f32 = Rte_IRead_ArbLmt_Per1_PATrqOvCmdRqst_HwNm_f32();
    PrkAssistState_Cnt_T_u08 = Rte_IRead_ArbLmt_Per1_PrkAssistState_Cnt_u08();
    VehicleSpeed_Kph_T_f32 = Rte_IRead_ArbLmt_Per1_VehicleSpeed_Kph_f32();


    /*** DST Slew ***/
    if ( (DSTState_Cnt_T_u08 == 0x03U) ||
         (DSTState_Cnt_T_u08 == 0x05U) ||
         (DSTState_Cnt_T_u08 == 0x06U) ||
         (DSTState_Cnt_T_u08 == 0x07U) )
    {
        DSTSlewState_Cnt_T_lgc = TRUE;
    }
    else
    {
        DSTSlewState_Cnt_T_lgc = FALSE;
    }

    (void) ArbiterSlewLimit(
            DSTTrqOvCmdRqst_HwNm_T_f32,
            DSTSlewState_Cnt_T_lgc,
            k_DSTSlewRate_NmpS_f32,
            &DSTTrqOvCmdOut_HwNm_T_f32,
            &DSTSlewComplete_Cnt_T_lgc,
            &DSTCmdActive_Cnt_T_lgc,
            &DSTSlew_HwNm_M_f32,
            &PrevDSTSlewState_Cnt_M_lgc);

    /*** HaLF Slew ***/
    if (HaLFTOState_Cnt_T_u08 != 0x01U)
    {
        HaLFTrqOvCmdRqst_MtrNm_T_f32 = 0; 
    }


    if ((HaLFTOState_Cnt_T_u08 == 0x01U) ||
    		((HaLFTOState_Cnt_T_u08 != 0x01U) && (Abs_f32_m(HaLFSlew_MtrNm_M_f32) > FLT_EPSILON)))
    {
        HaLFSlewState_Cnt_T_lgc = TRUE;
    }
    else
    {
        HaLFSlewState_Cnt_T_lgc = FALSE;
    }

    (void) ArbiterSlewLimit(
            HaLFTrqOvCmdRqst_MtrNm_T_f32,
            HaLFSlewState_Cnt_T_lgc,
            k_HaLFSlewRate_NmpS_f32,
            &HaLFTrqOvCmdOut_HwNm_T_f32,
            &HaLFSlewComplete_Cnt_T_lgc,
            &HaLFCmdActive_Cnt_T_lgc,
            &HaLFSlew_MtrNm_M_f32,
            &PrevHaLFSlewState_Cnt_M_lgc);

    /*** PPPA Slew ***/
    if (PrkAssistState_Cnt_T_u08 == 0x01U)
    {
        PPPASlewState_Cnt_T_lgc = TRUE;
    }
    else
    {
        PPPASlewState_Cnt_T_lgc = FALSE;
    }

    (void) ArbiterSlewLimit(
            PATrqOvCmdRqst_HwNm_T_f32,
            PPPASlewState_Cnt_T_lgc,
            k_PPPASlewRate_NmpS_f32,
            &PPPATrqOvCmdOut_HwNm_T_f32,
            &PPPASlewComplete_Cnt_T_lgc,
            &PPPACmdActive_Cnt_T_lgc,
            &PPPASlew_HwNm_M_f32,
            &PrevPPPASlewState_Cnt_M_lgc);

    /*** Priority ***/
    (void) ArbiterPriority(
            VehicleSpeed_Kph_T_f32,
            DSTCmdActive_Cnt_T_lgc,
            PPPACmdActive_Cnt_T_lgc,
            HaLFCmdActive_Cnt_T_lgc,
            &HaLFPriActive_Cnt_T_lgc,
            &PPPAPriActive_Cnt_T_lgc,
            &DSTPriActive_Cnt_T_lgc);

    /*** Ramping ***/
    (void) ArbiterRamping(
            DSTActive_Cnt_T_lgc,
            DSTSlewComplete_Cnt_T_lgc,
            HaLFSlewState_Cnt_T_lgc,
            HaLFSlewComplete_Cnt_T_lgc,
            &DSTScalar_Uls_T_f32,
            &HaLFScalar_Uls_T_f32);

    /*** Arbiter ***/
    ActiveFunctionBits_Cnt_T_u08 = D_ZERO_CNT_U8;

    VehicleSpeed_Kph_T_s8p7 = FPM_FloatToFixed_m(VehicleSpeed_Kph_T_f32, s8p7_T);
    PPPATrqOvCmdOut_HwNm_T_u8p8 = FPM_FloatToFixed_m(Abs_f32_m(PPPATrqOvCmdOut_HwNm_T_f32), u8p8_T);
    PPPAMtrNm_MtrNm_T_s4p11 = BilinearXMYM_s16_u16XMs16YM_Cnt(
                                    VehicleSpeed_Kph_T_s8p7,
                                    PPPATrqOvCmdOut_HwNm_T_u8p8,
                                    t_PPPAVehSpd_Kph_u9p7,
                                    TableSize_m(t_PPPAVehSpd_Kph_u9p7),
                                    t2_HwtX0_HwNm_u8p8[0],
                                    t2_AsstY0_MtrNm_s4p11[0],
                                    TableSize_m(t2_HwtX0_HwNm_u8p8[0]));
    PPPAMtrNm_MtrNm_T_f32 = FPM_FixedToFloat_m(PPPAMtrNm_MtrNm_T_s4p11, s4p11_T);
    PPPAMtrNm_MtrNm_T_f32 = Limit_m(PPPAMtrNm_MtrNm_T_f32, D_PPPALOLMT_MTRNM_F32, D_PPPAHILMT_MTRNM_F32);
    PPPAMtrNm_MtrNm_T_f32 = PPPAMtrNm_MtrNm_T_f32 * (float32)Sign_f32_m(PPPATrqOvCmdOut_HwNm_T_f32);


    if (DSTPriActive_Cnt_T_lgc == TRUE)
    {
        ActiveFunctionBits_Cnt_T_u08 |= D_DSTFUNCBIT_CNT_U08;
        IpTrqOvr_HwNm_T_f32 = DSTTrqOvCmdOut_HwNm_T_f32 * DSTScalar_Uls_T_f32;
    }
    else
    {
        IpTrqOvr_HwNm_T_f32 = D_ZERO_ULS_F32;
    }


    if (PPPAPriActive_Cnt_T_lgc == TRUE)
    {
        ActiveFunctionBits_Cnt_T_u08 |= D_PPPAFUNCBIT_CNT_U08;
        PAReturnSclFct_Uls_T_f32 = D_ZERO_ULS_F32;
        OpTrqOvr_MtrNm_T_f32 = PPPAMtrNm_MtrNm_T_f32;
    }
    else
    {
        PAReturnSclFct_Uls_T_f32 = D_ONE_ULS_F32;

        if (HaLFPriActive_Cnt_T_lgc == TRUE)
        {
            OpTrqOvr_MtrNm_T_f32 = HaLFTrqOvCmdOut_HwNm_T_f32 * HaLFScalar_Uls_T_f32;
        }
        else
        {
            OpTrqOvr_MtrNm_T_f32 = D_ZERO_ULS_F32;
        }
    }

	if (Abs_f32_m(HaLFTrqOvCmdOut_HwNm_T_f32 * HaLFScalar_Uls_T_f32) >= k_HalFPICmpThresh_MtrNm_f32)
	{
		PICmpDisableLearning_Cnt_T_lgc = HaLFPriActive_Cnt_T_lgc;
	}
	else
	{
		PICmpDisableLearning_Cnt_T_lgc = FALSE;
	}
	
    if (HaLFPriActive_Cnt_T_lgc == TRUE)
    {
        ActiveFunctionBits_Cnt_T_u08 |= D_HALFFUNCBIT_CNT_U08;
    }

    Rte_IWrite_ArbLmt_Per1_ActiveFunctionBits_Cnt_u08(ActiveFunctionBits_Cnt_T_u08);
    Rte_IWrite_ArbLmt_Per1_DSTSlewComplete_Cnt_lgc(DSTSlewComplete_Cnt_T_lgc);
    Rte_IWrite_ArbLmt_Per1_HaLFSlewComplete_Cnt_lgc(HaLFSlewComplete_Cnt_T_lgc);
    Rte_IWrite_ArbLmt_Per1_IpTrqOvr_HwNm_f32(IpTrqOvr_HwNm_T_f32);
    Rte_IWrite_ArbLmt_Per1_OpTrqOvr_MtrNm_f32(OpTrqOvr_MtrNm_T_f32);
    Rte_IWrite_ArbLmt_Per1_PAReturnSclFct_Uls_f32(PAReturnSclFct_Uls_T_f32);
    Rte_IWrite_ArbLmt_Per1_PrkAsstSlewComplete_Cnt_lgc(PPPASlewComplete_Cnt_T_lgc);
	Rte_IWrite_ArbLmt_Per1_PICmpDisableLearning_Cnt_lgc(PICmpDisableLearning_Cnt_T_lgc);

    /* Configurable End of Runnable Checkpoint */
    Rte_Call_ArbLmt_Per1_CP1_CheckpointReached();

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define RTE_STOP_SEC_AP_ARBLMT_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/***********************************************************************************************************************
 *  Name:   ArbiterSlewLimit
 *
 *  Inputs                              | Type      | Min       | Max
 *  ----------------------------------- | --------- | --------- | ---------
 *  TrqOvCmdRqst_HwNm_T_f32             | float32   | -10       | 10
 *  SlewState_Cnt_T_lgc                 | boolean   | FALSE     | TRUE
 *  SlewRate_NmpS_T_f32                 | *float32  | 0         | 2
 *  TrqOvCmdOut_HwNm_T_f32              | *float32  | -10       | 10
 *  SlewComplete_Cnt_T_lgc              | *boolean  | FALSE     | TRUE
 *  CmdActive_Cnt_T_lgc                 | *boolean  | FALSE     | TRUE
 *  Slew_Uls_T_f32                      | *float32  | -10       | 10
 *  PrevSlewState_Cnt_T_lgc             | *boolean  | FALSE     | TRUE
 *
 *  Output                              | Type      | Min       | Max
 *  ----------------------------------- | --------- | --------- | ---------
 *  None                                |           |           |
 *
 **********************************************************************************************************************/
STATIC FUNC(void, AP_ARBLMT_CODE) ArbiterSlewLimit(
        VAR(float32, AUTOMATIC) TrqOvCmdRqst_HwNm_T_f32,
        VAR(boolean, AUTOMATIC) SlewState_Cnt_T_lgc,
        VAR(float32, AUTOMATIC) SlewRate_NmpS_T_f32,
        P2VAR(float32, AUTOMATIC, AUTOMATIC) TrqOvCmdOut_HwNm_T_f32,
        P2VAR(boolean, AUTOMATIC, AUTOMATIC) SlewComplete_Cnt_T_lgc,
        P2VAR(boolean, AUTOMATIC, AUTOMATIC) CmdActive_Cnt_T_lgc,
        P2VAR(float32, AUTOMATIC, AUTOMATIC) Slew_Uls_T_f32,
        P2VAR(boolean, AUTOMATIC, AUTOMATIC) PrevSlewState_Cnt_T_lgc)
{
    VAR(float32, AUTOMATIC) SlewRateInput_HwNm_T_f32;

    SlewRateInput_HwNm_T_f32 = TrqOvCmdRqst_HwNm_T_f32;


    *Slew_Uls_T_f32 = Limit_m(SlewRateInput_HwNm_T_f32,
                              *Slew_Uls_T_f32 - (SlewRate_NmpS_T_f32 * D_4MS_S_F32),
                              *Slew_Uls_T_f32 + (SlewRate_NmpS_T_f32 * D_4MS_S_F32));

    if ( SlewState_Cnt_T_lgc == TRUE )
    {
        *TrqOvCmdOut_HwNm_T_f32 = *Slew_Uls_T_f32;
        *CmdActive_Cnt_T_lgc = TRUE;

        /* Same as: SlewRateInput_HwNm_T_f32 != *Slew_Uls_T_f32 */
        if ((Abs_f32_m(SlewRateInput_HwNm_T_f32 - *Slew_Uls_T_f32) > FLT_EPSILON) && (SlewActive_Cnt_M_lgc == FALSE))
        {
        	SlewActive_Cnt_M_lgc = TRUE;
        }
        else
        {
        	if ((Abs_f32_m(SlewRateInput_HwNm_T_f32 - *Slew_Uls_T_f32) <= FLT_EPSILON) && (SlewActive_Cnt_M_lgc == TRUE))
        	{
        		SlewActive_Cnt_M_lgc = FALSE;
        	}
		}
    }
    else
    {
        *TrqOvCmdOut_HwNm_T_f32 = SlewRateInput_HwNm_T_f32;
        SlewActive_Cnt_M_lgc = FALSE;
        *CmdActive_Cnt_T_lgc = FALSE;
    }

    if(SlewActive_Cnt_M_lgc == TRUE)
    {
        *SlewComplete_Cnt_T_lgc = FALSE;
    }
    else
    {
        *SlewComplete_Cnt_T_lgc = TRUE;
    }

    *PrevSlewState_Cnt_T_lgc = SlewState_Cnt_T_lgc;
}


/***********************************************************************************************************************
 *  Name:   ArbiterPriority
 *
 *  Inputs                              | Type      | Min       | Max
 *  ----------------------------------- | --------- | --------- | ---------
 *  VehSpd_Kph_T_f32                    | float32   | 0         | 511
 *  DSTCmdActive_Cnt_T_lgc              | boolean   | 0         | 1
 *  PPPACmdActive_Cnt_T_lgc             | boolean   | 0         | 1
 *  HaLFCmdActive_Cnt_T_lgc             | boolean   | 0         | 1
 *  HaLFPriActive_Cnt_T_lgc             | *boolean  | 0         | 1
 *  PPPAPriActive_Cnt_T_lgc             | *boolean  | 0         | 1
 *  DSTPriActive_Cnt_T_lgc              | *boolean  | 0         | 1
 *
 *  Output                              | Type      | Min       | Max
 *  ----------------------------------- | --------- | --------- | ---------
 *  None                                |           |           |
 *
 **********************************************************************************************************************/
STATIC FUNC(void, AP_ARBLMT_CODE) ArbiterPriority(
        VAR(float32, AUTOMATIC) VehSpd_Kph_T_f32,
        VAR(boolean, AUTOMATIC) DSTCmdActive_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) PPPACmdActive_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) HaLFCmdActive_Cnt_T_lgc,
        P2VAR(boolean, AUTOMATIC, AUTOMATIC) HaLFPriActive_Cnt_T_lgc,
        P2VAR(boolean, AUTOMATIC, AUTOMATIC) PPPAPriActive_Cnt_T_lgc,
        P2VAR(boolean, AUTOMATIC, AUTOMATIC) DSTPriActive_Cnt_T_lgc)
{
    VAR(boolean, AUTOMATIC) DSTLowSpdPri_Cnt_T_lgc = DSTLowSpdPri_Cnt_M_lgc;

    /* Take advantage of AND conditions and start by clearing all PriActive outputs */
    DSTLowSpdPri_Cnt_M_lgc = FALSE;
    *HaLFPriActive_Cnt_T_lgc = FALSE;
    *PPPAPriActive_Cnt_T_lgc = FALSE;
    *DSTPriActive_Cnt_T_lgc = FALSE;

    /* Then, selectively enable PriActive outputs based upon priority conditions */
    if (VehSpd_Kph_T_f32 > k_PPPAPriorityVehSpd_Kph_f32)
    {
        if (DSTCmdActive_Cnt_T_lgc == TRUE)
        {
            *DSTPriActive_Cnt_T_lgc = TRUE;
        }
        else if (HaLFCmdActive_Cnt_T_lgc == TRUE)
        {
            *HaLFPriActive_Cnt_T_lgc = TRUE;
        }
        else
        {
            /* Do Nothing */
        }
    }
    else
    {
        if ( (PPPACmdActive_Cnt_T_lgc == TRUE) &&
             (DSTLowSpdPri_Cnt_T_lgc == FALSE) )
        {
            *PPPAPriActive_Cnt_T_lgc = TRUE;
        }
        else if (DSTCmdActive_Cnt_T_lgc == TRUE)
        {
            *DSTPriActive_Cnt_T_lgc = TRUE;
            DSTLowSpdPri_Cnt_M_lgc = TRUE;
        }
        else
        {
            /* Do Nothing */
        }
    }
}


/***********************************************************************************************************************
 *  Name:   ArbiterRamping
 *
 *  Inputs                              | Type      | Min       | Max
 *  ----------------------------------- | --------- | --------- | ---------
 *  DSTEnable_Cnt_T_lgc                 | boolean   | 0         | 1
 *  DSTSlewComplete_Cnt_T_lgc           | boolean   | 0         | 1
 *  HaLFEnable_Cnt_T_lgc                | boolean   | 0         | 1
 *  HaLFSlewComplete_Cnt_T_lgc          | boolean   | 0         | 1
 *  DSTScalar_Uls_T_f32                 | *float32  | 0         | 1
 *  HaLFScalar_Uls_T_f32                | *float32  | 0         | 1
 *
 *  Output                              | Type      | Min       | Max
 *  ----------------------------------- | --------- | --------- | ---------
 *  None                                |           |           |
 *
 **********************************************************************************************************************/
STATIC FUNC(void, AP_ARBLMT_CODE) ArbiterRamping(
        VAR(boolean, AUTOMATIC) DSTEnable_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) DSTSlewComplete_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) HaLFEnable_Cnt_T_lgc,
        VAR(boolean, AUTOMATIC) HaLFSlewComplete_Cnt_T_lgc,
        P2VAR(float32, AUTOMATIC, AUTOMATIC) DSTScalar_Uls_T_f32,
        P2VAR(float32, AUTOMATIC, AUTOMATIC) HaLFScalar_Uls_T_f32)
{
    VAR(float32, AUTOMATIC) DSTScalarInput_Uls_T_f32;
    VAR(float32, AUTOMATIC) HaLFScalarInput_Uls_T_f32;
    VAR(boolean, AUTOMATIC) DSTActive_Cnt_T_lgc;
    VAR(boolean, AUTOMATIC) HaLFActive_Cnt_T_lgc;
    VAR(boolean, AUTOMATIC) DSTRampActive_Cnt_T_lgc;
    VAR(boolean, AUTOMATIC) HaLFRampActive_Cnt_T_lgc;

    if( (DSTEnable_Cnt_T_lgc == TRUE) ||
        (DSTSlewComplete_Cnt_T_lgc == FALSE) )
    {
        DSTScalarInput_Uls_T_f32 = D_ONE_ULS_F32;
        DSTActive_Cnt_T_lgc = TRUE;
    }
    else
    {
        DSTScalarInput_Uls_T_f32 = D_ZERO_ULS_F32;
        DSTActive_Cnt_T_lgc = FALSE;
    }

    if( (HaLFEnable_Cnt_T_lgc == TRUE) ||
        (HaLFSlewComplete_Cnt_T_lgc == FALSE) )
    {
        if (DSTActive_Cnt_T_lgc == FALSE)
        {
            HaLFScalarInput_Uls_T_f32 = D_ONE_ULS_F32;
        }
        else
        {
            HaLFScalarInput_Uls_T_f32 = D_ZERO_ULS_F32;
        }

        HaLFActive_Cnt_T_lgc = TRUE;
    }
    else
    {
        HaLFScalarInput_Uls_T_f32 = D_ZERO_ULS_F32;
        HaLFActive_Cnt_T_lgc = FALSE;
    }

    DSTScalarSlew_Uls_M_f32 = Limit_m(DSTScalarInput_Uls_T_f32,
                                      DSTScalarSlew_Uls_M_f32 - (k_RateLimit_UlspS_f32 * D_4MS_S_F32),
                                      DSTScalarSlew_Uls_M_f32 + (k_RateLimit_UlspS_f32 * D_4MS_S_F32));

    HaLFScalarSlew_Uls_M_f32 = Limit_m(HaLFScalarInput_Uls_T_f32,
                                       HaLFScalarSlew_Uls_M_f32 - (k_RateLimit_UlspS_f32 * D_4MS_S_F32),
                                       HaLFScalarSlew_Uls_M_f32 + (k_RateLimit_UlspS_f32 * D_4MS_S_F32));

    if( ( (DSTActive_Cnt_T_lgc == TRUE) &&
          (PrevDSTActive_Cnt_M_lgc == FALSE) &&
          (HaLFActive_Cnt_T_lgc == TRUE) ) ||
        (PrevDSTRampActive_Cnt_M_lgc == TRUE) ||
        (PrevHaLFRampActive_Cnt_M_lgc == TRUE) )
    {
        /* Ramping == True */
        *DSTScalar_Uls_T_f32 = DSTScalarSlew_Uls_M_f32;
        *HaLFScalar_Uls_T_f32 = HaLFScalarSlew_Uls_M_f32;

        if( (*DSTScalar_Uls_T_f32 > D_ZERO_ULS_F32) &&
            (*DSTScalar_Uls_T_f32 < D_ONE_ULS_F32) )
        {
            DSTRampActive_Cnt_T_lgc = TRUE;
        }
        else
        {
            DSTRampActive_Cnt_T_lgc = FALSE;
        }

        if( (*HaLFScalar_Uls_T_f32 > D_ZERO_ULS_F32) &&
            (*HaLFScalar_Uls_T_f32 < D_ONE_ULS_F32) )
        {
            HaLFRampActive_Cnt_T_lgc = TRUE;
        }
        else
        {
            HaLFRampActive_Cnt_T_lgc = FALSE;
        }
    }
    else
    {
        /* Ramping == False */
        *DSTScalar_Uls_T_f32 = DSTScalarInput_Uls_T_f32;
        *HaLFScalar_Uls_T_f32 = HaLFScalarInput_Uls_T_f32;
        DSTRampActive_Cnt_T_lgc = FALSE;
        HaLFRampActive_Cnt_T_lgc = FALSE;
    }

    PrevDSTActive_Cnt_M_lgc = DSTActive_Cnt_T_lgc;
    PrevDSTRampActive_Cnt_M_lgc = DSTRampActive_Cnt_T_lgc;
    PrevHaLFRampActive_Cnt_M_lgc = HaLFRampActive_Cnt_T_lgc;
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
