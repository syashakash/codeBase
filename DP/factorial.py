
if __name__ == "__main__":
	fac = [0] * 100
	fac[0] = fac[1] = 1
	fac[2] = 2
	for i in range(3, 100):
		fac[i] = fac[i - 1] * i
	for _ in range(int(input())):
		n = int(input())
		print(fac[n])