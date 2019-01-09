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
GEN = 20
k = np.array([16,8,4,2,1],dtype=int)

# Read initial state and instructions
# Padding of [0]*40 for growth and calculate index
# 40 = 20 generations * 2 growth/gen
state = np.array([0]*GEN*2+ch2int(r[0])+[0]*GEN*2, dtype=int)
for a in r[2:]:
	tmp = ch2int(a)
	inst, fin = tmp[:5], tmp[5]
	# If instruction produces plant
	if fin:
		insts.append( np.dot(np.array(inst),k) )

# Generation
for a in range(GEN):
	gen = np.convolve(state, k[::-1], mode='same')
	state = np.where(np.isin(gen, insts), 1, 0)
	# print(state[37:-29])

# Resovle index in terms of 0th position
index = np.array(np.where(state==1)) - GEN*2
print(index.sum())