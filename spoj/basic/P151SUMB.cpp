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
    int n;
    cin >> n;
    if (n < 3)
    {
        cout << -1;
        return;
    }
    int a = 5000, b;
    if (n % 5 == 0)
    {
        cout << n / 5;
        return;
    }
    if (n % 3 == 0)
        a = n / 3;
    int u = n % 5;
    while (u <= n && u % 3)
    {
        u += 5;
    }
    if (u <= n && u % 3 == 0)
    {
        int tmp = u / 3;
        b = tmp + (n - u) / 5;
    }
    else
        b = -1;
    cout << min(a, b);
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