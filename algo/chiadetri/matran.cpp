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
int n;
ll k;
ll ans[10][10];
ll tmp[10][10];
ll c[10][10];
void multi(ll a[10][10], ll b[10][10])
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            c[i][j] = 0;
            for (int z = 0; z < n; z++)
                c[i][j] = (c[i][j] + ((a[i][z] % MOD) * (b[z][j] % MOD)) % MOD) % MOD;
        }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = c[i][j];
}
void luythua(ll k)
{
    if (k == 1)
        return;
    luythua(k / 2);
    multi(ans, ans);
    if (k % 2)
        multi(ans, tmp);
}
void solve()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            cin >> ans[i][j];
            tmp[i][j] = ans[i][j];
        }
    luythua(k);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << ans[i][j] << " ";
        cout << endl;
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
    }
}