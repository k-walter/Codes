def main():
	n=int(input())
	a=tuple(map(int,input().split()))
	for i,j in zip(a, a[1:]):
		if i > j:
			break
	else:
		return 0
	if a[0]==n and a[-1]==1:
		return 3
	if a[0]==1 or a[-1]==n:
		return 1
	return 2

for i in range(int(input())):
	print(main())