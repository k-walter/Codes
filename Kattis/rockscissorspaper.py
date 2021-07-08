dd=[
	[-1,0],
	[0,-1],
	[0,1],
	[1,0]
]
nem={
	'R':'P',
	'S':'R',
	'P':'S'
}
def solve():
	r,c,n=map(int,input().split())
	g=[[[None]*c for i in range(r)]]
	g.append([list(input()) for i in range(r)])
	cur=1
	for i in range(n):
		u,v=g[cur],g[not cur]
		for i,y in enumerate(u):
			for j,x in enumerate(y):
				# for neighbors
				z=nem[x]
				for dy,dx in dd:
					yy=i+dy
					xx=j+dx
					if not (0<=yy<r) or not (0<=xx<c):
						continue
					if u[yy][xx] == z:
						x=z
						break
				v[i][j]=x
		cur=not cur
	print('\n'.join(
		''.join(row) for row in g[cur]
	), end='\n\n')

t=int(input())
for i in range(t):
	solve()