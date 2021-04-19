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
    ll n;
    while (1)
    {
        cin >> n;
        if (!n)
            break;
        int dem = 1;
        while (n != 1)
        {
            if (n % 2 == 0)
                n = n / 2;
            else
                n = 3 * n + 1;
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
    solve();
}