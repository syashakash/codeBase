import random
import queue as q

def ruleBook(matrix, x, y, count, n, m, visited_cell):
    d = q.PriorityQueue()
    if x - 1 >= 0 and visited_cell[x-1][y] == 0:
        if matrix[x - 1][y] == 'd':
            d.put([1 + (-5), 'UP'])
        else :
            d.put([1, 'UP'])
    if x + 1 < n and visited_cell[x + 1][y] == 0 :
        if matrix[x + 1][y] == 'd':
            d.put([2 + (-5), 'DOWN'])
        else :
            d.put([2, 'DOWN'])
    if y - 1 >= 0 and visited_cell[x][y - 1] == 0 :
        if matrix[x][y - 1]=='d':
            d.put([3 + (-5), 'LEFT'])
        else :
            d.put([3, 'LEFT'])
    if y + 1 < m and visited_cell[x][y + 1] == 0:
        if matrix[x][y + 1] == 'd':
            d.put([4 + (-5), 'RIGHT'])
        else :
            d.put([4, 'RIGHT'])
    if d.empty() :
        flag = 0
        while flag == 0:
            r = random.randrange(4)
            if r == 0 and x - 1 >= 0:
                flag = 1
                return 'UP'
            elif r == 1 and x + 1 <= n:
                flag = 1
                return 'DOWN'
            elif r == 2 and y - 1 >= 0:
                flag = 1
                return 'LEFT'
            elif r == 3 and y + 1 <= m:
                flag = 1
                return 'RIGHT'
    x = d.get()
    return x[1]

def simpleReflexAgent(matrix, x, y, count, n, m, visitedCell):
    if matrix[x][y] == 'd':
        matrix[x][y] = '-'
        print('Sucked at ', x, y)
    return ruleBook(matrix, x, y, count, n, m, visitedCell)


def vacuumCleaner(matrix, x, y, count, n, m, visitedCell):
    if count == (m + 1) * (n + 1):
        return
    if visitedCell[x][y] == 0:
        count += 1
    visitedCell[x][y] = 1
    action = simpleReflexAgent(matrix, x, y, count, n, m, visitedCell)
    if action == 'UP':
        print('going up from ', x, y, ' to ', x - 1, y)
        vacuumCleaner(matrix, x - 1, y, count, n, m, visitedCell)
    elif action == 'DOWN':
        print('going down from ', x, y, ' to ', x + 1, y)
        vacuumCleaner(matrix, x + 1, y, count, n, m, visitedCell)
    elif action == 'LEFT':
        print('going left from ', x, y, ' to ', x, y - 1)
        vacuumCleaner(matrix, x, y - 1, count, n, m, visitedCell)
    elif action == 'RIGHT':
        print('going right from ', x, y, ' to ', x, y + 1)
        vacuumCleaner(matrix, x, y + 1, count, n, m, visitedCell)

n, m = map(int, input().split())
matrix = []
visitedCell = []
for i in range(n):
    matrix.append([])
    visitedCell.append([])
    for j in range(m):
        x = random.randrange(2)
        visitedCell[i].append(0)
        if x == 0:
            matrix[i].append('-')
        else:
            matrix[i].append('d')
for i in range(len(matrix)):
    for j in range(len(matrix[0])):
        print(matrix[i][j], end = '')
    print()
x = random.randrange(n)
y = random.randrange(m)
count = 0
vacuumCleaner(matrix, x, y, count, n - 1, m - 1, visitedCell)
print(visitedCell)

