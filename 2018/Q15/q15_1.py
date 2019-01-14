import numpy as np
from queue import Queue

f = open("q15.in",'r')
r = f.read()
f.close()

r = np.array([list(i) for i in r.split("\n")], dtype=object)
print(r)


# Some values
enemy_ch = {'G':'E','E':'G'}
LARGE = 1000
EMPTY = '.'
adjacent = np.array(((-1,0),(0,-1),(0,1),(1,0)),dtype=int)

# Initialise hit points
g,e = r=='G',r=='E'
unit_no = {'G':len(np.argwhere(g)), 'E':len(np.argwhere(e))}
hp = np.where(g+e, 200, LARGE)

# Because numpy sucks at finding index efficiently
def find_index(arr,k):
	k = tuple(k)
	for a in range(len(arr)): 
		if k == tuple(arr[a]):
			return a
	return -1

def manhatten_floodfill(start,targets):
	# print(start,"finding",targets,end=" ")
	queue = Queue()
	queue.put(start)
	came_from = {start:None}
	visited = {start} # Contains borders and units
	finding = True

	while not queue.empty() and finding:
		curr = queue.get()
		# add squares
		for it in curr+adjacent:
			it = tuple(it)
			if it not in visited:
				visited.add(it)
				if it in targets:
					came_from[it] = curr
					finding = False
					break
				elif r[it] == EMPTY:
					came_from[it] = curr
					queue.put(it)

	if finding: # not found
		return -1

	# Returns full path
	# path = []
	# while it != start:
	# 	path.append(it)
	# 	it = came_from[it]
	# return path[::-1]

	# Returns first step on path
	while came_from[it] != start:
		it = came_from[it]
	# print("and moved to",it)
	return it

round_no = 0
while 0 not in unit_no.values():
	round_no += 1
	# print("\nROUND",round_no)
	units = np.argwhere(hp!=LARGE)
	while len(units):
		# No enemies left
		if 0 in unit_no.values():
			round_no -= 1 # ended mid-round
			break

		xy = tuple(units[0]) # coordinate of current unit
		ch = r[xy] # unit is 'E' or 'G'
		enemies_ch = enemy_ch[ch] # enemy is 'G' or 'E'
		enemies = r == enemies_ch # grid of enemy

		# Attack enemies in range
		enemies_adj = [tuple(i+xy) for i in adjacent if enemies[tuple(i+xy)]] # coordinates of adjacent enemies
		if len(enemies_adj): # has adjacent enemies?
			# Acquire target
			enemies_hp = [hp[i] for i in enemies_adj] # health of adjacent enemies
			enemies_targ = enemies_adj[np.argmin(enemies_hp)] # coordinate of enemy with min health
			# print(xy,"attacking",enemies_adj,"and chose",enemies_targ)

			# ATTACK!
			hp[enemies_targ] -= 3

			# But did he die?
			if hp[enemies_targ] <= 0:
				# print(xy,"killed",enemies_ch,enemies_targ)
				r[enemies_targ] = EMPTY # change map
				hp[enemies_targ] = LARGE # change hp grid
				unit_no[enemies_ch] -= 1 # change no of units left

				# remove from queue if exists
				it = find_index(units,enemies_targ)
				if it > -1: units = np.concatenate((units[:it],units[it+1:]), axis=0)

		# Move to adjacent open square around enemies in reading order
		else:
			# Find coordinates of enemies' adjacent open squares
			enemies_adj = [tuple(i+j) for j in adjacent for i in np.argwhere(enemies) if r[tuple(i+j)]==EMPTY]

			# Floodfill in reading order
			if len(enemies_adj):
				new = manhatten_floodfill(xy,enemies_adj)
				# if new == -1: print("but has no moves") # no moves

				# else:
				if new != -1: # has valid moves
					r[xy], r[new] = EMPTY, ch # change map
					hp[xy], hp[new] = LARGE, hp[xy] # change map
					xy = new

					# ATTACK (again)
					enemies_adj = [tuple(i+xy) for i in adjacent if enemies[tuple(i+xy)]] # coordinates of adjacent enemies
					if len(enemies_adj): # has adjacent enemies?
						# Acquire target
						enemies_hp = [hp[i] for i in enemies_adj] # health of adjacent enemies
						enemies_targ = enemies_adj[np.argmin(enemies_hp)] # coordinate of enemy with min health
						# print("still attacking",enemies_adj,"and chose",enemies_targ)

						# ATTACK!
						hp[enemies_targ] -= 3

						# But did he die?
						if hp[enemies_targ] <= 0:
							# print(xy,"killed",enemies_ch,enemies_targ)
							r[enemies_targ] = EMPTY # change map
							hp[enemies_targ] = LARGE # change hp grid
							unit_no[enemies_ch] -= 1 # change no of units left

							# remove from queue if exists
							it = find_index(units,enemies_targ)
							if it > -1: units = np.concatenate((units[:it],units[it+1:]), axis=0)

		units = units[1:]

	# print(r)
	# print(hp)

print(r)
print(hp)
print(round_no,"full rounds")
print( ((hp!=LARGE)*hp).sum() )
print( ( (hp!=LARGE)*hp ).sum() * round_no )

# Wall (#), Elf (E), Goblin (G), Open Square (.)
# units have 3 attack power, 200, hit points
# combat/movment in rounds
	# order of characters by reading order
	# identify all enemies
		# r=='E' or r=='G'
		# if in range, attack
			# if where not enemy, np.Inf, else hit point
			# choose enemy with fewest hit point
			# reduce enemy hit point by unit's attack power
			# if enemy hit point <= 0
				# enemy dies
				# square becomes open
				# dead enemy cannot take turn
		# else
			# decide where to move
				# adjacent open square around enemies
				# reachable squares
				# nearest by manhatten distance
				# nearest by reading order
			# and move
				# least no of step
				# shortest step in reading order (row first, col after)
			# if now in range, attack
# determine no of full rounds (rounds with enemies) * sum of hit points of remaining units