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
 * %version:          3 %
 * %derived_by:       sz1dx6 %
 * %date_modified:    Fri Apr 26 12:12:25 2013 %
 *---------------------------------------------------------------------------------------------------------------------
 */

#ifndef CALCONSTANTS_H
#define CALCONSTANTS_H

#include "Rte_Type.h"
#include "fixmath.h"
#include "filters.h"
#include "Ap_DiagMgr_Types.h"

#define D_NUMOFTUNSETS_CNT_U16 	10U
#define D_NUMOFPERS_CNT_U16 	3U

/* Put this at end of file
extern P2CONST(TUNING_P_Str, AUTOMATIC, AUTOMATIC) TunPer_Ptr_Str;
extern P2CONST(TUNING_Y_Str, AUTOMATIC, AUTOMATIC) TunSet_Ptr_Str;
extern CONSTP2CONST(TUNING_P_Str, AUTOMATIC, AUTOMATIC) T_TunPersSelectionTbl_Ptr_Str[D_NUMOFTUNSETS_CNT_U16][D_NUMOFPERS_CNT_U16];
extern CONSTP2CONST(TUNING_Y_Str, AUTOMATIC, AUTOMATIC) T_TunSetSelectionTbl_Ptr_Str[D_NUMOFTUNSETS_CNT_U16];
*/
/* Manually removed the macro for the k_CalID_Cnt_u16. This was required because the tuning sets/personalities needed to be
 * looped through to find the correct offset for the tuning set and personalities. *//* <- Remove this extra comment
#ifdef k_CalID_Cnt_u16
	#undef k_CalID_Cnt_u16
#endif
*/
/*********************** Start of Auto Generated Code ************************/

/****************** File Generated on 4/12/2013 1:09:09 PM *******************/
/*********************** Chrysler LWR Project - Rev 6 ************************/



/************* Tuning Structure Definition for "Y" Calibrations **************/

typedef struct
{
	uint16	t_MtrPosComplTblX_MtrNm_u8p8[6];
	uint16	t_MtrPosComplTblY_HwDegpMtrNm_u6p10[6];
	uint16	t_HwTrqDmpTblX_HwNm_u8p8[2];
	uint16	t_HwTrqDmpTblY_Uls_u1p15[2];
	sint16	t_TempScaleX_DegC_s8p7[14];
	uint16	t_TempScaleY_Uls_u4p12[14];
	Boolean	k_SoftStopEOTEnable_Cnt_lgc;
	uint16	k_EOTDefltPosition_HwDeg_u12p4;
	uint16	k_MinRackTrvl_HwDeg_u12p4;
	uint16	k_MaxRackTrvl_HwDeg_u12p4;
	uint16	k_EOTStateHwTrqLPFKn_Cnt_u16;
	uint16	k_EOTDeltaTrqThrsh_HwNm_u9p7;
	uint16	t_TrqTableX_HwNm_u8p8[2];
	float32	k_InrtCmp_MtrInertia_KgmSq_f32;
	uint16	t_InrtCmp_ScaleFactorTblY_Uls_u9p7[6];
	uint16	k_InrtCmp_TBarVelLPFKn_Cnt_u16;
	uint16	t_InrtCmp_TBarVel_ScaleFactorTblY_Uls_u9p7[6];
	float32	k_InrtCmp_MtrVel_ScaleFactor_Uls_f32;
	uint16	t_InrtCmp_VehSpdTblX_Kph_u15p1[6];
	uint16	t_FDD_ADDStaticTblY_MtrNmpRadpS_um1p17[24];
	uint16	t_FDD_ADDRollingTblYM_MtrNmpRadpS_um1p17[2][24];
	uint16	t_FDD_BlendTblY_Uls_u8p8[6];
	uint16	t_FDD_FreqTblYM_Hz_u12p4[2][6];
	uint16	t_FDD_AttenTblX_MtrRadpS_u12p4[2];
	uint16	t_FDD_AttenTblY_Uls_u8p8[2];
	float32	k_HysRevGain_InvHwNm_f32;
	uint16	k_LpFricIpLim_HwNm_u9p7;
	uint16	t_HysSpdTblX_Kph_u9p7[8];
	uint16	t_EffLossTblY_Uls_u4p12[8];
	uint16	t_EffOffTblY_HwNm_u9p7[8];
	float32	k_MtrNmPerHwNm_Uls_f32;
	uint16	t_HysCompCoulFricY_HwNm_u9p7[2][8];
	sint16	t_HysCompCoulFricTempScaleX_DegC_s14p1[8];
	uint16	t_HysCompCoulFricTempScaleY_HwNm_u9p7[8];
	uint16	t_HysCompHysSatY_HwNm_u9p7[8];
	uint16	t_HysCompCoulFricWIRBlendX_MtrNm_u8p8[6];
	uint16	t_HysCompCoulFricWIRBlendY_Uls_u2p14[6];
	uint16	t_HysCompNegHysCompX_MtrNm_u8p8[8];
	uint16	t_HysCompNegHysCompY_HwNm_u9p7[8];
	uint16	t_HysCompNegHysBlendX_HwNm_u9p7[5];
	uint16	t_HysCompNegHysBlendY_Uls_u2p14[5];
	float32	k_MinRackTrvl_HwDeg_f32;
	float32	k_MaxRackTrvl_HwDeg_f32;
	sint16	t_ReturnTempScaleXTbl_DegC_s11p4[14];
	uint16	t_ReturnTempScaleSclYTbl_Uls_u8p8[14];
	uint16	t_StCmpADDFBlendX_Uls_u2p14[2];
	uint16	t_StCmpADDFBlendY_Uls_u2p14[2];
	NotchFiltK_Str	t_StCmpNFK_Str[4];
	uint16	k_HwPosOpLPFCoeffK_Cnt_u16;
	float32	k_AsstFWInpLimitHysComp_MtrNm_f32;
	float32	k_AsstFWInpLimitHFA_MtrNm_f32;
	float32	k_AsstFWInpLimitBaseAsst_MtrNm_f32;
	float32	k_AsstFWFiltKn_Hz_f32;
	float32	k_AsstFWFWActiveLPF_Hz_f32;
	uint16	t_AsstFWVehSpd_Kph_u9p7[8];
	sint16	t2_AsstFWUprBoundX_HwNm_s4p11[8][16];
	sint16	t2_AsstFWUprBoundY_MtrNm_s4p11[8][16];
	sint16	t2_AsstFWLwrBoundX_HwNm_s4p11[8][16];
	sint16	t2_AsstFWLwrBoundY_MtrNm_s4p11[8][16];
	uint16	k_AsstFWPstep_Cnt_u16;
	uint16	k_AsstFWNstep_Cnt_u16;
	uint16	t_AsstFWPstepNstepThresh_Cnt_u16[2];
	float32	k_DampFWInpLimitDamp_MtrNm_f32;
	float32	k_DampFWFilkKn_Hz_f32;
	float32	k_DampFWFWActiveLPF_Hz_f32;
	float32	k_DampFWMtrVelScale_Uls_f32;
	float32	k_DampFWTbarVelLPFKn_Hz_f32;
	uint16	t_DampFWAddDampAFWX_MtrRadpS_u10p6[8];
	uint16	t_DampFWAddDampAFWY_MtrNm_u5p11[8];
	uint16	t_DampFWAddDampDFWX_MtrRadpS_u10p6[8];
	uint16	t_DampFWAddDampDFWY_MtrNm_u5p11[8];
	uint16	t_DampFWEstCompGain_MtrNmpMtrRadpS_u1p15[6];
	uint16	t_DampFWEstCompHPF_Hz_u7p9[6];
	uint16	t_DampFWEstCompTblX_Kph_u9p7[6];
	uint16	t_DampFWTbarVelScaleY_Uls_u2p14[6];
	uint16	t_DampFWVehSpd_Kph_u9p7[8];
	sint16	t2_DampFWLwrBoundX_MtrRadpS_s10p5[8][16];
	sint16	t2_DampFWLwrBoundY_MtrNm_s7p8[8][16];
	sint16	t2_DampFWUprBoundX_MtrRadpS_s10p5[8][16];
	sint16	t2_DampFWUprBoundY_MtrNm_s7p8[8][16];
	float32	k_HysCmpLPAstLPFKn_Hz_f32;
	float32	k_HysCmpHwTrqLPFKn_Hz_f32;
	float32	k_HysFinalOutLPFKn_Hz_f32;
	float32	k_HysOutLIm_HwNm_f32;
	float32	k_MtrVelEOTLrn_MtrRadpS_f32;
	uint16	k_EOTLrnTimer_mS_u16;
	float32	k_AuthorityStartLrn_Uls_f32;
	float32	k_HwTrqEOTLrn_HwNm_f32;
	float32	k_MinResetAuthority_Uls_f32;
	uint16	t_RtrnFWVehSpd_Kph_u9p7[8];
	sint16	t2_RtrnFWUprBoundX_HwDeg_s10p5[8][16];
	sint16	t2_RtrnFWUprBoundY_MtrNm_s4p11[8][16];
	sint16	t2_RtrnFWLwrBoundX_HwDeg_s10p5[8][16];
	sint16	t2_RtrnFWLwrBoundY_MtrNm_s4p11[8][16];
	float32	k_YawRateFilt_Hz_f32;
	float32	k_HwTrqFilt_Hz_f32;
	float32	k_STResetHwTrq_HwNm_f32;
	float32	k_STResetHwPos_HwDeg_f32;
	float32	k_STResetYawRate_DegpS_f32;
	float32	k_EnableHwTrqMax_HwNm_f32;
	float32	k_EnableHwPosMax_HwDeg_f32;
	float32	k_EnableHwAuthMin_Uls_f32;
	float32	k_EnableHwVelMax_DegpS_f32;
	float32	k_EnableVehSpdRateMax_KphpS_f32;
	float32	k_EnableVehSpdMin_Kph_f32;
	float32	k_EnableVehSpdMax_Kph_f32;
	float32	k_EnableYawRateMax_DegpS_f32;
	uint32	k_EnableTime_mS_u32;
	float32	k_STLimit_HwNm_f32;
	float32	k_STLearnTimeInc_Sec_f32;
	float32	k_STLearnTimeDec_Sec_f32;
	uint32	k_STOppSignTime_mS_u32;
	float32	k_STRampTime_Sec_f32;
	float32	k_STIntInputLimit_HwNm_f32;
	float32	k_STFilt_Hz_f32;
	float32	k_FiltDeadband_HwNm_f32;
	float32	k_LTLimit_HwNm_f32;
	float32	k_LTLearnTime_Min_f32;
	float32	k_LTFilt_Hz_f32;
	float32	k_LTIntInputLimit_HwNm_f32;
	float32	k_TotalLimit_HwNm_f32;
	float32	k_HwNmToMtrNm_Uls_f32;
	uint16	t_VehSpdScaleTblX_Kph_u9p7[4];
	uint16	t_VehSpdScaleTblY_Uls_u1p15[4];
	float32	k_OutputMaxRate_HwNmpS_f32;
	float32	k_PPPAPriorityVehSpd_Kph_f32;
	float32	k_RateLimit_UlspS_f32;
	float32	k_Quad13DmpMult_Uls_f32;
	float32	k_Quad24DmpMult_Uls_f32;
	uint16	t_AsstFWDefltAssistX_HwNm_u8p8[32];
	sint16	t_AsstFWDefltAssistY_MtrNm_s4p11[32];
	float32	k_RestoreThresh_MtrNm_f32;
	uint16	t_DampFWDefltDampX_MtrRadpS_u10p6[32];
	uint16	t_DampFWDefltDampY_MtrNm_u5p11[32];
	uint16	k_DampFWPstep_Cnt_u16;
	uint16	k_DampFWNstep_Cnt_u16;
	uint16	t_DampFWPNstepThresh_Cnt_u16[2];
	float32	k_InrtCmp_TBarVelLPFKn_Hz_f32;
	uint16	k_DampFWInCmpPStep_Cnt_u16;
	uint16	k_DampFWInCmpNStep_Cnt_u16;
	uint16	t_DampFWDampInrtCmpPNThesh_Cnt_u16[2];
	float32	k_DampFWErrThresh_MtrNm_f32;
	uint16	t_StCmpBlend12SpdBS_Kph_u9p7[8];
	uint16	t_StCmpBlend12Trq_HwNm_u8p8[6];
	uint16	t2_StCmpBlend12TblY_Uls_u2p14[8][6];
	uint16	t2_StCmpBlend02TblY_Uls_u2p14[8][6];
	uint16	t_StCmpBlend34SpdBS_Kph_u9p7[8];
	uint16	t_StCmpBlend34Trq_HwNm_u8p8[6];
	uint16	t2_StCmpBlend34TblY_Uls_u2p14[8][6];
	uint16	t2_StCmpBlend04TblY_Uls_u2p14[8][6];
	float32	k_StCmpHwTrqLPFKn_Hz_f32;
	uint16	t2_HysHwTrqBlndTblX_HwNm_u4p12[8][10];
	uint16	t2_HysHwTrqBlndTblY_Uls_u4p12[8][10];
	uint16	t_HysRiseTblX_HwNm_u2p14[6];
	uint16	t_HysRiseTblY_Uls_u2p14[6];
	float32	t_FrHystHwAPts_HwDeg_f32[4];
	float32	t2_VehSpd_Kph_f32[4][2];
	boolean	t_MskVehSpd_Cnt_lgc[4];
	float32	t_FricChgWeight_Uls_f32[4];
	uint16	t_InvRatioX_HwDeg_u11p5[10];
	uint16	t_InvRatioY_HwNmpMtrNm_u6p10[10];
	float32	k_LearningGain_Uls_f32;
	uint32	k_LearningThreshold_Cnt_u32;
	uint16	k_RangeCounterLimit_Cnt_u16;
	float32	k_AvgFricLPFKn_Hz_f32;
	float32	k_HwPosAuthMin_Uls_f32;
	float32	k_HwVelConstLimit_HwDegpS_f32;
	float32	k_HwVelMax_HwDegpS_f32;
	float32	k_HwVelMin_HwDegpS_f32;
	float32	k_LatAccMax_MpSecSqrd_f32;
	float32	k_LatAccMin_MpSecSqrd_f32;
	float32	k_SatFricChgLim_HwNm_f32;
	float32	k_FricOffsetLPFKn_Hz_f32;
	float32	k_TempMin_DegC_f32;
	float32	k_TempMax_DegC_f32;
	float32	k_DataPrepLPFKn_Hz_f32;
	float32	k_IgnCycleFricChgLim_HwNm_f32;
	float32	k_FricOffsetLimitLow_HwNm_f32;
	float32	k_FricOffsetLimitHigh_HwNm_f32;
	float32	t2_BaselineTheta_HwNm_f32[8][4];
	uint16	t2_BaselineRangeCounter_Cnt_u16[8][3];
	float32	t_BaselineFric_HwNm_f32[4];
	float32	k_BaselineEOLFric_HwNm_f32;
	float32	k_EOLFricDiffScalingFactor_Uls_f32;
	float32	k_EOLFricDiffLimitLow_HwNm_f32;
	float32	k_EOLFricDiffLimitHigh_HwNm_f32;

} TUNING_Y_Str;

/************* Tuning Structure Definition for "P" Calibrations **************/

typedef struct
{
	uint16	t2_AsstHwtX0_HwNm_u8p8[16][32];
	uint16	t2_AsstHwtX1_HwNm_u8p8[16][32];
	sint16	t2_AsstAsstY0_MtrNm_s4p11[16][32];
	sint16	t2_AsstAsstY1_MtrNm_s4p11[16][32];
	uint16	t_AsstSpeed_Kph_u9p7[16];
	uint16	t2_AsstWIRBlndX_MtrNm_u5p11[16][5];
	uint16	t2_AsstWIRBlendY_Uls_u2p14[16][5];
	uint16	t2_MtrVelDmpTblX_MtrRadpS_u12p4[16][32];
	uint16	t2_MtrVelDmpTblY_MtrNm_u5p11[16][32];
	uint16	t_VSpdDmpTblBS_Kph_u9p7[16];
	uint16	t_HPSscaleC1Y_Uls_u4p12[16];
	uint16	t_HPSscaleC2Y_Uls_u4p12[16];
	uint16	t_HPSscaleC3Y_Uls_u4p12[16];
	uint16	t_HPSscaleC4Y_Uls_u4p12[16];
	uint16	t_HPSAsstLimY_MtrNm_u4p12[16];
	float32	k_HPSOutLimit_MtrNm_f32;
	uint16	t_SpdIptTblXTbl_HwDeg_u12p4[2];
	uint16	t_SpdIptTblYTbl_MtrRadpS_u12p4[2];
	uint16	k_SpdIptScale_MtrNmpRadpS_u4p12;
	uint16	k_PosRampStep_HwDeg_u12p4;
	uint16	t2_EOTEnterGainX_HwDeg_u12p4[4][4];
	uint16	t2_EOTEnterGainY_Uls_u1p15[4][4];
	uint16	t_EOTEnterGainVspd_Kph_u9p7[4];
	uint16	k_EOTEnterLPFKn_Cnt_u16;
	uint16	k_EOTExitLPFKn_Cnt_u16;
	uint16	t2_EOTPosDepDmpTblX_HwDeg_u12p4[4][2];
	uint16	t2_EOTPosDepDmpTblY_MtrNmpRadpS_u5p11[4][2];
	uint16	t2_EOTExPosDepDmpTblY_MtrNmpRadps_u5p11[4][2];
	uint16	t_EOTDmpVspd_Kph_u9p7[4];
	uint16	t_WIRBlndTblX_MtrNm_u8p8[5];
	uint16	t_RIAstWIRBlndTblY_Uls_u2p14[5];
	uint16	t_DmpFiltKpWIRBlndY_Uls_u2p14[5];
	uint16	t_LPFKnX_Kph_u9p7[6];
	uint16	t2_LPFKnY_Cnt_u16[2][6];
	uint16	t_KnWIRBlndX_MtrNm_u4p12[5];
	uint16	t_KnWIRBlndY_Uls_u1p15[5];
	uint16	t_Speed_Kph_u9p7[16];
	uint16	t2_TorqX0_HwNm_u5p11[16][32];
	uint16	t2_TorqX1_HwNm_u5p11[16][32];
	uint16	t2_GainY0_MtrNmpHwNm_u3p13[16][32];
	uint16	t2_GainY1_MtrNmpHwNm_u3p13[16][32];
	uint16	t2_WIRBlendX_MtrNm_u4p12[16][5];
	uint16	t2_WIRBlendY_Uls_u1p15[16][5];
	uint16	t_ReturnVSpdTblBS_Kph_u9p7[9];
	uint16	t2_ReturnPosTblXM_HwDeg_u12p4[9][16];
	uint16	t2_ReturnPosTblYM_MtrNm_u5p11[9][16];
	uint16	t2_ReturnSclTrqTblXM_HwNm_T_u8p8[9][8];
	uint16	t2_ReturnSclTrqTblYM_Uls_u8p8[9][8];
	uint16	t2_ReturnSclVelTblXM_HwRadpS_T_u7p9[9][4];
	uint16	t2_ReturnSclVelTblYM_Uls_u8p8[9][4];
	uint16	t_AsstThermSclX_Cnt_u16p0[2];
	uint16	t_AsstThermSclY_Uls_u2p14[2];

} TUNING_P_Str;


/********************* AbsHwPos, My_LWR_WA, My_ePWM_LWR **********************/
#define t_MtrPosComplTblX_MtrNm_u8p8	TunSet_Ptr_Str->t_MtrPosComplTblX_MtrNm_u8p8
#define t_MtrPosComplTblY_HwDegpMtrNm_u6p10	TunSet_Ptr_Str->t_MtrPosComplTblY_HwDegpMtrNm_u6p10

/********************************** Damping **********************************/
#define t_HwTrqDmpTblX_HwNm_u8p8	TunSet_Ptr_Str->t_HwTrqDmpTblX_HwNm_u8p8
#define t_HwTrqDmpTblY_Uls_u1p15	TunSet_Ptr_Str->t_HwTrqDmpTblY_Uls_u1p15
#define t_TempScaleX_DegC_s8p7	TunSet_Ptr_Str->t_TempScaleX_DegC_s8p7
#define t_TempScaleY_Uls_u4p12	TunSet_Ptr_Str->t_TempScaleY_Uls_u4p12

/****************************** EOTActuatorMng *******************************/
#define k_SoftStopEOTEnable_Cnt_lgc	TunSet_Ptr_Str->k_SoftStopEOTEnable_Cnt_lgc
#define k_EOTDefltPosition_HwDeg_u12p4	TunSet_Ptr_Str->k_EOTDefltPosition_HwDeg_u12p4
#define k_MinRackTrvl_HwDeg_u12p4	TunSet_Ptr_Str->k_MinRackTrvl_HwDeg_u12p4
#define k_MaxRackTrvl_HwDeg_u12p4	TunSet_Ptr_Str->k_MaxRackTrvl_HwDeg_u12p4
#define k_EOTStateHwTrqLPFKn_Cnt_u16	TunSet_Ptr_Str->k_EOTStateHwTrqLPFKn_Cnt_u16
#define k_EOTDeltaTrqThrsh_HwNm_u9p7	TunSet_Ptr_Str->k_EOTDeltaTrqThrsh_HwNm_u9p7
#define t_TrqTableX_HwNm_u8p8	TunSet_Ptr_Str->t_TrqTableX_HwNm_u8p8

/******************** FrqDepDmpnInrtCmp, DampingFirewall *********************/
#define k_InrtCmp_MtrInertia_KgmSq_f32	TunSet_Ptr_Str->k_InrtCmp_MtrInertia_KgmSq_f32
#define t_InrtCmp_ScaleFactorTblY_Uls_u9p7	TunSet_Ptr_Str->t_InrtCmp_ScaleFactorTblY_Uls_u9p7

/***************************** FrqDepDmpnInrtCmp *****************************/
#define k_InrtCmp_TBarVelLPFKn_Cnt_u16	TunSet_Ptr_Str->k_InrtCmp_TBarVelLPFKn_Cnt_u16

/******************** FrqDepDmpnInrtCmp, DampingFirewall *********************/
#define t_InrtCmp_TBarVel_ScaleFactorTblY_Uls_u9p7	TunSet_Ptr_Str->t_InrtCmp_TBarVel_ScaleFactorTblY_Uls_u9p7
#define k_InrtCmp_MtrVel_ScaleFactor_Uls_f32	TunSet_Ptr_Str->k_InrtCmp_MtrVel_ScaleFactor_Uls_f32
#define t_InrtCmp_VehSpdTblX_Kph_u15p1	TunSet_Ptr_Str->t_InrtCmp_VehSpdTblX_Kph_u15p1
#define t_FDD_ADDStaticTblY_MtrNmpRadpS_um1p17	TunSet_Ptr_Str->t_FDD_ADDStaticTblY_MtrNmpRadpS_um1p17
#define t_FDD_ADDRollingTblYM_MtrNmpRadpS_um1p17	TunSet_Ptr_Str->t_FDD_ADDRollingTblYM_MtrNmpRadpS_um1p17
#define t_FDD_BlendTblY_Uls_u8p8	TunSet_Ptr_Str->t_FDD_BlendTblY_Uls_u8p8
#define t_FDD_FreqTblYM_Hz_u12p4	TunSet_Ptr_Str->t_FDD_FreqTblYM_Hz_u12p4
#define t_FDD_AttenTblX_MtrRadpS_u12p4	TunSet_Ptr_Str->t_FDD_AttenTblX_MtrRadpS_u12p4
#define t_FDD_AttenTblY_Uls_u8p8	TunSet_Ptr_Str->t_FDD_AttenTblY_Uls_u8p8

/********************************* HystComp **********************************/
#define k_HysRevGain_InvHwNm_f32	TunSet_Ptr_Str->k_HysRevGain_InvHwNm_f32
#define k_LpFricIpLim_HwNm_u9p7	TunSet_Ptr_Str->k_LpFricIpLim_HwNm_u9p7
#define t_HysSpdTblX_Kph_u9p7	TunSet_Ptr_Str->t_HysSpdTblX_Kph_u9p7
#define t_EffLossTblY_Uls_u4p12	TunSet_Ptr_Str->t_EffLossTblY_Uls_u4p12
#define t_EffOffTblY_HwNm_u9p7	TunSet_Ptr_Str->t_EffOffTblY_HwNm_u9p7
#define k_MtrNmPerHwNm_Uls_f32	TunSet_Ptr_Str->k_MtrNmPerHwNm_Uls_f32
#define t_HysCompCoulFricY_HwNm_u9p7	TunSet_Ptr_Str->t_HysCompCoulFricY_HwNm_u9p7
#define t_HysCompCoulFricTempScaleX_DegC_s14p1	TunSet_Ptr_Str->t_HysCompCoulFricTempScaleX_DegC_s14p1
#define t_HysCompCoulFricTempScaleY_HwNm_u9p7	TunSet_Ptr_Str->t_HysCompCoulFricTempScaleY_HwNm_u9p7
#define t_HysCompHysSatY_HwNm_u9p7	TunSet_Ptr_Str->t_HysCompHysSatY_HwNm_u9p7
#define t_HysCompCoulFricWIRBlendX_MtrNm_u8p8	TunSet_Ptr_Str->t_HysCompCoulFricWIRBlendX_MtrNm_u8p8
#define t_HysCompCoulFricWIRBlendY_Uls_u2p14	TunSet_Ptr_Str->t_HysCompCoulFricWIRBlendY_Uls_u2p14
#define t_HysCompNegHysCompX_MtrNm_u8p8	TunSet_Ptr_Str->t_HysCompNegHysCompX_MtrNm_u8p8
#define t_HysCompNegHysCompY_HwNm_u9p7	TunSet_Ptr_Str->t_HysCompNegHysCompY_HwNm_u9p7
#define t_HysCompNegHysBlendX_HwNm_u9p7	TunSet_Ptr_Str->t_HysCompNegHysBlendX_HwNm_u9p7
#define t_HysCompNegHysBlendY_Uls_u2p14	TunSet_Ptr_Str->t_HysCompNegHysBlendY_Uls_u2p14

/********************************** LrnEOT ***********************************/
#define k_MinRackTrvl_HwDeg_f32	TunSet_Ptr_Str->k_MinRackTrvl_HwDeg_f32
#define k_MaxRackTrvl_HwDeg_f32	TunSet_Ptr_Str->k_MaxRackTrvl_HwDeg_f32

/********************************** Return ***********************************/
#define t_ReturnTempScaleXTbl_DegC_s11p4	TunSet_Ptr_Str->t_ReturnTempScaleXTbl_DegC_s11p4
#define t_ReturnTempScaleSclYTbl_Uls_u8p8	TunSet_Ptr_Str->t_ReturnTempScaleSclYTbl_Uls_u8p8

/******************************* StabilityComp *******************************/
#define t_StCmpADDFBlendX_Uls_u2p14	TunSet_Ptr_Str->t_StCmpADDFBlendX_Uls_u2p14
#define t_StCmpADDFBlendY_Uls_u2p14	TunSet_Ptr_Str->t_StCmpADDFBlendY_Uls_u2p14
#define t_StCmpNFK_Str	TunSet_Ptr_Str->t_StCmpNFK_Str

/******************************* AbsHwPosScom ********************************/
#define k_HwPosOpLPFCoeffK_Cnt_u16	TunSet_Ptr_Str->k_HwPosOpLPFCoeffK_Cnt_u16

/****************************** AssistFirewall *******************************/
#define k_AsstFWInpLimitHysComp_MtrNm_f32	TunSet_Ptr_Str->k_AsstFWInpLimitHysComp_MtrNm_f32
#define k_AsstFWInpLimitHFA_MtrNm_f32	TunSet_Ptr_Str->k_AsstFWInpLimitHFA_MtrNm_f32
#define k_AsstFWInpLimitBaseAsst_MtrNm_f32	TunSet_Ptr_Str->k_AsstFWInpLimitBaseAsst_MtrNm_f32
#define k_AsstFWFiltKn_Hz_f32	TunSet_Ptr_Str->k_AsstFWFiltKn_Hz_f32
#define k_AsstFWFWActiveLPF_Hz_f32	TunSet_Ptr_Str->k_AsstFWFWActiveLPF_Hz_f32
#define t_AsstFWVehSpd_Kph_u9p7	TunSet_Ptr_Str->t_AsstFWVehSpd_Kph_u9p7
#define t2_AsstFWUprBoundX_HwNm_s4p11	TunSet_Ptr_Str->t2_AsstFWUprBoundX_HwNm_s4p11
#define t2_AsstFWUprBoundY_MtrNm_s4p11	TunSet_Ptr_Str->t2_AsstFWUprBoundY_MtrNm_s4p11
#define t2_AsstFWLwrBoundX_HwNm_s4p11	TunSet_Ptr_Str->t2_AsstFWLwrBoundX_HwNm_s4p11
#define t2_AsstFWLwrBoundY_MtrNm_s4p11	TunSet_Ptr_Str->t2_AsstFWLwrBoundY_MtrNm_s4p11
#define k_AsstFWPstep_Cnt_u16	TunSet_Ptr_Str->k_AsstFWPstep_Cnt_u16
#define k_AsstFWNstep_Cnt_u16	TunSet_Ptr_Str->k_AsstFWNstep_Cnt_u16
#define t_AsstFWPstepNstepThresh_Cnt_u16	TunSet_Ptr_Str->t_AsstFWPstepNstepThresh_Cnt_u16

/****************************** DampingFirewall ******************************/
#define k_DampFWInpLimitDamp_MtrNm_f32	TunSet_Ptr_Str->k_DampFWInpLimitDamp_MtrNm_f32
#define k_DampFWFilkKn_Hz_f32	TunSet_Ptr_Str->k_DampFWFilkKn_Hz_f32
#define k_DampFWFWActiveLPF_Hz_f32	TunSet_Ptr_Str->k_DampFWFWActiveLPF_Hz_f32
#define k_DampFWMtrVelScale_Uls_f32	TunSet_Ptr_Str->k_DampFWMtrVelScale_Uls_f32
#define k_DampFWTbarVelLPFKn_Hz_f32	TunSet_Ptr_Str->k_DampFWTbarVelLPFKn_Hz_f32
#define t_DampFWAddDampAFWX_MtrRadpS_u10p6	TunSet_Ptr_Str->t_DampFWAddDampAFWX_MtrRadpS_u10p6
#define t_DampFWAddDampAFWY_MtrNm_u5p11	TunSet_Ptr_Str->t_DampFWAddDampAFWY_MtrNm_u5p11
#define t_DampFWAddDampDFWX_MtrRadpS_u10p6	TunSet_Ptr_Str->t_DampFWAddDampDFWX_MtrRadpS_u10p6
#define t_DampFWAddDampDFWY_MtrNm_u5p11	TunSet_Ptr_Str->t_DampFWAddDampDFWY_MtrNm_u5p11
#define t_DampFWEstCompGain_MtrNmpMtrRadpS_u1p15	TunSet_Ptr_Str->t_DampFWEstCompGain_MtrNmpMtrRadpS_u1p15
#define t_DampFWEstCompHPF_Hz_u7p9	TunSet_Ptr_Str->t_DampFWEstCompHPF_Hz_u7p9
#define t_DampFWEstCompTblX_Kph_u9p7	TunSet_Ptr_Str->t_DampFWEstCompTblX_Kph_u9p7
#define t_DampFWTbarVelScaleY_Uls_u2p14	TunSet_Ptr_Str->t_DampFWTbarVelScaleY_Uls_u2p14
#define t_DampFWVehSpd_Kph_u9p7	TunSet_Ptr_Str->t_DampFWVehSpd_Kph_u9p7
#define t2_DampFWLwrBoundX_MtrRadpS_s10p5	TunSet_Ptr_Str->t2_DampFWLwrBoundX_MtrRadpS_s10p5
#define t2_DampFWLwrBoundY_MtrNm_s7p8	TunSet_Ptr_Str->t2_DampFWLwrBoundY_MtrNm_s7p8
#define t2_DampFWUprBoundX_MtrRadpS_s10p5	TunSet_Ptr_Str->t2_DampFWUprBoundX_MtrRadpS_s10p5
#define t2_DampFWUprBoundY_MtrNm_s7p8	TunSet_Ptr_Str->t2_DampFWUprBoundY_MtrNm_s7p8

/********************************* HystComp **********************************/
#define k_HysCmpLPAstLPFKn_Hz_f32	TunSet_Ptr_Str->k_HysCmpLPAstLPFKn_Hz_f32
#define k_HysCmpHwTrqLPFKn_Hz_f32	TunSet_Ptr_Str->k_HysCmpHwTrqLPFKn_Hz_f32
#define k_HysFinalOutLPFKn_Hz_f32	TunSet_Ptr_Str->k_HysFinalOutLPFKn_Hz_f32
#define k_HysOutLIm_HwNm_f32	TunSet_Ptr_Str->k_HysOutLIm_HwNm_f32

/********************************** LrnEOT ***********************************/
#define k_MtrVelEOTLrn_MtrRadpS_f32	TunSet_Ptr_Str->k_MtrVelEOTLrn_MtrRadpS_f32
#define k_EOTLrnTimer_mS_u16	TunSet_Ptr_Str->k_EOTLrnTimer_mS_u16
#define k_AuthorityStartLrn_Uls_f32	TunSet_Ptr_Str->k_AuthorityStartLrn_Uls_f32
#define k_HwTrqEOTLrn_HwNm_f32	TunSet_Ptr_Str->k_HwTrqEOTLrn_HwNm_f32
#define k_MinResetAuthority_Uls_f32	TunSet_Ptr_Str->k_MinResetAuthority_Uls_f32

/****************************** ReturnFirewall *******************************/
#define t_RtrnFWVehSpd_Kph_u9p7	TunSet_Ptr_Str->t_RtrnFWVehSpd_Kph_u9p7
#define t2_RtrnFWUprBoundX_HwDeg_s10p5	TunSet_Ptr_Str->t2_RtrnFWUprBoundX_HwDeg_s10p5
#define t2_RtrnFWUprBoundY_MtrNm_s4p11	TunSet_Ptr_Str->t2_RtrnFWUprBoundY_MtrNm_s4p11
#define t2_RtrnFWLwrBoundX_HwDeg_s10p5	TunSet_Ptr_Str->t2_RtrnFWLwrBoundX_HwDeg_s10p5
#define t2_RtrnFWLwrBoundY_MtrNm_s4p11	TunSet_Ptr_Str->t2_RtrnFWLwrBoundY_MtrNm_s4p11

/******************************** ActivePull *********************************/
#define k_YawRateFilt_Hz_f32	TunSet_Ptr_Str->k_YawRateFilt_Hz_f32
#define k_HwTrqFilt_Hz_f32	TunSet_Ptr_Str->k_HwTrqFilt_Hz_f32
#define k_STResetHwTrq_HwNm_f32	TunSet_Ptr_Str->k_STResetHwTrq_HwNm_f32
#define k_STResetHwPos_HwDeg_f32	TunSet_Ptr_Str->k_STResetHwPos_HwDeg_f32
#define k_STResetYawRate_DegpS_f32	TunSet_Ptr_Str->k_STResetYawRate_DegpS_f32
#define k_EnableHwTrqMax_HwNm_f32	TunSet_Ptr_Str->k_EnableHwTrqMax_HwNm_f32
#define k_EnableHwPosMax_HwDeg_f32	TunSet_Ptr_Str->k_EnableHwPosMax_HwDeg_f32
#define k_EnableHwAuthMin_Uls_f32	TunSet_Ptr_Str->k_EnableHwAuthMin_Uls_f32
#define k_EnableHwVelMax_DegpS_f32	TunSet_Ptr_Str->k_EnableHwVelMax_DegpS_f32
#define k_EnableVehSpdRateMax_KphpS_f32	TunSet_Ptr_Str->k_EnableVehSpdRateMax_KphpS_f32
#define k_EnableVehSpdMin_Kph_f32	TunSet_Ptr_Str->k_EnableVehSpdMin_Kph_f32
#define k_EnableVehSpdMax_Kph_f32	TunSet_Ptr_Str->k_EnableVehSpdMax_Kph_f32
#define k_EnableYawRateMax_DegpS_f32	TunSet_Ptr_Str->k_EnableYawRateMax_DegpS_f32
#define k_EnableTime_mS_u32	TunSet_Ptr_Str->k_EnableTime_mS_u32
#define k_STLimit_HwNm_f32	TunSet_Ptr_Str->k_STLimit_HwNm_f32
#define k_STLearnTimeInc_Sec_f32	TunSet_Ptr_Str->k_STLearnTimeInc_Sec_f32
#define k_STLearnTimeDec_Sec_f32	TunSet_Ptr_Str->k_STLearnTimeDec_Sec_f32
#define k_STOppSignTime_mS_u32	TunSet_Ptr_Str->k_STOppSignTime_mS_u32
#define k_STRampTime_Sec_f32	TunSet_Ptr_Str->k_STRampTime_Sec_f32
#define k_STIntInputLimit_HwNm_f32	TunSet_Ptr_Str->k_STIntInputLimit_HwNm_f32
#define k_STFilt_Hz_f32	TunSet_Ptr_Str->k_STFilt_Hz_f32
#define k_FiltDeadband_HwNm_f32	TunSet_Ptr_Str->k_FiltDeadband_HwNm_f32
#define k_LTLimit_HwNm_f32	TunSet_Ptr_Str->k_LTLimit_HwNm_f32
#define k_LTLearnTime_Min_f32	TunSet_Ptr_Str->k_LTLearnTime_Min_f32
#define k_LTFilt_Hz_f32	TunSet_Ptr_Str->k_LTFilt_Hz_f32
#define k_LTIntInputLimit_HwNm_f32	TunSet_Ptr_Str->k_LTIntInputLimit_HwNm_f32
#define k_TotalLimit_HwNm_f32	TunSet_Ptr_Str->k_TotalLimit_HwNm_f32
#define k_HwNmToMtrNm_Uls_f32	TunSet_Ptr_Str->k_HwNmToMtrNm_Uls_f32
#define t_VehSpdScaleTblX_Kph_u9p7	TunSet_Ptr_Str->t_VehSpdScaleTblX_Kph_u9p7
#define t_VehSpdScaleTblY_Uls_u1p15	TunSet_Ptr_Str->t_VehSpdScaleTblY_Uls_u1p15
#define k_OutputMaxRate_HwNmpS_f32	TunSet_Ptr_Str->k_OutputMaxRate_HwNmpS_f32

/********************************** ArbLmt ***********************************/
#define k_PPPAPriorityVehSpd_Kph_f32	TunSet_Ptr_Str->k_PPPAPriorityVehSpd_Kph_f32
#define k_RateLimit_UlspS_f32	TunSet_Ptr_Str->k_RateLimit_UlspS_f32

/********************************** Damping **********************************/
#define k_Quad13DmpMult_Uls_f32	TunSet_Ptr_Str->k_Quad13DmpMult_Uls_f32
#define k_Quad24DmpMult_Uls_f32	TunSet_Ptr_Str->k_Quad24DmpMult_Uls_f32

/****************************** AssistFirewall *******************************/
#define t_AsstFWDefltAssistX_HwNm_u8p8	TunSet_Ptr_Str->t_AsstFWDefltAssistX_HwNm_u8p8
#define t_AsstFWDefltAssistY_MtrNm_s4p11	TunSet_Ptr_Str->t_AsstFWDefltAssistY_MtrNm_s4p11
#define k_RestoreThresh_MtrNm_f32	TunSet_Ptr_Str->k_RestoreThresh_MtrNm_f32

/****************************** DampingFirewall ******************************/
#define t_DampFWDefltDampX_MtrRadpS_u10p6	TunSet_Ptr_Str->t_DampFWDefltDampX_MtrRadpS_u10p6
#define t_DampFWDefltDampY_MtrNm_u5p11	TunSet_Ptr_Str->t_DampFWDefltDampY_MtrNm_u5p11
#define k_DampFWPstep_Cnt_u16	TunSet_Ptr_Str->k_DampFWPstep_Cnt_u16
#define k_DampFWNstep_Cnt_u16	TunSet_Ptr_Str->k_DampFWNstep_Cnt_u16
#define t_DampFWPNstepThresh_Cnt_u16	TunSet_Ptr_Str->t_DampFWPNstepThresh_Cnt_u16
#define k_InrtCmp_TBarVelLPFKn_Hz_f32	TunSet_Ptr_Str->k_InrtCmp_TBarVelLPFKn_Hz_f32
#define k_DampFWInCmpPStep_Cnt_u16	TunSet_Ptr_Str->k_DampFWInCmpPStep_Cnt_u16
#define k_DampFWInCmpNStep_Cnt_u16	TunSet_Ptr_Str->k_DampFWInCmpNStep_Cnt_u16
#define t_DampFWDampInrtCmpPNThesh_Cnt_u16	TunSet_Ptr_Str->t_DampFWDampInrtCmpPNThesh_Cnt_u16
#define k_DampFWErrThresh_MtrNm_f32	TunSet_Ptr_Str->k_DampFWErrThresh_MtrNm_f32

/******************************* StabilityComp *******************************/
#define t_StCmpBlend12SpdBS_Kph_u9p7	TunSet_Ptr_Str->t_StCmpBlend12SpdBS_Kph_u9p7
#define t_StCmpBlend12Trq_HwNm_u8p8	TunSet_Ptr_Str->t_StCmpBlend12Trq_HwNm_u8p8
#define t2_StCmpBlend12TblY_Uls_u2p14	TunSet_Ptr_Str->t2_StCmpBlend12TblY_Uls_u2p14
#define t2_StCmpBlend02TblY_Uls_u2p14	TunSet_Ptr_Str->t2_StCmpBlend02TblY_Uls_u2p14
#define t_StCmpBlend34SpdBS_Kph_u9p7	TunSet_Ptr_Str->t_StCmpBlend34SpdBS_Kph_u9p7
#define t_StCmpBlend34Trq_HwNm_u8p8	TunSet_Ptr_Str->t_StCmpBlend34Trq_HwNm_u8p8
#define t2_StCmpBlend34TblY_Uls_u2p14	TunSet_Ptr_Str->t2_StCmpBlend34TblY_Uls_u2p14
#define t2_StCmpBlend04TblY_Uls_u2p14	TunSet_Ptr_Str->t2_StCmpBlend04TblY_Uls_u2p14
#define k_StCmpHwTrqLPFKn_Hz_f32	TunSet_Ptr_Str->k_StCmpHwTrqLPFKn_Hz_f32

/********************************* HystComp **********************************/
#define t2_HysHwTrqBlndTblX_HwNm_u4p12	TunSet_Ptr_Str->t2_HysHwTrqBlndTblX_HwNm_u4p12
#define t2_HysHwTrqBlndTblY_Uls_u4p12	TunSet_Ptr_Str->t2_HysHwTrqBlndTblY_Uls_u4p12
#define t_HysRiseTblX_HwNm_u2p14	TunSet_Ptr_Str->t_HysRiseTblX_HwNm_u2p14
#define t_HysRiseTblY_Uls_u2p14	TunSet_Ptr_Str->t_HysRiseTblY_Uls_u2p14

/******************************** AvgFricLrn *********************************/
#define t_FrHystHwAPts_HwDeg_f32	TunSet_Ptr_Str->t_FrHystHwAPts_HwDeg_f32
#define t2_VehSpd_Kph_f32	TunSet_Ptr_Str->t2_VehSpd_Kph_f32
#define t_MskVehSpd_Cnt_lgc	TunSet_Ptr_Str->t_MskVehSpd_Cnt_lgc
#define t_FricChgWeight_Uls_f32	TunSet_Ptr_Str->t_FricChgWeight_Uls_f32
#define t_InvRatioX_HwDeg_u11p5	TunSet_Ptr_Str->t_InvRatioX_HwDeg_u11p5
#define t_InvRatioY_HwNmpMtrNm_u6p10	TunSet_Ptr_Str->t_InvRatioY_HwNmpMtrNm_u6p10
#define k_LearningGain_Uls_f32	TunSet_Ptr_Str->k_LearningGain_Uls_f32
#define k_LearningThreshold_Cnt_u32	TunSet_Ptr_Str->k_LearningThreshold_Cnt_u32
#define k_RangeCounterLimit_Cnt_u16	TunSet_Ptr_Str->k_RangeCounterLimit_Cnt_u16
#define k_AvgFricLPFKn_Hz_f32	TunSet_Ptr_Str->k_AvgFricLPFKn_Hz_f32
#define k_HwPosAuthMin_Uls_f32	TunSet_Ptr_Str->k_HwPosAuthMin_Uls_f32
#define k_HwVelConstLimit_HwDegpS_f32	TunSet_Ptr_Str->k_HwVelConstLimit_HwDegpS_f32
#define k_HwVelMax_HwDegpS_f32	TunSet_Ptr_Str->k_HwVelMax_HwDegpS_f32
#define k_HwVelMin_HwDegpS_f32	TunSet_Ptr_Str->k_HwVelMin_HwDegpS_f32
#define k_LatAccMax_MpSecSqrd_f32	TunSet_Ptr_Str->k_LatAccMax_MpSecSqrd_f32
#define k_LatAccMin_MpSecSqrd_f32	TunSet_Ptr_Str->k_LatAccMin_MpSecSqrd_f32
#define k_SatFricChgLim_HwNm_f32	TunSet_Ptr_Str->k_SatFricChgLim_HwNm_f32
#define k_FricOffsetLPFKn_Hz_f32	TunSet_Ptr_Str->k_FricOffsetLPFKn_Hz_f32
#define k_TempMin_DegC_f32	TunSet_Ptr_Str->k_TempMin_DegC_f32
#define k_TempMax_DegC_f32	TunSet_Ptr_Str->k_TempMax_DegC_f32
#define k_DataPrepLPFKn_Hz_f32	TunSet_Ptr_Str->k_DataPrepLPFKn_Hz_f32
#define k_IgnCycleFricChgLim_HwNm_f32	TunSet_Ptr_Str->k_IgnCycleFricChgLim_HwNm_f32
#define k_FricOffsetLimitLow_HwNm_f32	TunSet_Ptr_Str->k_FricOffsetLimitLow_HwNm_f32
#define k_FricOffsetLimitHigh_HwNm_f32	TunSet_Ptr_Str->k_FricOffsetLimitHigh_HwNm_f32
#define t2_BaselineTheta_HwNm_f32	TunSet_Ptr_Str->t2_BaselineTheta_HwNm_f32
#define t2_BaselineRangeCounter_Cnt_u16	TunSet_Ptr_Str->t2_BaselineRangeCounter_Cnt_u16
#define t_BaselineFric_HwNm_f32	TunSet_Ptr_Str->t_BaselineFric_HwNm_f32
#define k_BaselineEOLFric_HwNm_f32	TunSet_Ptr_Str->k_BaselineEOLFric_HwNm_f32
#define k_EOLFricDiffScalingFactor_Uls_f32	TunSet_Ptr_Str->k_EOLFricDiffScalingFactor_Uls_f32
#define k_EOLFricDiffLimitLow_HwNm_f32	TunSet_Ptr_Str->k_EOLFricDiffLimitLow_HwNm_f32
#define k_EOLFricDiffLimitHigh_HwNm_f32	TunSet_Ptr_Str->k_EOLFricDiffLimitHigh_HwNm_f32

/********************************* AbsHwPos **********************************/
extern CONST(float32, CAL_CONST) k_InvGearRatio_Uls_f32;

/******************************* AssistSumnLmt *******************************/
extern CONST(float32, CAL_CONST) k_SnLPullCmpFwLmt_MtrNm_f32;

/********************************* CmMtrCurr *********************************/
extern CONST(uint16, CAL_CONST) k_CurrCorrErrFiltKn_Cnt_u16;
extern CONST(float32, CAL_CONST) k_CurrCorrErrThresh_Amps_f32;
extern CONST(float32, CAL_CONST) k_MtrPosComputDelay_Sec_f32;
extern CONST(float32, CAL_CONST) k_MtrCurrEOLMinOffset_Volts_f32;
extern CONST(float32, CAL_CONST) k_MtrCurrEOLMaxOffset_Volts_f32;
extern CONST(float32, CAL_CONST) k_MtrCurrEOLMinGain_AmpspVolts_f32;
extern CONST(float32, CAL_CONST) k_MtrCurrEOLMaxGain_AmpspVolts_f32;
extern CONST(float32, CAL_CONST) k_CurrGainNumerator_Amps_f32;
extern CONST(float32, CAL_CONST) k_MaxCurrOffMtrVel_RadpS_f32;
extern CONST(uint16, CAL_CONST) k_CurrOffGainKn_Cnt_u16;

/******************** CmMtrCurr, CurrReasDiag, MtrCtrl_CM ********************/
extern CONST(boolean, CAL_CONST) k_IPMMtrSwitch_Cnt_lgc;

/******************************* CtrldDisShtdn *******************************/
extern CONST(float32, CAL_CONST) k_F2Damping_MtrNmpRadpS_f32;
extern CONST(float32, CAL_CONST) k_CtrlDpVelThr_MtrRadpS_f32;
extern CONST(float32, CAL_CONST) k_MaxCtrlDmpLimit_MtrNm_f32;
extern CONST(uint16, CAL_CONST) k_CtrlDmpTmrBkptOne_mS_u16;
extern CONST(uint16, CAL_CONST) k_CtrlDmpTmrBkptTwo_mS_u16;

/********************************* CtrlTemp **********************************/
extern CONST(boolean, CAL_CONST) k_TempSnsrFiltDft_Cnt_lgc;
extern CONST(float32, CAL_CONST) k_TempSnsrDefVal_DegC_f32;
extern CONST(DiagSettings_Str, CAL_CONST) k_TempSensDiag_Cnt_str;
extern CONST(float32, CAL_CONST) k_TempSensLowLimit_DegC_f32;
extern CONST(float32, CAL_CONST) k_TempSensHighLimit_DegC_f32;

/****************** CurrCmd, IPMCurrCmd, TqRsDg, MtrCtrl_CM ******************/
extern CONST(float32, CAL_CONST) k_NoofPoles_Uls_f32;

/********************** CurrCmd, IPMCurrCmd, MtrCtrl_CM **********************/
extern CONST(float32, CAL_CONST) k_a0IdSlope_Uls_f32;
extern CONST(float32, CAL_CONST) k_a1IdSlope_Uls_f32;
extern CONST(float32, CAL_CONST) k_a2IdSlope_Uls_f32;
extern CONST(float32, CAL_CONST) k_K2Slope_RadpSecpNm_f32;
extern CONST(float32, CAL_CONST) k_K3VelIntercep_RadpSec_f32;
extern CONST(float32, CAL_CONST) k_IdrefMtrVelOffset_RadpSec_f32;
extern CONST(float32, CAL_CONST) k_MtrMaxCurr_AmpsSq_f32;
extern CONST(float32, CAL_CONST) k_PIGainVspdCutoff_kph_f32;
extern CONST(uint16, CAL_CONST) t_KpqGainX_MtrRadpSec_u12p4[8];
extern CONST(uint16, CAL_CONST) t_KpqGainY_Uls_u6p10[8];
extern CONST(uint16, CAL_CONST) t_KiqGainX_MtrRadpSec_u12p4[8];
extern CONST(uint16, CAL_CONST) t_KiqGainY_Uls_u10p6[8];
extern CONST(uint16, CAL_CONST) t_KpdGainX_MtrRadpSec_u12p4[8];
extern CONST(uint16, CAL_CONST) t_KpdGainY_Uls_u6p10[8];
extern CONST(uint16, CAL_CONST) t_KidGainX_MtrRadpSec_u12p4[8];
extern CONST(uint16, CAL_CONST) t_KidGainY_Uls_u10p6[8];

/**************************** CurrCmd, IPMCurrCmd ****************************/
extern CONST(uint16, CAL_CONST) k_IdMtrVelLPFKn_Cnt_u16;

/******** PICurrCntrl, CurrCmd, CurrParamComp, IPMCurrCmd, MtrCtrl_CM ********/
extern CONST(boolean, CAL_CONST) k_MtrTypeSwitch_Cnt_lgc;

/********************** CurrCmd, IPMCurrCmd, MtrCtrl_CM **********************/
extern CONST(float32, CAL_CONST) k_MtrPosComputationDelay_Sec_f32;

/************************* CurrParamComp, MtrCtrl_CM *************************/
extern CONST(float32, CAL_CONST) k_MinKeRngLmt_VpRadpS_f32;
extern CONST(float32, CAL_CONST) k_MaxKeRngLmt_VpRadpS_f32;
extern CONST(float32, CAL_CONST) k_MinRRngLmt_Ohm_f32;
extern CONST(float32, CAL_CONST) k_MaxRRngLmt_Ohm_f32;
extern CONST(float32, CAL_CONST) k_MinLqRngLmt_Henry_f32;
extern CONST(float32, CAL_CONST) k_MaxLqRngLmt_Henry_f32;
extern CONST(float32, CAL_CONST) k_MinLdRngLmt_Henry_f32;
extern CONST(float32, CAL_CONST) k_MaxLdRngLmt_Henry_f32;
extern CONST(float32, CAL_CONST) k_NomTemp_DegC_f32;
extern CONST(float32, CAL_CONST) k_MagThrC_VpRadpSpDegC_f32;
extern CONST(float32, CAL_CONST) k_NomRfet_Ohm_f32;
extern CONST(float32, CAL_CONST) k_SiThermCoeff_OhmpDegC_f32;
extern CONST(float32, CAL_CONST) k_CuThermCoeff_OhmpDegC_f32;
extern CONST(uint16, CAL_CONST) t_KeSatTblX_Amp_u9p7[16];
extern CONST(uint16, CAL_CONST) t_KeSatTblY_Uls_u2p14[16];
extern CONST(uint16, CAL_CONST) t_CurrParamCompDaxRef_Amp_u9p7[6];
extern CONST(uint16, CAL_CONST) t_CurrParamCompQaxRef_Amp_u9p7[7];
extern CONST(uint16, CAL_CONST) t_CurrParamLdSatSclFac_Uls_u2p14[6][7];
extern CONST(uint16, CAL_CONST) t_CurrParamLqSatSclFac_Uls_u2p14[6][7];

/******************************* CurrReasDiag ********************************/
extern CONST(float32, CAL_CONST) k_CurrReasErrAllow_Amp_f32;
extern CONST(float32, CAL_CONST) k_CurrReasKValHi_CntpAmp_f32;
extern CONST(float32, CAL_CONST) k_CurrReasKValLo_CntpAmp_f32;
extern CONST(float32, CAL_CONST) k_CurrReasMaxFiltCnt_Cnt_f32;
extern CONST(float32, CAL_CONST) k_CurrReasNStep_Cnt_f32;
extern CONST(float32, CAL_CONST) k_CurrReasMaxErr_Amp_f32;
extern CONST(uint16, CAL_CONST) k_MtrVelDampLPFKn_Cnt_u16;

/********************************** DiagMgr **********************************/
extern CONST(float32, CAL_CONST) k_FltRmpRate_UlspmS_f32[13];
extern CONST(FltRsp_Str, CAL_CONST) k_FltRspTbl_Cnt_str[512];

/****************************** DigPhsReasDiag *******************************/
extern CONST(sint16, CAL_CONST) k_PhsReasErrorTerm_Cnt_s16;
extern CONST(uint16, CAL_CONST) k_ErrorFiltKn_Cnt_u16;
extern CONST(uint32, CAL_CONST) k_ErrorThresh_Cnt_u32;
extern CONST(uint32, CAL_CONST) k_PhsReasEnableThresh_Cnt_u32;

/****************************** EOTActuatorMng *******************************/
extern CONST(uint16, CAL_CONST) k_EOTImpSpdEn_Kph_u9p7;
extern CONST(uint16, CAL_CONST) k_EOTDynConf_Uls_u8p8;

/***************** FrqDepDmpnInrtCmp, DampingFirewall, HwTrq *****************/
extern CONST(float32, CAL_CONST) k_TbarStiff_NmpDeg_f32;

/************************ HiLoadStall, ThrmDutyCycle *************************/
extern CONST(float32, CAL_CONST) k_AbsMtrVelBkt_MtrRadps_f32;

/******************************** HiLoadStall ********************************/
extern CONST(uint16, CAL_CONST) k_EOTThrmPrtLPFKn_Cnt_u16;
extern CONST(uint16, CAL_CONST) t_EOTThrmIndptTbl_MtrNm_u8p8[4];
extern CONST(uint16, CAL_CONST) t_EOTThrmDpntTbl_MtrNm_u8p8[4];
extern CONST(float32, CAL_CONST) k_EOTThrmSlwLmtStp_MtrNm_f32;

/*********************************** HwTrq ***********************************/
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
extern CONST(uint16, CAL_CONST) k_HysMaxChange_HwNm_u9p7;
extern CONST(uint16, CAL_CONST) t_HysMagBlndTblX_HwNm_u9p7[2];
extern CONST(uint16, CAL_CONST) t_HysMagBlndTblY_Uls_u4p12[2];
extern CONST(uint16, CAL_CONST) t_HysRiseTblX_HwNm_u9p7[6];
extern CONST(uint16, CAL_CONST) t_HysRiseTblY_Uls_u9p7[6];

/************************** IPMCurrCmd, MtrCtrl_CM ***************************/
extern CONST(float32, CAL_CONST) k_MtrCurrMaxAlphaErad_Rad_f32;
extern CONST(float32, CAL_CONST) k_MtrMaxCurrRef_Amp_f32;

/************************** IPMTrqCanc, MtrCtrl_CM ***************************/
extern CONST(float32, CAL_CONST) k_Harmonic6th_Uls_f32;
extern CONST(float32, CAL_CONST) k_Harmonic12th_Uls_f32;

/******************************** IPMTrqCanc *********************************/
extern CONST(uint16, CAL_CONST) t_MtrTrqRip6thMagTrq_MtrNm_u6p10[6][7];
extern CONST(uint16, CAL_CONST) t_MtrTrqRip12thMagTrq_MtrNm_u6p10[6][7];

/************************** IPMTrqCanc, MtrCtrl_CM ***************************/
extern CONST(uint16, CAL_CONST) t_MtrVelX_MtrRadpS_T_u14p2[10];
extern CONST(uint16, CAL_CONST) t_MtrTrqCancPIMagRP_Uls_u6p10[10];
extern CONST(uint16, CAL_CONST) t_MtrTrqCancPIPhRP_Rev_u0p16[10];

/******************************** MtrTempEst *********************************/
extern CONST(float32, CAL_CONST) k_SiLLFiltKB0_Uls_f32;
extern CONST(float32, CAL_CONST) k_SiLLFiltKB1_Uls_f32;
extern CONST(float32, CAL_CONST) k_SiLLFiltKA1_Uls_f32;
extern CONST(float32, CAL_CONST) k_MagLLFiltKB0_Uls_f32;
extern CONST(float32, CAL_CONST) k_MagLLFiltKB1_Uls_f32;
extern CONST(float32, CAL_CONST) k_MagLLFiltKA1_Uls_f32;
extern CONST(float32, CAL_CONST) k_CuLLFiltKB0_Uls_f32;
extern CONST(float32, CAL_CONST) k_CuLLFiltKB1_Uls_f32;
extern CONST(float32, CAL_CONST) k_CuLLFiltKA1_Uls_f32;
extern CONST(float32, CAL_CONST) k_AmbPwrMult_WtspAmpSq_f32;
extern CONST(float32, CAL_CONST) k_SiAmbMult_DegCpWatt_f32;
extern CONST(float32, CAL_CONST) k_MagAmbMult_DegCpWatt_f32;
extern CONST(float32, CAL_CONST) k_CuAmbMult_DegCpWatt_f32;
extern CONST(float32, CAL_CONST) k_SiCorrLmt_DegC_f32;
extern CONST(float32, CAL_CONST) k_MagCorrLmt_DegC_f32;
extern CONST(float32, CAL_CONST) k_CuCorrLmt_DegC_f32;
extern CONST(float32, CAL_CONST) k_AMDampScl_NmpRadpS_f32;
extern CONST(float32, CAL_CONST) k_AMAmbMult_DegCpWatt_f32;
extern CONST(float32, CAL_CONST) k_TrimTempSi_DegC_f32;
extern CONST(float32, CAL_CONST) k_TrimTempMag_DegC_f32;
extern CONST(float32, CAL_CONST) k_TrimTempCu_DegC_f32;
extern CONST(float32, CAL_CONST) k_TrimTempAM_DegC_f32;
extern CONST(float32, CAL_CONST) k_EngTempScl_Uls_f32;
extern CONST(float32, CAL_CONST) k_AmbTempScl_Uls_f32;
extern CONST(float32, CAL_CONST) k_AMLLFiltPoleA1_Uls_f32;
extern CONST(float32, CAL_CONST) k_AMLLFiltCoefB0_Uls_f32;
extern CONST(float32, CAL_CONST) k_AMLLFiltCoefB1_Uls_f32;
extern CONST(float32, CAL_CONST) k_TempAMEstCorrLmt_DegC_f32;
extern CONST(float32, CAL_CONST) k_AssistMechSlew_DegCpS_f32;

/******************** CurrentEst, PeakCurrEst, MtrCtrl_CM ********************/
extern CONST(uint16, CAL_CONST) k_EstPkCurr2msLPFKn_Uls_u16;
extern CONST(uint16, CAL_CONST) k_EstPkCurrSlowLoopLPFKn_Uls_u16;

/************************** PICurrCntrl, MtrCtrl_CM **************************/
extern CONST(float32, CAL_CONST) k_PiSamplingTs_Sec_f32;
extern CONST(uint16, CAL_CONST) t_CommOffsetTblX_Uls_u3p13[2];
extern CONST(uint16, CAL_CONST) t_CommOffsetTblY_Cnt_u16[2];

/**************************** QuadDet, MtrCtrl_CM ****************************/
extern CONST(float32, CAL_CONST) k_InstMtrDirHyst_Deg_f32;

/*************************** TrqCmdScl, MtrCtrl_CM ***************************/
extern CONST(float32, CAL_CONST) k_MinTrqCmdScl_Uls_f32;
extern CONST(float32, CAL_CONST) k_MaxTrqCmdScl_Uls_f32;

/********************* VehPwrMd, My_LWR_WA, My_ePWM_LWR **********************/
extern CONST(float32, CAL_CONST) k_RampDnRt_UlspmS_f32;
extern CONST(float32, CAL_CONST) k_RampUpRtLoSpd_UlspmS_f32;

/********************************* VehSpdLmt *********************************/
extern CONST(uint16, CAL_CONST) k_PosMaxOfstOne_HwDeg_u12p4;
extern CONST(uint16, CAL_CONST) k_PosMaxOfstTwo_HwDeg_u12p4;
extern CONST(uint16, CAL_CONST) t_MaxAsstTblX_Kph_u9p7[5];
extern CONST(uint16, CAL_CONST) t_MaxAsstTblY_MtrNm_u5p11[5];

/************************** My_LWR_WA, My_ePWM_LWR ***************************/
extern CONST(uint8, CAL_CONST) k_CalRelNum_Cnt_u8[12];
extern CONST(uint8, CAL_CONST) k_NOSMsgDbVer_Cnt_u8[4];
extern CONST(uint32, CAL_CONST) k_PWMTrqMinPlsCnts_Cnts_u16;
extern CONST(uint32, CAL_CONST) k_PWMTrqMinPer_Cnts_u32;
extern CONST(uint32, CAL_CONST) k_PWMTrqMaxPer_Cnts_u32;
extern CONST(float32, CAL_CONST) k_GearRatio_Uls_f32;
extern CONST(uint16, CAL_CONST) k_VehSpdCntInvld_mS_u16p0;
extern CONST(uint16, CAL_CONST) k_VehSpdQfTimeOut_mS_u16p0;
extern CONST(uint16, CAL_CONST) k_WhlSpdInvld_mS_u16p0;
extern CONST(float32, CAL_CONST) k_RTToNomRatioVar_Uls_f32;
extern CONST(float32, CAL_CONST) k_RTOffVelThr_MtrRadpS_f32;
extern CONST(float32, CAL_CONST) k_RTOffsetLmt_Volts_f32;
extern CONST(float32, CAL_CONST) k_RTFiltEnThresh_Uls_f32;
extern CONST(uint16, CAL_CONST) k_RTOffFiltKn_Cnt_u16;
extern CONST(float32, CAL_CONST) k_AmpRecVarLmt_Uls_f32;
extern CONST(float32, CAL_CONST) k_CorrelationError_Rev_f32;
extern CONST(DiagSettings_Str, CAL_CONST) k_MtrPosCorrDiag_Cnt_str;
extern CONST(DiagSettings_Str, CAL_CONST) k_MtrPosValDiag_Cnt_str;
extern CONST(float32, CAL_CONST) k_ValMinError_VoltsSqrd_f32;
extern CONST(float32, CAL_CONST) k_ValMaxError_VoltsSqrd_f32;
extern CONST(boolean, CAL_CONST) k_MtrVelFiltEn_Cnt_lgc;
extern CONST(uint16, CAL_CONST) t_MtrVelBlendTblX_MtrRadpS_u12p4[2];
extern CONST(uint16, CAL_CONST) t_MtrVelDeltaKpTblX_MtrRadpS_u12p4[2];
extern CONST(uint16, CAL_CONST) t_MtrVelDeltaKpTblY_Cnt_u16[2];
extern CONST(uint16, CAL_CONST) t_MtrVelFiltKpTblX_Kph_u9p7[2];
extern CONST(uint16, CAL_CONST) t_MtrVelFiltKpYTbl_Cnt_u16[2];
extern CONST(uint16, CAL_CONST) k_EOLTcmdSclLoLmt_Uls_u7p9;
extern CONST(uint16, CAL_CONST) k_EOLTcmdSclHiLmt_Uls_u7p9;
extern CONST(float32, CAL_CONST) k_FiltAsstReducTh_Pct_f32;
extern CONST(uint16, CAL_CONST) k_AsstReducLPFKn_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_LowVltAstRecTime_mS_u16p0;
extern CONST(uint16, CAL_CONST) k_LowVltAstRecTh_Volts_u8p8;
extern CONST(uint16, CAL_CONST) t_DLVTblX_Volts_u8p8[10];
extern CONST(sint16, CAL_CONST) t_DLVTblY_MtrRadpS_s11p4[10];

/******************* My_LWR_WA, PwrLmtFuncCr, My_ePWM_LWR ********************/
extern CONST(boolean, CAL_CONST) k_SpdAdjSlewEnable_Cnt_lgc;

/************************** My_LWR_WA, My_ePWM_LWR ***************************/
extern CONST(uint16, CAL_CONST) k_SpdAdjSlewDec_MtrRadpSpL_u12p4;
extern CONST(uint16, CAL_CONST) k_SpdAdjSlewInc_MtrRadpSpL_u12p4;
extern CONST(float32, CAL_CONST) k_KeStdTemp_VpRadpS_f32;
extern CONST(uint16, CAL_CONST) t_MtrEnvTblX_MtrRadpS_u12p4[6];
extern CONST(uint16, CAL_CONST) t_MtrEnvTblY_MtrNm_u5p11[6];
extern CONST(uint16, CAL_CONST) t_StdOpMtrEnvTblX_MtrRadpS_u12p4[6];
extern CONST(uint16, CAL_CONST) t_StdOpMtrEnvTblY_MtrNm_u5p11[6];

/*********************** My_LWR_WA, ePWM, My_ePWM_LWR ************************/
extern CONST(sint16, CAL_CONST) k_ADCTrig1Offset_Cnt_s16;

/************************** My_LWR_WA, My_ePWM_LWR ***************************/
extern CONST(sint16, CAL_CONST) k_ADCTrig2Offset_Cnt_s16;

/*********************** My_LWR_WA, ePWM, My_ePWM_LWR ************************/
extern CONST(uint16, CAL_CONST) k_PwmDeadBand_Cnt_u16;

/********************* My_LWR_WA, SVDrvr_CM, My_ePWM_LWR *********************/
extern CONST(uint16, CAL_CONST) k_DitherLPFKn_Cnt_u16;

/************************** My_LWR_WA, My_ePWM_LWR ***************************/
extern CONST(uint16, CAL_CONST) k_DefaultVehSpd_Kph_u9p7;
extern CONST(uint16, CAL_CONST) k_VsRmpTime_Cnt_u16;
extern CONST(DiagSettings_Str, CAL_CONST) k_OnStateDiag_Cnt_str;
extern CONST(DiagSettings_Str, CAL_CONST) k_GateDriveDiag_Cnt_str;
extern CONST(uint16, CAL_CONST) k_GateDrvInitDwellTime_mS_u16p0;
extern CONST(uint16, CAL_CONST) k_GenGateDrvFltThrsh_Cnt_u16;

/********************** My_LWR_WA, BVDiag, My_ePWM_LWR ***********************/
extern CONST(uint16, CAL_CONST) k_OvDetect_Volts_u10p6;
extern CONST(uint16, CAL_CONST) k_OvNotDetect_Volts_u10p6;
extern CONST(uint16, CAL_CONST) k_OvDetect_ms_u16p0;
extern CONST(uint16, CAL_CONST) k_OvNotDetect_ms_u16p0;
extern CONST(uint16, CAL_CONST) k_LowNotDetect_Volts_u10p6;
extern CONST(uint16, CAL_CONST) k_LowDetect_Volts_u10p6;
extern CONST(uint16, CAL_CONST) k_LowDetect_ms_u16p0;
extern CONST(uint16, CAL_CONST) k_LowNotDetect_ms_u16p0;

/************************** My_LWR_WA, My_ePWM_LWR ***************************/
extern CONST(float32, CAL_CONST) k_MaxSwitchedVolt_Volts_f32;
extern CONST(float32, CAL_CONST) k_MaxBattVoltDiff_Volts_f32;
extern CONST(DiagSettings_Str, CAL_CONST) k_AbsTempDiag_Cnt_str;
extern CONST(uint16, CAL_CONST) k_AbsTmpTrqSlewLmt_MtrNm_u9p7;
extern CONST(sint16, CAL_CONST) t_AbsTmpTblX_DegC_s15p0[2];
extern CONST(uint16, CAL_CONST) t_AbsTmpTblY_MtrNm_u9p7[2];
extern CONST(uint16, CAL_CONST) k_DutyCycFltTrshld_Uls_u16p0;
extern CONST(sint16, CAL_CONST) k_EOCTmpDelta_DegC_s15p0;
extern CONST(uint16, CAL_CONST) k_TrqCmdSlewDown_MtrNm_u9p7;
extern CONST(uint16, CAL_CONST) k_TrqCmdSlewUp_MtrNm_u9p7;
extern CONST(uint16, CAL_CONST) t_ThermAsstSclTblX_Uls_u16p0[2];
extern CONST(uint16, CAL_CONST) t_ThermAsstSclTblY_Uls_u2p14[2];
extern CONST(sint16, CAL_CONST) t_Mult12TblX_DegC_s15p0[5];
extern CONST(sint16, CAL_CONST) t_Mult36TblX_DegC_s15p0[5];
extern CONST(uint16, CAL_CONST) t_Mult1NSTblY_Uls_u3p13[5];
extern CONST(uint16, CAL_CONST) t_Mult2NSTblY_Uls_u3p13[5];
extern CONST(uint16, CAL_CONST) t_Mult3NSTblY_Uls_u3p13[5];
extern CONST(uint16, CAL_CONST) t_Mult4NSTblY_Uls_u3p13[5];
extern CONST(uint16, CAL_CONST) t_Mult5NSTblY_Uls_u3p13[5];
extern CONST(uint16, CAL_CONST) t_Mult6NSTblY_Uls_u3p13[5];
extern CONST(uint16, CAL_CONST) t_LastTblValNS_MtrNm_u9p7[5];
extern CONST(uint16, CAL_CONST) t_Mult1STblY_Uls_u3p13[5];
extern CONST(uint16, CAL_CONST) t_Mult2STblY_Uls_u3p13[5];
extern CONST(uint16, CAL_CONST) t_Mult3STblY_Uls_u3p13[5];
extern CONST(uint16, CAL_CONST) t_Mult4STblY_Uls_u3p13[5];
extern CONST(uint16, CAL_CONST) t_Mult5STblY_Uls_u3p13[5];
extern CONST(uint16, CAL_CONST) t_Mult6STblY_Uls_u3p13[5];
extern CONST(uint16, CAL_CONST) t_LastTblValS_MtrNm_u9p7[5];
extern CONST(uint16, CAL_CONST) t_TrqCmdTblX_Uls_u16p0[8];
extern CONST(uint16, CAL_CONST) t_TrqCmdTblY_MtrNm_u9p7[8];
extern CONST(uint16, CAL_CONST) k_PhsReasErrFiltKn_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_PhsReasSWFiltKn_Cnt_u16;
extern CONST(float32, CAL_CONST) k_PhsReasErrThresh_Uls_f32;
extern CONST(float32, CAL_CONST) k_DutyCycleEnable_Uls_f32;
extern CONST(float32, CAL_CONST) k_NomPhaseOffset_Volts_f32;
extern CONST(float32, CAL_CONST) k_OffsetMaxDrift_Volts_f32;
extern CONST(float32, CAL_CONST) k_MaxRackLimit_HwDeg_f32;

/******************************** IPMTrqCanc *********************************/
extern CONST(uint16, CAL_CONST) t_MtrTrqRipQax_Amp_u9p7[7];
extern CONST(uint16, CAL_CONST) t_MtrTrqRipDax_Amp_u9p7[6];
extern CONST(sint16, CAL_CONST) t_MtrTrqRip6thPhs_Rev_s0p15[6][7];
extern CONST(sint16, CAL_CONST) t_MtrTrqRip12thPhs_Rev_s0p15[6][7];
extern CONST(boolean, CAL_CONST) k_IPMMtrTypeSwitch_Cnt_lgc;
extern CONST(uint16, CAL_CONST) k_AutoCtrPinTrqLPFCoeffK_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_AutoCtrMtrVelT1L_MtrRadpS_u12p4;
extern CONST(uint16, CAL_CONST) k_AutoCtrVehSpdT1L_Kph_u9p7;
extern CONST(uint16, CAL_CONST) k_AutoCtrPinTrqT1L_HwNm_u11p5;
extern CONST(uint16, CAL_CONST) k_HwPTimer1MaxL_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_AutoCtrFiltOneCoeffkL_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_AutoCtrWindowL_HwDeg_u12p4;
extern CONST(uint16, CAL_CONST) k_AutoCtrFiltTwoCoeffkL_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_AutoCtrTimer2LSpd_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_HwPMtrVelT1H_MtrRadpS_u12p4;
extern CONST(uint16, CAL_CONST) k_HwPVehSpdT1H_Kph_u9p7;
extern CONST(uint16, CAL_CONST) k_HwPPinionTrqT1H_HwNm_u11p5;
extern CONST(uint16, CAL_CONST) k_HwPTimer1MaxH_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_HwPFilter1KnH_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_HwPWindowCalH_HwDeg_u12p4;
extern CONST(uint16, CAL_CONST) k_HwPFilter2KnH_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_HwPTmr2MaxHiSpd_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_MtrVelTmr4H_MtrRadpS_u12p4;
extern CONST(uint16, CAL_CONST) k_VehSpdTmr4H_kph_u9p7;
extern CONST(uint16, CAL_CONST) k_PinTrqTmr4H_HwNm_u11p5;
extern CONST(uint16, CAL_CONST) k_Tmr4CntrWindowH_HwDeg_u12p4;
extern CONST(uint16, CAL_CONST) k_AutoCtrTimer4H_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_VDAuthL_Uls_u8p8;
extern CONST(uint16, CAL_CONST) k_HiSpdAcAuth_Uls_u8p8;
extern CONST(uint16, CAL_CONST) k_HwPosAuthorityStep_Uls_u8p8;
extern CONST(uint16, CAL_CONST) k_HwPosOpLPFError_HwDeg_u12p4;

/******************************* AbsHwPosScom ********************************/
extern CONST(float32, CAL_CONST) k_KinmIntDiagMaxRackLmt_HwDeg_f32;
extern CONST(uint16, CAL_CONST) k_RbstPosLPFKn_Cnt_u16;

/******************************* CtrldDisShtdn *******************************/
extern CONST(uint16, CAL_CONST) k_CntrlDmpRampEnd_Uls_u8p8;

/********************************* CtrlTemp **********************************/
extern CONST(float32, CAL_CONST) k_TempSnsrLPFKn_Hz_f32;
extern CONST(float32, CAL_CONST) k_DampFWInpLimitInertCmp_MtrNm_f32;

/*********************************** HwTrq ***********************************/
extern CONST(DiagSettings_Str, CAL_CONST) k_AnaRngDiag_Cnt_str;
extern CONST(uint16, CAL_CONST) k_AnaT1T2ErrThreshold_Volts_u5p11;

/************************** IPMTrqCanc, MtrCtrl_CM ***************************/
extern CONST(sint16, CAL_CONST) t_MtrTrqCog_MtrNm_s5p10[512];
extern CONST(float32, CAL_CONST) k_MtrTrqEOTLrn_MtrNm_f32;
extern CONST(float32, CAL_CONST) k_MaxRackCntrDisp_HwDeg_f32;

/******************************** MtrTempEst *********************************/
extern CONST(float32, CAL_CONST) k_SiAmbLPFKn_Hz_f32;
extern CONST(float32, CAL_CONST) k_MagAmbLPFKn_Hz_f32;
extern CONST(float32, CAL_CONST) k_CuAmbLPFKn_Hz_f32;
extern CONST(float32, CAL_CONST) k_AMAmbLPFKn_Hz_f32;

/********************************** Return ***********************************/
extern CONST(float32, CAL_CONST) k_RtnOffsetSlew_HwDegpS_f32;
extern CONST(float32, CAL_CONST) k_RtnOffsetRange_HWDeg_f32;
extern CONST(uint16, CAL_CONST) t_HWAuthRetScl_X_Uls_u8p8[4];
extern CONST(uint16, CAL_CONST) t_HWAuthRetScl_Y_Uls_u9p7[4];
extern CONST(float32, CAL_CONST) k_RtnHWAuthSlew_UlspS_f32;

/******************************* ThrmDutyCycle *******************************/
extern CONST(float32, CAL_CONST) k_EOCCtrlTemp_DegC_f32;
extern CONST(boolean, CAL_CONST) k_CtrlTempSlc_Cnt_lgc;
extern CONST(boolean, CAL_CONST) k_MtrPrTempSlc_Cnt_lgc;
extern CONST(sint16, CAL_CONST) t_MultTblX_DegC_s15p0[5];
extern CONST(boolean, CAL_CONST) k_SlowFltTempSlc_Cnt_lgc;
extern CONST(float32, CAL_CONST) k_AbsTmpTrqSlewLmt_MtrNm_f32;
extern CONST(boolean, CAL_CONST) k_MultTempSlc_Cnt_lgc;
extern CONST(uint16, CAL_CONST) t_AssistThermScalarTblX_Uls_u16p0[2];
extern CONST(uint16, CAL_CONST) t_AssistThermScalarTblY_Uls_u2p14[2];
extern CONST(uint16, CAL_CONST) t_ThrmLoadLmtTblX_Uls_u16p0[8];
extern CONST(uint16, CAL_CONST) t_ThrmLoadLmtTblY_MtrNm_u9p7[8];

/******************************** SrlComInput ********************************/
extern CONST(uint16, CAL_CONST) k_VehSpdMisMsgTimeOut_mS_u16p0;
extern CONST(uint16, CAL_CONST) k_VehSpdValTimeOut_mS_u16p0;
extern CONST(uint16, CAL_CONST) k_IgnStatMisMsgTimeOut_mS_u16p0;
extern CONST(uint16, CAL_CONST) k_IgnStatValTimeOut_mS_u16p0;
extern CONST(uint16, CAL_CONST) k_EngRPMMisMsgTimeOut_mS_u16p0;
extern CONST(uint16, CAL_CONST) k_EngRPMValTimeOut_mS_u16p0;
extern CONST(uint16, CAL_CONST) k_SWAMisMsgTimeOut_mS_u16p0;
extern CONST(uint16, CAL_CONST) k_SWAValTimeOut_mS_u16p0;
extern CONST(sint8, CAL_CONST) k_StrgWhlAnglPol_s08;

/********************************* SgnlCond **********************************/
extern CONST(float32, CAL_CONST) k_VehSpdSlewRate_KphpSec_f32;

/********************************* VehPwrMd **********************************/
extern CONST(float32, CAL_CONST) k_VehSpdAstLmt_Kph_f32;

/******************************** ActivePull *********************************/
extern CONST(float32, CAL_CONST) k_SrvcHwTrqLimit_HwNm_f32;
extern CONST(float32, CAL_CONST) k_SrvcVehSpdLimit_Kph_f32;

/********************************* AstLmt_CM *********************************/
extern CONST(float32, CAL_CONST) k_SumLimPlCmpLimit_MtrNm_f32;
extern CONST(float32, CAL_CONST) k_SumLimOvrSpdMtrTrq2QLmt_MtrNm_f32;

/******************************* PwrLmtFuncCr ********************************/
extern CONST(uint16, CAL_CONST) t_DCLinkVelXAxis_Volt_u5p11[10];
extern CONST(uint16, CAL_CONST) t_DCLinkVelYAxis_MtrRadpS_u11p5[10];
extern CONST(uint16, CAL_CONST) t_MtrEnvXAxis_MtrRadpS_u11p5[9];
extern CONST(sint16, CAL_CONST) t_MtrEnvYAxis_MtrNm_s4p11[9];
extern CONST(uint16, CAL_CONST) t_APAMtrEnvXAxis_MtrRadpS_u11p5[9];
extern CONST(sint16, CAL_CONST) t_APAMtrEnvYAxis_MtrNm_s4p11[9];
extern CONST(float32, CAL_CONST) k_KeMinStdTemp_VpRadpS_f32;
extern CONST(float32, CAL_CONST) k_SpdAdjSlewInc_MtrRadpS_f32;
extern CONST(float32, CAL_CONST) k_SpdAdjSlewDec_MtrRadpS_f32;
extern CONST(float32, CAL_CONST) k_AsstReducLPFKn_Hz_f32;
extern CONST(float32, CAL_CONST) k_EnvLimitLevelThreshold_Uls_f32;
extern CONST(uint16, CAL_CONST) k_LowVltAstRecTime_mS_u16;
extern CONST(float32, CAL_CONST) k_LowVltAstRecTh_Volt_f32;

/******************************* TMS570_uDiag ********************************/
extern CONST(DiagSettings_Str, CAL_CONST) k_FlashECCDiag_Cnt_str;
extern CONST(DiagSettings_Str, CAL_CONST) k_RAMECCDiag_Cnt_str;
extern CONST(uint16, CAL_CONST) k_MtrCtrlMinCount_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_MtrCtrlMaxCount_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_OneMsLoopMinCount_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_OneMsLoopMaxCount_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_VIMParErrThrsh_Cnt_u16;

/******************************* SrlComOutput ********************************/
extern CONST(sint8, CAL_CONST) k_StrClmTrqPolarity_Cnt_s08;

/******************************* AbsHwPosScom ********************************/
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
extern CONST(float32, CAL_CONST) k_HwPosOpLPFError_HwDeg_f32;
extern CONST(float32, CAL_CONST) k_RbstPosLPFKn_Hz_f32;
extern CONST(uint16, CAL_CONST) k_HwPosVehStabilityTime_mS_u16;
extern CONST(float32, CAL_CONST) k_ScomHwPosAuth_Uls_f32;
extern CONST(float32, CAL_CONST) k_HwPosVehStabilityHwTrq_HwNm_f32;
extern CONST(float32, CAL_CONST) k_HwPosVehStabilityTrqCmd_MtrNm_f32;
extern CONST(float32, CAL_CONST) k_HwPosVehStabilityMtrVel_MtrRadpS_f32;
extern CONST(float32, CAL_CONST) k_VdynToScomMaxErr_HwDeg_f32;
extern CONST(float32, CAL_CONST) k_VdynToSComCorrLmt_HwDeg_f32;

/********************************** Damping **********************************/
extern CONST(float32, CAL_CONST) k_MtrVelDampLPFKn_Hz_f32;
extern CONST(float32, CAL_CONST) k_QddHwTrqDampKn_Hz_f32;
extern CONST(float32, CAL_CONST) k_QddMtrVelDampKn_Hz_f32;
extern CONST(float32, CAL_CONST) k_QDDHwTrqBckLash_HwNm_f32;
extern CONST(float32, CAL_CONST) k_QDDMtrVelBckLash_MtrRadpS_f32;
extern CONST(float32, CAL_CONST) k_QddSfLFPKn_Hz_f32;
extern CONST(float32, CAL_CONST) k_HPSbaseC1_MtrNmpMtrRadpS_f32;
extern CONST(float32, CAL_CONST) k_HPSbaseC2_MtrNmpMtrRadpS_f32;
extern CONST(float32, CAL_CONST) k_HPSbaseC3_MtrNmpMtrRadpS_f32;
extern CONST(float32, CAL_CONST) k_HPSbaseC4_MtrNmpMtrRadpS_f32;

/********************************** Return ***********************************/
extern CONST(float32, CAL_CONST) k_RtnLimit_MtrNm_f32;

/********************************** HwPwUp ***********************************/
extern CONST(uint16, CAL_CONST) k_PgmSpecMask_Cnt_u16;

/********************************** HaLFTO ***********************************/
extern CONST(uint16, CAL_CONST) k_HaLFHwTrqTime_mS_u16;
extern CONST(float32, CAL_CONST) k_HaLFMaxHwTrq_mS_f32;
extern CONST(uint16, CAL_CONST) k_HaLFVehSpdTime_mS_u16;
extern CONST(float32, CAL_CONST) k_HaLFMinVehSpd_Kph_f32;
extern CONST(float32, CAL_CONST) k_HaLFMaxVehSpd_Kph_f32;
extern CONST(uint16, CAL_CONST) k_HaLFRevGearTime_mS_u16;
extern CONST(uint16, CAL_CONST) k_HaLFDSTSyncTime_mS_u16;

/*************************** HaLFTO, PAwTO, StbCTO ***************************/
extern CONST(float32, CAL_CONST) k_TrqOverlayLimitPerc_Uls_f32;
extern CONST(uint16, CAL_CONST) k_TrqOverlaySuspendTime_mS_u16;

/*********************************** PAwTO ***********************************/
extern CONST(uint16, CAL_CONST) k_HandsOnLPFKn_Cnt_u16;
extern CONST(uint32, CAL_CONST) k_TrqOverlayHandsOnTrq_HwNm_u5p27;
extern CONST(uint16, CAL_CONST) k_PARvsGearChkTime_mS_u16;
extern CONST(uint16, CAL_CONST) k_PATrqOvNotZeroChkTime_mS_u16;
extern CONST(uint16, CAL_CONST) k_PAVehSpdNotLowTime_mS_u16;
extern CONST(float32, CAL_CONST) k_PAVSpdNotLowMin_Kph_f32;
extern CONST(float32, CAL_CONST) k_PAVSpdNotLowMax_Kph_f32;
extern CONST(uint16, CAL_CONST) k_PAIWSSWhlSpinSetTime_mS_u16;
extern CONST(uint16, CAL_CONST) k_PAIWSSWhlSpinClrTime_mS_u16;
extern CONST(uint16, CAL_CONST) k_PAExcessVehSpdSetTime_mS_u16;
extern CONST(uint16, CAL_CONST) k_PAExcessVehSpdClrTime_mS_u16;
extern CONST(float32, CAL_CONST) k_PAExcessVehSpd_Kph_f32;
extern CONST(uint16, CAL_CONST) k_PAMovMismatchSetTime_mS_u16;
extern CONST(uint16, CAL_CONST) k_PAMovMismatchClrTime_mS_u16;
extern CONST(float32, CAL_CONST) k_PAMovMismatchVSpd_Kph_f32;
extern CONST(uint16, CAL_CONST) k_PAVspdMismatchSetTime_mS_u16;
extern CONST(float32, CAL_CONST) k_PAEIWSSChkVspd_Kph_f32;
extern CONST(uint16, CAL_CONST) k_PABoostCurveTime_mS_u16;

/********************************** LmtCod ***********************************/
extern CONST(float32, CAL_CONST) k_EOTGainIncSlew_UlspS_f32;
extern CONST(float32, CAL_CONST) k_EOTGainDecSlew_UlspS_f32;
extern CONST(float32, CAL_CONST) k_OpRmpMultIncSlew_UlspS_f32;
extern CONST(float32, CAL_CONST) k_OpRmpMultDecSlew_UlspS_f32;
extern CONST(float32, CAL_CONST) k_LimiterIncSlew_MtrNmpS_f32;
extern CONST(float32, CAL_CONST) k_LimiterDecSlew_MtrNmpS_f32;

/*********************************** HwTrq ***********************************/
extern CONST(uint16, CAL_CONST) t_HwTorqCorrLimXAxis_HwNm_u4p12[6];
extern CONST(uint16, CAL_CONST) t_HwTorqCorrLimYAxis_HwNmSq_u7p9[6];
extern CONST(DiagSettings_Str, CAL_CONST) k_HwTorqCorrLimDiag_Cnt_str;
extern CONST(uint16, CAL_CONST) t_SysCHwTorqCorrLimXAxis_HwNm_u4p12[6];
extern CONST(uint16, CAL_CONST) t_SysCHwTorqCorrLimYAxis_HwNmSq_u7p9[6];
extern CONST(DiagSettings_Str, CAL_CONST) k_SysCHwTorqCorrLimDiag_Cnt_str;

/********************************** StbCTO ***********************************/
extern CONST(float32, CAL_CONST) k_DSTVSpdVLH_Kph_f32;
extern CONST(float32, CAL_CONST) k_DSTVSpdVHH_Kph_f32;
extern CONST(float32, CAL_CONST) k_DSTVSpdVLL_Kph_f32;
extern CONST(float32, CAL_CONST) k_DSTVSpdVHL_Kph_f32;
extern CONST(uint16, CAL_CONST) k_DSTVehSpdActvTime_mS_u16;
extern CONST(uint16, CAL_CONST) k_DSTVehSpdInActvTime_mS_u16;
extern CONST(uint16, CAL_CONST) k_DSTBkwdMotionTime_mS_u16;
extern CONST(float32, CAL_CONST) k_DSTTrqOvActiveMaxLimit_MtrNm_f32;
extern CONST(uint16, CAL_CONST) k_DSTTNAMaxTime_mS_u16;
extern CONST(uint16, CAL_CONST) k_DSTRDMaxTime_mS_u16;
extern CONST(uint8, CAL_CONST) k_DSTRDStateMaxCount_Cnt_u08;

/********************************** DiagMgr **********************************/
extern CONST(uint32* const, CAL_CONST) t_BlkBoxGrp_Ptr_u32[7][3];
extern CONST(NTCNumber, CAL_CONST) t_SortedNTCs_Cnt_enum[256];

/******************************** SrlComInput ********************************/
extern CONST(uint16, CAL_CONST) k_PSTMisMsgTimeOut_mS_u16p0;
extern CONST(uint16, CAL_CONST) k_VehCfg5MisMsgTimeOut_mS_u16p0;
extern CONST(uint16, CAL_CONST) k_HalfMsgTimeOut_mS_u16p0;
extern CONST(uint16, CAL_CONST) k_NETCFGMsgTimeOut_mS_u16p0;
extern CONST(uint16, CAL_CONST) k_EcuCfg6MsgTimeOut_mS_u16p0;
extern CONST(DiagSettings_Str, CAL_CONST) k_PSTTrqOvrlRangeDiag_Cnt_str;
extern CONST(float32, CAL_CONST) k_PSTTrqOvrlRange_Cnt_f32;
extern CONST(uint16, CAL_CONST) k_MC292hMsg_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_MC11ChMsg_Cnt_u16;
extern CONST(DiagSettings_Str, CAL_CONST) k_DSTTOCProgCnt1Diag_Cnt_str;
extern CONST(DiagSettings_Str, CAL_CONST) k_DSTTOCProgCnt2Diag_Cnt_str;
extern CONST(uint16, CAL_CONST) k_DSTTOCProgCnt1Thr2_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_DSTTOCProgCnt2Thr2_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_DSTTOCActMsgTimeOut_mS_u16p0;
extern CONST(uint16, CAL_CONST) k_DSTTOCNtActMsgTimeOut_mS_u16p0;
extern CONST(uint16, CAL_CONST) k_MC29FhMsg_Cnt_u16;
extern CONST(float32, CAL_CONST) k_HalfTrqMax_Nm_f32;
extern CONST(uint32, CAL_CONST) k_MsgMaxHalfTorqTO_mS_u32p0;
extern CONST(float32, CAL_CONST) k_PASlewRate_NmpS_f32;
extern CONST(float32, CAL_CONST) k_PSTTrqOvrlSlewLmt_NmpS_f32;
extern CONST(DiagSettings_Str, CAL_CONST) k_PSTTrqOvrlSlewLmtDiag_Cnt_str;
extern CONST(float32, CAL_CONST) k_HaLFSlewRate_NmpS_f32;
extern CONST(float32, CAL_CONST) k_HaLFTrqOvrlSlewLmt_NmpS_f32;
extern CONST(DiagSettings_Str, CAL_CONST) k_HaLFTrqOvrlSlewDiag_Cnt_str;
extern CONST(DiagSettings_Str, CAL_CONST) k_CRC294Diag_Cnt_str;
extern CONST(uint16, CAL_CONST) k_CRC294DiagThr2_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_CRC292DiagMsg_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_CRC29FDiagMsg_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_CRC11CDiagMsg_Cnt_u16;
extern CONST(float32, CAL_CONST) k_IWSSVSpdConst_Cnt_f32;
extern CONST(DiagSettings_Str, CAL_CONST) k_DSTTOCMisMsgtDiag_Cnt_str;
extern CONST(float32, CAL_CONST) k_DSTSlewRate_NmpS_f32;

/********************************** TqRsDg ***********************************/
extern CONST(float32, CAL_CONST) k_ErrAllow_MtrNm_f32;
extern CONST(float32, CAL_CONST) k_MaxErr_MtrNm_f32;
extern CONST(float32, CAL_CONST) k_KvalHiPstep_pMtrNm_f32;
extern CONST(float32, CAL_CONST) k_KvalLoPstep_pMtrNm_f32;
extern CONST(float32, CAL_CONST) k_FltDecrement_Uls_f32;
extern CONST(float32, CAL_CONST) k_MaxfltAccum_Uls_f32;
extern CONST(float32, CAL_CONST) k_MaxMtrEnvMi_Uls_f32;

/****************************** BatteryVoltage *******************************/
extern CONST(DiagSettings_Str, CAL_CONST) k_VswitchCorrLim_Cnt_Str;
extern CONST(DiagSettings_Str, CAL_CONST) k_VecuCorrLim_Cnt_Str;
extern CONST(float32, CAL_CONST) k_VecuVbatCorrLim_Volts_f32;
extern CONST(float32, CAL_CONST) k_VswitchCorrLim_Volts_f32;

/******************************** MtrTempEst *********************************/
extern CONST(float32, CAL_CONST) k_AMDfltOutoutTemp_DegC_f32;

/********************************** MtrVel ***********************************/
extern CONST(DiagSettings_Str, CAL_CONST) k_MtrVelCorrLim_Cnt_Str;
extern CONST(DiagSettings_Str, CAL_CONST) k_HwVelCorrLim_Cnt_Str;
extern CONST(float32, CAL_CONST) k_MtrVelCorrLim_MtrRadpS_f32;
extern CONST(float32, CAL_CONST) k_HwVelCorrLim_HwRadpS_f32;
extern CONST(float32, CAL_CONST) k_HwVelSampleTime_ms_f32;
extern CONST(float32, CAL_CONST) k_DiagMtrVelFiltKn_Hz_f32;

/******************************** MtrCtrl_CM *********************************/
extern CONST(uint16, CAL_CONST) k_MtrVelFiltFFKn_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_MtrVelFiltPIKn_Cnt_u16;
extern CONST(uint16, CAL_CONST) t_MtrCurrQaxRpl_Amp_u9p7[7];
extern CONST(uint16, CAL_CONST) t_MtrCurrDaxRpl_Amp_u9p7[6];
extern CONST(sint16, CAL_CONST) t2_MtrCurrQaxRpl6X_Amp_s6p9[6][7];
extern CONST(sint16, CAL_CONST) t2_MtrCurrQaxRpl6Y_Amp_s6p9[6][7];
extern CONST(sint16, CAL_CONST) t2_MtrCurrQaxRpl12X_Amp_s6p9[6][7];
extern CONST(sint16, CAL_CONST) t2_MtrCurrQaxRpl12Y_Amp_s6p9[6][7];

/******************************** SrlComInput ********************************/
extern CONST(DiagSettings_Str, CAL_CONST) k_PSTTrqOverlayDiag_Cnt_str;
extern CONST(float32, CAL_CONST) k_PSTTrqOverlayLmt_Cnt_f32;
extern CONST(float32, CAL_CONST) k_PSTTrqOvrlChngeLmt_NmpS_f32;
extern CONST(DiagSettings_Str, CAL_CONST) k_PSTTrqOvrlChngeLmtDiag_Cnt_str;
extern CONST(float32, CAL_CONST) k_HaLFTrqOvrlChngeLmt_NmpS_f32;
extern CONST(DiagSettings_Str, CAL_CONST) k_HaLFTrqOverlayDiag_Cnt_str;
extern CONST(uint16, CAL_CONST) k_BattVoltInvTimeOut_mS_u16p0;
extern CONST(uint16, CAL_CONST) k_BattVoltMsgTimeOut_mS_u16p0;
extern CONST(uint16, CAL_CONST) k_ECMA3MsgTimeOut_mS_u16p0;
extern CONST(uint16, CAL_CONST) k_ESP4AInvTimeOut_mS_u16p0;
extern CONST(uint16, CAL_CONST) k_ESP4AMsgTimeOut_mS_u16p0;
extern CONST(uint16, CAL_CONST) k_IC1AAInvTimeOut_mS_u16p0;
extern CONST(uint16, CAL_CONST) k_IC1AMsgTimeOut_mS_u16p0;
extern CONST(uint16, CAL_CONST) k_VehCfg1AInvTimeOut_mS_u16p0;
extern CONST(uint16, CAL_CONST) k_VehCfg1MsgTimeOut_mS_u16p0;
extern CONST(uint16, CAL_CONST) k_VINInvTimeOut_mS_u16p0;
extern CONST(uint16, CAL_CONST) k_VINMsgTimeOut_mS_u16p0;
extern CONST(uint16, CAL_CONST) k_BattMsgVoltHighTimeOut_mS_u16p0;
extern CONST(uint16, CAL_CONST) k_BattMsgVoltLowTimeOut_mS_u16p0;
extern CONST(uint16, CAL_CONST) k_CBCNodeAbsTime_mS_u16p0;
extern CONST(uint16, CAL_CONST) k_DSLNodeAbsTime_mS_u16p0;
extern CONST(uint16, CAL_CONST) k_StrWhlAnglRatTime_mS_u16p0;
extern CONST(uint16, CAL_CONST) k_VehCfg3InvMsgTimeOut_mS_u16p0;

/******************************* TuningSelAuth *******************************/
extern CONST(float32, CAL_CONST) k_TunSelHwTrqLPFKn_Hz_f32;
extern CONST(float32, CAL_CONST) k_TunSelHwTrqThresh_HwNm_f32;
extern CONST(float32, CAL_CONST) k_TunSelVehSpdThresh_Kph_f32;

/******************************** My_ePWM_LWR ********************************/
extern CONST(uint8, CAL_CONST) t_ActiveDiagInfo_Cnt_u08[3];

/******************************* PwrLmtFuncCr ********************************/
extern CONST(sint16, CAL_CONST) t_MtrEnvXAxis_MtrRadpS_s11p4[14];
extern CONST(uint16, CAL_CONST) t_MtrEnvYAxis_MtrNm_u5p11[14];
extern CONST(uint16, CAL_CONST) t_StdOpMtEnvTblXAxis_MtrRadpS_u11p5[6];
extern CONST(sint16, CAL_CONST) t_StdOpMtEnvTblYAxis_MtrNm_s4p11[6];

/*********************************** ePWM ************************************/
extern CONST(uint16, CAL_CONST) k_PwmRelay_Cnt_u16;

/******************************** SrlComInput ********************************/
extern CONST(uint16, CAL_CONST) k_CRC294DiagThr1_Cnt_u16;
extern CONST(DiagSettings_Str, CAL_CONST) k_CRC294DiagThr2_Cnt_str;
extern CONST(uint16, CAL_CONST) k_DSTMisMsgThr0_ms_u16;
extern CONST(uint16, CAL_CONST) k_DSTTOCActMisMsgThr1_Cnt_u16p0;
extern CONST(DiagSettings_Str, CAL_CONST) k_DSTTOCActMisMsgThr2_Cnt_str;
extern CONST(uint16, CAL_CONST) k_DSTTOCNotActMisMsgThr1_Cnt_u16p0;
extern CONST(DiagSettings_Str, CAL_CONST) k_DSTTOCNotActMisMsgThr2_Cnt_str;
extern CONST(DiagSettings_Str, CAL_CONST) k_DSTTOCProgCntDiagThr2_Cnt_str;
extern CONST(uint16, CAL_CONST) k_DSTTOCProgCntThr1_Cnt_u16;
extern CONST(float32, CAL_CONST) k_MsgMaxHalfTorqTO_Nm_f32;

/******************************** My_ePWM_LWR ********************************/
extern CONST(uint8, CAL_CONST) t_ECUPartNumber_Cnt_u8[10];
extern CONST(uint16, CAL_CONST) k_MaxADCConvTime_uS_u16;

/******************************** SrlComInput ********************************/
extern CONST(float32, CAL_CONST) k_DSTTrqMax_HwNm_f32;
extern CONST(float32, CAL_CONST) k_DSTTrqOvrlSlewLmt_NmpS_f32;
extern CONST(uint32, CAL_CONST) k_MaxDSTActiveTime_mS_u32p0;
extern CONST(uint16, CAL_CONST) k_MaxDSTXorCptNTC18F_Cnt_u16;

/******************************** My_ePWM_LWR ********************************/
extern CONST(float32, CAL_CONST) k_ResetVehicleSpeedLmt_Kph_f32;
extern CONST(float32, CAL_CONST) k_ResetAnaHwTorqueLmt_HwNm_f32;

/********************************* CtrlTemp **********************************/
extern CONST(float32, CAL_CONST) k_TempSnsrOffset_Volts_f32;
extern CONST(float32, CAL_CONST) k_TempSnsrScaling_DegpVolt_f32;

/********************************** Assist ***********************************/
#define t2_AsstHwtX0_HwNm_u8p8	TunPer_Ptr_Str->t2_AsstHwtX0_HwNm_u8p8
#define t2_AsstHwtX1_HwNm_u8p8	TunPer_Ptr_Str->t2_AsstHwtX1_HwNm_u8p8
#define t2_AsstAsstY0_MtrNm_s4p11	TunPer_Ptr_Str->t2_AsstAsstY0_MtrNm_s4p11
#define t2_AsstAsstY1_MtrNm_s4p11	TunPer_Ptr_Str->t2_AsstAsstY1_MtrNm_s4p11
#define t_AsstSpeed_Kph_u9p7	TunPer_Ptr_Str->t_AsstSpeed_Kph_u9p7
#define t2_AsstWIRBlndX_MtrNm_u5p11	TunPer_Ptr_Str->t2_AsstWIRBlndX_MtrNm_u5p11
#define t2_AsstWIRBlendY_Uls_u2p14	TunPer_Ptr_Str->t2_AsstWIRBlendY_Uls_u2p14

/********************************** Damping **********************************/
#define t2_MtrVelDmpTblX_MtrRadpS_u12p4	TunPer_Ptr_Str->t2_MtrVelDmpTblX_MtrRadpS_u12p4
#define t2_MtrVelDmpTblY_MtrNm_u5p11	TunPer_Ptr_Str->t2_MtrVelDmpTblY_MtrNm_u5p11
#define t_VSpdDmpTblBS_Kph_u9p7	TunPer_Ptr_Str->t_VSpdDmpTblBS_Kph_u9p7
#define t_HPSscaleC1Y_Uls_u4p12	TunPer_Ptr_Str->t_HPSscaleC1Y_Uls_u4p12
#define t_HPSscaleC2Y_Uls_u4p12	TunPer_Ptr_Str->t_HPSscaleC2Y_Uls_u4p12
#define t_HPSscaleC3Y_Uls_u4p12	TunPer_Ptr_Str->t_HPSscaleC3Y_Uls_u4p12
#define t_HPSscaleC4Y_Uls_u4p12	TunPer_Ptr_Str->t_HPSscaleC4Y_Uls_u4p12
#define t_HPSAsstLimY_MtrNm_u4p12	TunPer_Ptr_Str->t_HPSAsstLimY_MtrNm_u4p12
#define k_HPSOutLimit_MtrNm_f32	TunPer_Ptr_Str->k_HPSOutLimit_MtrNm_f32

/****************************** EOTActuatorMng *******************************/
#define t_SpdIptTblXTbl_HwDeg_u12p4	TunPer_Ptr_Str->t_SpdIptTblXTbl_HwDeg_u12p4
#define t_SpdIptTblYTbl_MtrRadpS_u12p4	TunPer_Ptr_Str->t_SpdIptTblYTbl_MtrRadpS_u12p4
#define k_SpdIptScale_MtrNmpRadpS_u4p12	TunPer_Ptr_Str->k_SpdIptScale_MtrNmpRadpS_u4p12
#define k_PosRampStep_HwDeg_u12p4	TunPer_Ptr_Str->k_PosRampStep_HwDeg_u12p4
#define t2_EOTEnterGainX_HwDeg_u12p4	TunPer_Ptr_Str->t2_EOTEnterGainX_HwDeg_u12p4
#define t2_EOTEnterGainY_Uls_u1p15	TunPer_Ptr_Str->t2_EOTEnterGainY_Uls_u1p15
#define t_EOTEnterGainVspd_Kph_u9p7	TunPer_Ptr_Str->t_EOTEnterGainVspd_Kph_u9p7
#define k_EOTEnterLPFKn_Cnt_u16	TunPer_Ptr_Str->k_EOTEnterLPFKn_Cnt_u16
#define k_EOTExitLPFKn_Cnt_u16	TunPer_Ptr_Str->k_EOTExitLPFKn_Cnt_u16
#define t2_EOTPosDepDmpTblX_HwDeg_u12p4	TunPer_Ptr_Str->t2_EOTPosDepDmpTblX_HwDeg_u12p4
#define t2_EOTPosDepDmpTblY_MtrNmpRadpS_u5p11	TunPer_Ptr_Str->t2_EOTPosDepDmpTblY_MtrNmpRadpS_u5p11
#define t2_EOTExPosDepDmpTblY_MtrNmpRadps_u5p11	TunPer_Ptr_Str->t2_EOTExPosDepDmpTblY_MtrNmpRadps_u5p11
#define t_EOTDmpVspd_Kph_u9p7	TunPer_Ptr_Str->t_EOTDmpVspd_Kph_u9p7

/******************** FrqDepDmpnInrtCmp, DampingFirewall *********************/
#define t_WIRBlndTblX_MtrNm_u8p8	TunPer_Ptr_Str->t_WIRBlndTblX_MtrNm_u8p8
#define t_RIAstWIRBlndTblY_Uls_u2p14	TunPer_Ptr_Str->t_RIAstWIRBlndTblY_Uls_u2p14
#define t_DmpFiltKpWIRBlndY_Uls_u2p14	TunPer_Ptr_Str->t_DmpFiltKpWIRBlndY_Uls_u2p14

/****************************** HighFreqAssist *******************************/
#define t_LPFKnX_Kph_u9p7	TunPer_Ptr_Str->t_LPFKnX_Kph_u9p7
#define t2_LPFKnY_Cnt_u16	TunPer_Ptr_Str->t2_LPFKnY_Cnt_u16
#define t_KnWIRBlndX_MtrNm_u4p12	TunPer_Ptr_Str->t_KnWIRBlndX_MtrNm_u4p12
#define t_KnWIRBlndY_Uls_u1p15	TunPer_Ptr_Str->t_KnWIRBlndY_Uls_u1p15
#define t_Speed_Kph_u9p7	TunPer_Ptr_Str->t_Speed_Kph_u9p7
#define t2_TorqX0_HwNm_u5p11	TunPer_Ptr_Str->t2_TorqX0_HwNm_u5p11
#define t2_TorqX1_HwNm_u5p11	TunPer_Ptr_Str->t2_TorqX1_HwNm_u5p11
#define t2_GainY0_MtrNmpHwNm_u3p13	TunPer_Ptr_Str->t2_GainY0_MtrNmpHwNm_u3p13
#define t2_GainY1_MtrNmpHwNm_u3p13	TunPer_Ptr_Str->t2_GainY1_MtrNmpHwNm_u3p13
#define t2_WIRBlendX_MtrNm_u4p12	TunPer_Ptr_Str->t2_WIRBlendX_MtrNm_u4p12
#define t2_WIRBlendY_Uls_u1p15	TunPer_Ptr_Str->t2_WIRBlendY_Uls_u1p15

/********************************** Return ***********************************/
#define t_ReturnVSpdTblBS_Kph_u9p7	TunPer_Ptr_Str->t_ReturnVSpdTblBS_Kph_u9p7
#define t2_ReturnPosTblXM_HwDeg_u12p4	TunPer_Ptr_Str->t2_ReturnPosTblXM_HwDeg_u12p4
#define t2_ReturnPosTblYM_MtrNm_u5p11	TunPer_Ptr_Str->t2_ReturnPosTblYM_MtrNm_u5p11
#define t2_ReturnSclTrqTblXM_HwNm_T_u8p8	TunPer_Ptr_Str->t2_ReturnSclTrqTblXM_HwNm_T_u8p8
#define t2_ReturnSclTrqTblYM_Uls_u8p8	TunPer_Ptr_Str->t2_ReturnSclTrqTblYM_Uls_u8p8
#define t2_ReturnSclVelTblXM_HwRadpS_T_u7p9	TunPer_Ptr_Str->t2_ReturnSclVelTblXM_HwRadpS_T_u7p9
#define t2_ReturnSclVelTblYM_Uls_u8p8	TunPer_Ptr_Str->t2_ReturnSclVelTblYM_Uls_u8p8

/********************************** Assist ***********************************/
#define t_AsstThermSclX_Cnt_u16p0	TunPer_Ptr_Str->t_AsstThermSclX_Cnt_u16p0
#define t_AsstThermSclY_Uls_u2p14	TunPer_Ptr_Str->t_AsstThermSclY_Uls_u2p14


/*********************** Start of Code Footer ************************/

extern P2CONST(TUNING_P_Str, AUTOMATIC, AUTOMATIC) TunPer_Ptr_Str;
extern P2CONST(TUNING_Y_Str, AUTOMATIC, AUTOMATIC) TunSet_Ptr_Str;
extern CONSTP2CONST(TUNING_P_Str, AUTOMATIC, AUTOMATIC) T_TunPersSelectionTbl_Ptr_Str[D_NUMOFTUNSETS_CNT_U16][D_NUMOFPERS_CNT_U16];
extern CONSTP2CONST(TUNING_Y_Str, AUTOMATIC, AUTOMATIC) T_TunSetSelectionTbl_Ptr_Str[D_NUMOFTUNSETS_CNT_U16];

extern CONST(TUNING_Y_Str, CAL_CONST)k_TunSet0_Cnt_Str;
extern CONST(TUNING_Y_Str, CAL_CONST)k_TunSet1_Cnt_Str;
extern CONST(TUNING_Y_Str, CAL_CONST)k_TunSet2_Cnt_Str;
extern CONST(TUNING_Y_Str, CAL_CONST)k_TunSet3_Cnt_Str;
extern CONST(TUNING_Y_Str, CAL_CONST)k_TunSet4_Cnt_Str;
extern CONST(TUNING_Y_Str, CAL_CONST)k_TunSet5_Cnt_Str;
extern CONST(TUNING_Y_Str, CAL_CONST)k_TunSet6_Cnt_Str;
extern CONST(TUNING_Y_Str, CAL_CONST)k_TunSet7_Cnt_Str;
extern CONST(TUNING_Y_Str, CAL_CONST)k_TunSet8_Cnt_Str;
extern CONST(TUNING_Y_Str, CAL_CONST)k_TunSet9_Cnt_Str;

extern CONST(TUNING_P_Str, CAL_CONST)k_TunSet0Per0_Cnt_Str;
extern CONST(TUNING_P_Str, CAL_CONST)k_TunSet0Per1_Cnt_Str;
extern CONST(TUNING_P_Str, CAL_CONST)k_TunSet0Per2_Cnt_Str;
extern CONST(TUNING_P_Str, CAL_CONST)k_TunSet1Per0_Cnt_Str;
extern CONST(TUNING_P_Str, CAL_CONST)k_TunSet1Per1_Cnt_Str;
extern CONST(TUNING_P_Str, CAL_CONST)k_TunSet1Per2_Cnt_Str;
extern CONST(TUNING_P_Str, CAL_CONST)k_TunSet2Per0_Cnt_Str;
extern CONST(TUNING_P_Str, CAL_CONST)k_TunSet2Per1_Cnt_Str;
extern CONST(TUNING_P_Str, CAL_CONST)k_TunSet2Per2_Cnt_Str;
extern CONST(TUNING_P_Str, CAL_CONST)k_TunSet3Per0_Cnt_Str;
extern CONST(TUNING_P_Str, CAL_CONST)k_TunSet3Per1_Cnt_Str;
extern CONST(TUNING_P_Str, CAL_CONST)k_TunSet3Per2_Cnt_Str;
extern CONST(TUNING_P_Str, CAL_CONST)k_TunSet4Per0_Cnt_Str;
extern CONST(TUNING_P_Str, CAL_CONST)k_TunSet4Per1_Cnt_Str;
extern CONST(TUNING_P_Str, CAL_CONST)k_TunSet4Per2_Cnt_Str;
extern CONST(TUNING_P_Str, CAL_CONST)k_TunSet5Per0_Cnt_Str;
extern CONST(TUNING_P_Str, CAL_CONST)k_TunSet5Per1_Cnt_Str;
extern CONST(TUNING_P_Str, CAL_CONST)k_TunSet5Per2_Cnt_Str;
extern CONST(TUNING_P_Str, CAL_CONST)k_TunSet6Per0_Cnt_Str;
extern CONST(TUNING_P_Str, CAL_CONST)k_TunSet6Per1_Cnt_Str;
extern CONST(TUNING_P_Str, CAL_CONST)k_TunSet6Per2_Cnt_Str;
extern CONST(TUNING_P_Str, CAL_CONST)k_TunSet7Per0_Cnt_Str;
extern CONST(TUNING_P_Str, CAL_CONST)k_TunSet7Per1_Cnt_Str;
extern CONST(TUNING_P_Str, CAL_CONST)k_TunSet7Per2_Cnt_Str;
extern CONST(TUNING_P_Str, CAL_CONST)k_TunSet8Per0_Cnt_Str;
extern CONST(TUNING_P_Str, CAL_CONST)k_TunSet8Per1_Cnt_Str;
extern CONST(TUNING_P_Str, CAL_CONST)k_TunSet8Per2_Cnt_Str;
extern CONST(TUNING_P_Str, CAL_CONST)k_TunSet9Per0_Cnt_Str;
extern CONST(TUNING_P_Str, CAL_CONST)k_TunSet9Per1_Cnt_Str;
extern CONST(TUNING_P_Str, CAL_CONST)k_TunSet9Per2_Cnt_Str;


#endif










