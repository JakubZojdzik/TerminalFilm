import numpy as np
import cv2
import time

video_name = "input.mp4"
cap = cv2.VideoCapture(video_name)
f = open("pixels.txt", 'w') #165x82, hight resolution (not recomendet - 234x130)
width = 234
height = 130
s = ""
for k in range(1000):
    for i in range(8):
        ret, frame = cap.read()
    
    frame = cv2.resize(frame, (width, height), interpolation =cv2.INTER_AREA)
    f.seek(0)
    f.truncate(0)
    s = ""
    for i in range(int(height/2)):
        for j in range(width):
            b, g, r = frame[i*2, j]
            s += str(r) + ';' + str(g) + ';' + str(b) + '; '
        s += '\n'
    f.write(s)
    time.sleep(0.5)

f.close()
cap.release()
