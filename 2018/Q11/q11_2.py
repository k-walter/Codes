import numpy as np
from scipy.signal import fftconvolve

SERIAL = 7803
# SERIAL = 42

# Calculate power level
def power(x,y):
	return (x+10)*(y*(x+10)+SERIAL) // 100 % 10 -5

# Solve power of individual cells
cell = np.fromfunction(power, (300,300), dtype=int)
shape = cell.shape

maxs = []
homes = []

# Calculate summed area table
sat = cell.cumsum(axis=1).cumsum(axis=0)
mesh = [
	[0,0,1], # BtmRight
	[0,-1,-1], # TopRight
	[-1,0,-1], # BtmLeft
	[-1,-1,1], # TopLeft
]

# Find max for each filter size
# Size of 1 is an edge case so let's hope it's not the largest
for size in range(2,301):
	# Find topleft, topright, bottom left, bottom right
	frame = size + 1

	# Find TopLeft, TopRight, BtmLeft, BtmRight
# 	# Note: Kernel is inverted because maths, but doesn't matter
	kernel = np.zeros((size+1,size+1), dtype=int)
	for x,y,z in mesh:
		kernel[x,y] = z

	# Find power using summed area table
	org = size%2 # If even window size, shift origin
	power = fftconvolve(sat, kernel, mode='same') # 'same' strips FFT stuff

	# Reduce erroneous border data
	border = size // 2
	power[:border,:] = -np.Inf # top
	power[-border:,:] = -np.Inf # bottom
	power[:,:border] = -np.Inf # left
	power[:,-border:] = -np.Inf # right

	# Find home of max power
	home = np.unravel_index(np.argmax(power), shape)
	maxs.append( power[home] ) # save max power
	homes.append( home ) # save coordinates

	# Heuristics
	# I'm guessing that all max don't go below 0
	# Previously guessed that it only goes up then down, I was wrong.
	# print(size,power[home],home)
	# if power[home] < 0:
	# 	break

# Largest filter size
size = np.argmax(maxs) + 2 # size of filter, 2 because I started with size of 2
print("Size",size,"Max",max(maxs))
TopLeft = np.array(homes[size-2]) - (size-1)//2 # Even sizes are centered to the right
print(TopLeft,size)