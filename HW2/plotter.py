import matplotlib.pyplot as plt

filename = "C:\\Users\\cole\\Projects\\CS260\\HW2\\results"

with open(filename, "r") as file:
    line = 0
    size = []
    bubble = []
    insert = []
    merge = []
    quick = []
    firstLine = True

    for line in file:
        splitLine = line.split('|')
        splitLine.pop(0)
        size.append(float(splitLine[0]))
        bubble.append(float(splitLine[1]))
        insert.append(float(splitLine[2]))
        merge.append(float(splitLine[3]))
        quick.append(float(splitLine[4]))


fig, ax = plt.subplots(2)

fig.suptitle("Array Size vs Average Time to Sort (ms)")

# Subplot 0
ax[0].set_xscale("log", base=2)
ax[0].set_xticks(size)
ax[0].set_yticks(range(0,25000,4000))
ax[0].set_xlabel("Size of array")
ax[0].set_ylabel("Average Time to Sort (ms)")

ax[0].plot(size, bubble, 'ro--')
ax[0].plot(size, insert, 'bo--')
ax[0].plot(size, merge, 'go--')
ax[0].plot(size, quick, 'mo--')

ax[0].legend(["Bubble", "Insert", "Merge", "Quick"])

# Subplot 1
ax[1].set_xscale("log", base=2)
ax[1].set_xticks(size)
ax[1].set_yticks(range(0,16,2))
ax[1].set_xlabel("Size of array")
ax[1].set_ylabel("Average Time to Sort (ms)")

ax[1].plot(size, merge, 'go--')
ax[1].plot(size, quick, 'mo--')

ax[1].legend(["Merge", "Quick"])

# Save plot to PNG
plt.savefig("C:\\Users\\cole\\Projects\\CS260\\HW2\\timingsComp.png")
