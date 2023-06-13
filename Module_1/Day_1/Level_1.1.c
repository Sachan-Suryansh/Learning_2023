#include <stdio.h>

int findMax(int a, int b) {
    int max;

    if (a > b) {
        max = a;
    } else {
        max = b;
    }

    return max;
}

int main() {
    int num1, num2;
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    int result = findMax(num1, num2);
    printf("The maximum number is: %d\n", result);

    return 0;
}
