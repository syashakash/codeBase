def howManyPairs(board, x, y):
	count = 0
	for i in range(y + 1, 8):
		if board[x][i] == 'Q':
			count += 1
			print(y, i)
	i, j = x - 1, y + 1
	while 8 > i >= 0 and 8 > j >= 0:
		if board[i][j] == 'Q':
			count += 1
			print(y, j)
		i -= 1
		j += 1
	i, j = x + 1, y + 1
	while 8 > i >= 0 and 8 > j >= 0:
		if board[i][j] == 'Q':
			count += 1
			print(y, j)
		i += 1
		j += 1
	return count

def countPairs(board, charArr):
	count = 0
	for i in range(8):
		count += howManyPairs(board, charArr[i], i)
	return count

if __name__ == "__main__":
	charArr = [ord('A') - ord('A'), ord('K') - ord('A'), ord('A') - ord('A'), ord('S') - ord('A'), ord('H') - ord('A'), ord('S') - ord('A'), ord('H') - ord('A'), ord('I') - ord('A')]
	print(charArr)
	for i in range(len(charArr)):
		charArr[i] = round(7 * charArr[i] / 25)
	board = [['N' for _ in range(8)] for _ in range(8)]
	charArr[6] += 1
	print(charArr)
	for i in range(len(charArr)):
		board[charArr[i]][i] = 'Q'
	answer = countPairs(board, charArr)
	print(answer)