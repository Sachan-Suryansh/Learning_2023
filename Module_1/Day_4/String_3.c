#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char timeStr[] = "10:12:50";
    char *token = strtok(timeStr, ":");
    int hours, minutes, seconds;

    if (token != NULL) {
        hours = atoi(token);
        token = strtok(NULL, ":");
        if (token != NULL) {
            minutes = atoi(token);
            token = strtok(NULL, ":");
            if (token != NULL) {
                seconds = atoi(token);

                int totalSeconds = (hours * 3600) + (minutes * 60) + seconds;
                printf("Total seconds: %d\n", totalSeconds);
                return 0;
            }
        }
    }

    printf("Invalid time format.\n");
    return 1;
}
