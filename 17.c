#include <stdio.h>

void find_pairs_with_difference(int arr[], int n, int diff) {
    int low = 0, high = 1;
    while (high < n) {
        int d = arr[high] - arr[low];
        if (d == diff) {
            printf("Pair: (%d, %d)\n", arr[low], arr[high]);
            low++;
            high++;
        } else if (d < diff) high++;
        else low++;
    }
}

int main() {
    int arr[] = {1, 5, 9, 12};
    int n = sizeof(arr) / sizeof(arr[0]);
    int diff = 4;
    find_pairs_with_difference(arr, n, diff);
    return 0;
}
