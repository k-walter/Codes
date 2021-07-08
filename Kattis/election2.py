ntop = dict()
ntoc = dict()
for i in range(int(input())):
	n = input()
	ntop[n] = input()
	ntoc[n] = 0
for i in range(int(input())):
	n = input()
	if n in ntoc:
		ntoc[n] += 1
ntop[""] = "tie"
win,hi="",0
for n,i in ntoc.items():
	if i == hi:
		win=""
	elif i > hi:
		win=n
		hi=i
print(ntop[win])