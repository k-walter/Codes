import numpy as np
import re

# read the data using scipy
f = open("q10.in",'r')
r = f.read()
f.close()

# Find all values and shape them into entries
read = np.array( [int(i) for i in re.findall(r"-?\d+",r)] ).reshape(-1,4)
posn, v = read[:,:2], read[:,2:]

# Using area as heuristics
# Idea is that area should get smaller as the word is formed
min_axis, max_axis = posn.min(axis=0)-1, posn.max(axis=0)+2
size = max_axis-min_axis
area = int(size[0]) * int(size[1]) # numpy arrays can't handle large integers
new = area

time = 0

while new <= area:
	# Move to new position
	posn += v
	time += 1

	# Heuristics
	area = new
	min_axis, max_axis = posn.min(axis=0)-1, posn.max(axis=0)+2
	size = max_axis-min_axis
	new = int(size[0]) * int(size[1])

print(time-1)