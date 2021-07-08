input()
d = dict()
for i,v in enumerate(map(int,input().split())):
	if v not in d:
		d[v] = [0, i]
	d[v][0] -= 1

out = ""
for k,v in sorted(d.items(), key=lambda x: x[1]):
	out += f"{k} " * -v[0]
print(out)