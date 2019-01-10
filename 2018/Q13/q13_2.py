import numpy as np

f = open("q13.in",'r')
r = f.read()
f.close()

# r = """/->-\\        
# |   |  /----\\
# | /-+--+-\\  |
# | | |  | v  |
# \\-+-/  \\-+--/
#   \\------/   """

r = np.array(list(r)+['\n'])
r = r.reshape(-1, np.argmax(r=='\n')+1 )[:,:-1]

# Pretty picture of initial
# [print(''.join(i)) for i in r]
# print()


class Cart():
	def __init__(self,prev,turn=0):
		self.prev = prev
		self.turn = turn

# Road directions
null = ' '
straight_rd={'-':np.array(((0,-1),(0,1)),dtype=int),'|':np.array(((-1,0),(1,0)),dtype=int)}
curve_rd={'/':np.array(((1,0),(0,1)),dtype=int),'\\':np.array(((0,1),(-1,0)),dtype=int)}
curve_reverse={'-','+'} # linked to both junction and straight road
junction_rd={'+':np.array(((-1,0),(0,1),(1,0),(0,-1)),dtype=int)} # clockwise

# Cart directions
cart_dir={'^':np.array((1,0),dtype=int),'>':np.array((0,-1),dtype=int),'v':np.array((-1,0),dtype=int),'<':np.array((0,1),dtype=int)} # reversed to calculate previous
urdl_dir = np.array(((0,1,0),(8,0,2),(0,4,0)),dtype=int) # (up right down left) with binary weights
false_dir = ( ('','-',''), ('|','','|'), ('','-','') ) # false directions
road_dir = {5:'|',10:'-',9:'/',6:'/',3:'\\',12:'\\',15:'+'} # (top & btm, left & right, top & left, btm & right, top & right, btm & left, all)

# Initialise variables
road = dict()
cart = np.full(r.shape, '', dtype=object)
prev = r[0,0]
r2 = np.pad(r, 1, mode='constant', constant_values=null) # pad to avoid edge cases with carts


# xx,yy = r.shape
# mesh = np.dstack( np.meshgrid(np.arange(xx),np.arange(yy)) ).reshape(-1,2)
# for a in mesh:

# Initialise roads and carts
for xy in np.ndindex(r.shape):
	x,y = xy
	ch = r[x,y]

	if ch != null:
		# Carts and unknown roads
		if ch in cart_dir:
			# Save cart direction 
			cart[x,y] = Cart( tuple(xy+cart_dir[ch]) )

			# Find and assign road type
			adj = r2[x:x+3,y:y+3] # get surrounding grid
			adj = ((adj!=null) == (adj!=false_dir)) * urdl_dir # (not empty and not parallel roads) multiplied by weight
			ch = road_dir[adj.sum()] # assign road using weight
			r[x,y] = ch

		# 2 way straight roads
		if ch in straight_rd:
			ccw,cw = [ tuple(i) for i in xy + straight_rd[ch] ] # cannot hash ndarray as key
			road[(x,y)] = {cw: ccw, ccw: cw}

		# 2 way curved roads
		elif ch in curve_rd:
			# 'prev' is the road directly above
			# eg (prev) -\ (curr)         |
			#            |        (prev) +/ (curr)
			mult = 1
			# if prev == '|':
			if prev in curve_reverse:
				mult = -1

			ccw,cw = [ tuple(i) for i in xy + mult*curve_rd[ch] ]
			road[(x,y)] = {cw: ccw, ccw: cw}
			# print(ccw,xy,cw)
			# print(r[tuple(ccw)],ch,r[tuple(cw)])

		# 4 way intersections
		elif ch in junction_rd:
			road[(x,y)] = xy + junction_rd[ch]

		prev = ch


# Because numpy sucks at finding index efficiently
def idx(arr,k):
	k = tuple(k)
	for a in range(len(arr)):
		if k == tuple(arr[a]):
			return a
	return -1

# Tick (until one left)
while True:
	# One left after previous tick
	carts = np.argwhere(cart!='')
	if len(carts) == 1:
		new = carts[0]
		break

	# Carts treated as queue
	while len(carts):
		xy = tuple(carts[0])

		# Print movement of carts
		# print(xy,":", cart[xy].prev, r[xy], end=' ')

		# 4 way junction
		if len(road[xy]) == 4:
			# Index of previous position
			# numpy sucks here because it can't efficiently find index of array in array
			new = road[xy]
			it = idx(new,cart[xy].prev)
			
			# New Position
			# (whichever turn %3 + shift 1 from current + current) out of the array %4
			new = tuple( new[ (cart[xy].turn%3+it+1)%4 ] )

			# print(road[xy],cart[xy].prev)
			# print("idx",it, "+ turn",cart[xy].turn, "+ 1 =",(cart[xy].turn+it+1)%4,new)

			cart[xy].turn += 1 # shift for next junction

		# 2 way road
		else:
			new = road[xy][cart[xy].prev]

		# Collision?!?
		if cart[new] != '':
			cart[new] = '' # remove currently there

			it = idx(carts,new)
			if it > -1: # removed exists in queue
				carts = np.concatenate((carts[:it],carts[it+1:]), axis=0)
				
		# Change previous position value and map
		else:
			cart[new] = cart[xy]
			cart[new].prev = xy

		cart[xy] = '' # remove from map
		carts = carts[1:] # next item

	# Pretty pictures
	# if go:
	# 	[print(''.join(i)) for i in np.where(cart!='','#',r)]
	# 	print()

print(new[::-1]) # x and y inverted