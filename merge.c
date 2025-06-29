#include <stdio.h>
#include <stdlib.h>
#define N 1000000  
void Merge(float a[], int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;
    float *L = (float *)malloc((n1 + 1) * sizeof(float));
    float *R = (float *)malloc((n2 + 1) * sizeof(float));
    for (int i = 0; i < n1; i++) {
        L[i] = a[p + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = a[q + 1 + j];
    }
    L[n1] = R[n2] = N; 
    int i = 0, j = 0;
    for (int k = p; k <= r; k++) {
        if (L[i] <= R[j]) {
            a[k] = L[i];
            i++;
        } else {
            a[k] = R[j];
            j++;
        }
    }
    free(L);
    free(R);
}
void Merge_sort(float a[], int p, int r) {
    if (p < r) {
        int q = (p + r) / 2;
        Merge_sort(a, p, q);
        Merge_sort(a, q + 1, r);
        Merge(a, p, q, r);
    }
}
void print_array(float a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%.2f ", a[i]);
    }
    printf("\n");
}
int main() {
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    float *a = (float *)malloc(n * sizeof(float));
    printf("Enter %d float elements: \n", n);
    for (int i = 0; i < n; i++) {
        scanf("%f", &a[i]);
    }
   printf("Original array: \n");
    print_array(a, n);
   Merge_sort(a, 0, n - 1);
   printf("Sorted array: \n");
    print_array(a, n);
   free(a);
    return 0;
}

