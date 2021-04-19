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
    ll a, b;
    cin >> a >> b;
    if (a == b)
        cout << "infinity";
    else if (a < b)
        cout << 0;
    else
    {
        int dem = 0;
        a = a - b;
        for (ll i = 1; i * i < a; i++)
            if (a % i == 0)
            {
                if (i > b)
                    dem++;
                if (a / i > b)
                    dem++;
            }
        int u = sqrt(a);
        if (u * u == a && u > b)
            dem++;
        cout << dem;
    }
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