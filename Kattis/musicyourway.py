atoi = dict()
attr = input()
for i, a in enumerate(attr.split()):
	atoi[a] = i
a = [input().split() for i in range(int(input()))]
ans=""
for i in range(int(input())):
	if i:
		ans += "\n"
	i = atoi[input()]
	a.sort(key = lambda x: x[i])
	ans+=attr+"\n"
	for i in a:
		ans+=' '.join(i)+"\n"
print(ans)