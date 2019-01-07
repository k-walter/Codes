import numpy as np

f = open("q3.in", "r")
r = f.readlines()
f.close()

# Find max width and height
# Width 15 999
# Height 13 998
# tmp = arr[:,1]+arr[:,3]
# print("Width",min(tmp),max(tmp))
# tmp = arr[:,2]+arr[:,4]
# print("Height",min(tmp),max(tmp))

# r = """#1 @ 1,3: 4x4
# #2 @ 3,1: 4x4
# #3 @ 5,5: 2x2""".split('\n')

class Coord():
	def __init__(self,x,y):
		self.x = x
		self.y = y

class Claim():
	def __init__(self,offset_x,offset_y,width,height):
		# Convert from string to int
		offset_x,offset_y,width,height = [int(a) for a in [offset_x,offset_y,width,height]]

		# Coordinates of claim
		self.start = Coord(offset_x, offset_y)
		self.end = Coord(offset_x + width, offset_y + height)

# Initialise fabric
fab = np.zeros((1000,1000),int)

for a in r:
	# Parse input
    tmp = a.split()
    claim = Claim(
    	*tmp[2][:-1].split(','),
		*tmp[3].split('x')
	)
    # print(claim.start.x,claim.end.x)
    # print(claim.start.y,claim.end.y)

    # Add to fabric
    for y in range(claim.start.y, claim.end.y):
	    for x in range(claim.start.x, claim.end.x):
    		fab[y,x] += 1

# Count no of overlaps
overlaps = np.nonzero(fab>1)
print(len(overlaps[0]))