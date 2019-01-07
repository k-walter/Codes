import numpy as np

f = open("q4_2.in", "r")
r = f.readlines()
f.close()

# Test cases
# r = """[1518-11-01 00:00] Guard #10 begins shift
# [1518-11-01 00:05] falls asleep
# [1518-11-01 00:25] wakes up
# [1518-11-01 00:30] falls asleep
# [1518-11-01 00:55] wakes up
# [1518-11-01 23:58] Guard #99 begins shift
# [1518-11-02 00:40] falls asleep
# [1518-11-02 00:50] wakes up
# [1518-11-03 00:05] Guard #10 begins shift
# [1518-11-03 00:24] falls asleep
# [1518-11-03 00:29] wakes up
# [1518-11-04 00:02] Guard #99 begins shift
# [1518-11-04 00:36] falls asleep
# [1518-11-04 00:46] wakes up
# [1518-11-05 00:03] Guard #99 begins shift
# [1518-11-05 00:45] falls asleep
# [1518-11-05 00:55] wakes up""".split('\n')

curr = -1 # Current Guard ID
lap = 0 # Starting point
guards = {} # Guards' Sleepy Times

# Change Guard
def guard(time,action):
	global lap, curr
	lap = 0 # reset time
	curr = int(action.split()[1][1:]) # set guard ID

	if curr not in guards:
		guards[curr] = np.zeros(60,int)

# Start the record
def sleep(time,action):
	global lap
	lap = time

# End the record
def wakes(time,action):
	global guards
	guards[curr][lap:time] += 1
	# print(curr,lap,time)
	# print(guards[curr])

# Possible Actions
actions = {
	"Guard":guard,
	"falls":sleep,
	"wakes":wakes
}

# Parse Input
for a in r:
	time, action = int(a[15:17]), a[19:]
	actions[action[:5]](time,action)

# Find sleepiest times
ID = -1
MAX = -1
MIN = -1
for a in guards:
	for b in range(60):
		curr = guards[a][b]
		if curr > MAX:
			MAX = curr
			ID = a
			MIN = b

print(ID,MAX,MIN)
print(ID*MIN)

# # Sort Input Data :(
# f = open("q4.in", "r")
# r = f.readlines()
# f.close()

# r.sort()
# string = ""
# for a in r:
# 	string += a
# f = open("q4_2.in","w")
# f.write(string[:-1])
# f.close()