import numpy as np
from scipy.spatial.distance import cdist

points = np.loadtxt('q6.in',delimiter=',')

# Test cases
# from io import StringIO
# r = StringIO("""1, 1
# 1, 6
# 8, 3
# 3, 4
# 5, 5
# 8, 9""")
# points = np.loadtxt(r,delimiter=',')

# Find boundary
xmax, ymax = np.amax(points, axis=0) + 2
xmin, ymin = np.amin(points, axis=0) - 1

# Initialise Grid
xx,yy = np.meshgrid( np.arange(xmin,xmax), np.arange(ymin,ymax) )
grid = np.dstack((xx,yy)).reshape(-1,2)

# Distance Map
dist = cdist(points,grid,'cityblock').sum(axis=0) # manhatten distance

# Safe zones
safety = np.where(dist<10000)[0]
print( len(safety) )

# Heatmap
# import matplotlib.pyplot as plt
# dist = dist.reshape(xx.shape) # need to save reshape
# plt.imshow( np.where(dist<10000, dist//2, dist) )
# plt.colorbar()
# plt.show()