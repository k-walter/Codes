from math import ceil
q,m,s,l=map(int,input().split())
# fill up Qs
ans=ceil(l/m)*q
# fill up remaining with 1s
rem = (-l%m)*q
s = max(0, s-rem)
# fill up remaining 1s
ans += ceil(s/m)
print(ans)

"""
10 2 0 1
0*1 + 1*10

10
"""

