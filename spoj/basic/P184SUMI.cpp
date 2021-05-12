#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef unsigned long long ll;
typedef double db;
#define endl "\n"
#define mod 1000000007
void solve()
{
    ll n;
    cin >> n;
    ll x = 0, y = 1, z = 1;
    ll i = 2;
    while (i++ <= n)
    {
        z = x % mod + y % mod;
        x = y;
        y = z;
    }
    cout << z;
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