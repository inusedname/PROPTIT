#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef double db;
#define endl "\n";
double s(double xa, double ya, double xb, double yb, double xc, double yc)
{
    return abs((xb - xa) * (yc - ya) - (xc - xa) * (yb - ya));
}
void solve()
{
    double xa, ya, xb, yb, xc, yc;
    cin >> xa >> ya >> xb >> yb >> xc >> yc;
    double sabc = s(xa, ya, xb, yb, xc, yc);
    int n;
    cin >> n;
    double a, b;
    int dem = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        if (s(xa, ya, xb, yb, a, b) + s(a, b, xb, yb, xc, yc) + s(xa, ya, a, b, xc, yc) == sabc)
            dem++;
    }
    printf("%.1lf\n", sabc * 0.5);
    cout << dem;
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
    }
}