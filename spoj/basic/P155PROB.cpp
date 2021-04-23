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
    int x, s;
    int a, b, c, d, e;
    cin >> x >> s >> a >> b >> c >> d >> e;
    x = x * s;
    cout << -x + a << " " << -x + b << " " << -x + c << " " << -x + d << " " << -x + e;
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