/*****************************************************************************
* Copyright 2010 Nexteer Automotive, All Rights Reserved.
* Nexteer Confidential
*
* Module File Name  : EPS_DiagSrvcs_SrvcLUTbl.h file
* Module Description: Common Manufacturing Program Interface for XCP and ISO services
* Product           : Gen II Plus - EA3.0
* Author            : Kevin Smith
*
* Notes:
* This file contains format of the lookup tables.
*
*****************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/* Version Control:
 * Date Created:      Mon Apr 12 10:20:00 2012
 * %version:          1 %
 * %derived_by:       jzh87w %
 * %date_modified:    Thu Dec  5 14:32:26 2013 %
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
#include"EPS_DiagSrvcs_CommonData.h"

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include area >>   		      		    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#ifndef EPS_DIAGSRVCS_PIDTBLINTERFACE_H
#define EPS_DIAGSRVCS_PIDTBLINTERFACE_H

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of custom include area >>	                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include"EPS_DiagSrvcs_ISO.h"			 /* required for typedefs for lookup table */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of custom include area >>	                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of custom define area >>   		  	    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/* Variables owned by the diagnostic service functions */
extern VAR(boolean, EPSDIAGSRVCS_VAR) MfgDiagInhibit_Uls_G_lgc;
extern VAR(uint16, EPSDIAGSRVCS_VAR) VehSpdOverride_Kph_M_u16p0;
extern VAR(ManufModeType, EPSDIAGSRVCS_VAR) NxtrMEC_Uls_G_enum;

extern VAR(uint8, NVM_APPL_DATA) Nvm_NMEC_Cnt_u8;
extern VAR(uint8, NVM_APPL_DATA) Nvm_EcuSrlNum_Cnt_u8[4];
extern VAR(uint8, NVM_APPL_DATA) Nvm_EpsSrlNum_Cnt_u8[4];
extern VAR(uint8, NVM_APPL_DATA) Nvm_EcuHwPn_Cnt_u8[12];
extern VAR(uint8, NVM_APPL_DATA) Nvm_NxtrManfScrpd_Cnt_u8[64];
extern VAR(uint16, NVM_APPL_DATA) Nvm_IgnCntr_Cnt_u16;

/* XCP and ISO services and variables PID Table */
#define D_DIAGSRCVS_PIDTBLSIZE_CNT_U16	180U
#define D_PIDTBL_NULLPTRADDR_ULS_U32 	t_DiagSrv_PIDtbl[0].address
#define D_PIDTBL_INVLDPID_ULS_U16		t_DiagSrv_PIDtbl[0].PID

/* PID Table definition */
typedef struct EPS_DiagSrv_PIDtbl {
     uint16 	PID;
     union {
    	 void* 			var;
    	 PIDFuncRef		pidFunc;
    	 RIDFuncRef		ridFunc;
    	 IOCFuncRef		iocFunc;
    	 ResetFuncRef	resetFunc;
     }address;
     uint8 		type;
     union {
     	uint16 	length;
     	uint16 	pidcnt;
     	uint16 	ctrlbytes;
     	uint16 	size;
     }cfgprm;
     uint8 		access;
     uint8 		active;
} EPS_DiagSrv_PIDtbl;
extern const struct EPS_DiagSrv_PIDtbl t_DiagSrv_PIDtbl[D_DIAGSRCVS_PIDTBLSIZE_CNT_U16];


/* ISO VAR specific table */
/* Value contained in this table are for ISO routines only if variables do not have SCom functions */
#define D_DIAGSRVCS_ISOVAR_TBLSIZE_CNT_U16	20U
#define D_ISOVARTBL_NULLPTR_ULS_U32		t_DiagSrv_ISOVarTbl[0].address
/* ISO VAR Table definition */
typedef struct EPS_DiagSrv_ISOVarTbl{
	void*			address;
} EPS_DiagSrv_ISOVarTbl;
extern const struct EPS_DiagSrv_ISOVarTbl t_DiagSrv_ISOVarTbl[D_DIAGSRVCS_ISOVAR_TBLSIZE_CNT_U16];

/* Table defines */
#define D_PIDTBL_READONLY 	0x00u
#define D_PIDTBL_READWRITE	0x01u
#define D_PIDTBL_DISABLED	0x00u
#define D_PIDTBL_ENABLED	0x01u

#define D_PIDTBL_VARTYPE	0x00u
#define D_PIDTBL_PIDTYPE	0x01u
#define D_PIDTBL_RIDTYPE	0x02u
#define D_PIDTBL_RESETTYPE	0x03u
#define D_PIDTBL_IOCTYPE	0x04u

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of custom define area >>	                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#endif /*EPS_DIAGSRVCS_PIDTBLINTERFACE_H*/

