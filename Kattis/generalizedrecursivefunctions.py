ab = list()
dp = [[-1]*100 for i in range(100)]
vis = [[-1]*100 for i in range(100)]
VIS = 0

def f(x,y):
	if x<=0 or y<=0:
		return ab[-1]
	if vis[x][y] == VIS:
		return dp[x][y]
	vis[x][y] = VIS
	dp[x][y] = 0
	for a,b in zip(ab[:-2:2], ab[1:-2:2]):
		dp[x][y] += f(x-a,y-b)
	dp[x][y] += ab[-2]
	return dp[x][y]

tc = int(input(""))
for i in range(tc):
	ab = list(map(int,input("").split()))
	xy = list(map(int,input("").split()))
	for x,y in zip(xy[::2], xy[1::2]):
		print(f(x,y))
	VIS += 1
	print()
