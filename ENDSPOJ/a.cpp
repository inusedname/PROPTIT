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
    double xa, ya, xb, yb;
    cin >> xa >> ya >> xb >> yb;
    double a = (yb - ya) / (xb - xa);
    double b = ya - (a * xa);
    int n;
    cin >> n;
    int x, y;
    int dem = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        if ((a * x) + b == y)
            dem++;
    }
    cout << dem;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
        cout << endl;
    }
}