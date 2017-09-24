def isSafe(solution, N, M, x, y):
	if x >= 0 and x < N and y >= 0 and y < M and solution[x][y] == 1:
		return True
	return False

def solveMaze(maze, N, M):
	solution = [[0 for i in range(M)] for i in range(N)]
	if not solveMazeUtil(maze, N, M, 0, 0, solution):
		return False
	printMazeSolution(solution)
	return True

def solveMazeUtil(maze, N, M, r, c, solution):
	if r == N - 1 and c == M - 1:
		solution[r][c] = 1
		return True
	if isSafe(maze, N, M, r, c):
		solution[r][c] = 1
		if solveMazeUtil(maze, N, M, r + 1, c, solution):
			return True
		if solveMazeUtil(maze, N, M, r, c + 1, solution):
			return True
		solution[r][c] = 0
		return False
	return False 

def printMazeSolution(solution):
	N = len(solution)
	M = len(solution[0])
	for i in range(N):
		for _ in range(M):
			if _ == M - 1:
				print("----")
			else :
				print('----', end = '')
		for j in range(M):
			print('| {0} '.format(solution[i][j]), end='')
		print("|")
	for _ in range(M):
		print('----', end = '')
	print()

def main():
	n,m = map(int, input("Enter dimensions for maze").split())
	maze = [[int(i) for i in input().strip().split()] for j in range(n)]
	solveMaze(maze, n, m)

if __name__ == '__main__':
	main()
