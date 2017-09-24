def dfs(r, c, pacX, pacY, foodX, foodY, board):
    visited = set()
    traversed = []
    stack = []
    stack.append((pacX, pacY))
    while not len(stack) == 0:
        presentX, presentY = stack[-1]
        stack.pop()
        visited.add((presentX, presentY))
        traversed.append((presentX, presentY))
        if (presentX, presentY) == (foodX, foodY):
            break
        if r > presentX - 1 >= 0 and board[presentX - 1][presentY] != '%' and (presentX - 1, presentY) not in visited:
            stack.append((presentX - 1, presentY))
        if c > presentY - 1 >= 0 and board[presentX][presentY - 1] != '%' and (presentX, presentY - 1) not in visited:
            stack.append((presentX, presentY - 1))
        if c > presentY + 1 >= 0 and board[presentX][presentY + 1] != '%' and (presentX, presentY + 1) not in visited:
            stack.append((presentX, presentY + 1))
        if r > presentX + 1 >= 0 and board[presentX + 1][presentY] != '%' and (presentX + 1, presentY) not in visited:
            stack.append((presentX + 1, presentY))
    return traversed

def main():
    pacX, pacY = map(int, input().split())
    foodX, foodY = map(int, input().split())
    rows, columns = map(int, input().split())
    board = [[j for j in input().strip()] for i in range(rows)]
    traversed = dfs(rows, columns, pacX, pacY, foodX, foodY, board)
    print(len(traversed))
    for i in traversed:
        print(*i)

if __name__ == "__main__":
    main()