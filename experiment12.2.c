#include <stdio.h>
#include <string.h>

#define NAME_LENGTH 50

// Union to store information of a student
union StudentInfo {
    char studentName[NAME_LENGTH];
    int rollNumber;
    float GPA;
};

// Structure to hold additional student details along with the union
struct Student {
    union StudentInfo info;
    char category; // To differentiate which field of the union is being used
};

int main() {
    struct Student student;

    printf("Enter student's name: ");
    fgets(student.info.studentName, NAME_LENGTH, stdin);
    student.info.studentName[strcspn(student.info.studentName, "\n")] = '\0'; // Remove newline character

    printf("Enter student's roll number: ");
    scanf("%d", &student.info.rollNumber);

    printf("Enter student's GPA: ");
    scanf("%f", &student.info.GPA);

    printf("\nStudent Information:\n");

    printf("Name: %s\n", student.info.studentName);
    printf("Roll Number: %d\n", student.info.rollNumber);
    printf("GPA: %.2f\n", student.info.GPA);

    return 0;
}
