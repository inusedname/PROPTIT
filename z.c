#include <stdio.h>
#include <math.h>
#define ll long long

int a[1000005];
ll f[1000005];
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        f[0] = a[0];
        for (int i = 1; i < n; i++)
        {
            f[i] = a[i];
            if (f[i - 1] > f[i])
                f[i] = f[i - 1];
            if (i >= 2)
            {
                if (f[i - 2] + a[i] > f[i])
                    f[i] = f[i - 2] + a[i];
            }
        }
        printf("%lld", f[n - 1]);
        printf("\n");
    }
}