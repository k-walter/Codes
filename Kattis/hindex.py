n=int(input())
a=sorted(int(input()) for i in range(n))
L,R=0,n
while L<R:
	m = (L+R+1)>>1
	if a[-m] >= m:
		L=m
	else:
		R=m-1
print(L)

"""
5
7 1 2 1 5
1 1 2 5 7

5
7 1 3 1 5
1 1 3 5 7

2 3 4
"""