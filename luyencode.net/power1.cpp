#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
#define endl "\n"
#define oo INT_MAX
const ll MOD = 1e9 + 7;
ll a, n;
ll luythua(ll a, ll n)
{
    if (n == 1)
        return a;
    ll tmp = luythua(a, n / 2) % MOD;
    tmp = (tmp * tmp) % MOD;
    if (n % 2)
        return (tmp * a) % MOD;
    return tmp;
}
void solve()
{
    cin >> a >> n;
    cout << luythua(a, n);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // int t;
    // cin >> t;
    // while (t--)
    {
        solve();
        cout << endl;
    }
}