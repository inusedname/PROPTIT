#include <stdio.h>

long long f[100003] = {0};
int main()
{
    long long n, i, temp;
    long long max = -999999;
    scanf("%lld",&n);
    for (i = 0; i < n;i++)
    {
        scanf("%lld", &temp);
        f[temp]++;
        if (temp>max)
            max = temp;
    }
    long long sum = 0;
    for (i = 0; i <= max;i++)
    {
        if (f[i]>1)
            sum = sum + ((f[i]*(f[i]-1))/2);
    }
    printf("%lld", sum);
}