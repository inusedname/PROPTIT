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
    ll a, b;
    cin >> a >> b;
    ll af = a, bf = b;
    while (a > 0)
    {
        if (a < b)
        {
            ll i = a;
            a = b;
            b = i;
        }
        a %= b;
    }
    cout << (af / b) * bf << " " << b << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}