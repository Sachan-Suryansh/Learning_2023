#include <stdio.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void parseString(char* input, struct Student* student) {
    char* token = strtok(input, " ");

    if (token != NULL) {
        student->rollno = atoi(token);

        token = strtok(NULL, " ");
        strncpy(student->name, token, sizeof(student->name));
        student->name[sizeof(student->name) - 1] = '\0';

        token = strtok(NULL, " ");
        student->marks = atof(token);
    }
}

void displayStudents(struct Student* students, int size) {
    printf("Student Details:\n");
    printf("-----------------\n");
    for (int i = 0; i < size; i++) {
        printf("Roll No: %d\n", students[i].rollno);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
        printf("-----------------\n");
    }
}

void sortStudents(struct Student* students, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (students[j].marks < students[j + 1].marks) {
                // Swap students[j] and students[j+1]
                struct Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

void searchStudentByName(struct Student* students, int size, const char* name) {
    printf("Search Result:\n");
    printf("-----------------\n");
    int found = 0;
    for (int i = 0; i < size; i++) {
        if (strcmp(students[i].name, name) == 0) {
            printf("Roll No: %d\n", students[i].rollno);
            printf("Name: %s\n", students[i].name);
            printf("Marks: %.2f\n", students[i].marks);
            printf("-----------------\n");
            found = 1;
        }
    }
    if (!found) {
        printf("Student not found.\n");
        printf("-----------------\n");
    }
}

int main() {
    int size;
    printf("Enter the number of students: ");
    scanf("%d", &size);
    getchar();

    struct Student students[size];

    printf("Enter student details (rollno name marks):\n");
    for (int i = 0; i < size; i++) {
        char input[100];
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';

        parseString(input, &students[i]);
    }

    displayStudents(students, size);

    sortStudents(students, size);
    printf("After sorting by marks in descending order:\n");
    displayStudents(students, size);

    printf("Enter the name to search: ");
    char searchName[20];
    fgets(searchName, sizeof(searchName), stdin);
    searchName[strcspn(searchName, "\n")] = '\0'; // Remove the trailing newline character

    searchStudentByName(students, size, searchName);

    return 0;
}
