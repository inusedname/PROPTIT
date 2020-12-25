#include <stdio.h>
#define M 1000000007
int main()
{
    int n, k, i, j;
    scanf("%d%d", &n, &k);
    long long temp;
    long long sum = 0;
    for (i = 2; i <= n;i++)
    {
        temp = 1;
        for (j = 1; j <= k;j++)
            temp = (temp%M) * i;
        sum = sum%M + temp;
    }
    printf("%lld", sum+1);
}