def longestCommSubSeq(strA, strB):
	A = len(strA)
	B = len(strB)
	LCS = [[0 for i in range(B + 1)] for j in  range(A + 1)]
	for i in range(1, A + 1):
		for j in range(1, B + 1):
			if strA[i - 1] == strB[j - 1]:
				LCS[i][j] = LCS[i - 1][j - 1] + 1
			else:
				LCS[i][j] = max(LCS[i][j - 1], LCS[i - 1][j])
	
	i, j = A, B
	strC = []
	while i > 0 and j > 0:
		if strA[i - 1] == strB[j - 1]:
			strC.append(strA[i - 1])
			i -= 1
			j -= 1
		elif LCS[i - 1][j] > LCS[i][j - 1]:
			i -= 1
		else:
			j -= 1
	strC = ''.join(strC)
	return (strC[::-1], LCS[A][B])

def main():
	strA = input()
	strB = input()
	answerStr, answerLen = longestCommSubSeq(strA, strB)
	print(answerStr)
	print(answerLen)

if __name__ == "__main__":
	main()