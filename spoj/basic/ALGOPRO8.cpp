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
    int n, m;
    cin >> n >> m;
    int mi = min(n, m);
    cout << mi << " ";
    n -= mi;
    m -= mi;
    if (n > 0)
        cout << n / 2;
    else if (m > 0)
        cout << m / 2;
    else
        cout << "0";
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