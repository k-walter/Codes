from math import log2
from functools import lru_cache

@lru_cache(maxsize=None)
def lgFact(n):
	if n <= 1:
		return 0
	return log2(n) + lgFact(n-1)

for y in range(1960, 2160+1):
	# 1960 to 1969 = 2^2
	if (y % 10 != 0):
		continue
	y = (y - 1960) // 10 + 2
	y = (1 << y)
	# y = (1 << (1 << y))
	for i in range(2, 1000000):
		if lgFact(i) >= y:
			print(i-1)
			break
	# print(y)
	# break