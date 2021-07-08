from sys import stdin
ans = ""
d = dict()

def solve(line):
	a = line.split()
	if len(a) > 1 and a[1] == "=":
		d[a[0]] = int(a[2])
		return
	no = 0
	s = ""
	for i in a[::2]:
		if i.isnumeric():
			no += int(i)
			continue
		elif i in d:
			no += d[i]
			continue
		if len(s):
			s += " + "
		s += i
	global ans
	if no:
		ans += f"{no}"
		if s:
			ans += " + "
	ans += s + "\n"


for line in stdin:
	line = line.strip()
	if line == "0":
		break
	solve(line)
print(ans)