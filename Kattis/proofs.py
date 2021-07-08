s = set()
ok=True
for i in range(1, int(input())+1):
	a, c = input().split('->')
	for w in a.strip().split():
		if w not in s:
			print(i)
			ok=False
			break
	if not ok:
		break
	for w in c.strip().split():
		s.add(w)
else:
	print("correct")