#ifndef __MYLIBRARY_H__
#define __MYLIBRARY_H__
#include "mylibrary.h"

//write functions
double sumdiag(double arr[10][10]) { //sums all the numbers in the main diagonal of the array ([0][0] to [99][99])
    double sum=0;
    for (int i=0;i<10;i++) {
        for (int j=0;j<10;j++) {
            if (i==j)
                sum += arr[i][j];
        }
    }
    return sum;
}
double sumall(double arr[10][10]) { //sums all the numbers in the array
    double sum=0;
    for (int i=0;i<10;i++) {
        for (int j=0;j<10;j++) {
            sum += arr[i][j];
        }
    }
    return sum;
}
double avright(double arr[10][10]) { //calculates the average of the last (rightmost) column of the array
    double sum=0;
    for (int i=0;i<10;i++) {
        double sum1=0;
        for (int j=0;j<10;j++) {
            sum1 += arr[j][i];
        }
        sum = sum1;
    }
    return sum/10;
}
double corners(double arr[10][10]) { //sums the four corners of the array
    return arr[0][0]+arr[0][10-1]+arr[10-1][0]+arr[10-1][10-1];
}
double largeanti(double arr[10][10]) { //returns the largest number found in the antidiagonal ([0][99] to [99][0]) of the array.

}


#endif