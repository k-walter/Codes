def main():
	n,m=map(int, input().split())
	a=[n]*m # 0s
	for i in range(n):
		for j,c in enumerate(input()):
			a[j] -= int(c)
	n>>=1
	out=""
	for i in a:
		out += "0" if i > n else "1"
	print(out)

for i in range(int(input())):
	main()