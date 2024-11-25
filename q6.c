#include <stdio.h>
#include <stdlib.h>

int n, W;
int *weights, *values;

int maxValBacktracking = 0;

void knapsackBacktracking(int i, int currentWeight, int currentValue) {
    if (i == n) {
        if (currentWeight <= W && currentValue > maxValBacktracking) {
            maxValBacktracking = currentValue;
        }
        return;
    }

    knapsackBacktracking(i + 1, currentWeight, currentValue);
    if (currentWeight + weights[i] <= W) {
        knapsackBacktracking(i + 1, currentWeight + weights[i], currentValue + values[i]);
    }
}

// Branch and Bound approach

typedef struct {
    int level, profit, weight;
} Node;

int bound(Node u) {
    if (u.weight >= W)
        return 0;
    int result = u.profit;
    int j = u.level + 1;
    int totalWeight = u.weight;
    while (j < n && totalWeight + weights[j] <= W) {
        totalWeight += weights[j];
        result += values[j];
        j++;
    }
    if (j < n)
        result += (W - totalWeight) * values[j] / weights[j];
    return result;
}

int knapsackBranchBound() {
    Node u, v;
    u.level = -1;
    u.profit = u.weight = 0;
    int maxProfit = 0;
    Node *queue = (Node*) malloc(n * sizeof(Node)); 
    int front = 0, rear = 0;

    queue[rear++] = u;

    while (front < rear) {
        u = queue[front++];

        if (u.level == n - 1)
            continue;

        v.level = u.level + 1;
        v.weight = u.weight + weights[v.level];
        v.profit = u.profit + values[v.level];

        if (v.weight <= W && v.profit > maxProfit)
            maxProfit = v.profit;

        if (bound(v) > maxProfit)
            queue[rear++] = v;

        v.weight = u.weight;
        v.profit = u.profit;

        if (bound(v) > maxProfit)
            queue[rear++] = v;
    }

    free(queue);  
    return maxProfit;
}

int main() {
    printf("Enter number of items: ");
    scanf("%d", &n);
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &W);

    weights = (int*) malloc(n * sizeof(int));  
    values = (int*) malloc(n * sizeof(int));   

    printf("Enter weights and values of the items:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &weights[i], &values[i]);
    }

    // Backtracking approach
    maxValBacktracking = 0;
    knapsackBacktracking(0, 0, 0);
    printf("Backtracking Maximum Value: %d\n", maxValBacktracking);

    // Branch & Bound approach
    int maxValBranchBound = knapsackBranchBound();
    printf("Branch & Bound Maximum Value: %d\n", maxValBranchBound);

    return 0;
}
