from collections import defaultdict
n=int(input())
a,b=defaultdict(int),defaultdict(int)
for i in range(n):
	a[input()]+=1
for i in range(n):
	b[input()]+=1
ans=0
for k,v in a.items():
	ans+=min(v,b[k])
print(ans)