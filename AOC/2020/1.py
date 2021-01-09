from typing import List
from itertools import combinations

with open('1.in') as f:
	arr: List[int] = list(map(int, f))

pairSums = {sum(ij): ij for ij in combinations(arr, 2)}
for i in arr:
	if 2020 - i not in pairSums:
		continue
	j, k = pairSums[2020 - i]
	prod = i * j * k
	print(prod)
	break
