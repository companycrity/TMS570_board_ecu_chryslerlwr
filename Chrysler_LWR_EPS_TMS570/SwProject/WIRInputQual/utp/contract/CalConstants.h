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
 * %version:          1 %
 * %derived_by:       czgng4 %
 * %date_modified:    Tue Feb 21 08:59:36 2012 %
 *---------------------------------------------------------------------------------------------------------------------
 */

#ifndef CALCONSTANTS_H
#define CALCONSTANTS_H

#include "Std_Types.h"

/*********************** Start of Auto Generated Code ************************/

/****************** File Generated on 2/10/2012 4:32:27 PM *******************/
/*************************** WIRInputQual - Rev 1 ****************************/


extern CONST(uint16, CAL_CONST) k_WhlSpdQPStep_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_WhlSpdQLimit_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_WhlSpdQNStep_Cnt_u16;
extern CONST(DiagSettings_Str, CAL_CONST) k_WhlSpdQualDiag_Cnt_Str;

/********************************* WhlImbRej *********************************/
extern CONST(uint16, CAL_CONST) t_FreqScaleTblX_Hz_u7p9[6];
extern CONST(uint16, CAL_CONST) t_FreqScaleTblY_Uls_u2p14[6];
#endif
