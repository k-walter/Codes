import matplotlib.pyplot as plt
import numpy as np
from queue import Queue

f = open("q6.in", "r")
r = f.readlines()
f.close()

# Test cases
# r = """1, 1
# 1, 6
# 8, 3
# 3, 4
# 5, 5
# 8, 9""".split('\n')

class MinMax():
	def __init__(self):
		self.MIN = 1000
		self.MAX = -1
		self.min_pts = []
		self.max_pts = []

	def compare(self,value,coord):
		# Check larger
		if value >= self.MAX:
			if value == self.MAX:
				self.max_pts.append(coord)
			else: # New largest
				self.MAX = value
				self.max_pts = [coord]

		# Check smaller
		if value <= self.MIN:
			if value == self.MIN:
				self.min_pts.append(coord)
			else: # New smallest
				self.MIN = value
				self.min_pts = [coord]

	def LEN(self):
		return self.MAX - self.MIN

pts = dict() # Store points and their area
idx = { -1:0 } # Heat map
it = 1
# y_axis = MinMax()
# x_axis = MinMax()

# Parse Input Points
for a in r:
	x,y = [int(i) for i in a.split(', ')]
	pt = (y,x)
	pts[pt] = 0
	# idx[pt] = it
	# it += 1
	
	plt.plot(x,-y,'bo')
	# y_axis.compare(y,pt)
	# x_axis.compare(x,pt)

# Coordinates on grid
class Coord():
	def __init__(self,dist,pt=-1):
		self.dist = dist
		self.pt = pt

# Initialise Grid as dictionary
SIZE = 400
grid = dict()
for a in range(SIZE):
	for b in range(SIZE):
		grid[(a,b)] = Coord(SIZE)

# Add adjacent points to queue
def add(queue,pt,origin):
	y,x = pt
	if y > 0:
		queue.put( (origin, (y-1,x)) )
		# print( (origin, (y-1,x)) )
	if y < SIZE-1:
		queue.put( (origin, (y+1,x)) )
		# print( (origin, (y+1,x)) )
	if x > 0:
		queue.put( (origin, (y,x-1)) )
		# print( (origin, (y,x-1)) )
	if x < SIZE-1:
		queue.put( (origin, (y,x+1)) )
		# print( (origin, (y,x+1)) )

	return queue

# Initial circle around points
axn = Queue()
for pt in pts:
	axn = add(axn, pt, pt)

# Manhatten Distance
def dist(pt1,pt2):
	return abs(pt1[0]-pt2[0]) + abs(pt1[1]-pt2[1])

# Expand the circle
while not axn.empty():
	origin,pt = axn.get()
	d = dist(origin,pt)
	curr_owner = grid[pt].pt

	# If current origin is closer
	if d < grid[pt].dist:
		# Subtract Area from Previous
		# If has owner that is not self
		if (curr_owner != -1 and
			curr_owner != origin):
			pts[ curr_owner ] -= 1

		# Change ownership of grid coordinate
		grid[pt].dist = d
		grid[pt].pt = origin

		# Add Area
		pts[origin] += 1

		# Expand Circle
		axn = add(axn,pt,origin)

	# Overlap with another origin
	# Not previously resolved (for other overlaps)
	# And not the same owner
	elif (d == grid[pt].dist and
		curr_owner != -1 and
		curr_owner != origin):
		# Subtract Area from Overlapping
		pts[ grid[pt].pt ] -= 1
		grid[pt].pt = -1

		axn = add(axn,pt,origin)

# Remove infinitely expanding points
for a in range(SIZE):
	if grid[(0,a)].pt in pts:
		pts.pop(grid[(0,a)].pt)
	if grid[(SIZE-1,a)].pt in pts:
		pts.pop(grid[(SIZE-1,a)].pt)
	if grid[(a,0)].pt in pts:
		pts.pop(grid[(a,0)].pt)
	if grid[(a,SIZE-1)].pt in pts:
		pts.pop(grid[(a,SIZE-1)].pt)

biggest = max(*pts)
print(biggest,pts[biggest])
# arr = []
# for y in range(SIZE):
# 	arr.append([])
# 	for x in range(SIZE):
# 		arr[y].append( idx[ grid[(y,x)].pt ] )

# print(np.array(arr))
# plt.imshow(np.array(arr), cmap='hot', interpolation='nearest')
# plt.show()

# grid = np.full((y_axis.MAX,x_axis.MAX), 1000)

# Solving nearest point for every coordinate
# for y in range(y_axis.MIN, y_axis.MAX+1):
# 	for x in range(x_axis.MIN, x_axis.MAX+1):
# 		for pt in pts:
# 			d = dist((y,x),pt)
# 			if d <= grid[y][x]:
# 				grid[y][x] = {}

# tmpx = []
# tmpy = []
# for a in range(50):
# 	for b in range(50):
# 		tmpx.append(a)
# 		tmpy.append(-b)

# plt.plot(tmpx,tmpy)
# print(pts)
# plt.show()
# print(y_axis.MIN,y_axis.min_pts,x_axis.MIN,x_axis.min_pts)
# print(y_axis.MAX,y_axis.max_pts,x_axis.MAX,x_axis.max_pts)