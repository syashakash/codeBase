
#include <bits/stdc++.h>
 using namespace std;
/* A utility function to print solution */
void printSolution(int **board, int N)
{
    static  int k = 1;
    printf("%d-\n",k++);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf(" %d ", board[i][j]);
        printf("\n");
    }
    printf("\n");
}
 
/* A utility function to check if a queen can
be placed on board[row][col]. Note that this
function is called when "col" queens are
already placed in columns from 0 to col -1.
So we need to check only left side for
attacking queens */
bool isSafe(int **board, int N, int row, int col)
{
    int i, j;
 
    /* Check this row on left side */
    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;
 
    /* Check upper diagonal on left side */
    for (i=0; i>=0 && j>=0; i--, j--)
        if (board[i][j])
            return false;
    i = row, j = col;
    /* Check lower diagonal on left side */
    while(i < N && j >=0 ) {
        if(board[i][j]) return false;
        i++;
        j--;
    }
 
    return true;
}
 
/* A recursive utility function to solve N
Queen problem */
bool solveNQUtil(int **board, int N, int col)
{
    /* base case: If all queens are placed
    then return true */
    if (col == N )
    {
        printSolution(board, N);
        return true;
    }
 
    /* Consider this column and try placing
    this queen in all rows one by one */
    for (int i = 0; i < N; i++)
    {
        /* Check if queen can be placed on
        board[i][col] */
        if ( isSafe(board, N, i, col) )
        {
            /* Place this queen in board[i][col] */
            board[i][col] = 1;
 
            /* recur to place rest of the queens */
            solveNQUtil(board, N, col + 1) ;
 
            // below commented statement is replaced
            // by above one
            /* if ( solveNQUtil(board, col + 1) )
                 return true;*/
 
            /* If placing queen in board[i][col]
            doesn't lead to a solution, then
            remove queen from board[i][col] */
            board[i][col] = 0; // BACKTRACK
        }
    }
 
    /* If queen can not be place in any row in
        this column col then return false */
    return false;
}
 
/* This function solves the N Queen problem using
Backtracking. It mainly uses solveNQUtil() to
solve the problem. It returns false if queens
cannot be placed, otherwise return true and
prints placement of queens in the form of 1s.
Please note that there may be more than one
solutions, this function prints one of the
feasible solutions.*/
void solveNQ(int n)
{
    int **board = new int*[n];
    for(int i = 0; i < n; i++) {
        board[i] = new int[n];
    }
    for(int i = 0 ; i < n; i++) {
        for(int j = 0; j < n; j++) {
            board[i][j] = 0;
        }
    }
    if (solveNQUtil(board, n, 0))
    {
        printf("Solution does not exist");
        return ;
    }
 
    return ;
}

int main()
{
    int n;
    cin>>n;
    solveNQ(n);
    return 0;
}