/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  Copyright (c) 2006-2011 by Vector Informatik GmbH.                                             All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Components/Rte_Ap_SrlComInput.h
 *     Workspace:  C:/Sankar/Chrysler/Synergy/CL/Temp_work/Chrysler_LWR_EPS_TMS570/Tools/AsrProject/Config/DCF/EPS.dcf
 *   ECU-Project:  EPS
 *  Generated at:  Mon Jul 18 14:56:54 2016
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1
 *       License:  License CBD1010124 valid for CBD1010124 Nexteer  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  Application header file for SW-C
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_AP_SRLCOMINPUT_H
# define _RTE_AP_SRLCOMINPUT_H

# ifndef RTE_CORE
#  ifdef RTE_APPLICATION_HEADER_FILE
#   error Multiple application header files included.
#  endif
#  define RTE_APPLICATION_HEADER_FILE
# endif

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

/* include files */

# include "Rte_Type.h"

# ifndef RTE_CORE

#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h"

/************************************************************************/
/* extern declaration of RTE buffers for optimized macro implementation */
/************************************************************************/
extern VAR(Float, RTE_VAR_INIT) Rte_SrlComInput_AirTempOutside_DegC_f32;
extern VAR(Float, RTE_VAR_INIT) Rte_SrlComInput_AmbTempAvg_DegC_f32;
extern VAR(Float, RTE_VAR_INIT) Rte_SrlComInput_BattVolt_Volt_f32;
extern VAR(UInt8, RTE_VAR_INIT) Rte_SrlComInput_CMDIgnStat_Cnt_u08;
extern VAR(Boolean, RTE_VAR_INIT) Rte_SrlComInput_CanMsgReceived_Cnt_lgc;
extern VAR(UInt8, RTE_VAR_INIT) Rte_SrlComInput_CfgStatRQ_Cnt_u08;
extern VAR(Boolean, RTE_VAR_INIT) Rte_SrlComInput_DSTEOLDisable_Cnt_lgc;
extern VAR(Boolean, RTE_VAR_INIT) Rte_SrlComInput_DSTEnableRqst_Cnt_lgc;
extern VAR(UInt8, RTE_VAR_INIT) Rte_SrlComInput_DSTErrCntrRecvLevel_Cnt_u08;
extern VAR(Boolean, RTE_VAR_INIT) Rte_SrlComInput_DSTExtSystemFltActive_Cnt_lgc;
extern VAR(Boolean, RTE_VAR_INIT) Rte_SrlComInput_DSTFuncPresent_Cnt_lgc;
extern VAR(Boolean, RTE_VAR_INIT) Rte_SrlComInput_DSTRevGearValid_Cnt_lgc;
extern VAR(TOC_STATE, RTE_VAR_INIT) Rte_SrlComInput_DSTTOCState_Uls_enum;
extern VAR(Float, RTE_VAR_INIT) Rte_SrlComInput_DSTTrqOvCmdRqst_HwNm_f32;
extern VAR(Boolean, RTE_VAR_INIT) Rte_SrlComInput_DSTTrqOvRqstValid_Cnt_lgc;
extern VAR(UInt16, RTE_VAR_INIT) Rte_SrlComInput_DesiredTunPers_Cnt_u16;
extern VAR(UInt8, RTE_VAR_INIT) Rte_SrlComInput_DesiredTunPersTypH_Cnt_u08;
extern VAR(UInt16, RTE_VAR_INIT) Rte_SrlComInput_DesiredTunSet_Cnt_u16;
extern VAR(UInt8, RTE_VAR_INIT) Rte_SrlComInput_EPS_Mode_Req_Cnt_u08;
extern VAR(Float, RTE_VAR_INIT) Rte_SrlComInput_EngOilTemp_DegC_f32;
extern VAR(UInt16, RTE_VAR_INIT) Rte_SrlComInput_EngRPM_Cnt_u16;
extern VAR(Boolean, RTE_VAR_INIT) Rte_SrlComInput_EssEngStop_Cnt_lgc;
extern VAR(Boolean, RTE_VAR_INIT) Rte_SrlComInput_HaLFEnableRqst_Cnt_lgc;
extern VAR(Boolean, RTE_VAR_INIT) Rte_SrlComInput_HaLFErrInterfaceActive_Cnt_lgc;
extern VAR(Boolean, RTE_VAR_INIT) Rte_SrlComInput_HaLFExtSystemFltActive_Cnt_lgc;
extern VAR(Boolean, RTE_VAR_INIT) Rte_SrlComInput_HaLFFuncPresent_Cnt_lgc;
extern VAR(Boolean, RTE_VAR_INIT) Rte_SrlComInput_HaLFIntSystemFltActive_Cnt_lgc;
extern VAR(Boolean, RTE_VAR_INIT) Rte_SrlComInput_HaLFSWATrqFail_Cnt_lgc;
extern VAR(Float, RTE_VAR_INIT) Rte_SrlComInput_HaLFTrqOvCmdRqst_MtrNm_f32;
extern VAR(Boolean, RTE_VAR_INIT) Rte_SrlComInput_HalfTrqOvRvrsGearEngage_Cnt_lgc;
extern VAR(Float, RTE_VAR_INIT) Rte_SrlComInput_IWSSCalcVspd_Kph_f32;
extern VAR(UInt16, RTE_VAR_INIT) Rte_SrlComInput_NET_CFG_STAT_PT_Cnt_u16;
extern VAR(Boolean, RTE_VAR_INIT) Rte_SrlComInput_PAEnableRqst_Cnt_lgc;
extern VAR(Boolean, RTE_VAR_INIT) Rte_SrlComInput_PAErrInterfaceActive_Cnt_lgc;
extern VAR(Boolean, RTE_VAR_INIT) Rte_SrlComInput_PAExtSystemFltActive_Cnt_lgc;
extern VAR(Boolean, RTE_VAR_INIT) Rte_SrlComInput_PAIntSystemFltActive_Cnt_lgc;
extern VAR(UInt8, RTE_VAR_INIT) Rte_SrlComInput_PAManoeuvrePhase_Cnt_u08;
extern VAR(Float, RTE_VAR_INIT) Rte_SrlComInput_PATrqOvCmdRqst_HwNm_f32;
extern VAR(Boolean, RTE_VAR_INIT) Rte_SrlComInput_PAWheelCriteriaMet_Cnt_lgc;
extern VAR(UInt8, RTE_VAR_INIT) Rte_SrlComInput_PAWhlDirRLStat_Cnt_u08;
extern VAR(UInt8, RTE_VAR_INIT) Rte_SrlComInput_PAWhlDirRRStat_Cnt_u08;
extern VAR(Boolean, RTE_VAR_INIT) Rte_SrlComInput_PAWhlPlsCntRLValid_Cnt_lgc;
extern VAR(Boolean, RTE_VAR_INIT) Rte_SrlComInput_PAWhlPlsCntRRValid_Cnt_lgc;
extern VAR(Boolean, RTE_VAR_INIT) Rte_SrlComInput_PrevHaLFEnableRqst_Cnt_lgc;
extern VAR(Float, RTE_VAR_INIT) Rte_SrlComInput_PrevHaLFTrqOvCmdRqst_MtrNm_f32;
extern VAR(Boolean, RTE_VAR_INIT) Rte_SrlComInput_PrkAsstFuncPresent_Cnt_lgc;
extern VAR(Boolean, RTE_VAR_INIT) Rte_SrlComInput_SpStPrsnt_Cnt_lgc;
extern VAR(Float, RTE_VAR_INIT) Rte_SrlComInput_SrlComLWhlSpd_Hz_f32;
extern VAR(Boolean, RTE_VAR_INIT) Rte_SrlComInput_SrlComLWhlSpdVld_Cnt_lgc;
extern VAR(Float, RTE_VAR_INIT) Rte_SrlComInput_SrlComRWhlSpd_Hz_f32;
extern VAR(Boolean, RTE_VAR_INIT) Rte_SrlComInput_SrlComRWhlSpdVld_Cnt_lgc;
extern VAR(Float, RTE_VAR_INIT) Rte_SrlComInput_SrlComVehSpd_Kph_f32;
extern VAR(Boolean, RTE_VAR_INIT) Rte_SrlComInput_SrlComVehSpdValid_Cnt_lgc;
extern VAR(Float, RTE_VAR_INIT) Rte_SrlComInput_StrgWhlAngl_HwDeg_f32;
extern VAR(Boolean, RTE_VAR_INIT) Rte_SrlComInput_StrgWhlAnglValid_Cnt_lgc;
extern VAR(Boolean, RTE_VAR_INIT) Rte_SrlComInput_TrqOvReverseGearEngage_Cnt_lgc;
extern VAR(UInt8, RTE_VAR_INIT) Rte_SrlComInput_VCBodyStyle_Cnt_u08;
extern VAR(UInt8, RTE_VAR_INIT) Rte_SrlComInput_VCCountry_Cnt_u08;
extern VAR(UInt8, RTE_VAR_INIT) Rte_SrlComInput_VCModelYear_Cnt_u08;
extern VAR(UInt8, RTE_VAR_INIT) Rte_SrlComInput_VCVehLine_Cnt_u08;
extern VAR(Float, RTE_VAR_INIT) Rte_SrlComInput_VehAccelX_KphpS_f32;
extern VAR(Float, RTE_VAR_INIT) Rte_HwTrq_AnaHwTorque_HwNm_f32;
extern VAR(Boolean, RTE_VAR_INIT) Rte_Ap_StbCTO_DSTSlewStart_Cnt_lgc;
extern VAR(UInt8, RTE_VAR_INIT) Rte_Ap_StbCTO_DSTState_Cnt_u08;
extern VAR(Boolean, RTE_VAR_INIT) Rte_DiagMgr_DiagStsDefVehSpd_Cnt_lgc;
extern VAR(Float, RTE_VAR_INIT) Rte_Ap_AvgFricLrn_EstFric_HwNm_f32;
extern VAR(UInt8, RTE_VAR_INIT) Rte_Ap_HaLFTO_HaLFState_Cnt_u08;
extern VAR(Boolean, RTE_VAR_INIT) Rte_Ap_HaLFTO_HaLFSuspend_Cnt_lgc;
extern VAR(Boolean, RTE_VAR_INIT) Rte_Ap_PAwTO_HandsOnDetect_Cnt_lgc;
extern VAR(ManufModeType, RTE_VAR_INIT) Rte_CDDInterface_MEC_Cnt_enum;
extern VAR(Boolean, RTE_VAR_INIT) Rte_Ap_PAwTO_PABoostCurveSwitch_Cnt_lgc;
extern VAR(UInt8, RTE_VAR_INIT) Rte_Ap_PAwTO_PrkAssistState_Cnt_u08;
extern VAR(Boolean, RTE_VAR_INIT) Rte_Ap_PAwTO_PrkAssistSuspend_Cnt_lgc;
extern VAR(Boolean, RTE_VAR_INIT) Rte_CDDInterface_RxMsgsSrlComSvcDft_Cnt_lgc;

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h"

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_AirTempOutside_DegC_f32 (0.0F)
#  define Rte_InitValue_AmbTempAvg_DegC_f32 (0.0F)
#  define Rte_InitValue_AnaHwTorque_HwNm_f32 (0.0F)
#  define Rte_InitValue_BattVolt_Volt_f32 (0.0F)
#  define Rte_InitValue_CMDIgnStat_Cnt_u08 (0U)
#  define Rte_InitValue_CanMsgReceived_Cnt_lgc (FALSE)
#  define Rte_InitValue_CfgStatRQ_Cnt_u08 (0U)
#  define Rte_InitValue_DSTEOLDisable_Cnt_lgc (FALSE)
#  define Rte_InitValue_DSTEnableRqst_Cnt_lgc (FALSE)
#  define Rte_InitValue_DSTErrCntrRecvLevel_Cnt_u08 (0U)
#  define Rte_InitValue_DSTExtSystemFltActive_Cnt_lgc (FALSE)
#  define Rte_InitValue_DSTFuncPresent_Cnt_lgc (FALSE)
#  define Rte_InitValue_DSTRevGearValid_Cnt_lgc (FALSE)
#  define Rte_InitValue_DSTSlewStart_Cnt_lgc (FALSE)
#  define Rte_InitValue_DSTState_Cnt_u08 (0U)
#  define Rte_InitValue_DSTTOCState_Uls_enum (0U)
#  define Rte_InitValue_DSTTrqOvCmdRqst_HwNm_f32 (0.0F)
#  define Rte_InitValue_DSTTrqOvRqstValid_Cnt_lgc (FALSE)
#  define Rte_InitValue_DefaultVehSpd_Cnt_lgc (FALSE)
#  define Rte_InitValue_DesiredTunPers_Cnt_u16 (0U)
#  define Rte_InitValue_DesiredTunPersTypH_Cnt_u08 (0U)
#  define Rte_InitValue_DesiredTunSet_Cnt_u16 (0U)
#  define Rte_InitValue_EPS_Mode_Req_Cnt_u08 (0U)
#  define Rte_InitValue_EngOilTemp_DegC_f32 (0.0F)
#  define Rte_InitValue_EngRPM_Cnt_u16 (1U)
#  define Rte_InitValue_EssEngStop_Cnt_lgc (TRUE)
#  define Rte_InitValue_EstFric_HwNm_f32 (0.0F)
#  define Rte_InitValue_HaLFEnableRqst_Cnt_lgc (FALSE)
#  define Rte_InitValue_HaLFErrInterfaceActive_Cnt_lgc (FALSE)
#  define Rte_InitValue_HaLFExtSystemFltActive_Cnt_lgc (FALSE)
#  define Rte_InitValue_HaLFFuncPresent_Cnt_lgc (FALSE)
#  define Rte_InitValue_HaLFIntSystemFltActive_Cnt_lgc (FALSE)
#  define Rte_InitValue_HaLFSWATrqFail_Cnt_lgc (FALSE)
#  define Rte_InitValue_HaLFState_Cnt_u08 (0U)
#  define Rte_InitValue_HaLFSuspend_Cnt_lgc (FALSE)
#  define Rte_InitValue_HaLFTrqOvCmdRqst_MtrNm_f32 (0.0F)
#  define Rte_InitValue_HalfTrqOvRvrsGearEngage_Cnt_lgc (FALSE)
#  define Rte_InitValue_HandsOnDetect_Cnt_lgc (FALSE)
#  define Rte_InitValue_IWSSCalcVspd_Kph_f32 (0.0F)
#  define Rte_InitValue_MEC_Cnt_enum (0U)
#  define Rte_InitValue_NET_CFG_STAT_PT_Cnt_u16 (0U)
#  define Rte_InitValue_ODO_HwNmSq_f32 (0.0F)
#  define Rte_InitValue_PABoostCurveSwitch_Cnt_lgc (FALSE)
#  define Rte_InitValue_PAEnableRqst_Cnt_lgc (FALSE)
#  define Rte_InitValue_PAErrInterfaceActive_Cnt_lgc (FALSE)
#  define Rte_InitValue_PAExtSystemFltActive_Cnt_lgc (FALSE)
#  define Rte_InitValue_PAIntSystemFltActive_Cnt_lgc (FALSE)
#  define Rte_InitValue_PAManoeuvrePhase_Cnt_u08 (0U)
#  define Rte_InitValue_PATrqOvCmdRqst_HwNm_f32 (0.0F)
#  define Rte_InitValue_PAWheelCriteriaMet_Cnt_lgc (FALSE)
#  define Rte_InitValue_PAWhlDirRLStat_Cnt_u08 (3U)
#  define Rte_InitValue_PAWhlDirRRStat_Cnt_u08 (3U)
#  define Rte_InitValue_PAWhlPlsCntRLValid_Cnt_lgc (FALSE)
#  define Rte_InitValue_PAWhlPlsCntRRValid_Cnt_lgc (FALSE)
#  define Rte_InitValue_PrevHaLFEnableRqst_Cnt_lgc (FALSE)
#  define Rte_InitValue_PrevHaLFTrqOvCmdRqst_MtrNm_f32 (0.0F)
#  define Rte_InitValue_PrkAssistState_Cnt_u08 (0U)
#  define Rte_InitValue_PrkAssistSuspend_Cnt_lgc (FALSE)
#  define Rte_InitValue_PrkAsstFuncPresent_Cnt_lgc (FALSE)
#  define Rte_InitValue_RxMsgsSrlComSvcDft_Cnt_lgc (FALSE)
#  define Rte_InitValue_SpStPrsnt_Cnt_lgc (FALSE)
#  define Rte_InitValue_SrlComLWhlSpd_Hz_f32 (0.0F)
#  define Rte_InitValue_SrlComLWhlSpdVld_Cnt_lgc (FALSE)
#  define Rte_InitValue_SrlComRWhlSpd_Hz_f32 (0.0F)
#  define Rte_InitValue_SrlComRWhlSpdVld_Cnt_lgc (FALSE)
#  define Rte_InitValue_SrlComVehSpd_Kph_f32 (0.0F)
#  define Rte_InitValue_SrlComVehSpdValid_Cnt_lgc (FALSE)
#  define Rte_InitValue_StrClmTrq_HwNm_f32 (0.0F)
#  define Rte_InitValue_StrgWhlAngl_HwDeg_f32 (0.0F)
#  define Rte_InitValue_StrgWhlAnglValid_Cnt_lgc (FALSE)
#  define Rte_InitValue_TrqOvReverseGearEngage_Cnt_lgc (FALSE)
#  define Rte_InitValue_VCBodyStyle_Cnt_u08 (0U)
#  define Rte_InitValue_VCCountry_Cnt_u08 (0U)
#  define Rte_InitValue_VCModelYear_Cnt_u08 (0U)
#  define Rte_InitValue_VCVehLine_Cnt_u08 (0U)
#  define Rte_InitValue_VehAccel_KphpS_f32 (0.0F)
#  define Rte_InitValue_VehAccelX_KphpS_f32 (0.0F)
# endif


# ifndef RTE_CORE
#  define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#  include "MemMap.h"

/**********************************************************************************************************************
 * Buffers for Mode Management
 *********************************************************************************************************************/
extern VAR(Rte_ModeType_StaMd_Mode, RTE_VAR_NOINIT) Rte_ModeMachine_Ap_StaMd9_SystemState9_Mode;

#  define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#  include "MemMap.h"
# endif /* !defined(RTE_CORE) */



# define RTE_START_SEC_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/

# define RTE_STOP_SEC_CODE
# include "MemMap.h"


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_AnaHwTorque_HwNm_f32 Rte_Read_Ap_SrlComInput_AnaHwTorque_HwNm_f32
#  define Rte_Read_Ap_SrlComInput_AnaHwTorque_HwNm_f32(data) (*(data) = Rte_HwTrq_AnaHwTorque_HwNm_f32, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_DSTSlewStart_Cnt_lgc Rte_Read_Ap_SrlComInput_DSTSlewStart_Cnt_lgc
#  define Rte_Read_Ap_SrlComInput_DSTSlewStart_Cnt_lgc(data) (*(data) = Rte_Ap_StbCTO_DSTSlewStart_Cnt_lgc, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_DSTState_Cnt_u08 Rte_Read_Ap_SrlComInput_DSTState_Cnt_u08
#  define Rte_Read_Ap_SrlComInput_DSTState_Cnt_u08(data) (*(data) = Rte_Ap_StbCTO_DSTState_Cnt_u08, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_DefaultVehSpd_Cnt_lgc Rte_Read_Ap_SrlComInput_DefaultVehSpd_Cnt_lgc
#  define Rte_Read_Ap_SrlComInput_DefaultVehSpd_Cnt_lgc(data) (*(data) = Rte_DiagMgr_DiagStsDefVehSpd_Cnt_lgc, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_EstFric_HwNm_f32 Rte_Read_Ap_SrlComInput_EstFric_HwNm_f32
#  define Rte_Read_Ap_SrlComInput_EstFric_HwNm_f32(data) (*(data) = Rte_Ap_AvgFricLrn_EstFric_HwNm_f32, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_HaLFState_Cnt_u08 Rte_Read_Ap_SrlComInput_HaLFState_Cnt_u08
#  define Rte_Read_Ap_SrlComInput_HaLFState_Cnt_u08(data) (*(data) = Rte_Ap_HaLFTO_HaLFState_Cnt_u08, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_HaLFSuspend_Cnt_lgc Rte_Read_Ap_SrlComInput_HaLFSuspend_Cnt_lgc
#  define Rte_Read_Ap_SrlComInput_HaLFSuspend_Cnt_lgc(data) (*(data) = Rte_Ap_HaLFTO_HaLFSuspend_Cnt_lgc, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_HandsOnDetect_Cnt_lgc Rte_Read_Ap_SrlComInput_HandsOnDetect_Cnt_lgc
#  define Rte_Read_Ap_SrlComInput_HandsOnDetect_Cnt_lgc(data) (*(data) = Rte_Ap_PAwTO_HandsOnDetect_Cnt_lgc, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_MEC_Cnt_enum Rte_Read_Ap_SrlComInput_MEC_Cnt_enum
#  define Rte_Read_Ap_SrlComInput_MEC_Cnt_enum(data) (*(data) = Rte_CDDInterface_MEC_Cnt_enum, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_PABoostCurveSwitch_Cnt_lgc Rte_Read_Ap_SrlComInput_PABoostCurveSwitch_Cnt_lgc
#  define Rte_Read_Ap_SrlComInput_PABoostCurveSwitch_Cnt_lgc(data) (*(data) = Rte_Ap_PAwTO_PABoostCurveSwitch_Cnt_lgc, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_PrkAssistState_Cnt_u08 Rte_Read_Ap_SrlComInput_PrkAssistState_Cnt_u08
#  define Rte_Read_Ap_SrlComInput_PrkAssistState_Cnt_u08(data) (*(data) = Rte_Ap_PAwTO_PrkAssistState_Cnt_u08, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_PrkAssistSuspend_Cnt_lgc Rte_Read_Ap_SrlComInput_PrkAssistSuspend_Cnt_lgc
#  define Rte_Read_Ap_SrlComInput_PrkAssistSuspend_Cnt_lgc(data) (*(data) = Rte_Ap_PAwTO_PrkAssistSuspend_Cnt_lgc, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RxMsgsSrlComSvcDft_Cnt_lgc Rte_Read_Ap_SrlComInput_RxMsgsSrlComSvcDft_Cnt_lgc
#  define Rte_Read_Ap_SrlComInput_RxMsgsSrlComSvcDft_Cnt_lgc(data) (*(data) = Rte_CDDInterface_RxMsgsSrlComSvcDft_Cnt_lgc, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_StrClmTrq_HwNm_f32 Rte_Read_Ap_SrlComInput_StrClmTrq_HwNm_f32
#  define Rte_Read_Ap_SrlComInput_StrClmTrq_HwNm_f32(data) (*(data) = Rte_HwTrq_AnaHwTorque_HwNm_f32, ((Std_ReturnType)RTE_E_OK))


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_AirTempOutside_DegC_f32 Rte_Write_Ap_SrlComInput_AirTempOutside_DegC_f32
#  define Rte_Write_Ap_SrlComInput_AirTempOutside_DegC_f32(data) (Rte_SrlComInput_AirTempOutside_DegC_f32 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_AmbTempAvg_DegC_f32 Rte_Write_Ap_SrlComInput_AmbTempAvg_DegC_f32
#  define Rte_Write_Ap_SrlComInput_AmbTempAvg_DegC_f32(data) (Rte_SrlComInput_AmbTempAvg_DegC_f32 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_BattVolt_Volt_f32 Rte_Write_Ap_SrlComInput_BattVolt_Volt_f32
#  define Rte_Write_Ap_SrlComInput_BattVolt_Volt_f32(data) (Rte_SrlComInput_BattVolt_Volt_f32 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_CMDIgnStat_Cnt_u08 Rte_Write_Ap_SrlComInput_CMDIgnStat_Cnt_u08
#  define Rte_Write_Ap_SrlComInput_CMDIgnStat_Cnt_u08(data) (Rte_SrlComInput_CMDIgnStat_Cnt_u08 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_CanMsgReceived_Cnt_lgc Rte_Write_Ap_SrlComInput_CanMsgReceived_Cnt_lgc
#  define Rte_Write_Ap_SrlComInput_CanMsgReceived_Cnt_lgc(data) (Rte_SrlComInput_CanMsgReceived_Cnt_lgc = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_CfgStatRQ_Cnt_u08 Rte_Write_Ap_SrlComInput_CfgStatRQ_Cnt_u08
#  define Rte_Write_Ap_SrlComInput_CfgStatRQ_Cnt_u08(data) (Rte_SrlComInput_CfgStatRQ_Cnt_u08 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_DSTEOLDisable_Cnt_lgc Rte_Write_Ap_SrlComInput_DSTEOLDisable_Cnt_lgc
#  define Rte_Write_Ap_SrlComInput_DSTEOLDisable_Cnt_lgc(data) (Rte_SrlComInput_DSTEOLDisable_Cnt_lgc = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_DSTEnableRqst_Cnt_lgc Rte_Write_Ap_SrlComInput_DSTEnableRqst_Cnt_lgc
#  define Rte_Write_Ap_SrlComInput_DSTEnableRqst_Cnt_lgc(data) (Rte_SrlComInput_DSTEnableRqst_Cnt_lgc = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_DSTErrCntrRecvLevel_Cnt_u08 Rte_Write_Ap_SrlComInput_DSTErrCntrRecvLevel_Cnt_u08
#  define Rte_Write_Ap_SrlComInput_DSTErrCntrRecvLevel_Cnt_u08(data) (Rte_SrlComInput_DSTErrCntrRecvLevel_Cnt_u08 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_DSTExtSystemFltActive_Cnt_lgc Rte_Write_Ap_SrlComInput_DSTExtSystemFltActive_Cnt_lgc
#  define Rte_Write_Ap_SrlComInput_DSTExtSystemFltActive_Cnt_lgc(data) (Rte_SrlComInput_DSTExtSystemFltActive_Cnt_lgc = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_DSTFuncPresent_Cnt_lgc Rte_Write_Ap_SrlComInput_DSTFuncPresent_Cnt_lgc
#  define Rte_Write_Ap_SrlComInput_DSTFuncPresent_Cnt_lgc(data) (Rte_SrlComInput_DSTFuncPresent_Cnt_lgc = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_DSTRevGearValid_Cnt_lgc Rte_Write_Ap_SrlComInput_DSTRevGearValid_Cnt_lgc
#  define Rte_Write_Ap_SrlComInput_DSTRevGearValid_Cnt_lgc(data) (Rte_SrlComInput_DSTRevGearValid_Cnt_lgc = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_DSTTOCState_Uls_enum Rte_Write_Ap_SrlComInput_DSTTOCState_Uls_enum
#  define Rte_Write_Ap_SrlComInput_DSTTOCState_Uls_enum(data) (Rte_SrlComInput_DSTTOCState_Uls_enum = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_DSTTrqOvCmdRqst_HwNm_f32 Rte_Write_Ap_SrlComInput_DSTTrqOvCmdRqst_HwNm_f32
#  define Rte_Write_Ap_SrlComInput_DSTTrqOvCmdRqst_HwNm_f32(data) (Rte_SrlComInput_DSTTrqOvCmdRqst_HwNm_f32 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_DSTTrqOvRqstValid_Cnt_lgc Rte_Write_Ap_SrlComInput_DSTTrqOvRqstValid_Cnt_lgc
#  define Rte_Write_Ap_SrlComInput_DSTTrqOvRqstValid_Cnt_lgc(data) (Rte_SrlComInput_DSTTrqOvRqstValid_Cnt_lgc = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_DesiredTunPers_Cnt_u16 Rte_Write_Ap_SrlComInput_DesiredTunPers_Cnt_u16
#  define Rte_Write_Ap_SrlComInput_DesiredTunPers_Cnt_u16(data) (Rte_SrlComInput_DesiredTunPers_Cnt_u16 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_DesiredTunPersTypH_Cnt_u08 Rte_Write_Ap_SrlComInput_DesiredTunPersTypH_Cnt_u08
#  define Rte_Write_Ap_SrlComInput_DesiredTunPersTypH_Cnt_u08(data) (Rte_SrlComInput_DesiredTunPersTypH_Cnt_u08 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_DesiredTunSet_Cnt_u16 Rte_Write_Ap_SrlComInput_DesiredTunSet_Cnt_u16
#  define Rte_Write_Ap_SrlComInput_DesiredTunSet_Cnt_u16(data) (Rte_SrlComInput_DesiredTunSet_Cnt_u16 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_EPS_Mode_Req_Cnt_u08 Rte_Write_Ap_SrlComInput_EPS_Mode_Req_Cnt_u08
#  define Rte_Write_Ap_SrlComInput_EPS_Mode_Req_Cnt_u08(data) (Rte_SrlComInput_EPS_Mode_Req_Cnt_u08 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_EngOilTemp_DegC_f32 Rte_Write_Ap_SrlComInput_EngOilTemp_DegC_f32
#  define Rte_Write_Ap_SrlComInput_EngOilTemp_DegC_f32(data) (Rte_SrlComInput_EngOilTemp_DegC_f32 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_EngRPM_Cnt_u16 Rte_Write_Ap_SrlComInput_EngRPM_Cnt_u16
#  define Rte_Write_Ap_SrlComInput_EngRPM_Cnt_u16(data) (Rte_SrlComInput_EngRPM_Cnt_u16 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_EssEngStop_Cnt_lgc Rte_Write_Ap_SrlComInput_EssEngStop_Cnt_lgc
#  define Rte_Write_Ap_SrlComInput_EssEngStop_Cnt_lgc(data) (Rte_SrlComInput_EssEngStop_Cnt_lgc = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_HaLFEnableRqst_Cnt_lgc Rte_Write_Ap_SrlComInput_HaLFEnableRqst_Cnt_lgc
#  define Rte_Write_Ap_SrlComInput_HaLFEnableRqst_Cnt_lgc(data) (Rte_SrlComInput_HaLFEnableRqst_Cnt_lgc = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_HaLFErrInterfaceActive_Cnt_lgc Rte_Write_Ap_SrlComInput_HaLFErrInterfaceActive_Cnt_lgc
#  define Rte_Write_Ap_SrlComInput_HaLFErrInterfaceActive_Cnt_lgc(data) (Rte_SrlComInput_HaLFErrInterfaceActive_Cnt_lgc = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_HaLFExtSystemFltActive_Cnt_lgc Rte_Write_Ap_SrlComInput_HaLFExtSystemFltActive_Cnt_lgc
#  define Rte_Write_Ap_SrlComInput_HaLFExtSystemFltActive_Cnt_lgc(data) (Rte_SrlComInput_HaLFExtSystemFltActive_Cnt_lgc = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_HaLFFuncPresent_Cnt_lgc Rte_Write_Ap_SrlComInput_HaLFFuncPresent_Cnt_lgc
#  define Rte_Write_Ap_SrlComInput_HaLFFuncPresent_Cnt_lgc(data) (Rte_SrlComInput_HaLFFuncPresent_Cnt_lgc = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_HaLFIntSystemFltActive_Cnt_lgc Rte_Write_Ap_SrlComInput_HaLFIntSystemFltActive_Cnt_lgc
#  define Rte_Write_Ap_SrlComInput_HaLFIntSystemFltActive_Cnt_lgc(data) (Rte_SrlComInput_HaLFIntSystemFltActive_Cnt_lgc = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_HaLFSWATrqFail_Cnt_lgc Rte_Write_Ap_SrlComInput_HaLFSWATrqFail_Cnt_lgc
#  define Rte_Write_Ap_SrlComInput_HaLFSWATrqFail_Cnt_lgc(data) (Rte_SrlComInput_HaLFSWATrqFail_Cnt_lgc = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_HaLFTrqOvCmdRqst_MtrNm_f32 Rte_Write_Ap_SrlComInput_HaLFTrqOvCmdRqst_MtrNm_f32
#  define Rte_Write_Ap_SrlComInput_HaLFTrqOvCmdRqst_MtrNm_f32(data) (Rte_SrlComInput_HaLFTrqOvCmdRqst_MtrNm_f32 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_HalfTrqOvRvrsGearEngage_Cnt_lgc Rte_Write_Ap_SrlComInput_HalfTrqOvRvrsGearEngage_Cnt_lgc
#  define Rte_Write_Ap_SrlComInput_HalfTrqOvRvrsGearEngage_Cnt_lgc(data) (Rte_SrlComInput_HalfTrqOvRvrsGearEngage_Cnt_lgc = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_IWSSCalcVspd_Kph_f32 Rte_Write_Ap_SrlComInput_IWSSCalcVspd_Kph_f32
#  define Rte_Write_Ap_SrlComInput_IWSSCalcVspd_Kph_f32(data) (Rte_SrlComInput_IWSSCalcVspd_Kph_f32 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_NET_CFG_STAT_PT_Cnt_u16 Rte_Write_Ap_SrlComInput_NET_CFG_STAT_PT_Cnt_u16
#  define Rte_Write_Ap_SrlComInput_NET_CFG_STAT_PT_Cnt_u16(data) (Rte_SrlComInput_NET_CFG_STAT_PT_Cnt_u16 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_ODO_HwNmSq_f32 Rte_Write_Ap_SrlComInput_ODO_HwNmSq_f32
#  define Rte_Write_Ap_SrlComInput_ODO_HwNmSq_f32(data) (RTE_E_OK)
#  define Rte_Write_PAEnableRqst_Cnt_lgc Rte_Write_Ap_SrlComInput_PAEnableRqst_Cnt_lgc
#  define Rte_Write_Ap_SrlComInput_PAEnableRqst_Cnt_lgc(data) (Rte_SrlComInput_PAEnableRqst_Cnt_lgc = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PAErrInterfaceActive_Cnt_lgc Rte_Write_Ap_SrlComInput_PAErrInterfaceActive_Cnt_lgc
#  define Rte_Write_Ap_SrlComInput_PAErrInterfaceActive_Cnt_lgc(data) (Rte_SrlComInput_PAErrInterfaceActive_Cnt_lgc = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PAExtSystemFltActive_Cnt_lgc Rte_Write_Ap_SrlComInput_PAExtSystemFltActive_Cnt_lgc
#  define Rte_Write_Ap_SrlComInput_PAExtSystemFltActive_Cnt_lgc(data) (Rte_SrlComInput_PAExtSystemFltActive_Cnt_lgc = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PAIntSystemFltActive_Cnt_lgc Rte_Write_Ap_SrlComInput_PAIntSystemFltActive_Cnt_lgc
#  define Rte_Write_Ap_SrlComInput_PAIntSystemFltActive_Cnt_lgc(data) (Rte_SrlComInput_PAIntSystemFltActive_Cnt_lgc = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PAManoeuvrePhase_Cnt_u08 Rte_Write_Ap_SrlComInput_PAManoeuvrePhase_Cnt_u08
#  define Rte_Write_Ap_SrlComInput_PAManoeuvrePhase_Cnt_u08(data) (Rte_SrlComInput_PAManoeuvrePhase_Cnt_u08 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PATrqOvCmdRqst_HwNm_f32 Rte_Write_Ap_SrlComInput_PATrqOvCmdRqst_HwNm_f32
#  define Rte_Write_Ap_SrlComInput_PATrqOvCmdRqst_HwNm_f32(data) (Rte_SrlComInput_PATrqOvCmdRqst_HwNm_f32 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PAWheelCriteriaMet_Cnt_lgc Rte_Write_Ap_SrlComInput_PAWheelCriteriaMet_Cnt_lgc
#  define Rte_Write_Ap_SrlComInput_PAWheelCriteriaMet_Cnt_lgc(data) (Rte_SrlComInput_PAWheelCriteriaMet_Cnt_lgc = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PAWhlDirRLStat_Cnt_u08 Rte_Write_Ap_SrlComInput_PAWhlDirRLStat_Cnt_u08
#  define Rte_Write_Ap_SrlComInput_PAWhlDirRLStat_Cnt_u08(data) (Rte_SrlComInput_PAWhlDirRLStat_Cnt_u08 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PAWhlDirRRStat_Cnt_u08 Rte_Write_Ap_SrlComInput_PAWhlDirRRStat_Cnt_u08
#  define Rte_Write_Ap_SrlComInput_PAWhlDirRRStat_Cnt_u08(data) (Rte_SrlComInput_PAWhlDirRRStat_Cnt_u08 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PAWhlPlsCntRLValid_Cnt_lgc Rte_Write_Ap_SrlComInput_PAWhlPlsCntRLValid_Cnt_lgc
#  define Rte_Write_Ap_SrlComInput_PAWhlPlsCntRLValid_Cnt_lgc(data) (Rte_SrlComInput_PAWhlPlsCntRLValid_Cnt_lgc = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PAWhlPlsCntRRValid_Cnt_lgc Rte_Write_Ap_SrlComInput_PAWhlPlsCntRRValid_Cnt_lgc
#  define Rte_Write_Ap_SrlComInput_PAWhlPlsCntRRValid_Cnt_lgc(data) (Rte_SrlComInput_PAWhlPlsCntRRValid_Cnt_lgc = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PrevHaLFEnableRqst_Cnt_lgc Rte_Write_Ap_SrlComInput_PrevHaLFEnableRqst_Cnt_lgc
#  define Rte_Write_Ap_SrlComInput_PrevHaLFEnableRqst_Cnt_lgc(data) (Rte_SrlComInput_PrevHaLFEnableRqst_Cnt_lgc = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PrevHaLFTrqOvCmdRqst_MtrNm_f32 Rte_Write_Ap_SrlComInput_PrevHaLFTrqOvCmdRqst_MtrNm_f32
#  define Rte_Write_Ap_SrlComInput_PrevHaLFTrqOvCmdRqst_MtrNm_f32(data) (Rte_SrlComInput_PrevHaLFTrqOvCmdRqst_MtrNm_f32 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PrkAsstFuncPresent_Cnt_lgc Rte_Write_Ap_SrlComInput_PrkAsstFuncPresent_Cnt_lgc
#  define Rte_Write_Ap_SrlComInput_PrkAsstFuncPresent_Cnt_lgc(data) (Rte_SrlComInput_PrkAsstFuncPresent_Cnt_lgc = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_SpStPrsnt_Cnt_lgc Rte_Write_Ap_SrlComInput_SpStPrsnt_Cnt_lgc
#  define Rte_Write_Ap_SrlComInput_SpStPrsnt_Cnt_lgc(data) (Rte_SrlComInput_SpStPrsnt_Cnt_lgc = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_SrlComLWhlSpd_Hz_f32 Rte_Write_Ap_SrlComInput_SrlComLWhlSpd_Hz_f32
#  define Rte_Write_Ap_SrlComInput_SrlComLWhlSpd_Hz_f32(data) (Rte_SrlComInput_SrlComLWhlSpd_Hz_f32 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_SrlComLWhlSpdVld_Cnt_lgc Rte_Write_Ap_SrlComInput_SrlComLWhlSpdVld_Cnt_lgc
#  define Rte_Write_Ap_SrlComInput_SrlComLWhlSpdVld_Cnt_lgc(data) (Rte_SrlComInput_SrlComLWhlSpdVld_Cnt_lgc = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_SrlComRWhlSpd_Hz_f32 Rte_Write_Ap_SrlComInput_SrlComRWhlSpd_Hz_f32
#  define Rte_Write_Ap_SrlComInput_SrlComRWhlSpd_Hz_f32(data) (Rte_SrlComInput_SrlComRWhlSpd_Hz_f32 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_SrlComRWhlSpdVld_Cnt_lgc Rte_Write_Ap_SrlComInput_SrlComRWhlSpdVld_Cnt_lgc
#  define Rte_Write_Ap_SrlComInput_SrlComRWhlSpdVld_Cnt_lgc(data) (Rte_SrlComInput_SrlComRWhlSpdVld_Cnt_lgc = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_SrlComVehSpd_Kph_f32 Rte_Write_Ap_SrlComInput_SrlComVehSpd_Kph_f32
#  define Rte_Write_Ap_SrlComInput_SrlComVehSpd_Kph_f32(data) (Rte_SrlComInput_SrlComVehSpd_Kph_f32 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_SrlComVehSpdValid_Cnt_lgc Rte_Write_Ap_SrlComInput_SrlComVehSpdValid_Cnt_lgc
#  define Rte_Write_Ap_SrlComInput_SrlComVehSpdValid_Cnt_lgc(data) (Rte_SrlComInput_SrlComVehSpdValid_Cnt_lgc = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_StrgWhlAngl_HwDeg_f32 Rte_Write_Ap_SrlComInput_StrgWhlAngl_HwDeg_f32
#  define Rte_Write_Ap_SrlComInput_StrgWhlAngl_HwDeg_f32(data) (Rte_SrlComInput_StrgWhlAngl_HwDeg_f32 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_StrgWhlAnglValid_Cnt_lgc Rte_Write_Ap_SrlComInput_StrgWhlAnglValid_Cnt_lgc
#  define Rte_Write_Ap_SrlComInput_StrgWhlAnglValid_Cnt_lgc(data) (Rte_SrlComInput_StrgWhlAnglValid_Cnt_lgc = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_TrqOvReverseGearEngage_Cnt_lgc Rte_Write_Ap_SrlComInput_TrqOvReverseGearEngage_Cnt_lgc
#  define Rte_Write_Ap_SrlComInput_TrqOvReverseGearEngage_Cnt_lgc(data) (Rte_SrlComInput_TrqOvReverseGearEngage_Cnt_lgc = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_VCBodyStyle_Cnt_u08 Rte_Write_Ap_SrlComInput_VCBodyStyle_Cnt_u08
#  define Rte_Write_Ap_SrlComInput_VCBodyStyle_Cnt_u08(data) (Rte_SrlComInput_VCBodyStyle_Cnt_u08 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_VCCountry_Cnt_u08 Rte_Write_Ap_SrlComInput_VCCountry_Cnt_u08
#  define Rte_Write_Ap_SrlComInput_VCCountry_Cnt_u08(data) (Rte_SrlComInput_VCCountry_Cnt_u08 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_VCModelYear_Cnt_u08 Rte_Write_Ap_SrlComInput_VCModelYear_Cnt_u08
#  define Rte_Write_Ap_SrlComInput_VCModelYear_Cnt_u08(data) (Rte_SrlComInput_VCModelYear_Cnt_u08 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_VCVehLine_Cnt_u08 Rte_Write_Ap_SrlComInput_VCVehLine_Cnt_u08
#  define Rte_Write_Ap_SrlComInput_VCVehLine_Cnt_u08(data) (Rte_SrlComInput_VCVehLine_Cnt_u08 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_VehAccel_KphpS_f32 Rte_Write_Ap_SrlComInput_VehAccel_KphpS_f32
#  define Rte_Write_Ap_SrlComInput_VehAccel_KphpS_f32(data) (RTE_E_OK)
#  define Rte_Write_VehAccelX_KphpS_f32 Rte_Write_Ap_SrlComInput_VehAccelX_KphpS_f32
#  define Rte_Write_Ap_SrlComInput_VehAccelX_KphpS_f32(data) (Rte_SrlComInput_VehAccelX_KphpS_f32 = (data), ((Std_ReturnType)RTE_E_OK))


/**********************************************************************************************************************
 * Rte_Mode_<p>_<m>
 *********************************************************************************************************************/
#  define Rte_Mode_SystemState_Mode() Rte_ModeMachine_Ap_StaMd9_SystemState9_Mode


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_AP_DIAGMGR9_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_AP_DIAGMGR9_APPL_CODE) NxtrDiagMgr9_GetNTCFailed(NTCNumber NTC_Cnt_T_enum, P2VAR(Boolean, AUTOMATIC, RTE_AP_DIAGMGR9_APPL_VAR) NTCFailed_Ptr_T_lgc);
#  define RTE_STOP_SEC_AP_DIAGMGR9_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_NxtrDiagMgr_GetNTCFailed NxtrDiagMgr9_GetNTCFailed
#  define RTE_START_SEC_AP_DIAGMGR9_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_AP_DIAGMGR9_APPL_CODE) NxtrDiagMgr9_GetNTCStatus(NTCNumber NTC_Cnt_T_enum, P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGMGR9_APPL_VAR) Status_Ptr_T_u08);
#  define RTE_STOP_SEC_AP_DIAGMGR9_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_NxtrDiagMgr_GetNTCStatus NxtrDiagMgr9_GetNTCStatus
#  define RTE_START_SEC_AP_DIAGMGR9_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_AP_DIAGMGR9_APPL_CODE) NxtrDiagMgr9_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);
#  define RTE_STOP_SEC_AP_DIAGMGR9_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_NxtrDiagMgr_SetNTCStatus NxtrDiagMgr9_SetNTCStatus
#  define RTE_START_SEC_WDGM_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_WDGM_APPL_CODE) WdgM_CheckpointReached(WdgM_SupervisedEntityIdType parg0, WdgM_CheckpointIdType parg1);
#  define RTE_STOP_SEC_WDGM_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_SrlComInput_Per1_CP0_CheckpointReached() (WdgM_CheckpointReached((WdgM_SupervisedEntityIdType)4, (WdgM_CheckpointIdType)0))
#  define RTE_START_SEC_NEXTEERLIBS_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_NEXTEERLIBS_APPL_CODE) DtrmnElapsedTime_mS_u16(UInt32 InitialTime, P2VAR(UInt16, AUTOMATIC, RTE_NEXTEERLIBS_APPL_VAR) ElapsedTime);
#  define RTE_STOP_SEC_NEXTEERLIBS_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(arg1, arg2) (DtrmnElapsedTime_mS_u16(arg1, arg2), ((Std_ReturnType)RTE_E_OK))
#  define RTE_START_SEC_NEXTEERLIBS_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_NEXTEERLIBS_APPL_CODE) DtrmnElapsedTime_mS_u32(UInt32 InitialTime, P2VAR(UInt32, AUTOMATIC, RTE_NEXTEERLIBS_APPL_VAR) ElapsedTime);
#  define RTE_STOP_SEC_NEXTEERLIBS_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_SystemTime_DtrmnElapsedTime_mS_u32(arg1, arg2) (DtrmnElapsedTime_mS_u32(arg1, arg2), ((Std_ReturnType)RTE_E_OK))
#  define RTE_START_SEC_NEXTEERLIBS_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_NEXTEERLIBS_APPL_CODE) GetSystemTime_mS_u32(P2VAR(UInt32, AUTOMATIC, RTE_NEXTEERLIBS_APPL_VAR) CurrentTime);
#  define RTE_STOP_SEC_NEXTEERLIBS_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_SystemTime_GetSystemTime_mS_u32(arg1) (GetSystemTime_mS_u32(arg1), ((Std_ReturnType)RTE_E_OK))


# endif /* !defined(RTE_CORE) */


# define RTE_START_SEC_AP_SRLCOMINPUT_APPL_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) FaultInjection_FltInjection(P2VAR(Float, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) SignalPath_Uls_f32, FltInjectionLocType LocationKey_Cnt_enum);

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) HaLFState_SCom_Transition(UInt8 State_Cnt_T_u08);

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) PrkAssistState_SCom_Transition(UInt8 State_Cnt_T_u08);

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_Init(void);

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_Per1(void);

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_SCom_ManualVehSpd(Float VehSpd_Kph_f32);

# define RTE_STOP_SEC_AP_SRLCOMINPUT_APPL_CODE
# include "MemMap.h"


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_NxtrDiagMgr_E_NOT_OK (1U)

#  define RTE_E_WdgM_CheckpointReached_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1468867288
#    error "The magic number of the generated file <C:/Sankar/Chrysler/Synergy/CL/Temp_work/Chrysler_LWR_EPS_TMS570/SwProject/Source/GenDataRte/Components/Rte_Ap_SrlComInput.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1468867288
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_AP_SRLCOMINPUT_H */
