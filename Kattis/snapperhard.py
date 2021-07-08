for i in range(1, int(input())+1):
	n,k = map(int,input().split())
	m = (1<<n) - 1
	print(f"Case #{i}: {'ON' if m&k==m else 'OFF'}")