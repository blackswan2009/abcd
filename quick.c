#include <stdio.h>
#include <stdlib.h>
float *a;
void interch(int i, int j) {
    float temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}
void Qsort(int m, int n) {
    if (m < n) {
        float key = a[m];
        int i = m + 1; 
        int j = n;       
        while (i <= j) { 
            while (a[i] < key && i <= n) {
                i++;
            }
            while (a[j] > key && j >= m) {
                j--;
            }
            if (i < j) {
                interch(i, j);
            } else {
                break;  
            }
        }
        interch(m, j);
        Qsort(m, j - 1); 
        Qsort(j + 1, n); 
    }
}
void print_array(int n) {
    for (int i = 0; i < n; i++) {
        printf("%.2f ", a[i]);
    }
    printf("\n");
}
int main() {
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    a = (float *)malloc(n * sizeof(float));
    printf("Enter %d elements: \n", n);
    for (int i = 0; i < n; i++) {
        scanf("%f", &a[i]);
    }
    printf("Original array: \n");
    print_array(n);
    Qsort(0, n - 1);
    printf("Sorted array: \n");
    print_array(n);
    free(a);
    return 0;
}
