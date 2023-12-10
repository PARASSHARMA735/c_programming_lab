   #include <stdio.h>
#include <string.h>

int main() {
    char str1[] = "Hello";
    char str2[] = "World!";
    char concatStr[50];
    char copyStr[50];
    char revStr[50];
    char searchChar = 'o';
    const char *str3 = "This is a test string";
    const char *substring = "test";

    // String concatenation using strcat()
    strcpy(concatStr, str1);
    strcat(concatStr, " ");
    strcat(concatStr, str2);
    printf("Concatenated string: %s\n", concatStr);

    // String copy using strcpy()
    strcpy(copyStr, str1);
    printf("Copied string: %s\n", copyStr);

    // String length using strlen()
    printf("Length of str1: %lu\n", strlen(str1));

    // String comparison using strcmp()
    if (strcmp(str1, str2) == 0) {
        printf("str1 and str2 are equal\n");
    } else {
        printf("str1 and str2 are not equal\n");
    }

    // String reverse
    int i, j;
    j = 0;
    for (i = strlen(str1) - 1; i >= 0; i--) {
        revStr[j++] = str1[i];
    }
    revStr[j] = '\0';
    printf("Reversed string of str1: %s\n", revStr);

    // Searching a character in a string using strchr()
    char *foundChar = strchr(str1, searchChar);
    if (foundChar != NULL) {
        printf("'%c' found at position: %ld\n", searchChar, foundChar - str1);
    } else {
        printf("'%c' not found in str1\n", searchChar);
    }

    // Searching a substring in a string using strstr()
    char *foundSubstr = strstr(str3, substring);
    if (foundSubstr != NULL) {
        printf("'%s' found in str3 at position: %ld\n", substring, foundSubstr - str3);
    } else {
        printf("'%s' not found in str3\n", substring);
    }

    return 0;
}
 