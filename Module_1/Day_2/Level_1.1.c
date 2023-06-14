#include <stdio.h>

void printExponent(double x) {
    unsigned long long int bits = *(unsigned long long int*) &x;
    unsigned int exponent = (bits >> 52) & 0x7FF;

    printf("Exponent in Hex: 0x%X\n", exponent);

    printf("Exponent in Binary: ");
    for (int i = 10; i >= 0; i--) {
        printf("%d", (exponent >> i) & 1);
    }
    printf("\n");
}

int main() {
    double x = 0.7;
    printExponent(x);

    return 0;
}
