#include <stdio.h>
#include <math.h>
int main()
{
    long long a, b, c;
    scanf("%lld%lld%lld", &a, &b, &c);
    if (a==0)
    {
        if (b==0&&c==0)
            printf("VO SO NGHIEM");
        if (b==0&&c!=0)
            printf("VO NGHIEM");
        if (b!=0)
            printf("%.2lf",(double) -c / b);
    }
    else {
        double delta = b * b - 4 * a * c;
        if (delta < 0)
        {
            printf("VO NGHIEM");
        }
        if (delta==0)
        {
            printf("%.2lf",(double) -b / (2 * a));
        }   
        if(delta>0)
        {
            double x1 = (double)(-b + sqrt(delta)) / (2 * a);
            double x2 = (double)(-b - sqrt(delta)) / (2 * a);
            if (x1>x2)
                printf("%.2lf %.2lf", x1, x2);
                else
                    printf("%.2lf %.2lf", x2, x1);
        }
    }
}