import matplotlib as py

N = []
runs = [[],[],[],[],[]]

with open("results.csv", "r") as file:
    N = file.readline().split(',')
    runs[0] = file.readline().split(',')
    runs[1] = file.readline().split(',')
    runs[2] = file.readline().split(',')
    runs[3] = file.readline().split(',')
    runs[4] = file.readline().split(',')

print(N)
print(runs)
        
