#include <stdio.h>
#include <string.h>

char studentNames[500][50];
int studentAges[500];
float studentGrades[500];
int studentCount = 0;

void addStudent() {
    if (studentCount < 500) {
        printf("Enter student name: ");
        scanf("%s", studentNames[studentCount]);

        printf("Enter student age: ");
        scanf("%d", &studentAges[studentCount]);

        printf("Enter student grade: ");
        scanf("%f", &studentGrades[studentCount]);

        studentCount++;
        printf("Student added successfully!\n");
    } else {
        printf("Maximum number of students reached = 500 .\n");
    }
}

void deleteStudent(const char *name) {
    int found = 0;
    for (int i = 0; i < studentCount; i++) {
        if (strcmp(studentNames[i], name) == 0) {
            found = 1;
            for (int j = i; j < (studentCount - 1); j++) {
                strcpy(studentNames[j], studentNames[j + 1]);
                studentAges[j] = studentAges[j + 1];
                studentGrades[j] = studentGrades[j + 1];
            }
            studentCount--;
            printf("Student '%s' deleted successfully!\n", name);
            break;
        }
    }
    if (!found) {
        printf("Student '%s' not found.\n", name);
    }
}

void displayStudents() {
    if (studentCount == 0) {
        printf("No student records to display.\n");
    } else {
        printf("Student Records:\n");
        for (int i = 0; i < studentCount; i++) {
            printf("Name: %s, Age: %d, Grade: %.2f\n", studentNames[i], studentAges[i], studentGrades[i]);
        }
    }
}

int main() {
    printf("Student Information System\n");

    while (1) {
        printf("\nOptions:\n");
        printf("1. Add Student\n");
        printf("2. Delete Student\n");
        printf("3. Display Students\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                {
                    char nameToDelete[50];
                    printf("Enter student name to delete: ");
                    scanf("%s", nameToDelete);
                    deleteStudent(nameToDelete);
                }
                break;
            case 3:
                displayStudents();
                break;
            case 4:
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}
