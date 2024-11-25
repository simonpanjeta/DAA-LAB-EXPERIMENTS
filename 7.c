#include <stdio.h>

void find_floor_ceil(int arr[], int n, int x) {
    int low = 0, high = n - 1;
    int floor = -1, ceil = -1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == x) {
            floor = arr[mid];
            ceil = arr[mid];
            break;
        }
        if (arr[mid] < x) {
            floor = arr[mid];
            low = mid + 1;
        } else {
            ceil = arr[mid];
            high = mid - 1;
        }
    }
    printf("Floor: %d, Ceil: %d\n", floor, ceil);
}

int main() {
    int arr[] = {1, 2, 8, 10, 10, 12, 19};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 5;
    find_floor_ceil(arr, n, x);
    return 0;
}
