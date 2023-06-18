//Decimal to Binary/Octal/Hex Conversion
#include <stdio.h>

#define SIZE 5

// Function to convert decimal to binary
void decimalToBinary(int decimal) {
    if (decimal == 0) {
        return;
    } else {
        decimalToBinary(decimal / 2);
        printf("%d", decimal % 2);
    }
}

int main() {
    int decimalArray[SIZE] = {29, 14, 7, 3, 1};

    printf("Decimal\tBinary\t\tOctal\tHexadecimal\n");
    printf("---------------------------------------------\n");

    for (int i = 0; i < SIZE; i++) {
        int decimal = decimalArray[i];

        // Convert decimal to binary
        printf("%d\t", decimal);
        decimalToBinary(decimal);
        printf("\t");

        // Convert decimal to octal
        printf("%o\t", decimal);

        // Convert decimal to hexadecimal
        printf("%X\n", decimal);
    }

    return 0;
}
