#include <stdio.h>

#define MAX_STUDENTS 100

struct Student {
    char name[50];
    float marks;
};

void readStudents(struct Student students[], int n) {
    printf("Enter details for %d students:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Enter name of student %d: ", i+1);
        scanf("%s", students[i].name);
        printf("Enter marks of student %d: ", i+1);
        scanf("%f", &students[i].marks);
    }
}

void writeStudents(struct Student students[], int n) {
    printf("Student details:\n");
    for (int i = 0; i < n; i++) {
        printf("Name: %s, Marks: %.2f\n", students[i].name, students[i].marks);
    }
}

float calculateAverage(struct Student students[], int n) {
    float sum = 0;
    for (int i = 0; i < n; i++) {
        sum += students[i].marks;
    }
    return sum / n;
}

void printAboveAverage(struct Student students[], int n, float average) {
    printf("Students scoring above average marks:\n");
    for (int i = 0; i < n; i++) {
        if (students[i].marks > average) {
            printf("Name: %s, Marks: %.2f\n", students[i].name, students[i].marks);
        }
    }
}

void printBelowAverage(struct Student students[], int n, float average) {
    printf("Students scoring below average marks:\n");
    for (int i = 0; i < n; i++) {
        if (students[i].marks < average) {
            printf("Name: %s, Marks: %.2f\n", students[i].name, students[i].marks);
        }
    }
}

int main() {
    int n;
    struct Student students[MAX_STUDENTS];

    printf("Enter the number of students: ");
    scanf("%d", &n);

    readStudents(students, n);

    writeStudents(students, n);

    float average = calculateAverage(students, n);
    printf("Average marks: %.2f\n", average);

    printAboveAverage(students, n, average);

    printBelowAverage(students, n, average);

    return 0;
}
