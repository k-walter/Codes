n=0
a=[]
st=[]
for c in input():
	if c == "(":
		m=1<<n
		a.append([m,c])
		st.append(m)
		n+=1
	elif c == ")":
		m=st.pop()
		a.append([m,c])
	else:
		a.append(c)
ans=set() # eg ((1)) --> _(1)_ and (_1_)
for i in range((1<<n)-1):
	cur=""
	for j in a:
		if isinstance(j, str):
			cur+=j
		else:
			k,c = j
			if k&i:
				cur+=c
	ans.add(cur)
	# ans.append(cur)
print('\n'.join(sorted(ans)))