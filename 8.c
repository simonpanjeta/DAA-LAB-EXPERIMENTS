#include <stdio.h>

int search_nearly_sorted(int arr[], int n, int target) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == target) return mid;
        if (mid - 1 >= low && arr[mid - 1] == target) return mid - 1;
        if (mid + 1 <= high && arr[mid + 1] == target) return mid + 1;
        if (arr[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int main() {
    int arr[] = {5, 10, 30, 20, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 30;
    printf("Element found at index: %d\n", search_nearly_sorted(arr, n, target));
    return 0;
}
