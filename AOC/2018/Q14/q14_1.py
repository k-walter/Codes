INPUT = 10+765071
score = [3,7]
it1, it2 = 0, 1

# numpy is slower here :(
# import numpy as np
# score = np.array((3,7))

while len(score) < INPUT:
	# Create recipe(s)
	sc1, sc2 = score[it1], score[it2]
	sums = sc1 + sc2
	if sums >= 10: # faster than converting to string and back
		sums = [sums//10, sums%10]
	else:
		sums = [sums]
	score += sums
	# score = np.concatenate((score,sums))

	# Shift iterators
	it1 = (sc1+it1+1)%len(score)
	it2 = (sc2+it2+1)%len(score)
	# print(score,it1,it2)

[print(str(i),end='') for i in score[INPUT-10:INPUT]]

# from time import time
# num = 1000000
# t0 = time()
# for a in range(num):
# t1 = time()
# print((t1-t0)/num)