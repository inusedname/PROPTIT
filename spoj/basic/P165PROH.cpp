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
    ll x, y, z;
    cin >> x >> y >> z;
    ll u = sqrt((x * z) / y);
    ll v = sqrt((x * y) / z);
    ll w = sqrt((y * z) / x);
    cout << 4 * (u + v + w);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
        cout << endl;
    }
}