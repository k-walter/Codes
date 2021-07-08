n,m=map(int, input().split())
ans=None
for i in range(n):
	s=set(input().split())
	if ans is None:
		ans=s
	else:
		ans &= s
print(len(ans))
print('\n'.join(sorted(ans)))
