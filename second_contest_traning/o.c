#include <stdio.h>
#define M 1000000007
int pows(int n, int k)
{
    if (k==0)
        return 1;
    if (k==1)
        return n;
    int temp = pows(n, k / 2);
    if (n%2==0)
        return temp * temp;
    else
        return temp * temp * n;
}
int main()
{
    int n, k, i, j;
    scanf("%d%d", &n, &k);
    long long temp;
    long long sum = 0;
    for (i = 2; i <= n;i++)
    {
        sum = (sum%M + pows(i, k)%M)%M;
    }
    printf("%lld", sum+1);
}