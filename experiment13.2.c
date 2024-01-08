#include <stdio.h>
#include <stdlib.h>

#define MAX_SUBJECTS 5
#define MAX_STUDENTS 3

// Structure to store student information
struct Student {
    char name[50];
    int rollNumber;
    int marks[MAX_SUBJECTS];
};

// Function to write student data to a file
void writeStudentData(FILE *file, const struct Student *students, int numStudents, int numSubjects) {
    for (int i = 0; i < numStudents; i++) {
        fprintf(file, "Student %d\n", i + 1);
        fprintf(file, "Name: %s\n", students[i].name);
        fprintf(file, "Roll Number: %d\n", students[i].rollNumber);
        fprintf(file, "Marks in %d subjects:\n", numSubjects);
        for (int j = 0; j < numSubjects; j++) {
            fprintf(file, "Subject %d: %d\n", j + 1, students[i].marks[j]);
        }
        fprintf(file, "\n");
    }
}

// Function to read student data from a file
void readStudentData(FILE *file, int numStudents, int numSubjects) {
    struct Student students[MAX_STUDENTS];
    char buffer[100];

    printf("Reading student data from the file:\n\n");

    for (int i = 0; i < numStudents; i++) {
        fgets(buffer, sizeof(buffer), file); // Read "Student i"
        fgets(buffer, sizeof(buffer), file); // Read "Name: ..."
        sscanf(buffer, "Name: %[^\n]", students[i].name);

        fgets(buffer, sizeof(buffer), file); // Read "Roll Number: ..."
        sscanf(buffer, "Roll Number: %d", &students[i].rollNumber);

        fgets(buffer, sizeof(buffer), file); // Read "Marks in numSubjects subjects:"
        for (int j = 0; j < numSubjects; j++) {
            fgets(buffer, sizeof(buffer), file); // Read "Subject j: ..."
            sscanf(buffer, "Subject %*d: %d", &students[i].marks[j]);
        }

        fgets(buffer, sizeof(buffer), file); // Read empty line after a student's data
    }

    // Display read student data
    for (int i = 0; i < numStudents; i++) {
        printf("Student %d\n", i + 1);
        printf("Name: %s\n", students[i].name);
        printf("Roll Number: %d\n", students[i].rollNumber);
        printf("Marks in %d subjects:\n", numSubjects);
        for (int j = 0; j < numSubjects; j++) {
            printf("Subject %d: %d\n", j + 1, students[i].marks[j]);
        }
        printf("\n");
    }
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

    // Writing student data to a file
    FILE *fileWrite = fopen("student_data.txt", "w");
    if (fileWrite == NULL) {
        printf("File cannot be opened.\n");
        return 1;
    }

    writeStudentData(fileWrite, students, numStudents, numSubjects);
    fclose(fileWrite);
    printf("\nStudent data has been written to the file 'student_data.txt'.\n");

    // Reading student data from a file
    FILE *fileRead = fopen("student_data.txt", "r");
    if (fileRead == NULL) {
        printf("File cannot be opened.\n");
        return 1;
    }

    readStudentData(fileRead, numStudents, numSubjects);
    fclose(fileRead);

    return 0;
}
