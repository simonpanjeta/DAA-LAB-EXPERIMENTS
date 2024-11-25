#include <stdio.h>

void activitySelection(int start[], int finish[], int n) {
    int i, j;
    printf("Selected activities: \n");
    i = 0;
    printf("%d ", i);
    for (j = 1; j < n; j++) {
        if (start[j] >= finish[i]) {
            printf("%d ", j);
            i = j;
        }
    }
}

int main() {
    int n, i;
    
    printf("Enter the number of activities: ");
    scanf("%d", &n);
    
    int start[n], finish[n];
    
    printf("Enter start times:\n");
    for (i = 0; i < n; i++) {
        printf("Start time of activity %d: ", i+1);
        scanf("%d", &start[i]);
    }

    printf("Enter finish times:\n");
    for (i = 0; i < n; i++) {
        printf("Finish time of activity %d: ", i+1);
        scanf("%d", &finish[i]);
    }

    activitySelection(start, finish, n);
    
    return 0;
}
