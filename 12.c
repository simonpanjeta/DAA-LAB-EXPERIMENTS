#include <stdio.h>

void find_floor_ceil_recursive(int arr[], int low, int high, int x, int *floor, int *ceil) {
    if (low > high) return;
    int mid = (low + high) / 2;
    if (arr[mid] == x) {
        *floor = *ceil = arr[mid];
        return;
    }
    if (arr[mid] < x) {
        *floor = arr[mid];
        find_floor_ceil_recursive(arr, mid + 1, high, x, floor, ceil);
    } else {
        *ceil = arr[mid];
        find_floor_ceil_recursive(arr, low, mid - 1, x, floor, ceil);
    }
}

int main() {
    int arr[] = {1, 2, 8, 10, 10, 12, 19};
    int n = sizeof(arr) / sizeof(arr[0]);
    int floor = -1, ceil = -1;
    find_floor_ceil_recursive(arr, 0, n - 1, 5, &floor, &ceil);
    printf("Floor: %d, Ceil: %d\n", floor, ceil);
    return 0;
}
