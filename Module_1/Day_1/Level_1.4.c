#include <stdio.h>

int main() {
    float operand1, operand2;
    char operator;

    printf("Enter Number1: ");
    scanf("%f", &operand1);

    printf("Enter the operator: ");
    scanf(" %c", &operator);

    printf("Enter Number2: ");
    scanf("%f", &operand2);

    float result;

    if (operator == '+') {
        result = operand1 + operand2;
    } else if (operator == '-') {
        result = operand1 - operand2;
    } else if (operator == '*') {
        result = operand1 * operand2;
    } else if (operator == '/') {
        if (operand2 != 0) {
            result = operand1 / operand2;
        } else {
            printf("Error: Division by zero is not allowed.\n");
            return 0;
        }
    } else {
        printf("Error: Invalid operator.\n");
        return 0;
    }

    printf("Result: %.2f\n", result);

    return 0;
}
