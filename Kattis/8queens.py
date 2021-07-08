def main():
	c,dl,dr=0,0,0
	no=0
	for i in range(8):
		r=False
		dl<<=1
		dr>>=1
		for i,ch in enumerate(input()):
			if ch != "*":
				continue
			i=1<<i
			if c&i or dl&i or dr&i or r:
				print("invalid")
				return
			dl|=i
			dr|=i
			c|=i
			no+=1
			r=True
	if no!=8:
		print("invalid")
	else:
		print("valid")

main()