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
    ll n;
    cin >> n;
    ll k = n * 2;
    ll u;
    for (ll i = 1; i * i <= n; i++)
    {
        u = sqrt(k - (i * (i + 1)));
        for (ll j = u; j >= i; j--)
            if (i * (i + 1) + j * (j + 1) == k)
            {
                cout << "YES";
                return;
            }
    }
    cout << "NO";
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