from math import ceil
L,m = map(int, input().split())
lo=10**6
a=["no such mower"]
for i in range(m):
	name,p,c,t,r=input().split(',')
	p,c,t,r=map(int,(p,c,t,r))
	if p>lo:
		continue
	for T in range(1000):
		T = T**2
		tc = ceil(L*T/c)
		tr = (tc//t) * r
		if tc+tr > 10080*T:
			break
	else:
		if p<lo:
			lo=p
			a=[]
		a.append(name)
print('\n'.join(a))
