#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct address_t {
    char ip[16];
    char networkName[50];
};

void compare(char str1[], char str2[]) {
    int counter = 0;
    for (int i = 0; i < 6; i++) {
        if (str1[i] == str2[i]) {
            counter++;
        }
    }
    if (counter == 6 || counter == 5 || counter == 4) {
        printf("\nsame");
    }
}

void splitting(char str[]) {  // change it up [from google]
    const char s[2] = ".";
    char *token;

    /* get the first token */
    token = strtok(str, s);

    /* walk through other tokens */
    while (token != NULL) {
        printf(" %s\n", token);

        token = strtok(NULL, s);
    }
}

int main() {
    FILE *fp = fopen("data.txt", "r");
    // address_t Network = ipAdd[16], networkName[50];
    struct address_t Network[100];
    int i = 0;

    // strcpy(Network.ip, "test");
    // scanning
    while (fscanf(fp, "%s %s", &Network[i].ip, &Network[i].networkName) != EOF) {
        i++;
    }
    for (int i = 0; i < 10; i++) {
        // printf("%s - %s\n", Network[i].ip, Network[i].networkName);
    }

    printf("%s - %s\n", Network[0].ip, Network[1].networkName);
    compare(Network[1].ip, Network[4].ip);
    // printf("%s", Network.ip);

    return 0;
}