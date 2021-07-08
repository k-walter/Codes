from collections import deque
t=int(input())
for i in range(t):
	n=int(input())
	s=set()
	q=deque()
	ans=0
	for i in range(n):
		u=int(input())
		while u in s:
			s.remove(q.popleft())
		s.add(u)
		q.append(u)
		ans=max(ans,len(q))
	print(ans)