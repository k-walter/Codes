s = set()
for i in range(int(input())):
	s.add(input().replace("-", " ").lower())
print(len(s))