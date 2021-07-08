from sys import stdin

for n in stdin:
    n=int(n)
    if n<0:
        print("-1", end=' ')
        n=-n
    i=2
    while i*i <= n:
        if n%i!=0:
            i+=1
            continue
        cnt=0
        while n%i==0:
            n//=i
            cnt+=1
        print(i, end='')
        if cnt>1:
            print(f"^{cnt}", end='')
        print(end=' ')
        i+=1
    if n>1:
        print(n, end='')
    print()
