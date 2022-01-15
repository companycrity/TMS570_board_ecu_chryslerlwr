/*****************************************************************************
* Copyright 2010 Nexteer Automotive, All Rights Reserved.
* Nexteer Confidential
*
* Module File Name  : CalConstants.h
* Module Description: This file contains the declarations of calibration 
*                     constants used in the EPS Software.
* Product           : Gen II Plus EA3.0
* Author            : Lucas Wendling
*****************************************************************************/
/* Version Control:
 * Date Created:      Wed Apr 13 12:17:00 2011
 * %version:          2 %
 * %derived_by:       rz3h1n %
 * %date_modified:    Fri Jul  6 14:02:11 2012 %
 *---------------------------------------------------------------------------------------------------------------------
 */

#ifndef CALCONSTANTS_H
#define CALCONSTANTS_H

#include "Rte_Type.h"
#include "fixmath.h"
#include "Filter_Types.h"

/*********************** Start of Auto Generated Code ************************/

/****************** File Generated on 7/6/2012 10:10:53 AM *******************/
/*************************** AbsHwPosScom - Rev 4 ****************************/


extern CONST(uint16, CAL_CONST) t_MtrPosComplTblX_MtrNm_u8p8[6];
extern CONST(uint16, CAL_CONST) t_MtrPosComplTblY_HwDegpMtrNm_u6p10[6];
extern CONST(float32, CAL_CONST) k_InvGearRatio_Uls_f32;
extern CONST(float32, CAL_CONST) k_AutoCtrPinTrqLPFCoeffK_Hz_f32;
extern CONST(float32, CAL_CONST) k_AutoCtrMtrVelT1L_MtrRadpS_f32;
extern CONST(float32, CAL_CONST) k_AutoCtrVehSpdT1L_Kph_f32;
extern CONST(float32, CAL_CONST) k_AutoCtrPinTrqT1L_HwNm_f32;
extern CONST(uint16, CAL_CONST) k_HwPTimer1MaxL_ms_u16;
extern CONST(float32, CAL_CONST) k_AutoCtrFiltOneCoeffkL_Hz_f32;
extern CONST(float32, CAL_CONST) k_AutoCtrWindowL_HwDeg_f32;
extern CONST(float32, CAL_CONST) k_AutoCtrFiltTwoCoeffkL_Hz_f32;
extern CONST(uint16, CAL_CONST) k_AutoCtrTimer2LSpd_ms_u16;
extern CONST(float32, CAL_CONST) k_HwPMtrVelT1H_MtrRadpS_f32;
extern CONST(float32, CAL_CONST) k_HwPVehSpdT1H_Kph_f32;
extern CONST(float32, CAL_CONST) k_HwPPinionTrqT1H_HwNm_f32;
extern CONST(uint16, CAL_CONST) k_HwPTimer1MaxH_ms_u16;
extern CONST(float32, CAL_CONST) k_HwPFilter1KnH_Hz_f32;
extern CONST(float32, CAL_CONST) k_HwPWindowCalH_HwDeg_f32;
extern CONST(float32, CAL_CONST) k_HwPFilter2KnH_Hz_f32;
extern CONST(uint16, CAL_CONST) k_HwPTmr2MaxHiSpd_ms_u16;
extern CONST(float32, CAL_CONST) k_MtrVelTmr4H_MtrRadpS_f32;
extern CONST(float32, CAL_CONST) k_VehSpdTmr4H_kph_f32;
extern CONST(float32, CAL_CONST) k_PinTrqTmr4H_HwNm_f32;
extern CONST(float32, CAL_CONST) k_Tmr4CntrWindowH_HwDeg_f32;
extern CONST(uint16, CAL_CONST) k_AutoCtrTimer4H_ms_u16;
extern CONST(float32, CAL_CONST) k_VDAuthL_Uls_f32;
extern CONST(float32, CAL_CONST) k_HiSpdAcAuth_Uls_f32;
extern CONST(float32, CAL_CONST) k_HwPosAuthorityStep_Uls_f32;
extern CONST(uint16, CAL_CONST) k_HwPosOpLPFCoeffK_Cnt_u16;
extern CONST(float32, CAL_CONST) k_HwPosOpLPFError_HwDeg_f32;
extern CONST(float32, CAL_CONST) k_KinmIntDiagMaxRackLmt_HwDeg_f32;
extern CONST(float32, CAL_CONST) k_RbstPosLPFKn_Hz_f32;
extern CONST(uint16, CAL_CONST) k_HwPosVehStabilityTime_mS_u16;
extern CONST(float32, CAL_CONST) k_ScomHwPosAuth_Uls_f32;
extern CONST(float32, CAL_CONST) k_HwPosVehStabilityHwTrq_HwNm_f32;
extern CONST(float32, CAL_CONST) k_HwPosVehStabilityTrqCmd_MtrNm_f32;
extern CONST(float32, CAL_CONST) k_HwPosVehStabilityMtrVel_MtrRadpS_f32;
extern CONST(float32, CAL_CONST) k_VdynToScomMaxErr_HwDeg_f32;
extern CONST(float32, CAL_CONST) k_VdynToSComCorrLmt_HwDeg_f32;
#endif
