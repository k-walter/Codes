from sys import stdin
from collections import Counter
c = Counter(i.strip() for i in stdin.readlines())
n = sum(c.values())
ans = ""
for k,v in sorted(c.items()):
	ans += f"{k} {v*100/n:6f}\n"
print(ans, end="")