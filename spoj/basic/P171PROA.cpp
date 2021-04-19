#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef unsigned long long ll;
typedef double db;
#define endl "\n";

void solve()
{
    ll l, r, x;
    cin >> l >> r >> x;
    ll k = 1;
    int flag = 0;
    ll lim = log(r) / log(x);
    int i = 0;
    while (i <= lim)
    {
        if (k >= l && k <= r)
        {
            cout << k << " ";
            flag = 1;
        }
        k *= x;
        i++;
    }
    if (!flag)
        cout << -1;
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