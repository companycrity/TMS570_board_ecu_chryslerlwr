/*****************************************************************************
* Copyright 2003 Delphi Technologies, Inc., All Rights Reserved.
* Delphi Confidential
*
* Module File Name  : SrlComSrvc.c
* Module Description: Serial Communication, Serial Diagnostic Services and XCP
* Product           : Gen II Plus - EA3.0
* Author            : Bobby O'Steen
*****************************************************************************/
/* Version Control:
 * Date Created:      Wed Apr 13 12:17:00 2011
 * %version:          1 %
 * %derived_by:       tzj9qy %
 * %date_modified:    Thu Jul 19 13:06:55 2012 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 04/13/11  1        LWW       Initial K2xx Synergy Version
 * 08/05/11  2		  SAH		Call EpsDiagSrvcs Init
 */

#include "SrlComSrvc.h" 	/* Needed for module function decleration */
#include "SComm_Func.h" 	/* Needed DiagSrvcs function calls	*/


/************* Section Embedded Constants ****************************/


/************ Section Module Internal Variables *********************/


/************ Local Functions ***************************************/


/*****************************************************************************
 *
 *  Function Name:     SrlComSrvc_Init1
 *
 *  Description:       Initialize diagnostic services and communication tasks
 *
 *  Inputs:            None
 *
 *  Outputs:           None
 *
 *****************************************************************************/
FUNC(void, SRLCOMSRVC_CODE) SrlComSrvc_Init1 (void)
{

	//SMW EPSDiagSrvcs_Init();		/* Initialize Nexteer Diag Services */

}
/* TODO: add periodic functions for future periodic diagnostic tasks */
/* TODO: add shutdown/powerdown functions for future shutdown diagnostic tasks */



