def NQueen(n, board, i, j, found):
	if not found:
		if valid(board, i, j):
			board[i][j] = 1
			if i == n - 1:
				found = True
				printBoard(board)
			NQueen(n, board, i + 1, 0, found)
		else:
			while j >= n - 1:
				i, j = revertMove(board, i, j);
			NQueen(n, board, i, j + 1, False)


def valid(board, x, y):
	for i in range(len(board)):
		if board[x][i] != 0:
			return False

	for i in range(len(board)):
		if board[i][y] != 0:
			return False

	if not isSafe(board, x, y):
		return False
	return True


def isSafe(board, x, y):
	i, j = x, y
	n = len(board)
	while i >= 0 and j >= 0 and i < n and j < n:
		if board[i][j] != 0:
			return False
		i += 1
		j += 1

	i, j = x, y
	while i >= 0 and j >= 0 and i < n and j < n:
		if board[i][j] != 0:
			return False
		i += 1
		j -= 1

	i, j = x, y
	while i >= 0 and j >= 0 and i < n and j < n:
		if board[i][j] != 0:
			return False
		i -= 1
		j -= 1	

	i, j = x, y
	while i >= 0 and j >= 0 and i < n and j < n:
		if board[i][j] != 0:
			return False
		i -= 1
		j += 1 
	return True

def revertMove(board, x, y):
	i, j = x, y
	while i >= 0:
		while j >= 0:
			if board[i][j] != 0:
				board[i][j] = 0
				return i, j
			j -= 1
		i -= 1
	return i, j

def printBoard(board):
	for i in len(board):
		for j in range(board):
			print(board, sep = " ")
		print()

if __name__ == "__main__":
	n = int(input())
	board = [[0 for i in range(n)] for j in range(n)]
	NQueen(n, board, 0, 0, False)