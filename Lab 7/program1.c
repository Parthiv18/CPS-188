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
    // int og1 = strlen(original);
    // int rev1 = strlen(reversed);
    if (strlen(original) > 0) {
        reversed[strlen(reversed)] = original[strlen(original) - 1];  // copy
        original[strlen(original) - 1] = '\0';                        // remove
        reverse(original, reversed);                                  // run down
    }
}

void palindromeChecker(char original[], char reversed[]) {
    int checker = 1;
    for (int i = 0; i < 100; i++) {
        if (original[i] != reversed[i]) {
            checker = 0;
            printf("\nNot Palindrome");
            break;
        }
    }
    if (checker == 1) {
        printf("Palindrome");
    }
}

int main() {
    char og[100];
    printf("string: ");     // asking user
    fgets(og, 100, stdin);  // storing string

    char stp[strlen(og)];  // empty strip array
    strip(og, stp);
    printf("Stripped Input: %s\n", stp);

    char rev[100];  // empty reverse array
    char revStrip[100];
    reverse(stp, rev);
    strip(rev, revStrip);
    printf("Reversed: %s", revStrip);

    palindromeChecker(stp, revStrip);

    return 0;
}