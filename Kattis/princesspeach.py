n,m=map(int,input().split())
vis = 0
for i in range(m):
	vis |= 1 << int(input())
for i in range(n):
	if (vis & 1) == 0:
		print(i)
		n -= 1
	vis >>= 1
print(f"Mario got {n} of the dangerous obstacles.")