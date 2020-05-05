import numpy as np

f = open("q7.in", "r")
r = f.readlines()
f.close()

# Test cases
# r = """Step C must be finished before step A can begin.
# Step C must be finished before step F can begin.
# Step A must be finished before step B can begin.
# Step A must be finished before step D can begin.
# Step B must be finished before step E can begin.
# Step D must be finished before step E can begin.
# Step F must be finished before step E can begin.""".split('\n')

# Initialise linked nodes
SIZE = 26
A = ord('A')
steps = np.zeros((SIZE,SIZE),dtype=int)

# Parse Input
for line in r:
	steps[ ord(line[36])-A, ord(line[5])-A ] = 1

# Sum
sums = steps.sum(axis=1)

# Iterate through letters
ans = ""
for a in range(SIZE):
	it = np.argmax(sums == 0) # returns index fastest, but returns 0 on fail
	ans += chr(it+A)

	# Change all dependent values
	steps[:,it]=0

	# Don't recalculate
	sums[it] = -1
	sums = np.where(sums>-1,steps.sum(axis=1),-1)

print(ans)