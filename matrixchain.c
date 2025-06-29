#include <stdio.h>
#include <limits.h>
#define MAX 100
int m[MAX][MAX], s[MAX][MAX];
void printOptimalParens(int i, int j) {
    if (i == j) printf("A%d", i);
    else {
        printf("(");
        printOptimalParens(i, s[i][j]);
        printOptimalParens(s[i][j] + 1, j);
        printf(")");
    }
}
void matrixChainOrder(int p[], int n) {
    for (int i = 1; i < n; i++) m[i][i] = 0;
    for (int l = 2; l < n; l++)
        for (int i = 1, j; (j = i + l - 1) < n; i++) {
            m[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j]) m[i][j] = q, s[i][j] = k;
            }
        }
    printf("\nMinimum number of multiplications: %d\n", m[1][n - 1]);
    printf("Optimal Parenthesization: ");
    printOptimalParens(1, n - 1);
    printf("\n");
}
int main() {
    int p[MAX], n;
    printf("Enter number of matrices: ");
    scanf("%d", &n);
    printf("Enter %d dimensions:\n", n + 1);
    for (int i = 0; i <= n; i++) scanf("%d", &p[i]);
    matrixChainOrder(p, n + 1);
    return 0;
}
