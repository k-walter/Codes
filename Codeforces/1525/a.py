from math import gcd

def solve():
	k = int(input())
	print(100 // gcd(k, 100))


for i in range(int(input())):
	solve()