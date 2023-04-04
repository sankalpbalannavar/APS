#include <stdio.h>
#include <stdbool.h>

#define N 8 // Size of chessboard

// Function to print the chessboard
void printBoard(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to check if a queen can be placed on board[row][col]
bool isSafe(int board[N][N], int row, int col) {
    int i, j;

    // Check if there is a queen in the same row
    for (i = 0; i < col; i++) {
        if (board[row][i]) {
            return false;
        }
    }

    // Check if there is a queen in the upper diagonal on left side
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j]) {
            return false;
        }
    }

    // Check if there is a queen in the lower diagonal on left side
    for (i = row, j = col; j >= 0 && i < N; i++, j--) {
        if (board[i][j]) {
            return false;
        }
    }

    return true;
}

// Function to solve N-Queens problem using backtracking
bool solveNQueens(int board[N][N], int col) {
    // Base case: If all queens are placed
    if (col >= N) {
        return true;
    }

    // Try placing queen in each row of the current column
    for (int i = 0; i < N; i++) {
        // Check if a queen can be placed on board[i][col]
        if (isSafe(board, i, col)) {
            // Place the queen on board[i][col]
            board[i][col] = 1;

            // Recur to place the rest of the queens
            if (solveNQueens(board, col+1)) {
                return true;
            }

            // If placing queen on board[i][col] doesn't lead to a solution,
            // remove the queen from board[i][col]
            board[i][col] = 0;
        }
    }

    // If the queen cannot be placed in any row of the current column, return false
    return false;
}

// Driver function to solve N-Queens problem
int main() {
    int board[N][N] = {0};

    if (solveNQueens(board, 0)) {
        printBoard(board);
    } else {
        printf("Solution does not exist.");
    }

    return 0;
}