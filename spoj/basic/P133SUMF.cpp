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
    int m, n, p;
    cin >> m >> n >> p;
    int valmin = min(min(m, n), p);
    int min = 99999;
    if (abs(m - n) < min)
        min = abs(m - n);
    if (abs(m - p) < min)
        min = abs(m - p);
    if (abs(p - n) < min)
        min = abs(p - n);
    for (int i = 1; i < 4; i++)
    {
        valmin += min;
        if (valmin != m && valmin != n && valmin != p)
        {
            cout << valmin;
            break;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // int t;
    // cin >> t;
    // while (t--)
    {
        solve();
        cout << endl;
    }
}