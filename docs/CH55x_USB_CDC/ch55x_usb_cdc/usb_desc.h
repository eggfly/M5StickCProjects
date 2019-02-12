#ifndef __USB_DESC_H
#define __USB_DESC_H

#include "ch554_platform.h"

// Note: to make the code more structural and human-readable, ideas have been borrowed from:
// https://github.com/libopencm3/libopencm3-examples/blob/master/examples/stm32/f4/stm32f4-discovery/usb_midi/usbmidi.c#L259
// https://github.com/libopencm3/libopencm3/blob/master/include/libopencm3/usb/usbstd.h

#ifdef __SDCC
	#define USB_UINT8(name, val) .name = val
	// A Helper to set a 16-bit field in USB descriptors, USB int16s are little-endian (Except USB Attached SCSI)
	#define USB_UINT16(name, leVal) .name##L = leVal&0xFF, .name##H = (leVal>>8)&0xFF
#elif defined __C51__
	#define USB_UINT8(name,val) val
	#define USB_UINT16(name, leVal) leVal&0xFF, (leVal>>8)&0xFF
#endif

// USB Descriptors
typedef struct _USB_DEVICE_DESCR usb_device_descriptor;
#define USB_DESCSIZE_DEVICE sizeof(usb_device_descriptor)
typedef struct _USB_CONFIG_DESCR  usb_config_descriptor_header;
#define USB_DESCSIZE_CONFIG sizeof(usb_config_descriptor)

//typedef struct usb_config_descriptor_st {
//	usb_config_descriptor_header header;
//} usb_config_descriptor;


#define USB_INTERFACES 2

// Common USB Descriptors

#define USB_DESCSIZE_CONFIG_H 0
#define USB_DESCSIZE_CONFIG_L 75	// Actual size of your CfgDesc, set according to your configuration
// Device Descriptor
extern code const usb_device_descriptor DevDesc;
//extern code const uint8_t DevDesc[];
// Configuration Descriptor, Interface Descriptors, Endpoint Descriptors and ...
extern code const uint8_t CfgDesc[];
// String Descriptors
#define USB_STRINGDESC_COUNT 4 		// Number of String Descriptors available
extern code const uint8_t* StringDescs[];

#endif /* __USB_DESC_H */
