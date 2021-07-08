n=int(input())
b=list(map(int, input().split()))
A,B=map(int,input().split())
lo=10**9
hi=-10**9
for i in b:
	if A<=i<=B:
		lo=min(lo,i)
		hi=max(hi,i)
if A<=lo<=B:
	b.append(A-(lo-A))
if A<=hi<=B:
	b.append(B+(B-hi))
b.sort()
st,d=-1,10**10
for i,j in zip(b,b[1:]):
	if not (A<=i<=B or A<=j<=B):
		continue
	if j-i <= d:
		continue
	d=j-i
	st=i
print(st,d,st+d>>1)