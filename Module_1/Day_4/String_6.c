//No. of days elapsed
#include <stdio.h>

// Function to check if the given year is a leap year
int isLeapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        return 1;
    } else {
        return 0;
    }
}

// Function to get the number of days in a month
int getDaysInMonth(int month, int year) {
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (month == 2 && isLeapYear(year)) {
        return 29;
    } else {
        return daysInMonth[month - 1];
    }
}

// Function to calculate the number of days elapsed
int calculateDaysElapsed(int day, int month, int year) {
    int daysElapsed = 0;

    for (int i = 1; i < month; i++) {
        daysElapsed += getDaysInMonth(i, year);
    }

    daysElapsed += day;

    return daysElapsed;
}

int main() {
    int day, month, year;

    printf("Enter the date (dd/mm/yyyy): ");
    scanf("%d/%d/%d", &day, &month, &year);

    int daysElapsed = calculateDaysElapsed(day, month, year);

    printf("Number of days elapsed: %d\n", daysElapsed);

    return 0;
}
