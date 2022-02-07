#include <stdio.h>
#include <math.h>

int main(void)
{
    double sum;
    double starting = 21000;
    double value = 0.25;

    double scrap = 2000;
    double formula = (starting-scrap)/7;

    //printf("%d", formula);

    for (int i=0; i<7; i++) {
        /*sum = starting - (starting*value);
        starting = sum;
        printf("%lf\n", sum);*/
        
        sum = starting - formula;
        starting = sum;
        printf("%lf\n", sum);    
    }
}