#include <stdio.h>
void intch(float *a, float *b) {
    float temp = *a;
    *a = *b;
    *b = temp;
}
void Selection_sort(float a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int j = i;
        for (int k = i + 1; k < n; k++) {
            if (a[k] < a[j]) {
                j = k;
            }
        }
        if (i != j) {
            intch(&a[i], &a[j]); 
        }
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
   float a[n];
   printf("Enter %d elements: \n", n);
    for (int i = 0; i < n; i++) {
        scanf("%f", &a[i]); 
    }
   printf("Original array: \n");
    print_array(a, n);
   Selection_sort(a, n);
   printf("Sorted array: \n");
    print_array(a, n);
   return 0;
}

