from bisect import bisect
n,m=map(int,input().split())
a=[(0,0)]
for i in range(n):
	h,t=map(int,input().split())
	t+=a[-1][0]
	h+=a[-1][-1]
	a.append((t,h))
d=[(0,a[-1][-1])]
for i in range(m):
	h,t=map(int,input().split())
	h=d[-1][-1]-h
	t+=d[-1][0]
	d.append((t,h))
L,R=0,min(a[-1][0], d[-1][0])
for i in range(200):
	m=(L+R)/2
	# find height of a
	i=bisect(a,(m,-1))
	(ut,uh),(vt,vh)=a[i-1],a[i]
	ah=(m-ut)*(vh-uh)/(vt-ut)+uh
	# find height of d
	i=bisect(d,(m,-1))
	(ut,uh),(vt,vh)=d[i-1],d[i]
	dh=uh-(m-ut)*(uh-vh)/(vt-ut)
	if ah < dh:
		L=m
	else:
		R=m
print(m)