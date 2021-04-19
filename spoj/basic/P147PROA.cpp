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
    ll x, y, z;
    cin >> x >> y >> z;
    ll a = sqrt(x * y * z) / x;
    ll b = sqrt(x * y * z) / y;
    ll c = sqrt(x * y * z) / z;
    cout << 4 * (a + b + c);
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