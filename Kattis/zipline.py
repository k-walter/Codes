from math import hypot


def main():
    w,g,h,r=map(int,input().split())
    ansMin = hypot(h-g, w)
    # find minima in quadratic curve
    L,R=0,w
    while R-L > 1e-9:
        M1 = (R-L) / 3 + L
        M2 = R - (R-L) / 3
        l1 = hypot(g-r, M1) + hypot(h-r, w-M1)
        l2 = hypot(g-r, M2) + hypot(h-r, w-M2)
        if l1 < l2:
            R=M2
        else:
            L=M1
    print(ansMin, hypot(g-r,L) + hypot(h-r,w-L))
    # K=5
    # for i in range(K):
    #     print(hypot(g-r, w/K*i) + hypot(h-r, w/K*(K-i)), end=' ')


for i in range(int(input())):
    main()

"""
L = L1 + L2
w = w1 + w2
L1 = hypot(g-r, w1)
L2 = hypot(h-r, w2)
L = ((g-r)^2 + w1^2)^0.5 + ((h-r)^2 + (w-w1)^2)^0.5
"""