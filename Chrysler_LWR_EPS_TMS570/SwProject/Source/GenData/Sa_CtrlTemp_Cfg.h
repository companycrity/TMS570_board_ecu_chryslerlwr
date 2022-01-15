
/*****************************************************************************
* Copyright 2010 Nexteer Automotive, All Rights Reserved.
* Nexteer Confidential
*
* Module File Name  : Sa_CtrlTemp_Cfg.h
* Module Description: Configuration file of DiagMgr module
* Product           : Gen II Plus - EA3.0
* Generator         : artt 2.0.2.0
* Generation Time   : 27.06.2013 15:13:58
*****************************************************************************/
/* Version Control:
 * Date Created:      Fri Jul 13 18:34:17 2012
 * %version:          2 %
 * %date_modified:    Fri Jun 28 09:28:42 2013 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 07/13/12   1       JJW       Initial template creation
 */

#ifndef AP_CTRLTEMP_CFG_H
#define AP_CTRLTEMP_CFG_H


/*******************************************************************************
**                      Define Section                                       **
*******************************************************************************/

/* CtrlTemp_Per2_CP0 Checkpoint is enabled */

/* Disable all checkpoints that are not enabled */
#define Rte_Call_CtrlTemp_Per1_CP0_CheckpointReached()		(void)0 /* Checkpoint disabled */	 
#define Rte_Call_CtrlTemp_Per1_CP1_CheckpointReached()		(void)0 /* Checkpoint disabled */	 
#define Rte_Call_CtrlTemp_Per2_CP1_CheckpointReached()		(void)0 /* Checkpoint disabled */	 
   
#endif /* CTRLTEMP_CFG_H */

/*** End of file **************************************************************/
