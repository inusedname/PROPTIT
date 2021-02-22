#include <stdio.h>
#include <math.h>
int main()
{
    int test;
    scanf("%d", &test);
    while(test--)
    {
        double a;
        double r;
        double T;
        scanf("%lf %lf %lf", &a, &r, &T);
        r = r / 10000;
        double n = log((T / a * r)+ 1 )/ log(1 + r) - 1;
        int N = ceil(n);
        if (N>=12)
        {
            printf("%d nam %d thang.", N / 12, N % 12);
        }
        else
            printf("%d thang.", N);
        printf("\n");
    }
}