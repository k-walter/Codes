import numpy as np

# WA
def modpow(A, n, mod = 10 ** 10):
	if n <= 1:
		return A
	B = modpow(A, n>>1)
	B = np.matmul(B, B)
	if n&1:
		B = np.matmul(B, A)
	return B % mod

A = np.array([[1,1,1],[1,0,0],[0,1,0]])
# ans = modpow(A, 10**13 + 1 - 3)
ans = modpow(A, 10**13 + 1 - 3, 10**20)
print(np.matmul(ans, [2,1,1]))
