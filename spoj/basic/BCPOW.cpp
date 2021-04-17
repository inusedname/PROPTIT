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
    int n, m;
    cin >> n >> m;
    ll s = pow(2, n) + pow(3, m);
    while (s > 10)
    {
        s /= 10;
    }
    cout << s;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // int t;
    // cin >> t;
    // while (t--)
    solve();
}