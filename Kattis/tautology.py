def solve(s):
	for i in range(1<<5):
		st=[]
		for c in reversed(s):
			if 'p' <= c <= 't':
				v = (i & (1 << (ord(c)-ord('p')))) != 0
				st.append(v)
				continue
			if c == 'N':
				v = st.pop()
				st.append(not v)
				continue
			u = st.pop()
			v = st.pop()
			if c=='K':
				st.append(u and v)
			elif c=='A':
				st.append(u or v)
			elif c=='C':
				st.append(not u or v)
			elif c=='E':
				st.append(u == v)
			else:
				assert False, (c, u, v)
		if not st[0]:
			print("not")
			return
	print("tautology")

line = input()
while line != "0":
	solve(line)
	line = input()
