input()
hz=[False]*1002
for i in map(int, input().split()):
	hz[i]=True
st,run=-1,0
for i, ok in enumerate(hz[1:], 1):
	if ok:
		if run==0:
			st=i
		run += 1
		continue
	if run == 0:
		continue
	if run>2:
		print(f"{st}-{i-1}", end=' ')
	else:
		for j in range(st,i):
			print(j, end=' ')
	run=0