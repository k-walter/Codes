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
print("Tuples", timeit(tup, setup="gc.enable()", number=n))
print("Arrays", timeit(arr, setup="gc.enable()", number=n))
'''
Tuples 4.0753265
Arrays 5.674330899999999

Verdict: arrays are slower to convert from/to hashable format
'''