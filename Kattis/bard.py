n=int(input())
hz=[0]*(n+1)
e=int(input())
for i in range(e):
	a=list(map(int, input().split()[1:]))
	if 1 in a:
		val = hz[1]+1
		for i in a:
			hz[i] |= val
	else:
		vis=0
		for i in a:
			vis |= hz[i]
		for i in a:
			hz[i]=vis
for i, vis in enumerate(hz):
	if vis == hz[1]:
		print(i)