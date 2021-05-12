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
    int a, b, c;
    cin >> a >> b >> c;
    if (a == 0 && (b == 0 || c == 0))
    {
        cout << "NO" << endl;
    }
    else
    {
        if (b == c)
        {
            cout << "YES" << endl;
        }
        else
        {
            long long t = c - b;
            if (t < 0)
                t = -t;
            if (t % 3 != 0)
            {
                cout << "NO" << endl;
            }
            else
                cout << "YES" << endl;
        }
    }
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