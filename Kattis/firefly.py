from bisect import bisect_left
n,h=map(int, input().split())
a=[int(input()) for i in range(n)]
a,b=a[::2],a[1::2]
a.sort()
b.sort()
n>>=1
lo,hz=10**6,0
for i in range(1,h+1):
	u=n-bisect_left(a,i)
	v=n-bisect_left(b,h-i+1)
	# print(u,v,u+v)
	u+=v
	if u>lo:
		continue
	if u<lo:
		lo=u
		hz=0
	hz+=1
print(lo, hz)