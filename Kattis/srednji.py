n,b=map(int,input().split())
it=0
a = [0]
for i, u in enumerate(map(int,input().split()),1):
	val = 0
	if u == b:
		it = i
	elif u > b:
		val = 1
	else:
		val = -1
	a.append(a[-1]+val)
# save all before
# [-n,n] --> [0,2n]
hz = [0]*(n+n+1)
for i,v in enumerate(a[:it]):
	hz[v+n] += 1
# count all after
ans=0
for i,v in enumerate(a[it:], it):
	ans+=hz[v+n]
print(ans)

"""
-1 -1 -1 0 1

  -1 -1 1 1 1 0
0 -1 -2 -1 0 1 2


  1 1 -1 0 -1 -1 1
0 1 2 1  1 0  -1 0

 3 5 4 2 1
-1 0 0 0 -1
"""