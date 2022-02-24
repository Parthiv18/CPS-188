#include <stdio.h>
#include <stdlib.h>

double perigee(int choice, double speed) {  // minimum time => d=st
    if (choice == 1) {                      // conditions to get the accurate time
        return 363104 / speed;
    } else if (choice == 2) {
        return 54600000 / speed;
    } else if (choice == 3) {
        return 38000000 / speed;
    } else {
        return 0;
    }
}
double apogee(int choice, double speed) {  // maximum time => d=st
    if (choice == 1) {                     // conditions to get the accurate time
        return 405696 / speed;
    } else if (choice == 2) {
        return 401000000 / speed;
    } else if (choice == 3) {
        return 261000000 / speed;
    } else {
        return 0;
    }
}

int main() {
    int choice;
    do {
        double speed;

        // getting info
        printf("1. Traveling to the Moon\n2. Traveling to Mars\n3. Traveling to Venus\n4. Exit Program\n");
        printf("Choose Option: ");
        scanf("%d", &choice);
        if (choice == 4) {  // condition to exit the program
            break;
        }
        printf("Enter Speed: ");
        scanf("%lf", &speed);

        printf("Time (perigee): %.2lf h\nTime (apogee): %.2lf h\n\n", perigee(choice, speed), apogee(choice, speed));  // output

    } while (choice != 4);  // keep going until choice is exit program

    return 0;
}