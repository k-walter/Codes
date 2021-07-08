from functools import lru_cache

lut=[None]*((1<<9)+1)
for i in range(10):
	lut[1<<i]=i

def main():
	n,k=map(int,input().split())
	am=[]
	for i in range(n):
		adj=(1<<n)-1
		am.append(adj & ~(1<<i))
	for i in range(k):
		u,v=map(int,input().split())
		u-=1
		v-=1
		am[u] &= ~(1<<v)
		am[v] &= ~(1<<u)

	@lru_cache(maxsize=None)
	def f(u, mask):
		if mask==0:
			return am[u]&1
		adj = (mask<<1) & am[u]
		ans=0
		while adj:
			m = adj & (-adj)
			v = lut[m]
			ans+=f(v, mask&(~(m>>1)))
			adj &= ~m
		return ans

	print((f(0, (1<<(n-1))-1)>>1) % 9901)

for i in range(1, int(input())+1):
	print(f"Case #{i}: ", end='')
	main()