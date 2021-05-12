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
    int a, b, c, d, e;
    int dem;
    while (1)
    {
        dem = -1;
        cin >> a >> b >> c >> d;
        if (a + b + c + d == 0)
            break;
        while (a + b + c + d != 0)
        {
            e = abs(d - a);
            a = abs(a - b);
            b = abs(b - c);
            c = abs(c - d);
            d = e;
            dem++;
        }
        cout << dem << endl;
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