from itertools import permutations, combinations
from collections import defaultdict

def cnt_inv(a):
	ans = 0
	for i, j in combinations(a, 2):
		if i > j:
			ans += 1
	return ans

n=7
d = defaultdict(int)
hi = 0
for i in range(1,n+1):
	for a in permutations(range(i), i):
		no_inv = cnt_inv(a)
		hi = max(hi, no_inv)
		d[(i,no_inv)] += 1
for i in range(hi+2):
	print(f"{i:<5}", end='')
print()
for i in range(1, n+1):
	print(f"{i:<5}", end='')
	for k in range(i*i):
		if (i,k) not in d:
			break
		print(i,k)
		print(f"{d[(i,k)]:<5}", end='')
	print()
