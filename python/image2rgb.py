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
with serial.Serial('COM16', 115200) as ser:
    print("opened COM")
    start_time = time.time()
    total = 0
    for i in range(max_count):
        total += 1
        print("reading line")
        line = ser.readline()
        print("reading line end")
        print(line)
        delta = time.time() - start_time
        speed = total / delta
        print("fps: %f" %speed)

        num = "%04d" %(i+1)
        image = Image.open("60fps_bad_apple/60fps_bad_apple %s.jpg" % num)
        origin_width, origin_height = image.size
        height = VIDEO_HEIGHT
        width = VIDEO_HEIGHT * origin_width / origin_height
        width = math.ceil(width)
        image = image.resize((width, height))
        image = image.convert('LA')
        width, height = image.size
        byte = 0
        bits = 0
        buf_index = 0
        for y in range(height):
            for x in range(width):
                level, _ = image.getpixel((x, y))
                bits += 1
                if level >= 128:
                    byte |= 1
                if bits == 8:
                    buf_array[buf_index] = struct.pack('B', byte)
                    byte = 0
                    bits = 0
                    buf_index += 1
                else:
                    byte <<= 1
        serial_data = b''.join(buf_array)
        #print(serial_data[200:220], end=',')
        #print(len(serial_data))
        ser.write(serial_data)
