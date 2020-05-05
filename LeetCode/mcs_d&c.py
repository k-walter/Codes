class subarr():
	def __init__(self, ans=0, left=0, right=0, total=0):
		self.ans = ans
		self.left = left
		self.right = right
		self.total = total

def solve(arr): # T(n)
	if (len(arr) == 1):
		return subarr(arr[0], arr[0], arr[0], arr[0])
	L = solve(arr[:len(arr)>>1]) # T(n/2)
	R = solve(arr[len(arr)>>1:]) # T(n/2)
	# O(1)
	ans = subarr()
	ans.ans = max(L.ans, R.ans, L.right+R.left)
	ans.left = max(L.left, L.total+R.left)
	ans.right = max(R.right, L.right+R.total)
	ans.total = L.total + R.total
	return ans

print(solve([-2,1,-3,4,-1,2,1,-5,4]).ans)