from sys import stdin
s=set()
def main(line):
	out = ""
	for w in line.split():
		u = w.lower()
		if u in s:
			out+=". "
		else:
			out+=w+" "
		s.add(u)

	print(out)

for line in stdin:
	main(line)