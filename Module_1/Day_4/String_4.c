//Rotate String
#include <stdio.h>
#include <string.h>

void rotateLeft(char* str, int k) {
    int len = strlen(str);
    k = k % len;

    for (int i = 0; i < k; i++) {
        char temp = str[0];
        for (int j = 0; j < len - 1; j++) {
            str[j] = str[j + 1];
        }
        str[len - 1] = temp;
    }
}

void rotateRight(char* str, int k) {
    int len = strlen(str);
    k = k % len;

    for (int i = 0; i < k; i++) {
        char temp = str[len - 1];
        for (int j = len - 1; j > 0; j--) {
            str[j] = str[j - 1];
        }
        str[0] = temp;
    }
}

int main() {
    char str[] = "abcdxyz";
    int k = 2;

    printf("Original String: %s\n", str);

    rotateLeft(str, k);
    printf("After Left Rotation: %s\n", str);

    strcpy(str, "abcdxyz");

    k = 3;

    rotateRight(str, k);
    printf("After Right Rotation: %s\n", str);

    return 0;
}
