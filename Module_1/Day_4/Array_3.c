#include <stdio.h>

#define SIZE 5 // Size of the array

int main() {
    int arr[SIZE] = {1, 2, 3, 4, 5};
    int start = 0; // Start index of the array
    int end = SIZE - 1; // End index of the array

    // Reverse the array
    while (start < end) {
        // Swap elements
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        // Move start index towards the center
        start++;

        // Move end index towards the center
        end--;
    }

    // Print the reversed array
    printf("Reversed array: ");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
