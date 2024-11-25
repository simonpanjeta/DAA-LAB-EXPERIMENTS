#include <stdio.h>

int division(int dividend, int divisor) {
    int low = 0, high = dividend;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (mid * divisor == dividend) return mid;
        if (mid * divisor < dividend) low = mid + 1;
        else high = mid - 1;
    }
    return high;
}

int main() {
    int dividend = 10, divisor = 2;
    printf("Result: %d\n", division(dividend, divisor));
    return 0;
}
