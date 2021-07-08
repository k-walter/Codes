from itertools import zip_longest
while True:
	inp = input()
	if inp=="0 0":
		break
	a,b = inp.split()
	ans=0
	car=0
	for u,v in zip_longest(a[::-1],b[::-1],fillvalue='0'):
		u=int(u)
		v=int(v)
		if u+v+car > 9:
			car=1
			ans+=1
		else:
			car=0
	if ans:
		print(f"{ans} carry operation{'s' if ans>1 else ''}.")
	else:
		print("No carry operation.")
