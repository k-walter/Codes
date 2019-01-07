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
claims = set(range(1,len(r)+1))

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
	for y in range(claim.start.y, claim.end.y):
		for x in range(claim.start.x, claim.end.x):
			# If previously occupied
			if fab[y,x] > 0:
				claims.discard(claim.no)
				claims.discard(fab[y,x])

			# Occupy with claim no, which is >0
			# This helps in the first instance of overlap
			fab[y,x] = claim.no

# Non-overlap(s)
print(claims)