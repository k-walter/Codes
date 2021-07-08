n,u,v=input().split()
n=int(n)
r,s=0,0
hzu,hzv = [0]*26, [0]*26
for a,b in zip(u,v):
	if a==b:
		r += 1
	hzu[ord(a)-65]+=1
	hzv[ord(b)-65]+=1
for a,b in zip(hzu,hzv):
	s += min(a,b)
print(r,s-r)