/*****************************************************************************
* Copyright 2010 Nexteer Automotive, All Rights Reserved.
* Nexteer Confidential
*
* Module File Name  : SchM_WdgM.c
* Module Description: Definition of SchM configuration for WdgM
* Product           : Gen II Plus - EA3.0
* Author            : Jeremy Warmbier
*****************************************************************************/
/* Version Control:
 * Date Created:      Wed Apr 13 12:17:00 2011
 * %version:          2 %
 * %derived_by:       xz0btk %
 * %date_modified:    Mon Mar  4 08:49:28 2013 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 09/13/12  3        JJW       Updates for integration of new WdgM
 */

#ifndef SCHM_WDGM_H
#define SCHM_WDGM_H

#include "SchM.h"
#include "SchM_Types.h"
#include "SchM_Cfg.h"

/* WdgM is not scheduled through SchM in the Nexteer EPS project, but rather by integrator placement in a task */

# define WDGM_EXCLUSIVE_AREA_0   			(SCHM_EA_SUSPENDALLINTERRUPTS)
# define SchM_Enter_WdgM(ExclusiveArea)   	SCHM_ENTER_EXCLUSIVE(ExclusiveArea)
# define SchM_Exit_WdgM(ExclusiveArea)    	SCHM_EXIT_EXCLUSIVE(ExclusiveArea)


#endif /* SCHM_WDGM_H */

