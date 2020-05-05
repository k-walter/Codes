with open('5.in') as f:
	r = list(map(int,f.read().split(',')))

def foo(r, noun, verb):
	mem = r[:]
	mem[1] = noun
	mem[2] = verb
	it = 0
	while mem[it] in range(1,4+1):
		if mem[it] == 1:
			mem[mem[it+3]] = mem[mem[it+1]] + mem[mem[it+2]]
		else if mem[it] == 2:
			mem[mem[it+3]] = mem[mem[it+1]] * mem[mem[it+2]]
		else if mem[it] == 3:
			# read int input, save to position mem[mem[it+1]]
			pass
		else if mem[it] == 4:
			# output mem[mem[it+1]]
			pass
		it += 4
	return mem[0]

# print(foo(r, 12, 2))
for noun in range(0, 99+1):
	for verb in range(0, 99+1):
		if foo(r, noun, verb) == 19690720:
			print(100*noun + verb)