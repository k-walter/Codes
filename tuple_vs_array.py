from array import array
from timeit import timeit

n = 10000000

t = tuple(range(16))
def tup():
	global t
	l = list(t)
	l[4], l[5] = l[5], l[4]
	t = tuple(l)

a = array('B', range(1,10)).tobytes()
def arr():
	global a
	b = array('B')
	array.frombytes(b, a)
	b[4], b[5] = b[5], b[4]
	a = b.tobytes()
# Enable garbage collector
# print("Tuples", timeit(tup, setup="gc.enable()", number=n))
# print("Arrays", timeit(arr, setup="gc.enable()", number=n))
'''
Tuples 4.0753265
Arrays 5.674330899999999

Verdict: arrays are slower to convert from/to hashable format
'''

m = [(1 << 9) - 1] * 3
def bm():
	global m
	return m[0] & m[1] & m[2] & (1 << 3) == 0
	# return (1 << 3) & mask == 0

s = [set(range(1,9)), set(range(3)), set(range(4,9))]
def st():
	global s
	return any(3 in _ for _ in s)

print("bitmask", timeit(bm, setup="gc.enable()", number=n))
print("set", timeit(st, setup="gc.enable()", number=n))

'''
bitmask faster than set for multiple comparisons
'''