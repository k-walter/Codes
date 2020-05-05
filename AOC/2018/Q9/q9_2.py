PLAYER = 463
POINT = 71787*100

# Players
score = [0] * PLAYER # scores
player = 2 # current

class Marble():
	def __init__(self,prev,nexts):
		self.next = nexts
		self.prev = prev

# Marbles
marbles = dict()
marbles[0] = Marble(1,1)
marbles[1] = Marble(0,0)
it = 1

for no in range(2,POINT+1):
	# If not multiple of 23
	if no % 23:
		# Shift marble
		it = marbles[it].next

		# Save nodes
		nexts = marbles[it].next
		prev = marbles[nexts].prev

		# Change previous and next nodes
		marbles[it].next = no
		marbles[nexts].prev = no

		# Create new marble and shift to it
		marbles[no] = Marble(prev,nexts)
		it = no

	else:
		# Shift 7 CCW
		for a in range(7):
			it = marbles[it].prev
		
		# Add to score
		score[player] += it + no

		# Store pointers
		nexts, prev = marbles[it].next, marbles[it].prev

		# Change pointers
		marbles[prev].next, marbles[nexts].prev = nexts, prev
		it = nexts

	player += 1
	player %= PLAYER

# print(score)
print(max(score))