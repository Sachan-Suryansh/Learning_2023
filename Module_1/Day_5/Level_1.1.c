//Structures
#include <stdio.h>

struct Box {
    float length;
    float width;
    float height;
};

void calculateVolumeAndSurfaceArea(struct Box* box, float* volume, float* surfaceArea) {
    *volume = box->length * box->width * box->height;
    *surfaceArea = 2 * (box->length * box->width + box->length * box->height + box->width * box->height);
}

int main() {
    struct Box myBox = { 2.5, 3.0, 4.0 };
    struct Box* boxPtr = &myBox;
    float volume, surfaceArea;

    calculateVolumeAndSurfaceArea(boxPtr, &volume, &surfaceArea);

    printf("Volume: %.2f\n", volume);
    printf("Total Surface Area: %.2f\n", surfaceArea);

    return 0;
}
