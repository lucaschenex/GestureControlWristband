import matplotlib
matplotlib.use('TkAgg') # do this before importing pylab
import matplotlib.pyplot as plt
import random
import time



# fig = plt.figure()
fig, axarr = plt.subplots(3, sharex=True)


x = range(30)
y = [[random.randint(-150,150) for i in x], [random.randint(-150,150) for i in x], [random.randint(-150,150) for i in x]]


line = [None] * 3
for i in range(3):
    line[i], = axarr[i].plot(x,y[i])

def animate(data):
    
    # while 1:
    # data = random.random()
    for i in range(3):
        n = len(y[i])
        y[i].append(data[i])
        n += 1
        line[i].set_data(range(n-30, n), y[i][-30:])
        axarr[i].set_xlim(n-31, n-1)
        fig.canvas.draw()
        # time.sleep(0.1)

