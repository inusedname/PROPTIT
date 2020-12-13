#include<stdio.h>
#include<math.h>
int main()
{
    long long x1, y1, x2, y2;
    double r1, r2;
    scanf("%lld%lld%lld%lld%lf%lf", &x1, &y1, &x2, &y2, &r1, &r2);
    double sum = r1 + r2;
    double minus = fabs(r1 - r2);
    double a = (double)((x2 - x1) * (x2 - x1));
    double b = (double)((y2 - y1) * (y2 - y1));
    double lngt = sqrt(a + b);
    if (minus<lngt&&lngt<sum)
        printf("Cut");
    if (minus==lngt)
        printf("Touch");
    if (sum==lngt)
        printf("Touch");
    if (lngt>sum)
        printf("Don't Cut");
    if (lngt<minus||lngt==0)
        printf("'Cut");
}