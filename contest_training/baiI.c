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
            printf("%.2f",(float) -c / b);
    }
    else {
        unsigned long long delta = (b * b) - (4 * a * c);
        printf("%llu\n", delta);
        if (delta < 0)
        {
            printf("VO NGHIEM");
        }
        if (delta==0)
        {
            printf("%.2f",(float) -b / (2 * a));
        }   
        if(delta>0)
        {
            printf("%.2f %.2f", ((float)-b + sqrt(delta)) / (2 * (float)a), ((float)-b - sqrt(delta)) / (2 * (float)a));
        }
    }
}