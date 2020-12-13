#include <stdio.h>

int main ()
{
    int n;
    scanf("%d", &n);
    unsigned long long ans = 1;
    for (int i = n; i > 0;i--)
        ans = ans * (unsigned long long)i;
    printf("%llu", ans);
}