#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct address_t {
    int aa;
    int bb;
    int cc;
    int dd;
    char networkName[15];
};

int localnet(struct address_t ip1, struct address_t ip2) {
    if (ip1.aa == ip2.aa && ip1.bb == ip2.bb) {
        return 1;
    }
    return 0;
}

int main() {
    FILE *fp = fopen("data.txt", "r");
    struct address_t Network[300];
    int i = 0;

    // scanning
    while (fscanf(fp, "%d.%d.%d.%d %s", &Network[i].aa, &Network[i].bb, &Network[i].cc, &Network[i].dd, &Network[i].networkName) != EOF) {
        if (Network[i].aa == 0 && Network[i].bb == 0 && Network[i].cc == 0 && Network[i].dd == 0 || Network[i].networkName == "sentinel")  // sentinal case
            break;
        i++;
    }
    for (int j = 0; j < i; j++) {
        for (int k = j + 1; k < i; k++) {
            if (localnet(Network[j], Network[k]) == 1) {
                printf("%s [%d.%d.%d.%d] and %s [%d.%d.%d.%d] are on the same network\n", Network[j].networkName, Network[j].aa, Network[j].bb, Network[j].cc, Network[j].dd,
                       Network[k].networkName, Network[k].aa, Network[k].bb, Network[k].cc, Network[k].dd);
            }
        }
    }
    printf("\nIP Address\t Network Name\n");
    for (int j = 0; j < i; j++) {
        printf("%d.%d.%d.%d\t| %s\n", Network[j].aa, Network[j].bb, Network[j].cc, Network[j].dd,
               Network[j].networkName);
    }
    return 0;
}