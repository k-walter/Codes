n, m = map(int, input().split())
p = sorted(map(int, input().split()))
t = [-1001] + sorted(map(int, input().split())) + [2000]
i = 0
ans = 0
hz = 0
for u in p:
	while u - t[i] > t[i+1] - u:
		i += 1
		ans += max(0, hz - 1)
		hz = 0
	hz += 1
ans += max(0, hz - 1)
print(ans)