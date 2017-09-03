if __name__ == "__main__":
	fib = [0] * 1001
	fib[0] = 0
	fib[1] = 1
	for i in range(2, 1001):
		fib[i] = fib[i - 1] + fib[i - 2]
	for _ in range(int(input())):
		n = int(input())
		print(fib[n])	