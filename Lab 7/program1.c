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
    int switchCounter = 1;
    /*for (int i = 0; i < strlen(original); i++) {
        if (original[i] == reversed[i]) {
            switchCounter = 1;
        } else {
            switchCounter = 0;
        }
    }*/
    if(original == reversed) {
        switchCounter = 1;
    }
    else {
        switchCounter = 0;
    }
    if (switchCounter == 1) {
        printf("same");
    } else {
        printf("not same");
    }
}

int main() {
    char og[100];
    printf("string: ");     // asking user
    fgets(og, 100, stdin);  // storing string

    char stp[100];  // empty strip array
    strip(og, stp);
    printf("Stripped Input: %s\n", stp);
    // printf("%d\n", strlen(stp));

    char rev[strlen(stp) - 1];  // empty reverse array
    reverse(stp, rev);
    printf("Reversed String: %s\n", rev);
    // printf("%d\n", strlen(stp));

    palindromeChecker(stp, rev);  // checking if the same

    return 0;
}