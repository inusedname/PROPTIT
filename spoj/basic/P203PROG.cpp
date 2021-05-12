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
    ll n, d;
    bool flag;
    ll k, dem = 0;
    cin >> n >> k;
    vector<ll> a(600);
    ll max = 0;
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] > max)
            max = a[i];
    }
    if (n <= k - 1)
    {
        cout << max;
        return;
    }
    while (1)
    {
        flag = 0;
        while (a[0] > a[1])
        {
            flag = 1;
            dem++;
            if (dem == k)
            {
                cout << a[0];
                return;
            }
            d = a[1];
            a.erase(a.begin() + 1);
            a.insert(a.begin() + n - 1, d);
        }
        d = a[0];
        a.erase(a.begin());
        a.insert(a.begin() + n - 1, d);
        if (!flag)
            dem++;
        else
            dem = 1;
    }
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