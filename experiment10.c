#include <stdio.h>

// Function to swap two numbers using call by value
void swapByValue(int x, int y) {
    int temp;
    temp = x;
    x = y;
    y = temp;
    printf("Inside swapByValue function: x = %d, y = %d\n", x, y);
}

// Function to swap two numbers using call by reference
void swapByReference(int *x, int *y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
    printf("Inside swapByReference function: x = %d, y = %d\n", *x, *y);
}

int main() {
    int num1 = 5, num2 = 10;

    printf("Before swapping: num1 = %d, num2 = %d\n", num1, num2);

    // Call by value
    swapByValue(num1, num2);
    printf("After swapByValue function: num1 = %d, num2 = %d\n", num1, num2);

    // Resetting values
    num1 = 5;
    num2 = 10;

    // Call by reference
    swapByReference(&num1, &num2);
    printf("After swapByReference function: num1 = %d, num2 = %d\n", num1, num2);

    return 0;
}