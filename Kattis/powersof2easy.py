from math import log10, ceil
n,k=map(int,input().split())
k=1<<k
d=10 ** ceil(log10(k))
ans=0
for m in range(k,n+1):
	while m>=k:
		if m%d == k:
			# print(m)
			ans += 1
			break
		m//=10
print(ans)