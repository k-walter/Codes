"""
 	You have an unsorted integer array A[1..n]. You also have a sorted integer array B[1..k] (k<n), where B[1]<B[2]<…<B[k]. For any 1i<k, let Si be the set { A[j] | B[i]A[j]<B[i+1] }. You need to compute the array C[1..k-1] where C[i] is the median of all integers in Si if Si is a non-empty set; otherwise set C[i]=0.  Can you propose an 𝑂(𝑛log𝑘) time algorithm to compute C[1..k-1]?
"""

import numpy as np

n = 100
k = 5

np.random.seed(1)
A = np.random.randint(100, size=n)
B = np.sort(np.random.randint(100, size=k)) -1
print("A", np.sort(A))
print("B", B, "\n")

c2 = [[] for i in range(k-1)] # O(k)
for i in A: # O(n)
	idx = np.searchsorted(B, i, side="right") - 1 # O(lgk)
	if idx >= 0 and idx < k-1:
		c2[idx].append(i)
# print("Lengths", [len(i) for i in c2])
print(f"len\tarr")
for i in c2:
	print(f"{len(i)}\t{np.sort(i)}")
print()

c = []
# n1 + n2 + ... + n_k <= n
for i in c2:
	if len(i) == 0:
		c.append(0)
		continue
	m = len(i) >> 1
	i = np.partition(i, m) # O(n_i)
	if len(i) & 1:
		c.append(i[m])
	else:
		i[:m] = np.partition(i[:m], m-1) # left median
		c.append((i[m] + i[m-1])/2)
print(c)