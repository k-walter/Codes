def main():
	n=int(input())
	hz=[0]*n
	for i in range(n):
		u=int(input().split()[-1])
		hz[u-1]+=1
	ans=0
	car=0
	for u in hz:
		car+=u-1
		ans+=abs(car)
	print(ans)

for i in range(int(input())):
	input()
	main()