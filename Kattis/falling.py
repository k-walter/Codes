a=int(input())
for sub in range(1, a+1):
	if a % sub != 0:
		continue
	add = a//sub
	c = add + sub
	if c & 1:
		continue
	c>>=1
	print(add-c, c)
	break
else:
	print("impossible")

"""
0 < a^2 = c^2 - b^2
= (c+b) (c-b)
Since c+b>=a
= >a <a
"""