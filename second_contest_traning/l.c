#include <stdio.h>
#define M 1000000007
int main()
{
    long long n,i;
    int ans = 0;
    scanf("%lld", &n);
    for (i = n-1; i > 1;i--)
        n = (n*i) % M;
    while(n>0)
    {
        ans = n % 10;
        if (ans!=0)
            break;
        else
            n = (n / 10)%10;
    }
    printf("%d", ans);
}