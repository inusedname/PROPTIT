#include <stdio.h>

int main ()
{
    int n;
    scanf("%d", &n);
    unsigned long long ans = 1;
    while (n>1)
    {
        ans = ans * n;
        n--;
    }
    printf("%llu", ans);
}