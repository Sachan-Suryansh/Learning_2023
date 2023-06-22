#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void parseString(const char* input, struct Student* students, int numStudents) {
    int i = 0;
    char temp[20];
    sscanf(input, "%d %s %f", &(students[i].rollno), temp, &(students[i].marks));
    strncpy(students[i].name, temp, sizeof(students[i].name) - 1);
}

void displayStudents(const struct Student* students, int numStudents) {
    printf("Students:\n");
    for (int i = 0; i < numStudents; i++) {
        printf("Roll No: %d, Name: %s, Marks: %.2f\n", students[i].rollno, students[i].name, students[i].marks);
    }
}

int compareStudents(const void* a, const void* b) {
    const struct Student* studentA = (const struct Student*)a;
    const struct Student* studentB = (const struct Student*)b;
    if (studentA->marks < studentB->marks) {
        return 1;  // Sort in descending order
    } else if (studentA->marks > studentB->marks) {
        return -1;
    } else {
        return 0;
    }
}

void sortStudents(struct Student* students, int numStudents) {
    qsort(students, numStudents, sizeof(struct Student), compareStudents);
}

int main() {
    int numStudents;
    printf("Enter the number of students: ");
    scanf("%d", &numStudents);
    getchar();

    struct Student* students = (struct Student*)malloc(numStudents * sizeof(struct Student));

    printf("Enter student details (Roll No, Name, Marks):\n");
    for (int i = 0; i < numStudents; i++) {
        char input[100];
        fgets(input, sizeof(input), stdin);
        parseString(input, &(students[i]), numStudents);
    }

    displayStudents(students, numStudents);

    sortStudents(students, numStudents);

    printf("Students sorted in descending order based on marks:\n");
    displayStudents(students, numStudents);

    free(students);

    return 0;
}
