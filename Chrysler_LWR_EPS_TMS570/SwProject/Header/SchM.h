

#ifndef SCHM_H
#define SCHM_H

#include "Std_Types.h"
#include "SchM_Cfg.h"

/**
 * Define vendor and module ID
 */
#define SCHM_VENDOR_ID          0 /* HIS Vendor ID for Unassigned Suppliers  */
#define SCHM_MODULE_ID        130 /* SchM Module ID according to BSW Modules */

/**
 * Define AUTOSAR version
 */
#define SCHM_AR_MAJOR_VERSION  1
#define SCHM_AR_MINOR_VERSION  1
#define SCHM_AR_PATCH_VERSION  0

/**
 * Define version for header and source file consistency
 */
#define SCHM_SW_MAJOR_VERSION  0
#define SCHM_SW_MINOR_VERSION  0
#define SCHM_SW_PATCH_VERSION  0

/**
 * Define SchM InitState
 */
#define SCHM_UNINIT 0
#define SCHM_INIT   1


/**
 * Define error report for DET
 */
/*API IDs*/
#define SCHM_APIID_SCHM_INIT                  0x00
#define SCHM_APIID_SCHM_DEINIT                0x01
#define SCHM_APIID_SCHM_GETVERSIONINFO        0x02
#define SCHM_APIID_SCHM_ENTER                 0x03
#define SCHM_APIID_SCHM_EXIT                  0x04
#define SCHM_APIID_SCHM_ACTIVATEMAINFUNCTION  0x05
#define SCHM_APIID_SCHM_CANCELMAINFUNCTION    0x06
#define SCHM_APIID_SCHM_TASK                  0x07

/*Error IDs*/
#define SCHM_E_PARAM_CONFIG                   0x01
#define SCHM_E_NOT_INIT                       0x02    /*API call befor Init*/


/*******************************************************************************
 * Global functions
 *******************************************************************************/
void SchM_Init( void );

/* Initialisation of global variables, call once before any other SchM function */
void SchM_InitMemory( void );

void SchM_Deinit( void );


#if (SCHM_VERSION_INFO_API == STD_ON)
void SchM_GetVersionInfo( Std_VersionInfoType *versioninfo );
#endif

#endif /* SCHM_H */


