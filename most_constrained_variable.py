from itertools import chain
from copy import deepcopy

DOM = dict()
VAR = set("FTUWRO")
for c in VAR:
	DOM[c] = list(range(10))
for i in range(1,4):
	DOM[f"C{i}"] = [0,1]
DOM["C3"] = DOM["F"] = 1
DOM["T"].remove(0)

def rank(x):
	if isinstance(x, list):
		return len(x)
	return 1e9 + 1

# TODO: use ordereddict, abstract variables
def solve(D2, var=None, depth=-1):
	D = deepcopy(D2)
	if var is not None:
		# alldiff
		val = D[var]
		if var in VAR:
			for v2 in VAR:
				if v2 == var or isinstance(D[v2], int):
					continue
				if val in D[v2]:
					D[v2].remove(val)
		print("\t"*depth + f"{var} = {val}\t{D}")

		# forward check
		if all(isinstance(D[x],int) for x in ("O","R","C1")):
			res = 2 * D["O"] == D["R"] + 10 * D["C1"]
			if not res:
				return False

		if all(isinstance(D[x],int) for x in ("W","C1","U","C2")):
			res = 2 * D["W"] + D["C1"] == D["U"] + 10 * D["C2"]
			if not res:
				return False
	
		if all(isinstance(D[x],int) for x in ("T","C2","O","C3")):
			res = 2 * D["T"] + D["C2"] == D["O"] + 10 * D["C3"]
			if not res:
				return False

		if any(x==[] for x in VAR):
			return False

		# finished
		if all(isinstance(D[x],int) for x in chain(VAR,["C1","C2","C3"])):
			return True

	# select min constrained var
	lo, var = 1e9, "W"
	for k, v in D.items():
		if rank(v) > lo or (rank(v) == lo and k > var):
			continue
		lo = rank(v)
		var = k

	# assign val
	tmp = D[var]
	depth += 1
	for val in tmp:
		D[var] = val
		if solve(D, var, depth):
			return True
		else:
			print("\t"*(1+depth) + f"backtrack {var} = {val}")

	return False

print(DOM)
solve(DOM)