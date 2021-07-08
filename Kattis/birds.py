from math import ceil

l,d,n=map(int, input().split())
a=sorted([6-d,l-6+d] + [int(input()) for i in range(n)])
ans = 0
for u,v in zip(a, a[1:]):
    u+=d
    v-=d
    if u > v:
        continue
    ans += ceil((v-u+1)/d)
print(ans)

"""
1 2
1 --> 2
2 --> 1

1 3
1 --> 3
2 --> 2

1 4
1 --> 4
2 --> 2

ceil( (R-L+1)/diff )
"""