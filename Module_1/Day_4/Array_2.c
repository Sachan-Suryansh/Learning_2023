#include <stdio.h>

#define SIZE 5 // Size of the array

int main() {
    int arr[SIZE] = {5, 10, 15, 20, 25};
    int min = arr[0]; // Assume the first element is the minimum
    int max = arr[0]; // Assume the first element is the maximum
    int i;

    // Find the minimum and maximum
    for (i = 1; i < SIZE; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    printf("Minimum: %d\n", min);
    printf("Maximum: %d\n", max);

    return 0;
}
