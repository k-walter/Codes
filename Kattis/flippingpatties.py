from collections import defaultdict
n=int(input())
d=defaultdict(int)
for i in range(n):
	a,b=map(int,input().split())
	d[b]+=1
	d[b-a]+=1
	d[b-2*a]+=1
ans=max(d.values())
print((ans+1)//2)

"""
0 7 14
1 3 5
2 3 4
"""