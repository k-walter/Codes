from sys import stdin
s=dict()
def solve(line):
	a=line.split()
	if a[0] == "define":
		s[a[-1]] = int(a[1])
		return
	op = a[2]
	u, v = a[1], a[-1]
	if u not in s or v not in s:
		print("undefined")
		return
	u, v = s[u], s[v]
	if op == "<":
		ans=u < v
	elif op == ">":
		ans = u > v
	else:
		ans = u == v
	print("true" if ans else "false")

for line in stdin:
	solve(line.strip())