# Copied from https://www.reddit.com/r/adventofcode/comments/a3kr4r/2018_day_6_solutions/ebfivn2

import numpy as np
from scipy.spatial import distance

# read the data using scipy
points = np.loadtxt('q6.in', delimiter=', ')

# build a grid of the appropriate size - note the -1 and +2 to ensure all points
# are within the grid
# axis 0 is col, axis 1 is row
xmin, ymin = points.min(axis=0) - 1
xmax, ymax = points.max(axis=0) + 2

# and use mesgrid to build the target coordinates
xgrid, ygrid = np.meshgrid(np.arange(xmin, xmax), np.arange(xmin, xmax))
targets = np.dstack([xgrid, ygrid]).reshape(-1, 2) # stack grids by col into rows, then reshape grouped rows to n rows of 2

# happily scipy.spatial.distance has cityblock (or manhatten) distance out
# of the box
cityblock = distance.cdist(points, targets, metric='cityblock') # distance from each point to target
# the resulting array is an input points x target points array
# so get the index of the maximum along axis 0 to tie each target coordinate
# to closest ID
closest_origin = np.argmin(cityblock, axis=0) # argmin returns index
# we need to filter out points with competing closest IDs though
min_distances = np.min(cityblock, axis=0)
competing_locations_filter = (cityblock == min_distances).sum(axis=0) > 1 # If >1 location == min, then true
# note, integers in numpy don't support NaN, so make the ID higher than
# the possible point ID
closest_origin[competing_locations_filter] = len(points) + 1
# and those points around the edge of the region for "infinite" regions
closest_origin = closest_origin.reshape(xgrid.shape) # reshape all points into 2d array
infinite_ids = np.unique(np.vstack([
    closest_origin[0],
    closest_origin[-1],
    closest_origin[:, 0],
    closest_origin[:, -1]
]))
closest_origin[np.isin(closest_origin, infinite_ids)] = len(points) + 1 # infinite_ids is in closest_origin

# and because we know the id of the "null" data is guaranteed to be last
# in the array (it's highest) we can index it out before getting the max
# region size
print(np.max(np.bincount(closest_origin.ravel())[:-1])) # ravel flattens, bincount[id] reflects frequency of id, 

# finally, make a pretty picture for good measure
# import matplotlib.pyplot as plt
# plt.imshow(np.where(closest_origin > len(points), np.NaN, closest_origin)) # returns X,Y where(condition,do if true, do if false)
# plt.colorbar()
# plt.show()