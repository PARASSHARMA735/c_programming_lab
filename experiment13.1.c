#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *filePointer;
    char data[100];

    // Writing data to a file
    filePointer = fopen("example.txt", "w");
    if (filePointer == NULL) {
        printf("File cannot be opened.\n");
        return 1;
    }

    printf("Enter data to write to the file:\n");
    fgets(data, sizeof(data), stdin);
    fputs(data, filePointer);

    fclose(filePointer);

    // Reading data from the file
    filePointer = fopen("example.txt", "r");
    if (filePointer == NULL) {
        printf("File cannot be opened.\n");
        return 1;
    }

    printf("\nData read from the file:\n");
    while (fgets(data, sizeof(data), filePointer) != NULL) {
        printf("%s", data);
    }

    fclose(filePointer);

    return 0;
}
