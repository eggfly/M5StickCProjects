import struct

from PIL import Image
import math

max_count = 886

size = None
with open('tingwode.bin', "wb") as rgb_file:
    for i in range(max_count):
        num = "%d" % (i + 1)
        image = Image.open("images/out%s.png" % num)
        origin_width, origin_height = image.size
        height = 80
        width = 80 * origin_width / origin_height
        width = int(math.ceil(width))
        image = image.resize((width, height))
        # image = image.convert('LA')
        image.save("thumb/%s.png" % num)
        width, height = image.size
        size = image.size
        # c_filename = "c/%dx%d_%s.c" % (width, height, num)
        # c_file = open(c_filename, 'w')
        for y in range(height):
            for x in range(width):
                # RGB565
                r, g, b = image.getpixel((x, y))
                # r = 255
                # g = 0
                # b = 0
                level1 = (r & 0b11111000) | (g >> 5)
                level2 = ((g << 3) & 0b11100000) | (b >> 3)
                # print level1, level2
                # c_file.write("%d, %d, " % (level2, level1))
                rgb_file.write(struct.pack("B", level2))
                rgb_file.write(struct.pack("B", level1))
            # c_file.write("\n")
        # c_file.close()
        # rgb_file.write(b"\r\n\r\n")
        if i % 200 == 0:
            print(i)
        # print(image.getpixel((60,60)))
    print("done!")
    print(size)

