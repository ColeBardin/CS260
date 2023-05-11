import matplotlib.pyplot as plt
import numpy as np

N = []
runs = [[],[],[],[],[]]
index = 0

with open("results.csv", "r") as file:
    for line in file.readlines():
        for entry in line.split(','):
            if index == 0:
                N.append(int(entry))
            else:
                runs[index - 1].append(float(entry))
        index+=1

bottom = []
top = []

top = 2.375*np.log2(N) - 1
bottom = (np.log2(N) - 1) * 1.75

plt.plot(N, runs[0], '-o', color='#0064ff')
plt.plot(N, runs[1], '-o', color='#3364ff')
plt.plot(N, runs[2], '-o', color='#6664ff')
plt.plot(N, runs[3], '-o', color='#9964ff')
plt.plot(N, runs[4], '-o', color='#CC64ff')
plt.plot(N, top, '-g')
plt.plot(N, bottom, '-r')
plt.xscale("log")
plt.grid()

plt.title("Average Tree Hight versus Number of Random Elements")
plt.legend(["Run 1", "Run 2", "Run 3", "Run 4", "Run 5", "Upper Bound", "Lower Bound"])
plt.xlabel("Number of Random Elements")
plt.ylabel("Average Tree Height")

plt.show()