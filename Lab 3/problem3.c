#include <math.h>
#include <stdio.h>

/*
    scale of 0-10
    two lowest are dropped
    avg of 8 with higher grades = 25% of course

    mid => 0-100
        if (mid >= final)
            mid value = 35% of course grade
            final = 40% of course grade
        if (final > mid)
            mid value = 25% of course grade
            final = 50% of course grade
*/

double midValue(double midGrade, double finalGrade) {  // method to calculate midterm weight accordingly
    if (midGrade >= finalGrade) {
        return 35;
    } else if (midGrade < finalGrade) {
        return 25;
    } else {
        return 0;  // error
    }
}

double finalValue(double midGrade, double finalGrade) {  // method to calculate final weight accordingly
    if (midGrade >= finalGrade) {
        return 40;
    } else if (midGrade < finalGrade) {
        return 50;
    } else {
        return 0;  // error
    }
}

void sortQuiz(double arr[]) {               // bubble sort method on quiz array
    for (int i = 0; i < 10; i++) {          // loop size of array
        for (int j = i; j < 10 - 1; j++) {  // loop one more
            if (arr[i] > arr[j]) {          // if pos at i is greater than pos at j
                double temp = arr[i];       // store in temp
                arr[i] = arr[j];            // make pos at i same as pos at j
                arr[j] = temp;              // store pos at j in temp to re-perform sort
            }
        }
    }
}

int main() {
    // var
    int counter = 1;
    double quiz[9];
    double sum = 0;
    double midtermGrade, finalGrade;

    // asking for 10 quizzes
    for (int i = 0; i < 10; i++) {
        printf("What is Quiz Mark (%d of 10): ", counter);
        scanf("%lf", &quiz[i]);
        counter++;
    }
    sortQuiz(quiz);                 // running the bubble sort
    for (int i = 2; i < 10; i++) {  // starting at 2 meanign 2 lowest quizzes are not accounted for
        sum += quiz[i];             // print here
    }

    // midterm and final grade info
    printf("MidTerm Grade: ");
    scanf("\n%lf", &midtermGrade);
    printf("Final Grade: ");
    scanf("\n%lf", &finalGrade);

    // formula
    double quizFormula = (sum / 80) * 100;
    double courseGrade = ((quizFormula * 25) + (midtermGrade * midValue(midtermGrade, finalGrade)) + (finalGrade * finalValue(midtermGrade, finalGrade))) / 100;

    // print something here
    if ((midtermGrade * midValue(midtermGrade, finalGrade)) != 0 && (finalGrade * finalValue(midtermGrade, finalGrade)) != 0) {
        printf("Course Grade (PERCENTAGE): %.2lf", courseGrade);
    } else {
        printf("ERROR HAS OCCURED");  // if error happens
    }
    return 0;
}