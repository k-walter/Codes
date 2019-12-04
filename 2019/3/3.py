from collections import defaultdict as dd
with open("3.in") as f:
	r = list(f.readline().strip().split(','))
	r2 = list(f.readline().strip().split(','))

# r = list('R75,D30,R83,U83,L12,D49,R71,U7,L72'.split(','))
# r2 = list('U62,R66,U55,R34,D71,R55,D58,R83'.split(','))
# r = list('R98,U47,R26,D63,R33,U87,L62,D20,R33,U53,R51'.split(','))
# r2 = list('U98,R91,D20,R16,D67,R40,U7,R15,U6,R7'.split(','))
move = {
	'U': (-1, 0),
	'D': (1, 0),
	'L': (0, -1),
	'R': (0, 1)
}

# grid = set((0,0))
g = dd(lambda: 1e9)
xx = yy = 0
mv = 1
for i in r:
	(dy, dx), n = move[i[0]], int(i[1:])

	# starting at y
	# stop before dy * (n+1) distance
	# step by dy
	if dx == 0:
		coord = ((y, xx) for y in range(yy+dy, yy + dy * (n+1), dy))
	else:
		coord = ((yy, x) for x in range(xx+dx, xx + dx * (n+1), dx))

	for y,x in coord:
		g[(y,x)] = min(g[(y,x)], mv)
		mv += 1
	yy = y
	xx = x

xx = yy = 0
mv, dist = 1, 1e9
for i in r2:
	(dy, dx), n = move[i[0]], int(i[1:])
	if dx == 0:
		coord = ((y, xx) for y in range(yy+dy, yy + dy * (n+1), dy))
	else:
		coord = ((yy, x) for x in range(xx+dx, xx + dx * (n+1), dx))

	for y,x in coord:
		if (y,x) in g:
			if (g[(y,x)] + mv < dist):
				dist = g[(y,x)] + mv
		mv += 1
	yy = y
	xx = x

print(dist)