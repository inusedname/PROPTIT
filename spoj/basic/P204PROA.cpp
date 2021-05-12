#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef double db;
#define endl "\n"

void solve()
{
    ll M;
    ll c, b, r;
    cin >> M >> c >> b >> r;
    int dem = 0;
    int tmp;
    if (b - r < c)
    {
        while (M >= b)
        {
            tmp = M / b;
            dem += tmp;
            M %= b;
            M += tmp * r;
        }
        if (M >= c)
            dem += M / c;
    }
    else
        dem = M / c;
    cout << dem;
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