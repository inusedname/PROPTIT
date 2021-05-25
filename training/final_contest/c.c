#include <stdio.h>
#include <math.h>

int main()
{
    int i,t;
    scanf("%d", &t);
    while (t)
    {
        long long n, i, max = -999999;
        long long a[3000];
        scanf("%lld", &n);
        long long dem = 0;
        long long dau = 0, cuoi = n - 1;
        for (i = 0; i < n;i++)
        {
            scanf("%lld", &a[i]);
            if (a[i]>max)
                max = a[i];
        }
        while (cuoi-dau>0)
        {
            if (a[dau]==max&&a[cuoi]==max)
                dau++;
            while (a[dau]!=max)
            {
                a[dau + 1] = a[dau] + a[dau + 1];
                dem++;
                dau++;
                if (a[dau]>max)
                    max = a[dau];
            }
            while (a[cuoi]!=max)
            {
                a[cuoi - 1] = a[cuoi] + a[cuoi - 1];
                dem++;
                cuoi--;
                if (a[cuoi]>max)
                    max = a[cuoi];
            }
        }
        printf("%lld\n",dem);
        t--;
    }
}