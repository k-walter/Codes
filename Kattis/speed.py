EPS=1e-8
n,T=map(int,input().split())
a=[]
for i in range(n):
	a.append(tuple(map(int,input().split())))
R=1e9
L=-min(i[1] for i in a)
for i in range(200):
	m = (L + R) / 2
	t = 0
	for d,s in a:
		t += d/(s+m)
	# print(f"L {L} R {R} m {m} t {t} T {T}")
	if abs(t-T) < EPS:
		break
	if t > T:
		L=m
	else:
		R=m
print(m)
"""
4/(-1+c) + 4/(0+c) + 10/(3+c) = 5

d1/(s1+c) + d2/(s2+c) + ... dn/(sn+c)
= T
"""