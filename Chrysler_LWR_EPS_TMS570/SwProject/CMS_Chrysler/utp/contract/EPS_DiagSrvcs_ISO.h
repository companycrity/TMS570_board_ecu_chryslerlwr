/*****************************************************************************
* Copyright 2010 Nexteer Automotive, All Rights Reserved.
* Nexteer Confidential
*
* Module File Name  : EPS_DiagSrvcs_ISO.h file
* Module Description: Common Manufacturing Program Interface for XCP and ISO services
* Product           : Gen II Plus - EA3.0
* Author            : Kevin Smith
*
* Notes:
* This file contains configurations for ISO services.
*
*****************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/* Version Control:
 * Date Created:      Mon Apr 12 10:20:00 2012
 * %version:          1 %
 * %derived_by:       jzh87w %
 * %date_modified:    Thu Dec  5 14:32:25 2013 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 04/12/12 	1		KS		Initial Version
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include area >>		                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "EPS_DiagSrvcs_CommonData.h"
#include "EPS_DiagSrvcs_SrvcLUTbl.h"
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include area >>   		      		    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#ifndef EPS_DIAGSRVCS_ISO_H
#define EPS_DIAGSRVCS_ISO_H

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of custom include area >>	                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "EPS_DiagSrvcs_ISO.Interface.h"

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of custom include area >>	                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of custom define area >>   		  	    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/* The following define statements connect variables names to the names used within the
 * service functions. Common defines are shared across multiple services, and specific
 * defines are only included if the service above is active. */


/* Indexes for ISO variables */
#define D_ISOVAR_SWRELNUM			 1u
#define D_ISOVAR_CALRELNUM			 2u
#define D_ISOVAR_LEARNEDKE			 3u
#define D_ISOVAR_LEARNEDR			 4u
#define D_ISOVAR_VEHSPD_KPH			 5u
#define D_ISOVAR_EOLWHLIMBSEL		 6u
#define D_ISOVAR_EOLSRLCOMSVCDFT	 7u
#define D_ISOVAR_MRFCUMMTRPOS		 8u
#define D_ISOVAR_MTRTRQCMD			 9u
#define D_ISOVAR_SYSSTATE			 10u
#define D_ISOVAR_VEHSPDOVERRIDE		 11u
#define D_ISOVAR_DFTTRQSNSRDIAGSRVC	 12u
#define D_ISOVAR_NXTRMECCNTR		 13u
#define D_ISOVAR_ECUSERIALNUM		 14u
#define D_ISOVAR_EPSSERIALNUM		 15u
#define D_ISOVAR_HWPARTNUM			 16u
#define D_ISOVAR_NXTRMFGSCRPAD		 17u
#define D_ISOVAR_IGNCNTR			 18u


/* Structure to share float data with serial comm data */
typedef struct EPS_DiagSrv_DataStr {
     union {
    	 float32 FloatData_f32;
    	 uint32  IntData_u32;
     }type;
} EPS_DiagSrv_DataStr;

/* function pointer types */
typedef CM_MsgBufferType (*PIDFuncRef)(VAR(CM_MsgBufferType, EPSDIAGSRVCS_VAR), P2CONST(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR), P2VAR(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR), VAR(uint8, EPSDIAGSRVCS_VAR), VAR(uint16, EPSDIAGSRVCS_VAR));
typedef uint8 (*RIDFuncRef)(P2CONST(uint8, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR), VAR(uint16, EPSDIAGSRVCS_VAR), VAR(uint16, EPSDIAGSRVCS_VAR));
typedef uint8 (*IOCFuncRef)(P2CONST(uint8, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR), VAR(uint16, EPSDIAGSRVCS_VAR), VAR(uint16, EPSDIAGSRVCS_VAR));
typedef CM_MsgBufferType (*ResetFuncRef)(VAR(CM_MsgBufferType, EPSDIAGSRVCS_VAR), P2VAR(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR));

/******************************************************************************
 *  --- GENERAL FUNCTION START ---
 *****************************************************************************/
extern FUNC(void, EPSDIAGSRVCS_CODE) EPS_DiagSessionChangeIndicator(CONST(uint8,EPSDIAGSRVCS_VAR) SesCtrlTypeOld, CONST(uint8,EPSDIAGSRVCS_VAR) SesCtrlTypeNew);
extern FUNC(void, EPSDIAGSRVCS_CODE) EPSDiagSrvcs_Task(void) ;
extern FUNC(void, EPSDIAGSRVCS_CODE) EPS_DiagSrvcs_Init(void);
extern FUNC(uint16, EPSXCPDIAGSRVCS_CODE) DiagSrvcs_PIDIdxSearch(VAR(uint16, EPSDIAGSRVCS_VAR) PID_Uls_T_u16);
extern FUNC(void, EPSDIAGSRVCS_CODE) NxtrMEC_Init(void);
extern FUNC(CM_MsgBufferType, EPSDIAGSRVCS_CODE) EPS_ResetSrvc(VAR(CM_MsgBufferType, EPSDIAGSRVCS_VAR) pbDiagData, P2VAR(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) RespLen_Cnt_T_u16);
extern FUNC(uint8, EPSDIAGSRVCS_CODE) DiagSrvRIDNullFunc (P2CONST(uint8, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) t_Param_Uls_T_u08, VAR(uint8, EPSDIAGSRVCS_VAR) CtrlByteLen_Cnt_T_u08, VAR(uint16, EPSDIAGSRVCS_VAR) LUTidx_Cnt_T_u16);
extern FUNC(uint8, EPSDIAGSRVCS_CODE) DiagSrvIOCNullFunc (P2CONST(uint8, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) t_Param_Uls_T_u08, VAR(uint8, EPSDIAGSRVCS_VAR) CtrlByteLen_Cnt_T_u08, VAR(uint16, EPSDIAGSRVCS_VAR) LUTidx_Cnt_T_u16);
extern FUNC(CM_MsgBufferType, EPSDIAGSRVCS_CODE) DiagSrvResetNullFunc (VAR(CM_MsgBufferType, EPSDIAGSRVCS_VAR) pbDiagData, P2VAR(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) RespLength_Cnt_T_u16);
extern FUNC(CM_MsgBufferType, EPSDIAGSRVCS_CODE) DiagSrvPIDNullFunc (VAR(CM_MsgBufferType, EPSDIAGSRVCS_VAR) pbDiagData, P2CONST(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) ReqLen_Cnt_T_u16, P2VAR(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) RespLength_Cnt_T_u16, VAR(uint8, EPSDIAGSRVCS_VAR) SrvcReqType_Cnt_T_u8, VAR(uint16, EPSDIAGSRVCS_VAR) LUTidx_Cnt_T_u16);
/******************************************************************************
 *  --- GENERAL FUNCTION END ---
 *****************************************************************************/

/****************************************
 * Reset Services                       *
 ***************************************/
#if (D_EPS_DIAGSRV_RESET_1160 == D_DIAGSRVC_ENABLED)
	extern FUNC(CM_MsgBufferType, EPSDIAGSRVCS_CODE) EPSInternal_RESET_1160 (VAR(CM_MsgBufferType, EPSDIAGSRVCS_VAR) pbDiagData, P2VAR(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) RespLength_Cnt_T_u16);
	#define D_EPS_DIAGSRV_RESETNUM_1160	0x1160U
#else
	#define EPSInternal_RESET_1160	DiagSrvResetNullFunc
#endif /* D_EPS_DIAGSRV_RESET_1160 */

/****************************************
 * Routine I/O Services                 *
 ***************************************/
#if (D_EPS_DIAGSRV_RID_F000 == D_DIAGSRVC_ENABLED)
	extern FUNC(uint8, EPSDIAGSRVCS_CODE) EPSInternal_RID_F000 (P2CONST(uint8, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) t_Param_Uls_T_u08, VAR(uint8, EPSDIAGSRVCS_VAR) CtrlByteLen_Cnt_T_u08, VAR(uint16, EPSDIAGSRVCS_VAR) LUTidx_Cnt_T_u16);
	#define D_EPS_DIAGSRV_RIDNUM_F000	0xF000U
#else
	#define EPSInternal_RID_F000	DiagSrvRIDNullFunc
#endif /* D_EPS_DIAGSRV_RID_F000 */

#if (D_EPS_DIAGSRV_RID_F001 == D_DIAGSRVC_ENABLED)
	extern FUNC(uint8, EPSDIAGSRVCS_CODE) EPSInternal_RID_F001 (P2CONST(uint8, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) t_Param_Uls_T_u08, VAR(uint8, EPSDIAGSRVCS_VAR) CtrlByteLen_Cnt_T_u08, VAR(uint16, EPSDIAGSRVCS_VAR) LUTidx_Cnt_T_u16);
	#define D_EPS_DIAGSRV_RIDNUM_F001	0xF001U
#else
	#define EPSInternal_RID_F001	DiagSrvRIDNullFunc
#endif /* D_EPS_DIAGSRV_RID_F001 */

#if (D_EPS_DIAGSRV_RID_F002 == D_DIAGSRVC_ENABLED)
	extern FUNC(uint8, EPSDIAGSRVCS_CODE) EPSInternal_RID_F002 (P2CONST(uint8, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) t_Param_Uls_T_u08, VAR(uint8, EPSDIAGSRVCS_VAR) CtrlByteLen_Cnt_T_u08, VAR(uint16, EPSDIAGSRVCS_VAR) LUTidx_Cnt_T_u16);
	#define D_EPS_DIAGSRV_RIDNUM_F002	0xF002U
#else
	#define EPSInternal_RID_F002	DiagSrvRIDNullFunc
#endif /* D_EPS_DIAGSRV_RID_F002 */

#if (D_EPS_DIAGSRV_RID_F003 == D_DIAGSRVC_ENABLED)
	extern FUNC(uint8, EPSDIAGSRVCS_CODE) EPSInternal_RID_F003 (P2CONST(uint8, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) t_Param_Uls_T_u08, VAR(uint8, EPSDIAGSRVCS_VAR) CtrlByteLen_Cnt_T_u08, VAR(uint16, EPSDIAGSRVCS_VAR) LUTidx_Cnt_T_u16);
	#define D_EPS_DIAGSRV_RIDNUM_F003	0xF003U
#else
	#define EPSInternal_RID_F003	DiagSrvRIDNullFunc
#endif /* D_EPS_DIAGSRV_RID_F003 */

#if (D_EPS_DIAGSRV_RID_F004 == D_DIAGSRVC_ENABLED)
	extern FUNC(uint8, EPSDIAGSRVCS_CODE) EPSInternal_RID_F004 (P2CONST(uint8, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) t_Param_Uls_T_u08, VAR(uint8, EPSDIAGSRVCS_VAR) CtrlByteLen_Cnt_T_u08, VAR(uint16, EPSDIAGSRVCS_VAR) LUTidx_Cnt_T_u16);
	#define D_EPS_DIAGSRV_RIDNUM_F004	0xF004U
#else
	#define EPSInternal_RID_F004	DiagSrvRIDNullFunc
#endif /* D_EPS_DIAGSRV_RID_F004 */

#if (D_EPS_DIAGSRV_RID_F006 == D_DIAGSRVC_ENABLED)
	extern FUNC(uint8, EPSDIAGSRVCS_CODE) EPSInternal_RID_F006 (P2CONST(uint8, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) t_Param_Uls_T_u08, VAR(uint8, EPSDIAGSRVCS_VAR) CtrlByteLen_Cnt_T_u08, VAR(uint16, EPSDIAGSRVCS_VAR) LUTidx_Cnt_T_u16);
	#define D_EPS_DIAGSRV_RIDNUM_F006	0xF006U
#else
	#define EPSInternal_RID_F006	DiagSrvRIDNullFunc
#endif /* D_EPS_DIAGSRV_RID_F006 */

#if (D_EPS_DIAGSRV_RID_F007 == D_DIAGSRVC_ENABLED)
	extern FUNC(uint8, EPSDIAGSRVCS_CODE) EPSInternal_RID_F007 (P2CONST(uint8, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) t_Param_Uls_T_u08, VAR(uint8, EPSDIAGSRVCS_VAR) CtrlByteLen_Cnt_T_u08, VAR(uint16, EPSDIAGSRVCS_VAR) LUTidx_Cnt_T_u16);
	#define D_EPS_DIAGSRV_RIDNUM_F007	0xF007U
#else
	#define EPSInternal_RID_F007	DiagSrvRIDNullFunc
#endif /* D_EPS_DIAGSRV_RID_F007 */

#if (D_EPS_DIAGSRV_RID_F008 == D_DIAGSRVC_ENABLED)
	extern FUNC(uint8, EPSDIAGSRVCS_CODE) EPSInternal_RID_F008 (P2CONST(uint8, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) t_Param_Uls_T_u08, VAR(uint8, EPSDIAGSRVCS_VAR) CtrlByteLen_Cnt_T_u08, VAR(uint16, EPSDIAGSRVCS_VAR) LUTidx_Cnt_T_u16);
	#define D_EPS_DIAGSRV_RIDNUM_F008	0xF008U
#else
	#define EPSInternal_RID_F008	DiagSrvRIDNullFunc
#endif /* D_EPS_DIAGSRV_RID_F008 */

#if (D_EPS_DIAGSRV_RID_F009 == D_DIAGSRVC_ENABLED)
	extern FUNC(uint8, EPSDIAGSRVCS_CODE) EPSInternal_RID_F009 (P2CONST(uint8, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) t_Param_Uls_T_u08, VAR(uint8, EPSDIAGSRVCS_VAR) CtrlByteLen_Cnt_T_u08, VAR(uint16, EPSDIAGSRVCS_VAR) LUTidx_Cnt_T_u16);
	#define D_EPS_DIAGSRV_RIDNUM_F009	0xF009U
#else
	#define EPSInternal_RID_F009	DiagSrvRIDNullFunc
#endif /* D_EPS_DIAGSRV_RID_F009 */

#if (D_EPS_DIAGSRV_RID_F00A == D_DIAGSRVC_ENABLED)
	extern FUNC(uint8, EPSDIAGSRVCS_CODE) EPSInternal_RID_F00A (P2CONST(uint8, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) t_Param_Uls_T_u08, VAR(uint8, EPSDIAGSRVCS_VAR) CtrlByteLen_Cnt_T_u08, VAR(uint16, EPSDIAGSRVCS_VAR) LUTidx_Cnt_T_u16);
	#define D_EPS_DIAGSRV_RIDNUM_F00A	0xF00AU
#else
	#define EPSInternal_RID_F00A	DiagSrvRIDNullFunc
#endif /* D_EPS_DIAGSRV_RID_F00A */

#if (D_EPS_DIAGSRV_RID_F00B == D_DIAGSRVC_ENABLED)
	extern FUNC(uint8, EPSDIAGSRVCS_CODE) EPSInternal_RID_F00B (P2CONST(uint8, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) t_Param_Uls_T_u08, VAR(uint8, EPSDIAGSRVCS_VAR) CtrlByteLen_Cnt_T_u08, VAR(uint16, EPSDIAGSRVCS_VAR) LUTidx_Cnt_T_u16);
	#define D_EPS_DIAGSRV_RIDNUM_F00B	0xF00BU
#else
	#define EPSInternal_RID_F00B	DiagSrvRIDNullFunc
#endif /* D_EPS_DIAGSRV_RID_F00B */

#if (D_EPS_DIAGSRV_RID_F00D == D_DIAGSRVC_ENABLED)
	extern FUNC(uint8, EPSDIAGSRVCS_CODE) EPSInternal_RID_F00D (P2CONST(uint8, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) t_Param_Uls_T_u08, VAR(uint8, EPSDIAGSRVCS_VAR) CtrlByteLen_Cnt_T_u08, VAR(uint16, EPSDIAGSRVCS_VAR) LUTidx_Cnt_T_u16);
	#define D_EPS_DIAGSRV_RIDNUM_F00D	0xF00DU
#else
	#define EPSInternal_RID_F00D	DiagSrvRIDNullFunc
#endif /* D_EPS_DIAGSRV_RID_F00D */

#if (D_EPS_DIAGSRV_RID_F00E == D_DIAGSRVC_ENABLED)
	extern FUNC(uint8, EPSDIAGSRVCS_CODE) EPSInternal_RID_F00E (P2CONST(uint8, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) t_Param_Uls_T_u08, VAR(uint8, EPSDIAGSRVCS_VAR) CtrlByteLen_Cnt_T_u08, VAR(uint16, EPSDIAGSRVCS_VAR) LUTidx_Cnt_T_u16);
	#define D_EPS_DIAGSRV_RIDNUM_F00E	0xF00EU
#else
	#define EPSInternal_RID_F00E	DiagSrvRIDNullFunc
#endif /* D_EPS_DIAGSRV_RID_F00E */

/****************************************
 * Customer Routine I/O Services        *
 ***************************************/
#if (D_EPS_DIAGSRV_RID_FCE0 == D_DIAGSRVC_ENABLED)
	extern FUNC(uint8, EPSDIAGSRVCS_CODE) EPSInternal_RID_FCE0 (P2CONST(uint8, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) t_Param_Uls_T_u08, VAR(uint8, EPSDIAGSRVCS_VAR) CtrlByteLen_Cnt_T_u08, VAR(uint16, EPSDIAGSRVCS_VAR) LUTidx_Cnt_T_u16);
	#define D_EPS_DIAGSRV_RIDNUM_FCE0	0xFCE0U
#else
	#define EPSInternal_RID_FCE0	DiagSrvRIDNullFunc
#endif /* D_EPS_DIAGSRV_RID_FCE0 */

#if (D_EPS_DIAGSRV_RID_FCE1 == D_DIAGSRVC_ENABLED)
	extern FUNC(uint8, EPSDIAGSRVCS_CODE) EPSInternal_RID_FCE1 (P2CONST(uint8, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) t_Param_Uls_T_u08, VAR(uint8, EPSDIAGSRVCS_VAR) CtrlByteLen_Cnt_T_u08, VAR(uint16, EPSDIAGSRVCS_VAR) LUTidx_Cnt_T_u16);
	#define D_EPS_DIAGSRV_RIDNUM_FCE1	0xFCE1U
#else
	#define EPSInternal_RID_FCE1	DiagSrvRIDNullFunc
#endif /* D_EPS_DIAGSRV_RID_FCE1 */

#if (D_EPS_DIAGSRV_RID_FCE2 == D_DIAGSRVC_ENABLED)
	extern FUNC(uint8, EPSDIAGSRVCS_CODE) EPSInternal_RID_FCE2 (P2CONST(uint8, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) t_Param_Uls_T_u08, VAR(uint8, EPSDIAGSRVCS_VAR) CtrlByteLen_Cnt_T_u08, VAR(uint16, EPSDIAGSRVCS_VAR) LUTidx_Cnt_T_u16);
	#define D_EPS_DIAGSRV_RIDNUM_FCE2	0xFCE2U
#else
	#define EPSInternal_RID_FCE2	DiagSrvRIDNullFunc
#endif /* D_EPS_DIAGSRV_RID_FCE2 */

#if (D_EPS_DIAGSRV_RID_FCE3 == D_DIAGSRVC_ENABLED)
	extern FUNC(uint8, EPSDIAGSRVCS_CODE) EPSInternal_RID_FCE3 (P2CONST(uint8, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) t_Param_Uls_T_u08, VAR(uint8, EPSDIAGSRVCS_VAR) CtrlByteLen_Cnt_T_u08, VAR(uint16, EPSDIAGSRVCS_VAR) LUTidx_Cnt_T_u16);
	#define D_EPS_DIAGSRV_RIDNUM_FCE3	0xFCE3U
#else
	#define EPSInternal_RID_FCE3	DiagSrvRIDNullFunc
#endif /* D_EPS_DIAGSRV_RID_FCE3 */

#if (D_EPS_DIAGSRV_RID_FCE4 == D_DIAGSRVC_ENABLED)
	extern FUNC(uint8, EPSDIAGSRVCS_CODE) EPSInternal_RID_FCE4 (P2CONST(uint8, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) t_Param_Uls_T_u08, VAR(uint8, EPSDIAGSRVCS_VAR) CtrlByteLen_Cnt_T_u08, VAR(uint16, EPSDIAGSRVCS_VAR) LUTidx_Cnt_T_u16);
	#define D_EPS_DIAGSRV_RIDNUM_FCE4	0xFCE4U
#else
	#define EPSInternal_RID_FCE4	DiagSrvRIDNullFunc
#endif /* D_EPS_DIAGSRV_RID_FCE4 */

#if (D_EPS_DIAGSRV_RID_FCE5 == D_DIAGSRVC_ENABLED)
	extern FUNC(uint8, EPSDIAGSRVCS_CODE) EPSInternal_RID_FCE5 (P2CONST(uint8, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) t_Param_Uls_T_u08, VAR(uint8, EPSDIAGSRVCS_VAR) CtrlByteLen_Cnt_T_u08, VAR(uint16, EPSDIAGSRVCS_VAR) LUTidx_Cnt_T_u16);
	#define D_EPS_DIAGSRV_RIDNUM_FCE5	0xFCE5U
#else
	#define EPSInternal_RID_FCE5	DiagSrvRIDNullFunc
#endif /* D_EPS_DIAGSRV_RID_FCE5 */

#if (D_EPS_DIAGSRV_RID_FCE6 == D_DIAGSRVC_ENABLED)
	extern FUNC(uint8, EPSDIAGSRVCS_CODE) EPSInternal_RID_FCE6 (P2CONST(uint8, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) t_Param_Uls_T_u08, VAR(uint8, EPSDIAGSRVCS_VAR) CtrlByteLen_Cnt_T_u08, VAR(uint16, EPSDIAGSRVCS_VAR) LUTidx_Cnt_T_u16);
	#define D_EPS_DIAGSRV_RIDNUM_FCE6	0xFCE6U
#else
	#define EPSInternal_RID_FCE6	DiagSrvRIDNullFunc
#endif /* D_EPS_DIAGSRV_RID_FCE6 */

#if (D_EPS_DIAGSRV_RID_FCE7 == D_DIAGSRVC_ENABLED)
	extern FUNC(uint8, EPSDIAGSRVCS_CODE) EPSInternal_RID_FCE7 (P2CONST(uint8, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) t_Param_Uls_T_u08, VAR(uint8, EPSDIAGSRVCS_VAR) CtrlByteLen_Cnt_T_u08, VAR(uint16, EPSDIAGSRVCS_VAR) LUTidx_Cnt_T_u16);
	#define D_EPS_DIAGSRV_RIDNUM_FCE7	0xFCE7U
#else
	#define EPSInternal_RID_FCE7	DiagSrvRIDNullFunc
#endif /* D_EPS_DIAGSRV_RID_FCE7 */

#if (D_EPS_DIAGSRV_RID_FCE8 == D_DIAGSRVC_ENABLED)
	extern FUNC(uint8, EPSDIAGSRVCS_CODE) EPSInternal_RID_FCE8 (P2CONST(uint8, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) t_Param_Uls_T_u08, VAR(uint8, EPSDIAGSRVCS_VAR) CtrlByteLen_Cnt_T_u08, VAR(uint16, EPSDIAGSRVCS_VAR) LUTidx_Cnt_T_u16);
	#define D_EPS_DIAGSRV_RIDNUM_FCE8	0xFCE8U
#else
	#define EPSInternal_RID_FCE8	DiagSrvRIDNullFunc
#endif /* D_EPS_DIAGSRV_RID_FCE8 */

#if (D_EPS_DIAGSRV_RID_FCE9 == D_DIAGSRVC_ENABLED)
	extern FUNC(uint8, EPSDIAGSRVCS_CODE) EPSInternal_RID_FCE9 (P2CONST(uint8, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) t_Param_Uls_T_u08, VAR(uint8, EPSDIAGSRVCS_VAR) CtrlByteLen_Cnt_T_u08, VAR(uint16, EPSDIAGSRVCS_VAR) LUTidx_Cnt_T_u16);
	#define D_EPS_DIAGSRV_RIDNUM_FCE9	0xFCE9U
#else
	#define EPSInternal_RID_FCE9	DiagSrvRIDNullFunc
#endif /* D_EPS_DIAGSRV_RID_FCE9 */

#if (D_EPS_DIAGSRV_RID_FCEA == D_DIAGSRVC_ENABLED)
	extern FUNC(uint8, EPSDIAGSRVCS_CODE) EPSInternal_RID_FCEA (P2CONST(uint8, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) t_Param_Uls_T_u08, VAR(uint8, EPSDIAGSRVCS_VAR) CtrlByteLen_Cnt_T_u08, VAR(uint16, EPSDIAGSRVCS_VAR) LUTidx_Cnt_T_u16);
	#define D_EPS_DIAGSRV_RIDNUM_FCEA	0xFCEAU
#else
	#define EPSInternal_RID_FCEA	DiagSrvRIDNullFunc
#endif /* D_EPS_DIAGSRV_RID_FCEA */

#if (D_EPS_DIAGSRV_RID_FCEB == D_DIAGSRVC_ENABLED)
	extern FUNC(uint8, EPSDIAGSRVCS_CODE) EPSInternal_RID_FCEB (P2CONST(uint8, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) t_Param_Uls_T_u08, VAR(uint8, EPSDIAGSRVCS_VAR) CtrlByteLen_Cnt_T_u08, VAR(uint16, EPSDIAGSRVCS_VAR) LUTidx_Cnt_T_u16);
	#define D_EPS_DIAGSRV_RIDNUM_FCEB	0xFCEBU
#else
	#define EPSInternal_RID_FCEB	DiagSrvRIDNullFunc
#endif /* D_EPS_DIAGSRV_RID_FCEB */

#if (D_EPS_DIAGSRV_RID_FCEC == D_DIAGSRVC_ENABLED)
	extern FUNC(uint8, EPSDIAGSRVCS_CODE) EPSInternal_RID_FCEC (P2CONST(uint8, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) t_Param_Uls_T_u08, VAR(uint8, EPSDIAGSRVCS_VAR) CtrlByteLen_Cnt_T_u08, VAR(uint16, EPSDIAGSRVCS_VAR) LUTidx_Cnt_T_u16);
	#define D_EPS_DIAGSRV_RIDNUM_FCEC	0xFCECU
#else
	#define EPSInternal_RID_FCEC	DiagSrvRIDNullFunc
#endif /* D_EPS_DIAGSRV_RID_FCEC */

#if (D_EPS_DIAGSRV_RID_FCED == D_DIAGSRVC_ENABLED)
	extern FUNC(uint8, EPSDIAGSRVCS_CODE) EPSInternal_RID_FCED (P2CONST(uint8, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) t_Param_Uls_T_u08, VAR(uint8, EPSDIAGSRVCS_VAR) CtrlByteLen_Cnt_T_u08, VAR(uint16, EPSDIAGSRVCS_VAR) LUTidx_Cnt_T_u16);
	#define D_EPS_DIAGSRV_RIDNUM_FCED	0xFCEDU
#else
	#define EPSInternal_RID_FCED	DiagSrvRIDNullFunc
#endif /* D_EPS_DIAGSRV_RID_FCED */

#if (D_EPS_DIAGSRV_RID_FCEE == D_DIAGSRVC_ENABLED)
	extern FUNC(uint8, EPSDIAGSRVCS_CODE) EPSInternal_RID_FCEE (P2CONST(uint8, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) t_Param_Uls_T_u08, VAR(uint8, EPSDIAGSRVCS_VAR) CtrlByteLen_Cnt_T_u08, VAR(uint16, EPSDIAGSRVCS_VAR) LUTidx_Cnt_T_u16);
	#define D_EPS_DIAGSRV_RIDNUM_FCEE	0xFCEEU
#else
	#define EPSInternal_RID_FCEE	DiagSrvRIDNullFunc
#endif /* D_EPS_DIAGSRV_RID_FCEE */

#if (D_EPS_DIAGSRV_RID_FCEF == D_DIAGSRVC_ENABLED)
	extern FUNC(uint8, EPSDIAGSRVCS_CODE) EPSInternal_RID_FCEF (P2CONST(uint8, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) t_Param_Uls_T_u08, VAR(uint8, EPSDIAGSRVCS_VAR) CtrlByteLen_Cnt_T_u08, VAR(uint16, EPSDIAGSRVCS_VAR) LUTidx_Cnt_T_u16);
	#define D_EPS_DIAGSRV_RIDNUM_FCEF	0xFCEFU
#else
	#define EPSInternal_RID_FCEF	DiagSrvRIDNullFunc
#endif /* D_EPS_DIAGSRV_RID_FCEF */

#if (D_EPS_DIAGSRV_RID_FCF0 == D_DIAGSRVC_ENABLED)
	extern FUNC(uint8, EPSDIAGSRVCS_CODE) EPSInternal_RID_FCF0 (P2CONST(uint8, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) t_Param_Uls_T_u08, VAR(uint8, EPSDIAGSRVCS_VAR) CtrlByteLen_Cnt_T_u08, VAR(uint16, EPSDIAGSRVCS_VAR) LUTidx_Cnt_T_u16);
	#define D_EPS_DIAGSRV_RIDNUM_FCF0	0xFCF0U
#else
	#define EPSInternal_RID_FCF0	DiagSrvRIDNullFunc
#endif /* D_EPS_DIAGSRV_RID_FCF0 */

#if (D_EPS_DIAGSRV_RID_FCF1 == D_DIAGSRVC_ENABLED)
	extern FUNC(uint8, EPSDIAGSRVCS_CODE) EPSInternal_RID_FCF1 (P2CONST(uint8, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) t_Param_Uls_T_u08, VAR(uint8, EPSDIAGSRVCS_VAR) CtrlByteLen_Cnt_T_u08, VAR(uint16, EPSDIAGSRVCS_VAR) LUTidx_Cnt_T_u16);
	#define D_EPS_DIAGSRV_RIDNUM_FCF1	0xFCF1U
#else
	#define EPSInternal_RID_FCF1	DiagSrvRIDNullFunc
#endif /* D_EPS_DIAGSRV_RID_FCF1 */

#if (D_EPS_DIAGSRV_RID_FCF2 == D_DIAGSRVC_ENABLED)
	extern FUNC(uint8, EPSDIAGSRVCS_CODE) EPSInternal_RID_FCF2 (P2CONST(uint8, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) t_Param_Uls_T_u08, VAR(uint8, EPSDIAGSRVCS_VAR) CtrlByteLen_Cnt_T_u08, VAR(uint16, EPSDIAGSRVCS_VAR) LUTidx_Cnt_T_u16);
	#define D_EPS_DIAGSRV_RIDNUM_FCF2	0xFCF2U
#else
	#define EPSInternal_RID_FCF2	DiagSrvRIDNullFunc
#endif /* D_EPS_DIAGSRV_RID_FCF2 */

#if (D_EPS_DIAGSRV_RID_FCF3 == D_DIAGSRVC_ENABLED)
	extern FUNC(uint8, EPSDIAGSRVCS_CODE) EPSInternal_RID_FCF3 (P2CONST(uint8, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) t_Param_Uls_T_u08, VAR(uint8, EPSDIAGSRVCS_VAR) CtrlByteLen_Cnt_T_u08, VAR(uint16, EPSDIAGSRVCS_VAR) LUTidx_Cnt_T_u16);
	#define D_EPS_DIAGSRV_RIDNUM_FCF3	0xFCF3U
#else
	#define EPSInternal_RID_FCF3	DiagSrvRIDNullFunc
#endif /* D_EPS_DIAGSRV_RID_FCF3 */

#if (D_EPS_DIAGSRV_RID_FCF4 == D_DIAGSRVC_ENABLED)
	extern FUNC(uint8, EPSDIAGSRVCS_CODE) EPSInternal_RID_FCF4 (P2CONST(uint8, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) t_Param_Uls_T_u08, VAR(uint8, EPSDIAGSRVCS_VAR) CtrlByteLen_Cnt_T_u08, VAR(uint16, EPSDIAGSRVCS_VAR) LUTidx_Cnt_T_u16);
	#define D_EPS_DIAGSRV_RIDNUM_FCF4	0xFCF4U
#else
	#define EPSInternal_RID_FCF4	DiagSrvRIDNullFunc
#endif /* D_EPS_DIAGSRV_RID_FCF4 */

#if (D_EPS_DIAGSRV_RID_FCF5 == D_DIAGSRVC_ENABLED)
	extern FUNC(uint8, EPSDIAGSRVCS_CODE) EPSInternal_RID_FCF5 (P2CONST(uint8, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) t_Param_Uls_T_u08, VAR(uint8, EPSDIAGSRVCS_VAR) CtrlByteLen_Cnt_T_u08, VAR(uint16, EPSDIAGSRVCS_VAR) LUTidx_Cnt_T_u16);
	#define D_EPS_DIAGSRV_RIDNUM_FCF5	0xFCF5U
#else
	#define EPSInternal_RID_FCF5	DiagSrvRIDNullFunc
#endif /* D_EPS_DIAGSRV_RID_FCF5 */

#if (D_EPS_DIAGSRV_RID_FCF6 == D_DIAGSRVC_ENABLED)
	extern FUNC(uint8, EPSDIAGSRVCS_CODE) EPSInternal_RID_FCF6 (P2CONST(uint8, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) t_Param_Uls_T_u08, VAR(uint8, EPSDIAGSRVCS_VAR) CtrlByteLen_Cnt_T_u08, VAR(uint16, EPSDIAGSRVCS_VAR) LUTidx_Cnt_T_u16);
	#define D_EPS_DIAGSRV_RIDNUM_FCF6	0xFCF6U
#else
	#define EPSInternal_RID_FCF6	DiagSrvRIDNullFunc
#endif /* D_EPS_DIAGSRV_RID_FCF6 */

#if (D_EPS_DIAGSRV_RID_FCF7 == D_DIAGSRVC_ENABLED)
	extern FUNC(uint8, EPSDIAGSRVCS_CODE) EPSInternal_RID_FCF7 (P2CONST(uint8, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) t_Param_Uls_T_u08, VAR(uint8, EPSDIAGSRVCS_VAR) CtrlByteLen_Cnt_T_u08, VAR(uint16, EPSDIAGSRVCS_VAR) LUTidx_Cnt_T_u16);
	#define D_EPS_DIAGSRV_RIDNUM_FCF7	0xFCF7U
#else
	#define EPSInternal_RID_FCF7	DiagSrvRIDNullFunc
#endif /* D_EPS_DIAGSRV_RID_FCF7 */

#if (D_EPS_DIAGSRV_RID_FCF8 == D_DIAGSRVC_ENABLED)
	extern FUNC(uint8, EPSDIAGSRVCS_CODE) EPSInternal_RID_FCF8 (P2CONST(uint8, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) t_Param_Uls_T_u08, VAR(uint8, EPSDIAGSRVCS_VAR) CtrlByteLen_Cnt_T_u08, VAR(uint16, EPSDIAGSRVCS_VAR) LUTidx_Cnt_T_u16);
	#define D_EPS_DIAGSRV_RIDNUM_FCF8	0xFCF8U
#else
	#define EPSInternal_RID_FCF8	DiagSrvRIDNullFunc
#endif /* D_EPS_DIAGSRV_RID_FCF8 */

#if (D_EPS_DIAGSRV_RID_FCF9 == D_DIAGSRVC_ENABLED)
	extern FUNC(uint8, EPSDIAGSRVCS_CODE) EPSInternal_RID_FCF9 (P2CONST(uint8, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) t_Param_Uls_T_u08, VAR(uint8, EPSDIAGSRVCS_VAR) CtrlByteLen_Cnt_T_u08, VAR(uint16, EPSDIAGSRVCS_VAR) LUTidx_Cnt_T_u16);
	#define D_EPS_DIAGSRV_RIDNUM_FCF9	0xFCF9U
#else
	#define EPSInternal_RID_FCF9	DiagSrvRIDNullFunc
#endif /* D_EPS_DIAGSRV_RID_FCF9 */

#if (D_EPS_DIAGSRV_RID_FCFA == D_DIAGSRVC_ENABLED)
	extern FUNC(uint8, EPSDIAGSRVCS_CODE) EPSInternal_RID_FCFA (P2CONST(uint8, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) t_Param_Uls_T_u08, VAR(uint8, EPSDIAGSRVCS_VAR) CtrlByteLen_Cnt_T_u08, VAR(uint16, EPSDIAGSRVCS_VAR) LUTidx_Cnt_T_u16);
	#define D_EPS_DIAGSRV_RIDNUM_FCFA	0xFCFAU
#else
	#define EPSInternal_RID_FCFA	DiagSrvRIDNullFunc
#endif /* D_EPS_DIAGSRV_RID_FCFA */

#if (D_EPS_DIAGSRV_RID_FCFB == D_DIAGSRVC_ENABLED)
	extern FUNC(uint8, EPSDIAGSRVCS_CODE) EPSInternal_RID_FCFB (P2CONST(uint8, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) t_Param_Uls_T_u08, VAR(uint8, EPSDIAGSRVCS_VAR) CtrlByteLen_Cnt_T_u08, VAR(uint16, EPSDIAGSRVCS_VAR) LUTidx_Cnt_T_u16);
	#define D_EPS_DIAGSRV_RIDNUM_FCFB	0xFCFBU
#else
	#define EPSInternal_RID_FCFB	DiagSrvRIDNullFunc
#endif /* D_EPS_DIAGSRV_RID_FCFB */

#if (D_EPS_DIAGSRV_RID_FCFC == D_DIAGSRVC_ENABLED)
	extern FUNC(uint8, EPSDIAGSRVCS_CODE) EPSInternal_RID_FCFC (P2CONST(uint8, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) t_Param_Uls_T_u08, VAR(uint8, EPSDIAGSRVCS_VAR) CtrlByteLen_Cnt_T_u08, VAR(uint16, EPSDIAGSRVCS_VAR) LUTidx_Cnt_T_u16);
	#define D_EPS_DIAGSRV_RIDNUM_FCFC	0xFCFCU
#else
	#define EPSInternal_RID_FCFC	DiagSrvRIDNullFunc
#endif /* D_EPS_DIAGSRV_RID_FCFC */

#if (D_EPS_DIAGSRV_RID_FCFD == D_DIAGSRVC_ENABLED)
	extern FUNC(uint8, EPSDIAGSRVCS_CODE) EPSInternal_RID_FCFD (P2CONST(uint8, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) t_Param_Uls_T_u08, VAR(uint8, EPSDIAGSRVCS_VAR) CtrlByteLen_Cnt_T_u08, VAR(uint16, EPSDIAGSRVCS_VAR) LUTidx_Cnt_T_u16);
	#define D_EPS_DIAGSRV_RIDNUM_FCFD	0xFCFDU
#else
	#define EPSInternal_RID_FCFD	DiagSrvRIDNullFunc
#endif /* D_EPS_DIAGSRV_RID_FCFD */

#if (D_EPS_DIAGSRV_RID_FCFE == D_DIAGSRVC_ENABLED)
	extern FUNC(uint8, EPSDIAGSRVCS_CODE) EPSInternal_RID_FCFE (P2CONST(uint8, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) t_Param_Uls_T_u08, VAR(uint8, EPSDIAGSRVCS_VAR) CtrlByteLen_Cnt_T_u08, VAR(uint16, EPSDIAGSRVCS_VAR) LUTidx_Cnt_T_u16);
	#define D_EPS_DIAGSRV_RIDNUM_FCFE	0xFCFEU
#else
	#define EPSInternal_RID_FCFE	DiagSrvRIDNullFunc
#endif /* D_EPS_DIAGSRV_RID_FCFE */

#if (D_EPS_DIAGSRV_RID_FCFF == D_DIAGSRVC_ENABLED)
	extern FUNC(uint8, EPSDIAGSRVCS_CODE) EPSInternal_RID_FCFF (P2CONST(uint8, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) t_Param_Uls_T_u08, VAR(uint8, EPSDIAGSRVCS_VAR) CtrlByteLen_Cnt_T_u08, VAR(uint16, EPSDIAGSRVCS_VAR) LUTidx_Cnt_T_u16);
	#define D_EPS_DIAGSRV_RIDNUM_FCFF	0xFCFFU
#else
	#define EPSInternal_RID_FCFF	DiagSrvRIDNullFunc
#endif /* D_EPS_DIAGSRV_RID_FCFF */

/****************************************
 * PID & I/O Control                    *
 ***************************************/
#if (D_EPS_DIAGSRV_PID_FD01 == D_DIAGSRVC_ENABLED)
	extern FUNC(CM_MsgBufferType, EPSDIAGSRVCS_CODE) EPSInternal_PID_FD01 (VAR(CM_MsgBufferType, EPSDIAGSRVCS_VAR) pbDiagData, P2CONST(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) ReqLen_Cnt_T_u16, P2VAR(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) RespLength_Cnt_T_u16, VAR(uint8, EPSDIAGSRVCS_VAR) SrvcReqType_Cnt_T_u8, VAR(uint16, EPSDIAGSRVCS_VAR) LUTidx_Cnt_T_u16);
	#define D_EPS_DIAGSRV_PIDNUM_FD01	0xFD01U
#else
	#define EPSInternal_PID_FD01	DiagSrvPIDNullFunc
#endif /* D_EPS_DIAGSRV_PID_FD01 */

#if (D_EPS_DIAGSRV_PID_FD02 == D_DIAGSRVC_ENABLED)
	extern FUNC(CM_MsgBufferType, EPSDIAGSRVCS_CODE) EPSInternal_PID_FD02 (VAR(CM_MsgBufferType, EPSDIAGSRVCS_VAR) pbDiagData, P2CONST(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) ReqLen_Cnt_T_u16, P2VAR(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) RespLength_Cnt_T_u16, VAR(uint8, EPSDIAGSRVCS_VAR) SrvcReqType_Cnt_T_u8, VAR(uint16, EPSDIAGSRVCS_VAR) LUTidx_Cnt_T_u16);
	#define D_EPS_DIAGSRV_PIDNUM_FD02	0xFD02U
#else
	#define EPSInternal_PID_FD02	DiagSrvPIDNullFunc
#endif /* D_EPS_DIAGSRV_PID_FD02 */

#if (D_EPS_DIAGSRV_PID_FD03 == D_DIAGSRVC_ENABLED)
	extern FUNC(CM_MsgBufferType, EPSDIAGSRVCS_CODE) EPSInternal_PID_FD03 (VAR(CM_MsgBufferType, EPSDIAGSRVCS_VAR) pbDiagData, P2CONST(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) ReqLen_Cnt_T_u16, P2VAR(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) RespLength_Cnt_T_u16, VAR(uint8, EPSDIAGSRVCS_VAR) SrvcReqType_Cnt_T_u8, VAR(uint16, EPSDIAGSRVCS_VAR) LUTidx_Cnt_T_u16);
	#define D_EPS_DIAGSRV_PIDNUM_FD03	0xFD03U
#else
	#define EPSInternal_PID_FD03	DiagSrvPIDNullFunc
#endif /* D_EPS_DIAGSRV_PID_FD03 */

#if (D_EPS_DIAGSRV_PID_FD04 == D_DIAGSRVC_ENABLED)
	extern FUNC(CM_MsgBufferType, EPSDIAGSRVCS_CODE) EPSInternal_PID_FD04 (VAR(CM_MsgBufferType, EPSDIAGSRVCS_VAR) pbDiagData, P2CONST(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) ReqLen_Cnt_T_u16, P2VAR(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) RespLength_Cnt_T_u16, VAR(uint8, EPSDIAGSRVCS_VAR) SrvcReqType_Cnt_T_u8, VAR(uint16, EPSDIAGSRVCS_VAR) LUTidx_Cnt_T_u16);
	#define D_EPS_DIAGSRV_PIDNUM_FD04	0xFD04U
#else
	#define EPSInternal_PID_FD04	DiagSrvPIDNullFunc
#endif /* D_EPS_DIAGSRV_PID_FD04 */

#if (D_EPS_DIAGSRV_PID_FD05 == D_DIAGSRVC_ENABLED)
	extern FUNC(CM_MsgBufferType, EPSDIAGSRVCS_CODE) EPSInternal_PID_FD05 (VAR(CM_MsgBufferType, EPSDIAGSRVCS_VAR) pbDiagData, P2CONST(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) ReqLen_Cnt_T_u16, P2VAR(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) RespLength_Cnt_T_u16, VAR(uint8, EPSDIAGSRVCS_VAR) SrvcReqType_Cnt_T_u8, VAR(uint16, EPSDIAGSRVCS_VAR) LUTidx_Cnt_T_u16);
	#define D_EPS_DIAGSRV_PIDNUM_FD05	0xFD05U
#else
	#define EPSInternal_PID_FD05	DiagSrvPIDNullFunc
#endif /* D_EPS_DIAGSRV_PID_FD05 */

#if (D_EPS_DIAGSRV_PID_FD06 == D_DIAGSRVC_ENABLED)
	extern FUNC(CM_MsgBufferType, EPSDIAGSRVCS_CODE) EPSInternal_PID_FD06 (VAR(CM_MsgBufferType, EPSDIAGSRVCS_VAR) pbDiagData, P2CONST(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) ReqLen_Cnt_T_u16, P2VAR(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) RespLength_Cnt_T_u16, VAR(uint8, EPSDIAGSRVCS_VAR) SrvcReqType_Cnt_T_u8, VAR(uint16, EPSDIAGSRVCS_VAR) LUTidx_Cnt_T_u16);
	#define D_EPS_DIAGSRV_PIDNUM_FD06	0xFD06U
#else
	#define EPSInternal_PID_FD06	DiagSrvPIDNullFunc
#endif /* D_EPS_DIAGSRV_PID_FD06 */

#if (D_EPS_DIAGSRV_PID_FD07 == D_DIAGSRVC_ENABLED)
	extern FUNC(CM_MsgBufferType, EPSDIAGSRVCS_CODE) EPSInternal_PID_FD07 (VAR(CM_MsgBufferType, EPSDIAGSRVCS_VAR) pbDiagData, P2CONST(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) ReqLen_Cnt_T_u16, P2VAR(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) RespLength_Cnt_T_u16, VAR(uint8, EPSDIAGSRVCS_VAR) SrvcReqType_Cnt_T_u8, VAR(uint16, EPSDIAGSRVCS_VAR) LUTidx_Cnt_T_u16);
	#define D_EPS_DIAGSRV_PIDNUM_FD07	0xFD07U
#else
	#define EPSInternal_PID_FD07	DiagSrvPIDNullFunc
#endif /* D_EPS_DIAGSRV_PID_FD07 */

#if (D_EPS_DIAGSRV_PID_FD08 == D_DIAGSRVC_ENABLED)
	extern FUNC(CM_MsgBufferType, EPSDIAGSRVCS_CODE) EPSInternal_PID_FD08 (VAR(CM_MsgBufferType, EPSDIAGSRVCS_VAR) pbDiagData, P2CONST(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) ReqLen_Cnt_T_u16, P2VAR(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) RespLength_Cnt_T_u16, VAR(uint8, EPSDIAGSRVCS_VAR) SrvcReqType_Cnt_T_u8, VAR(uint16, EPSDIAGSRVCS_VAR) LUTidx_Cnt_T_u16);
	#define D_EPS_DIAGSRV_PIDNUM_FD08	0xFD08U
#else
	#define EPSInternal_PID_FD08	DiagSrvPIDNullFunc
#endif /* D_EPS_DIAGSRV_PID_FD08 */

#if (D_EPS_DIAGSRV_PID_FD09 == D_DIAGSRVC_ENABLED)
	extern FUNC(CM_MsgBufferType, EPSDIAGSRVCS_CODE) EPSInternal_PID_FD09 (VAR(CM_MsgBufferType, EPSDIAGSRVCS_VAR) pbDiagData, P2CONST(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) ReqLen_Cnt_T_u16, P2VAR(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) RespLength_Cnt_T_u16, VAR(uint8, EPSDIAGSRVCS_VAR) SrvcReqType_Cnt_T_u8, VAR(uint16, EPSDIAGSRVCS_VAR) LUTidx_Cnt_T_u16);
	#define D_EPS_DIAGSRV_PIDNUM_FD09	0xFD09U
#else
	#define EPSInternal_PID_FD09	DiagSrvPIDNullFunc
#endif /* D_EPS_DIAGSRV_PID_FD09 */

#if (D_EPS_DIAGSRV_PID_FD0A == D_DIAGSRVC_ENABLED)
	extern FUNC(CM_MsgBufferType, EPSDIAGSRVCS_CODE) EPSInternal_PID_FD0A (VAR(CM_MsgBufferType, EPSDIAGSRVCS_VAR) pbDiagData, P2CONST(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) ReqLen_Cnt_T_u16, P2VAR(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) RespLength_Cnt_T_u16, VAR(uint8, EPSDIAGSRVCS_VAR) SrvcReqType_Cnt_T_u8, VAR(uint16, EPSDIAGSRVCS_VAR) LUTidx_Cnt_T_u16);
	#define D_EPS_DIAGSRV_PIDNUM_FD0A	0xFD0AU
#else
	#define EPSInternal_PID_FD0A	DiagSrvPIDNullFunc
#endif /* D_EPS_DIAGSRV_PID_FD0A */

#if (D_EPS_DIAGSRV_PID_FD0B == D_DIAGSRVC_ENABLED)
	extern FUNC(CM_MsgBufferType, EPSDIAGSRVCS_CODE) EPSInternal_PID_FD0B (VAR(CM_MsgBufferType, EPSDIAGSRVCS_VAR) pbDiagData, P2CONST(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) ReqLen_Cnt_T_u16, P2VAR(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) RespLength_Cnt_T_u16, VAR(uint8, EPSDIAGSRVCS_VAR) SrvcReqType_Cnt_T_u8, VAR(uint16, EPSDIAGSRVCS_VAR) LUTidx_Cnt_T_u16);
	#define D_EPS_DIAGSRV_PIDNUM_FD0B	0xFD0BU
#else
	#define EPSInternal_PID_FD0B	DiagSrvPIDNullFunc
#endif /* D_EPS_DIAGSRV_PID_FD0B */

#if (D_EPS_DIAGSRV_PID_FD0C == D_DIAGSRVC_ENABLED)
	extern FUNC(CM_MsgBufferType, EPSDIAGSRVCS_CODE) EPSInternal_PID_FD0C (VAR(CM_MsgBufferType, EPSDIAGSRVCS_VAR) pbDiagData, P2CONST(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) ReqLen_Cnt_T_u16, P2VAR(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) RespLength_Cnt_T_u16, VAR(uint8, EPSDIAGSRVCS_VAR) SrvcReqType_Cnt_T_u8, VAR(uint16, EPSDIAGSRVCS_VAR) LUTidx_Cnt_T_u16);
	#define D_EPS_DIAGSRV_PIDNUM_FD0C	0xFD0CU
#else
	#define EPSInternal_PID_FD0C	DiagSrvPIDNullFunc
#endif /* D_EPS_DIAGSRV_PID_FD0C */

#if (D_EPS_DIAGSRV_IOC_FD0D == D_DIAGSRVC_ENABLED)
	extern FUNC(uint8, EPSDIAGSRVCS_CODE) EPSInternal_IOC_FD0D (P2CONST(uint8, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) t_Param_Uls_T_u08, VAR(uint8, EPSDIAGSRVCS_VAR) CtrlByteLen_Cnt_T_u08, VAR(uint16, EPSDIAGSRVCS_VAR) LUTidx_Cnt_T_u16);
	#define D_EPS_DIAGSRV_IOCNUM_FD0D	0xFD0DU
#else
	#define EPSInternal_IOC_FD0D	DiagSrvIOCNullFunc
#endif /* D_EPS_DIAGSRV_IOC_FD0D */

#if (D_EPS_DIAGSRV_PID_FD0E == D_DIAGSRVC_ENABLED)
	extern FUNC(CM_MsgBufferType, EPSDIAGSRVCS_CODE) EPSInternal_PID_FD0E (VAR(CM_MsgBufferType, EPSDIAGSRVCS_VAR) pbDiagData, P2CONST(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) ReqLen_Cnt_T_u16, P2VAR(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) RespLength_Cnt_T_u16, VAR(uint8, EPSDIAGSRVCS_VAR) SrvcReqType_Cnt_T_u8, VAR(uint16, EPSDIAGSRVCS_VAR) LUTidx_Cnt_T_u16);
	#define D_EPS_DIAGSRV_PIDNUM_FD0E	0xFD0EU
#else
	#define EPSInternal_PID_FD0E	DiagSrvPIDNullFunc
#endif /* D_EPS_DIAGSRV_PID_FD0E */

#if (D_EPS_DIAGSRV_PID_FD0F == D_DIAGSRVC_ENABLED)
	extern FUNC(CM_MsgBufferType, EPSDIAGSRVCS_CODE) EPSInternal_PID_FD0F (VAR(CM_MsgBufferType, EPSDIAGSRVCS_VAR) pbDiagData, P2CONST(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) ReqLen_Cnt_T_u16, P2VAR(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) RespLength_Cnt_T_u16, VAR(uint8, EPSDIAGSRVCS_VAR) SrvcReqType_Cnt_T_u8, VAR(uint16, EPSDIAGSRVCS_VAR) LUTidx_Cnt_T_u16);
	#define D_EPS_DIAGSRV_PIDNUM_FD0F	0xFD0FU
#else
	#define EPSInternal_PID_FD0F	DiagSrvPIDNullFunc
#endif /* D_EPS_DIAGSRV_PID_FD0F */

#if (D_EPS_DIAGSRV_PID_FD10 == D_DIAGSRVC_ENABLED)
	extern FUNC(CM_MsgBufferType, EPSDIAGSRVCS_CODE) EPSInternal_PID_FD10 (VAR(CM_MsgBufferType, EPSDIAGSRVCS_VAR) pbDiagData, P2CONST(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) ReqLen_Cnt_T_u16, P2VAR(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) RespLength_Cnt_T_u16, VAR(uint8, EPSDIAGSRVCS_VAR) SrvcReqType_Cnt_T_u8, VAR(uint16, EPSDIAGSRVCS_VAR) LUTidx_Cnt_T_u16);
	#define D_EPS_DIAGSRV_PIDNUM_FD10	0xFD10U
#else
	#define EPSInternal_PID_FD10	DiagSrvPIDNullFunc
#endif /* D_EPS_DIAGSRV_PID_FD10 */

#if (D_EPS_DIAGSRV_IOC_FD11 == D_DIAGSRVC_ENABLED)
	extern FUNC(uint8, EPSDIAGSRVCS_CODE) EPSInternal_IOC_FD11 (P2CONST(uint8, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) t_Param_Uls_T_u08, VAR(uint8, EPSDIAGSRVCS_VAR) CtrlByteLen_Cnt_T_u08, VAR(uint16, EPSDIAGSRVCS_VAR) LUTidx_Cnt_T_u16);
	#define D_EPS_DIAGSRV_IOCNUM_FD11	0xFD11U
#else
	#define EPSInternal_IOC_FD11	DiagSrvIOCNullFunc
#endif /* D_EPS_DIAGSRV_IOC_FD11 */

#if (D_EPS_DIAGSRV_PID_FD12 == D_DIAGSRVC_ENABLED)
	extern FUNC(CM_MsgBufferType, EPSDIAGSRVCS_CODE) EPSInternal_PID_FD12 (VAR(CM_MsgBufferType, EPSDIAGSRVCS_VAR) pbDiagData, P2CONST(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) ReqLen_Cnt_T_u16, P2VAR(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) RespLength_Cnt_T_u16, VAR(uint8, EPSDIAGSRVCS_VAR) SrvcReqType_Cnt_T_u8, VAR(uint16, EPSDIAGSRVCS_VAR) LUTidx_Cnt_T_u16);
	#define D_EPS_DIAGSRV_PIDNUM_FD12	0xFD12U
#else
	#define EPSInternal_PID_FD12	DiagSrvPIDNullFunc
#endif /* D_EPS_DIAGSRV_PID_FD12 */

#if (D_EPS_DIAGSRV_PID_FD13 == D_DIAGSRVC_ENABLED)
	extern FUNC(CM_MsgBufferType, EPSDIAGSRVCS_CODE) EPSInternal_PID_FD13 (VAR(CM_MsgBufferType, EPSDIAGSRVCS_VAR) pbDiagData, P2CONST(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) ReqLen_Cnt_T_u16, P2VAR(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) RespLength_Cnt_T_u16, VAR(uint8, EPSDIAGSRVCS_VAR) SrvcReqType_Cnt_T_u8, VAR(uint16, EPSDIAGSRVCS_VAR) LUTidx_Cnt_T_u16);
	#define D_EPS_DIAGSRV_PIDNUM_FD13	0xFD13U
#else
	#define EPSInternal_PID_FD13	DiagSrvPIDNullFunc
#endif /* D_EPS_DIAGSRV_PID_FD13 */

#if (D_EPS_DIAGSRV_PID_FD14 == D_DIAGSRVC_ENABLED)
	extern FUNC(CM_MsgBufferType, EPSDIAGSRVCS_CODE) EPSInternal_PID_FD14 (VAR(CM_MsgBufferType, EPSDIAGSRVCS_VAR) pbDiagData, P2CONST(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) ReqLen_Cnt_T_u16, P2VAR(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) RespLength_Cnt_T_u16, VAR(uint8, EPSDIAGSRVCS_VAR) SrvcReqType_Cnt_T_u8, VAR(uint16, EPSDIAGSRVCS_VAR) LUTidx_Cnt_T_u16);
	#define D_EPS_DIAGSRV_PIDNUM_FD14	0xFD14U
#else
	#define EPSInternal_PID_FD14	DiagSrvPIDNullFunc
#endif /* D_EPS_DIAGSRV_PID_FD14 */

#if (D_EPS_DIAGSRV_PID_FD15 == D_DIAGSRVC_ENABLED)
	extern FUNC(CM_MsgBufferType, EPSDIAGSRVCS_CODE) EPSInternal_PID_FD15 (VAR(CM_MsgBufferType, EPSDIAGSRVCS_VAR) pbDiagData, P2CONST(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) ReqLen_Cnt_T_u16, P2VAR(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) RespLength_Cnt_T_u16, VAR(uint8, EPSDIAGSRVCS_VAR) SrvcReqType_Cnt_T_u8, VAR(uint16, EPSDIAGSRVCS_VAR) LUTidx_Cnt_T_u16);
	#define D_EPS_DIAGSRV_PIDNUM_FD15	0xFD15U
#else
	#define EPSInternal_PID_FD15	DiagSrvPIDNullFunc
#endif /* D_EPS_DIAGSRV_PID_FD15 */

#if (D_EPS_DIAGSRV_PID_FD16 == D_DIAGSRVC_ENABLED)
	extern FUNC(CM_MsgBufferType, EPSDIAGSRVCS_CODE) EPSInternal_PID_FD16 (VAR(CM_MsgBufferType, EPSDIAGSRVCS_VAR) pbDiagData, P2CONST(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) ReqLen_Cnt_T_u16, P2VAR(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) RespLength_Cnt_T_u16, VAR(uint8, EPSDIAGSRVCS_VAR) SrvcReqType_Cnt_T_u8, VAR(uint16, EPSDIAGSRVCS_VAR) LUTidx_Cnt_T_u16);
	#define D_EPS_DIAGSRV_PIDNUM_FD16	0xFD16U
#else
	#define EPSInternal_PID_FD16	DiagSrvPIDNullFunc
#endif /* D_EPS_DIAGSRV_PID_FD16 */

#if (D_EPS_DIAGSRV_PID_FD18 == D_DIAGSRVC_ENABLED)
	extern FUNC(CM_MsgBufferType, EPSDIAGSRVCS_CODE) EPSInternal_PID_FD18 (VAR(CM_MsgBufferType, EPSDIAGSRVCS_VAR) pbDiagData, P2CONST(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) ReqLen_Cnt_T_u16, P2VAR(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) RespLength_Cnt_T_u16, VAR(uint8, EPSDIAGSRVCS_VAR) SrvcReqType_Cnt_T_u8, VAR(uint16, EPSDIAGSRVCS_VAR) LUTidx_Cnt_T_u16);
	#define D_EPS_DIAGSRV_PIDNUM_FD18	0xFD18U
#else
	#define EPSInternal_PID_FD18	DiagSrvPIDNullFunc
#endif /* D_EPS_DIAGSRV_PID_FD18 */

#if (D_EPS_DIAGSRV_PID_FD19 == D_DIAGSRVC_ENABLED)
	extern FUNC(CM_MsgBufferType, EPSDIAGSRVCS_CODE) EPSInternal_PID_FD19 (VAR(CM_MsgBufferType, EPSDIAGSRVCS_VAR) pbDiagData, P2CONST(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) ReqLen_Cnt_T_u16, P2VAR(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) RespLength_Cnt_T_u16, VAR(uint8, EPSDIAGSRVCS_VAR) SrvcReqType_Cnt_T_u8, VAR(uint16, EPSDIAGSRVCS_VAR) LUTidx_Cnt_T_u16);
	#define D_EPS_DIAGSRV_PIDNUM_FD19	0xFD19U
#else
	#define EPSInternal_PID_FD19	DiagSrvPIDNullFunc
#endif /* D_EPS_DIAGSRV_PID_FD19 */

#if (D_EPS_DIAGSRV_PID_FD1A == D_DIAGSRVC_ENABLED)
	extern FUNC(CM_MsgBufferType, EPSDIAGSRVCS_CODE) EPSInternal_PID_FD1A (VAR(CM_MsgBufferType, EPSDIAGSRVCS_VAR) pbDiagData, P2CONST(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) ReqLen_Cnt_T_u16, P2VAR(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) RespLength_Cnt_T_u16, VAR(uint8, EPSDIAGSRVCS_VAR) SrvcReqType_Cnt_T_u8, VAR(uint16, EPSDIAGSRVCS_VAR) LUTidx_Cnt_T_u16);
	#define D_EPS_DIAGSRV_PIDNUM_FD1A	0xFD1AU
#else
	#define EPSInternal_PID_FD1A	DiagSrvPIDNullFunc
#endif /* D_EPS_DIAGSRV_PID_FD1A */

#if (D_EPS_DIAGSRV_PID_FD1B == D_DIAGSRVC_ENABLED)
	extern FUNC(CM_MsgBufferType, EPSDIAGSRVCS_CODE) EPSInternal_PID_FD1B (VAR(CM_MsgBufferType, EPSDIAGSRVCS_VAR) pbDiagData, P2CONST(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) ReqLen_Cnt_T_u16, P2VAR(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) RespLength_Cnt_T_u16, VAR(uint8, EPSDIAGSRVCS_VAR) SrvcReqType_Cnt_T_u8, VAR(uint16, EPSDIAGSRVCS_VAR) LUTidx_Cnt_T_u16);
	#define D_EPS_DIAGSRV_PIDNUM_FD1B	0xFD1BU
#else
	#define EPSInternal_PID_FD1B	DiagSrvPIDNullFunc
#endif /* D_EPS_DIAGSRV_PID_FD1B */

#if (D_EPS_DIAGSRV_PID_FD1C == D_DIAGSRVC_ENABLED)
	extern FUNC(CM_MsgBufferType, EPSDIAGSRVCS_CODE) EPSInternal_PID_FD1C (VAR(CM_MsgBufferType, EPSDIAGSRVCS_VAR) pbDiagData, P2CONST(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) ReqLen_Cnt_T_u16, P2VAR(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) RespLength_Cnt_T_u16, VAR(uint8, EPSDIAGSRVCS_VAR) SrvcReqType_Cnt_T_u8, VAR(uint16, EPSDIAGSRVCS_VAR) LUTidx_Cnt_T_u16);
	#define D_EPS_DIAGSRV_PIDNUM_FD1C	0xFD1CU
#else
	#define EPSInternal_PID_FD1C	DiagSrvPIDNullFunc
#endif /* D_EPS_DIAGSRV_PID_FD1C */

#if (D_EPS_DIAGSRV_PID_FD1D == D_DIAGSRVC_ENABLED)
	extern FUNC(CM_MsgBufferType, EPSDIAGSRVCS_CODE) EPSInternal_PID_FD1D (VAR(CM_MsgBufferType, EPSDIAGSRVCS_VAR) pbDiagData, P2CONST(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) ReqLen_Cnt_T_u16, P2VAR(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) RespLength_Cnt_T_u16, VAR(uint8, EPSDIAGSRVCS_VAR) SrvcReqType_Cnt_T_u8, VAR(uint16, EPSDIAGSRVCS_VAR) LUTidx_Cnt_T_u16);
	#define D_EPS_DIAGSRV_PIDNUM_FD1D	0xFD1DU
#else
	#define EPSInternal_PID_FD1D	DiagSrvPIDNullFunc
#endif /* D_EPS_DIAGSRV_PID_FD1D */

#if (D_EPS_DIAGSRV_PID_FD1E == D_DIAGSRVC_ENABLED)
	extern FUNC(CM_MsgBufferType, EPSDIAGSRVCS_CODE) EPSInternal_PID_FD1E (VAR(CM_MsgBufferType, EPSDIAGSRVCS_VAR) pbDiagData, P2CONST(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) ReqLen_Cnt_T_u16, P2VAR(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) RespLength_Cnt_T_u16, VAR(uint8, EPSDIAGSRVCS_VAR) SrvcReqType_Cnt_T_u8, VAR(uint16, EPSDIAGSRVCS_VAR) LUTidx_Cnt_T_u16);
	#define D_EPS_DIAGSRV_PIDNUM_FD1E	0xFD1EU
#else
	#define EPSInternal_PID_FD1E	DiagSrvPIDNullFunc
#endif /* D_EPS_DIAGSRV_PID_FD1E */

#if (D_EPS_DIAGSRV_PID_FD1F == D_DIAGSRVC_ENABLED)
	extern FUNC(CM_MsgBufferType, EPSDIAGSRVCS_CODE) EPSInternal_PID_FD1F (VAR(CM_MsgBufferType, EPSDIAGSRVCS_VAR) pbDiagData, P2CONST(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) ReqLen_Cnt_T_u16, P2VAR(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) RespLength_Cnt_T_u16, VAR(uint8, EPSDIAGSRVCS_VAR) SrvcReqType_Cnt_T_u8, VAR(uint16, EPSDIAGSRVCS_VAR) LUTidx_Cnt_T_u16);
	#define D_EPS_DIAGSRV_PIDNUM_FD1F	0xFD1FU
#else
	#define EPSInternal_PID_FD1F	DiagSrvPIDNullFunc
#endif /* D_EPS_DIAGSRV_PID_FD1F */

#if (D_EPS_DIAGSRV_PID_FD21 == D_DIAGSRVC_ENABLED)
	extern FUNC(CM_MsgBufferType, EPSDIAGSRVCS_CODE) EPSInternal_PID_FD21 (VAR(CM_MsgBufferType, EPSDIAGSRVCS_VAR) pbDiagData, P2CONST(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) ReqLen_Cnt_T_u16, P2VAR(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) RespLength_Cnt_T_u16, VAR(uint8, EPSDIAGSRVCS_VAR) SrvcReqType_Cnt_T_u8, VAR(uint16, EPSDIAGSRVCS_VAR) LUTidx_Cnt_T_u16);
	#define D_EPS_DIAGSRV_PIDNUM_FD21	0xFD21U
#else
	#define EPSInternal_PID_FD21	DiagSrvPIDNullFunc
#endif /* D_EPS_DIAGSRV_PID_FD21 */

#if (D_EPS_DIAGSRV_PID_FD25 == D_DIAGSRVC_ENABLED)
	extern FUNC(CM_MsgBufferType, EPSDIAGSRVCS_CODE) EPSInternal_PID_FD25 (VAR(CM_MsgBufferType, EPSDIAGSRVCS_VAR) pbDiagData, P2CONST(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) ReqLen_Cnt_T_u16, P2VAR(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) RespLength_Cnt_T_u16, VAR(uint8, EPSDIAGSRVCS_VAR) SrvcReqType_Cnt_T_u8, VAR(uint16, EPSDIAGSRVCS_VAR) LUTidx_Cnt_T_u16);
	#define D_EPS_DIAGSRV_PIDNUM_FD25	0xFD25U
#else
	#define EPSInternal_PID_FD25	DiagSrvPIDNullFunc
#endif /* D_EPS_DIAGSRV_PID_FD25 */

#if (D_EPS_DIAGSRV_PID_FD41 == D_DIAGSRVC_ENABLED)
	extern FUNC(CM_MsgBufferType, EPSDIAGSRVCS_CODE) EPSInternal_PID_FD41 (VAR(CM_MsgBufferType, EPSDIAGSRVCS_VAR) pbDiagData, P2CONST(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) ReqLen_Cnt_T_u16, P2VAR(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) RespLength_Cnt_T_u16, VAR(uint8, EPSDIAGSRVCS_VAR) SrvcReqType_Cnt_T_u8, VAR(uint16, EPSDIAGSRVCS_VAR) LUTidx_Cnt_T_u16);
	#define D_EPS_DIAGSRV_PIDNUM_FD41	0xFD41U
#else
	#define EPSInternal_PID_FD41	DiagSrvPIDNullFunc
#endif /* D_EPS_DIAGSRV_PID_FD41 */

#if (D_EPS_DIAGSRV_PID_FDA0 == D_DIAGSRVC_ENABLED)
	extern FUNC(CM_MsgBufferType, EPSDIAGSRVCS_CODE) EPSInternal_PID_FDA0 (VAR(CM_MsgBufferType, EPSDIAGSRVCS_VAR) pbDiagData, P2CONST(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) ReqLen_Cnt_T_u16, P2VAR(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) RespLength_Cnt_T_u16, VAR(uint8, EPSDIAGSRVCS_VAR) SrvcReqType_Cnt_T_u8, VAR(uint16, EPSDIAGSRVCS_VAR) LUTidx_Cnt_T_u16);
	#define D_EPS_DIAGSRV_PIDNUM_FDA0	0xFDA0U
#else
	#define EPSInternal_PID_FDA0	DiagSrvPIDNullFunc
#endif /* D_EPS_DIAGSRV_PID_FDA0 */

#if (D_EPS_DIAGSRV_PID_FDA1 == D_DIAGSRVC_ENABLED)
	extern FUNC(CM_MsgBufferType, EPSDIAGSRVCS_CODE) EPSInternal_PID_FDA1 (VAR(CM_MsgBufferType, EPSDIAGSRVCS_VAR) pbDiagData, P2CONST(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) ReqLen_Cnt_T_u16, P2VAR(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) RespLength_Cnt_T_u16, VAR(uint8, EPSDIAGSRVCS_VAR) SrvcReqType_Cnt_T_u8, VAR(uint16, EPSDIAGSRVCS_VAR) LUTidx_Cnt_T_u16);
	#define D_EPS_DIAGSRV_PIDNUM_FDA1	0xFDA1U
#else
	#define EPSInternal_PID_FDA1	DiagSrvPIDNullFunc
#endif /* D_EPS_DIAGSRV_PID_FDA1 */

#if (D_EPS_DIAGSRV_PID_FDA2 == D_DIAGSRVC_ENABLED)
	extern FUNC(CM_MsgBufferType, EPSDIAGSRVCS_CODE) EPSInternal_PID_FDA2 (VAR(CM_MsgBufferType, EPSDIAGSRVCS_VAR) pbDiagData, P2CONST(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) ReqLen_Cnt_T_u16, P2VAR(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) RespLength_Cnt_T_u16, VAR(uint8, EPSDIAGSRVCS_VAR) SrvcReqType_Cnt_T_u8, VAR(uint16, EPSDIAGSRVCS_VAR) LUTidx_Cnt_T_u16);
	#define D_EPS_DIAGSRV_PIDNUM_FDA2	0xFDA2U
#else
	#define EPSInternal_PID_FDA2	DiagSrvPIDNullFunc
#endif /* D_EPS_DIAGSRV_PID_FDA2 */

#if (D_EPS_DIAGSRV_PID_FDA3 == D_DIAGSRVC_ENABLED)
	extern FUNC(CM_MsgBufferType, EPSDIAGSRVCS_CODE) EPSInternal_PID_FDA3 (VAR(CM_MsgBufferType, EPSDIAGSRVCS_VAR) pbDiagData, P2CONST(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) ReqLen_Cnt_T_u16, P2VAR(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) RespLength_Cnt_T_u16, VAR(uint8, EPSDIAGSRVCS_VAR) SrvcReqType_Cnt_T_u8, VAR(uint16, EPSDIAGSRVCS_VAR) LUTidx_Cnt_T_u16);
	#define D_EPS_DIAGSRV_PIDNUM_FDA3	0xFDA3U
#else
	#define EPSInternal_PID_FDA3	DiagSrvPIDNullFunc
#endif /* D_EPS_DIAGSRV_PID_FDA3 */

#if (D_EPS_DIAGSRV_PID_FDA4 == D_DIAGSRVC_ENABLED)
	extern FUNC(CM_MsgBufferType, EPSDIAGSRVCS_CODE) EPSInternal_PID_FDA4 (VAR(CM_MsgBufferType, EPSDIAGSRVCS_VAR) pbDiagData, P2CONST(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) ReqLen_Cnt_T_u16, P2VAR(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) RespLength_Cnt_T_u16, VAR(uint8, EPSDIAGSRVCS_VAR) SrvcReqType_Cnt_T_u8, VAR(uint16, EPSDIAGSRVCS_VAR) LUTidx_Cnt_T_u16);
	#define D_EPS_DIAGSRV_PIDNUM_FDA4	0xFDA4U
#else
	#define EPSInternal_PID_FDA4	DiagSrvPIDNullFunc
#endif /* D_EPS_DIAGSRV_PID_FDA4 */

#if (D_EPS_DIAGSRV_PID_FDA5 == D_DIAGSRVC_ENABLED)
	extern FUNC(CM_MsgBufferType, EPSDIAGSRVCS_CODE) EPSInternal_PID_FDA5 (VAR(CM_MsgBufferType, EPSDIAGSRVCS_VAR) pbDiagData, P2CONST(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) ReqLen_Cnt_T_u16, P2VAR(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) RespLength_Cnt_T_u16, VAR(uint8, EPSDIAGSRVCS_VAR) SrvcReqType_Cnt_T_u8, VAR(uint16, EPSDIAGSRVCS_VAR) LUTidx_Cnt_T_u16);
	#define D_EPS_DIAGSRV_PIDNUM_FDA5	0xFDA5U
#else
	#define EPSInternal_PID_FDA5	DiagSrvPIDNullFunc
#endif /* D_EPS_DIAGSRV_PID_FDA5 */

#if (D_EPS_DIAGSRV_PID_FDA7 == D_DIAGSRVC_ENABLED)
	extern FUNC(CM_MsgBufferType, EPSDIAGSRVCS_CODE) EPSInternal_PID_FDA7 (VAR(CM_MsgBufferType, EPSDIAGSRVCS_VAR) pbDiagData, P2CONST(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) ReqLen_Cnt_T_u16, P2VAR(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) RespLength_Cnt_T_u16, VAR(uint8, EPSDIAGSRVCS_VAR) SrvcReqType_Cnt_T_u8, VAR(uint16, EPSDIAGSRVCS_VAR) LUTidx_Cnt_T_u16);
	#define D_EPS_DIAGSRV_PIDNUM_FDA7	0xFDA7U
#else
	#define EPSInternal_PID_FDA7	DiagSrvPIDNullFunc
#endif /* D_EPS_DIAGSRV_PID_FDA7 */

#if (D_EPS_DIAGSRV_PID_FDA8 == D_DIAGSRVC_ENABLED)
	extern FUNC(CM_MsgBufferType, EPSDIAGSRVCS_CODE) EPSInternal_PID_FDA8 (VAR(CM_MsgBufferType, EPSDIAGSRVCS_VAR) pbDiagData, P2CONST(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) ReqLen_Cnt_T_u16, P2VAR(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) RespLength_Cnt_T_u16, VAR(uint8, EPSDIAGSRVCS_VAR) SrvcReqType_Cnt_T_u8, VAR(uint16, EPSDIAGSRVCS_VAR) LUTidx_Cnt_T_u16);
	#define D_EPS_DIAGSRV_PIDNUM_FDA8	0xFDA8U
#else
	#define EPSInternal_PID_FDA8	DiagSrvPIDNullFunc
#endif /* D_EPS_DIAGSRV_PID_FDA8 */

#if (D_EPS_DIAGSRV_PID_FDA9 == D_DIAGSRVC_ENABLED)
	extern FUNC(CM_MsgBufferType, EPSDIAGSRVCS_CODE) EPSInternal_PID_FDA9 (VAR(CM_MsgBufferType, EPSDIAGSRVCS_VAR) pbDiagData, P2CONST(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) ReqLen_Cnt_T_u16, P2VAR(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) RespLength_Cnt_T_u16, VAR(uint8, EPSDIAGSRVCS_VAR) SrvcReqType_Cnt_T_u8, VAR(uint16, EPSDIAGSRVCS_VAR) LUTidx_Cnt_T_u16);
	#define D_EPS_DIAGSRV_PIDNUM_FDA9	0xFDA9U
#else
	#define EPSInternal_PID_FDA9	DiagSrvPIDNullFunc
#endif /* D_EPS_DIAGSRV_PID_FDA9 */

#if (D_EPS_DIAGSRV_PID_FDAC == D_DIAGSRVC_ENABLED)
	extern FUNC(CM_MsgBufferType, EPSDIAGSRVCS_CODE) EPSInternal_PID_FDAC (VAR(CM_MsgBufferType, EPSDIAGSRVCS_VAR) pbDiagData, P2CONST(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) ReqLen_Cnt_T_u16, P2VAR(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) RespLength_Cnt_T_u16, VAR(uint8, EPSDIAGSRVCS_VAR) SrvcReqType_Cnt_T_u8, VAR(uint16, EPSDIAGSRVCS_VAR) LUTidx_Cnt_T_u16);
	#define D_EPS_DIAGSRV_PIDNUM_FDAC	0xFDACU
#else
	#define EPSInternal_PID_FDAC	DiagSrvPIDNullFunc
#endif /* D_EPS_DIAGSRV_PID_FDAC */

#if (D_EPS_DIAGSRV_PID_FDAD == D_DIAGSRVC_ENABLED)
	extern FUNC(CM_MsgBufferType, EPSDIAGSRVCS_CODE) EPSInternal_PID_FDAD (VAR(CM_MsgBufferType, EPSDIAGSRVCS_VAR) pbDiagData, P2CONST(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) ReqLen_Cnt_T_u16, P2VAR(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) RespLength_Cnt_T_u16, VAR(uint8, EPSDIAGSRVCS_VAR) SrvcReqType_Cnt_T_u8, VAR(uint16, EPSDIAGSRVCS_VAR) LUTidx_Cnt_T_u16);
	#define D_EPS_DIAGSRV_PIDNUM_FDAD	0xFDADU
#else
	#define EPSInternal_PID_FDAD	DiagSrvPIDNullFunc
#endif /* D_EPS_DIAGSRV_PID_FDAD */

#if (D_EPS_DIAGSRV_PID_FDAE == D_DIAGSRVC_ENABLED)
	extern FUNC(CM_MsgBufferType, EPSDIAGSRVCS_CODE) EPSInternal_PID_FDAE (VAR(CM_MsgBufferType, EPSDIAGSRVCS_VAR) pbDiagData, P2CONST(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) ReqLen_Cnt_T_u16, P2VAR(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) RespLength_Cnt_T_u16, VAR(uint8, EPSDIAGSRVCS_VAR) SrvcReqType_Cnt_T_u8, VAR(uint16, EPSDIAGSRVCS_VAR) LUTidx_Cnt_T_u16);
	#define D_EPS_DIAGSRV_PIDNUM_FDAE	0xFDAEU
#else
	#define EPSInternal_PID_FDAE	DiagSrvPIDNullFunc
#endif /* D_EPS_DIAGSRV_PID_FDAE */

#if (D_EPS_DIAGSRV_PID_FDAF == D_DIAGSRVC_ENABLED)
	extern FUNC(CM_MsgBufferType, EPSDIAGSRVCS_CODE) EPSInternal_PID_FDAF (VAR(CM_MsgBufferType, EPSDIAGSRVCS_VAR) pbDiagData, P2CONST(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) ReqLen_Cnt_T_u16, P2VAR(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) RespLength_Cnt_T_u16, VAR(uint8, EPSDIAGSRVCS_VAR) SrvcReqType_Cnt_T_u8, VAR(uint16, EPSDIAGSRVCS_VAR) LUTidx_Cnt_T_u16);
	#define D_EPS_DIAGSRV_PIDNUM_FDAF	0xFDAFU
#else
	#define EPSInternal_PID_FDAF	DiagSrvPIDNullFunc
#endif /* D_EPS_DIAGSRV_PID_FDAF */

#if (D_EPS_DIAGSRV_PID_FDB0 == D_DIAGSRVC_ENABLED)
	extern FUNC(CM_MsgBufferType, EPSDIAGSRVCS_CODE) EPSInternal_PID_FDB0 (VAR(CM_MsgBufferType, EPSDIAGSRVCS_VAR) pbDiagData, P2CONST(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) ReqLen_Cnt_T_u16, P2VAR(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) RespLength_Cnt_T_u16, VAR(uint8, EPSDIAGSRVCS_VAR) SrvcReqType_Cnt_T_u8, VAR(uint16, EPSDIAGSRVCS_VAR) LUTidx_Cnt_T_u16);
	#define D_EPS_DIAGSRV_PIDNUM_FDB0	0xFDB0U
#else
	#define EPSInternal_PID_FDB0	DiagSrvPIDNullFunc
#endif /* D_EPS_DIAGSRV_PID_FDB0 */

#if (D_EPS_DIAGSRV_PID_FDB1 == D_DIAGSRVC_ENABLED)
	extern FUNC(CM_MsgBufferType, EPSDIAGSRVCS_CODE) EPSInternal_PID_FDB1 (VAR(CM_MsgBufferType, EPSDIAGSRVCS_VAR) pbDiagData, P2CONST(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) ReqLen_Cnt_T_u16, P2VAR(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) RespLength_Cnt_T_u16, VAR(uint8, EPSDIAGSRVCS_VAR) SrvcReqType_Cnt_T_u8, VAR(uint16, EPSDIAGSRVCS_VAR) LUTidx_Cnt_T_u16);
	#define D_EPS_DIAGSRV_PIDNUM_FDB1	0xFDB1U
#else
	#define EPSInternal_PID_FDB1	DiagSrvPIDNullFunc
#endif /* D_EPS_DIAGSRV_PID_FDB1 */

#if (D_EPS_DIAGSRV_PID_FDB2 == D_DIAGSRVC_ENABLED)
	extern FUNC(CM_MsgBufferType, EPSDIAGSRVCS_CODE) EPSInternal_PID_FDB2 (VAR(CM_MsgBufferType, EPSDIAGSRVCS_VAR) pbDiagData, P2CONST(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) ReqLen_Cnt_T_u16, P2VAR(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) RespLength_Cnt_T_u16, VAR(uint8, EPSDIAGSRVCS_VAR) SrvcReqType_Cnt_T_u8, VAR(uint16, EPSDIAGSRVCS_VAR) LUTidx_Cnt_T_u16);
	#define D_EPS_DIAGSRV_PIDNUM_FDB2	0xFDB2U
#else
	#define EPSInternal_PID_FDB2	DiagSrvPIDNullFunc
#endif /* D_EPS_DIAGSRV_PID_FDB2 */

#if (D_EPS_DIAGSRV_PID_FDB3 == D_DIAGSRVC_ENABLED)
	extern FUNC(CM_MsgBufferType, EPSDIAGSRVCS_CODE) EPSInternal_PID_FDB3 (VAR(CM_MsgBufferType, EPSDIAGSRVCS_VAR) pbDiagData, P2CONST(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) ReqLen_Cnt_T_u16, P2VAR(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) RespLength_Cnt_T_u16, VAR(uint8, EPSDIAGSRVCS_VAR) SrvcReqType_Cnt_T_u8, VAR(uint16, EPSDIAGSRVCS_VAR) LUTidx_Cnt_T_u16);
	#define D_EPS_DIAGSRV_PIDNUM_FDB3	0xFDB3U
#else
	#define EPSInternal_PID_FDB3	DiagSrvPIDNullFunc
#endif /* D_EPS_DIAGSRV_PID_FDB3 */

#if (D_EPS_DIAGSRV_PID_FDB4 == D_DIAGSRVC_ENABLED)
	extern FUNC(CM_MsgBufferType, EPSDIAGSRVCS_CODE) EPSInternal_PID_FDB4 (VAR(CM_MsgBufferType, EPSDIAGSRVCS_VAR) pbDiagData, P2CONST(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) ReqLen_Cnt_T_u16, P2VAR(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) RespLength_Cnt_T_u16, VAR(uint8, EPSDIAGSRVCS_VAR) SrvcReqType_Cnt_T_u8, VAR(uint16, EPSDIAGSRVCS_VAR) LUTidx_Cnt_T_u16);
	#define D_EPS_DIAGSRV_PIDNUM_FDB4	0xFDB4U
#else
	#define EPSInternal_PID_FDB4	DiagSrvPIDNullFunc
#endif /* D_EPS_DIAGSRV_PID_FDB4 */

#if (D_EPS_DIAGSRV_PID_FDB5 == D_DIAGSRVC_ENABLED)
	extern FUNC(CM_MsgBufferType, EPSDIAGSRVCS_CODE) EPSInternal_PID_FDB5 (VAR(CM_MsgBufferType, EPSDIAGSRVCS_VAR) pbDiagData, P2CONST(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) ReqLen_Cnt_T_u16, P2VAR(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) RespLength_Cnt_T_u16, VAR(uint8, EPSDIAGSRVCS_VAR) SrvcReqType_Cnt_T_u8, VAR(uint16, EPSDIAGSRVCS_VAR) LUTidx_Cnt_T_u16);
	#define D_EPS_DIAGSRV_PIDNUM_FDB5	0xFDB5U
#else
	#define EPSInternal_PID_FDB5	DiagSrvPIDNullFunc
#endif /* D_EPS_DIAGSRV_PID_FDB5 */

#if (D_EPS_DIAGSRV_PID_FDB6 == D_DIAGSRVC_ENABLED)
	extern FUNC(CM_MsgBufferType, EPSDIAGSRVCS_CODE) EPSInternal_PID_FDB6 (VAR(CM_MsgBufferType, EPSDIAGSRVCS_VAR) pbDiagData, P2CONST(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) ReqLen_Cnt_T_u16, P2VAR(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) RespLength_Cnt_T_u16, VAR(uint8, EPSDIAGSRVCS_VAR) SrvcReqType_Cnt_T_u8, VAR(uint16, EPSDIAGSRVCS_VAR) LUTidx_Cnt_T_u16);
	#define D_EPS_DIAGSRV_PIDNUM_FDB6	0xFDB6U
#else
	#define EPSInternal_PID_FDB6	DiagSrvPIDNullFunc
#endif /* D_EPS_DIAGSRV_PID_FDB6 */

/****************************************
 * Customer PID & I/O Control Services  *
 ***************************************/
#if (D_EPS_DIAGSRV_PID_FEE0 == D_DIAGSRVC_ENABLED)
	extern FUNC(CM_MsgBufferType, EPSDIAGSRVCS_CODE) EPSInternal_PID_FEE0 (VAR(CM_MsgBufferType, EPSDIAGSRVCS_VAR) pbDiagData, P2CONST(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) ReqLen_Cnt_T_u16, P2VAR(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) RespLength_Cnt_T_u16, VAR(uint8, EPSDIAGSRVCS_VAR) SrvcReqType_Cnt_T_u8, VAR(uint16, EPSDIAGSRVCS_VAR) LUTidx_Cnt_T_u16);
	#define D_EPS_DIAGSRV_PIDNUM_FEE0	0xFEE0U
#else
	#define EPSInternal_PID_FEE0	DiagSrvPIDNullFunc
#endif /* D_EPS_DIAGSRV_PID_FEE0 */

#if (D_EPS_DIAGSRV_PID_FEE1 == D_DIAGSRVC_ENABLED)
	extern FUNC(CM_MsgBufferType, EPSDIAGSRVCS_CODE) EPSInternal_PID_FEE1 (VAR(CM_MsgBufferType, EPSDIAGSRVCS_VAR) pbDiagData, P2CONST(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) ReqLen_Cnt_T_u16, P2VAR(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) RespLength_Cnt_T_u16, VAR(uint8, EPSDIAGSRVCS_VAR) SrvcReqType_Cnt_T_u8, VAR(uint16, EPSDIAGSRVCS_VAR) LUTidx_Cnt_T_u16);
	#define D_EPS_DIAGSRV_PIDNUM_FEE1	0xFEE1U
#else
	#define EPSInternal_PID_FEE1	DiagSrvPIDNullFunc
#endif /* D_EPS_DIAGSRV_PID_FEE1 */

#if (D_EPS_DIAGSRV_PID_FEE2 == D_DIAGSRVC_ENABLED)
	extern FUNC(CM_MsgBufferType, EPSDIAGSRVCS_CODE) EPSInternal_PID_FEE2 (VAR(CM_MsgBufferType, EPSDIAGSRVCS_VAR) pbDiagData, P2CONST(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) ReqLen_Cnt_T_u16, P2VAR(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) RespLength_Cnt_T_u16, VAR(uint8, EPSDIAGSRVCS_VAR) SrvcReqType_Cnt_T_u8, VAR(uint16, EPSDIAGSRVCS_VAR) LUTidx_Cnt_T_u16);
	#define D_EPS_DIAGSRV_PIDNUM_FEE2	0xFEE2U
#else
	#define EPSInternal_PID_FEE2	DiagSrvPIDNullFunc
#endif /* D_EPS_DIAGSRV_PID_FEE2 */

#if (D_EPS_DIAGSRV_PID_FEE3 == D_DIAGSRVC_ENABLED)
	extern FUNC(CM_MsgBufferType, EPSDIAGSRVCS_CODE) EPSInternal_PID_FEE3 (VAR(CM_MsgBufferType, EPSDIAGSRVCS_VAR) pbDiagData, P2CONST(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) ReqLen_Cnt_T_u16, P2VAR(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) RespLength_Cnt_T_u16, VAR(uint8, EPSDIAGSRVCS_VAR) SrvcReqType_Cnt_T_u8, VAR(uint16, EPSDIAGSRVCS_VAR) LUTidx_Cnt_T_u16);
	#define D_EPS_DIAGSRV_PIDNUM_FEE3	0xFEE3U
#else
	#define EPSInternal_PID_FEE3	DiagSrvPIDNullFunc
#endif /* D_EPS_DIAGSRV_PID_FEE3 */

#if (D_EPS_DIAGSRV_PID_FEE4 == D_DIAGSRVC_ENABLED)
	extern FUNC(CM_MsgBufferType, EPSDIAGSRVCS_CODE) EPSInternal_PID_FEE4 (VAR(CM_MsgBufferType, EPSDIAGSRVCS_VAR) pbDiagData, P2CONST(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) ReqLen_Cnt_T_u16, P2VAR(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) RespLength_Cnt_T_u16, VAR(uint8, EPSDIAGSRVCS_VAR) SrvcReqType_Cnt_T_u8, VAR(uint16, EPSDIAGSRVCS_VAR) LUTidx_Cnt_T_u16);
	#define D_EPS_DIAGSRV_PIDNUM_FEE4	0xFEE4U
#else
	#define EPSInternal_PID_FEE4	DiagSrvPIDNullFunc
#endif /* D_EPS_DIAGSRV_PID_FEE4 */

#if (D_EPS_DIAGSRV_PID_FEE5 == D_DIAGSRVC_ENABLED)
	extern FUNC(CM_MsgBufferType, EPSDIAGSRVCS_CODE) EPSInternal_PID_FEE5 (VAR(CM_MsgBufferType, EPSDIAGSRVCS_VAR) pbDiagData, P2CONST(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) ReqLen_Cnt_T_u16, P2VAR(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) RespLength_Cnt_T_u16, VAR(uint8, EPSDIAGSRVCS_VAR) SrvcReqType_Cnt_T_u8, VAR(uint16, EPSDIAGSRVCS_VAR) LUTidx_Cnt_T_u16);
	#define D_EPS_DIAGSRV_PIDNUM_FEE5	0xFEE5U
#else
	#define EPSInternal_PID_FEE5	DiagSrvPIDNullFunc
#endif /* D_EPS_DIAGSRV_PID_FEE5 */

#if (D_EPS_DIAGSRV_PID_FEE6 == D_DIAGSRVC_ENABLED)
	extern FUNC(CM_MsgBufferType, EPSDIAGSRVCS_CODE) EPSInternal_PID_FEE6 (VAR(CM_MsgBufferType, EPSDIAGSRVCS_VAR) pbDiagData, P2CONST(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) ReqLen_Cnt_T_u16, P2VAR(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) RespLength_Cnt_T_u16, VAR(uint8, EPSDIAGSRVCS_VAR) SrvcReqType_Cnt_T_u8, VAR(uint16, EPSDIAGSRVCS_VAR) LUTidx_Cnt_T_u16);
	#define D_EPS_DIAGSRV_PIDNUM_FEE6	0xFEE6U
#else
	#define EPSInternal_PID_FEE6	DiagSrvPIDNullFunc
#endif /* D_EPS_DIAGSRV_PID_FEE6 */

#if (D_EPS_DIAGSRV_PID_FEE7 == D_DIAGSRVC_ENABLED)
	extern FUNC(CM_MsgBufferType, EPSDIAGSRVCS_CODE) EPSInternal_PID_FEE7 (VAR(CM_MsgBufferType, EPSDIAGSRVCS_VAR) pbDiagData, P2CONST(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) ReqLen_Cnt_T_u16, P2VAR(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) RespLength_Cnt_T_u16, VAR(uint8, EPSDIAGSRVCS_VAR) SrvcReqType_Cnt_T_u8, VAR(uint16, EPSDIAGSRVCS_VAR) LUTidx_Cnt_T_u16);
	#define D_EPS_DIAGSRV_PIDNUM_FEE7	0xFEE7U
#else
	#define EPSInternal_PID_FEE7	DiagSrvPIDNullFunc
#endif /* D_EPS_DIAGSRV_PID_FEE7 */

#if (D_EPS_DIAGSRV_PID_FEE8 == D_DIAGSRVC_ENABLED)
	extern FUNC(CM_MsgBufferType, EPSDIAGSRVCS_CODE) EPSInternal_PID_FEE8 (VAR(CM_MsgBufferType, EPSDIAGSRVCS_VAR) pbDiagData, P2CONST(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) ReqLen_Cnt_T_u16, P2VAR(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) RespLength_Cnt_T_u16, VAR(uint8, EPSDIAGSRVCS_VAR) SrvcReqType_Cnt_T_u8, VAR(uint16, EPSDIAGSRVCS_VAR) LUTidx_Cnt_T_u16);
	#define D_EPS_DIAGSRV_PIDNUM_FEE8	0xFEE8U
#else
	#define EPSInternal_PID_FEE8	DiagSrvPIDNullFunc
#endif /* D_EPS_DIAGSRV_PID_FEE8 */

#if (D_EPS_DIAGSRV_PID_FEE9 == D_DIAGSRVC_ENABLED)
	extern FUNC(CM_MsgBufferType, EPSDIAGSRVCS_CODE) EPSInternal_PID_FEE9 (VAR(CM_MsgBufferType, EPSDIAGSRVCS_VAR) pbDiagData, P2CONST(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) ReqLen_Cnt_T_u16, P2VAR(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) RespLength_Cnt_T_u16, VAR(uint8, EPSDIAGSRVCS_VAR) SrvcReqType_Cnt_T_u8, VAR(uint16, EPSDIAGSRVCS_VAR) LUTidx_Cnt_T_u16);
	#define D_EPS_DIAGSRV_PIDNUM_FEE9	0xFEE9U
#else
	#define EPSInternal_PID_FEE9	DiagSrvPIDNullFunc
#endif /* D_EPS_DIAGSRV_PID_FEE9 */

#if (D_EPS_DIAGSRV_PID_FEEA == D_DIAGSRVC_ENABLED)
	extern FUNC(CM_MsgBufferType, EPSDIAGSRVCS_CODE) EPSInternal_PID_FEEA (VAR(CM_MsgBufferType, EPSDIAGSRVCS_VAR) pbDiagData, P2CONST(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) ReqLen_Cnt_T_u16, P2VAR(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) RespLength_Cnt_T_u16, VAR(uint8, EPSDIAGSRVCS_VAR) SrvcReqType_Cnt_T_u8, VAR(uint16, EPSDIAGSRVCS_VAR) LUTidx_Cnt_T_u16);
	#define D_EPS_DIAGSRV_PIDNUM_FEEA	0xFEEAU
#else
	#define EPSInternal_PID_FEEA	DiagSrvPIDNullFunc
#endif /* D_EPS_DIAGSRV_PID_FEEA */

#if (D_EPS_DIAGSRV_PID_FEEB == D_DIAGSRVC_ENABLED)
	extern FUNC(CM_MsgBufferType, EPSDIAGSRVCS_CODE) EPSInternal_PID_FEEB (VAR(CM_MsgBufferType, EPSDIAGSRVCS_VAR) pbDiagData, P2CONST(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) ReqLen_Cnt_T_u16, P2VAR(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) RespLength_Cnt_T_u16, VAR(uint8, EPSDIAGSRVCS_VAR) SrvcReqType_Cnt_T_u8, VAR(uint16, EPSDIAGSRVCS_VAR) LUTidx_Cnt_T_u16);
	#define D_EPS_DIAGSRV_PIDNUM_FEEB	0xFEEBU
#else
	#define EPSInternal_PID_FEEB	DiagSrvPIDNullFunc
#endif /* D_EPS_DIAGSRV_PID_FEEB */

#if (D_EPS_DIAGSRV_PID_FEEC == D_DIAGSRVC_ENABLED)
	extern FUNC(CM_MsgBufferType, EPSDIAGSRVCS_CODE) EPSInternal_PID_FEEC (VAR(CM_MsgBufferType, EPSDIAGSRVCS_VAR) pbDiagData, P2CONST(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) ReqLen_Cnt_T_u16, P2VAR(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) RespLength_Cnt_T_u16, VAR(uint8, EPSDIAGSRVCS_VAR) SrvcReqType_Cnt_T_u8, VAR(uint16, EPSDIAGSRVCS_VAR) LUTidx_Cnt_T_u16);
	#define D_EPS_DIAGSRV_PIDNUM_FEEC	0xFEECU
#else
	#define EPSInternal_PID_FEEC	DiagSrvPIDNullFunc
#endif /* D_EPS_DIAGSRV_PID_FEEC */

#if (D_EPS_DIAGSRV_PID_FEED == D_DIAGSRVC_ENABLED)
	extern FUNC(CM_MsgBufferType, EPSDIAGSRVCS_CODE) EPSInternal_PID_FEED (VAR(CM_MsgBufferType, EPSDIAGSRVCS_VAR) pbDiagData, P2CONST(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) ReqLen_Cnt_T_u16, P2VAR(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) RespLength_Cnt_T_u16, VAR(uint8, EPSDIAGSRVCS_VAR) SrvcReqType_Cnt_T_u8, VAR(uint16, EPSDIAGSRVCS_VAR) LUTidx_Cnt_T_u16);
	#define D_EPS_DIAGSRV_PIDNUM_FEED	0xFEEDU
#else
	#define EPSInternal_PID_FEED	DiagSrvPIDNullFunc
#endif /* D_EPS_DIAGSRV_PID_FEED */

#if (D_EPS_DIAGSRV_PID_FEEE == D_DIAGSRVC_ENABLED)
	extern FUNC(CM_MsgBufferType, EPSDIAGSRVCS_CODE) EPSInternal_PID_FEEE (VAR(CM_MsgBufferType, EPSDIAGSRVCS_VAR) pbDiagData, P2CONST(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) ReqLen_Cnt_T_u16, P2VAR(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) RespLength_Cnt_T_u16, VAR(uint8, EPSDIAGSRVCS_VAR) SrvcReqType_Cnt_T_u8, VAR(uint16, EPSDIAGSRVCS_VAR) LUTidx_Cnt_T_u16);
	#define D_EPS_DIAGSRV_PIDNUM_FEEE	0xFEEEU
#else
	#define EPSInternal_PID_FEEE	DiagSrvPIDNullFunc
#endif /* D_EPS_DIAGSRV_PID_FEEE */

#if (D_EPS_DIAGSRV_PID_FEEF == D_DIAGSRVC_ENABLED)
	extern FUNC(CM_MsgBufferType, EPSDIAGSRVCS_CODE) EPSInternal_PID_FEEF (VAR(CM_MsgBufferType, EPSDIAGSRVCS_VAR) pbDiagData, P2CONST(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) ReqLen_Cnt_T_u16, P2VAR(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) RespLength_Cnt_T_u16, VAR(uint8, EPSDIAGSRVCS_VAR) SrvcReqType_Cnt_T_u8, VAR(uint16, EPSDIAGSRVCS_VAR) LUTidx_Cnt_T_u16);
	#define D_EPS_DIAGSRV_PIDNUM_FEEF	0xFEEFU
#else
	#define EPSInternal_PID_FEEF	DiagSrvPIDNullFunc
#endif /* D_EPS_DIAGSRV_PID_FEEF */

#if (D_EPS_DIAGSRV_PID_FEF0 == D_DIAGSRVC_ENABLED)
	extern FUNC(CM_MsgBufferType, EPSDIAGSRVCS_CODE) EPSInternal_PID_FEF0 (VAR(CM_MsgBufferType, EPSDIAGSRVCS_VAR) pbDiagData, P2CONST(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) ReqLen_Cnt_T_u16, P2VAR(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) RespLength_Cnt_T_u16, VAR(uint8, EPSDIAGSRVCS_VAR) SrvcReqType_Cnt_T_u8, VAR(uint16, EPSDIAGSRVCS_VAR) LUTidx_Cnt_T_u16);
	#define D_EPS_DIAGSRV_PIDNUM_FEF0	0xFEF0U
#else
	#define EPSInternal_PID_FEF0	DiagSrvPIDNullFunc
#endif /* D_EPS_DIAGSRV_PID_FEF0 */

#if (D_EPS_DIAGSRV_PID_FEF1 == D_DIAGSRVC_ENABLED)
	extern FUNC(CM_MsgBufferType, EPSDIAGSRVCS_CODE) EPSInternal_PID_FEF1 (VAR(CM_MsgBufferType, EPSDIAGSRVCS_VAR) pbDiagData, P2CONST(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) ReqLen_Cnt_T_u16, P2VAR(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) RespLength_Cnt_T_u16, VAR(uint8, EPSDIAGSRVCS_VAR) SrvcReqType_Cnt_T_u8, VAR(uint16, EPSDIAGSRVCS_VAR) LUTidx_Cnt_T_u16);
	#define D_EPS_DIAGSRV_PIDNUM_FEF1	0xFEF1U
#else
	#define EPSInternal_PID_FEF1	DiagSrvPIDNullFunc
#endif /* D_EPS_DIAGSRV_PID_FEF1 */

#if (D_EPS_DIAGSRV_PID_FEF2 == D_DIAGSRVC_ENABLED)
	extern FUNC(CM_MsgBufferType, EPSDIAGSRVCS_CODE) EPSInternal_PID_FEF2 (VAR(CM_MsgBufferType, EPSDIAGSRVCS_VAR) pbDiagData, P2CONST(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) ReqLen_Cnt_T_u16, P2VAR(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) RespLength_Cnt_T_u16, VAR(uint8, EPSDIAGSRVCS_VAR) SrvcReqType_Cnt_T_u8, VAR(uint16, EPSDIAGSRVCS_VAR) LUTidx_Cnt_T_u16);
	#define D_EPS_DIAGSRV_PIDNUM_FEF2	0xFEF2U
#else
	#define EPSInternal_PID_FEF2	DiagSrvPIDNullFunc
#endif /* D_EPS_DIAGSRV_PID_FEF2 */

#if (D_EPS_DIAGSRV_PID_FEF3 == D_DIAGSRVC_ENABLED)
	extern FUNC(CM_MsgBufferType, EPSDIAGSRVCS_CODE) EPSInternal_PID_FEF3 (VAR(CM_MsgBufferType, EPSDIAGSRVCS_VAR) pbDiagData, P2CONST(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) ReqLen_Cnt_T_u16, P2VAR(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) RespLength_Cnt_T_u16, VAR(uint8, EPSDIAGSRVCS_VAR) SrvcReqType_Cnt_T_u8, VAR(uint16, EPSDIAGSRVCS_VAR) LUTidx_Cnt_T_u16);
	#define D_EPS_DIAGSRV_PIDNUM_FEF3	0xFEF3U
#else
	#define EPSInternal_PID_FEF3	DiagSrvPIDNullFunc
#endif /* D_EPS_DIAGSRV_PID_FEF3 */

#if (D_EPS_DIAGSRV_PID_FEF4 == D_DIAGSRVC_ENABLED)
	extern FUNC(CM_MsgBufferType, EPSDIAGSRVCS_CODE) EPSInternal_PID_FEF4 (VAR(CM_MsgBufferType, EPSDIAGSRVCS_VAR) pbDiagData, P2CONST(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) ReqLen_Cnt_T_u16, P2VAR(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) RespLength_Cnt_T_u16, VAR(uint8, EPSDIAGSRVCS_VAR) SrvcReqType_Cnt_T_u8, VAR(uint16, EPSDIAGSRVCS_VAR) LUTidx_Cnt_T_u16);
	#define D_EPS_DIAGSRV_PIDNUM_FEF4	0xFEF4U
#else
	#define EPSInternal_PID_FEF4	DiagSrvPIDNullFunc
#endif /* D_EPS_DIAGSRV_PID_FEF4 */

#if (D_EPS_DIAGSRV_PID_FEF5 == D_DIAGSRVC_ENABLED)
	extern FUNC(CM_MsgBufferType, EPSDIAGSRVCS_CODE) EPSInternal_PID_FEF5 (VAR(CM_MsgBufferType, EPSDIAGSRVCS_VAR) pbDiagData, P2CONST(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) ReqLen_Cnt_T_u16, P2VAR(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) RespLength_Cnt_T_u16, VAR(uint8, EPSDIAGSRVCS_VAR) SrvcReqType_Cnt_T_u8, VAR(uint16, EPSDIAGSRVCS_VAR) LUTidx_Cnt_T_u16);
	#define D_EPS_DIAGSRV_PIDNUM_FEF5	0xFEF5U
#else
	#define EPSInternal_PID_FEF5	DiagSrvPIDNullFunc
#endif /* D_EPS_DIAGSRV_PID_FEF5 */

#if (D_EPS_DIAGSRV_PID_FEF6 == D_DIAGSRVC_ENABLED)
	extern FUNC(CM_MsgBufferType, EPSDIAGSRVCS_CODE) EPSInternal_PID_FEF6 (VAR(CM_MsgBufferType, EPSDIAGSRVCS_VAR) pbDiagData, P2CONST(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) ReqLen_Cnt_T_u16, P2VAR(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) RespLength_Cnt_T_u16, VAR(uint8, EPSDIAGSRVCS_VAR) SrvcReqType_Cnt_T_u8, VAR(uint16, EPSDIAGSRVCS_VAR) LUTidx_Cnt_T_u16);
	#define D_EPS_DIAGSRV_PIDNUM_FEF6	0xFEF6U
#else
	#define EPSInternal_PID_FEF6	DiagSrvPIDNullFunc
#endif /* D_EPS_DIAGSRV_PID_FEF6 */

#if (D_EPS_DIAGSRV_PID_FEF7 == D_DIAGSRVC_ENABLED)
	extern FUNC(CM_MsgBufferType, EPSDIAGSRVCS_CODE) EPSInternal_PID_FEF7 (VAR(CM_MsgBufferType, EPSDIAGSRVCS_VAR) pbDiagData, P2CONST(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) ReqLen_Cnt_T_u16, P2VAR(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) RespLength_Cnt_T_u16, VAR(uint8, EPSDIAGSRVCS_VAR) SrvcReqType_Cnt_T_u8, VAR(uint16, EPSDIAGSRVCS_VAR) LUTidx_Cnt_T_u16);
	#define D_EPS_DIAGSRV_PIDNUM_FEF7	0xFEF7U
#else
	#define EPSInternal_PID_FEF7	DiagSrvPIDNullFunc
#endif /* D_EPS_DIAGSRV_PID_FEF7 */

#if (D_EPS_DIAGSRV_PID_FEF8 == D_DIAGSRVC_ENABLED)
	extern FUNC(CM_MsgBufferType, EPSDIAGSRVCS_CODE) EPSInternal_PID_FEF8 (VAR(CM_MsgBufferType, EPSDIAGSRVCS_VAR) pbDiagData, P2CONST(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) ReqLen_Cnt_T_u16, P2VAR(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) RespLength_Cnt_T_u16, VAR(uint8, EPSDIAGSRVCS_VAR) SrvcReqType_Cnt_T_u8, VAR(uint16, EPSDIAGSRVCS_VAR) LUTidx_Cnt_T_u16);
	#define D_EPS_DIAGSRV_PIDNUM_FEF8	0xFEF8U
#else
	#define EPSInternal_PID_FEF8	DiagSrvPIDNullFunc
#endif /* D_EPS_DIAGSRV_PID_FEF8 */

#if (D_EPS_DIAGSRV_PID_FEF9 == D_DIAGSRVC_ENABLED)
	extern FUNC(CM_MsgBufferType, EPSDIAGSRVCS_CODE) EPSInternal_PID_FEF9 (VAR(CM_MsgBufferType, EPSDIAGSRVCS_VAR) pbDiagData, P2CONST(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) ReqLen_Cnt_T_u16, P2VAR(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) RespLength_Cnt_T_u16, VAR(uint8, EPSDIAGSRVCS_VAR) SrvcReqType_Cnt_T_u8, VAR(uint16, EPSDIAGSRVCS_VAR) LUTidx_Cnt_T_u16);
	#define D_EPS_DIAGSRV_PIDNUM_FEF9	0xFEF9U
#else
	#define EPSInternal_PID_FEF9	DiagSrvPIDNullFunc
#endif /* D_EPS_DIAGSRV_PID_FEF9 */

#if (D_EPS_DIAGSRV_PID_FEFA == D_DIAGSRVC_ENABLED)
	extern FUNC(CM_MsgBufferType, EPSDIAGSRVCS_CODE) EPSInternal_PID_FEFA (VAR(CM_MsgBufferType, EPSDIAGSRVCS_VAR) pbDiagData, P2CONST(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) ReqLen_Cnt_T_u16, P2VAR(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) RespLength_Cnt_T_u16, VAR(uint8, EPSDIAGSRVCS_VAR) SrvcReqType_Cnt_T_u8, VAR(uint16, EPSDIAGSRVCS_VAR) LUTidx_Cnt_T_u16);
	#define D_EPS_DIAGSRV_PIDNUM_FEFA	0xFEFAU
#else
	#define EPSInternal_PID_FEFA	DiagSrvPIDNullFunc
#endif /* D_EPS_DIAGSRV_PID_FEFA */

#if (D_EPS_DIAGSRV_PID_FEFB == D_DIAGSRVC_ENABLED)
	extern FUNC(CM_MsgBufferType, EPSDIAGSRVCS_CODE) EPSInternal_PID_FEFB (VAR(CM_MsgBufferType, EPSDIAGSRVCS_VAR) pbDiagData, P2CONST(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) ReqLen_Cnt_T_u16, P2VAR(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) RespLength_Cnt_T_u16, VAR(uint8, EPSDIAGSRVCS_VAR) SrvcReqType_Cnt_T_u8, VAR(uint16, EPSDIAGSRVCS_VAR) LUTidx_Cnt_T_u16);
	#define D_EPS_DIAGSRV_PIDNUM_FEFB	0xFEFBU
#else
	#define EPSInternal_PID_FEFB	DiagSrvPIDNullFunc
#endif /* D_EPS_DIAGSRV_PID_FEFB */

#if (D_EPS_DIAGSRV_PID_FEFC == D_DIAGSRVC_ENABLED)
	extern FUNC(CM_MsgBufferType, EPSDIAGSRVCS_CODE) EPSInternal_PID_FEFC (VAR(CM_MsgBufferType, EPSDIAGSRVCS_VAR) pbDiagData, P2CONST(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) ReqLen_Cnt_T_u16, P2VAR(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) RespLength_Cnt_T_u16, VAR(uint8, EPSDIAGSRVCS_VAR) SrvcReqType_Cnt_T_u8, VAR(uint16, EPSDIAGSRVCS_VAR) LUTidx_Cnt_T_u16);
	#define D_EPS_DIAGSRV_PIDNUM_FEFC	0xFEFCU
#else
	#define EPSInternal_PID_FEFC	DiagSrvPIDNullFunc
#endif /* D_EPS_DIAGSRV_PID_FEFC */

#if (D_EPS_DIAGSRV_PID_FEFD == D_DIAGSRVC_ENABLED)
	extern FUNC(CM_MsgBufferType, EPSDIAGSRVCS_CODE) EPSInternal_PID_FEFD (VAR(CM_MsgBufferType, EPSDIAGSRVCS_VAR) pbDiagData, P2CONST(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) ReqLen_Cnt_T_u16, P2VAR(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) RespLength_Cnt_T_u16, VAR(uint8, EPSDIAGSRVCS_VAR) SrvcReqType_Cnt_T_u8, VAR(uint16, EPSDIAGSRVCS_VAR) LUTidx_Cnt_T_u16);
	#define D_EPS_DIAGSRV_PIDNUM_FEFD	0xFEFDU
#else
	#define EPSInternal_PID_FEFD	DiagSrvPIDNullFunc
#endif /* D_EPS_DIAGSRV_PID_FEFD */

#if (D_EPS_DIAGSRV_PID_FEFE == D_DIAGSRVC_ENABLED)
	extern FUNC(CM_MsgBufferType, EPSDIAGSRVCS_CODE) EPSInternal_PID_FEFE (VAR(CM_MsgBufferType, EPSDIAGSRVCS_VAR) pbDiagData, P2CONST(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) ReqLen_Cnt_T_u16, P2VAR(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) RespLength_Cnt_T_u16, VAR(uint8, EPSDIAGSRVCS_VAR) SrvcReqType_Cnt_T_u8, VAR(uint16, EPSDIAGSRVCS_VAR) LUTidx_Cnt_T_u16);
	#define D_EPS_DIAGSRV_PIDNUM_FEFE	0xFEFEU
#else
	#define EPSInternal_PID_FEFE	DiagSrvPIDNullFunc
#endif /* D_EPS_DIAGSRV_PID_FEFE */

#if (D_EPS_DIAGSRV_PID_FEFF == D_DIAGSRVC_ENABLED)
	extern FUNC(CM_MsgBufferType, EPSDIAGSRVCS_CODE) EPSInternal_PID_FEFF (VAR(CM_MsgBufferType, EPSDIAGSRVCS_VAR) pbDiagData, P2CONST(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) ReqLen_Cnt_T_u16, P2VAR(CM_MsgLenType, EPSDIAGSRVCS_VAR, EPSDIAGSRVCS_VAR) RespLength_Cnt_T_u16, VAR(uint8, EPSDIAGSRVCS_VAR) SrvcReqType_Cnt_T_u8, VAR(uint16, EPSDIAGSRVCS_VAR) LUTidx_Cnt_T_u16);
	#define D_EPS_DIAGSRV_PIDNUM_FEFF	0xFEFFU
#else
	#define EPSInternal_PID_FEFF	DiagSrvPIDNullFunc
#endif /* D_EPS_DIAGSRV_PID_FEFF */
 

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of custom define area >>	                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#endif /* EPS_DIAGSRVCS_ISO_H */
