import numpy as np
from queue import Queue

f = open("q15.in",'r')
r = f.read()
f.close()

r = np.array([list(i) for i in r.split("\n")], dtype=object)
for i in r:
	print(''.join(i))


# Some values
enemy_ch = {'G':'E','E':'G'}
LARGE = 1000
EMPTY = '.'
adjacent = np.array(((-1,0),(0,-1),(0,1),(1,0)),dtype=int)

# Initialise hit points
g,e = r=='G',r=='E'
unit_no = {'G':len(np.argwhere(g)), 'E':len(np.argwhere(e))}
min_atk, max_atk = 4, unit_no['G']**2*3+1 # derived from 1 v all
unit_atk = {'G':3,'E':15} # 15 is a guess
hp = np.where(g+e, 200, LARGE)

# Because numpy sucks at finding index efficiently
def find_index(arr,k):
	k = tuple(k)
	for a in range(len(arr)): 
		if k == tuple(arr[a]):
			return a
	return -1

# def adj_enemies(xy,ch,r):
# 	# print(xy,ch)
# 	for it in xy+adjacent:
# 		if r[tuple(it)] == ch:
# 			return True
# 	return False

def bfs_move(start,enemies_ch,r):
	# Adjacent to enemy?
	# if adj_enemies(start,enemies_ch,r): return start
	for it in start+adjacent:
		if r[tuple(it)] == enemies_ch:
			return start

	# Find all adjacent squares to enemy
	targets = set()
	for i in np.argwhere(r==enemies_ch):
		for j in adjacent:
			ij = tuple(i+j)
			if r[ij] == EMPTY:
				targets.add(ij)

	queue = Queue()
	queue.put( (0,start) )
	found = []
	came_from = {start:None}
	# visited = {start} # Contains borders and units
	finding = True

	while not queue.empty():
		turns,curr = queue.get()

		# elif finding:
		for it in curr+adjacent:
			it = tuple(it)
			if it not in came_from:
				came_from[it] = curr
				if it in targets:
					found.append( (turns+1,it) )
					finding = False

				# Don't add more moves if found
				# But still need to look through the rest of same moves
				elif r[it] == EMPTY and finding:
					queue.put( (turns+1,it) )

	if finding: # not found
		return -1

	# Find fewest steps in reading order
	it = min(found)[1]
	# Returns first step on path
	while came_from[it] != start:
		it = came_from[it]
		# print(it)
	# print("and moved to",it)
	return it

def game(r,hp,unit_no):
	go = True
	round_no = 0
	while go and 0 not in unit_no.values():
		round_no += 1
		# print("\nROUND",round_no)
		units = np.argwhere(hp!=LARGE) # queue
		while len(units):
			# No enemies left
			if 0 in unit_no.values():
				round_no -= 1 # ended mid-round
				break

			xy = tuple(units[0]) # coordinate of current unit
			ch = r[xy] # unit is 'E' or 'G'
			enemies_ch = enemy_ch[ch] # enemy is 'G' or 'E'

			# Find steps to nearest enemy
			new = bfs_move(xy,enemies_ch,r)

			# If is adjacent or need to move
			if new != -1:
				if new != xy: # need to move
					r[xy], r[new] = EMPTY, ch # change map
					hp[xy], hp[new] = LARGE, hp[xy] # change map
					xy = new

				# Coordinates and health of adjacent enemies
				enemies_adj = []
				enemies_hp = []
				for i in adjacent:
					i = tuple(i+xy)
					if r[i] == enemies_ch:
						enemies_adj.append(i)
						enemies_hp.append(hp[i])

				if len(enemies_adj): # has adjacent enemies?
					# Acquire target
					enemies_targ = enemies_adj[np.argmin(enemies_hp)] # coordinate of enemy with min health

					# ATTACK!
					hp[enemies_targ] -= unit_atk[ch]
					# print(xy,"attacking",enemies_adj,"and chose",enemies_ch,enemies_targ,hp[enemies_targ])

					# But did he die?
					if hp[enemies_targ] <= 0:
						# print(xy,"killed",enemies_ch,enemies_targ)
						r[enemies_targ] = EMPTY # change map
						hp[enemies_targ] = LARGE # change hp grid
						unit_no[enemies_ch] -= 1 # change no of units left

						# killed an elf :(
						if enemies_ch == 'E':
							go = False
							break

						# remove from queue if exists
						it = find_index(units,enemies_targ)
						if it > -1: units = np.concatenate((units[:it],units[it+1:]), axis=0)

			units = units[1:]

	# 	for i in range(r.shape[0]):
	# 		h = [int(hp[i,j]) for j in np.argwhere(hp[i]) if hp[i,j]!=LARGE]
	# 		print(''.join(r[i]),h)

	# for i in range(r.shape[0]):
	# 	h = [int(hp[i,j]) for j in np.argwhere(hp[i]) if hp[i,j]!=LARGE]
	# 	print(''.join(r[i]),h)
	
	# Elf died?
	return unit_no['E']==0 or not go, round_no, hp


# Binary search for attack
tried = dict()
while True:
	# print("\n",unit_atk,min_atk,max_atk)
	r2,hp2,unit_no2 = r.copy(), hp.copy(), unit_no.copy()
	dead, round_no, hp2 = game(r2,hp2,unit_no2)
	if unit_atk['E'] not in tried:
		tried[unit_atk['E']] = (round_no,hp2)
	# died, too little atk
	if dead:
		print(unit_atk['E'],"too little, try",end=' ')
		min_atk = unit_atk['E']
		unit_atk['E'] = (max_atk+min_atk+1)//2
		print(unit_atk['E'])
	# didn't die, too much atk
	else:
		print(unit_atk['E'],"too much, try",end=' ')
		max_atk = unit_atk['E']
		unit_atk['E'] = (max_atk+min_atk)//2
		print(unit_atk['E'])

	if unit_atk['E'] in tried:
		break
	# break

print()
round_no, hp2 = tried[max_atk]
print("ATK",max_atk)
print(round_no,"full rounds")
print( ((hp2!=LARGE)*hp2).sum() )
print( ( (hp2!=LARGE)*hp2 ).sum() * round_no )


# print(r)
# print(hp)
# print(round_no,"full rounds")
# print( ((hp!=LARGE)*hp).sum() )
# print( ( (hp!=LARGE)*hp ).sum() * round_no )