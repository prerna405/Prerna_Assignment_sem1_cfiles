/*
 * Problem Name          : N-Queens
 * LeetCode Problem No.  : 51
 * Topic                 : ALGORITHMS
 * Problem Link          : https://leetcode.com/problems/n-queens/
 *
 * Problem Description:
 * Given an integer n, determine all possible ways to position
 * n queens on an n x n chessboard such that no two queens can
 * attack each other.
 *
 * A valid arrangement ensures that no two queens share the
 * same row, column, or diagonal.
 */

#include <stdlib.h>
#include <string.h>

void backtrack(int row, int n, char **board,
               int *cols, int *diag1, int *diag2,
               char ****result, int *returnSize, int *capacity) {

    if (row == n) {

        if (*returnSize == *capacity) {
            *capacity *= 2;
            *result = realloc(*result, (*capacity) * sizeof(char **));
        }

        char **solution = malloc(n * sizeof(char *));

        for (int i = 0; i < n; i++) {
            solution[i] = malloc((n + 1) * sizeof(char));
            strcpy(solution[i], board[i]);
        }

        (*result)[(*returnSize)++] = solution;
        return;
    }

    for (int col = 0; col < n; col++) {

        int d1 = row - col + n - 1;
        int d2 = row + col;

        if (cols[col] || diag1[d1] || diag2[d2])
            continue;

        board[row][col] = 'Q';
        cols[col] = 1;
        diag1[d1] = 1;
        diag2[d2] = 1;

        backtrack(row + 1, n, board, cols, diag1, diag2,
                  result, returnSize, capacity);

        board[row][col] = '.';
        cols[col] = 0;
        diag1[d1] = 0;
        diag2[d2] = 0;
    }
}

char*** solveNQueens(int n, int* returnSize, int** returnColumnSizes) {

    int capacity = 16;

    char ***result = malloc(capacity * sizeof(char **));

    char **board = malloc(n * sizeof(char *));

    for (int i = 0; i < n; i++) {
        board[i] = malloc((n + 1) * sizeof(char));
        memset(board[i], '.', n);
        board[i][n] = '\0';
    }

    int *cols = calloc(n, sizeof(int));
    int *diag1 = calloc(2 * n - 1, sizeof(int));
    int *diag2 = calloc(2 * n - 1, sizeof(int));

    *returnSize = 0;

    backtrack(0, n, board, cols, diag1, diag2,
              &result, returnSize, &capacity);

    *returnColumnSizes = malloc((*returnSize) * sizeof(int));

    for (int i = 0; i < *returnSize; i++) {
        (*returnColumnSizes)[i] = n;
    }

    return result;
}
