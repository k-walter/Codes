f = open("q1.in", "r")
r = [int(i) for i in f.read().split()]
f.close()

dup = set()
it = 0
lens = len(r)
hz = r[it]

while hz not in dup:
	dup.add(hz)

	it += 1
	it %= lens
	hz += r[it]
	
print(hz)