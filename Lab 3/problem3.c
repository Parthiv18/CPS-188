#include <stdio.h>
#include <math.h>

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

double midValue (double midGrade, double finalGrade) {
    if (midGrade >= finalGrade) {
        return 35;
    }
    else if (midGrade < finalGrade) {
        return 25;
    }
    else {
        return 0; //error
    }
    return 0; //error
}

double finalValue (double midGrade, double finalGrade) {
    if (midGrade >= finalGrade) {
        return 40;
    }
    else if (midGrade < finalGrade) {
        return 50;
    }
    else {
        return 0; //error
    }
    return 0; //error
}

void sortQuiz (double arr[]) {
    for (int i = 0; i < 10 ; i++) {
        for (int j = i ; j < 10-1 ; j++) {
            if (arr[i] > arr[j]) {
                double temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {

    int counter=1;
    double quiz[9];
    double sum=0;
    double midtermGrade,finalGrade;

    //add quiz port
    for (int i = 0 ; i<10; i++) {
        printf("What is Quiz Mark (%d of 10): ", counter);
        scanf("%lf", &quiz[i]);
        counter++;
    } 
    sortQuiz(quiz);
    for (int i=2 ; i<10; i++) {
        sum += quiz[i];
    } 

    //midterm and final grade info
    printf("MidTerm Grade: ");
    scanf("\n%lf", &midtermGrade);
    printf("Final Grade: ");
    scanf("\n%lf", &finalGrade);

    //formula
    double courseGrade = (((sum/8)*25) + (midtermGrade*midValue(midtermGrade,finalGrade)) + (finalGrade*finalValue(midtermGrade,finalGrade))) / 100;

    if ((midtermGrade*midValue(midtermGrade,finalGrade)) !=0 && (finalGrade*finalValue(midtermGrade,finalGrade)) !=0) {
        printf("Course Grade: %.2lf", courseGrade);
    }
    else  {
        printf("ERROR HAS OCCURED"); //if error happens
    }
    return 0;
}