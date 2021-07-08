def solve():
	L,R = input().split()
	n = max(len(R), len(L))
	L = "0" + L.zfill(n)
	R = "0" + R.zfill(n)
	ans=0
	for i in range(1,len(L)):
		ans += (int(R[:i]) - int(L[:i])) * 10 - int(L[i]) + int(R[i])
	print(ans)

for i in range(int(input())):
	solve()

"""
10 20
10s 1
1s 1*10

1 1000000000
10^9 1
10^8 1*10


12 34
10^1 2
10^0 (3-1)*10 - 2 + 4

"""