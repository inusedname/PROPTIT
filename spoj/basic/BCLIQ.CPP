#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef double db;
#define endl "\n";

void solve()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int dem = 0, max = 0;
    for (int i = 0; i < n; i++)
    {
        dem = 0;
        for (int j = i + 1; j < n; j++)
            if (a[j] >= a[i])
            {
                a[i] = a[j];
                dem++;
            }
        if (dem > max)
            max = dem;
    }
    cout << max + 1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // int t;
    // cin >> t;
    // while (t--)
    solve();
}