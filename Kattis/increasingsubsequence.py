from bisect import bisect_left
line=input()
while line!="0":
	a=list(map(int,line.split()))
	n,a=a[0]+1,a[1:]+[10**9]
	# LIS
	prv=[-1]*n
	lis=[]
	for i,u in enumerate(a):
		if len(lis)==0 or u>lis[-1][0]:
			if len(lis):
				prv[i]=lis[-1][-1]
			lis.append((u,i))
			continue
		j=bisect_left(lis,(u,-1))
		if lis[j]==u:
			continue
		if j>0:
			prv[i]=lis[j-1][-1]
		lis[j]=(u,i)
	# print(lis, prv)
	ans=[]
	cur=prv[n-1]
	while cur!=-1:
		ans.append(a[cur])
		cur=prv[cur]
	print(len(ans), end=' ')
	for i in reversed(ans):
		print(i, end=' ')
	print()
	line=input()