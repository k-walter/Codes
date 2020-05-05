with open('1.in') as f:
	r = list(map(int, f.readlines()))

def fuel(i):
	i = i//3-2
	if (i <= 0): return 0
	return i + fuel(i)

# print(fuel(100756))
print(sum(fuel(i) for i in r))