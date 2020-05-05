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

# Initialise Tasks
SIZE = 26 # or 6
WORKERS = 5 # or 2
A = ord('A')
steps = np.zeros((SIZE,SIZE),dtype=int)

# Parse Input
for line in r:
	steps[ ord(line[36])-A, ord(line[5])-A ] = 1

# To Keep Track
doing = np.full(SIZE,False) # tasks in progress
done = np.full(SIZE,False) # done tasks
timer = np.zeros(SIZE,dtype=int) # timer for running tasks
time = -1 # keep time
working = 0

# Iterate through seconds
while False in done:
	# Increment time and reduce timer
	time += 1
	timer = np.where(timer>0,timer-1,0)

	# Who's done?
	sums = (steps.sum(axis=1) + timer) == 0

	# UwU Task Done?
	it = np.where(sums & doing)[0]
	for a in it:
		# Done!
		working -= 1
		doing[a] = False
		done[a] = True

		# Recalculate to add new tasks
		steps[:,a] = 0
		sums = (steps.sum(axis=1) + timer) == 0

	# OwO New Task?
	it = np.where(sums & (~doing) & (~done))[0] 
	for a in it:
		# Labour laws restrict number of workers
		if working == WORKERS:
			break
		working += 1

		# Start the Grind
		doing[a] = True
		timer[a] = a+61 # timer, or 1

print(time)