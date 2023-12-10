#include <stdio.h>

int fibonacci(int n) {
    if (n <= 1)
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int count, i;

    printf("Enter the number of Fibonacci numbers to print: ");
    scanf("%d", &count);

    printf("Fibonacci Series up to %d terms:\n", count);
    for (i = 0; i < count; ++i) {
        printf("%d ", fibonacci(i));
    }
    printf("\n");

    return 0;
}