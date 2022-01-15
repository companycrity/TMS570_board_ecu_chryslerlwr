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
 * %version:          5 %
 * %derived_by:       nzx5jd %
 * %date_modified:    Wed Oct 10 14:31:45 2012 %
 *---------------------------------------------------------------------------------------------------------------------
 */

#ifndef CALCONSTANTS_H
#define CALCONSTANTS_H

#include "Std_Types.h"

/*********************** Start of Auto Generated Code ************************/

/****************** File Generated on 2012-10-10 1:53:45 PM ******************/
/****************************** HwTrq - Rev 18 *******************************/


extern CONST(float32, CAL_CONST) k_TbarStiff_NmpDeg_f32;
extern CONST(DiagSettings_Str, CAL_CONST) k_AnaRngDiag_Cnt_str;
extern CONST(float32, CAL_CONST) k_T1HghRange_Volts_f32;
extern CONST(float32, CAL_CONST) k_T1LowRange_Volts_f32;
extern CONST(float32, CAL_CONST) k_T2HghRange_Volts_f32;
extern CONST(float32, CAL_CONST) k_T2LowRange_Volts_f32;
extern CONST(uint16, CAL_CONST) k_T1AccRecLim_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_T2AccRecLim_Cnt_u16;
extern CONST(float32, CAL_CONST) k_MaxTrqSumLmt_Volts_f32;
extern CONST(uint16, CAL_CONST) k_TdiagLim_Volts_u5p11;
extern CONST(uint16, CAL_CONST) k_CorrDiagFiltActiv_Volts_u5p11;
extern CONST(uint16, CAL_CONST) k_CorrDiagKn_Cnts_u16;
extern CONST(uint16, CAL_CONST) k_TdiagCorrLim_Volts_u5p11;
extern CONST(uint16, CAL_CONST) k_SSDiagKn_Cnts_u16;
extern CONST(uint16, CAL_CONST) k_SSDiagLim_Volts_u5p11;
extern CONST(uint16, CAL_CONST) t_TDiagFiltKnTbl_Cnt_u16[17];
extern CONST(uint16, CAL_CONST) k_SumFiltRecLim_Volt_u5p11;
extern CONST(uint16, CAL_CONST) k_SSFiltRecLim_Volt_u5p11;
extern CONST(uint16, CAL_CONST) t_TDiagIndptTbl_Volts_u5p11[17];
extern CONST(uint16, CAL_CONST) k_TrqFltRecLim_Cnt_u16;
extern CONST(float32, CAL_CONST) k_MaxHwTrqTrim_Volts_f32;
extern CONST(float32, CAL_CONST) k_HwTrqSclNom_VoltspDeg_f32;
extern CONST(uint16, CAL_CONST) k_AnaT1T2ErrThreshold_Volts_u5p11;
extern CONST(uint16, CAL_CONST) t_HwTorqCorrLimXAxis_HwNm_u4p12[6];
extern CONST(uint16, CAL_CONST) t_HwTorqCorrLimYAxis_HwNmSq_u7p9[6];
extern CONST(DiagSettings_Str, CAL_CONST) k_HwTorqCorrLimDiag_Cnt_str;
extern CONST(uint16, CAL_CONST) t_SysCHwTorqCorrLimXAxis_HwNm_u4p12[6];
extern CONST(uint16, CAL_CONST) t_SysCHwTorqCorrLimYAxis_HwNmSq_u7p9[6];
extern CONST(DiagSettings_Str, CAL_CONST) k_SysCHwTorqCorrLimDiag_Cnt_str;
#endif
