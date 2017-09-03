if __name__ == "__main__":
	alist = [int(i) for i in input().strip().split()]
	lis = [] * len(alist)
	for i in range(1, len(alist)):
		for j in range(i):
			if alist[i] >= alist[j] and lis[i] < lis[j] + 1:
				lis[i] = lis[j] + 1
	print(max(lis))