#include <stdio.h>
#include <math.h>

double hypotenuse (double a, double b) {
    return sqrt(pow(a,2) + pow(b,2));
}
double perimeter(double a, double b, double c) {
    return a+b+c; 
}
double surfaceArea (double b, double h) {
    return (b*h)/2;
}

int main(void) {
    //var
    double a;
    double b;
    double height;

    //scan
    printf("What is Side A: ");
    scanf("%lf", &a); 
    printf("What is Side B: ");
    scanf("%lf", &b);
    printf("What is Height: ");
    scanf("%lf", &height);
    
    //formula
    double hyp = hypotenuse(a,b);
    double per = perimeter(a,b,hyp);
    double surA = surfaceArea(b,height);
    
    //output
    printf("Hypotenuse: %lf\nPerimeter: %lf\nSurface Area: %lf", hyp,per,surA);
    //printf("%lf", "\nPerimeter", per);   
    return 0;
}