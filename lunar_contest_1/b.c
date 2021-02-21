#include <stdio.h>
int main()
{
    long long n;
    scanf("%lld", &n);
    if (n==1)
    {
        printf("0");
        return 0;
    }
        long long ans = 1;
        double i = 0;
        while (ans > 0)
        {
            i++;
            ans = n - (((1 + i) / 2) * i) - ((2 + i) * (i + 1));
    }
    if (ans<0)
        i--;
    printf("%.0lf", i+1);
}