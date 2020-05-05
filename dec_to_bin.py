def frac(n, dp=10):
	i = 0
	n -= int(n)
	ans = []
	while i < dp and n!=0:
		n *= 2
		ans.append(int(n))
		n -= int(n)
		i += 1
	if i < dp:
		print("ended after", i)
	
	print(''.join(map(str,ans)))
	while len(ans) % 4:
		ans.append(0)
	for i in range(0,len(ans),4):
		tmp = 0
		for j in ans[i:i+4]:
			tmp = (tmp << 1) + j
		print(hex(tmp)[-1], end ='')
	print()

frac(.98,1000)