n,T=map(int, input().split())
a,b,c,t0=map(int, input().split())
arr=[t0]
for i in range(n-1):
    arr.append((a * arr[-1] + b) % c + 1)
arr.sort()
no, t, pen= 0, 0, 0
for i in arr:
    t+=i
    if t>T:
        break
    pen+=t
    no+=1
print(no, pen % (10**9 + 7))