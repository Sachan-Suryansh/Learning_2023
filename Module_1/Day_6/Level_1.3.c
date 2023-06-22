#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void parseInputString(char* input, struct Student* student) {
    char* token = strtok(input, " ");
    if (token != NULL) {
        student->rollno = atoi(token);
        token = strtok(NULL, " ");
        strncpy(student->name, token, sizeof(student->name) - 1);
        token = strtok(NULL, " ");
        student->marks = atof(token);
    }
}

void displayStudents(struct Student* students, int size) {
    printf("\n--- Student Details ---\n");
    for (int i = 0; i < size; i++) {
        printf("Student %d:\n", i + 1);
        printf("Roll No: %d\n", students[i].rollno);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
        printf("---------------------\n");
    }
}

int main() {
    int size;
    printf("Enter the number of students: ");
    scanf("%d", &size);
    getchar();

    // Allocate memory for the array of structures
    struct Student* students = malloc(size * sizeof(struct Student));
    if (students == NULL) {
        printf("Memory allocation failed. Exiting the program.\n");
        return 1;
    }

    printf("Enter the student details (rollno name marks):\n");
    for (int i = 0; i < size; i++) {
        char input[100];
        fgets(input, sizeof(input), stdin);
        parseInputString(input, &students[i]);
    }

    displayStudents(students, size);

    // Free the allocated memory
    free(students);

    return 0;
}
