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

# Find sleepiest guard
# and their sleepiest times
MAX = -1 # largest total no of minutes
sleepiest = -1 # sleepiest ID
mins = {} # every guard's sleepy time
for a in guards:
	total = 0 # total for current guard
	time = -1 # sleepiest time
	maxz = 0 # frequency of sleepiness

	# Add total sleeping time
	# and find sleepiest minute
	for b in range(60):
		curr = guards[a][b]
		total += curr
		if curr > maxz:
			maxz = curr
			time = b

	# Record sleepy times
	mins[a] = time

	# If current guard is sleepier, targethim!
	if total > MAX:
		MAX = total
		sleepiest = a

print(sleepiest,mins[sleepiest])
print(sleepiest*mins[sleepiest])

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

'''
Checking Edge Cases
===================
Possible to do duty without sleeping
	But nothing to add if didn't sleep
Guards fall asleep after 0000
Fortunately, final answer didn't have multiple minutes with same values
'''
# just_changed = False
# for a in r:
# 	time, action = a[1:17], a[19:]
# 	# actions[action[:5]](action)
# 	# print(time,action)
# 	spec = action[:5]
# 	if spec == "Guard":
# 		just_changed = True
# 		print(time,action)
# 	elif just_changed:
# 		just_changed = False
# 		print(time,action)
# 		if spec != "falls":
# 			print("Did not sleep")
# 			break
# 		elif time[-5:-3] != "00":
# 			print("Slept before 12")
# 			break