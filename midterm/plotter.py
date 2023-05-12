import matplotlib.pyplot as plt

filename = "/Users/colebardin/Projects/CS260/midterm/results.csv"

size = []
c = []
go = []
csharp = []

with open(filename, "r") as file:
    index = 0
    for line in file.readlines():
        for entry in line.split(','):
            if index == 0:
                size.append(int(entry))
            elif index == 1:
                c.append(float(entry))
            elif index == 2:
                go.append(float(entry))
            elif index == 3:
                csharp.append(float(entry))
        index+=1


plt.title("Array Size vs Time to QuickSort (ms)")

# Subplot 0
plt.grid("both")
plt.xscale("log", base=2)
plt.xticks(size)
plt.xlabel("Size of array")
plt.ylabel("Time to QuickSort (ms)")

plt.plot(size, c, 'ro--')
plt.plot(size, go, 'go--')
plt.plot(size, csharp, 'bo--')

plt.legend(["C", "GO", "C#"])

#plt.show()
# Save plot to PNG
plt.savefig("midterm/timingsComp.png")
