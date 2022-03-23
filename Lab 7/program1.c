#include <ctype.h>
#include <stdio.h>
#include <string.h>

void strip(char original[], char stripped[]) {  // add strip
    // changing from lower to upper
    for (int i = 0; i < strlen(original); i++) {
        if (isupper(original[i])) {
            original[i] = tolower(original[i]);
        }
    }

    // checking if it has alpha or digits only
    int j = 0, spaceCounter = 0;
    while (original[j] != '\0') {
        if ((isalpha(original[j]) || isdigit(original[j]))) {
            original[spaceCounter++] = original[j];
        }
        j++;
    }
    original[spaceCounter] = '\0';

    // copying
    for (int i = 0; i < strlen(original); i++) {
        stripped[i] = original[i];
    }
}
void reverse(char original[], char reversed[]) {
    if (strlen(original) > 0) {
        reversed[strlen(reversed)] = original[strlen(original) - 1];  // copy
        original[strlen(original) - 1] = '\0';                        // remove
        reverse(original, reversed);                                  // run down
    }
}
void compare(char original[], char reversed[]) {
    int counterChar = 0;
    for (int i = 0; i < strlen(original); i++) {
        if (original[i] != '\0') {
            counterChar++;
        }
    }
    int counter = 1;
    for (int i = 0; i < strlen(reversed); i++) {
        if (original[i] == reversed[i]) {
            counter++;
        }
    }
    // printf("\n\nCounter Char (stripped): [%d] Counter (same): [%d]\n", counterChar, counter); //if they are the same we want counterchar to be one more to match
    if (counterChar + 1 == counter) {  // condition to check if they are palindrome
        printf("\nPalindrome");
    } else {
        printf("\nNot Palindrome");
    }
}

int main() {
    // char org[100] = "Marge lets Norah see Sharon's telegram.";  // original
    // printf("Original: %s\n", org);
    char org[100];
    printf("Input String: ");  // asking user
    fgets(org, 100, stdin);    // storing string

    char orgStrip[100] = "\0";  // stripping original
    strip(org, orgStrip);
    printf("Stripped: ");
    for (int i = 0; i < 100; i++) {
        printf("%c ", orgStrip[i]);
    }

    printf("\n");

    char rev[100] = "\0";  // reversing stripping original
    reverse(orgStrip, rev);
    printf("Reversed: ");
    for (int i = 0; i < 100; i++) {
        printf("%c ", rev[i]);
    }

    compare(org, rev);

    return 0;
}