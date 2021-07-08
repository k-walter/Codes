from itertools import permutations
n = int(input())
a = [ord(c)-ord('A') for c in input()]
hz = [0,0,0]
for i in a:
	hz[i] += 1
ans = 10**9
for b in permutations(range(3), 3):
	tmp = 0
	# start from right
	k = n-1				# end of 3
	j = k - hz[b[-1]]	# end of 2
	i = j - hz[b[1]]	# end of 1
	for v in a[:i+1]:
		tmp += v != b[0]
	for v in a[i+1:j+1]:
		tmp += v != b[1]
	for v in a[j+1:]:
		tmp += v != b[-1]
	ans = min(tmp, ans)
	# move left
	while i >= 1:
		tmp -= a[k] != b[-1]
		tmp += a[k] != b[0]

		tmp -= a[j] != b[1]
		tmp += a[j] != b[-1]

		tmp -= a[i] != b[0]
		tmp += a[i] != b[1]

		i -= 1
		j -= 1
		k -= 1
		ans = min(tmp, ans)
print(ans)