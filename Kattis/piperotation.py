n,m = map(int,input().split())
hol = [False] * m
def solve():
	for i in range(n):
		line = input()
		L = False
		for i, (v, T) in enumerate(zip(line, hol)):
			if v == "A":
				continue
			elif v == "B":
				if L + T != 1:
					return "Impossible"
				if T:
					L = False
			elif v == "D":
				if L + T != 2:
					return "Impossible"

			elif L + T == 2:
				L = False
				hol[i] = False
			elif L:
				L = False
				hol[i] = True
			elif T:
				L = True
				hol[i] = False
			else:
				L = True
				hol[i] = True
		if L:
			return "Impossible"
	return "Possible"
print(solve())

"""
A nil
B straight
C corner
D 4

Must form cycles, ie no ends terminated
"""