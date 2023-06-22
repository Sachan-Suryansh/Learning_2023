#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void parseString(const char* input, struct Student* students, int numStudents) {
    char temp[100];
    int i = 0;
    const char* delimiter = " ";

    strncpy(temp, input, sizeof(temp));  // Create a copy of the input string
    char* token = strtok(temp, delimiter);

    while (token != NULL && i < numStudents) {
        students[i].rollno = atoi(token);
        token = strtok(NULL, delimiter);

        if (token != NULL) {
            strncpy(students[i].name, token, sizeof(students[i].name));
            token = strtok(NULL, delimiter);
        }

        if (token != NULL) {
            students[i].marks = atof(token);
            token = strtok(NULL, delimiter);
        }

        i++;
    }
}

int main() {
    int numStudents;
    printf("Enter the number of students: ");
    scanf("%d", &numStudents);

    struct Student* students = malloc(numStudents * sizeof(struct Student));

    // Clear the newline character from the input buffer
    while (getchar() != '\n')
        continue;

    char input[100];
    printf("Enter the student data: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';

    parseString(input, students, numStudents);

    // Display the initialized array of structures
    printf("\nStudent Details:\n");
    for (int i = 0; i < numStudents; i++) {
        printf("Student %d:\n", i + 1);
        printf("Roll No: %d\n", students[i].rollno);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
        printf("\n");
    }

    free(students);
    return 0;
}
