#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef double db;
#define endl "\n"
#define MOD int(1e9 + 7)
ll n;
ll ans[2][2];
ll mat[2][2];
void multi(ll f[2][2], ll m[2][2])
{
    ll a = ((f[0][0] * m[0][0]) % MOD + (f[0][1] * m[1][0]) % MOD) % MOD;
    ll b = ((f[0][0] * m[0][1]) % MOD + (f[0][1] * m[1][1]) % MOD) % MOD;
    ll c = ((f[1][0] * m[0][0]) % MOD + (f[1][1] * m[1][0]) % MOD) % MOD;
    ll d = ((f[1][0] * m[0][1]) % MOD + (f[1][1] * m[1][1]) % MOD) % MOD;
    f[0][0] = a;
    f[0][1] = b;
    f[1][0] = c;
    f[1][1] = d;
}
void luythua(int n)
{
    if (n == 1)
        return;
    luythua(n / 2);
    multi(ans, ans);
    if (n % 2)
        multi(ans, mat);
}
void solve()
{
    ans[0][0] = 1, ans[0][1] = 1, ans[1][0] = 1, ans[1][1] = 0;
    mat[0][0] = 1, mat[0][1] = 1, mat[1][0] = 1, mat[1][1] = 0;
    cin >> n;
    if (n == 0)
        cout << 0;
    else if (n == 1)
        cout << 1;
    else
    {
        luythua(n - 1);
        cout << ans[0][0];
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
        cout << endl;
    }
}