f = open("q1.in", "r")
r = f.read().split()
f.close()

total = 0
for a in r:
    total += int(a)

print(total)
