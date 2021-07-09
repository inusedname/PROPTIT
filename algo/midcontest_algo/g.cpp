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
    int n, l, r;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
    {
        l = i, r = i;
        while (l > 0 && a[l] > a[l - 1])
            l--;
        while (r < n - 1 && a[r] > a[r + 1])
            r++;
        cout << r - l + 1 << " ";
    }
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