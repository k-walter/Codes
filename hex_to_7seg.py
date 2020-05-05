roygbv = [0xff0900, 0xff700, 0xffef00, 0x00f11d, 0x0079ff, 0xa800ff]
for color, hexa in zip('roygbv', roygbv):
	r = int(bin(max(0,-1+round(((hexa>>(4*4)) & 0xff) / 0xff * (1<<5))))[2:])
	g = int(bin(max(0,-1+round(((hexa>>(2*4)) & 0xff) / 0xff * (1<<6))))[2:])
	b = int(bin(max(0,-1+round(((hexa>>(0*4)) & 0xff) / 0xff * (1<<5))))[2:])
	print(("{}\t{:<05d}\t{:<06d}\t{:<05d}").format(color, r, g, b))