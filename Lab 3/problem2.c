#include <stdio.h>
#include <math.h>

int main () {
   double weight, height;

   printf("Enter your weight (kg): ");
   scanf("%lf", &weight);
   printf("Enter your height (m): ");
   scanf("%lf", &height);


    double bmi = weight/pow(height,2); //formula

    if (bmi>=18.5) {
        printf("YOUR BMI value is %.1lf which classifies you as underweight", bmi); //x>=18.5 underweight 
    }
    else if (18.5<=bmi<=24.9) {
        printf("YOUR BMI value is %.1lf which classifies you as normal", bmi); //18.5<=x<=24.9 normal
    }
    else if (25<=bmi<=29.9) {
        printf("YOUR BMI value is %.1lf which classifies you as overweight", bmi);  //25<=x<=29.9 overweight
    }
    else if (30<=bmi) {
        printf("YOUR BMI value is %.1lf which classifies you as obese", bmi);  //30<=x obese
    }
    else {
        printf("ERROR ENTER CORRECT VALUES"); //errors
    }

    return 0;
}