f = open("q8.in", "r")
r = [int(a) for a in f.read().split()]
f.close()

# Test cases
# r = [int(a) for a in """2 3 0 3 10 11 12 1 1 0 1 99 2 1 1 2""".split()]

sums = 0

def exec(node):
	noChild,noMeta = node[:2]
	length = 0

	# Recurse children to find length
	for a in range(noChild):
		length += exec( node[2+length:] )

	# Add metadata
	global sums
	for a in node[2+length:2+length+noMeta]:
		sums += a

	# Length of current node
	return 2+length+noMeta

exec(r)
print(sums)