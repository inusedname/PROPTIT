#include <stdio.h>
int main()
{
    int n, k, i;
    scanf("%d%d", &n, &k);
    int sum = n;
    while (n >= k)
    {
        sum = sum + n / k;
        n = n % k + n / k;
    }
    printf("%d", sum);
}