#include <stdio.h>

void swapAlternateElements(int arr[], int size) {
    for (int i = 0; i < size - 1; i += 2) {
        int temp = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = temp;
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int a[] = {10, 20, 30, 40, 50};
    int size = sizeof(a) / sizeof(a[0]);

    printf("Original array: ");
    printArray(a, size);

    swapAlternateElements(a, size);

    printf("Modified array: ");
    printArray(a, size);

    return 0;
}
