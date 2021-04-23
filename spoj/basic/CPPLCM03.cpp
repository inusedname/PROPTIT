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
    int n;
    cin >> n;
    vector<ll> a(n);
    ll h = 1;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        h = (h % mod * a[i] % mod) % mod;
    }
    ll g = a[0];
    for (int i = 1; i < n; i++)
        g = __gcd(g, a[i]);
    ll res = 1;
    for (int i = 1; i <= g; i++)
        res = (res % mod * h % mod) % mod;
    cout << res;
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