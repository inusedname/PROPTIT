#include <stdio.h>

int main()
{
    int t;
    scanf("%d", &t);
    while (t)
    {
        long long i, x, k, n, temp;
        scanf("%lld%lld%lld", &x, &k, &n);
        if(!n)
        {
            printf("NO");
            t--;
            continue;
        }
        for (i = 0; i < n;i++)
        {
            scanf("%lld", &temp);
            x = x + temp;
        }
        if (x>k)
            printf("YES");
        else
            printf("NO");
        t--;
    }
}