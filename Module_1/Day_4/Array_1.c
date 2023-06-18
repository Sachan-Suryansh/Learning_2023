#include <stdio.h>

#define SIZE 5

int main() {
    int arr[SIZE] = {5, 10, 15, 20, 25};
    int sum = 0;
    float average;
    int i;

    // Calculate the sum
    for (i = 0; i < SIZE; i++) {
        sum += arr[i];
    }

    // Calculate the average
    average = (float) sum / SIZE;

    printf("Sum: %d\n", sum);
    printf("Average: %.2f\n", average);

    return 0;
}
