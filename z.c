#include <stdio.h>
#include <math.h>

int main()
{
    double x;
    scanf("%lf", &x);
    double sum = 1.0 / (1.0 + exp(-x));
    printf("%.5lf", sum);
}