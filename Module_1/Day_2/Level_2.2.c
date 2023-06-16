#include <stdio.h>

int compareBoxes(int A[], int B[], int size) {
    int count[size];
    for (int i = 0; i < size; i++) {
        count[i] = 0;
    }
    for (int i = 0; i < size; i++) {
        int item = A[i];
        int j;
        for (j = 0; j < size; j++) {
            if (B[j] == item && count[j] == 0) {
                count[j] = 1;
                break;
            }
        }
        if (j == size || count[j] == 1) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int A[] = {200, 10, -90};
    int B[] = {-90, 200, 10};
    int size = sizeof(A) / sizeof(A[0]);

    int result = compareBoxes(A, B, size);

    if (result == 1) {
        printf("The boxes have a one-to-one mapping of items.\n");
    } else {
        printf("The boxes do not have a one-to-one mapping of items.\n");
    }

    return 0;
}
