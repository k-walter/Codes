from math import ceil
scr=[100,75,60,50,45,40,36,32,29,26,24,22,20,18,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1]
n=int(input())
a=[[1,0,0,0,0]]
for i in range(n):
	s,p,f,o=map(int,input().split())
	a.append([-s,p,f,o,i])
a.sort(key=lambda x:x[:3])

ans=[0]*n
for s,u in zip(scr,a):
	ans[u[-1]] = s

rank = 1
tmp=[]
for u,v in zip(a,a[1:]):
	tmp.append(u[-1])
	if u[:3] == v[:3]:
		continue
	avg=ceil(sum(ans[i] for i in tmp)/len(tmp))
	for i in tmp:
		ans[i]=avg
	rank += 1
	if rank > 30:
		break
	tmp=[]

for u in a[:-1]:
	ans[u[-1]]+=u[-2]

print('\n'.join(map(str,ans)))