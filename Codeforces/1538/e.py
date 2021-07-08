from collections import namedtuple
Word = namedtuple('Word', ['pre', 'suf', 'hz'])

def add(a, b):
	c = a.suf + b.pre
	hz = a.hz + b.hz
	for i,j,k,l in zip(c,c[1:],c[2:],c[3:]):
		if i+j+k+l == "haha":
			hz+=1
	pre = a.pre if len(a.pre) >= 3 else c[:3]
	suf = b.suf if len(b.suf) >= 3 else c[-3:]
	return Word(pre, suf, hz)

def solve():
	d = dict()
	last = ""
	for i in range(int(input())):
		a = input().split()
		rd, op = a[0], a[1]
		last = rd
		if op == "=":
			rn, rm = a[2], a[-1]
			d[rd] = add(d[rn], d[rm])
			continue
		rn = a[-1]
		d[rd] = Word(rn[:3], rn[-3:], rn.count("haha"))
	print(d[last].hz)

for i in range(int(input())):
	solve()
