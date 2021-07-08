def main(line):
	w = float(line.split()[-1])
	hor = list(map(float, input().split())) + [-w/2]
	ver = list(map(float, input().split())) + [-w/2]
	x, y = 75+w/2, 100+w/2
	for u in sorted(hor, reverse=True):
		if u + w < x:
			print("NO")
			return
		x = u
	for u in sorted(ver, reverse=True):
		if u + w < y:
			print("NO")
			return
		y = u
	print("YES")

while 1:
	line = input()
	if line == "0 0 0.0":
		break
	main(line)