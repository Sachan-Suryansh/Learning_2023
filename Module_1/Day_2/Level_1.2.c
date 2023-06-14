#include <stdio.h>

void swap(void* a, void* b, size_t size) {
    char* temp = (char*)malloc(size);
    memcpy(temp, a, size);
    memcpy(a, b, size);
    memcpy(b, temp, size);
    free(temp);
}

int main() {
    int int1 = 10, int2 = 20;
    float float1 = 3.14, float2 = 2.71;
    char char1 = 'A', char2 = 'B';

    printf("Before swapping:\n");
    printf("int1 = %d, int2 = %d\n", int1, int2);
    printf("float1 = %.2f, float2 = %.2f\n", float1, float2);
    printf("char1 = %c, char2 = %c\n", char1, char2);

    swap(&int1, &int2, sizeof(int));
    swap(&float1, &float2, sizeof(float));
    swap(&char1, &char2, sizeof(char));

    printf("\nAfter swapping:\n");
    printf("int1 = %d, int2 = %d\n", int1, int2);
    printf("float1 = %.2f, float2 = %.2f\n", float1, float2);
    printf("char1 = %c, char2 = %c\n", char1, char2);

    return 0;
}
