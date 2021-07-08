def hor(i,a):
	r,c=0,0
	for j,u in enumerate(a):
		if u is None:
			continue
		if i & (1<<j):
			x,y=u
		else:
			y,x=u
		c+=x
		r=max(r,y)
	return r,c

def stacked(i,a):
	r,c=0,0
	for j,u in enumerate(a):
		if i & (1<<j):
			x,y=u
		else:
			y,x=u
		c+=x
		r=max(r,y)
	return r*c


def solve():
	v=list(map(int,input().split()))
	a=[]
	a.append(v[:2])
	a.append(v[2:-2])
	a.append(v[-2:])
	ans=10**19
	for i in range(8):
		# 3 in row
		r,c = hor(i,a)
		ans=min(ans, r*c)
		# stack 1 above
		for j in range(3):
			b = a[:j] + [None] + a[j+1:]
			r,c = hor(i,b)
			# stack above both
			if i & (1<<j):
				x,y=a[j]
			else:
				y,x=a[j]
			ans=min(ans, max(r,x)*(c+y))
			# if different height, stack between
			dy,dx=-1,-1
			for j,u in enumerate(b):
				if u is None:
					continue
				if i & (1<<j):
					x,y=b[j]
				else:
					y,x=b[j]
				if dy==-1:
					pass
		return
	print(ans)

t=int(input())
for i in range(t):
	solve()