from functools import lru_cache

arr = [10,3,7,2,4,6,11,8,9,1,6,13,12]

# O(n^2) DP solution
@lru_cache()
def lis(n = len(arr)-1, m = 1e9):
	if n == 0:
		return (1, [arr[0]]) if arr[0] < m else (0, [])
		# return arr[0] < m
	if arr[n] >= m:
		return lis(n-1, m)
	else:
		l1, a1 = lis(n-1,arr[n])
		l2, a2 = lis(n-1,m)
		return (l1+1, a1+[arr[n]]) if l1+1 > l2 else (l2, a2)
		# return max(lis(n-1,arr[n])+1, lis(n-1,m))

print(lis())