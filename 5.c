#include <stdio.h>

int count_occurrences(int arr[], int n, int target) {
    int first = first_occurrence(arr, 0, n - 1, target);
    if (first == -1) return 0;
    int last = last_occurrence(arr, 0, n - 1, target);
    return last - first + 1;
}

int main() {
    int arr[] = {1, 2, 2, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 2;
    printf("Occurrences: %d\n", count_occurrences(arr, n, target));
    return 0;
}
