from functools import lru_cache

a=[6,2,5,5,4,5,6,3,7,6]
ahi={v:i for i,v in enumerate(a)}
alo={v:i for i,v in reversed(list(enumerate(a)))}

# print(sorted(ahi.items()))

def arrlo(a):
	a.sort()
	for i, v in enumerate(a):
		if v:
			break
	a.pop(i)
	return [v] + a

@lru_cache(maxsize=None)
def lo(u):
	# most matchsticks, least digits
	if u == 6:
		return [6]
	if u in alo:
		return [alo[u]]
	if u < 0:
		return None
	ans = None
	for m, v in alo.items():
		tmp = lo(u-m)
		if not tmp:
			continue
		tmp = arrlo(tmp + [v])
		# if u == 15:
		# 	print(tmp)
		if not ans:
			ans = tmp
			continue
		if len(ans) > len(tmp):
			ans = tmp
		elif len(ans) == len(tmp) and tmp < ans:
			ans = tmp
	return ans

@lru_cache(maxsize=None)
def hi(u):
	# most matchsticks, least digits
	if u == 0:
		return []
	if u < 0:
		return None
	ans = None
	for m, v in ahi.items():
		tmp = hi(u-m)
		if tmp is None:
			continue
		tmp = sorted(tmp + [v], reverse=True)
		if not ans:
			ans = tmp
			continue
		if len(ans) < len(tmp):
			ans = tmp
		elif len(ans) == len(tmp) and tmp > ans:
			ans = tmp
	return ans

def ltos(a):
	return ''.join(map(str, a))

# for i in (3,6,7,15):
for i in range(2,101):
	print('"'+ltos(lo(i)), ltos(hi(i))
		+'",')