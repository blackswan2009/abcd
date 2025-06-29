#include <stdio.h>
void intch(float *a, float *b) {
    float temp = *a;
    *a = *b;
    *b = temp;
}
void Bubble_sort(float a[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                intch(&a[j], &a[j + 1]); 
            }
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
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    float a[n];
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%f", &a[i]);
    }
    printf("Original array: \n");
    print_array(a, n);
    Bubble_sort(a, n);
    printf("Sorted array: \n");
    print_array(a, n);
    return 0;
}
