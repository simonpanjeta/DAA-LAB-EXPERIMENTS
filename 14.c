#include <stdio.h>

double square_root(int n) {
    double low = 0, high = n, mid;
    while (high - low > 0.0001) {
        mid = (low + high) / 2;
        if (mid * mid > n) high = mid;
        else low = mid;
    }
    return (low + high) / 2;
}

int main() {
    int n = 16;
    printf("Square root: %lf\n", square_root(n));
    return 0;
}
