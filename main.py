import cv2
import time
import os

def colored(r, g, b, text):
    return "\033[38;2;{};{};{}m{}\033[38;2;255;255;255m".format(r, g, b, text)

video_name = "input.mp4"
cap = cv2.VideoCapture(video_name)
width = 131 # S - 132x65, M - 165x82, L - 234x130
height = 64
fps = 35
speed = 2 # with small resolution - 2/3, with high resolution - 3/4 is recomended
pxl = "█"
print("\033c", end="")
for k in range(1000):
    for _ in range(speed):
        ret, frame = cap.read()
    if ret:
        #os.system("clear")
        #print(chr(27)+'[2j')
        #print('\033c')
        print('\x1bc')
        #print("\033[%d;%dH" % (0, 0), end='')
        frame = cv2.resize(frame, (width, height), interpolation =cv2.INTER_AREA)
        s = ""
        for i in range(int(height/2)):
            for j in range(width):
                b, g, r = frame[i*2, j]
                print(colored(r, g, b, pxl), end='')
            print()
        time.sleep(1/fps)

cap.release()



