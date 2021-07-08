hz=[0]*1000000
for i in map(int,input().split()[1:]):
	hz[i]=1
for i in map(int,input().split()[1:]):
	hz[i]|=0b10
prv=0
ans=0
for i in hz:
	if i==0:
		continue
	if i==0b11:
		prv=0
		ans+=1
		continue
	if i & prv:
		continue
	prv = i
	ans += 1
print(ans)