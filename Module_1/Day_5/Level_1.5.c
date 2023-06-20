#include <stdio.h>

struct Point {
    int x;
    int y;
};

void swapFields(struct Point *p1, struct Point *p2) {
    int temp;

    temp = p1->x;
    p1->x = p2->x;
    p2->x = temp;

    temp = p1->y;
    p1->y = p2->y;
    p2->y = temp;
}

int main() {
    struct Point p1 = {2, 3};
    struct Point p2 = {5, 7};

    printf("Before swapping:\n");
    printf("p1 = (%d, %d)\n", p1.x, p1.y);
    printf("p2 = (%d, %d)\n", p2.x, p2.y);

    swapFields(&p1, &p2);

    printf("\nAfter swapping:\n");
    printf("p1 = (%d, %d)\n", p1.x, p1.y);
    printf("p2 = (%d, %d)\n", p2.x, p2.y);

    return 0;
}
