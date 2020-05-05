f = open("q5.in", "r")
r = f.read()
f.close()

# Test cases
# r = """dabAcCaCBAcCcaDA"""

# Using Stack method
stack = []
DIFF = ord('a') - ord('A')

for a in r:
	char = ord(a)

	# If stack not empty
	# And same letter, different case
	if len(stack) and abs(char - stack[-1]) == DIFF:
		stack.pop()
	else:
		stack.append(char)

print( len(stack) )