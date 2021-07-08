from collections import Counter
def read():
	while 1:
		line = input()
		if line == "***":
			return
		yield line
c = Counter(read())
ans = "Runoff!"
hi = 0
for k, v in c.items():
	if v == hi:
		ans = "Runoff!"
	elif v > hi:
		hi = v
		ans = k
print(ans)
