n=int(input())
while n:
	a,b=0,0
	for i in range(n):
		op,rd=input().split()
		rd=int(rd)
		if op[0]=="D":
			b+=rd
			print("DROP 2", rd)
			continue
		elif a>=rd:
			print("TAKE 1", rd)
			a-=rd
		else:
			if a:
				print("TAKE 1", a)
			rd-=a
			print("MOVE 2->1", b)
			a,b=b,0
			print("TAKE 1",rd)
			a-=rd
	print()
	n=int(input())
