from collections import Counter
s=input()
c = [0]*10
for i in map(int,s):
	c[i] += 1
# get min of digits
for i in range(1, 10**len(s)):
	hz = [0]*10
	j=i
	while i:
		i,d = divmod(i, 10)
		hz[d] += 1
		if hz[d] > c[d]:
			print(j)
			break
	else:
		continue
	break
