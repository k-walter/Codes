from sys import stdin

d = dict()
def add(line):
	e, f = line.split()
	d[f] = e

def solve(line):
	print(d.get(line, "eh"))

adding = True
for line in stdin:
	line = line.strip()
	if line == "":
		adding = False
	elif adding:
		add(line)
	else:
		solve(line)