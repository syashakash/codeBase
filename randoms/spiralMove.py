def spiralMove(board, m, n):
	top = 0
	bottom = m - 1
	left = 0
	right = n - 1
	dirr = 0
	while top <= bottom and left <= right:
		if dirr == 0:
			for i in range(left, right + 1):
				"""
				if board[top][i] == "1":
					board[top][i] = "0"
				"""
				print(board[top][i], sep = " ")
			top += 1

		elif dirr == 1:
			for i in range(top, bottom + 1):
				"""
				if board[top][i] == "1":
					board[top][i] = "0"
				"""
				print(board[i][right], sep = " ")
			right -= 1			

		elif dirr == 2:
			for i in range(right, left - 1, -1):
				"""
				if board[top][i] == "1":
					board[top][i] = "0"
				"""
				print(board[bottom][i], sep = " ")
			bottom -= 1
		elif dirr == 3:
			for i in range(bottom, top - 1, -1):
				"""
				if board[top][i] == "1":
					board[top][i] = "0"
				"""
				print(board[i][left], sep = " ")
			left += 1
		dirr = (dirr + 1) % 4

if __name__ == "__main__":
	m, n = map(int, input().split())
	board = [[j for j in input().split(' ')] for i in range(m)]
	print(board)
	spiralMove(board, m, n)