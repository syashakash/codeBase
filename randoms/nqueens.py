solution = 1
def isSafe(board, x, y):
	for i in range(y):
		if board[x][i] == 'Q':
			return False
	i, j = x, y
	while i < len(board) and j >= 0:
		if board[i][j] == 'Q':
			return False
		i += 1
		j -= 1
	i, j = x, y
	while i >= 0 and j >= 0:
		if board[i][j] == 'Q':
			return False
		i -= 1
		j -= 1
	return True

def solveNQueenUtil(board, N, col):
	if col == N:
		printBoard(board, N)
		return True
	for i in range(N):
		if isSafe(board, i, col):
			board[i][col] = 'Q'
			solveNQueenUtil(board, N, col + 1)
			board[i][col] = ' '
	return False

def solveNQueen(board):
	N = len(board)
	if solveNQueenUtil(board, N, 0):
		print("No Solutions Exist")

def printBoard(board, N):
	global solution
	print()
	print("SOLUTION {0}".format(solution))
	solution += 1
	for i in range(N):
		for _ in range(N):
			if _ == N - 1:
				print("----")
			else :
				print('----', end = '')
		for j in range(N):
			print('| {0} '.format(board[i][j]), end='')
		print("|")
	for _ in range(N):
		print('----', end = '')
	print()

def main():
	N = int(input("Enter the size of Board: "))
	board = [[' ' for i in range(N)] for i in range(N)]
	solveNQueen(board)

if __name__ == '__main__':
	main()