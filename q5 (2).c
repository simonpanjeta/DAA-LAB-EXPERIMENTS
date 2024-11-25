// SUM OF SUBSET

#include <stdio.h>
#include <stdbool.h>

bool subsetSum(int arr[], int n, int sum, int subset[], int* subsetSize) {
    if (sum == 0) {
        return true;
    }
    if (n == 0 || sum < 0) {
        return false;
    }

    if (subsetSum(arr, n - 1, sum, subset, subsetSize)) {
        return true;
    }

    if (arr[n - 1] <= sum) {
        subset[(*subsetSize)++] = arr[n - 1];
        if (subsetSum(arr, n - 1, sum - arr[n - 1], subset, subsetSize)) {
            return true;
        }
        (*subsetSize)--;  
    }

    return false;
}

int main() {
    int n, sum;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the sum to check: ");
    scanf("%d", &sum);

    int subset[n];
    int subsetSize = 0;

    if (subsetSum(arr, n, sum, subset, &subsetSize)) {
        printf("Subset with the given sum: ");
        for (int i = 0; i < subsetSize; i++) {
            printf("%d ", subset[i]);
        }
        printf("\n");
    } else {
        printf("No subset with the given sum exists.\n");
    }

    return 0;
}


// N QUEEN PROBLEM

#include <stdio.h>
#include <stdbool.h>

#define MAX_N 30  

int board[MAX_N];
int leftDiagonal[2 * MAX_N - 1], rightDiagonal[2 * MAX_N - 1], column[MAX_N];

void printSolution(int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i] == j)
                printf("Q ");
            else
                printf(". ");
        }
        printf("\n");
    }
}

bool isSafe(int row, int col, int N) {
    return !column[col] && !leftDiagonal[row - col + N - 1] && !rightDiagonal[row + col];
}

void placeQueen(int row, int col, int N) {
    column[col] = 1;
    leftDiagonal[row - col + N - 1] = 1;
    rightDiagonal[row + col] = 1;
    board[row] = col;
}

void removeQueen(int row, int col, int N) {
    column[col] = 0;
    leftDiagonal[row - col + N - 1] = 0;
    rightDiagonal[row + col] = 0;
}

bool solveNQ(int row, int N) {
    if (row == N) {
        printSolution(N);
        return true;
    }

    for (int col = 0; col < N; col++) {
        if (isSafe(row, col, N)) {
            placeQueen(row, col, N);
            if (solveNQ(row + 1, N))
                return true;
            removeQueen(row, col, N);
        }
    }

    return false;
}

int main() {
    int N;
    printf("Enter the value of N (size of the board): ");
    scanf("%d", &N);

    if (N > MAX_N) {
        printf("N is too large! Maximum supported N is %d.\n", MAX_N);
        return 0;
    }

    for (int i = 0; i < N; i++) {
        board[i] = -1; 
    }

    if (!solveNQ(0, N)) {
        printf("Solution does not exist.\n");
    }

    return 0;
}
