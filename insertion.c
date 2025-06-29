#include <stdio.h>

int main() {
    int n;

    // Ask user for number of elements
    printf("Enter number of elements: ");
    scanf("%d", &n);

    // Declare array with 1-based indexing (extra 1 space)
    double a[n + 1];

    // Input array elements (start from index 1)
    printf("Enter %d numbers:\n", n);
    for (int i = 1; i <= n; i++) {
        scanf("%lf", &a[i]);
    }

    // Insertion_sort(a, n)
    for (int j = 2; j <= n; j++) {
        double key = a[j];
        int i = j - 1;
        while (i > 0 && key < a[i]) {
            a[i + 1] = a[i];
            i = i - 1;
        }
        a[i + 1] = key;
    }

    // Output sorted array
    printf("Sorted array:\n");
    for (int i = 1; i <= n; i++) {
        printf("%g ", a[i]);  // %g formats both int and float nicely
    }
    printf("\n");

    return 0;
}
