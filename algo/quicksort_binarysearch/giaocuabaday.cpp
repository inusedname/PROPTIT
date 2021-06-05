#include <stdio.h>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef unsigned long long ll;
typedef double db;
#define endl "\n"

int binsearch(ll a[], int j, ll x)
{
    int i = 0;
    while (i <= j)
    {
        int mid = (i + j) / 2;
        if (a[mid] == x)
            return 1;
        else if (a[mid] > x)
            j = mid - 1;
        else
            i = mid + 1;
    }
    return 0;
}
void solve()
{
    int m, n, p;
    scanf("%d%d%d", &m, &n, &p);
    ll a[m], b[n], c[p];
    for (int i = 0; i < m; i++)
        scanf("%llu", &a[i]);
    for (int i = 0; i < n; i++)
        scanf("%llu", &b[i]);
    for (int i = 0; i < p; i++)
        scanf("%llu", &c[i]);
    if (m <= n && m <= p)
    {
        int flag = 0;
        for (int i = 0; i < m; i++)
        {
            if (binsearch(b, n, a[i]) && binsearch(c, p, a[i]))
            {
                flag = 1;
                printf("%llu ", a[i]);
            }
        }
        if (flag == 0)
            printf("-1");
    }
    else if (n <= m && n <= p)
    {
        int flag = 0;
        for (int i = 0; i < n; i++)
        {
            if (binsearch(a, m, b[i]) && binsearch(c, p, b[i]))
            {
                flag = 1;
                printf("%llu ", b[i]);
            }
        }
        if (flag == 0)
            printf("-1");
    }
    else if (p <= n && p <= m)
    {
        int flag = 0;
        for (int i = 0; i < p; i++)
        {
            if (binsearch(a, m, c[i]) && binsearch(b, n, c[i]))
            {
                flag = 1;
                printf("%llu ", c[i]);
            }
        }
        if (flag == 0)
            printf("-1");
    }
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