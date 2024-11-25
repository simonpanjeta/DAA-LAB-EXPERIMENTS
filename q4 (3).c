#include <stdio.h>

#define MAX_ITEMS 100

// Greedy Approach: 0/1 Knapsack 
float greedyKnapsack(int values[], int weights[], int n, int W) {
    float ratio[n];
    int i, j;
    for (i = 0; i < n; i++) {
        ratio[i] = (float)values[i] / weights[i];
    }

    // Sort items by value/weight ratio in descending order
    for (i = 0; i < n-1; i++) {
        for (j = i+1; j < n; j++) {
            if (ratio[i] < ratio[j]) {
                float tempRatio = ratio[i];
                ratio[i] = ratio[j];
                ratio[j] = tempRatio;

                int tempValue = values[i];
                values[i] = values[j];
                values[j] = tempValue;

                int tempWeight = weights[i];
                weights[i] = weights[j];
                weights[j] = tempWeight;
            }
        }
    }

    int currentWeight = 0;
    float totalValue = 0.0;

    // Pick items based on greedy approach
    for (i = 0; i < n; i++) {
        if (currentWeight + weights[i] <= W) {
            currentWeight += weights[i];
            totalValue += values[i];
        }
    }

    return totalValue;
}

// Dynamic Programming Approach: 0/1 Knapsack (Optimal Solution)
int knapsack(int values[], int weights[], int n, int W) {
    int dp[n+1][W+1];
    int i, w;

    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            } else if (weights[i-1] <= w) {
                dp[i][w] = (values[i-1] + dp[i-1][w - weights[i-1]] > dp[i-1][w]) ? 
                            values[i-1] + dp[i-1][w - weights[i-1]] : dp[i-1][w];
            } else {
                dp[i][w] = dp[i-1][w];
            }
        }
    }

    return dp[n][W];
}

int main() {
    int n, W, i;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    int values[n], weights[n];

    printf("Enter the values and weights of the items:\n");
    for (i = 0; i < n; i++) {
        printf("Item %d - Value: ", i + 1);
        scanf("%d", &values[i]);
        printf("Item %d - Weight: ", i + 1);
        scanf("%d", &weights[i]);
    }

    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &W);

    printf("\nGreedy Approach: Maximum value = %.2f\n", greedyKnapsack(values, weights, n, W));
    printf("Dynamic Programming Approach: Maximum value = %d\n", knapsack(values, weights, n, W));

    return 0;
}
