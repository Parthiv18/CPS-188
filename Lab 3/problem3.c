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

double quizAvg (double quizTotalSum) {
    return quizTotalSum/8; //change to 8 after
}

int main() {
    int counter=0;
    double sum=0,midtermGrade,finalGrade;
    
    while (counter<10) { //still have to remove 2 lowest
        double quiz;
        printf("Quiz grade (total 10): ");
        scanf("%lf", &quiz);
        sum += quiz;
        counter++;
    }

    //midterm and final grade info
    printf("MidTerm Grade: ");
    scanf("%lf", &midtermGrade);
    printf("Final Grade: ");
    scanf("%lf", &finalGrade);

    //formula
    double courseGrade = ((quizAvg(sum)*25) + (midtermGrade*midValue(midtermGrade,finalGrade)) + (finalGrade*finalValue(midtermGrade,finalGrade))) / 100;

    //printf("%.2lf avg is %.2lf", sum, quizAvg(sum)); 
    if ((midtermGrade*midValue(midtermGrade,finalGrade)) !=0 && (finalGrade*finalValue(midtermGrade,finalGrade)) !=0)
        printf("Course Grade: %.2lf", courseGrade); 
    else 
        printf("ERROR HAS OCCURED"); //if error happens
    return 0;
}