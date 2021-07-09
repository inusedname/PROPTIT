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
    ll n;
    int x, y;
    cin >> n >> x >> y;
    if (y > x * 2)
        cout << n * x;
    else
    {
        ll dem = (n / 2) * y;
        n %= 2;
        dem += n * x;
        cout << dem;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
        cout << endl;
    }
}