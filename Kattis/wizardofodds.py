from math import log2
n,k=map(int,input().split())
if log2(n)>k:
	print("You will become a flying monkey!")
else:
	print("Your wish is granted!")