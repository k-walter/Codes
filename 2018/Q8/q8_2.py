f = open("q8.in", "r")
r = [int(a) for a in f.read().split()]
f.close()

# Test cases
# r = [int(a) for a in """2 3 0 3 10 11 12 1 1 0 1 99 2 1 1 2""".split()]

def exec(node):
	noChild,noMeta = node[:2]
	length = 0
	value = 0
	children = []

	# Recurse children to find length
	for a in range(noChild):
		lenChild, valChild = exec( node[2+length:] )
		length += lenChild
		children.append(valChild)

	# Get metadata
	meta = node[2+length:2+length+noMeta]

	# No Child
	if noChild == 0:
		for a in meta:
			value += a
	# Has Child
	else:
		ranges = range(noChild)
		for a in meta:
			# Correct metadata
			if a-1 in ranges:
				value += children[a-1]

	# Length and Value of current node
	return 2+length+noMeta, value

a,value = exec(r)
print(value)