#include <stdio.h>

int count_ones(int arr[], int n) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == 1) {
            if (mid == n - 1 || arr[mid + 1] == 0) return mid + 1;
            else low = mid + 1;
        } else high = mid - 1;
    }
    return 0;
}

int main() {
    int arr[] = {0, 0, 1, 1, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Number of 1's: %d\n", count_ones(arr, n));
    return 0;
}
