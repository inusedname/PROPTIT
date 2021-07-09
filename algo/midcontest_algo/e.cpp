#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>

#define ll long long
#define endl "\n"
#define pi pair<int, int>
#define pll pair<ll, ll>
const int oo = 1e9;
const int MOD = 1e9 + 7;

using namespace std;

void solve()
{
    int n;
    cin >> n;
    ll k;
    for (int i = 0; i < n; i++)
    {
        cin >> k;
        if (k % 2)
        {
            cout << 1 << " ";
            continue;
        }
        ll k_fixed = k;
        while (k % 2 == 0)
            k /= 2;
        if (k)
            cout << log2(k_fixed / k) + 1;
        else
            cout << log2(k) + 1;
        cout << " ";
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