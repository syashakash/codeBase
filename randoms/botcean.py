
import math

def permutations(objects):
    if len(objects) <= 1:
        yield objects
    else:
        for perm in permutations(objects[1 : ]):
            for i in range(len(objects)):
                yield perm[ : i] + objects[0 : 1] + perm[i : ]
                
def path_length(path):
    distance = 0
    for i in range(len(path) - 1):
        distance += abs(path[i][0] - path[i + 1][0]) + abs(path[i][1] - path[i + 1][1])
    return distance

def brute_force_tsp(posr, posc, board, m, n):
    # get list of dirty cells
    dirty = []
    for i in range(len(board)):
        for j in range(len(board[0])):
            if board[i][j] == "d":
                dirty.append((i, j))
    
    # for all possible orderings of the dirty cells
    min_length = m * n + 1
    min_path = None
    for path in permutations(dirty):
        # calculate length of path
        length = path_length([(posr, posc)] + path)
        
        # if less than min, replace min
        if length < min_length:
            min_length = length
            min_path = path
    
    return min_path
    
def next_move(posr, posc, board, m, n):
    if board[posr][posc] == "d":
        board[posr][posc] = "-"
        print("CLEAN")
        return
        
    min_path = brute_force_tsp(posr, posc, board, m, n)
    if posr != min_path[0][0]:
        if posr > min_path[0][0]:
            print("UP")
        else:
            print("DOWN")
    else:
        if posc > min_path[0][1]:
            print("LEFT")
        else:
            print("RIGHT")

if __name__ == "__main__":
    m, n = map(int, input().split())
    pos = [int(i) for i in input().strip().split()]
    board = [[j for j in input().strip()] for i in range(m)]
    next_move(pos[0], pos[1], board, m, n)