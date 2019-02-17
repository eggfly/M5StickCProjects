import pyscreenshot as ImageGrab
import struct

if __name__ == '__main__':
    im = ImageGrab.grab(bbox=(100, 100, 100 + 160, 100 + 80))  # X1,Y1,X2,Y2
    # save image file
    im.save('screenshot.png')
    print(im)
    w, h = im.size
    print(im.size)
    buffer = b''
    for y in range(h):
        for x in range(w):
            r,g,b = im.getpixel((x,y))
            r >>= 3
            g >>= 2
            b >>= 3
            rgb = (r<<11)|(g<<5)|b
            int16 = struct.pack('>H', rgb)
            buffer+=int16
            if rgb != 65503:
                # print(rgb,end=" ")
                pass
    # show image in a window
    im.show()
    print("done")
    print(len(buffer))
#-#██████████████████████████████████████████
