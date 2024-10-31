/*
 *  classpnp.h  SCSI class driver functions
 *
 * =========================================================================
 *
 *                          Open Watcom Project
 *
 * Copyright (c) 2004-2024 The Open Watcom Contributors. All Rights Reserved.
 *
 *    This file is automatically generated. Do not edit directly.
 *
 * =========================================================================
 */

#ifndef _CLASS_
#define _CLASS_

#ifndef _ENABLE_AUTODEPEND
 #pragma read_only_file
#endif

#include <ntdddisk.h>
#include <ntddcdrm.h>
#include <ntddtape.h>
#include <ntddscsi.h>
#include <ntddstor.h>
#include <stdio.h>
#include <scsi.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Structured exception handling macros */
#ifdef TRY
    #undef TRY
#endif
#ifdef LEAVE
    #undef LEAVE
#endif
#ifdef FINALLY
    #undef FINALLY
#endif
#define TRY
#define LEAVE   goto __tryLabel;
#define FINALLY __tryLabel:

/* Debug buffer length */
#define DEBUG_BUFFER_LENGTH 256

/* SRB class flags */
#define SRB_CLASS_FLAGS_LOW_PRIORITY    0x10000000L
#define SRB_CLASS_FLAGS_PERSISTENT      0x20000000L
#define SRB_CLASS_FLAGS_PAGING          0x40000000L
#define SRB_CLASS_FLAGS_FREE_MDL        0x80000000L

/* Macros to manipulate flags */
#define SET_FLAG( p1, p2 )      ((p1) |= (p2))
#define CLEAR_FLAG( p1, p2 )    ((p1) &= ~(p2))
#define TEST_FLAG( p1, p2 )     (((p1) & (p2)) != 0)

/* Class tags */
#define CLASS_TAG_AUTORUN_DISABLE           'ALcS'
#define CLASS_TAG_FILE_OBJECT_EXTENSION     'FLcS'
#define CLASS_TAG_MEDIA_CHANGE_DETECTION    'MLcS'
#define CLASS_TAG_MOUNT                     'mLcS'
#define CLASS_TAG_RELEASE_QUEUE             'qLcS'
#define CLASS_TAG_POWER                     'WLcS'
#define CLASS_TAG_WMI                       'wLcS'
#define CLASS_TAG_FAILURE_PREDICT           'fLcS'
#define CLASS_TAG_DEVICE_CONTROL            'OIcS'
#define CLASS_TAG_MODE_DATA                 'oLcS'
#define CLASS_TAG_MULTIPATH                 'mPcS'

/* Maximum number of retries */
#define MAXIMUM_RETRIES 4

/* Removed flags */
#define NO_REMOVE       0
#define REMOVE_PENDING  1
#define REMOVE_COMPLETE 2

/* Timeouts */
#define START_UNIT_TIMEOUT                          240
#define MEDIA_CHANGE_DEFAULT_TIME                   1
#define MEDIA_CHANGE_TIMEOUT_TIME                   300
#define MAXIMUM_RETRY_FOR_SINGLE_IO_IN_100NS_UNITS  0x3B9ACA00

/* Class working set maximum */
#define CLASS_WORKING_SET_MAXIMUM   2048

/* Maximum history count */
#define CLASS_INTERPRET_SENSE_INFO2_MAXIMUM_HISTORY_COUNT   30000

/* Default failure prediction period */
#define DEFAULT_FAILURE_PREDICTION_PERIOD   3600

/* Class scan for special flags */
#define CLASS_SPECIAL_DISABLE_SPIN_DOWN                     0x00000001L
#define CLASS_SPECIAL_DISABLE_SPIN_UP                       0x00000002L
#define CLASS_SPECIAL_NO_QUEUE_LOCK                         0x00000008L
#define CLASS_SPECIAL_DISABLE_WRITE_CACHE                   0x00000010L
#define CLASS_SPECIAL_CAUSE_NOT_REPORTABLE_HACK             0x00000020L
#if (NTDDI_VERSION == 0x05000300) || (OSVER( NTDDI_VERSION ) == 0x05010000)
    #define CLASS_SPECIAL_DISABLE_WRITE_CACHE_NOT_SUPPORTED 0x00000040L
#endif
#define CLASS_SPECIAL_MODIFY_CACHE_UNSUCCESSFUL             0x00000040L
#define CLASS_SPECIAL_FUA_NOT_SUPPORTED                     0x00000080L
#define CLASS_SPECIAL_VALID_MASK                            0x000000FBL

/* Device flags */
#define DEV_WRITE_CACHE     0x00000001L
#define DEV_USE_SCSI1       0x00000002L
#define DEV_SAFE_START_UNIT 0x00000004L
#define DEV_NO_12BYTE_CDB   0x00000008L
#define DEV_POWER_PROTECTED 0x00000010L
#define DEV_USE_16BYTE_CDB  0x00000020L

/* Class GUIDs */
#define GUID_CLASSPNP_QUERY_REGINFOEX \
    { 0x00E34B11, 0x2444, 0x4745, { 0xA5, 0x3D, 0x62, 0x01, 0x00, 0xCD, 0x82, 0xF7 } }
#define GUID_CLASSPNP_SENSEINFO2 \
    { 0x509A8C5F, 0x71D7, 0x48F6, { 0x82, 0x1E, 0x17, 0x3C, 0x49, 0xBF, 0x2F, 0x18 } }
#define GUID_CLASSPNP_WORKING_SET \
    { 0x105701B0, 0x9E9B, 0x47CB, { 0x97, 0x80, 0x81, 0x19, 0x8A, 0xF7, 0xB5, 0x24 } }

/* Opaque data types */
typedef struct _CLASS_PRIVATE_FDO_DATA      CLASS_PRIVATE_FDO_DATA;
typedef struct _CLASS_PRIVATE_FDO_DATA      *PCLASS_PRIVATE_FDO_DATA;
typedef struct _CLASS_PRIVATE_PDO_DATA      CLASS_PRIVATE_PDO_DATA;
typedef struct _CLASS_PRIVATE_PDO_DATA      *PCLASS_PRIVATE_PDO_DATA;
typedef struct _CLASS_PRIVATE_COMMON_DATA   CLASS_PRIVATE_COMMON_DATA;
typedef struct _CLASS_PRIVATE_COMMON_DATA   *PCLASS_PRIVATE_COMMON_DATA;
typedef struct _MEDIA_CHANGE_DETECTION_INFO MEDIA_CHANGE_DETECTION_INFO;
typedef struct _MEDIA_CHANGE_DETECTION_INFO *PMEDIA_CHANGE_DETECTION_INFO;
typedef struct _DICTIONARY_HEADER           DICTIONARY_HEADER;
typedef struct _DICTIONARY_HEADER           *PDICTIONARY_HEADER;
typedef struct _FAILURE_PREDICTION_INFO     FAILURE_PREDICTION_INFO;
typedef struct _FAILURE_PREDICTION_INFO     *PFAILURE_PREDICTION_INFO;

/* Class debug levels */
typedef enum _CLASS_DEBUG_LEVEL {
    ClassDebugError         = 0,
    ClassDebugWarning       = 1,
    ClassDebugTrace         = 2,
    ClassDebugInfo          = 3,
    ClassDebugMediaLocks    = 8,
    ClassDebugMCN           = 9,
    ClassDebugDelayedRetry  = 10,
    ClassDebugSenseInfo     = 11,
    ClassDebugRemoveLock    = 12,
    ClassDebugExternal4     = 13,
    ClassDebugExternal3     = 14,
    ClassDebugExternal2     = 15,
    ClassDebugExternal1     = 16
} CLASS_DEBUG_LEVEL;
typedef CLASS_DEBUG_LEVEL   *PCLASS_DEBUG_LEVEL;

/* Media change detection states */
typedef enum _MEDIA_CHANGE_DETECTION_STATE {
    MediaUnknown        = 0,
    MediaPresent        = 1,
    MediaNotPresent     = 2,
    MediaUnavailable    = 3
} MEDIA_CHANGE_DETECTION_STATE;
typedef MEDIA_CHANGE_DETECTION_STATE    *PMEDIA_CHANGE_DETECTION_STATE;

/* Dictionary */
typedef struct _DICTIONARY {
    ULONGLONG           Signature;
    PDICTIONARY_HEADER  List;
    KSPIN_LOCK          SpinLock;
} DICTIONARY;
typedef DICTIONARY  *PDICTIONARY;

/* Scan for special information */
typedef struct _CLASSPNP_SCAN_FOR_SPECIAL_INFO {
    PCHAR       VendorId;
    PCHAR       ProductId;
    PCHAR       ProductRevision;
    ULONG_PTR   Data;
} CLASSPNP_SCAN_FOR_SPECIAL_INFO;
typedef CLASSPNP_SCAN_FOR_SPECIAL_INFO  *PCLASSPNP_SCAN_FOR_SPECIAL_INFO;

/* Class enable/disable function values */
typedef enum {
    EventGeneration     = 0,
    DataBlockCollection = 1
} CLASSENABLEDISABLEFUNCTION;

/* SRB history item */
typedef struct _SRB_HISTORY_ITEM {
    LARGE_INTEGER   TickCountSent;
    LARGE_INTEGER   TickCountCompleted;
    ULONG           MillisecondsDelayOnRetry;
    SENSE_DATA      NormalizedSenseData;
    UCHAR           SrbStatus;
    UCHAR           ClassDriverUse;
} SRB_HISTORY_ITEM;
typedef SRB_HISTORY_ITEM    *PSRB_HISTORY_ITEM;

/* SRB history */
typedef struct _SRB_HISTORY {
    ULONG_PTR           ClassDriverUse[4];
    ULONG               TotalHistoryCount;
    ULONG               UsedHistoryCount;
    SRB_HISTORY_ITEM    History[1];
} SRB_HISTORY;
typedef SRB_HISTORY *PSRB_HISTORY;

/* Class callbacks */
typedef VOID        (NTAPI *PCLASS_ERROR)( PDEVICE_OBJECT, PSCSI_REQUEST_BLOCK, NTSTATUS *, BOOLEAN * );
typedef NTSTATUS    (NTAPI *PCLASS_ADD_DEVICE)( PDRIVER_OBJECT, PDEVICE_OBJECT );
typedef NTSTATUS    (NTAPI *PCLASS_POWER_DEVICE)( PDEVICE_OBJECT, PIRP );
typedef NTSTATUS    (NTAPI *PCLASS_START_DEVICE)( PDEVICE_OBJECT );
typedef NTSTATUS    (NTAPI *PCLASS_STOP_DEVICE)( PDEVICE_OBJECT, UCHAR );
typedef NTSTATUS    (NTAPI *PCLASS_INIT_DEVICE)( PDEVICE_OBJECT );
typedef NTSTATUS    (NTAPI *PCLASS_ENUM_DEVICE)( PDEVICE_OBJECT );
typedef NTSTATUS    (NTAPI *PCLASS_READ_WRITE)( PDEVICE_OBJECT, PIRP );
typedef NTSTATUS    (NTAPI *PCLASS_DEVICE_CONTROL)( PDEVICE_OBJECT, PIRP );
typedef NTSTATUS    (NTAPI *PCLASS_SHUTDOWN_FLUSH)( PDEVICE_OBJECT, PIRP );
typedef NTSTATUS    (NTAPI *PCLASS_CREATE_CLOSE)( PDEVICE_OBJECT, PIRP );
typedef NTSTATUS    (NTAPI *PCLASS_QUERY_ID)( PDEVICE_OBJECT, BUS_QUERY_ID_TYPE, PUNICODE_STRING );
typedef NTSTATUS    (NTAPI *PCLASS_REMOVE_DEVICE)( PDEVICE_OBJECT, UCHAR );
typedef VOID        (NTAPI *PCLASS_UNLOAD)( PDRIVER_OBJECT );
typedef NTSTATUS    (NTAPI *PCLASS_QUERY_PNP_CAPABILITIES)( PDEVICE_OBJECT, PDEVICE_CAPABILITIES );
typedef VOID        (NTAPI *PCLASS_TICK)( PDEVICE_OBJECT );
typedef NTSTATUS    (NTAPI *PCLASS_QUERY_WMI_REGINFO_EX)( PDEVICE_OBJECT, ULONG *, PUNICODE_STRING, PUNICODE_STRING );
typedef NTSTATUS    (NTAPI *PCLASS_QUERY_WMI_REGINFO)( PDEVICE_OBJECT, ULONG *, PUNICODE_STRING );
typedef NTSTATUS    (NTAPI *PCLASS_QUERY_WMI_DATABLOCK)( PDEVICE_OBJECT, PIRP, ULONG, ULONG, PUCHAR );
typedef NTSTATUS    (NTAPI *PCLASS_SET_WMI_DATABLOCK)( PDEVICE_OBJECT, PIRP, ULONG, ULONG, PUCHAR );
typedef NTSTATUS    (NTAPI *PCLASS_SET_WMI_DATAITEM)( PDEVICE_OBJECT, PIRP, ULONG, ULONG, ULONG, PUCHAR );
typedef NTSTATUS    (NTAPI *PCLASS_EXECUTE_WMI_METHOD)( PDEVICE_OBJECT, PIRP, ULONG, ULONG, ULONG, ULONG, PUCHAR );
typedef NTSTATUS    (NTAPI *PCLASS_WMI_FUNCTION_CONTROL)( PDEVICE_OBJECT, PIRP, ULONG, CLASSENABLEDISABLEFUNCTION, BOOLEAN );
typedef BOOLEAN     (NTAPI *PCLASS_INTERPRET_SENSE_INFO)( PDEVICE_OBJECT, PIRP, PSCSI_REQUEST_BLOCK, UCHAR, ULONG, ULONG, SRB_HISTORY *, NTSTATUS *, LONGLONG * );
typedef VOID        (NTAPI *PCLASS_COMPRESS_RETRY_HISTORY_DATA)( PDEVICE_OBJECT, PSRB_HISTORY );

/* GUID registration information */
typedef struct {
    GUID    Guid;
    ULONG   InstanceCount;
    ULONG   Flags;
} GUIDREGINFO;
typedef GUIDREGINFO *PGUIDREGINFO;

/* Class WMI information */
typedef struct _CLASS_WMI_INFO {
    ULONG                       GuidCount;
    PGUIDREGINFO                GuidRegInfo;
    PCLASS_QUERY_WMI_REGINFO    ClassQueryWmiRegInfo;
    PCLASS_QUERY_WMI_DATABLOCK  ClassQueryWmiDataBlock;
    PCLASS_SET_WMI_DATABLOCK    ClassSetWmiDataBlock;
    PCLASS_SET_WMI_DATAITEM     ClassSetWmiDataItem;
    PCLASS_EXECUTE_WMI_METHOD   ClassExecuteWmiMethod;
    PCLASS_WMI_FUNCTION_CONTROL ClassWmiFunctionControl;
} CLASS_WMI_INFO;
typedef CLASS_WMI_INFO  *PCLASS_WMI_INFO;

/* Class device information */
typedef struct _CLASS_DEV_INFO {
    ULONG                           DeviceExtensionSize;
    DEVICE_TYPE                     DeviceType;
    UCHAR                           StackSize;
    ULONG                           DeviceCharacteristics;
    PCLASS_ERROR                    ClassError;
    PCLASS_READ_WRITE               ClassReadWriteVerification;
    PCLASS_DEVICE_CONTROL           ClassDeviceControl;
    PCLASS_SHUTDOWN_FLUSH           ClassShutdownFlush;
    PCLASS_CREATE_CLOSE             ClassCreateClose;
    PCLASS_INIT_DEVICE              ClassInitDevice;
    PCLASS_START_DEVICE             ClassStartDevice;
    PCLASS_POWER_DEVICE             ClassPowerDevice;
    PCLASS_STOP_DEVICE              ClassStopDevice;
    PCLASS_REMOVE_DEVICE            ClassRemoveDevice;
    PCLASS_QUERY_PNP_CAPABILITIES   ClassQueryPnpCapabilities;
    CLASS_WMI_INFO                  ClassWmiInfo;
} CLASS_DEV_INFO;
typedef CLASS_DEV_INFO  *PCLASS_DEV_INFO;

/* Class initialization data */
typedef struct _CLASS_INIT_DATA {
    ULONG               InitializationDataSize;
    CLASS_DEV_INFO      FdoData;
    CLASS_DEV_INFO      PdoData;
    PCLASS_ADD_DEVICE   ClassAddDevice;
    PCLASS_ENUM_DEVICE  ClassEnumerateDevice;
    PCLASS_QUERY_ID     ClassQueryId;
    PDRIVER_STARTIO     ClassStartIo;
    PCLASS_UNLOAD       ClassUnload;
    PCLASS_TICK         ClassTick;
} CLASS_INIT_DATA;
typedef CLASS_INIT_DATA *PCLASS_INIT_DATA;

/* File object extension */
typedef struct _FILE_OBJECT_EXTENSION {
    PFILE_OBJECT    FileObject;
    PDEVICE_OBJECT  DeviceObject;
    ULONG           LockCount;
    ULONG           McnDisableCount;
} FILE_OBJECT_EXTENSION;
typedef FILE_OBJECT_EXTENSION   *PFILE_OBJECT_EXTENSION;

/* Class working set */
typedef struct _CLASS_WORKING_SET {
    ULONG   Size;
    ULONG   XferPacketsWorkingSetMaximum;
    ULONG   XferPacketsWorkingSetMinimum;
} CLASS_WORKING_SET;
typedef CLASS_WORKING_SET   *PCLASS_WORKING_SET;

/* Class interpret sense information (version 2) */
typedef struct _CLASS_INTERPRET_SENSE_INFO2 {
    ULONG                               Size;
    ULONG                               HistoryCount;
    PCLASS_COMPRESS_RETRY_HISTORY_DATA  Compress;
    PCLASS_INTERPRET_SENSE_INFO         Interpret;
} CLASS_INTERPRET_SENSE_INFO2;
typedef CLASS_INTERPRET_SENSE_INFO2 *PCLASS_INTERPRET_SENSE_INFO2;

/* Class driver extension */
typedef struct _CLASS_DRIVER_EXTENSION {
    UNICODE_STRING                  RegistryPath;
    CLASS_INIT_DATA                 InitData;
    ULONG                           DeviceCount;
#if (NTDDI_VERSION >= 0x05010000)
    PCLASS_QUERY_WMI_REGINFO_EX     ClassFdoQueryWmiRegInfoEx;
    PCLASS_QUERY_WMI_REGINFO_EX     ClassPdoQueryWmiRegInfoEx;
#endif
#if (NTDDI_VERSION >= 0x06000000)
    REGHANDLE                       EtwHandle;
    PDRIVER_DISPATCH                DeviceMajorFunctionTable[IRP_MJ_MAXIMUM_FUNCTION + 1];
    PDRIVER_DISPATCH                MpDeviceMajorFunctionTable[IRP_MJ_MAXIMUM_FUNCTION + 1];
    PCLASS_INTERPRET_SENSE_INFO2    InterpretSenseInfo;
    PCLASS_WORKING_SET              WorkingSet;
#endif
} CLASS_DRIVER_EXTENSION;
typedef CLASS_DRIVER_EXTENSION  *PCLASS_DRIVER_EXTENSION;

/* Common device extension */
typedef struct _COMMON_DEVICE_EXTENSION {
    ULONG                               Version;
    PDEVICE_OBJECT                      DeviceObject;
    PDEVICE_OBJECT                      LowerDeviceObject;
    struct _FUNCTIONAL_DEVICE_EXTENSION *PartitionZeroExtension;
    PCLASS_DRIVER_EXTENSION             DriverExtension;
    LONG                                RemoveLock;
    KEVENT                              RemoveEvent;
    KSPIN_LOCK                          RemoveTrackingSpinlock;
    PVOID                               RemoveTrackingList;
    LONG                                RemoveTrackingUntrackedCount;
    PVOID                               DriverData;
    struct {
        BOOLEAN IsFdo                           : 1;
        BOOLEAN IsInitialized                   : 1;
        BOOLEAN IsSrbLookasideListInitialized   : 1;
    };
    UCHAR                               PreviousState;
    UCHAR                               CurrentState;
    ULONG                               IsRemoved;
    UNICODE_STRING                      DeviceName;
    struct _PHYSICAL_DEVICE_EXTENSION   *ChildList;
    ULONG                               PartitionNumber;
    LARGE_INTEGER                       PartitionLength;
    LARGE_INTEGER                       StartingOffset;
    PCLASS_DEV_INFO                     DevInfo;
    ULONG                               PagingPathCount;
    ULONG                               DumpPathCount;
    ULONG                               HibernationPathCount;
    KEVENT                              PathCountEvent;
#ifndef ALLOCATE_SRB_FROM_POOL
    NPAGED_LOOKASIDE_LIST               SrbLookasideList;
#endif
    UNICODE_STRING                      MountedDeviceInterfaceName;
    ULONG                               GuidCount;
    PGUIDREGINFO                        GuidRegInfo;
    DICTIONARY                          FileObjectDictionary;
#if (NTDDI_VERSION >= 0x05010000)
    PCLASS_PRIVATE_COMMON_DATA          PrivateCommonData;
#else
    ULONG_PTR                           Reserved1;
#endif
#if (NTDDI_VERSION >= 0x06000000)
    PDRIVER_DISPATCH                    *DispatchTable;
#else
    ULONG_PTR                           Reserved2;
#endif
    ULONG_PTR                           Reserved3;
    ULONG_PTR                           Reserved4;
} COMMON_DEVICE_EXTENSION;
typedef COMMON_DEVICE_EXTENSION *PCOMMON_DEVICE_EXTENSION;

/* Failure prediction methods */
typedef enum {
    FailurePredictionNone   = 0,
    FailurePredictionIoctl  = 1,
    FailurePredictionSmart  = 2,
    FailurePredictionSense  = 3
} FAILURE_PREDICTION_METHOD;
typedef FAILURE_PREDICTION_METHOD   *PFAILURE_PREDICTION_METHOD;

/* Class power options */
typedef struct _CLASS_POWER_OPTIONS {
    ULONG   PowerDown       : 1;
    ULONG   LockQueue       : 1;
    ULONG   HandleSpinDown  : 1;
    ULONG   HandleSpinUp    : 1;
    ULONG   Reserved        : 27;
} CLASS_POWER_OPTIONS;
typedef CLASS_POWER_OPTIONS *PCLASS_POWER_OPTIONS;

/* Class power-down states */
typedef enum {
    PowerDownDeviceInitial  = 0,
    PowerDownDeviceLocked   = 1,
    PowerDownDeviceStopped  = 2,
    PowerDownDeviceOff      = 3,
    PowerDownDeviceUnlocked = 4
} CLASS_POWER_DOWN_STATE;

/* Class power-down states (version 2) */
typedef enum {
    PowerDownDeviceInitial2     = 0,
    PowerDownDeviceLocked2      = 1,
    PowerDownDeviceFlushed2     = 2,
    PowerDownDeviceStopped2     = 3,
    PowerDownDeviceOff2         = 4,
    PowerDownDeviceUnlocked2    = 5
} CLASS_POWER_DOWN_STATE2;

/* Class power-up states */
typedef enum {
    PowerUpDeviceInitial    = 0,
    PowerUpDeviceLocked     = 1,
    PowerUpDeviceOn         = 2,
    PowerUpDeviceStarted    = 3,
    PowerUpDeviceUnlocked   = 4
} CLASS_POWER_UP_STATE;

/* Class power context */
typedef struct _CLASS_POWER_CONTEXT {
    union {
        CLASS_POWER_DOWN_STATE  PowerDown;
        CLASS_POWER_DOWN_STATE2 PowerDown2;
        CLASS_POWER_UP_STATE    PowerUp;
    } PowerChangeState;
    CLASS_POWER_OPTIONS     Options;
    BOOLEAN                 InUse;
    BOOLEAN                 QueueLocked;
    NTSTATUS                FinalStatus;
    ULONG                   RetryCount;
    ULONG                   RetryInterval;
    PIO_COMPLETION_ROUTINE  CompletionRoutine;
    PDEVICE_OBJECT          DeviceObject;
    PIRP                    Irp;
    SCSI_REQUEST_BLOCK      Srb;
} CLASS_POWER_CONTEXT;
typedef CLASS_POWER_CONTEXT *PCLASS_POWER_CONTEXT;

/* Functional device extension */
typedef struct _FUNCTIONAL_DEVICE_EXTENSION {
    union {
        struct {
            ULONG           Version;
            PDEVICE_OBJECT  DeviceObject;
        };
        COMMON_DEVICE_EXTENSION CommonExtension;
    };
    PDEVICE_OBJECT                  LowerPdo;
    PSTORAGE_DEVICE_DESCRIPTOR      DeviceDescriptor;
    PSTORAGE_ADAPTER_DESCRIPTOR     AdapterDescriptor;
    DEVICE_POWER_STATE              DevicePowerState;
    ULONG                           DMByteSkew;
    ULONG                           DMSkew;
    BOOLEAN                         DMActive;
    DISK_GEOMETRY                   DiskGeometry;
    PSENSE_DATA                     SenseData;
    ULONG                           TimeOutValue;
    ULONG                           DeviceNumber;
    ULONG                           SrbFlags;
    ULONG                           ErrorCount;
    ULONG                           LockCount;
    ULONG                           ProtectedLockCount;
    ULONG                           InternalLockCount;
    KEVENT                          EjectSynchronizationEvent;
    USHORT                          DeviceFlags;
    UCHAR                           SectorShift;
#if (NTDDI_VERSION >= 0x06000000)
    UCHAR                           CdbForceUnitAccess;
#else
    UCHAR                           ReservedByte;
#endif
    PMEDIA_CHANGE_DETECTION_INFO    MediaChangeDetectionInfo;
    PKEVENT                         Unused1;
    HANDLE                          Unused2;
    FILE_OBJECT_EXTENSION           KernelModeMcnContext;
    ULONG                           MediaChangeCount;
    HANDLE                          DeviceDirectory;
    KSPIN_LOCK                      ReleaseQueueSpinLock;
    PIRP                            ReleaseQueueIrp;
    SCSI_REQUEST_BLOCK              ReleaseQueueSrb;
    BOOLEAN                         ReleaseQueueNeeded;
    BOOLEAN                         ReleaseQueueInProgress;
    BOOLEAN                         ReleaseQueueIrpFromPool;
    BOOLEAN                         FailurePredicted;
    ULONG                           FailureReason;
    PFAILURE_PREDICTION_INFO        FailurePredictionInfo;
    BOOLEAN                         PowerDownInProgress;
    ULONG                           EnumerationInterlock;
    KEVENT                          ChildLock;
    PKTHREAD                        ChildLockOwner;
    ULONG                           ChildLockAcquisitionCount;
    ULONG                           ScanForSpecialFlags;
    KDPC                            PowerRetryDpc;
    KTIMER                          PowerRetryTimer;
    CLASS_POWER_CONTEXT             PowerContext;
#if (NTDDI_VERSION <= 0x05000000)
#if (SPVER( NTDDI_VERSION ) < 2)
    ULONG_PTR                       Reserved1;
    ULONG_PTR                       Reserved2;
    ULONG_PTR                       Reserved3;
    ULONG_PTR                       Reserved4;
#else
    ULONG                           CompletionSuccessCount;
    ULONG                           SavedSrbFlags;
    ULONG                           SavedErrorCount;
    ULONG_PTR                       Reserved1;
#endif
#else
    PCLASS_PRIVATE_FDO_DATA         PrivateFdoData;
    ULONG_PTR                       Reserved2;
    ULONG_PTR                       Reserved3;
    ULONG_PTR                       Reserved4;
#endif
} FUNCTIONAL_DEVICE_EXTENSION;
typedef FUNCTIONAL_DEVICE_EXTENSION *PFUNCTIONAL_DEVICE_EXTENSION;

/* Physical device extension */
typedef struct _PHYSICAL_DEVICE_EXTENSION {
    union {
        struct {
            ULONG           Version;
            PDEVICE_OBJECT  DeviceObject;
        };
        COMMON_DEVICE_EXTENSION CommonExtension;
    };
    BOOLEAN                 IsMissing;
    BOOLEAN                 IsEnumerated;
#if (NTDDI_VERSION >= 0x05010000)
    PCLASS_PRIVATE_PDO_DATA PrivatePdoData;
#else
    ULONG_PTR               Reserved1;
#endif
    ULONG_PTR               Reserved2;
    ULONG_PTR               Reserved3;
    ULONG_PTR               Reserved4;
} PHYSICAL_DEVICE_EXTENSION;
typedef PHYSICAL_DEVICE_EXTENSION   *PPHYSICAL_DEVICE_EXTENSION;

/* Completion context */
typedef struct _COMPLETION_CONTEXT {
    PDEVICE_OBJECT      DeviceObject;
    SCSI_REQUEST_BLOCK  Srb;
} COMPLETION_CONTEXT;
typedef COMPLETION_CONTEXT  *PCOMPLETION_CONTEXT;

/* Class query WMI registration information list (extended version) */
typedef struct _CLASS_QUERY_WMI_REGINFO_EX_LIST {
    ULONG                       Size;
    PCLASS_QUERY_WMI_REGINFO_EX ClassFdoQueryWmiRegInfoEx;
    PCLASS_QUERY_WMI_REGINFO_EX ClassPdoQueryWmiRegInfoEx;
} CLASS_QUERY_WMI_REGINFO_EX_LIST;
typedef CLASS_QUERY_WMI_REGINFO_EX_LIST *PCLASS_QUERY_WMI_REGINFO_EX_LIST;

/* ClassScanForSpecial() callback */
typedef VOID        (NTAPI *PCLASS_SCAN_FOR_SPECIAL_HANDLER)( PFUNCTIONAL_DEVICE_EXTENSION, ULONG_PTR );

/* Functions in CLASSPNP.SYS */
SCSIPORT_API VOID       NTAPI ClassAcquireChildLock( PFUNCTIONAL_DEVICE_EXTENSION );
SCSIPORT_API ULONG      NTAPI ClassAcquireRemoveLockEx( PDEVICE_OBJECT, PVOID, PCSTR, ULONG );
SCSIPORT_API NTSTATUS   NTAPI ClassAsynchronousCompletion( PDEVICE_OBJECT, PIRP, PVOID );
SCSIPORT_API NTSTATUS   NTAPI ClassBuildRequest( PDEVICE_OBJECT, PIRP );
SCSIPORT_API VOID       NTAPI ClassCheckMediaState( PFUNCTIONAL_DEVICE_EXTENSION );
SCSIPORT_API NTSTATUS   NTAPI ClassClaimDevice( PDEVICE_OBJECT, BOOLEAN );
SCSIPORT_API VOID       NTAPI ClassCleanupMediaChangeDetection( PFUNCTIONAL_DEVICE_EXTENSION );
SCSIPORT_API VOID       NTAPI ClassCompleteRequest( PDEVICE_OBJECT, PIRP, CCHAR );
SCSIPORT_API NTSTATUS   NTAPI ClassCreateDeviceObject( PDRIVER_OBJECT, PCCHAR, PDEVICE_OBJECT, BOOLEAN, PDEVICE_OBJECT * );
SCSIPORT_API VOID       __cdecl ClassDebugPrint( CLASS_DEBUG_LEVEL, PCCHAR, ... );
SCSIPORT_API VOID       NTAPI ClassDeleteSrbLookasideList( PCOMMON_DEVICE_EXTENSION );
SCSIPORT_API NTSTATUS   NTAPI ClassDeviceControl( PDEVICE_OBJECT, PIRP );
SCSIPORT_API VOID       NTAPI ClassDisableMediaChangeDetection( PFUNCTIONAL_DEVICE_EXTENSION );
SCSIPORT_API VOID       NTAPI ClassEnableMediaChangeDetection( PFUNCTIONAL_DEVICE_EXTENSION );
SCSIPORT_API PVOID      NTAPI ClassFindModePage( PCHAR, ULONG, UCHAR, BOOLEAN );
SCSIPORT_API NTSTATUS   NTAPI ClassForwardIrpSynchronous( PCOMMON_DEVICE_EXTENSION, PIRP );
SCSIPORT_API NTSTATUS   NTAPI ClassGetDescriptor( PDEVICE_OBJECT, PSTORAGE_PROPERTY_ID, PVOID * );
SCSIPORT_API VOID       NTAPI ClassGetDeviceParameter( PFUNCTIONAL_DEVICE_EXTENSION, PWSTR, PWSTR, PULONG );
SCSIPORT_API PCLASS_DRIVER_EXTENSION NTAPI ClassGetDriverExtension( PDRIVER_OBJECT );
SCSIPORT_API PVPB       NTAPI ClassGetVpb( PDEVICE_OBJECT );
SCSIPORT_API ULONG      NTAPI ClassInitialize( PVOID, PVOID, PCLASS_INIT_DATA );
SCSIPORT_API ULONG      NTAPI ClassInitializeEx( PDRIVER_OBJECT, LPGUID, PVOID );
SCSIPORT_API VOID       NTAPI ClassInitializeMediaChangeDetection( PFUNCTIONAL_DEVICE_EXTENSION, PUCHAR );
SCSIPORT_API VOID       NTAPI ClassInitializeSrbLookasideList( PCOMMON_DEVICE_EXTENSION, ULONG );
SCSIPORT_API NTSTATUS   NTAPI ClassInitializeTestUnitPolling( PFUNCTIONAL_DEVICE_EXTENSION, BOOLEAN );
SCSIPORT_API NTSTATUS   NTAPI ClassInternalIoControl( PDEVICE_OBJECT, PIRP );
SCSIPORT_API BOOLEAN    NTAPI ClassInterpretSenseInfo( PDEVICE_OBJECT, PSCSI_REQUEST_BLOCK, UCHAR, ULONG, ULONG, NTSTATUS *, ULONG * );
SCSIPORT_API VOID       NTAPI ClassInvalidateBusRelations( PDEVICE_OBJECT );
SCSIPORT_API NTSTATUS   NTAPI ClassIoComplete( PDEVICE_OBJECT, PIRP, PVOID );
SCSIPORT_API NTSTATUS   NTAPI ClassIoCompleteAssociated( PDEVICE_OBJECT, PIRP, PVOID );
SCSIPORT_API BOOLEAN    NTAPI ClassMarkChildMissing( PPHYSICAL_DEVICE_EXTENSION, BOOLEAN );
SCSIPORT_API VOID       NTAPI ClassMarkChildrenMissing( PFUNCTIONAL_DEVICE_EXTENSION );
SCSIPORT_API ULONG      NTAPI ClassModeSense( PDEVICE_OBJECT, PCHAR, ULONG, UCHAR );
SCSIPORT_API VOID       NTAPI ClassNotifyFailurePredicted( PFUNCTIONAL_DEVICE_EXTENSION, PUCHAR, ULONG, BOOLEAN, ULONG, UCHAR, UCHAR, UCHAR );
SCSIPORT_API ULONG      NTAPI ClassQueryTimeOutRegistryValue( PDEVICE_OBJECT );
SCSIPORT_API NTSTATUS   NTAPI ClassReadDriveCapacity( PDEVICE_OBJECT );
SCSIPORT_API VOID       NTAPI ClassReleaseChildLock( PFUNCTIONAL_DEVICE_EXTENSION );
SCSIPORT_API VOID       NTAPI ClassReleaseQueue( PDEVICE_OBJECT );
SCSIPORT_API VOID       NTAPI ClassReleaseRemoveLock( PDEVICE_OBJECT, PIRP );
SCSIPORT_API NTSTATUS   NTAPI ClassRemoveDevice( PDEVICE_OBJECT, UCHAR );
SCSIPORT_API VOID       NTAPI ClassResetMediaChangeTimer( PFUNCTIONAL_DEVICE_EXTENSION );
SCSIPORT_API VOID       NTAPI ClassScanForSpecial( PFUNCTIONAL_DEVICE_EXTENSION, CLASSPNP_SCAN_FOR_SPECIAL_INFO [], PCLASS_SCAN_FOR_SPECIAL_HANDLER );
SCSIPORT_API VOID       NTAPI ClassSendDeviceIoControlSynchronous( ULONG, PDEVICE_OBJECT, PVOID, ULONG, ULONG, BOOLEAN, PIO_STATUS_BLOCK );
SCSIPORT_API NTSTATUS   NTAPI ClassSendIrpSynchronous( PDEVICE_OBJECT, PIRP );
SCSIPORT_API NTSTATUS   NTAPI ClassSendSrbAsynchronous( PDEVICE_OBJECT, PSCSI_REQUEST_BLOCK, PIRP, PVOID, ULONG, BOOLEAN );
SCSIPORT_API NTSTATUS   NTAPI ClassSendSrbSynchronous( PDEVICE_OBJECT, PSCSI_REQUEST_BLOCK, PVOID, ULONG, BOOLEAN );
SCSIPORT_API VOID       NTAPI ClassSendStartUnit( PDEVICE_OBJECT );
SCSIPORT_API NTSTATUS   NTAPI ClassSetDeviceParameter( PFUNCTIONAL_DEVICE_EXTENSION, PWSTR, PWSTR, ULONG );
SCSIPORT_API NTSTATUS   NTAPI ClassSetFailurePredictionPoll( PFUNCTIONAL_DEVICE_EXTENSION, FAILURE_PREDICTION_METHOD, ULONG );
SCSIPORT_API VOID       NTAPI ClassSetMediaChangeState( PFUNCTIONAL_DEVICE_EXTENSION, MEDIA_CHANGE_DETECTION_STATE, BOOLEAN );
SCSIPORT_API NTSTATUS   NTAPI ClassSignalCompletion( PDEVICE_OBJECT, PIRP, PKEVENT );
SCSIPORT_API NTSTATUS   NTAPI ClassSpinDownPowerHandler( PDEVICE_OBJECT, PIRP );
SCSIPORT_API VOID       NTAPI ClassSplitRequest( PDEVICE_OBJECT, PIRP, ULONG );
SCSIPORT_API NTSTATUS   NTAPI ClassStopUnitPowerHandler( PDEVICE_OBJECT, PIRP );
SCSIPORT_API VOID       NTAPI ClassUpdateInformationInRegistry( PDEVICE_OBJECT, PCHAR, ULONG, PINQUIRYDATA, ULONG );
SCSIPORT_API NTSTATUS   NTAPI ClassWmiCompleteRequest( PDEVICE_OBJECT, PIRP, NTSTATUS, ULONG, CCHAR );
SCSIPORT_API NTSTATUS   NTAPI ClassWmiFireEvent( PDEVICE_OBJECT, LPGUID, ULONG, ULONG, PVOID );
#if (NTDDI_VERSION >= 0x06000000)
SCSIPORT_API PFILE_OBJECT_EXTENSION NTAPI ClassGetFsContext( PCOMMON_DEVICE_EXTENSION, PFILE_OBJECT );
SCSIPORT_API VOID       NTAPI ClassSendNotification( PFUNCTIONAL_DEVICE_EXTENSION, const GUID *, ULONG, PVOID );
#endif

/* Functions implemented as macros */
#define ClassAcquireRemoveLock( p1, p2 ) \
    ClassAcquireRemoveLockEx( p1, p2, __FILE__, __LINE__ )
#ifdef ALLOCATE_SRB_FROM_POOL
    #define ClasspAllocateSrb( x ) \
        ExAllocatePoolWithTag( NonPagedPool, sizeof( SCSI_REQUEST_BLOCK ), 'sBRS' )
    #define ClasspFreeSrb( p1, p2 ) \
        ExFreePool( p2 )
#else
    #define ClasspAllocateSrb( x ) \
        ExAllocateFromNPagedLookasideList( &((x)->CommonExtension.SrbLookasideList) )
    #define ClasspFreeSrb( p1, p2 ) \
        ExFreeToNPagedLookasideList( &((p1)->CommonExtension.SrbLookasideList), p2 )
#endif
#undef DebugPrint
#if DBG
    #define DebugPrint( x ) ClassDebugPrint x
#else
    #define DebugPrint( x )
#endif

/* Other macros */
#define ASSERT_FDO( x ) \
    ASSERT( ((PCOMMON_DEVICE_EXTENSION)(x)->DeviceExtension)->IsFdo )
#define ASSERT_PDO( x ) \
    ASSERT( !(((PCOMMON_DEVICE_EXTENSION)(x)->DeviceExtension)->IsFdo) )
#define IS_CLEANUP_REQUEST( x ) \
    (((x) == IRP_MJ_CLOSE) || ((x) == IRP_MJ_CLEANUP) || ((x) == IRP_MJ_SHUTDOWN))
#define DO_MCD( x ) \
    (((x)->MediaChangeDetectionInfo != NULL) && \
    ((x)->MediaChangeDetectionInfo->MediaChangeDetectionDisableCount == 0))
#define IS_SCSIOP_READ( x ) \
    (((x) == SCSIOP_READ6) || ((x) == SCSIOP_READ) || ((x) == SCSIOP_READ12) || \
    ((x) == SCSIOP_READ16))
#define IS_SCSIOP_WRITE( x ) \
    (((x) == SCSIOP_WRITE6) || ((x) == SCSIOP_WRITE) || ((x) == SCSIOP_WRITE12) || \
    ((x) == SCSIOP_WRITE16))
#define IS_SCSIOP_READWRITE( x )    (IS_SCSIOP_READ( x ) || IS_SCSIOP_WRITE( x ))
#define ADJUST_FUA_FLAG( x ) \
    { \
        if( TEST_FLAG( x->DeviceFlags, DEV_WRITE_CACHE ) && \
            !TEST_FLAG( x->DeviceFlags, DEV_WRITE_PROTECTED ) && \
            !TEST_FLAG( x->ScanForSpecialFlags, CLASS_SPECIAL_FUA_NOT_SUPPORTED ) ) { \
            x->CdbForceUnitAccess = TRUE; \
        } else { \
            x->CdbForceUnitAccess = FALSE; \
        } \
    }
#define FREE_POOL( x ) \
    if( x != NULL ) { \
        ExFreePool( x ); \
        x = NULL; \
    }

__inline BOOLEAN PORT_ALLOCATED_SENSE( PFUNCTIONAL_DEVICE_EXTENSION p1,
                                       PSCSI_REQUEST_BLOCK p2 )
{
    return( (BOOLEAN)(TEST_FLAG( p2->SrbFlags, SRB_FLAGS_PORT_DRIVER_ALLOCSENSE) &&
        TEST_FLAG( p2->SrbFlags, SRB_FLAGS_FREE_SENSE_BUFFER ) &&
        p2->SenseInfoBuffer != p1->SenseData) );
}

__inline VOID FREE_PORT_ALLOCATED_SENSE_BUFFER( PFUNCTIONAL_DEVICE_EXTENSION p1,
                                                PSCSI_REQUEST_BLOCK p2 )
{
    ASSERT( TEST_FLAG( p2->SrbFlags, SRB_FLAGS_PORT_DRIVER_ALLOCSENSE ) );
    ASSERT( TEST_FLAG( p2->SrbFlags, SRB_FLAGS_FREE_SENSE_BUFFER ) );
    ASSERT( p2->SenseInfoBuffer != p1->SenseData );
    ExFreePool( p2->SenseInfoBuffer );
    p2->SenseInfoBuffer = p1->SenseData;
    p2->SenseInfoBufferLength = SENSE_BUFFER_SIZE;
    CLEAR_FLAG( p2->SrbFlags, SRB_FLAGS_PORT_DRIVER_ALLOCSENSE );
}

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* _CLASS_ */
