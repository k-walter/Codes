with open('2.in') as f:
	r = list(map(int,f.read().split(',')))
# r[1] = 12
# r[2] = 2

def foo(r, noun, verb):
	mem = r[:]
	mem[1] = noun
	mem[2] = verb
	it = 0
	while mem[it] in {1,2}:
		if mem[it] == 1:
			mem[mem[it+3]] = mem[mem[it+1]] + mem[mem[it+2]]
		else:
			mem[mem[it+3]] = mem[mem[it+1]] * mem[mem[it+2]]
		it += 4
	return mem[0]

# print(foo(r, 12, 2))
for noun in range(0, 99+1):
	for verb in range(0, 99+1):
		if foo(r, noun, verb) == 19690720:
			print(100*noun + verb)