#include <stdio.h>
#include <limits.h>

int mcm(int p[], int n)
{
    int m[n][n];
    int i, j, k, L, q;

    for (i = 1; i < n; i++)
        m[i][i] = 0;

    printf("Initial m matrix:\n");
    for (i = 1; i < n; i++) {
        for (j = 1; j < n; j++) {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    for (L = 2; L < n; L++) {
        printf("Processing chain length %d:\n", L);
        for (i = 1; i < n - L + 1; i++) {
            j = i + L - 1;
            m[i][j] = INT_MAX;
            for (k = i; k <= j - 1; k++) {
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                printf("  Considering split at k = %d: cost = m[%d][%d] + m[%d][%d] + %d * %d * %d = %d + %d + %d = %d\n",
                    k, i, k, k + 1, j, p[i - 1], p[k], p[j], m[i][k], m[k + 1][j], p[i - 1] * p[k] * p[j], q);
                if (q < m[i][j]) {
                    m[i][j] = q;
                    printf("  Updating m[%d][%d] = %d\n", i, j, m[i][j]);
                }
            }
        }
        printf("\n");
        printf("M matrix after processing chain length %d:\n", L);
        for (i = 1; i < n; i++) {
            for (j = 1; j < n; j++) {
                printf("%d ", m[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }

    return m[1][n - 1];
}

int main()
{
    int n;
    printf("Enter the number of matrices: ");
    scanf("%d", &n);

    int arr[n + 1];
    printf("Enter the dimensions of the matrices (p0 p1 ... pn): ");
    for (int i = 0; i <= n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Minimum number of multiplications is %d\n", mcm(arr, n + 1));

    return 0;
}
