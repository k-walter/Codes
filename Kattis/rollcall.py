from sys import stdin
from collections import Counter
a = sorted((line.strip().split() for line in stdin), key = lambda x: x[::-1])
d = Counter(i[0] for i in a)
ans = ""
for f,l in a:
	ans+=f
	if d[f] > 1:
		ans += " " + l
	ans += "\n"
print(ans)