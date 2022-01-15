/* -----------------------------------------------------------------------------
  Filename:     dem.c
  Description:  Implementation of FRFM Wrapper with DEM functions.
                
                Manufacturer: Chrysler
 ----------------------------------------------------------------------------- */

/* -----------------------------------------------------------------------------
    &&&~ History
 ----------------------------------------------------------------------------- */

/*
------------------------------------------------------------------------------------------------------------------------
                                             A U T H O R   I D E N T I T Y
------------------------------------------------------------------------------------------------------------------------
Initials   Name                  Company
---------- --------------------- ---------------------------------------------------------------------------------------
Ayb        Abir Bazzi        Vector CANtech, Inc
------------------------------------------------------------------------------------------------------------------------
                                            R E V I S I O N   H I S T O R Y
------------------------------------------------------------------------------------------------------------------------
Date       Version  Author  Description
---------- -------- ------  ----------------------------------
2012-06-25 01.00.00  Ayb    Template Implementation of FRFM Wrapper with DEM functions.
------------------------------------------------------------------------------------------------------------------------
 */

#if !defined(__DEM_H__)
#define __DEM_H__


/* -----------------------------------------------------------------------------
    &&&~ DEM precompiled parameters
 ----------------------------------------------------------------------------- */
#define DEM_USE_RTE                          STD_ON
#define DEM_VERSION_INFO_API                 STD_ON
#define DEM_DEV_ERROR_DETECT                 STD_ON /*STD_OFF*/


/* -----------------------------------------------------------------------------
    &&&~ Includes
 ----------------------------------------------------------------------------- */
/**
 * File Rte_Type.h contains the typedefs and defines which are required as PortInterface argument
 * and also used in the DEM. If we are not using the RTE, the types will be defined by ourself below
 */
#if (DEM_USE_RTE == STD_ON)
#include "Rte_Type.h"
#endif

/* Use AUTOSAR standard types  */
#ifndef STD_TYPES_H
# include "std_types.h"
#endif

#if (defined(STD_OFF) && defined(STD_ON))
#else
# error "Definition of STD_ON and/or STD_OFF is missing in Std_Types.h"
#endif

#include "v_inc.h"
/* this wrapper founds on the frfm definitions */
#include "frfm.h"

extern VAR(t_FrfmNonVolatileData, AP_DEMIF_VAR) Dem_NvData;

/* -----------------------------------------------------------------------------
    &&&~ Preprocessor constants (defines)
 ----------------------------------------------------------------------------- */

/* * Module version
 * This is the Vector's Autosar DEM main and release version.
 * The version numbers are BCD coded. E.g. a main version of 1.23 is coded with
 * 0x0123, a release version of 9 is coded 0x09.
 */
/* *
 * The Autosar compatible version number is decimal coded
 */
/* from FRFM.h
#define DIAG_FAULTMEMORY_VERSION                                       0x0320
#define DIAG_FAULTMEMORY_RELEASE_VERSION                               0x00
*/

#define DEM_SW_MAJOR_VERSION                                           0x03
#define DEM_SW_MINOR_VERSION                                           0x20
#define DEM_SW_PATCH_VERSION                                           0x00
#define DEM_AR_MAJOR_VERSION                                           0x02   /* Major version of AUTOSAR specification */
#define DEM_AR_MINOR_VERSION                                           0x02   /* Minor version of AUTOSAR specification */
#define DEM_AR_PATCH_VERSION                                           0x01   /* Patch version of AUTOSAR specification */

/* Module identifier */
#define DEM_MODULE_ID                                                  54   /* DEM */
/* Module identifier */
#define DEM_INSTANCE_ID                                                0    /* always 1 instance */
/* Vendor identifier */
#define DEM_VENDOR_ID                                                  30   /* Vector Informatik GmbH */


/**
 * This DEM FRFM wrapper uses following IDs to call the FRFM functionality
 */
/* Enable Condition IDs for Dem_SetEnableCondition() */
#define DEM_ID_EC1_DTC_SETTING_STATUS                                   0x01u
#define DEM_ID_EC5_IOD_FUSE_STATUS                                      0x05u
#define DEM_ID_EC6_NWCONFIG_STATUS                                      0x06u
#define DEM_ID_EC7_BUS_PHYSICAL_STATUS                                  0x07u
#define DEM_ID_EC8_IODEVICE_CONFIG                                      0x08u


/* Operation Cycle IDs for Dem_SetOperationCycleState() */
#define DEM_ID_OPCYC_IGNITIONCYCLE                                      0x00u

/* Oem specific IDs for Dem_SetValueByOemId() */
/* These IDs might be used for Diagnostic Service $22 */
#define DEM_ID_OEM_LOCALVOLTAGE                                         0xE090u
#define DEM_ID_OEM_SYSTEMVOLTAGE                                        0xE091u
#define DEM_ID_OEM_RESET_READINESSGROUP                                 0xE001u

/* Supplier specific IDs for Dem_SetVoltageValue() */
#define DEM_LOCALVOLTAGE                                         0x00u
#define DEM_SYSTEMVOLTAGE                                        0x01u

/* Oem specific IDs for Xxx_DemGetDataValueByDataIdentifier() */
/* These IDs are also used for Diagnostic Service $22 */
#define DEM_ID_DID_ODOMETERVALUE                                        0xE092u


/* ErrorIds for reporting errors to the DET */
/* The FRFM kFrfmAssertXXX values are in range 0x00-0x20, the values below get offset 0x80 to differ */
#define DEM_E_PARAM_CONFIG                                              (0x10+0x80)
#define DEM_E_PARAM_ADDRESS                                             (0x11+0x80)
#define DEM_E_PARAM_DATA                                                (0x12+0x80)
#define DEM_E_PARAM_LENGTH                                              (0x13+0x80)
#define DEM_E_UNINIT                                                    (0x20+0x80)
#define DEM_E_NODATAAVAILABLE                                           (0x30+0x80)

/* Internal ErrorIds */
#define Dem_NVM_E_INTEGRITY_FAILED           47
#define Dem_NVM_E_REQ_FAILED                 48

/* error reporting with Det_ReportError(DEM_MODULE_ID, DEM_INSTANCE_ID, ApiId, ErrorId): */
/* API Service IDs for reporting errors to the DET */
#define DEM_SETEVENTSTATUS_APIID                    0x04
#define DEM_GETEVENTSTATUS_APIID                    0x0a


/* -----------------------------------------------------------------------------
    &&&~ Datatype definitions
 ----------------------------------------------------------------------------- */

typedef uint8 Dem_DTCStatusMaskType;

 typedef uint8 Dem_ReturnGetExtendedDataRecordByDTCType;
 #define DEM_RECORD_OK                                                   0x00u
 #define DEM_RECORD_WRONG_DTC                                            0x01u
 #define DEM_RECORD_WRONG_DTCORIGIN                                      0x02u
 #define DEM_RECORD_WRONG_DTCKIND                                        0x03u
 #define DEM_RECORD_WRONG_NUMBER                                         0x04u
 #define DEM_RECORD_WRONG_BUFFERSIZE                                     0x05u

 typedef uint8 Dem_IndicatorIdType;

#if (DEM_USE_RTE == STD_OFF)
typedef t_FrfmDtcSfnType Dem_EventIdType; /* DTC number type is dependent on total DTC count found in the database. */

typedef uint8 Dem_EventStatusType;
#define DEM_EVENT_STATUS_PASSED                                         0x00u
#define DEM_EVENT_STATUS_FAILED                                         0x01u
#define DEM_EVENT_STATUS_PREPASSED                                      0x02u
#define DEM_EVENT_STATUS_PREFAILED                                      0x03u

typedef uint8 Dem_EventStatusExtendedType;

typedef uint32 Dem_DTCType;

typedef uint8 Dem_OperationCycleIdType;
typedef uint8 Dem_OperationCycleStateType;
#define DEM_CYCLE_STATE_START                                           0x01u
#define DEM_CYCLE_STATE_END                                             0x02u


typedef uint8 Dem_DTCKindType;
#define DEM_DTC_KIND_ALL_DTCS                                           0x01u
#define DEM_DTC_KIND_EMISSION_REL_DTCS                                  0x02u

typedef uint8 Dem_ReturnGetDTCOfEventType;
#define DEM_GET_DTCOFEVENT_OK                                           0x00u
#define DEM_GET_DTCOFEVENT_WRONG_EVENTID                                0x01u
#define DEM_GET_DTCOFEVENT_WRONG_TRANSLATION                            0x02u

typedef sint8 Dem_FaultDetectionCounterType;

typedef uint8 Dem_IndicatorStatusType;
#define DEM_INDICATOR_OFF                                               0x00u
#define DEM_INDICATOR_CONTINUOUS                                        0x01u
#define DEM_INDICATOR_BLINKING                                          0x02u

#endif /* (DEM_USE_RTE == STD_OFF)*/

/* -----------------------------------------------------------------------------
    &&&~ Function prototypes
 ----------------------------------------------------------------------------- */
FUNC(Std_ReturnType, DEM_CODE)
Dem_SetEventStatus(
  Dem_EventIdType       EventId,
  Dem_EventStatusType   EventStatus
  );

FUNC(Std_ReturnType, DEM_CODE)
Dem_GetEventStatus(
  Dem_EventIdType                                               EventId,
  P2VAR(Dem_EventStatusExtendedType, AUTOMATIC, DEM_APPL_DATA)  EventStatusExtended
  );

FUNC(Std_ReturnType, DEM_CODE)
Dem_SetEnableCondition(
  uint8     EnableConditionID,
  boolean   ConditionFulfilled
  );

FUNC(Std_ReturnType, DEM_CODE)
Dem_SetOperationCycleState(
  Dem_OperationCycleIdType      OperationCycleId,
  Dem_OperationCycleStateType   CycleState
  );

#if 0
FUNC(Std_ReturnType, DEM_CODE)
Dem_SetValueByOemId(
  uint16                                  OemID,
  P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA)  DataValue,
  uint8                                   BufferLength
  );
#endif

FUNC(Std_ReturnType, DEM_CODE)
Dem_SetVoltageValue(
  uint8   VoltageID,
  uint16  VoltageValue
  );

FUNC(Std_ReturnType, DEM_CODE)   Dem_GetDTCOfEvent(
  Dem_EventIdType                               EventId,
  Dem_DTCKindType                               DTCKind,
  P2VAR(Dem_DTCType, AUTOMATIC, DEM_APPL_DATA)  DTCOfEvent
  );

FUNC(Std_ReturnType, DEM_CODE)
Dem_ResetEventStatus(
  Dem_EventIdType   EventId
  );

FUNC(Std_ReturnType, DEM_CODE)
Dem_GetEventFailed(
  Dem_EventIdType                           EventId,
  P2VAR(boolean, AUTOMATIC, DEM_APPL_DATA)  EventFailed
  );

FUNC(Std_ReturnType, DEM_CODE)
Dem_GetEventTested(
  Dem_EventIdType                           EventId,
  P2VAR(boolean, AUTOMATIC, DEM_APPL_DATA)  EventTested
  );

FUNC(Std_ReturnType, DEM_CODE)
Dem_GetFaultDetectionCounter(
  Dem_EventIdType                                                 EventId,
  P2VAR(Dem_FaultDetectionCounterType, AUTOMATIC, DEM_APPL_DATA)  EventIdFaultDetectionCounter
);

FUNC(Std_ReturnType, DEM_CODE)
Dem_GetIndicatorStatus(
  Dem_IndicatorIdType                                       Dem_IndicatorId,
  P2VAR(Dem_IndicatorStatusType, AUTOMATIC, DEM_APPL_DATA)  Dem_IndicatorStatus
  );

FUNC(void, DEM_CODE)
Dem_ReportErrorStatus(
  Dem_EventIdType       EventId,
  Dem_EventStatusType   EventStatus
  );

#if (DEM_VERSION_INFO_API == STD_ON)
FUNC(void, DEM_CODE)
Dem_GetVersionInfo(
  P2VAR(Std_VersionInfoType, AUTOMATIC, DEM_APPL_DATA)  versioninfo
  );
#endif

FUNC(Std_ReturnType, DEM_CODE)
Dem_NvDataInit(
  void
  );

FUNC(void, DEM_CODE)
Dem_PreInit(
  void
  );

FUNC(void, DEM_CODE)
Dem_Init(
  void
  );

FUNC(void, DEM_CODE)
Dem_Init1(
  void
  );

FUNC(void, DEM_CODE)
Dem_Shutdown(
  void
  );

FUNC(void, DEM_CODE)
Dem_MainFunction(
  void
  );

/* the following prototypes might need to be updated to match the application/RTE callback functions */
/*
extern Std_ReturnType Xxx_DemTriggerOnDTCStatus( Dem_DTCType DTC, Dem_EventIdType EventId, Dem_DTCStatusMaskType DTCStatusOld, Dem_DTCStatusMaskType DTCStatusNew );
extern Std_ReturnType Xxx_DemGetExtendedDataRecord( uint8 ExtendedDataRecordNumber, uint8 *ExtendedDataRecord );
extern Std_ReturnType Xxx_DemGetDataValueByDataIdentifier( uint16 DataID, uint8 *DemDataValueByDataIDBuffer );
*/

/* the following prototypes are generated in applfrfm.h*/
/*t_FrfmOdometer ApplFrfmGetOdometerValue( void );*/
/*vuint8 ApplFrfmGetAddEnvData( vuint16 recordNumber, vuint8 *chronoStackAddEnvData, vuint8 envDataSize );*/
/*void   ApplFrfmOnDtcStatusChange(t_FrfmDtcNumType dtcNum, t_FrfmDtcStatusByte oldDtcStatus, t_FrfmDtcStatusByte newDtcStatus);*/


/* -----------------------------------------------------------------------------
    &&&~ ROM definitions
 ----------------------------------------------------------------------------- */

//#define Dem_NvData		g_frfmNVData


/* -----------------------------------------------------------------------------
    &&&~ Macro definitions
 ----------------------------------------------------------------------------- */

#if (kFrfmNumConfigs > 1)
# define Dem_PreInit()                                                  FrfmInitPowerOn((t_FrfmNumConfigs) 0)
#else
# define Dem_PreInit()                                                  FrfmInitPowerOn()
#endif
#define Dem_Init()                                                      (void)FrfmPowerUp()
//#define Dem_Shutdown()                                                  FrfmPowerDown()

/* Support of DET to handle assertions */
/* extern void Det_ReportError( uint16 ModuleId, uint8 InstanceId, uint8 ApiId, uint8 ErrorId ); */
#if (DEM_DEV_ERROR_DETECT == STD_ON)
# define Dem_DetReportError(ApiId, ErrorId)   Det_ReportError(DEM_MODULE_ID, DEM_INSTANCE_ID, (ApiId), (ErrorId))
#else
# define Dem_DetReportError(ApiId, ErrorId)   do {/* no DET error reporting */} while(0)
#endif  /* DEM_DEV_ERROR_DETECT */

#define Dem_ReportErrorStatus(id,stat)                                  (void)Dem_SetEventStatus(id,stat)

#endif /* __DEM_H__ */
