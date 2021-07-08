n=int(input())
ans=0
for i in range(n-1,-1,-1):
	if input()=='O':
		ans |= 1<<i
print(ans)

"""
Lowest O --> Z
Z --> O
Z --> O

ZOZ
ZZO
ZZZ

OZZO
OZZZ
ZOOO
ZOOZ
ZOZO
ZOZZ
ZZOO
ZZOZ

1 O 1
2 OZ-->ZO 2
4 OZZ --> ZOO --> ZOZ 4
8 OZZZ --> ZOOO --> ZOOZ --> ZOZO --> ZOZZ 8

010 = 2
1001

1010
1001
"""