s = set()
def fn(arr):
	if arr in s:
		return
	s.add(arr)

	ans = 0
	for i in reversed(arr):
		ans = (ans << 1 ) | i
	print('\t'.join(map(str,(1 if i else 0 for i in arr))),'\t',ans)

	a,b,c,d = arr
	# Count down
	aa = not a
	bb = not b if not a else b
	cc = not c if not (a or b) else c
	dd = not d if not (a or b or c) else d
	# Count up 
	# bb = not b if a else b
	# cc = not c if (a and b) else c
	# dd = not d if (a and b and c) else d
	fn((aa,bb,cc,dd))

fn(tuple([False]*4))