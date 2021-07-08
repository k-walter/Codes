from tqdm.auto import tqdm
from functools import lru_cache

def solve(n):
	if n <= 1:
		return 0
	return len(lucky(n))

@lru_cache(maxsize=None)
def lucky(n):
	if n <= 1:
		return range(1,10)
	return tuple(_lucky(n))

def _lucky(n):
	for i in lucky(n-1):
		i *= 10
		for j in range(0,10):
			if (i + j) % n == 0:
				yield i + j

print(list(map(solve, tqdm(range(0,1000+1)))))
