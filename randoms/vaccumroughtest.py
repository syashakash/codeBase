def reachOrigin(board, x, y):
	while y > 0:
		y -= 1
	
	while x > 0:
		x -= 1

def state(val):
	return 1 if val == "d" else 0

def rule(percept):
	if percept == 1:
		return "clean"
	else:
		return "move"

def interpertInput(percept):
	if rule(percept) == "clean":
		return 1
	elif rule(percept) == "move":
		return 0

def simpleReflexAgent(percept):
	interprettedInput = interpertInput(percept)
	if interprettedInput == 1:
		return 1
	else:
		return 0

def spiralMove(board, m, n):
	top = 0
	bottom = m - 1
	left = 0
	right = n - 1
	dirr = 0
	while top <= bottom and left <= right:
		if dirr == 0:
			for i in range(left, right + 1):
				if simpleReflexAgent(state(board[top][i])) == 1:
					board[top][i] = "-"
					print("Clean")
				print("Move East")
			top += 1

		if dirr == 1:
			for i in range(top, bottom + 1):
				if simpleReflexAgent(state(board[i][right])) == 1:
					board[i][right] = "-"
					print("Clean")
				print("Move South")
			right -= 1			

		if dirr == 2:
			for i in range(right, left - 1, -1):
				if simpleReflexAgent(state(board[bottom][i])) == 1:
					board[bottom][i] = "-"
					print("Clean")
				print("Move West")
			bottom -= 1
		if dirr == 3:
			for i in range(bottom, top - 1, -1):
				if simpleReflexAgent(state(board[i][left])) == 1:
					board[i][left] = "-"
					print("Clean")
				print("Move North")
			left += 1
		dirr = (dirr + 1) % 4

def main():
	m, n = map(int, input().split())
	x, y = map(int, input().split())
	board = [[j for j in input().strip()] for i in range(m)]
	reachOrigin(board, x, y)
	spiralMove(board, m, n)
	print(board)

#if __name__ == "__main__":
main()