/*
 *  usbioctl.h  USB device I/O control codes
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

#ifndef __USBIOCTL_H__
#define __USBIOCTL_H__

#ifndef _ENABLE_AUTODEPEND
 #pragma read_only_file
#endif

#include <usb200.h>
#include <usbiodef.h>

#ifdef __cplusplus
extern "C" {
#endif

/* USB device I/O control codes */
#define IOCTL_INTERNAL_USB_SUBMIT_URB \
    CTL_CODE( FILE_DEVICE_USB, USB_SUBMIT_URB, METHOD_NEITHER, FILE_ANY_ACCESS )
#define IOCTL_INTERNAL_USB_RESET_PORT \
    CTL_CODE( FILE_DEVICE_USB, USB_RESET_PORT, METHOD_NEITHER, FILE_ANY_ACCESS )
#define IOCTL_INTERNAL_USB_GET_ROOTHUB_PDO \
    CTL_CODE( FILE_DEVICE_USB, USB_GET_ROOTHUB_PDO, METHOD_NEITHER, FILE_ANY_ACCESS )
#define IOCTL_INTERNAL_USB_GET_PORT_STATUS \
    CTL_CODE( FILE_DEVICE_USB, USB_GET_PORT_STATUS, METHOD_NEITHER, FILE_ANY_ACCESS )
#define IOCTL_INTERNAL_USB_ENABLE_PORT \
    CTL_CODE( FILE_DEVICE_USB, USB_ENABLE_PORT, METHOD_NEITHER, FILE_ANY_ACCESS )
#define IOCTL_INTERNAL_USB_GET_HUB_COUNT \
    CTL_CODE( FILE_DEVICE_USB, USB_GET_HUB_COUNT, METHOD_NEITHER, FILE_ANY_ACCESS )
#define IOCTL_INTERNAL_USB_CYCLE_PORT \
    CTL_CODE( FILE_DEVICE_USB, USB_CYCLE_PORT, METHOD_NEITHER, FILE_ANY_ACCESS )
#define IOCTL_INTERNAL_USB_GET_HUB_NAME \
    CTL_CODE( FILE_DEVICE_USB, USB_GET_HUB_NAME, METHOD_BUFFERED, FILE_ANY_ACCESS )
#define IOCTL_INTERNAL_USB_GET_BUS_INFO \
    CTL_CODE( FILE_DEVICE_USB, USB_GET_BUS_INFO, METHOD_BUFFERED, FILE_ANY_ACCESS )
#define IOCTL_INTERNAL_USB_GET_CONTROLLER_NAME \
    CTL_CODE( FILE_DEVICE_USB, USB_GET_CONTROLLER_NAME, METHOD_BUFFERED, \
    FILE_ANY_ACCESS )
#define IOCTL_INTERNAL_USB_GET_BUSGUID_INFO \
    CTL_CODE( FILE_DEVICE_USB, USB_GET_BUSGUID_INFO, METHOD_BUFFERED, FILE_ANY_ACCESS )
#define IOCTL_INTERNAL_USB_GET_PARENT_HUB_INFO \
    CTL_CODE( FILE_DEVICE_USB, USB_GET_PARENT_HUB_INFO, METHOD_BUFFERED, \
    FILE_ANY_ACCESS )
#if (_WIN32_WINNT >= 0x0501)
    #define IOCTL_INTERNAL_USB_SUBMIT_IDLE_NOTIFICATION \
        CTL_CODE( FILE_DEVICE_USB, USB_IDLE_NOTIFICATION, METHOD_NEITHER, \
        FILE_ANY_ACCESS )
    #define IOCTL_INTERNAL_USB_GET_DEVICE_HANDLE \
        CTL_CODE( FILE_DEVICE_USB, USB_GET_DEVICE_HANDLE, METHOD_NEITHER, \
        FILE_ANY_ACCESS )
#endif
#if (_WIN32_WINNT >= 0x0600)
    #define IOCTL_INTERNAL_USB_NOTIFY_IDLE_READY \
        CTL_CODE( FILE_DEVICE_USB, USB_IDLE_NOTIFICATION_EX, METHOD_NEITHER, \
        FILE_ANY_ACCESS )
    #define IOCTL_INTERNAL_USB_REQ_GLOBAL_SUSPEND \
        CTL_CODE( FILE_DEVICE_USB, USB_REQ_GLOBAL_SUSPEND, METHOD_NEITHER, \
        FILE_ANY_ACCESS )
    #define IOCTL_INTERNAL_USB_REQ_GLOBAL_RESUME \
        CTL_CODE( FILE_DEVICE_USB, USB_REQ_GLOBAL_RESUME, METHOD_NEITHER, \
        FILE_ANY_ACCESS )
    #define IOCTL_INTERNAL_USB_RECORD_FAILURE \
        CTL_CODE( FILE_DEVICE_USB, USB_RECORD_FAILURE, METHOD_NEITHER, \
        FILE_ANY_ACCESS )
    #define IOCTL_INTERNAL_USB_GET_DEVICE_HANDLE_EX \
        CTL_CODE( FILE_DEVICE_USB, USB_GET_DEVICE_HANDLE_EX, METHOD_NEITHER, \
        FILE_ANY_ACCESS )
    #define IOCTL_INTERNAL_USB_GET_TT_DEVICE_HANDLE \
        CTL_CODE( FILE_DEVICE_USB, USB_GET_TT_DEVICE_HANDLE, METHOD_NEITHER, \
        FILE_ANY_ACCESS )
    #define IOCTL_INTERNAL_USB_GET_TOPOLOGY_ADDRESS \
        CTL_CODE( FILE_DEVICE_USB, USB_GET_TOPOLOGY_ADDRESS, METHOD_NEITHER, \
        FILE_ANY_ACCESS )
    #define IOCTL_INTERNAL_USB_GET_DEVICE_CONFIG_INFO \
        CTL_CODE( FILE_DEVICE_USB, USB_GET_HUB_CONFIG_INFO, METHOD_NEITHER, \
        FILE_ANY_ACCESS )
#endif
#if (NTDDI_VERSION >= NTDDI_WIN8)
    #define IOCTL_INTERNAL_USB_REGISTER_COMPOSITE_DEVICE \
        CTL_CODE(FILE_DEVICE_USBEX, USB_REGISTER_COMPOSITE_DEVICE, \
        METHOD_NEITHER, FILE_ANY_ACCESS)
    #define IOCTL_INTERNAL_USB_UNREGISTER_COMPOSITE_DEVICE \
        CTL_CODE(FILE_DEVICE_USBEX, USB_UNREGISTER_COMPOSITE_DEVICE, \
            METHOD_NEITHER, FILE_ANY_ACCESS)
    #define IOCTL_INTERNAL_USB_REQUEST_REMOTE_WAKE_NOTIFICATION \
        CTL_CODE(FILE_DEVICE_USBEX, USB_REQUEST_REMOTE_WAKE_NOTIFICATION, \
        METHOD_NEITHER, FILE_ANY_ACCESS)
#endif
#ifndef USB_KERNEL_IOCTL
    #define IOCTL_USB_HCD_GET_STATS_1 \
        CTL_CODE( FILE_DEVICE_USB, HCD_GET_STATS_1, METHOD_BUFFERED, FILE_ANY_ACCESS )
    #define IOCTL_USB_HCD_GET_STATS_2 \
        CTL_CODE( FILE_DEVICE_USB, HCD_GET_STATS_2, METHOD_BUFFERED, FILE_ANY_ACCESS )
    #define IOCTL_USB_HCD_DISABLE_PORT \
        CTL_CODE( FILE_DEVICE_USB, HCD_DISABLE_PORT, METHOD_BUFFERED, FILE_ANY_ACCESS )
    #define IOCTL_USB_HCD_ENABLE_PORT \
        CTL_CODE( FILE_DEVICE_USB, HCD_ENABLE_PORT, METHOD_BUFFERED, FILE_ANY_ACCESS )
    #ifndef IOCTL_USB_DIAGNOSTIC_MODE_ON
        #define IOCTL_USB_DIAGNOSTIC_MODE_ON \
            CTL_CODE( FILE_DEVICE_USB, HCD_DIAGNOSTIC_MODE_ON, METHOD_BUFFERED, \
            FILE_ANY_ACCESS )
    #endif
    #ifndef IOCTL_USB_DIAGNOSTIC_MODE_OFF
        #define IOCTL_USB_DIAGNOSTIC_MODE_OFF \
            CTL_CODE( FILE_DEVICE_USB, HCD_DIAGNOSTIC_MODE_OFF, METHOD_BUFFERED, \
            FILE_ANY_ACCESS )
    #endif
    #ifndef IOCTL_USB_GET_ROOT_HUB_NAME
        #define IOCTL_USB_GET_ROOT_HUB_NAME \
            CTL_CODE( FILE_DEVICE_USB, HCD_GET_ROOT_HUB_NAME, METHOD_BUFFERED, \
            FILE_ANY_ACCESS )
    #endif
    #ifndef IOCTL_GET_HCD_DRIVERKEY_NAME
        #define IOCTL_GET_HCD_DRIVERKEY_NAME \
            CTL_CODE( FILE_DEVICE_USB, HCD_GET_DRIVERKEY_NAME, METHOD_BUFFERED, \
            FILE_ANY_ACCESS )
    #endif
    #define IOCTL_USB_GET_NODE_INFORMATION \
        CTL_CODE( FILE_DEVICE_USB, USB_GET_NODE_INFORMATION, METHOD_BUFFERED, \
        FILE_ANY_ACCESS )
    #define IOCTL_USB_GET_NODE_CONNECTION_INFORMATION \
        CTL_CODE( FILE_DEVICE_USB, USB_GET_NODE_CONNECTION_INFORMATION, \
        METHOD_BUFFERED, FILE_ANY_ACCESS )
    #define IOCTL_USB_GET_DESCRIPTOR_FROM_NODE_CONNECTION \
        CTL_CODE( FILE_DEVICE_USB, USB_GET_DESCRIPTOR_FROM_NODE_CONNECTION, \
        METHOD_BUFFERED, FILE_ANY_ACCESS )
    #define IOCTL_USB_GET_NODE_CONNECTION_NAME \
        CTL_CODE( FILE_DEVICE_USB, USB_GET_NODE_CONNECTION_NAME, METHOD_BUFFERED, \
        FILE_ANY_ACCESS )
    #define IOCTL_USB_DIAG_IGNORE_HUBS_ON \
        CTL_CODE( FILE_DEVICE_USB, USB_DIAG_IGNORE_HUBS_ON, METHOD_BUFFERED, \
        FILE_ANY_ACCESS )
    #define IOCTL_USB_DIAG_IGNORE_HUBS_OFF \
        CTL_CODE( FILE_DEVICE_USB, USB_DIAG_IGNORE_HUBS_OFF, METHOD_BUFFERED, \
        FILE_ANY_ACCESS )
    #define IOCTL_USB_GET_NODE_CONNECTION_DRIVERKEY_NAME \
        CTL_CODE( FILE_DEVICE_USB, USB_GET_NODE_CONNECTION_DRIVERKEY_NAME, \
        METHOD_BUFFERED, FILE_ANY_ACCESS )
    #if (_WIN32_WINNT >= 0x0501)
        #define IOCTL_USB_GET_HUB_CAPABILITIES \
            CTL_CODE( FILE_DEVICE_USB, USB_GET_HUB_CAPABILITIES, METHOD_BUFFERED, \
            FILE_ANY_ACCESS )
        #define IOCTL_USB_HUB_CYCLE_PORT \
            CTL_CODE( FILE_DEVICE_USB, USB_HUB_CYCLE_PORT, METHOD_BUFFERED, \
            FILE_ANY_ACCESS )
        #define IOCTL_USB_GET_NODE_CONNECTION_ATTRIBUTES \
            CTL_CODE( FILE_DEVICE_USB, USB_GET_NODE_CONNECTION_ATTRIBUTES, \
            METHOD_BUFFERED, FILE_ANY_ACCESS )
        #define IOCTL_USB_GET_NODE_CONNECTION_INFORMATION_EX \
            CTL_CODE( FILE_DEVICE_USB, USB_GET_NODE_CONNECTION_INFORMATION_EX, \
            METHOD_BUFFERED, FILE_ANY_ACCESS )
    #endif
    #if (_WIN32_WINNT >= 0x0600)
        #define IOCTL_USB_RESET_HUB \
            CTL_CODE( FILE_DEVICE_USB, USB_RESET_HUB, METHOD_BUFFERED, FILE_ANY_ACCESS )
        #define IOCTL_USB_GET_HUB_CAPABILITIES_EX \
            CTL_CODE( FILE_DEVICE_USB, USB_GET_HUB_CAPABILITIES_EX, METHOD_BUFFERED, \
            FILE_ANY_ACCESS )
    #endif
    #if (NTDDI_VERSION >= NTDDI_WIN8)
        #define IOCTL_USB_GET_HUB_INFORMATION_EX \
            CTL_CODE(FILE_DEVICE_USB, USB_GET_HUB_INFORMATION_EX, METHOD_BUFFERED, \
            FILE_ANY_ACCESS)

        #define IOCTL_USB_GET_PORT_CONNECTOR_PROPERTIES \
            CTL_CODE(FILE_DEVICE_USB, USB_GET_PORT_CONNECTOR_PROPERTIES, \
            METHOD_BUFFERED, FILE_ANY_ACCESS)

        #define IOCTL_USB_GET_NODE_CONNECTION_INFORMATION_EX_V2 \
            CTL_CODE(FILE_DEVICE_USB, USB_GET_NODE_CONNECTION_INFORMATION_EX_V2, \
            METHOD_BUFFERED, FILE_ANY_ACCESS)
    #endif
#endif

/* USBD port status flags */
#define USBD_PORT_ENABLED   0x00000001L
#define USBD_PORT_CONNECTED 0x00000002L

/* WMI USB GUID indices */
#ifndef USB_KERNEL_IOCTL
    #define WMI_USB_DRIVER_INFORMATION      0
    #define WMI_USB_DRIVER_NOTIFICATION     1
    #define WMI_USB_POWER_DEVICE_ENABLE     2
    #define WMI_USB_HUB_NODE_INFORMATION    4
    #define WMI_USB_PERFORMANCE_INFORMATION 1
    #define WMI_USB_DEVICE_NODE_INFORMATION 2
#endif

/* USB node information signature */
#ifndef USB_KERNEL_IOCTL
    #if (_WIN32_WINNT >= 0x0600)
        #define USB_NODE_INFO_SIG   'USBN'
    #endif
#endif

/* USB start fail data */
#if (_WIN32_WINNT >= 0x0600)
#ifdef USB20_API
typedef struct _USB_START_FAILDATA {
    ULONG       LengthInBytes;
    NTSTATUS    NtStatus;
    USBD_STATUS UsbdStatus;
    ULONG       ConnectStatus;
    UCHAR       DriverData[4];
} USB_START_FAILDATA;
typedef USB_START_FAILDATA  *PUSB_START_FAILDATA;
#endif
#endif

/* USB topology address */
#if (_WIN32_WINNT >= 0x0600)
typedef struct _USB_TOPOLOGY_ADDRESS {
    ULONG   PciBusNumber;
    ULONG   PciDeviceNumber;
    ULONG   PciFunctionNumber;
    ULONG   Reserved;
    USHORT  RootHubPortNumber;
    USHORT  HubPortNumber[5];
    USHORT  Reserved2;
} USB_TOPOLOGY_ADDRESS;
typedef USB_TOPOLOGY_ADDRESS    *PUSB_TOPOLOGY_ADDRESS;
#endif

/* The following structures get one-byte packing. */
#pragma pack( __push, 1 )

/* USB hub nodes */
#ifndef USB_KERNEL_IOCTL
typedef enum _USB_HUB_NODE {
    UsbHub      = 0,
    UsbMIParent = 1
} USB_HUB_NODE;
#endif

/* USB hub information */
#ifndef USB_KERNEL_IOCTL
typedef struct _USB_HUB_INFORMATION {
    USB_HUB_DESCRIPTOR  HubDescriptor;
    BOOLEAN             HubIsBusPowered;
} USB_HUB_INFORMATION;
typedef USB_HUB_INFORMATION *PUSB_HUB_INFORMATION;
#endif

/* USB MI parent information */
#ifndef USB_KERNEL_IOCTL
typedef struct _USB_MI_PARENT_INFORMATION {
    ULONG   NumberOfInterfaces;
} USB_MI_PARENT_INFORMATION;
typedef USB_MI_PARENT_INFORMATION   *PUSB_MI_PARENT_INFORMATION;
#endif

/* USB node information */
#ifndef USB_KERNEL_IOCTL
typedef struct _USB_NODE_INFORMATION {
    USB_HUB_NODE    NodeType;
    union {
        USB_HUB_INFORMATION         HubInformation;
        USB_MI_PARENT_INFORMATION   MiParentInformation;
    } u;
} USB_NODE_INFORMATION;
typedef USB_NODE_INFORMATION    *PUSB_NODE_INFORMATION;
#endif

/* USB pipe information */
#ifndef USB_KERNEL_IOCTL
typedef struct _USB_PIPE_INFO {
    USB_ENDPOINT_DESCRIPTOR EndpointDescriptor;
    ULONG                   ScheduleOffset;
} USB_PIPE_INFO;
typedef USB_PIPE_INFO   *PUSB_PIPE_INFO;
#endif

/* USB connection status values */
#ifndef USB_KERNEL_IOCTL
typedef enum _USB_CONNECTION_STATUS {
    NoDeviceConnected           = 0,
    DeviceConnected             = 1,
    DeviceFailedEnumeration     = 2,
    DeviceGeneralFailure        = 3,
    DeviceCausedOvercurrent     = 4,
    DeviceNotEnoughPower        = 5,
#if (_WIN32_WINNT >= 0x0501)
    DeviceNotEnoughBandwidth    = 6,
    DeviceHubNestedTooDeeply    = 7,
#if (_WIN32_WINNT >= 0x0600)
    DeviceInLegacyHub           = 8,
    DeviceEnumerating           = 9,
    DeviceReset                 = 10
#else
    DeviceInLegacyHub           = 8
#endif
#else
    DeviceNotEnoughBandwidth    = 6
#endif
} USB_CONNECTION_STATUS;
typedef USB_CONNECTION_STATUS   *PUSB_CONNECTION_STATUS;
#endif

/* USB node connection information */
#ifndef USB_KERNEL_IOCTL
typedef struct _USB_NODE_CONNECTION_INFORMATION {
    ULONG                   ConnectionIndex;
    USB_DEVICE_DESCRIPTOR   DeviceDescriptor;
    UCHAR                   CurrentConfigurationValue;
    BOOLEAN                 LowSpeed;
    BOOLEAN                 DeviceIsHub;
    USHORT                  DeviceAddress;
    ULONG                   NumberOfOpenPipes;
    USB_CONNECTION_STATUS   ConnectionStatus;
    USB_PIPE_INFO           PipeList[1];
} USB_NODE_CONNECTION_INFORMATION;
typedef USB_NODE_CONNECTION_INFORMATION *PUSB_NODE_CONNECTION_INFORMATION;
#endif

/* USB node connection driver key name */
#ifndef USB_KERNEL_IOCTL
typedef struct _USB_NODE_CONNECTION_DRIVERKEY_NAME {
    ULONG   ConnectionIndex;
    ULONG   ActualLength;
    WCHAR   DriverKeyName[1];
} USB_NODE_CONNECTION_DRIVERKEY_NAME;
typedef USB_NODE_CONNECTION_DRIVERKEY_NAME  *PUSB_NODE_CONNECTION_DRIVERKEY_NAME;
#endif

/* USB node connection name */
#ifndef USB_KERNEL_IOCTL
typedef struct _USB_NODE_CONNECTION_NAME {
    ULONG   ConnectionIndex;
    ULONG   ActualLength;
    WCHAR   NodeName[1];
} USB_NODE_CONNECTION_NAME;
typedef USB_NODE_CONNECTION_NAME    *PUSB_NODE_CONNECTION_NAME;
#endif

/* USB hub name */
#ifndef USB_KERNEL_IOCTL
typedef struct _USB_HUB_NAME {
    ULONG   ActualLength;
    WCHAR   HubName[1];
} USB_HUB_NAME;
typedef USB_HUB_NAME    *PUSB_HUB_NAME;
#endif

/* USB root hub name */
#ifndef USB_KERNEL_IOCTL
typedef struct _USB_ROOT_HUB_NAME {
    ULONG   ActualLength;
    WCHAR   RootHubName[1];
} USB_ROOT_HUB_NAME;
typedef USB_ROOT_HUB_NAME   *PUSB_ROOT_HUB_NAME;
#endif

/* USB HCD driver key name */
#ifndef USB_KERNEL_IOCTL
typedef struct _USB_HCD_DRIVERKEY_NAME {
    ULONG   ActualLength;
    WCHAR   DriverKeyName[1];
} USB_HCD_DRIVERKEY_NAME;
typedef USB_HCD_DRIVERKEY_NAME  *PUSB_HCD_DRIVERKEY_NAME;
#endif

/* USB descriptor request */
#ifndef USB_KERNEL_IOCTL
typedef struct _USB_DESCRIPTOR_REQUEST {
    ULONG   ConnectionIndex;
    struct {
        UCHAR   bmRequest;
        UCHAR   bRequest;
        USHORT  wValue;
        USHORT  wIndex;
        USHORT  wLength;
    } SetupPacket;
    UCHAR   Data[1];
} USB_DESCRIPTOR_REQUEST;
typedef USB_DESCRIPTOR_REQUEST  *PUSB_DESCRIPTOR_REQUEST;
#endif

/* USB hub capabilities */
#ifndef USB_KERNEL_IOCTL
#if (_WIN32_WINNT >= 0x0501)
typedef struct _USB_HUB_CAPABILITIES {
    ULONG   HubIs2xCapable  : 1;
} USB_HUB_CAPABILITIES;
typedef USB_HUB_CAPABILITIES    *PUSB_HUB_CAPABILITIES;
#endif
#endif

/* USB node connection attributes */
#ifndef USB_KERNEL_IOCTL
#if (_WIN32_WINNT >= 0x0501)
typedef struct _USB_NODE_CONNECTION_ATTRIBUTES {
    ULONG                   ConnectionIndex;
    USB_CONNECTION_STATUS   ConnectionStatus;
    ULONG                   PortAttributes;
} USB_NODE_CONNECTION_ATTRIBUTES;
typedef USB_NODE_CONNECTION_ATTRIBUTES  *PUSB_NODE_CONNECTION_ATTRIBUTES;
#endif
#endif

/* USB node connection information (extended version) */
#ifndef USB_KERNEL_IOCTL
#if (_WIN32_WINNT >= 0x0501)
typedef struct _USB_NODE_CONNECTION_INFORMATION_EX {
    ULONG                   ConnectionIndex;
    USB_DEVICE_DESCRIPTOR   DeviceDescriptor;
    UCHAR                   CurrentConfigurationValue;
    UCHAR                   Speed;
    BOOLEAN                 DeviceIsHub;
    USHORT                  DeviceAddress;
    ULONG                   NumberOfOpenPipes;
    USB_CONNECTION_STATUS   ConnectionStatus;
    USB_PIPE_INFO           PipeList[1];
} USB_NODE_CONNECTION_INFORMATION_EX;
typedef USB_NODE_CONNECTION_INFORMATION_EX  *PUSB_NODE_CONNECTION_INFORMATION_EX;
#endif
#endif

/* USB hub capability flags */
#ifndef USB_KERNEL_IOCTL
#if (_WIN32_WINNT >= 0x0600)
typedef union _USB_HUB_CAP_FLAGS {
    ULONG   ul;
    struct {
        ULONG   HubIsHighSpeedCapable   : 1;
        ULONG   HubIsHighSpeed          : 1;
        ULONG   HubIsMultiTtCapable     : 1;
        ULONG   HubIsMultiTt            : 1;
        ULONG   HubIsRoot               : 1;
        ULONG   HubIsArmedWakeOnConnect : 1;
        ULONG   HubIsBusPowered         : 1;
        ULONG   ReservedMBZ             : 25;
    };
} USB_HUB_CAP_FLAGS;
typedef USB_HUB_CAP_FLAGS   *PUSB_HUB_CAP_FLAGS;
#endif
#endif

/* USB hub capabilities (extended version) */
#ifndef USB_KERNEL_IOCTL
#if (_WIN32_WINNT >= 0x0600)
typedef struct _USB_HUB_CAPABILITIES_EX {
    USB_HUB_CAP_FLAGS   CapabilityFlags;
} USB_HUB_CAPABILITIES_EX;
typedef USB_HUB_CAPABILITIES_EX *PUSB_HUB_CAPABILITIES_EX;
#endif
#endif

/* USB cycle port parameters */
#ifndef USB_KERNEL_IOCTL
#if (_WIN32_WINNT >= 0x0600)
typedef struct _USB_CYCLE_PORT_PARAMS {
    ULONG   ConnectionIndex;
    ULONG   StatusReturned;
} USB_CYCLE_PORT_PARAMS;
typedef USB_CYCLE_PORT_PARAMS   *PUSB_CYCLE_PORT_PARAMS;
#endif
#endif

/* USB identifier string */
#ifndef USB_KERNEL_IOCTL
#if (_WIN32_WINNT >= 0x0600)
typedef struct _USB_ID_STRING {
    USHORT  LanguageId;
    USHORT  Pad;
    ULONG   LengthInBytes;
    PWCHAR  Buffer;
} USB_ID_STRING;
typedef USB_ID_STRING   *PUSB_ID_STRING;
#endif
#endif

/* USB hub device UXD settings */
#ifndef USB_KERNEL_IOCTL
#if (_WIN32_WINNT >= 0x0600)
typedef struct _USB_HUB_DEVICE_UXD_SETTINGS {
    ULONG   Version;
    GUID    PnpGuid;
    GUID    OwnerGuid;
    ULONG   DeleteOnShutdown;
    ULONG   DeleteOnReload;
    ULONG   DeleteOnDisconnect;
    ULONG   Reserved[5];
} USB_HUB_DEVICE_UXD_SETTINGS;
typedef USB_HUB_DEVICE_UXD_SETTINGS *PUSB_HUB_DEVICE_UXD_SETTINGS;
#endif
#endif

/* Hub device configuration information (version 1) */
#ifndef USB_KERNEL_IOCTL
#if (_WIN32_WINNT >= 0x0600)
typedef struct _HUB_DEVICE_CONFIG_INFO_V1 {
    ULONG                       Version;
    ULONG                       Length;
    USB_HUB_CAP_FLAGS           HubFlags;
    USB_ID_STRING               HardwareIds;
    USB_ID_STRING               CompatibleIds;
    USB_ID_STRING               DeviceDescription;
    ULONG                       Reserved[19];
    USB_HUB_DEVICE_UXD_SETTINGS UxdSettings;
} HUB_DEVICE_CONFIG_INFO;
typedef HUB_DEVICE_CONFIG_INFO  *PHUB_DEVICE_CONFIG_INFO;
#endif
#endif

/* HCD statistics counters */
#ifndef USB_KERNEL_IOCTL
typedef struct _HCD_STAT_COUNTERS {
    ULONG   BytesTransferred;
    USHORT  IsoMissedCount;
    USHORT  DataOverrunErrorCount;
    USHORT  CrcErrorCount;
    USHORT  ScheduleOverrunCount;
    USHORT  TimeoutErrorCount;
    USHORT  InternalHcErrorCount;
    USHORT  BufferOverrunErrorCount;
    USHORT  SWErrorCount;
    USHORT  StallPidCount;
    USHORT  PortDisableCount;
} HCD_STAT_COUNTERS;
typedef HCD_STAT_COUNTERS   *PHCD_STAT_COUNTERS;
#endif

/* HCD ISO statistics counters */
#ifndef USB_KERNEL_IOCTL
typedef struct _HCD_ISO_STAT_COUNTERS {
    USHORT  LateUrbs;
    USHORT  DoubleBufferedPackets;
    USHORT  TransfersCF_5ms;
    USHORT  TransfersCF_2ms;
    USHORT  TransfersCF_1ms;
    USHORT  MaxInterruptLatency;
    USHORT  BadStartFrame;
    USHORT  StaleUrbs;
    USHORT  IsoPacketNotAccessed;
    USHORT  IsoPacketHWError;
    USHORT  SmallestUrbPacketCount;
    USHORT  LargestUrbPacketCount;
    USHORT  IsoCRC_Error;
    USHORT  IsoOVERRUN_Error;
    USHORT  IsoINTERNAL_Error;
    USHORT  IsoUNKNOWN_Error;
    ULONG   IsoBytesTransferred;
    USHORT  LateMissedCount;
    USHORT  HWIsoMissedCount;
    ULONG   Reserved7[8];
} HCD_ISO_STAT_COUNTERS;
typedef HCD_ISO_STAT_COUNTERS   *PHCD_ISO_STAT_COUNTERS;
#endif

/* HCD statistics information (version 1) */
#ifndef USB_KERNEL_IOCTL
typedef struct _HCD_STAT_INFORMATION_1 {
    ULONG               Reserved1;
    ULONG               Reserved2;
    ULONG               ResetCounters;
    LARGE_INTEGER       TimeRead;
    HCD_STAT_COUNTERS   Counters;
} HCD_STAT_INFORMATION_1;
typedef HCD_STAT_INFORMATION_1  *PHCD_STAT_INFORMATION_1;
#endif

/* HCD statistics information (version 2) */
#ifndef USB_KERNEL_IOCTL
typedef struct _HCD_STAT_INFORMATION_2 {
    ULONG                   Reserved1;
    ULONG                   Reserved2;
    ULONG                   ResetCounters;
    LARGE_INTEGER           TimeRead;
    LONG                    LockedMemoryUsed;
    HCD_STAT_COUNTERS       Counters;
    HCD_ISO_STAT_COUNTERS   IsoCounters;
} HCD_STAT_INFORMATION_2;
typedef HCD_STAT_INFORMATION_2  *PHCD_STAT_INFORMATION_2;
#endif

/* USB notification types */
#ifndef USB_KERNEL_IOCTL
typedef enum _USB_NOTIFICATION_TYPE {
    EnumerationFailure      = 0,
    InsufficientBandwidth   = 1,
    InsufficientPower       = 2,
    OverCurrent             = 3,
    ResetOvercurrent        = 4,
    AcquireBusInfo          = 5,
    AcquireHubName          = 6,
    AcquireControllerName   = 7,
    HubOvercurrent          = 8,
#if (_WIN32_WINNT >= 0x0501)
    HubPowerChange          = 9,
    HubNestedTooDeeply      = 10,
    ModernDeviceInLegacyHub = 11
#else
    HubPowerChange          = 9
#endif
} USB_NOTIFICATION_TYPE;
#endif

/* USB notification */
#ifndef USB_KERNEL_IOCTL
typedef struct _USB_NOTIFICATION {
    USB_NOTIFICATION_TYPE   NotificationType;
} USB_NOTIFICATION;
typedef USB_NOTIFICATION    *PUSB_NOTIFICATION;
#endif

/* USB connection notification */
#ifndef USB_KERNEL_IOCTL
typedef struct _USB_CONNECTION_INFORMATION {
    USB_NOTIFICATION_TYPE   NotificationType;
    ULONG                   ConnectionNumber;
    ULONG                   RequestedBandwidth;
    ULONG                   EnumerationFailReason;
    ULONG                   PowerRequested;
    ULONG                   HubNameLength;
} USB_CONNECTION_INFORMATION;
typedef USB_CONNECTION_INFORMATION  *PUSB_CONNECTION_INFORMATION;
#endif

/* USB bus notification */
#ifndef USB_KERNEL_IOCTL
typedef struct _USB_BUS_NOTIFICATION {
    USB_NOTIFICATION_TYPE   NotificationType;
    ULONG                   TotalBandwidth;
    ULONG                   ConsumedBandwidth;
    ULONG                   ControllerNameLength;
} USB_BUS_NOTIFICATION;
typedef USB_BUS_NOTIFICATION    *PUSB_BUS_NOTIFICATION;
#endif

/* USB acquire information */
#ifndef USB_KERNEL_IOCTL
typedef struct _USB_ACQUIRE_INFO {
    USB_NOTIFICATION_TYPE   NotificationType;
    ULONG                   TotalSize;
    WCHAR                   Buffer[1];
} USB_ACQUIRE_INFO;
typedef USB_ACQUIRE_INFO    *PUSB_ACQUIRE_INFO;
#endif

/* USB WMI device node types */
#ifndef USB_KERNEL_IOCTL
#if (_WIN32_WINNT >= 0x0600)
typedef enum _USB_WMI_DEVICE_NODE_TYPE {
    UsbDevice       = 0,
    HubDevice       = 1,
    CompositeDevice = 2,
    UsbController   = 3
} USB_WMI_DEVICE_NODE_TYPE;
typedef USB_WMI_DEVICE_NODE_TYPE    *PUSB_WMI_DEVICE_NODE_TYPE;
#endif
#endif

/* USB device state */
#ifndef USB_KERNEL_IOCTL
#if (_WIN32_WINNT >= 0x0600)
typedef struct _USB_DEVICE_STATE {
    ULONG   DeviceConnected : 1;
    ULONG   DeviceStarted   : 1;
} USB_DEVICE_STATE;
typedef USB_DEVICE_STATE    *PUSB_DEVICE_STATE;
#endif
#endif

/* USB hub port information */
#ifndef USB_KERNEL_IOCTL
#if (_WIN32_WINNT >= 0x0600)
typedef struct _USB_HUB_PORT_INFORMATION {
    USB_DEVICE_STATE        DeviceState;
    USHORT                  PortNumber;
    USHORT                  DeviceAddress;
    ULONG                   ConnectionIndex;
    USB_CONNECTION_STATUS   ConnectionStatus;
} USB_HUB_PORT_INFORMATION;
typedef USB_HUB_PORT_INFORMATION    *PUSB_HUB_PORT_INFORMATION;
#endif
#endif

/* USB hub device information */
#ifndef USB_KERNEL_IOCTL
#if (_WIN32_WINNT >= 0x0600)
typedef struct _USB_HUB_DEVICE_INFO {
    USB_HUB_DESCRIPTOR          HubDescriptor;
    ULONG                       HubNumber;
    USHORT                      DeviceAddress;
    BOOLEAN                     HubIsSelfPowered;
    BOOLEAN                     HubIsRootHub;
    USB_HUB_CAPABILITIES        HubCapabilities;
    ULONG                       NumberOfHubPorts;
    USB_HUB_PORT_INFORMATION    PortInfo[1];
} USB_HUB_DEVICE_INFO;
typedef USB_HUB_DEVICE_INFO *PUSB_HUB_DEVICE_INFO;
#endif
#endif

/* USB composite function information */
#ifndef USB_KERNEL_IOCTL
#if (_WIN32_WINNT >= 0x0600)
typedef struct _USB_COMPOSITE_FUNCTION_INFO {
    UCHAR   FunctionNumber;
    UCHAR   BaseInterfaceNumber;
    UCHAR   NumberOfInterfaces;
    BOOLEAN FunctionIsIdle;
} USB_COMPOSITE_FUNCTION_INFO;
typedef USB_COMPOSITE_FUNCTION_INFO *PUSB_COMPOSITE_FUNCTION_INFO;
#endif
#endif

/* USB composite device information */
#ifndef USB_KERNEL_IOCTL
#if (_WIN32_WINNT >= 0x0600)
typedef struct _USB_COMPOSITE_DEVICE_INFO {
    USB_DEVICE_DESCRIPTOR           DeviceDescriptor;
    USB_CONFIGURATION_DESCRIPTOR    CurrentConfigDescriptor;
    UCHAR                           CurrentConfigurationValue;
    UCHAR                           NumberOfFunctions;
    USB_COMPOSITE_FUNCTION_INFO     FunctionInfo[1];
} USB_COMPOSITE_DEVICE_INFO;
typedef USB_COMPOSITE_DEVICE_INFO   *PUSB_COMPOSITE_DEVICE_INFO;
#endif
#endif

/* USB controller device information */
#ifndef USB_KERNEL_IOCTL
#if (_WIN32_WINNT >= 0x0600)
typedef struct _USB_CONTROLLER_DEVICE_INFO {
    ULONG   PciVendorId;
    ULONG   PciDeviceId;
    ULONG   PciRevision;
    ULONG   NumberOfRootPorts;
    ULONG   HcFeatureFlags;
} USB_CONTROLLER_DEVICE_INFO;
typedef USB_CONTROLLER_DEVICE_INFO  *PUSB_CONTROLLER_DEVICE_INFO;
#endif
#endif

/* USB device information */
#ifndef USB_KERNEL_IOCTL
#if (_WIN32_WINNT >= 0x0600)
typedef struct _USB_DEVICE_INFO {
    USB_DEVICE_STATE        DeviceState;
    USHORT                  PortNumber;
    USB_DEVICE_DESCRIPTOR   DeviceDescriptor;
    UCHAR                   CurrentConfigurationValue;
    USB_DEVICE_SPEED        Speed;
    USHORT                  DeviceAddress;
    ULONG                   ConnectionIndex;
    USB_CONNECTION_STATUS   ConnectionStatus;
    WCHAR                   PnpHardwareId[128];
    WCHAR                   PnpCompatibleId[128];
    WCHAR                   SerialNumberId[128];
    WCHAR                   PnpDeviceDescription[128];
    ULONG                   NumberOfOpenPipes;
    USB_PIPE_INFO           PipeList[1];
} USB_DEVICE_INFO;
typedef USB_DEVICE_INFO *PUSB_DEVICE_INFO;
#endif
#endif

/* USB device node information */
#ifndef USB_KERNEL_IOCTL
#if (_WIN32_WINNT >= 0x0600)
typedef struct _USB_DEVICE_NODE_INFO {
    ULONG                       Sig;
    ULONG                       LengthInBytes;
    WCHAR                       DeviceDescription[40];
    USB_WMI_DEVICE_NODE_TYPE    NodeType;
    USB_TOPOLOGY_ADDRESS        BusAddress;
    union {
        USB_DEVICE_INFO             UsbDeviceInfo;
        USB_HUB_DEVICE_INFO         HubDeviceInfo;
        USB_COMPOSITE_DEVICE_INFO   CompositeDeviceInfo;
        USB_CONTROLLER_DEVICE_INFO  ControllerDeviceInfo;
        UCHAR                       DeviceInformation[4];
    };
} USB_DEVICE_NODE_INFO;
typedef USB_DEVICE_NODE_INFO    *PUSB_DEVICE_NODE_INFO;
#endif
#endif

/* USB device performance information */
#ifndef USB_KERNEL_IOCTL
#if (_WIN32_WINNT >= 0x0600)
typedef struct _USB_DEVICE_PERFORMANCE_INFO {
    ULONG               BulkBytes;
    ULONG               ControlDataBytes;
    ULONG               IsoBytes;
    ULONG               InterruptBytes;
    ULONG               BulkUrbCount;
    ULONG               ControlUrbCount;
    ULONG               IsoUrbCount;
    ULONG               InterruptUrbCount;
    ULONG               AllocedInterrupt[6];
    ULONG               AllocedIso;
    ULONG               Total32secBandwidth;
    ULONG               TotalTtBandwidth;
    WCHAR               DeviceDescription[60];
    USB_DEVICE_SPEED    DeviceSpeed;
    ULONG               TotalIsoLatency;
    ULONG               DroppedIsoPackets;
    ULONG               TransferErrors;
    ULONG               PciInterruptCount;
    ULONG               HcIdleState;
    ULONG               HcAsyncIdleState;
    ULONG               HcAsyncCacheFlushCount;
    ULONG               HcPeriodicIdleState;
    ULONG               HcPeriodicCacheFlushCount;
} USB_DEVICE_PERFORMANCE_INFO;
typedef USB_DEVICE_PERFORMANCE_INFO *PUSB_DEVICE_PERFORMANCE_INFO;
#endif

#if (NTDDI_VERSION >= NTDDI_WIN8)
typedef enum _USB_HUB_TYPE {
    UsbRootHub = 1,
    Usb20Hub   = 2,
    Usb30Hub   = 3
} USB_HUB_TYPE;

typedef struct _USB_HUB_INFORMATION_EX {
    USB_HUB_TYPE        HubType;
    USHORT              HighestPortNumber;
    union {
        USB_HUB_DESCRIPTOR      UsbHubDescriptor;
        USB_30_HUB_DESCRIPTOR   Usb30HubDescriptor;
    } u;
} USB_HUB_INFORMATION_EX, *PUSB_HUB_INFORMATION_EX;

typedef union _USB_PORT_PROPERTIES {
    ULONG  ul;
    struct {
        ULONG PortIsUserConnectable     : 1;
        ULONG PortIsDebugCapable        : 1;
        ULONG PortHasMultipleCompanions : 1;
        ULONG PortConnectorIsTypeC      : 1;
        ULONG ReservedMBZ               : 28;
    };
} USB_PORT_PROPERTIES,  *PUSB_PORT_PROPERTIES;

typedef struct _USB_PORT_CONNECTOR_PROPERTIES {
    ULONG               ConnectionIndex;
    ULONG               ActualLength;
    USB_PORT_PROPERTIES UsbPortProperties;
    USHORT              CompanionIndex;
    USHORT              CompanionPortNumber;
    WCHAR               CompanionHubSymbolicLinkName[1];
} USB_PORT_CONNECTOR_PROPERTIES,    *PUSB_PORT_CONNECTOR_PROPERTIES;

typedef union _USB_PROTOCOLS {
    ULONG  ul;
    struct {
        ULONG Usb110        : 1;
        ULONG Usb200        : 1;
        ULONG Usb300        : 1;
        ULONG ReservedMBZ   : 29;
    };
} USB_PROTOCOLS,    *PUSB_PROTOCOLS;

typedef union _USB_NODE_CONNECTION_INFORMATION_EX_V2_FLAGS {
    ULONG  ul;
    struct {
        ULONG DeviceIsOperatingAtSuperSpeedOrHigher     : 1;
        ULONG DeviceIsSuperSpeedCapableOrHigher         : 1;
        ULONG DeviceIsOperatingAtSuperSpeedPlusOrHigher : 1;
        ULONG DeviceIsSuperSpeedPlusCapableOrHigher     : 1;
        ULONG ReservedMBZ                               : 28;
    };
} USB_NODE_CONNECTION_INFORMATION_EX_V2_FLAGS,  *PUSB_NODE_CONNECTION_INFORMATION_EX_V2_FLAGS;

typedef struct _USB_NODE_CONNECTION_INFORMATION_EX_V2 {
    ULONG           ConnectionIndex;
    ULONG           Length;
    USB_PROTOCOLS   SupportedUsbProtocols;
    USB_NODE_CONNECTION_INFORMATION_EX_V2_FLAGS Flags;
} USB_NODE_CONNECTION_INFORMATION_EX_V2,    *PUSB_NODE_CONNECTION_INFORMATION_EX_V2;
#endif
#endif

/* Revert to default packing. */
#pragma pack( __pop )

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* __USBIOCTL_H__ */
