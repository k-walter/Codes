from functools import lru_cache
dd=[
	[-0.5,0],
	[0.5,0],
	[0,-0.5],
	[0,0.5],
]

l,w,n,r=map(int,input().split())
r2=r*r
rect=[]
for dl,dw in dd:
	rect.append((dl*l,dw*w))
a=[]
for i in range(n):
	cx,cy=map(int,input().split())
	ans=0
	for j,(x,y) in enumerate(rect):
		if (x-cx)**2 + (y-cy)**2 <= r2:
			ans |= 1<<j
	a.append(ans)

@lru_cache(maxsize=None)
def f(u, mask):
	if mask==0:
		return 0
	if u==n:
		return 1e9
	return min(
		f(u+1, mask),
		1 + f(u+1, mask&(~a[u]))
		)

ans=f(0, (1<<4)-1)
if ans>=1e9:
	print("Impossible")
else:
	print(ans)