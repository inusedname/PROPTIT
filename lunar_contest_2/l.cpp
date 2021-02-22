#include <stdio.h>
long long a[1000002];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n;i++)
    {
        scanf("%lld", &a[i]);
    }
    int dem = 0;
    int dau = 0;
    int cuoi = n - 1;
    while(cuoi-dau>=0)
    {
        if (a[dau]==a[cuoi])
        {
            dau++;
            cuoi--;
        }
        else if (a[dau]<a[cuoi])
        {
            dau++;
            a[dau] = a[dau] + a[dau-1];
            dem++;
        }
        else 
        {
            cuoi--;
            a[cuoi] = a[cuoi + 1] + a[cuoi];
            dem++;
        }
    }
    printf("%d", dem);
}