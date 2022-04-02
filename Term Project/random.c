/*question 3*/

#include <stdio.h>
#define COL 8
#define ROW2020 366


void date_month(double x[366][8], int n)
{
    int day = n;
    int maxDay = x[365][1];
    
    int monthDays[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    if (maxDay == 366)
    {
        monthDays[1]=29;
    }
    int month = 1;
    int dayOFMonth=0;
    for (int i=0; i<12; i++)
    {
        if (day>monthDays[i])
        {
            day -=monthDays[i];
            month++;
        }
        else
        {
            dayOFMonth=day;
            break;
        }
    }
    printf("%d/%d\n", dayOFMonth, month);
    return;
}

int main()
{
    FILE *open;
    open = fopen("data2020.txt", "r");
    
    int x, y, Superior, Michigan, Huron, Erie, Ontario, SaintClair;
    double lake[ROW2020][COL];
    
    Superior = 0;
    Michigan = 0;
    Huron = 0;
    Erie = 0;
    Ontario = 0;
    SaintClair = 0;
    
    for (x = 0; x < ROW2020; x++)
    {
        for (y = 0; y < COL; y++)
        {
            fscanf (open, "%lf", &lake[x][y]);
        }
    }
    /*question 3*/
    double cool, where;
    cool=lake[0][2];
    for (x = 1; x < 366; x++)
    {
        if (lake[x][2]<cool)
        {
            cool=lake[x][2];
            where=lake[x][1];
        }
    }
    printf("\n-----------------------------------------------------------------------------");
    printf("\nThe coolest water temperature for Lake Superior is %.2lf and occurs on ", cool);
    date_month(lake, where);
    double warm;
    warm=lake[0][2];
    for (x = 1; x < 366; x++)
    {
        if (lake[x][2]>warm)
        {
            warm = lake[x][2];
            where = lake[x][1];
        }
    }
    printf("The warmest is %.2lf and occurs on ", warm);
    date_month(lake, where);
    for (x = 1; x < 366; x++)
    {
        if (lake[x][3]<cool)
        {
            cool=lake[x][3];
            where=lake[x][1];
        }
    }
    printf("\nThe coolest water temperature for Lake Michigan is %.2lf and occurs on ", cool);
    date_month(lake, where);
    warm=lake[0][3];
    for (x = 1; x < 366; x++)
    {
        if (lake[x][3]>warm)
        {
            warm = lake[x][3];
            where = lake[x][1];
        }
    }
    printf("The warmest is %.2lf and occurs on ", warm);
    date_month(lake, where);
    for (x = 1; x < 366; x++)
    {
        if (lake[x][4]<cool)
        {
            cool=lake[x][4];
            where=lake[x][1];
        }
    }
    printf("\nThe coolest water temperature for Lake Huron is %.2lf and occurs on ", cool);
    date_month(lake, where);
    warm=lake[0][4];
    for (x=1; x<366; x++)
    {
        if (lake[x][4]>warm)
        {
            warm = lake[x][4];
            where = lake[x][1];
        }
    }
    printf("The warmest is %.2lf and occurs on ", warm);
    date_month(lake, where);
    for (x=1; x < 366; x++)
    {
        if (lake[x][5]<cool)
        {
            cool=lake[x][5];
            where=lake[x][1];
        }
    }
    printf("\nThe coolest water temperature for Lake Erie is %.2lf and occurs on ", cool);
    date_month(lake, where);
    warm=lake[0][5];
    for (x=1; x<366; x++)
    {
        if (lake[x][5]>warm)
        {
            warm = lake[x][5];
            where = lake[x][1];
        }
    }
    printf("The warmest is %.2lf and occurs on ", warm);
    date_month(lake, where);
    for (x=1; x < 366; x++)
    {
        if (lake[x][6]<cool)
        {
            cool=lake[x][6];
            where=lake[x][1];
        }
    }
    printf("\nThe coolest water temperature for Lake Ontario is %.2lf and occurs on ", cool);
    date_month(lake, where);
    warm=lake[0][6];
    for (x=1; x<366; x++)
    {
        if (lake[x][6]>warm)
        {
            warm = lake[x][6];
            where = lake[x][1];
        }
    }
    printf("The warmest is %.2lf and occurs on ", warm);
    date_month(lake, where);
    for (x=1; x < 366; x++)
    {
        if (lake[x][7]<cool)
        {
            cool=lake[x][7];
            where=lake[x][1];
        }
    }
    printf("\nThe coolest water temperature for Lake St. Clair is %.2lf and occurs on ", cool);
    date_month(lake, where);
    warm=lake[0][7];
    for (x=1; x<366; x++)
    {
        if (lake[x][7]>warm)
        {
            warm = lake[x][7];
            where = lake[x][1];
        }
    }
    printf("The warmest is %.2lf and occurs on ", warm);
    date_month(lake, where);
}
  