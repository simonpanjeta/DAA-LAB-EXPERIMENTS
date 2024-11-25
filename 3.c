#include <stdio.h>

int first_occurrence(int arr[], int low, int high, int target) {
    int result = -1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == target) {
            result = mid;
            high = mid - 1;
        } else if (arr[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return result;
}

int main() {
    int arr[] = {1, 2, 2, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 2;
    printf("First occurrence at index: %d\n", first_occurrence(arr, 0, n - 1, target));
    return 0;
}
