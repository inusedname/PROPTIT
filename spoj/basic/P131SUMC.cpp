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
    double x, y, z, t;
    cin >> x >> y >> z >> t;
    int count = 0;
    double max = fabs(x / z - y / t);
    if (fabs(z / t - x / y) > max)
    {
        max = fabs(z / t - x / y);
        count = 1;
    }
    if (fabs(t / y - z / x) > max)
    {
        max = fabs(t / y - z / x);
        count = 2;
    }
    if (fabs(y / x - t / z) > max)
    {
        max = fabs(y / x - t / z);
        count = 3;
    }
    cout << count;
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