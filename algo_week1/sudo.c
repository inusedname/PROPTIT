#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
typedef unsigned long long ll;
typedef double db;

int binsearch(ll sum[], int i, int j, ll x)
{
    while (i <= j)
    {
        int mid = (i + j) / 2;
        if (sum[mid] == x)
            return mid;
        else if (sum[mid] > x)
            j = mid - 1;
        else
            i = mid + 1;
    }
    return -1;
}
void solve()
{
    int n;
    ll k;
    scanf("%d%llu", &n, &k);
    ll a[n];
    ll sum[n];
    for (int i = 0; i < n; i++)
        scanf("%lld", &a[i]);
    sum[0] = a[0];
    for (int i = 1; i < n; i++)
        sum[i] = sum[i - 1] + a[i];
    for (int i = 0; i < n; i++)
    {
        if (sum[i] == k)
        {
            for (int j = 0; j <= i; j++)
                printf("%lld ", a[j]);
            return;
        }
        if (sum[i] > k)
        {
            int posi = binsearch(sum, 0, i - 1, sum[i] - k);
            if (posi != -1)
            {
                for (int j = posi + 1; j <= i; j++)
                    printf("%lld ", a[j]);
                return;
            }
        }
    }
    printf("NOT FOUND");
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        solve();
        printf("\n");
    }
}