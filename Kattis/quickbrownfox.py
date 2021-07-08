from string import ascii_lowercase
n=int(input())
for i in range(n):
	hz=[False]*26
	for c in input().lower():
		if not ('a' <= c <= 'z'):
			continue
		hz[ord(c)-ord('a')]=True
	out=""
	for c, i in zip(ascii_lowercase, hz):
		if i:
			continue
		out+=c
	if out == "":
		print("pangram")
	else:
		print(f"missing {out}")
