#include <stdio.h>

// Function to perform linear search
int linearSearch(int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            return 1; // Element found
        }
    }
    return 0; // element not found 
}

int main() {
    int size, key;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to search: ");
    scanf("%d", &key);

    
    if (linearSearch(arr, size, key)) {
        printf("Yes\n"); // Element found
    } else {
        printf("No\n"); // element not found
    }

    return 0;
}
