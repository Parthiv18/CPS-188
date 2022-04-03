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

int main() {
    FILE *fp = fopen("data.txt", "r");
    struct address_t Network[100];
    int i = 0;

    // scanning
    while (fscanf(fp, "%s %s", &Network[i].ip, &Network[i].networkName) != EOF) {
        i++;
    }
    for (int j = 0; j < 10; j++) {
        printf("%s - %s\n", Network[j].ip, Network[j].networkName);
    }
    printf("\nsame\n");
    for (int j = 0; j < 10; j++) {
        for (int k = 0; k < 10 - 1; k++) {
            if (j != k) {
                localnet(Network[j].ip, Network[k].ip);
                printf("%s - %s and %s - %s\n", Network[j].ip, Network[j].networkName, Network[k].ip, Network[k].networkName);
            }
        }
        printf("\n");
    }

    return 0;
}