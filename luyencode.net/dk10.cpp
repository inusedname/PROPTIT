#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>

#define ll long long
#define endl "\n"
#define vi vector<int>
#define vll vector<ll>
#define vii pair<int, int>
#define v2ll pair<ll, ll>
const int oo = 1e9;
const int MOD = 1e9 + 7;
using namespace std;

void solve()
{
    int m, y;
    cin >> m >> y;
    if (m == 0 || m > 12)
        cout << "INVALID";
    else
    {
        if (m == 2)
        {
            if (y % 400 == 0 || y % 100 && y % 4 == 0)
                cout << 29;
            else
                cout << 28;
            return;
        }
        if (m % 2 && m < 8 || m >= 8 && m % 2 == 0)
            cout << 31;
        else
            cout << 30;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    // int t;
    // cin >> t;
    // while (t--)
    {
        solve();
        cout << endl;
    }
}