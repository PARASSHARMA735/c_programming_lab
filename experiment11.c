#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr;

    // Demonstrate malloc()
    int size = 5;
    printf("Demonstrating malloc():\n");
    ptr = (int*)malloc(size * sizeof(int));
    if (ptr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    printf("Memory allocated using malloc() successfully.\n");

    // Assigning values using malloc()
    printf("Enter %d integers:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &ptr[i]);
    }

    // Display values using malloc()
    printf("Values entered using malloc():\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", ptr[i]);
    }
    printf("\n");

    // Demonstrate calloc()
    printf("\nDemonstrating calloc():\n");
    int *ptr_calloc = (int*)calloc(size, sizeof(int));
    if (ptr_calloc == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    printf("Memory allocated using calloc() successfully.\n");

    // Assigning values using calloc()
    printf("Values after calloc() (should be initialized to zero):\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", ptr_calloc[i]);
    }
    printf("\n");

    // Demonstrate realloc()
    int new_size = 7;
    printf("\nDemonstrating realloc():\n");
    int *ptr_realloc = (int*)realloc(ptr, new_size * sizeof(int));
    if (ptr_realloc == NULL) {
        printf("Memory reallocation failed.\n");
        free(ptr);
        return 1;
    }
    printf("Memory reallocated using realloc() successfully.\n");

    // Display values after realloc()
    printf("Enter %d more integers:\n", new_size - size);
    for (int i = size; i < new_size; i++) {
        scanf("%d", &ptr_realloc[i]);
    }

    printf("Values after realloc():\n");
    for (int i = 0; i < new_size; i++) {
        printf("%d ", ptr_realloc[i]);
    }
    printf("\n");

    // Free memory
    free(ptr_realloc);
    free(ptr_calloc);

    return 0;
}
