#include <stdio.h>

#define MAX_SUBJECTS 5
#define MAX_STUDENTS 3

// Structure to store student information
struct Student {
    char name[50];
    int rollNumber;
    int marks[MAX_SUBJECTS];
};

int main() {
    struct Student students[MAX_STUDENTS];
    int numStudents, numSubjects;

    printf("Enter the number of students: ");
    scanf("%d", &numStudents);

    printf("Enter the number of subjects per student: ");
    scanf("%d", &numSubjects);

    if (numStudents > MAX_STUDENTS || numSubjects > MAX_SUBJECTS) {
        printf("Exceeded maximum limit for students or subjects.\n");
        return 1;
    }

    // Input student information
    for (int i = 0; i < numStudents; i++) {
        printf("\nEnter details for student %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("Roll Number: ");
        scanf("%d", &students[i].rollNumber);

        printf("Enter marks for %d subjects:\n", numSubjects);
        for (int j = 0; j < numSubjects; j++) {
            printf("Subject %d: ", j + 1);
            scanf("%d", &students[i].marks[j]);
        }
    }

    // Calculate and display total marks for each student
    printf("\nTotal marks for each student:\n");
    for (int i = 0; i < numStudents; i++) {
        int totalMarks = 0;
        for (int j = 0; j < numSubjects; j++) {
            totalMarks += students[i].marks[j];
        }
        printf("Student %d - Name: %s, Roll Number: %d, Total Marks: %d\n",
               i + 1, students[i].name, students[i].rollNumber, totalMarks);
    }

    return 0;
}
