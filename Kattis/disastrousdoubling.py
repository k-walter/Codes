def main():
	ans=1
	input("")
	for i in map(int,input("").split()):
		ans = (ans * 2) - i
		if ans < 0:
			print("error")
			break
	else:
		print(ans%(10**9+7))

main()