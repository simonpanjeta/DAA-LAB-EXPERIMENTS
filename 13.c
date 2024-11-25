#include <stdio.h>

void find_frequency(int arr[], int n) {
    int low = 0;
    while (low < n) {
        int target = arr[low];
        int first = first_occurrence(arr, 0, n - 1, target);
        int last = last_occurrence(arr, 0, n - 1, target);
        printf("%d occurs %d times\n", target, last - first + 1);
        low = last + 1;
    }
}

int main() {
    int arr[] = {1, 2, 2, 2, 3, 3, 4, 4, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    find_frequency(arr, n);
    return 0;
}
