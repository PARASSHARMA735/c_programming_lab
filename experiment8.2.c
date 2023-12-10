#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isPalindrome(const char *str) {
    int length = strlen(str);
    int i, j;

    // Ignore non-alphanumeric characters and convert to lowercase
    char cleanStr[length + 1];
    int cleanLen = 0;
    for (i = 0; i < length; i++) {
        if (isalnum(str[i])) {
            cleanStr[cleanLen++] = tolower(str[i]);
        }
    }
    cleanStr[cleanLen] = '\0';

    // Check if cleanStr is a palindrome
    length = cleanLen;
    for (i = 0, j = length - 1; i < j; i++, j--) {
        if (cleanStr[i] != cleanStr[j]) {
            return 0; // Not a palindrome
        }
    }
    return 1; // Palindrome
}

int main() {
    char inputString[100];

    printf("Enter a string: ");
    fgets(inputString, sizeof(inputString), stdin);

    // Remove newline character from fgets input
    inputString[strcspn(inputString, "\n")] = '\0';

    if (isPalindrome(inputString)) {
        printf("\"%s\" is a palindrome.\n", inputString);
    } else {
        printf("\"%s\" is not a palindrome.\n", inputString);
    }

    return 0;
}