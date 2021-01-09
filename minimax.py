al = {
	1 : [2,3],
	2 : [4,5],
	3 : [6,7,8],
	4 : [9,10],
	5 : [11,12,13],
	6 : [14,15,16],
	7 : [17,18],
	8 : 10,
	9 : 2,
	10:4,
	11:8,
	12:3,
	13:0,
	14:3,
	15:7,
	16:9,
	17:0,
	18:12,
}

def MAX(s, a, b):
	if isinstance(al[s], int):
		a = max(a, al[s])
		# print(s, a, b)
		return al[s]
	for i in reversed(al[s]):
		a = max(a, MIN(i, a, b))
		if a >= b:
			# print("stopped", s, a, b)
			return a
	# print(s, a, b)
	return a

def MIN(s, a, b):
	if isinstance(al[s], int):
		b = min(b, al[s])
		# print(s, a, b)
		return al[s]
	for i in reversed(al[s]):
		b = min(b, MAX(i, a, b))
		if b <= a:
			# print("stopped", s, a, b)
			return b
	# print(s, a, b)
	return b

def minimax():
	return MAX(1, -1e9, 1e9)

print(minimax())