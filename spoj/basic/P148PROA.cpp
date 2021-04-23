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
    int n = 1;
    while (1)
    {
        cin >> n;
        int dem = 1;
        if (n == 0)
            break;
        if (n == 1)
        {
            cout << 1 << endl;
            continue;
        }
        while (1)
        {
            if (n % 2 == 0)
            {
                n /= 2;
                dem++;
            }
            else
            {
                n = 3 * n + 1;
                dem++;
            }
            if (n == 1)
                break;
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