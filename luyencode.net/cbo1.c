#include <stdio.h>

int main()
{
    double a;
    scanf("%lf", &a);
    int itg = (int)a;
    if (a > 0 && a - itg >= 0.5)
        itg++;
    if (a < 0 && a - itg > -0.5)
        itg--;
    printf("%d", itg);
}