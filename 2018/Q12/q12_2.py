import numpy as np
# from scipy.signal import fftconvolve
# from scipy.ndimage import convolve
import re

# read the data using scipy
# f = open("q12_test.in",'r')
f = open("q12.in",'r')
r = f.readlines()
f.close()

# Input Parser
p = re.compile('[#.]')
def ch2int(r):
	return [1 if ch == '#' else 0 for ch in p.findall(r)]

# Save value
# Converting to binary to find pattern
insts = []
GEN = 50000000000
k = np.array([16,8,4,2,1],dtype=int)

# Read initial state and instructions
# Padding of [0]*40 for growth and calculate index
# 40 = 20 generations * 2 growth/gen
state = np.array(ch2int(r[0]), dtype=int)
for a in r[2:]:
	tmp = ch2int(a)
	inst, fin = tmp[:5], tmp[5]
	# If instruction produces plant
	if fin:
		insts.append( np.dot(np.array(inst),k) )

# Heuristics
# Idea is that new state equal to previous
# ie plants have spread out and cannot propagate / propagates in the same manner
zeroes = 0 # for index
diff = 0 # to project for final value
prev = 0 # base of projection
stop = False

# Generation
for a in range(GEN):
	# print("#",a+1,end=", Ans: ")

	gen = np.convolve(state, k[::-1], mode='full')
	new = np.where(np.isin(gen, insts), 1, 0)

	# Strip 0s and save index for calculation
	front, back = np.argmax(new), np.argmax(new[::-1]) # returns first '1'
	zeroes += front

	# Stopping later to calculate difference for projection
	if np.array_equal(state, new[front:-back]):
		stop = True

	# Replace state rather than using old = state.copy()
	state = new[front:-back]

	# Resolve index in terms of 0th position
	index = np.array(np.where(state==1)) - a*2 - 2 + zeroes
	curr = index.sum()
	# print(curr)

	diff = curr - prev
	prev = curr

	if stop:
		break

# Project value in final generation
ans = prev + diff*(GEN-a-1)
# print(a+1,"similar to",a,"with difference of",diff)
# print("# {}, Ans: {}".format(GEN, prev + diff*(GEN-a-1)))

print(ans)