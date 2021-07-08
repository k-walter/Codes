n=int(input())
ans=0
a=[]
for i in map(int, input().split()[::-1]):
	if len(a)==0:
		a.append(i)
	elif a[-1]==i:
		a.pop()
	else:
		a.append(i)
if len(a):
	print("impossible")
else:
	print(n<<1)

"""
1 2 1 2

1 3 2 2 4 4 3 1

"""