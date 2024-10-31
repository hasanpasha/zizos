/*
 *  minitape.h  Minitape definitions
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

#ifndef _MINITAPE_
#define _MINITAPE_

#ifndef _ENABLE_AUTODEPEND
 #pragma read_only_file
#endif

/* The Microsoft version of minitape.h is mostly a lot of the same stuff that's in
 * other headers.  To save space, include those headers and just define those constants
 * and structures that are unique to this header.
 */
#include <ntddk.h>
#include <ntddtape.h>
#include <ntddstor.h>
#include <srb.h>
#include <scsi.h>
#include <wmidata.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Tape retry flags */
#define TAPE_RETRY_MASK 0x0000FFFFL
#define IGNORE_ERRORS   0x00010000L
#define RETURN_ERRORS   0x00020000L

/* QIC tape density codes */
#define QIC_XX      0
#define QIC_24      5
#define QIC_120     15
#define QIC_150     16
#define QIC_525     17
#define QIC_1350    18
#define QIC_1000    21
#define QIC_1000C   30
#define QIC_2100    31
#define QIC_2GB     34
#define QIC_5GB     40

/* QIC tape media codes */
#define DCXXXX      0
#define DC300       1
#define DC300XLP    2
#define DC615       3
#define DC600       4
#define DC6037      5
#define DC6150      6
#define DC6250      7
#define DC6320      8
#define DC6525      9
#define DC9135SL    33
#define DC9210      34
#define DC9135      35
#define DC9100      36
#define DC9120      37
#define DC9120SL    38
#define DC9164      39
#define DCXXXXFW    48
#define DC9200SL    49
#define DC9210XL    50
#define DC10GB      51
#define DC9200      52
#define DC9120XL    53
#define DC9210SL    54
#define DC9164XL    55
#define DC9200XL    64
#define DC9400      65
#define DC9500      66
#define DC9500SL    70

/* Translation reference points */
#define NOT_FROM_BOT    0
#define FROM_BOT        1

/* Tape alert log page */
#define TapeAlertLogPage    0x2E

/* Tape alert types */
#define READ_WARNING            1
#define WRITE_WARNING           2
#define HARD_ERROR              3
#define MEDIA_ERROR             4
#define READ_FAILURE            5
#define WRITE_FAILURE           6
#define MEDIA_LIFE              7
#define NOT_DATA_GRADE          8
#define WRITE_PROTECT           9
#define NO_REMOVAL              10
#define CLEANING_MEDIA          11
#define UNSUPPORTED_FORMAT      12
#define SNAPPED_TAPE            13
#define CLEAN_NOW               20
#define CLEAN_PERIODIC          21
#define EXPIRED_CLEANING_MEDIA  22
#define HARDWARE_A              30
#define HARDWARE_B              31
#define INTERFACE_ERROR         32
#define EJECT_MEDIA             33
#define DOWNLOAD_FAIL           34

/* Mode device configuration pages */
typedef struct _MODE_DEVICE_CONFIGURATION_PAGE {
    UCHAR   PageCode        : 6;
    UCHAR   Reserved1       : 1;
    UCHAR   PS              : 1;
    UCHAR   PageLength;
    UCHAR   ActiveFormat    : 5;
    UCHAR   CAFBit          : 1;
    UCHAR   CAPBit          : 1;
    UCHAR   Reserved2       : 1;
    UCHAR   ActivePartition;
    UCHAR   WriteBufferFullRatio;
    UCHAR   ReadBufferEmptyRatio;
    UCHAR   WriteDelayTime[2];
    UCHAR   REW             : 1;
    UCHAR   RBO             : 1;
    UCHAR   SOCF            : 2;
    UCHAR   AVC             : 1;
    UCHAR   RSmk            : 1;
    UCHAR   BIS             : 1;
    UCHAR   DBR             : 1;
    UCHAR   GapSize;
    UCHAR   Reserved3       : 3;
    UCHAR   SEW             : 1;
    UCHAR   EEG             : 1;
    UCHAR   EODefined       : 3;
    UCHAR   BufferSize[3];
    UCHAR   DCAlgorithm;
    UCHAR   Reserved4;
} MODE_DEVICE_CONFIGURATION_PAGE;
typedef MODE_DEVICE_CONFIGURATION_PAGE  *PMODE_DEVICE_CONFIGURATION_PAGE;

/* Mode medium partition page */
typedef struct _MODE_MEDIUM_PARTITION_PAGE {
    UCHAR   PageCode    : 6;
    UCHAR   Reserved1   : 1;
    UCHAR   PSBit       : 1;
    UCHAR   PageLength;
    UCHAR   MaximumAdditionalPartitions;
    UCHAR   AdditionalPartitionDefined;
    UCHAR   Reserved2   : 3;
    UCHAR   PSUMBit     : 2;
    UCHAR   IDPBit      : 1;
    UCHAR   SDPBit      : 1;
    UCHAR   FDPBit      : 1;
    UCHAR   MediumFormatRecognition;
    UCHAR   Reserved3[2];
    UCHAR   Partition0Size[2];
    UCHAR   Partition1Size[2];
} MODE_MEDIUM_PARTITION_PAGE;
typedef MODE_MEDIUM_PARTITION_PAGE  *PMODE_MEDIUM_PARTITION_PAGE;

/* Mode data compression page */
typedef struct _MODE_DATA_COMPRESSION_PAGE {
    UCHAR   PageCode    : 6;
    UCHAR   Reserved1   : 2;
    UCHAR   PageLength;
    UCHAR   Reserved2   : 6;
    UCHAR   DCC         : 1;
    UCHAR   DCE         : 1;
    UCHAR   Reserved3   : 5;
    UCHAR   RED         : 2;
    UCHAR   DDE         : 1;
    UCHAR   CompressionAlgorithm[4];
    UCHAR   DecompressionAlgorithm[4];
    UCHAR   Reserved4[4];
} MODE_DATA_COMPRESSION_PAGE;
typedef MODE_DATA_COMPRESSION_PAGE  *PMODE_DATA_COMPRESSION_PAGE;

/* Mode capabilities page */
typedef struct _MODE_CAPABILITIES_PAGE {
    UCHAR   PageCode    : 6;
    UCHAR   Reserved1   : 2;
    UCHAR   PageLength;
    UCHAR   Reserved2[2];
    UCHAR   RO          : 1;
    UCHAR   Reserved3   : 4;
    UCHAR   SPREV       : 1;
    UCHAR   Reserved4   : 2;
    UCHAR   Reserved5   : 3;
    UCHAR   EFMT        : 1;
    UCHAR   Reserved6   : 1;
    UCHAR   QFA         : 1;
    UCHAR   Reserved7   : 2;
    UCHAR   LOCK        : 1;
    UCHAR   LOCKED      : 1;
    UCHAR   PREVENT     : 1;
    UCHAR   UNLOAD      : 1;
    UCHAR   Reserved8   : 2;
    UCHAR   ECC         : 1;
    UCHAR   CMPRS       : 1;
    UCHAR   Reserved9   : 1;
    UCHAR   BLK512      : 1;
    UCHAR   BLK1024     : 1;
    UCHAR   Reserved10  : 4;
    UCHAR   SLOWB       : 1;
    UCHAR   MaximumSpeedSupported[2];
    UCHAR   MaximumStoredDefectedListEntries[2];
    UCHAR   ContinuousTransferLimit[2];
    UCHAR   CurrentSpeedSelected[2];
    UCHAR   BufferSize[2];
    UCHAR   Reserved11[2];
} MODE_CAPABILITIES_PAGE;
typedef MODE_CAPABILITIES_PAGE  *PMODE_CAPABILITIES_PAGE;

/* Mode capabilities page */
typedef struct _MODE_CAP_PAGE {
    MODE_PARAMETER_HEADER   ParameterListHeader;
    MODE_PARAMETER_BLOCK    ParameterListBlock;
    MODE_CAPABILITIES_PAGE  CapabilitiesPage;
} MODE_CAP_PAGE;
typedef MODE_CAP_PAGE   *PMODE_CAP_PAGE;

/* Mode medium partition page */
typedef struct _MODE_MEDIUM_PART_PAGE {
    MODE_PARAMETER_HEADER       ParameterListHeader;
    MODE_MEDIUM_PARTITION_PAGE  MediumPartPage;
} MODE_MEDIUM_PART_PAGE;
typedef MODE_MEDIUM_PART_PAGE   *PMODE_MEDIUM_PART_PAGE;

/* Mode medium partition page plus */
typedef struct _MODE_MEDIUM_PART_PAGE_PLUS {
    MODE_PARAMETER_HEADER       ParameterListHeader;
    MODE_PARAMETER_BLOCK        ParameterListBlock;
    MODE_MEDIUM_PARTITION_PAGE  MediumPartPage;
} MODE_MEDIUM_PART_PAGE_PLUS;
typedef MODE_MEDIUM_PART_PAGE_PLUS  *PMODE_MEDIUM_PART_PAGE_PLUS;

/* Mode tape media information */
typedef struct _MODE_TAPE_MEDIA_INFORMATION {
    MODE_PARAMETER_HEADER       ParameterListHeader;
    MODE_PARAMETER_BLOCK        ParameterListBlock;
    MODE_MEDIUM_PARTITION_PAGE  MediumPartPage;
} MODE_TAPE_MEDIA_INFORMATION;
typedef MODE_TAPE_MEDIA_INFORMATION *PMODE_TAPE_MEDIA_INFORMATION;

/* Mode device configuration page */
typedef struct _MODE_DEVICE_CONFIG_PAGE {
    MODE_PARAMETER_HEADER           ParameterListHeader;
    MODE_DEVICE_CONFIGURATION_PAGE  DeviceConfigPage;
} MODE_DEVICE_CONFIG_PAGE;
typedef MODE_DEVICE_CONFIG_PAGE *PMODE_DEVICE_CONFIG_PAGE;

/* Mode device configuration page plus */
typedef struct _MODE_DEVICE_CONFIG_PAGE_PLUS {
    MODE_PARAMETER_HEADER           ParameterListHeader;
    MODE_PARAMETER_BLOCK            ParameterListBlock;
    MODE_DEVICE_CONFIGURATION_PAGE  DeviceConfigPage;
} MODE_DEVICE_CONFIG_PAGE_PLUS;
typedef MODE_DEVICE_CONFIG_PAGE_PLUS    *PMODE_DEVICE_CONFIG_PAGE_PLUS;

/* Mode data compression page */
typedef struct _MODE_DATA_COMPRESS_PAGE {
    MODE_PARAMETER_HEADER       ParameterListHeader;
    MODE_DATA_COMPRESSION_PAGE  DataCompressPage;
} MODE_DATA_COMPRESS_PAGE;
typedef MODE_DATA_COMPRESS_PAGE *PMODE_DATA_COMPRESS_PAGE;

/* Mode data compress page plus */
typedef struct _MODE_DATA_COMPRESS_PAGE_PLUS {
    MODE_PARAMETER_HEADER       ParameterListHeader;
    MODE_PARAMETER_BLOCK        ParameterListBlock;
    MODE_DATA_COMPRESSION_PAGE  DataCompressPage;
} MODE_DATA_COMPRESS_PAGE_PLUS;
typedef MODE_DATA_COMPRESS_PAGE_PLUS    *PMODE_DATA_COMPRESS_PAGE_PLUS;

/* Tape status values */
typedef enum _TAPE_STATUS {
    TAPE_STATUS_SEND_SRB_AND_CALLBACK       = 0,
    TAPE_STATUS_CALLBACK                    = 1,
    TAPE_STATUS_CHECK_TEST_UNIT_READY       = 2,
    TAPE_STATUS_SUCCESS                     = 3,
    TAPE_STATUS_INSUFFICIENT_RESOURCES      = 4,
    TAPE_STATUS_NOT_IMPLEMENTED             = 5,
    TAPE_STATUS_INVALID_DEVICE_REQUEST      = 6,
    TAPE_STATUS_INVALID_PARAMETER           = 7,
    TAPE_STATUS_MEDIA_CHANGED               = 8,
    TAPE_STATUS_BUS_RESET                   = 9,
    TAPE_STATUS_SETMARK_DETECTED            = 10,
    TAPE_STATUS_FILEMARK_DETECTED           = 11,
    TAPE_STATUS_BEGINNING_OF_MEDIA          = 12,
    TAPE_STATUS_END_OF_MEDIA                = 13,
    TAPE_STATUS_BUFFER_OVERFLOW             = 14,
    TAPE_STATUS_NO_DATA_DETECTED            = 15,
    TAPE_STATUS_EOM_OVERFLOW                = 16,
    TAPE_STATUS_NO_MEDIA                    = 17,
    TAPE_STATUS_IO_DEVICE_ERROR             = 18,
    TAPE_STATUS_UNRECOGNIZED_MEDIA          = 19,
    TAPE_STATUS_DEVICE_NOT_READY            = 20,
    TAPE_STATUS_MEDIA_WRITE_PROTECTED       = 21,
    TAPE_STATUS_DEVICE_DATA_ERROR           = 22,
    TAPE_STATUS_NO_SUCH_DEVICE              = 23,
    TAPE_STATUS_INVALID_BLOCK_LENGTH        = 24,
    TAPE_STATUS_IO_TIMEOUT                  = 25,
    TAPE_STATUS_DEVICE_NOT_CONNECTED        = 26,
    TAPE_STATUS_DATA_OVERRUN                = 27,
    TAPE_STATUS_DEVICE_BUSY                 = 28,
    TAPE_STATUS_REQUIRES_CLEANING           = 29,
    TAPE_STATUS_CLEANER_CARTRIDGE_INSTALLED = 30
} TAPE_STATUS;
typedef TAPE_STATUS *PTAPE_STATUS;

/* Minitape callbacks */
typedef BOOLEAN     (NTAPI *TAPE_VERIFY_INQUIRY_ROUTINE)( PINQUIRYDATA, PMODE_CAPABILITIES_PAGE );
typedef VOID        (NTAPI *TAPE_EXTENSION_INIT_ROUTINE)( PVOID, PINQUIRYDATA, PMODE_CAPABILITIES_PAGE );
typedef VOID        (NTAPI *TAPE_ERROR_ROUTINE)( PVOID, PSCSI_REQUEST_BLOCK, PTAPE_STATUS );
typedef TAPE_STATUS (NTAPI *TAPE_PROCESS_COMMAND_ROUTINE)( PVOID, PVOID, PVOID, PSCSI_REQUEST_BLOCK, ULONG, TAPE_STATUS, PULONG );

/* Tape initialization data */
typedef struct _TAPE_INIT_DATA {
    TAPE_VERIFY_INQUIRY_ROUTINE     VerifyInquiry;
    BOOLEAN                         QueryModeCapabilitiesPage;
    ULONG                           MinitapeExtensionSize;
    TAPE_EXTENSION_INIT_ROUTINE     ExtensionInit;
    ULONG                           DefaultTimeOutValue;
    TAPE_ERROR_ROUTINE              TapeError;
    ULONG                           CommandExtensionSize;
    TAPE_PROCESS_COMMAND_ROUTINE    CreatePartition;
    TAPE_PROCESS_COMMAND_ROUTINE    Erase;
    TAPE_PROCESS_COMMAND_ROUTINE    GetDriveParameters;
    TAPE_PROCESS_COMMAND_ROUTINE    GetMediaParameters;
    TAPE_PROCESS_COMMAND_ROUTINE    GetPosition;
    TAPE_PROCESS_COMMAND_ROUTINE    GetStatus;
    TAPE_PROCESS_COMMAND_ROUTINE    Prepare;
    TAPE_PROCESS_COMMAND_ROUTINE    SetDriveParameters;
    TAPE_PROCESS_COMMAND_ROUTINE    SetMediaParameters;
    TAPE_PROCESS_COMMAND_ROUTINE    SetPosition;
    TAPE_PROCESS_COMMAND_ROUTINE    WriteMarks;
    TAPE_PROCESS_COMMAND_ROUTINE    PreProcessReadWrite;
} TAPE_INIT_DATA;
typedef TAPE_INIT_DATA  *PTAPE_INIT_DATA;

/* Tape initialization data (extended version) */
typedef struct _TAPE_INIT_DATA_EX {
    ULONG                           InitDataSize;
    TAPE_VERIFY_INQUIRY_ROUTINE     VerifyInquiry;
    BOOLEAN                         QueryModeCapabilitiesPage;
    ULONG                           MinitapeExtensionSize;
    TAPE_EXTENSION_INIT_ROUTINE     ExtensionInit;
    ULONG                           DefaultTimeOutValue;
    TAPE_ERROR_ROUTINE              TapeError;
    ULONG                           CommandExtensionSize;
    TAPE_PROCESS_COMMAND_ROUTINE    CreatePartition;
    TAPE_PROCESS_COMMAND_ROUTINE    Erase;
    TAPE_PROCESS_COMMAND_ROUTINE    GetDriveParameters;
    TAPE_PROCESS_COMMAND_ROUTINE    GetMediaParameters;
    TAPE_PROCESS_COMMAND_ROUTINE    GetPosition;
    TAPE_PROCESS_COMMAND_ROUTINE    GetStatus;
    TAPE_PROCESS_COMMAND_ROUTINE    Prepare;
    TAPE_PROCESS_COMMAND_ROUTINE    SetDriveParameters;
    TAPE_PROCESS_COMMAND_ROUTINE    SetMediaParameters;
    TAPE_PROCESS_COMMAND_ROUTINE    SetPosition;
    TAPE_PROCESS_COMMAND_ROUTINE    WriteMarks;
    TAPE_PROCESS_COMMAND_ROUTINE    PreProcessReadWrite;
    TAPE_PROCESS_COMMAND_ROUTINE    TapeGetMediaTypes;
    ULONG                           MediaTypesSupported;
    TAPE_PROCESS_COMMAND_ROUTINE    TapeWMIOperations;
    ULONG                           Reserved[2];
} TAPE_INIT_DATA_EX;
typedef TAPE_INIT_DATA_EX   *PTAPE_INIT_DATA_EX;

/* Tape physical position */
typedef struct _TAPE_PHYS_POSITION {
    ULONG   SeekBlockAddress;
    ULONG   SpaceBlockCount;
} TAPE_PHYS_POSITION;
typedef TAPE_PHYS_POSITION  *PTAPE_PHYS_POSITION;

/* Tape alert information types */
typedef enum _TAPE_ALERT_INFO_TYPE {
    TapeAlertInfoNone           = 0,
    TapeAlertInfoRequestSense   = 1,
    TapeAlertInfoLogPage        = 2
} TAPE_ALERT_INFO_TYPE;

/* Functions in TAPE.SYS */
SCSIPORT_API BOOLEAN    NTAPI TapeClassAllocateSrbBuffer( PSCSI_REQUEST_BLOCK, ULONG );
SCSIPORT_API ULONG      NTAPI TapeClassCompareMemory( PVOID, PVOID, ULONG );
SCSIPORT_API ULONG      NTAPI TapeClassInitialize( PVOID, PVOID, PTAPE_INIT_DATA_EX );
SCSIPORT_API LARGE_INTEGER NTAPI TapeClassLiDiv( LARGE_INTEGER, LARGE_INTEGER );
SCSIPORT_API TAPE_PHYS_POSITION NTAPI TapeClassLogicalBlockToPhysicalBlock( UCHAR, ULONG, ULONG, BOOLEAN );
SCSIPORT_API ULONG      NTAPI TapeClassPhysicalBlockToLogicalBlock( UCHAR, ULONG, ULONG, BOOLEAN );
SCSIPORT_API VOID       NTAPI TapeClassZeroMemory( PVOID, ULONG );
SCSIPORT_API VOID       __cdecl TapeDebugPrint( ULONG, PCCHAR, ... );

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* _MINITAPE_ */
