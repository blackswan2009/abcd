#include <stdio.h>

#define MAX 100

float heap[MAX];     // Array to hold the heap (float type)
int heap_size;       // Global variable to store heap size

// Swap function: swaps values at two pointers
void floatch(float *a, float *b) {
    float temp = *a;
    *a = *b;
    *b = temp;
}

// Maxheapify(A, i)
void Maxheapify(float A[], int i) {
    int l = 2 * i;
    int r = 2 * i + 1;
    int largest;

    if (l <= heap_size && A[l] > A[i])
        largest = l;
    else
        largest = i;

    if (r <= heap_size && A[r] > A[largest])
        largest = r;

    if (largest != i) {
        floatch(&A[i], &A[largest]);
        Maxheapify(A, largest);
    }
}

// Build_max_heap(A)
void Build_max_heap(float A[], int length) {
    heap_size = length;
    for (int i = length / 2; i >= 1; i--) {
        Maxheapify(A, i);
    }
}

// Heap_sort(A)
void Heap_sort(float A[], int length) {
    Build_max_heap(A, length);
    for (int i = length; i >= 2; i--) {
        floatch(&A[1], &A[i]);
        heap_size = heap_size - 1;
        Maxheapify(A, 1);
    }
}

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 1; i <= n; i++) {
        scanf("%f", &heap[i]); // Reading float input
    }

    Heap_sort(heap, n);

    printf("Sorted array:\n");
    for (int i = 1; i <= n; i++) {
        printf("%.2f ", heap[i]); // Printing with 2 decimal places
    }
    printf("\n");

    return 0;
}

