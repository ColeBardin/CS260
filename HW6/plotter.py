import matplotlib.pyplot as plt

filename = "results.csv"
size = []
merge = []
quick = []
heap = []

with open(filename, "r") as file:
    for line in file:
        splitLine = line.split(',')
        size.append(float(splitLine[0]))
        merge.append(float(splitLine[1]))
        quick.append(float(splitLine[2]))
        heap.append(float(splitLine[3]))


plt.title("Array Size vs Average Time to Sort (ms)")
plt.xscale("log", base=2)
plt.xticks(size)
plt.grid("both")
plt.xlabel("Size of array")
plt.ylabel("Average Time to Sort (ms)")

plt.plot(size, merge, 'ro-')
plt.plot(size, quick, 'bo-')
plt.plot(size, heap, 'go-')

plt.legend(["Merge", "Quick", "Heap"])

# Save plot to PNG
plt.show()
plt.savefig("timingsComp.png")
