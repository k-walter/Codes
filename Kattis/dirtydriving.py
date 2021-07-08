n,p = map(int, input().split())
a = sorted(map(int, input().split()))
ans = 0
for i, v in enumerate(a, 1):
    ans = max(i * p - v, ans)
print(a[0] + ans)

"""
p(n+1), n = #cars btw

4 = 3-4 =-1
2 = 2-2 =0
1 = 1-1 =0
+1?

x	o 	x 	x 	?
				o = 1 - (1-1)
				o = 2 - (2-1)
			o = 3 - (4-1)


"""