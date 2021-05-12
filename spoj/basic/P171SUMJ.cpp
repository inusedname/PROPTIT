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
    double a, b, c;
    cin >> a >> b >> c;
    if (a == 0)
    {
        if (b == 0)
            if (c == 0)
                cout << -1;
            else
                cout << 0;
        else
            printf("1\n%.5lf", -c / b);
        return;
    }
    ll delta = (b * b) - (4.0 * a * c);
    if (delta < 0)
        cout << 0;
    else if (delta == 0)
        printf("1\n%.5lf", -b / (2.0 * a));
    else
    {
        double x1 = (-b + (double)sqrt(delta)) / (2.0 * a);
        double x2 = (-b - (double)sqrt(delta)) / (2.0 * a);
        if (x1 > x2)
            printf("2\n%.5lf\n%.5lf", x2, x1);
        else
            printf("2\n%.5lf\n%.5lf", x1, x2);
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