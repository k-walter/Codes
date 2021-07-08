from sys import stdin
from itertools import combinations
def solve(line):
	a=sorted(map(int,line.split()))
	s=[False]*(a[-1]-a[0])
	for i,j in combinations(a, 2):
		j-=i+1
		if s[j]:
			print("not a ruler")
			return
		s[j]=True
	ans=""
	for i,u in enumerate(s,1):
		if not u:
			ans += f" {i}"
	if len(ans):
		print(f"missing{ans}")
	else:
		print("perfect")

for line in stdin:
	solve(line)