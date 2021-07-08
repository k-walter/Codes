def solve():
	n=int(input())
	a=list(map(int,input().split()))
	# find min
	lo=min(range(n), key=lambda x:a[x])
	hi=max(range(n), key=lambda x:a[x])
	l,r = min(lo,hi), max(lo,hi)
	# print(l,r)
	ans=min(r+1, n-l, l+1+(n-r))
	print(ans)

for i in range(int(input())):
	solve()