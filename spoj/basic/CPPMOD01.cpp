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
    ll x, y, p;
    cin >> x >> y >> p;
    y = y % (p - 1);
    ll ans = 1;
    for (ll i = 1; i <= y;i++)
        ans = (ans * x) % p;
    cout << ans;
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