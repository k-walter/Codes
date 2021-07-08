n,k = map(int, input().split())
a=[tuple(map(int,input().split())) for i in range(n)]
s=set()
for i in range(3):
	a.sort(key = lambda x: -x[i])
	for i in a[:k]:
		s.add(i)
print(len(s))