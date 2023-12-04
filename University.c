#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to represent a student
struct Student {
    int rollNumber;
    char name[50];
    float marks;
};

// Function to add a new student
void addStudent(struct Student *students, int *numStudents) {
    if (*numStudents >= 100) {
        printf("Error: Maximum number of students reached.\n");
        return;
    }

    printf("Enter student details:\n");

    printf("Roll Number: ");
    scanf("%d", &students[*numStudents].rollNumber);

    printf("Name: ");
    scanf("%s", students[*numStudents].name);

    printf("Marks: ");
    scanf("%f", &students[*numStudents].marks);

    (*numStudents)++;

    printf("Student added successfully.\n");
}

// Function to display all students
void displayStudents(struct Student *students, int numStudents) {
    if (numStudents == 0) {
        printf("No students to display.\n");
        return;
    }

    printf("Student Details:\n");
    for (int i = 0; i < numStudents; i++) {
        printf("Roll Number: %d\n", students[i].rollNumber);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
        printf("\n");
    }
}

int main() {
    struct Student students[100]; // Assuming a maximum of 100 students
    int numStudents = 0;
    int choice;

    do {
        printf("\nUniversity Management System Menu:\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent(students, &numStudents);
                break;
            case 2:
                displayStudents(students, numStudents);
                break;
            case 3:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 3);

    return 0;
}
