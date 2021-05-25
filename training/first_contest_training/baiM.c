#include<stdio.h>
#include<math.h>
int main()
{
    long long x1, y1, x2, y2;
    double r1, r2;
    scanf("%lld%lld%lld%lld%lf%lf", &x1, &y1, &x2, &y2, &r1, &r2);
    double sum = r1 + r2;
    double minus = fabs(r1 - r2);
    long long a = (x2 - x1) * (x2 - x1);
    long long b = (y2 - y1) * (y2 - y1);
    double lngt = sqrt(a + b);
    if (minus<lngt&&lngt<sum)
    {
        printf("Cut");
        return 0;
    }
    if (minus==lngt)
    {
        printf("Touch");
        return 0;
    }
    if (sum==lngt)
    {
        printf("Touch");
        return 0;
    }
    if (lngt > sum)
    {
        printf("Don't Cut");
        return 0;
    }
    if (lngt < minus || lngt == 0)
    {
        printf("Cut");
    }
}