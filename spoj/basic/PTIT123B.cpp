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

void solve(int step)
{
    int n;
    cin >> n;
    if (n == 0)
        exit(0);
    ll a[n];
    int min = 99999;
    int mmax = -99999;
    for (int i = 0; i < n; i++)
    {
        cin >> a[n];
        if (a[i] < min)
            min = a[i];
        if (a[i] > mmax)
            mmax = a[i];
    }
    int dem = 0;
    while (dem < 1000 && min < mmax)
    {
        for (int i = 0; i < n - 1; i++)
        {
            a[i] = abs(a[i] - a[i + 1]);
        }
        a[n - 1] = a[n - 1] - a[0];
        min = 0;
        mmax = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] < min)
                min = a[i];
            if (a[i] > mmax)
                mmax = a[i];
        }
        dem++;
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
    int step = 1;
    while (1)
    {
        solve(step);
        step++;
    }
}