#include <bits/stdc++.h>
#define ll long long
#define arraycin(n)             \
    for (int i = 0; i < n; i++) \
        cin >> a[i];
#define endl "\n"
const int oo = 20122007;
const int mod = 1e9 + 7;
using namespace std;

ll power(ll k)
{
    if (k == 1)
        return 3;
    ll u = power(k / 2);
    u = (u * u) % oo;
    if (k % 2)
        return (3 * u) % oo;
    else
        return u;
}
void solve()
{
    ll n;
    cin >> n;
    ll ans = 1;
    for (ll i = 1; i * i < n; i++)
    {
        if (n % i == 0)
        {
            ans = (ans * (power(i) - 1)) % oo;
            ans = (ans * (power(n / i) - 1)) % oo;
        }
    }
    int u = sqrt(n);
    if (u * u == n)
        ans = (ans * (power(sqrt(n)) - 1)) % oo;
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
        cout << endl;
    }
}