#include <math.h>
#include <stdio.h>

double intenLevel(char level) {  // method for returning values depending on low, medium or high
    if (level == 'L') {
        return 0.55;
    } else if (level == 'M') {
        return 0.65;
    } else if (level == 'H') {
        return 0.8;
    } else {
        return 0;  // return 0 for error [returns also for method]
    }
}

double formula(char gender, int age, int rhr, char level) {         // method for formula
    double maleMHR = 203.7 / (1 + exp(0.033 * (age - 104.3)));      // formula for male
    double femaleMHR = 190.2 / (1 + exp(0.04534 * (age - 107.5)));  // formula for female

    if (gender == 'F') {  // if char is F then apply female formula
        return (femaleMHR - rhr) * (intenLevel(level) + rhr);
    } else if (gender == 'M') {  // if char is M then apply male formula
        return (maleMHR - rhr) * (intenLevel(level) + rhr);
    } else {
        return 0;  // return 0 for error [returns also for method]
    }
}

int main() {
    // var
    char gender, fitnessLevel;
    int age, heartRate;

    // getting info
    printf("What is your age: ");
    scanf("%d", &age);
    printf("What is your gender (M,F): ");
    scanf(" %c", &gender);
    printf("What is your resting heart rate (RHR): ");
    scanf("%d", &heartRate);
    printf("What is your fitness level (L,M,H): ");
    scanf(" %c", &fitnessLevel);

    if (formula(gender, age, heartRate, fitnessLevel) && intenLevel(fitnessLevel) != 0)
        printf("Training Heart Rate: %1.0lf", formula(gender, age, heartRate, fitnessLevel));  // no error if all conditions are met and rounding to nearest int
    else
        printf("ERROR [Please Enter Valid Inputs]");  // error

    return 0;
}