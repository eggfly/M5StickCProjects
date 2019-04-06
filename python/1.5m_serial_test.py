from PIL import Image
import math

max_count = 2195
for i in range(max_count):
    num = "%04d" %(i+1)
    image = Image.open("60fps_bad_apple/60fps_bad_apple %s.jpg" % num)
    origin_width, origin_height = image.size
    height = 80
    width = 80 * origin_width / origin_height
    width = math.ceil(width)
    image = image.resize((width, height))
    image = image.convert('LA')
    # image.save("%s.png" %num)
    width, height = image.size
    c_filename = "c/%dx%d_%s.c" %(width, height, num)
    c_file = open(c_filename, 'w')
    for y in range(height):
        for x in range(width):
            level, _ = image.getpixel((x,y))
            level >>= 6
            c_file.write("%d,"%level)
        c_file.write("\n")
    c_file.close()
    if i % 200 == 0:
        print(i)
    # print(image.getpixel((60,60)))
print("done!")
