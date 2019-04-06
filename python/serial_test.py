import serial
import time
import struct
import math
from PIL import Image

VIDEO_WIDTH = 104
VIDEO_HEIGHT = 78

BUFFER_BYTES = int(VIDEO_WIDTH * VIDEO_HEIGHT / 8)

buf_array = [b"\xFF"] * BUFFER_BYTES
max_count = 1317

print("opening COM")
with serial.Serial('/dev/cu.usbserial-814E45E541', 1500000) as ser:
    print("opened COM")
    start_time = time.time()
    total = 0
    for i in range(max_count):
        total += 1
        print("reading line")
        line = ser.readline()
        print("reading line end")
        print(line)
        print((line[1]))
        print((line[2]))
