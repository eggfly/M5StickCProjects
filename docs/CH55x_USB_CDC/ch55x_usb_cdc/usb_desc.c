#include "usb_desc.h"

#include "ch554_platform.h"

// Device Descriptor
code const usb_device_descriptor DevDesc = {
		USB_UINT8(bLength, USB_DESCSIZE_DEVICE),
		USB_UINT8(bDescriptorType, USB_DESCR_TYP_DEVICE),	// Type: Device Descriptor
		USB_UINT16(bcdUSB, 0x0110),				// USB Spec., 0x0110 -> USB 1.1
		USB_UINT8(bDeviceClass, 0),				// Device defined at interface level
		USB_UINT8(bDeviceSubClass, 0),
		USB_UINT8(bDeviceProtocol, 0),
		USB_UINT8(bMaxPacketSize0, 8),			// Max packet size of EP0
		USB_UINT16(idVendor, 0x1A86),			// VID
		USB_UINT16(idProduct, 0x5722),			// PID
		USB_UINT16(bcdDevice, 0x0100),			// Device release number in BCD
		USB_UINT8(iManufacturer, 2),			// Manufactor, index of string descriptor
		USB_UINT8(iProduct, 1),					// Product string descriptor ID
		USB_UINT8(iSerialNumber, 0),			// Serial number (String descriptor ID)
		USB_UINT8(bNumConfigurations, 1),		// Number of available configurations
};

// Configuration Descriptor and Interface Descriptor
code const uint8_t CfgDesc[] =
{
	// Configuration Descriptor
	9,					// Length of the descriptor
	0x02,				// Type: Configuration Descriptor
	// Total length of this and following descriptors
	USB_DESCSIZE_CONFIG_L, USB_DESCSIZE_CONFIG_H,
	USB_INTERFACES,		// Number of interfaces
	0x01, 			// Value used to select this configuration
	0x00,				// Index of corresponding string descriptor
	0x80,				// Attributes, D7 must be 1, D6 Self-powered, D5 Remote Wakeup, D4-D0=0
	0x32,				// Max current drawn by device, in units of 2mA

	// Interface Association Descriptor (CDC)
	8,					// Length of the descriptor
	0x0B,				// Type: Interface Association Descriptor (IAD)
	0x00, 				// First interface: 0 in this case, see following
	0x02, 				// Total number of grouped interfaces
	0x02, 				// bFunctionClass
	0x02, 				// bFunctionSubClass
	0x01, 				// bFunctionProtocol
	0x03, 				// Index of string descriptor describing this function

	// Interface descriptor (CDC)
	9,					// Length of the descriptor
	0x04,				// Type: Interface Descriptor
	0x00,				// Interface ID
	0x00,				// Alternate setting
	0x01,				// Number of Endpoints
	0x02,				// Interface class code - Communication Interface Class
	0x02,				// Subclass code - Abstract Control Model
	0x01,				// Protocol code - AT Command V.250 protocol
	0x00,				// Index of corresponding string descriptor (On Windows, it is called "Bus reported device description")

	// Header Functional descriptor (CDC)
	5,					// Length of the descriptor
	0x24,				// bDescriptortype, CS_INTERFACE
	0x00,				// bDescriptorsubtype, HEADER
	0x10,0x01,			// bcdCDC

	// Call Management Functional Descriptor (CDC)
	5,					// Length of the descriptor
	0x24,				// bDescriptortype, CS_INTERFACE
	0x01,				// bDescriptorsubtype, Call Management Functional Descriptor
	0x00,				// bmCapabilities
	// Bit0: Does not handle call management
	// Bit1: Call Management over Comm Class interface
	0x00,				// Data Interfaces

	// Abstract Control Management (CDC)
	4,					// Length of the descriptor
	0x24,				// bDescriptortype, CS_INTERFACE
	0x02,				// bDescriptorsubtype, Abstract Control Management
	0x02,				// bmCapabilities
	// Bit0: CommFeature
	// Bit1: LineStateCoding  Device supports the request combination of
	// Set_Line_Coding,	Set_Control_Line_State, Get_Line_Coding, and the notification Serial_State.
	// Bit2: SendBreak
	// Bit3: NetworkConnection
	// Ö§³ÖSet_Line_Coding¡¢Set_Control_Line_State¡¢Get_Line_Coding¡¢Serial_State

	// Union Functional Descriptor (CDC)
	5,					// Length of the descriptor
	0x24,				// bDescriptortype, CS_INTERFACE
	0x06,				// bDescriptorSubtype: Union func desc
	0x00,				// bMasterInterface: Communication class interface
	0x01,				// bSlaveInterface0: Data Class Interface

	// EndPoint descriptor (CDC Upload, Interrupt)
	7,					// Length of the descriptor
	0x05,				// Type: Endpoint Descriptor
	0x81,				// Endpoint: D7: 0-Out 1-In, D6-D4=0, D3-D0 Endpoint number
	0x03,				// Attributes:
						// D1:0 Transfer type: 00 = Control 01 = Isochronous 10 = Bulk 11 = Interrupt
						// 			The following only apply to isochronous endpoints. Else set to 0.
						// D3:2 Synchronization Type: 00 = No Synchronization 01 = Asynchronous 10 = Adaptive 11 = Synchronous
						// D5:4	Usage Type: 00 = Data endpoint 01 = Feedback endpoint 10 = Implicit feedback Data endpoint 11 = Reserved
						// D7:6 = 0
	0x10, 0x00,			// Maximum packet size can be handled
	0x40,				// Interval for polling, in units of 1 ms for low/full speed

	// Interface descriptor (CDC)
	9,					// Length of the descriptor
	0x04,				// Type: Interface Descriptor
	0x01,				// Interface ID
	0x00,				// Alternate setting
	0x02,				// Number of Endpoints
	0x0a,				// Interface class code
	0x00,				// Subclass code
	0x00,				// Protocol code
	0x00,				// Index of corresponding string descriptor (On Windows, it is called "Bus reported device description")

	// EndPoint descriptor (CDC Upload, Bulk)
	7,					// Length of the descriptor
	0x05,				// Type: Endpoint Descriptor
	0x02,				// Endpoint: D7: 0-Out 1-In, D6-D4=0, D3-D0 Endpoint number
	0x02,				// Attributes:
						// D1:0 Transfer type: 00 = Control 01 = Isochronous 10 = Bulk 11 = Interrupt
						// 			The following only apply to isochronous endpoints. Else set to 0.
						// D3:2 Synchronization Type: 00 = No Synchronization 01 = Asynchronous 10 = Adaptive 11 = Synchronous
						// D5:4	Usage Type: 00 = Data endpoint 01 = Feedback endpoint 10 = Implicit feedback Data endpoint 11 = Reserved
						// D7:6 = 0
	0x40, 0x00,			// Maximum packet size can be handled
	0x00,				// Interval for polling, in units of 1 ms for low/full speed

	// EndPoint descriptor (CDC Upload, Bulk)
	7,				// Length of the descriptor
	0x05,				// Type: Endpoint Descriptor
	0x82,				// Endpoint: D7: 0-Out 1-In, D6-D4=0, D3-D0 Endpoint number
	0x02,				// Attributes:
						// D1:0 Transfer type: 00 = Control 01 = Isochronous 10 = Bulk 11 = Interrupt
						// 			The following only apply to isochronous endpoints. Else set to 0.
						// D3:2 Synchronization Type: 00 = No Synchronization 01 = Asynchronous 10 = Adaptive 11 = Synchronous
						// D5:4	Usage Type: 00 = Data endpoint 01 = Feedback endpoint 10 = Implicit feedback Data endpoint 11 = Reserved
						// D7:6 = 0
	0x40, 0x00,			// Maximum packet size can be handled
	0x00				// Interval for polling, in units of 1 ms for low/full speed
};
