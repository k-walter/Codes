from functools import lru_cache

n=10

@lru_cache(2*n*n)
def p(i,j):
	if i == 0 or j == 0: return 0
	if i==1 and j==1: return 1
	return .5 * (p(i-1,j) + p(i,j-1))

for i in range(1,n+1):
	for j in range(1,n+1):
		print(f"{p(i,j):.5f}", end='\t')
	print()