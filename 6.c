#include <stdio.h>

int find_min(int arr[], int n) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] <= arr[high]) high = mid - 1;
        else low = mid + 1;
    }
    return arr[low];
}

int main() {
    int arr[] = {15, 18, 2, 3, 6, 12};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Smallest element: %d\n", find_min(arr, n));
    return 0;
}
