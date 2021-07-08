n=input()
a=[]
for i in map(int,input().split()):
	if len(a) == 0:
		a.append(i)
	elif (a[-1]+i)&1==0:
		a.pop()
	else:
		a.append(i)
print(len(a))