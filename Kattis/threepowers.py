from sys import stdin

lut = {1<<i: i for i in range(65)}
t = [1] * 65
for i in range(1, 65):
	t[i] = t[i-1] * 3

ans = ""
def main(line):
	n = line - 1
	global ans
	ans += "{"
	foo = False
	while n != 0:
		# do stuff
		m = n & (-n)
		if foo:
			ans += ","
		else:
			foo = True
		ans += " " + str(t[lut[m]])
		n &= ~m
	ans += " }\n"

for line in stdin:
	line = int(line)
	if line != 0:
		main(line)
print(ans)

"""
1 3 9 27 81
			0 1
-			1
  -			2
- -			3
    -
-   -
  - -		6 7
- - -


"""