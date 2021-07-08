def solve():
	x,y,a,b = map(int,input().split())
	if a == b:
		return min(x//a, y//a)
	if a > b:
		a,b = b,a
	L, R = 0, min(x//a, y//a)
	while L < R:
		M = (L + R + 1) >> 1
		v = (x - a * M) // (b - a)
		u = (y - a * M) // (b - a)
		if v + u < M:
			R = M - 1
		else:
			L = M
	return L

for i in range(int(input())):
	print(solve())

"""
u, v in each config

2u + 5v <= 12
2(u + v) + 3v <= 12
v <= ...

5u + 2v <= 10
2(u + v) + 3u <= 10
u <= ...

u + v >= (u+v)
"""