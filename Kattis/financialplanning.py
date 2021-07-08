from bisect import bisect
from math import ceil

n, m=map(int, input().split())
a=[]
for i in range(n):
	p,c=map(int,input().split())
	a.append([ceil(c/p), p, c])
a.sort()

for i,j in zip(a,a[1:]):
	j[1]+=i[1]
	j[2]+=i[2]

L,R=a[0][0],2*(10**9)
while L<R:
	M = (L + R) >> 1
	_,p,c=a[bisect(a, [M, 10**10, 10**10]) - 1]
	if m + c <= M * p:
		R=M
	else:
		L=M+1
print(L)

"""
m + c1+... = d * (p1+...)

4 10
3 12	= 4
1 8		= 8
4 17	= 5
10 100	= 10
"""
