from collections import deque
n=input()
q=deque(input().split())
class Team():
	def __init__(self):
		self.start=0
		self.turn=0
		self.streak=0
		self.name=['', '']
	def __str__(self):
		return f"{self.start:<5}{self.turn:<5}{self.streak:<5}{self.name}"
wb=[Team(), Team()]
wb[0].name[0]=q.popleft()
wb[1].name[0]=q.popleft()
wb[0].name[1]=q.popleft()
wb[1].name[1]=q.popleft()
ans=1
ansl=[]
for g in input():
	win=1
	if g == 'W':
		win=0
	# winner
	u = wb[win]
	u.turn = not u.turn
	u.streak += 1
	# loser
	v = wb[not win]
	if v.streak >= ans:
		names = f"{v.name[v.start]} {v.name[not v.start]}"
		if v.streak > ans:
			ans=v.streak
			ansl=[]
		ansl.append(names)
	v.turn = not v.turn
	q.append(v.name[v.turn])
	v.name[v.turn] = q.popleft()
	v.start = not v.start
	v.streak = 0
	# print(v,"\n")
for u in wb:
	if u.streak >= ans:
		names = f"{u.name[u.start]} {u.name[not u.start]}"
		if u.streak > ans:
			ans=u.streak
			ansl=[]
		ansl.append(names)
print('\n'.join(ansl))