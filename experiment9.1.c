#include <stdio.h>

// Function to add two numbers
float add(float num1, float num2) {
    return num1 + num2;
}

// Function to subtract two numbers
float subtract(float num1, float num2) {
    return num1 - num2;
}

// Function to multiply two numbers
float multiply(float num1, float num2) {
    return num1 * num2;
}

// Function to divide two numbers
float divide(float num1, float num2) {
    if (num2 != 0) {
        return num1 / num2;
    } else {
        printf("Error: Division by zero\n");
        return 0;
    }
}

int main() {
    char operation;
    float num1, num2, result;

    printf("Enter an operation (+, -, *, /): ");
    scanf("%c", &operation);

    printf("Enter two numbers: ");
    scanf("%f %f", &num1, &num2);

    switch (operation) {
        case '+':
            result = add(num1, num2);
            printf("Result: %.2f\n", result);
            break;
        case '-':
            result = subtract(num1, num2);
            printf("Result: %.2f\n", result);
            break;
        case '*':
            result = multiply(num1, num2);
            printf("Result: %.2f\n", result);
            break;
        case '/':
            result = divide(num1, num2);
            printf("Result: %.2f\n", result);
            break;
        default:
            printf("Invalid operation\n");
            break;
    }

    return 0;
}