#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <stdlib.h>
using namespace std;
typedef long long ll;
typedef double db;
#define endl "\n";
int step = 1;
int n;
int ktralap(ll a[])
{
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] != a[i + 1])
            return 1;
    }
    return 0;
}

void solve()
{
    cin >> n;
    if (n == 0)
        exit(0);
    ll a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    if (ktralap(a) == 0)
    {
        printf("Case %d: 0 iterations\n", step);
        return;
    }
    int dem = 0;
    while (dem < 1000)
    {
        int tmp = abs(a[n - 1] - a[0]);
        for (int i = 0; i < n - 1; i++)
            a[i] = abs(a[i] - a[i + 1]);
        a[n - 1] = tmp;
        // debug(a);
        dem++;
        if (ktralap(a) == 0)
            break;
    }
    if (dem < 1000)
        printf("Case %d: %d iterations\n", step, dem);
    else
        printf("Case %d: not attained\n", step);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // int t;
    // cin >> t;
    while (1)
    {
        solve();
        step++;
    }
}