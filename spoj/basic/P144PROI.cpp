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
    int n;
    cin >> n;
    ll a[n + 1];
    ll ma = 10e9;
    ll b[n + 1];
    ll mb = 1;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i] >> b[i];
        if (a[i] < ma)
        {
            ma = a[i];
        }
        if (b[i] > mb)
        {
            mb = b[i];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == ma && b[i] == mb)
        {
            cout << i;
            return;
        }
    }
    cout << -1;
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