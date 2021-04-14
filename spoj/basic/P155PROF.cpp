#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef double db;
#define endl "\n";
#define mod 1000000007
void solve()
{
    ll x, y;
    ll n;
    cin >> x >> y >> n;
    if (n % 6 == 0)
        n = 6;
    else
        n %= 6;
    ll k = 3;
    ll z = (y % mod - x % mod) % mod;
    while (k <= n)
    {
        z = (y % mod - x % mod) % mod;
        x = y;
        y = z;
        k++;
    }
    if (n == 1)
        z = x;
    else if (n == 2)
        z = y;
    if (z >= 0)
        cout << z;
    else
        cout << z + mod;
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