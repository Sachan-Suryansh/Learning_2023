#include <stdio.h>
#include <string.h>

void sortNames(char *names[], int size) {
    int i, j;
    char *temp;
    // Implementing bubble sort algorithm
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (strcmp(names[j], names[j + 1]) > 0) {
                // Swap names
                temp = names[j];
                names[j] = names[j + 1];
                names[j + 1] = temp;
            }
        }
    }
}

int main() {
    char *names[] = {
        "Santosh", "Amol", "Santosh Jain", "Kishore", "Rahul", "Amolkumar", "Hemant"
    };
    int size = sizeof(names) / sizeof(names[0]);

    printf("Names before sorting:\n");
    for (int i = 0; i < size; i++) {
        printf("%s\n", names[i]);
    }

    sortNames(names, size);

    printf("\nNames after sorting:\n");
    for (int i = 0; i < size; i++) {
        printf("%s\n", names[i]);
    }

    return 0;
}
