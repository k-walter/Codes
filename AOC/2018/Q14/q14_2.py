INPUT = '765071'
# INPUT = '59414'
lens = (len(INPUT))
inputs = [int(i) for i in INPUT]
score = [3,7,1,0]
it1, it2 = 0,1

while score[-lens:] != inputs:
	# Create recipe(s)
	sc1, sc2 = score[it1], score[it2]
	sums = sc1 + sc2
	if sums >= 10:
		sums = [sums//10, sums%10]
		if score[-lens+1:] + [sums[0]] == inputs: # special case
			score += [sums[0]]
			break
	else:
		sums = [sums]

	# works like score += sums
	# inconclusive results on which is faster
	score.extend( sums )

	# Shift iterators
	it1 = (sc1+it1+1)%len(score)
	it2 = (sc2+it2+1)%len(score)
	
	# if len(score)%1000000==0:
	# 	print(len(score),score[-lens:])

print(len(score)-lens) # recipes before