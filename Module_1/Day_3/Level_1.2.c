#include <stdio.h>

void printBits(unsigned int num);

int main() {
    unsigned int num;
    scanf("%u", &num);
    printf("Binary representation: ");
    printBits(num);

    return 0;
}

void printBits(unsigned int num) {
    unsigned int mask = 1 << 31;

    for (int i = 0; i < 32; i++) {
        if (num & mask)
            printf("1");
        else
            printf("0");
        mask >>= 1;
    }

    printf("\n");
}
