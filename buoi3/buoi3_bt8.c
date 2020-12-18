#include <stdio.h>

int main()
{
    long long i, n, sum;
    int du;
    scanf("%lld",&n);
    for(i=n; i!=0; i/10)
    {
        du = i % 10;
        sum = (10 * sum) + du;
    }
    if (n==sum)
    {
         printf("Yes");
    }
    else printf("No");
}
