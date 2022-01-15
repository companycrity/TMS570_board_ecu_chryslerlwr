/*****************************************************************************
* Copyright 2010 Nexteer Automotive, All Rights Reserved.
* Nexteer Confidential
*
* Module File Name  : EPS_DiagSrvcs_CommonData.h file
* Module Description: Common data shared between all the files.
* Product           : Gen II Plus - EA3.0
* Author            : Kevin Smith
*
* Notes:
* This file contains configurations that are shared between ISO and XCP services
* and is included in all the files.
*
*****************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/* Version Control:
 * Date Created:      Mon Apr 12 10:20:00 2012
 * %version:          1 %
 * %derived_by:       jzh87w %
 * %date_modified:    Thu Dec  5 14:32:24 2013 %
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
#include "Std_Types.h"
#include "Rte_type.h"
#include "NvM.h"
#include "osek.h"
#include "fpmtype.h"
#include "fixmath.h"
#include "GlobalMacro.h"
#include "Compiler.h"
#include "CalConstants.h"
#include "Ap_DfltConfigData.h"
#include "CDD_Data.h"
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include area >>   		      		    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#ifndef EPS_DIAGSRVCS_COMMONDATA_H_
#define EPS_DIAGSRVCS_COMMONDATA_H_

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of custom include area >>	                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of custom include area >>	                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of custom define area >>   		  	    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/* Switches to enable / disable the services */
#define D_DIAGSRVC_ENABLED					STD_ON
#define D_DIAGSRVC_DISABLED					STD_OFF

/* Common defines used in the diagnostic services */
#define D_SRVCREQTYPEREAD_CNT_U16 			0x00
#define D_SRVCREQTYPEWRITE_CNT_U16 			0x01
#define D_PID_NOTACTIVE_CNT_U8				0x00
#define D_PID_ACTIVE_CNT_U8					0x01
#define D_PID_READONLY_CNT_U8				0x00
#define D_PID_READWRITE_CNT_U8				0x01
#define D_BIT0MASK_CNT_U16					0x0001U
#define D_BIT1MASK_CNT_U16					0x0002U
#define D_BIT2MASK_CNT_U16					0x0004U
#define D_BIT3MASK_CNT_U16					0x0008U
#define D_BIT4MASK_CNT_U16					0x0010U
#define D_BIT5MASK_CNT_U16					0x0020U
#define D_BIT6MASK_CNT_U16					0x0040U
#define D_BIT7MASK_CNT_U16					0x0080U
#define D_BYTEMASK_ULS_U8					0xFFU
#define D_NIBBLESHIFT_CNT_U16				4U
#define D_BYTESHIFT_CNT_U16					8U
#define D_BYTESHIFT_CNT_U8					8U
#define D_WORDBYTESHIFT_CNT_U16				12U
#define D_WORDSHIFT_CNT_U16					16U
#define D_MSBYTESHIFT_CNT_U16				24U
#define D_LOWERNIBBLEMASK_CNT_U16			0x0FU
#define D_UPPERNIBBLEMASK_CNT_U16   		0xF0U
#define D_LOWERSIXBITSMASK_CNT_U16	   		0x3FU
#define D_LOWERBYTEBITSEVEN_CNT_U16	   		0x40U
#define d_LOWNIBUPBYTEMASK_CNT_U16			0x0F00U
#define D_UPPNIBUPBYTEMASK_CNT_U16			0xF000U
#define D_LOWERBYTEMASK_CNT_U16				0x00FFU
#define D_UPPERBYTEMASK_CNT_U16				0xFF00U
#define D_LOWERWORDBYTEMASK_CNT_U16			0x0FFFU
#define D_LOWBYTELOWORDMASK_CNT_U32 		0x000000FFUL
#define D_LOWERWORDMASK_CNT_U32 			0x0000FFFFUL
#define D_UPPERWORDMASK_CNT_U32 			0xFFFF0000UL
#define D_UPPERNIBBLEMASK_CNT_U32 			0xF0000000UL
#define D_FLOATMASK_CNT_U32					0xFFFFFFFFUL

/* MEC Values */
#define D_NXTRMEC_ENGMODE_CNT_U8			0xFFU
#define D_NXTRMEC_PRODMODE_CNT_U8			0x00U

/* Macros */
#define bytesToWord_m(x,y)				(((uint16)x << D_BYTESHIFT_CNT_U16) | (uint16)y)
#define uint32RightShftuint8_m(x,y)		(uint8)(((uint32)x >> y) & D_BYTEMASK_ULS_U8)
#define uint8LeftShftuint32_m(x,y)		(uint32)(((uint32)x << y) & D_FLOATMASK_CNT_U32)
#define MSB(x)							(uint8)(((uint16)x >> D_BYTESHIFT_CNT_U16) & D_BYTEMASK_ULS_U8)
#define LSB(x)							(uint8)((uint16)x & D_BYTEMASK_ULS_U8)

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of custom define area >>	                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#endif /* EPS_DIAGSRVCS_COMMONDATA_H_ */

