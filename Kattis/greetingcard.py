n=int(input())
s=set()
for i in range(n):
	x,y=map(int,input().split())
	s.add((x,y))
dd=[
	[2018,0],
	[-2018,0],
	[0,2018],
	[0,-2018],

	[1118,1680],
	[-1118,-1680],
	[1118,-1680],
	[-1118,1680],

	[1680,1118],
	[-1680,-1118],
	[1680,-1118],
	[-1680,1118],
]
ans=0
for x,y in tuple(s):
	ok=0
	for dx,dy in dd:
		if (x+dx, y+dy) in s:
			ans += 1
			ok=1
	if ok:
		s.remove((x,y))
			# print(f"({x},{y}) ({x+dx},{y+dy})")
print(ans)