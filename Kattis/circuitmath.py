input()
ass = [i=="T" for i in input().split()]
st = []
A = ord("A")
for i in input().split():
	if i == "-":
		st[-1] = not st[-1]
	elif i == "+":
		v = st.pop()
		st[-1] |= v
	elif i == "*":
		v = st.pop()
		st[-1] &= v
	else:
		st.append(ass[ord(i) - A])
print("T" if st[-1] else "F")