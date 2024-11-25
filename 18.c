#include <stdio.h>

void find_k_closest_elements(int arr[], int n, int k, int x) {
    int low = 0, high = n - 1;
    while (high - low >= k) {
        if (x - arr[low] <= arr[high] - x) high--;
        else low++;
    }
    for (int i = low; i <= high; i++) printf("%d ", arr[i]);
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3, x = 6;
    find_k_closest_elements(arr, n, k, x);
    return 0;
}
