for i in range(int(input())):
	a=input()
	ans=0
	for i in range(1, len(a)+1):
		b = int(a[:i])
		ans = max(ans, bin(b).count('1'))
	print(ans)
