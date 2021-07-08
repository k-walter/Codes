from sys import stdin
from collections import defaultdict

day = 0
bill = defaultdict(int)
cur = dict()
def main(line):
	if line == "OPEN":
		bill.clear()
		return
	if line == "CLOSE":
		global day
		if day:
			print()
		day += 1
		print(f"Day {day}")
		for k, v in sorted(bill.items()):
			print(f"{k} ${v//10}.{v%10}0")
		return
	op, name, t = line.split()
	t = int(t)
	if op == "ENTER":
		cur[name] = t
	else:
		bill[name] += t - cur.pop(name)

for line in stdin:
	main(line.strip())

"""
Generate every day
.10 / min
OPEN, CLOSE (calculate), ENTER EXIT
"""