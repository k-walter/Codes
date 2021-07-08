out = ""
for i in range(1, int(input())+1):
	n, k = map(int, input().split())
	out += f"Case #{i}: "
	if (k & ((1<<n) - 1)) + 1 == 1 << n:
		out += "ON"
	else:
		out += "OFF"
	out += "\n"
print(out)
