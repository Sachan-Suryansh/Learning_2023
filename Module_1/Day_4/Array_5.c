//Diff between even & odd indexed elements
#include <stdio.h>

#define SIZE 10

int main() {
    int arr[SIZE] = {64, 84, 21, 36, 17, 90, 77, 10, 48, 55};
    int evenSum = 0;
    int oddSum = 0;


    for (int i = 0; i < SIZE; i++) {
        if (i % 2 == 0) {
            evenSum += arr[i];
        } else {
            oddSum += arr[i];
        }
    }

    int difference = evenSum - oddSum;
    printf("Difference between even-indexed and odd-indexed elements: %d\n", difference);

    return 0;
}
