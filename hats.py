from tqdm.auto import tqdm
from random import shuffle

N = 10 ** 7

cnt = 0
arr = list(range(10))
for i in tqdm(range(N)):
	shuffle(arr)
	for i,j in enumerate(arr):
		if i == j:
			cnt += 1
			break

print(cnt / N)