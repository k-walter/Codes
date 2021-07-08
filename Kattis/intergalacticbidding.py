n,s=map(int,input().split())
a=[]
for i in range(n):
	t,b=input().split()
	a.append((int(b), t))
a.sort(reverse=True)
ans=[]
for b,t in a:
	if b>s:
		continue
	s-=b
	ans.append(t)
if s:
	print(0)
else:
	print(len(ans))
	print('\n'.join(ans))
