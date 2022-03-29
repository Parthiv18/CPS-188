#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct address_t {
    char ip[16];
    char networkName[50];
};

void localnet(char str1[], char str2[]) {
    int counter = 0;
    for (int i = 0; i < 6; i++) {
        if (str1[i] == str2[i]) {
            counter++;
        }
    }
    if (counter == 2 || counter == 4 || counter == 5 || counter == 6) {
        printf(" [1] ");
    } else {
        printf(" [0] ");
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

    // printf("%s - %s\n", Network[1].ip, Network[1].networkName);
    // printf("%s - %s", Network[4].ip, Network[4].networkName);
    // localnet(Network[1].ip, Network[4].ip);
    //  printf("%s", Network.ip);

    for (int j = 0; j < 10; j++) {
        printf("%s - %s\n", Network[j].ip, Network[j].networkName);
    }
    printf("\nsame\n");
    for (int j = 0; j < 10; j++) {
        for (int k = 0; k < 10 - 1; k++) {
            // printf("%d %d\n", j, k);
            if (j != k) {
                localnet(Network[j].ip, Network[k].ip);
                printf("%s - %s and %s - %s\n", Network[j].ip, Network[j].networkName, Network[k].ip, Network[k].networkName);
            }
        }
        printf("\n");
    }

    return 0;
}