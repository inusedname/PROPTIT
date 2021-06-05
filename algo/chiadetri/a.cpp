#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef double db;
#define endl "\n"
#define MOD ll(1e9 + 7)
ll tmp;
int n, k;
int luythua(int n, int k)
{
    if (k == 1)
        return n;
    tmp = luythua(n, k / 2);
    if (k % 2)
        return (((tmp * tmp) % MOD) * n) % MOD;
    return (tmp * tmp) % MOD;
}
void solve()
{
    cin >> n >> k;
    cout << luythua(n, k);
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