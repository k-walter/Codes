from collections import defaultdict
def main():
	n=int(input())
	d=defaultdict(int)
	for i in range(n):
		n,c = input().split()
		d[n]+=int(c)
	print(len(d))
	for k,v in sorted(d.items(), key=lambda x: (-x[1], x[0])):
		print(k, v)

for i in range(int(input())):
	main()
