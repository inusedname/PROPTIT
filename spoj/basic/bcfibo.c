#include <stdio.h>
#define modu 1000000007
#define ull unsigned long long
int main()
{
    ull x0 = 0;
    ull x1 = 1;
    ull x;
    int n;
    scanf("%d", &n);
    for (int i = 2; i <= n; i++)
    {
        x = (x0 % modu + x1 % modu) % modu;
        x0 = x1 % modu;
        x1 = x;
    }
    printf("%llu", x);
}