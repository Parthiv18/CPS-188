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

    return 0;
}