import sys
import serial
import array
import time
import math
import numpy as np

# enum states
class states:
    initial,ready,steady,go,finish = range(5)

class gestures:
    none,up,down,right,left,front,back = range(7)

# struct used for feature and window
class fstruct:
    def __init__(self):
        self.x = []
        self.y = []
        self.z = []


def startAccessPoint():
    return array.array('B', [0xFF, 0x07, 0x03]).tostring()
 
def accDataRequest():
    return array.array('B', [0xFF, 0x08, 0x07, 0x00, 0x00, 0x00, 0x00]).tostring()

# global variables
#Open port
ser = serial.Serial(2,115200,timeout=1)
 
#Start access point
ser.write(startAccessPoint())


# Read accelerometer data
def readAcc(ser):
    ser.write(accDataRequest())
    accel = ser.read(7)
    
    xoffset = 8
    yoffset = -1
    zoffset = -20
 
    if len(accel) != 7 or (ord(accel[0]) == 0 and ord(accel[1]) == 0 and ord(accel[2]) == 0):
        return (257,257,257)
    
    if ord(accel[2])>127:
        z = ord(accel[2])-256
    else:
        z = ord(accel[2])
    
    if ord(accel[1])>127:
        y = ord(accel[1])-256
    else:
        y = ord(accel[1])
        
    if ord(accel[0])>127:
        x = ord(accel[0])-256
    else:
        x = ord(accel[0])
       
    # calibrate
    x = x-xoffset
    y = y-yoffset
    z = z-zoffset
       
    return (x,y,z)

def parse_line(line):    # parse a line in text into a integer list
    line = line.strip("[]\n")
#     line = line.replace(",","")
    retList = [float(i) for i in line.split()]
    #print(retList)    
    return retList

def read_params(filename):  # hacky
    try:
        infile = open(filename,'r')
    except:
        sys.exit('can\'t open parameter file')
    
    theta = []
    for i in range(7):
        line = infile.readline()
        if line == 'left: \n':
            n = 19
        else:
            n = 13
        
        row = np.array([])
        for j in range(n):
            line = infile.readline()
            new = np.array(parse_line(line))
            row = np.append(row,new,1)
        theta.append(row)
    
    theta = np.asarray(theta)
    return theta

# predict functions
def sigmoid(z):
    s = 1./(1+np.exp(-z))
    return s

def predict(theta,window):
    f = [float(i) for i in window.x]+[float(i) for i in window.y]+[float(i) for i in window.z]
    f = f + [1.0]     # add bias term
    f = np.matrix(f)
    
    theta = (np.matrix(theta)).T
    g = f*theta
    h = sigmoid(g)    
    h = np.asarray(h)
    p = h.argmax(1)  
    return p



######################################################
# start processing
theta = read_params('theta.txt')
g = 50
wlen = 25
x = 0
y = 0
z = 0
state = states.initial
tstart = time.time()
timer = time.time()
window = fstruct()
print("start")
while (time.time()-tstart)<300:
    # state operations
#     print('state is '+str(state))
    if state == states.ready:
        while True:
            (x,y,z) = readAcc(ser)
            if x<256 and y<256 and z<256:
                break           
    elif state == states.steady:
        while True:
            (x,y,z) = readAcc(ser)
            if x<256 and y<256 and z<256:
                break
    elif state == states.go:
        while True:
            (x,y,z) = readAcc(ser)
            if x<256 and y<256 and z<256:
                break        
        window.x.append(x)
        window.y.append(y)
        window.z.append(z)
    elif state == states.finish:
        pass
    else:
        pass
        
            
    # state transitions
    if state == states.initial:
        next_state = states.ready
        timer = time.time()
    elif state == states.ready:
#         print(str(x)+' '+str(y)+' '+str(z))
#         print(math.sqrt(x**2+y**2+z**2))
        if abs(math.sqrt(x**2+y**2+z**2)-g) > 0.1*g:
            next_state = states.ready
            timer = time.time()
        else:
            if time.time()-timer > 0.5:
                next_state = states.steady
                timer = time.time()
                print('ready')
            else:
                next_state = states.ready
    elif state == states.steady:
        #print(math.sqrt(x**2+y**2+z**2))
        if abs(math.sqrt(x**2+y**2+z**2)-g) > 0.1*g:
            next_state = states.go
            timer = time.time()
        else:
            next_state = states.steady
            timer = time.time()
    elif state == states.go:
        if len(window.x) >= wlen:
            next_state = states.finish
            timer = time.time()
        else:
            next_state = states.go
    elif state == states.finish:
        # gesture recognition and actions
        p = predict(theta,window)
        
        if p == gestures.up:
            gesture = 'up'
        elif p == gestures.down:
            gesture = 'down'
        elif p == gestures.right:
            gesture = 'right'
        elif p == gestures.left:
            gesture = 'left'
        elif p == gestures.front:
            gesture = 'front'
        elif p == gestures.back:
            gesture = 'back'
        else:
            gesture = 'none'
        
        
        print(gesture)
#         print(window.x)
#         print(window.y)
#         print(window.z)
        
        # clear window and transit
        window.x = []
        window.y = []
        window.z = []
        next_state = states.ready
        timer = time.time()

                   
    state = next_state

print('finish') 

