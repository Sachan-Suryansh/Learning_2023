#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void initializeStudents(struct Student* students, int numStudents) {
    for (int i = 0; i < numStudents; i++) {
        students[i].rollno = i + 1;
        strcpy(students[i].name, "Unknown");
        students[i].marks = 0.0;
    }
}

int main() {
    int numStudents;
    printf("Enter the number of students: ");
    scanf("%d", &numStudents);

    // Dynamically allocate memory for students
    struct Student* students = malloc(numStudents * sizeof(struct Student));
    if (students == NULL) {
        printf("Memory allocation failed. Exiting the program.\n");
        return 1;  // Return a non-zero value to indicate an error
    }

    initializeStudents(students, numStudents);

    // Display the initialized array of structures
    printf("\nStudent Details:\n");
    for (int i = 0; i < numStudents; i++) {
        printf("Student %d:\n", i + 1);
        printf("Roll No: %d\n", students[i].rollno);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
        printf("\n");
    }

    free(students);  // Deallocate the dynamically allocated memory
    return 0;
}
