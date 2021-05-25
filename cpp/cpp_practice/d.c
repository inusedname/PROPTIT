#include <stdio.h>
int main()
{
    long long a, b;
    scanf("%lld%lld", &a, &b);
    long long m = a, n = b;
    while(a>0)
    {
        if (a<b)
        {
            int c = a;
            a = b;
            b = c;
        }
        a = a % b;
    }
    printf("%lld %lld", b, (m / b) * n);
}