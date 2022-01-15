
/*****************************************************************************
* Copyright 2010 Nexteer Automotive, All Rights Reserved.
* Nexteer Confidential
*
* Module File Name  : Ap_PAwTO_Cfg.h
* Module Description: Configuration file of DiagMgr module
* Product           : Gen II Plus - EA3.0
* Generator         : artt 2.0.2.0
* Generation Time   : 18.07.2013 12:24:39
*****************************************************************************/
/* Version Control:
 * Date Created:      Fri Jul 13 18:34:17 2012
 * %version:          3 %
 * %date_modified:    Thu Jul 18 13:22:07 2013 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 09/20/12   1       ssk       Initial template creation
 * 	 	
 */

#ifndef AP_PAWTO_CFG_H
#define AP_PAWTO_CFG_H


/*******************************************************************************
**                      Define Section                                       **
*******************************************************************************/

/* PAwTO_Per2_CP1 Checkpoint is enabled */

/* Disable all checkpoints that are not enabled */
#define Rte_Call_PAwTO_Per1_CP0_CheckpointReached()		(void)0 /* Checkpoint disabled */	 
#define Rte_Call_PAwTO_Per1_CP1_CheckpointReached()		(void)0 /* Checkpoint disabled */	 
#define Rte_Call_PAwTO_Per2_CP0_CheckpointReached()		(void)0 /* Checkpoint disabled */	 
   
#endif /* PAWTO_CFG_H */

/*** End of file **************************************************************/
