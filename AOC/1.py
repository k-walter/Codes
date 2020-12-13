with open("1.in") as f:
    a = sorted(int(i.strip()) for i in f)

l, r = 0, len(a) - 1
while l < r:
    tot = a[l] + a[r]
    if tot == 2020:
        print(a[l] * a[r])
        break
    if tot < 2020:
        l += 1
    else:
        r -= 1
