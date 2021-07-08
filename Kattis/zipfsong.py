n,m=map(int,input().split())
a=[]
for i in range(1,n+1):
	f,s=input().split()
	f=int(f)
	a.append([-f*i, i, s])
a.sort()
print('\n'.join(i[-1] for i in a[:m]))