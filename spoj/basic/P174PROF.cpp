#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef double db;
vector<string> a(1000002);
void solve()
{
    ll n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.begin() + n);
    ll u = sqrt(k * 2);
    if (u * (u + 1) == k * 2)
        cout << a[u - 1];
    else if (u * (u + 1) > k * 2)
    {
        ll t = ((u * (u + 1)) - (k * 2)) / 2;
        cout << a[u - t - 1];
    }
    else if (u * (u + 1) < k * 2)
    {
        u++;
        ll t = ((u * (u + 1)) - (k * 2)) / 2;
        cout << a[u - t - 1];
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