#include <stdio.h>
#include <math.h>

double hypotenuse (double a, double b) {
    return sqrt(pow(a,2) + pow(b,2)); //formula
}
double perimeter(double a, double b, double c) {
    return a+b+c; //formula
}
double surfaceArea (double b, double h) {
    return (b*h)/2; //formula
}

int main(void) {
    //var
    double a;
    double b;

    //scan
    printf("What is Side A: ");
    scanf("%lf", &a); 
    printf("What is Side B: ");
    scanf("%lf", &b);
   
    //calling methods
    double hyp = hypotenuse(a,b);
    double per = perimeter(a,b,hyp);
    double surA = surfaceArea(b,a);
    
    //output
    printf("Hypotenuse: %lf\nPerimeter: %lf\nSurface Area: %lf", hyp,per,surA);
   
    return 0;
}