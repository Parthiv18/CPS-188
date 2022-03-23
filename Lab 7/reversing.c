#include <ctype.h>
#include <stdio.h>
#include <string.h>

void strip(char original[], char stripped[]) {  // add strip
    int spaceCounter = 0;
    for (int i = 0; i < strlen(original); i++) {  // change 5 to acc size
        if (original[i] >= 'A' && original[i] <= 'Z') {
            stripped[i] = original[i] + 32;
        } else {
            stripped[i] = original[i];
        }
    }
    for (int i = 0; original[i] != 0; i++)
        if (original[i] != ' ' && (isalpha(original[i]) || isdigit(original[i]))) {
            stripped[spaceCounter] = original[i];
            spaceCounter++;
        }
    stripped[spaceCounter] = '\0';  // empty
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
    printf("\n%d %d\n", counterChar, counter);
    if (counterChar+1 == counter) {
        printf("\nPalindrome");
    } else {
        printf("\nNot Palindrome");
    }
}

int main() {
    char org[100] = "jaj";  // original
    printf("Original: %s\n", org);

    char orgStrip[100] = "\0";  // stripping original
    strip(org, orgStrip);
    // printf("Stripped: %s\n", orgStrip);
    for (int i = 0; i < 100; i++) {
        printf("%c ", orgStrip[i]);
    }

    printf("\n");

    char rev[100] = "\0";  // reversing stripping original
    reverse(orgStrip, rev);
    for (int i = 0; i < 100; i++) {
        printf("%c ", rev[i]);
    }
    // printf("Reversed: %s\n", rev);

    /*for (int i = 0; i < 5; i++) {
        org[i] = '\0';
    }*/
    compare(org, rev);

    return 0;
}