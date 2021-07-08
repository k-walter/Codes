from sys import stdin
p,t=map(int,input().split())
a=[list() for i in range(p)]
for line in stdin:
	u,v=map(int,line.strip().split())
	a[u-1].append(v)
s=set()
for i in a:
	s.add(tuple(sorted(i)))
print(len(s))