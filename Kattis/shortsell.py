n,k=map(int,input().split())
a=[int(i)*100 for i in input().split()] + [10**8]
for i in range(n):
	a[i]+=k*i
lo=[a[-1]]
for i in a[-2::-1]:
	lo.append(min(i, lo[-1]))
ans=0
for i,l in zip(a,lo[::-1]):
	ans=max(ans,i-k-l)
print(ans)