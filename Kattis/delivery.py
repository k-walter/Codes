m,k=map(int, input().split())
p,n=[],[]
for i in range(m):
	x,c=map(int, input().split())
	if x<0:
		n.append([-x,c])
	else:
		p.append([x,c])
n=n[::-1]
ans=0
while len(p):
	cap=k
	ans += p[-1][0] << 1
	while len(p) and cap:
		x,c = p[-1]
		if c <= cap:
			p.pop()
		else:
			p[-1][-1]-=cap
		cap -= min(c,cap)
while len(n):
	cap=k
	ans += n[-1][0] << 1
	while len(n) and cap:
		x,c = n[-1]
		if c <= cap:
			n.pop()
		else:
			n[-1][-1]-=cap
		cap -= min(c,cap)
print(ans)