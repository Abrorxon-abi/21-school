#include <stdio.h>

#define N 10

int input(int *a, int n);
void quick_sort(int *a, int low, int high);
int partition(int *a, int low, int high);
void swap(int *a, int *b);
void heap_sort(int *a, int n);
void build_heap(int *a, int n);
void heapify(int *a, int n, int i);
void output(int *a, int n);

int main() {
    int data[N];

    if (input(data, N)) {
        int data_copy[N];

        // Сортировка с использованием быстрой сортировки
        for (int i = 0; i < N; i++) {
            data_copy[i] = data[i];
        }
        quick_sort(data_copy, 0, N - 1);
        output(data_copy, N);

        // Сортировка с использованием пирамидальной сортировки
        for (int i = 0; i < N; i++) {
            data_copy[i] = data[i];
        }
        heap_sort(data_copy, N);
        output(data_copy, N);
    } else {
        printf("n/a\n");
    }

    return 0;
}

int input(int *a, int n) {
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &a[i]) != 1) {
            return 0;  // Invalid input
        }
    }

    return 1;  // Input successfully read
}

void quick_sort(int *a, int low, int high) {
    if (low < high) {
        int pivot_index = partition(a, low, high);
        quick_sort(a, low, pivot_index - 1);
        quick_sort(a, pivot_index + 1, high);
    }
}

int partition(int *a, int low, int high) {
    int pivot = a[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (a[j] <= pivot) {
            i++;
            swap(&a[i], &a[j]);
        }
    }

    swap(&a[i + 1], &a[high]);
    return i + 1;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heap_sort(int *a, int n) {
    build_heap(a, n);

    for (int i = n - 1; i > 0; i--) {
        swap(&a[0], &a[i]);
        heapify(a, i, 0);
    }
}

void build_heap(int *a, int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(a, n, i);
    }
}

void heapify(int *a, int n, int i) {
    int largest = i;
    int left_child = 2 * i + 1;
    int right_child = 2 * i + 2;

    if (left_child < n && a[left_child] > a[largest]) {
        largest = left_child;
    }

    if (right_child < n && a[right_child] > a[largest]) {
        largest = right_child;
    }

    if (largest != i) {
        swap(&a[i], &a[largest]);
        heapify(a, n, largest);
    }
}

void output(int *a, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}
