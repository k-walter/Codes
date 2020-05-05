PLAYER = 463
POINT = 71787

# Marbles
circle = [0] # circle
it = 0 # current

# Players
score = [0] * PLAYER # scores
player = 1 # current

for no in range(1,POINT+1):
	# If not multiple of 23
	if no % 23:
		# New position
		it += 2
		it %= len(circle)

		# Add marble
		circle = circle[:it+1] + [no] + circle[it+1:]
	else:
		# New position
		it -= 6
		it %= len(circle)

		# Keep current marble and marble 7 places CCW
		score[player] += no + circle[it]

		# Remove marble 7 places CCW
		circle = circle[:it] + circle[it+1:]

		# Shift position because marble removed
		it -= 1
		it %= len(circle)

	# Next Player
	player += 1
	player %= PLAYER

# print(score)
print(max(score))