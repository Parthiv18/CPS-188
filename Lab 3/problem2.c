#include <math.h>
#include <stdio.h>

int main() {
    // var
    double weight, height;

    // getting info
    printf("Enter your height (m): ");
    scanf("%lf", &height);
    printf("Enter your weight (kg): ");
    scanf("%lf", &weight);

    double bmi = weight / pow(height, 2);  // formula

    // checking conditions
    if (bmi <= 18.5) {
        printf("YOUR BMI value is %.1lf which classifies you as underweight", bmi);  // x>=18.5 underweight
    } else if (18.5 <= bmi && bmi <= 24.9) {
        printf("YOUR BMI value is %.1lf which classifies you as normal", bmi);  // 18.5<=x<=24.9 normal
    } else if (25 <= bmi && bmi <= 29.9) {
        printf("YOUR BMI value is %.1lf which classifies you as overweight", bmi);  // 25<=x<=29.9 overweight
    } else if (30 <= bmi) {
        printf("YOUR BMI value is %.2lf which classifies you as obese", bmi);  // 30<=x obese
    } else {
        printf("ERROR ENTER CORRECT VALUES");  // errors
    }

    return 0;
}