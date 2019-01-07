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

# Test Case
# r = """#1 @ 1,3: 4x4
# #2 @ 2,1: 4x4
# #3 @ 5,5: 2x2""".split('\n')

class Coord():
	def __init__(self,x,y):
		self.x = x
		self.y = y

class Claim():
	def __init__(self,no,offset_x,offset_y,width,height):
		# Convert from string to int
		no,offset_x,offset_y,width,height = [int(a) for a in [no,offset_x,offset_y,width,height]]

		self.no = no

		# Coordinates of claim
		self.start = Coord(offset_x, offset_y)
		self.end = Coord(offset_x + width, offset_y + height)

# Initialise fabric
fab = np.zeros((1000,1000),int)
# fab = np.zeros((8,8),int)
coords = {} # dict to tag claim to coordinates

for a in r:
	# Parse input
	tmp = a.split()
	claim = Claim(
		tmp[0][1:],
		*tmp[2][:-1].split(','),
		*tmp[3].split('x')
	)
	# print(claim.start.x,claim.end.x)
	# print(claim.start.y,claim.end.y)

	# Add to fabric
	overlap = False
	for y in range(claim.start.y, claim.end.y):
		for x in range(claim.start.x, claim.end.x):
			fab[y,x] += 1

			# Tag claim numbers to their coordinate
			if fab[y,x] > 1:
				coords[y,x].append(claim.no)
			else:
				coords[y,x] = [claim.no]

# Coordinates of overlaps
overlaps = np.nonzero(fab>1)

# Remove overlaps
claims = set(range(1,len(r)+1))
for a in range(len(overlaps[0])):
	y = overlaps[0][a]
	x = overlaps[1][a]
	for b in coords[ (y,x) ]:
		claims.discard(b)

# Non-overlap(s)
print(claims)