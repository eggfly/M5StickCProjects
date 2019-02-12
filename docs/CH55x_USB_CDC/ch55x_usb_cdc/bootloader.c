#include "bootloader.h"
#include "delay.h"
#include "ch554_platform.h"

void JumpToBootloader(void) {
	USB_INT_EN = 0;
	USB_CTRL = 0x06;

	mDelaymS(100);

	EA = 0;/* Disable all interrupts */

#ifdef __SDCC
	__asm
		LJMP BOOT_ADDR /* Jump to bootloader */
	__endasm;
#endif

#ifdef __C51__
#pragma asm
		LJMP BOOT_ADDR /* Jump to bootloader */
#pragma endasm
#endif

	while(1);
}
