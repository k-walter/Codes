from math import floor
def isPrime(u):
	for i in range(2,floor(u**.5)+1):
		if u % i == 0:
			return False
	return True

n,b=map(int,input().split())
a=list(range(1,n+1))
tot=sum(a)
ok=False
i=n-1
while a[i] <= b:
	if isPrime(tot):
		ok=True
		break
	if a[i] >= b:
		break
	a[i]+=1
	tot+=1
	if i:
		i-=1
	else:
		i=n-1
if not ok:
	print("impossible")
else:
	for i in range(n):
		print(' '.join(map(str, a[i:]+a[:i])))