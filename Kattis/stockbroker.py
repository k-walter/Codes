d=int(input())
a=[int(input()) for i in range(d)] + [0]
cash=100
stk=0
for i,j in zip(a,a[1:]):
	if i<j and stk==0:
		stk=min(100000, cash//i)
		cash-=stk*i
	elif i>j and stk:
		cash+=stk*i
		stk=0
	# print(stk,cash,i>j)
print(cash)

"""
	#	cash
	0	100
265	0	100
262	0	100
120	0	100
318 0	100
98	1	2
360	1	2
464	0	466
195	2	76
440	0	956
196	0	956
"""