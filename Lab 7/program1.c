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
        if (original[i] != ' ') {
            stripped[spaceCounter] = original[i];
            spaceCounter++;
        }
    stripped[spaceCounter] = '\0';  // empty
}

/*
    do reverse
*/

int main() {
    char og1[] = "boam";
    char og1Clean[0];
    char rev1[0];

    strip(og1, og1Clean);
    printf("%s\n", og1Clean);

    return 0;
}