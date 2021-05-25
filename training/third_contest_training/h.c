#include <stdio.h>

int a[1000003];
int main()
{
    int i, n;
    long long k;
    scanf("%d %lld", &n, &k);
    k = k % n;
    for (i = 0; i < n;i++)
        scanf("%d", &a[i]);
    for (i = k; i < n;i++)
        printf("%d ", a[i]);
    for (i = 0; i < k;i++)
        printf("%d ", a[i]);
}