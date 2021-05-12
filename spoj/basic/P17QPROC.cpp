#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef double db;
#define endl "\n";
vector<ll> a(1e7, 0);
void sang()
{
    for (ll i = 1; i <= 1e7; i++)
    {
        for (int j = i * 2; j <= 1e7; j += i)
            a[j] += i;
    }
}
void solve()
{
    sang();
    ll l, r;
    cin >> l >> r;
    ll sum;
    for (ll i = l; i <= r; i++)
        sum += abs(i - a[i]);
    cout << sum;
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