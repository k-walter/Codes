f = open("q2.in", "r")
r = f.read().split()
f.close()

num2 = 0
num3 = 0
for a in r:
    # Store Hz
    dic = {}
    for b in a:
        if b in dic:
            dic[b] += 1
        else:
            dic[b] = 1

    has2 = False
    has3 = False
    for b in dic:
        if dic[b] == 2:
            has2 = True
        elif dic[b] == 3:
            has3 = True

    if has2:
        num2 += 1
    if has3:
        num3 += 1

print(num2*num3)
