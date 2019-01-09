import numpy as np
from scipy.ndimage import convolve

SERIAL = 7803

# Calculate power level
def power(x,y):
	return (x+10)*(y*(x+10)+SERIAL) // 100 % 10 -5

# Solve power of individual cells
cell = np.fromfunction(lambda i,j: power(i,j), (300,300), dtype=int)

# Convolution Filter to calculate local power
kernel = np.ones((3,3), dtype=int) # actual kernel is inverted in x and y
power = convolve(cell, kernel, mode='constant', cval=0)

home = np.unravel_index(np.argmax(power), cell.shape) # Center of power
print(np.array(home)-1)