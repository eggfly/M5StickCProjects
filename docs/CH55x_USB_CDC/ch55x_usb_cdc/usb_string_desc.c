#include "ch554_platform.h"
#include "usb_desc.h"

// Language Descriptor
code const uint8_t LangDesc[] = {
	4, 0x03,		// Length = 4 bytes, String Descriptor (0x03) 
	0x09, 0x04	// 0x0409 English - United States
};

// String Descriptors:

code const uint8_t DevName1[] = {
	20, 0x03, 	// Length = 20 bytes, String Descriptor (0x03)
	'C', 0, 'H', 0, '5', 0, '5', 0, '4', 0, ' ', 0, 'C', 0, 'D', 0, 'C', 0
};

code const uint8_t ProductName[] = {
	38, 0x03, 	// Length = 38 bytes, String Descriptor (0x03)
	'R', 0, 'i', 0, 'k', 0, 'k', 0, 'a', 0, '`', 0, 's', 0, ' ', 0, 'C', 0, 'H', 0, '5', 0, '5', 0, '4', 0, ' ', 0, 'D', 0, 'e', 0, 'm', 0, 'o', 0
};

code const uint8_t ManuName[] = {
	18, 0x03, 	// Length = 18 bytes, String Descriptor (0x03)
	'R', 0, 'i', 0, 'k', 0, 'k', 0, 'a', 0, '0', 0, 'w', 0, '0', 0
};

code const uint8_t* StringDescs[USB_STRINGDESC_COUNT] = {	
	LangDesc,			// 0 (If you want to support string descriptors, you must have this!)
	ProductName,		// 1
	ManuName,			// 2
	DevName1			// 3
};
