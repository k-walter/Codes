from math import gcd, ceil

# build prime sieve
N = ceil(10**4.5)
isPrime = [True] * (N + 1)
isPrime[0] = False
isPrime[1] = False
primes = []
for i in range(2,N+1):
	if not isPrime[i]:
		continue
	primes.append(i)
	for j in range(i * i, N + 1, i):
		isPrime[j] = False

def sexp(n):
	ans = 0
	for p in primes:
		if n <= N and isPrime[n]:
			break
		if p * p > n:
			break
		while n % p == 0:
			ans += 1
			n //= p
	if n > 1:
		ans += 1
	return ans

def solve():
	a,b,k=map(int,input().split())
	g = gcd(a,b)
	if k == 1:
		if (g!=a) and (g!=b):
			return "NO"
		if g==a and g==b:
			return "NO"
	# if k > sum of exponents, no
	if k > sexp(a) + sexp(b):
		return "NO"
	return "YES"

for i in range(int(input())):
	print(solve())

"""
It is acceptable that a=b until the end of k moves. The main thing is that after k moves it turns out to be a=b.

Reduce a or b to factor
a/... = b/... in k turns

gcd(a,b)

36 = 2^2 * 3^2
48 = 2^4 * 3^1
12 = 2^2 * 3^1
	0+2		1+0
	6		3

Not enough moves
	k=1 both need to change
Too many moves
	
"""