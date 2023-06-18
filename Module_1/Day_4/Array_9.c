//Linear search
#include <stdio.h>

int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;  // Element found
        }
    }
    return -1;  // Element not found
}

int main() {
    int arr[] = {30, 40, 10, 60, 50, 20, 70, 90, 80, 25};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 90;

    int result = linearSearch(arr, size, target);

    if (result != -1) {
        printf("Element %d found at index %d\n", target, result);
    } else {
        printf("Element %d not found in the array\n", target);
    }

    return 0;
}
