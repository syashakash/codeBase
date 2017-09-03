def lps(string):
    n = len(string)
    L = [[0 for x in range(n)] for x in range(n)]
    for i in range(n):
        L[i][i] = 1
    for cl in range(2, n + 1):
        for i in range(n - cl + 1):
            j = i + cl - 1
            if string[i] == string[j] and cl == 2:
                L[i][j] = 2
            elif string[i] == string[j]:
                L[i][j] = L[i + 1][j - 1] + 2
            else:
                L[i][j] = max(L[i][j - 1], L[i + 1][j]);
 
    return L[0][n - 1]
 
"""
    The recursive method
"""

"""
def recLps(string, i, j):
    if i == j:
        return 1

    if i == j - 1 and string[i] == string[j]:
        return 2
    elif string[i] == string[j]:
        return recLps(string, i + 1, j - 1)
    else:
        return max(recLps(string, i + 1, j), recLps(string, i, j - 1))
"""
def main():
    string = input()
    print("The longest pallindromic subsequence in string is : %d" %lps(string))
 
if __name__ == "__main__":
    main()