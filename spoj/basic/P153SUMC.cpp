#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef double db;
#define endl "\n"

void solve()
{
    ll x, y;
    cin >> x >> y;
    int n;
    cin >> n;
    n--;
    switch (n % 6)
    {
    case 0:
        cout << x;
        break;
    case 1:
        cout << y;
        break;
    case 2:
        cout << y - x;
        break;
    case 3:
        cout << -x;
        break;
    case 4:
        cout << -y;
        break;
    case 5:
        cout << x - y;
        break;
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