TARGET = usb_device_cdc

# Adjust the XRAM location and size to leave space for the USB DMA buffers
# Buffer layout in XRAM:
# 0x0000 Ep0Buffer[8]
# 0x0040 Ep1Buffer[8]
# 0x0080 EP2Buffer[2*64]
#
# This takes a total of 256bytes, so there are 768 bytes left.
XRAM_SIZE = 0x0300
XRAM_LOC = 0x0100

C_FILES = \
	main.c \
	bootloader.c \
	ch554_conf.c \
	delay.c \
	usb_cdc.c \
	usb_desc.c \
	usb_endp.c \
	usb_ep0.c \
	usb_it.c \
	usb_string_desc.c

pre-flash:
	

include ../Makefile.include
