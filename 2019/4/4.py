ran = range(130254,678275+1)
# ran = range(128392,643281+1)
def valid(i):
	i = str(i)
	LEN = 1
	dbl = False
	for a,b in zip(i, i[1:]):
		if b < a:
			return False
		if b == a:
			# dbl = True
			LEN += 1
		else:
			if LEN == 2:
				dbl = True
			LEN = 1

	return dbl or LEN == 2
	# return dbl

no = 0
for i in ran:
	if valid(i):
		print(i)
		no += 1
print(no)