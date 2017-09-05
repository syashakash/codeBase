#!usr/bin/python3
def getCombination(strA, strB):
	A, B = len(strA), len(strB)
	dp = [[None] * (B + 1) for i in range(A + 1)]
	for i in range(A + 1):
		for j in range(B + 1):
			if not i:
				dp[i][j] = j
			elif not j:
				dp[i][j] = i
			elif strA[i - 1] == strB[j - 1]:
				dp[i][j] = 1 + dp[i - 1][j - 1]
			else:
				dp[i][j] = 1 + min(dp[i][j - 1], dp[i - 1][j])
	i, j = A, B
	strC = []
	while i > 0 and j > 0:
		if strA[i - 1] == strB[j - 1]:
			strC.append(strA[i - 1])
			i -= 1
			j -= 1
		elif dp[i - 1][j] < dp[i][ j -1]:
			i -= 1
		elif dp[i][j - 1] < dp[i - 1][j]:
			j -= 1
	while i > 0:
		strC.append(strA[ i -1])
		i -= 1
	while j > 0:
		strC.append(strA[j - 1])
		j -= 1

	strC = "".join(strC)
	return strC

def main():
	strA = input()
	strB = input()
	answerStr = getCombination(strA, strB)
	print(answerStr)


if __name__ == "__main__":
	main()