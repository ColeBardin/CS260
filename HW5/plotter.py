import matplotlib.pyploy as plt

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

plt.plot(N, runs[0], 'r')
plt.plot(N, runs[1], 'o')
plt.plot(N, runs[2], 'y')
plt.plot(N, runs[3], 'g')
plt.plot(N, runs[4], 'b')