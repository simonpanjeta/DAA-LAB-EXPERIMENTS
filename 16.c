#include <stdio.h>

int find_odd_occurrence(int arr[], int n) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (mid % 2 == 0) {
            if (arr[mid] == arr[mid + 1]) low = mid + 2;
            else high = mid - 1;
        } else {
            if (arr[mid] == arr[mid - 1]) low = mid + 1;
            else high = mid - 1;
        }
    }
    return arr[low];
}

int main() {
    int arr[] = {1, 1, 2, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Odd occurring element: %d\n", find_odd_occurrence(arr, n));
    return 0;
}
