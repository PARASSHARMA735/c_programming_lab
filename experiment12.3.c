#include <stdio.h>

#define MAX_SUBJECTS 5
#define MAX_STUDENTS 3

// Structure to store student information
struct Student {
    char name[50];
    int rollNumber;
    int marks[MAX_SUBJECTS];
};

// Function to calculate total marks for a student
int calculateTotalMarks(const struct Student *student, int numSubjects) {
    int totalMarks = 0;
    for (int i = 0; i < numSubjects; i++) {
        totalMarks += student->marks[i];
    }
    return totalMarks;
}

// Function to calculate average marks for a student
float calculateAverageMarks(const struct Student *student, int numSubjects) {
    int totalMarks = calculateTotalMarks(student, numSubjects);
    return (float)totalMarks / numSubjects;
}

// Function to display student information
void displayStudentInfo(const struct Student *student, int numSubjects) {
    printf("Name: %s\n", student->name);
    printf("Roll Number: %d\n", student->rollNumber);
    printf("Marks in %d subjects:\n", numSubjects);
    for (int i = 0; i < numSubjects; i++) {
        printf("Subject %d: %d\n", i + 1, student->marks[i]);
    }
    printf("\n");
}

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

    // Display student information and perform operations
    for (int i = 0; i < numStudents; i++) {
        printf("\nDetails for student %d:\n", i + 1);
        displayStudentInfo(&students[i], numSubjects);
        printf("Total Marks: %d\n", calculateTotalMarks(&students[i], numSubjects));
        printf("Average Marks: %.2f\n", calculateAverageMarks(&students[i], numSubjects));
    }

    return 0;
}
