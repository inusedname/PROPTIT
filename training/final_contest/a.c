#include <stdio.h>
#include <math.h>
int main()
{
    long long a,b,c,d,e;
    long long i;
    int dem = 0;
    scanf("%lld%lld%lld%lld%lld", &a, &b, &c, &d, &e);
    if (a==0&&b==0&&c==0&&d!=0)
    {
        printf("1");
        return 0;
    }
    for (i = -1000; i < 1001;i++)
    {
        if ((a*i*i*i*i)+(b*i*i*i)+(c*i*i)+(d*i)+e==0)
            dem++;
    }
    printf("%d", dem);
}