#include <stdio.h>
#include <math.h>
#define MOD 1000000007
int bcnn(unsigned long long a,unsigned long long b)
{
    unsigned long long m = a, n = b;
    while (a>0)
    {
        if (a<b)
        {
            unsigned long long c = a;
            a = b;
            b = c;
        }
        a = a % b;
    }
    return ((m / b)*n);
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t)
    {
        int i;
        unsigned long long a[5];
        int step = 0;
        scanf("%llu%llu%llu%llu%llu", &a[0], &a[1], &a[2], &a[3], &a[4]);
        for (step = 0; step < 4;step++)
        {    
            for (i = step + 1; i < 5;i++)
            {
                a[i] = bcnn(a[step], a[i]);
                if (a[i]>MOD)
                {
                    unsigned long long sum = 0;
                    while (a[i]>MOD)
                    {
                        sum = sum * 10 + a[i] % 10;
                        a[i] = a[i] / 10;
                    }
                    a[i] = sum;
                }
            }
        }
        printf("%llu", a[4]);
        printf("\n");
        t--;
    }
}