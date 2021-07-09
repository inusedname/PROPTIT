#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>

#define ll long long
#define endl "\n"
#define vi vector<int>
#define vll vector<ll>
#define vii pair<int, int>
#define v2ll pair<ll, ll>
const int oo = 1e9;
const int MOD = 1e9 + 7;
using namespace std;

void solve()
{
    int n, k, s;
    cin >> n >> k;
    s = n - 2;
    int dkxd;
    ll res = 0;
    vi a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    for (int i = n - 1; i > 0; i--)
    {
        dkxd = a[i] - k;
        while (s > 0 && a[s] > dkxd)
            s--;
        if (a[s] <= dkxd)
            s++;
        res += i - s;
    }
    cout << res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    // int t;
    // cin >> t;
    // while (t--)
    {
        solve();
        cout << endl;
    }
}