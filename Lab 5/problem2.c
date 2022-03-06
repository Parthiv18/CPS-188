#include <stdio.h>
#include <stdlib.h>
 
double *moon(double speed) {  // mmoon function
    double min = 363104 / speed;
    double max = 405696 / speed;
    static double arr[2];  // make static array to return array function
    arr[0] = min;          // store index 0
    arr[1] = max;          // store index 1
    return arr;            // return
}
double *mars(double speed) {  // mars function
    double min = 54600000 / speed;
    double max = 401000000 / speed;
    static double arr[2];  // make static array to return array function
    arr[0] = min;          // store index 0
    arr[1] = max;          // store index 1
    return arr;            // return
}
double *venus(double speed) {  // venus function
    double min = 38000000 / speed;
    double max = 261000000 / speed;
    static double arr[2];  // make static array to return array function
    arr[0] = min;          // store index 0
    arr[1] = max;          // store index 1
    return arr;            // return
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
 
        if (choice == 1) {                                                                                     // condition to call moon function
            double *arr = moon(speed);                                                                         // pointer assign to function
            printf("Earth to Moon -> Time (perigee): %.2lf h | Time (apogee): %.2lf h\n\n", arr[0], arr[1]);   // output
        } else if (choice == 2) {                                                                              // condition to call mars function
            double *arr = mars(speed);                                                                         // pointer assign to function
            printf("Earth to Mars -> Time (perigee): %.2lf h | Time (apogee): %.2lf h\n\n", arr[0], arr[1]);   // output
        } else if (choice == 3) {                                                                              // condition to call venus function
            double *arr = venus(speed);                                                                        // pointer assign to function
            printf("Earth to Venus -> Time (perigee): %.2lf h | Time (apogee): %.2lf h\n\n", arr[0], arr[1]);  // output
        } else {                                                                                               // if none are chosen
            printf("Please Enter a Valid Choice");
        }
    } while (choice != 4);  // keep going until choice is exit program
 
    return 0;
}
