T=int(input())
a=[]
for i in range(int(input())):
    a.append(tuple(map(int,input().split())))
b=[]
for i in range(int(input())):
    b.append(tuple(map(int,input().split())))
L,R=1,T
while L<R:
    M = (L+R+1)>>1
    ca = 0
    for x,y in a:
        ca += (M >= x)
        ca += max(0, (M-x)//y)
    cb = 0
    for x,y in b:
        cb += (T-M >= x)
        cb += max(0, (T-M-x)//y)
    # print(f"L {L} R {R} M {M} ca {ca} cb {cb}")
    if ca <= cb:
        L=M
    else:
        R=M-1
print(L)

"""
T1 + T2 = T
(T1-A1)//B1 + (T1-A2)//B2 + ... <= (T2-C1)//D1 + ...

20
2
3 2
1 3
3
3 1
4 1
5 1

3+2 x1 <= T1
1+3 x2 <= T1
x1 + x2 + (<=T1)

3+1 y1 <= T2
4+1 y2 <= T2
5+1 y3 <= T2
y1+y2+y3+(<=T2)

x1 + x2 + (<=T1) <= y1+y2+y3+(<=T2)
"""