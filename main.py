import numpy as np
import cv2
import time

video_name = "input.mp4"
cap = cv2.VideoCapture(video_name)
f = open("pixels.txt", 'w')
width = 165
height = 82
s = ""
for k in range(1000):
    ret, frame = cap.read()
    ret, frame = cap.read()
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
cv2.destroyAllWindows()
