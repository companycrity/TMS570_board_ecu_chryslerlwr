
/*****************************************************************************
* Copyright 2010 Nexteer Automotive, All Rights Reserved.
* Nexteer Confidential
*
* Module File Name  : Ap_ApXcp_Cfg.h
* Module Description: Configuration file of Xcp module
* Product           : Gen II Plus - EA3.0
* Generator         : artt 2.0.2.0
* Generation Time   : 12.08.2016 14:54:19
*****************************************************************************/
/* Version Control:
 * Date Created:      Fri Jul 13 18:34:17 2012
 * %version:          EA3#1.1.3 %
 * %date_modified:    Tue Jan 21 10:11:13 2014 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 01/07/13   1       LWW       Initial template creation
 * 10/28/13   4       KJS       Changed configuration to support new TOTF configuration layout for segments
 *								0, 1, 2, 3, 4, and 16. 
 */

#ifndef AP_XCP_CFG_H
#define AP_XCP_CFG_H

#include "Std_Types.h"                   /* Standard type definitions      */

/*** Private Part (used by Ap_ApXcp.c only) *************************************/
#ifdef APXCP_C

#define D_NUMOFOSAPPS_CNT_U8					4U
#define D_NUMOFVLDMEMRGNS_CNT_U08				2
#endif
#endif /* AP_APXCP_CFG_H */
/*** End of file **************************************************************/
