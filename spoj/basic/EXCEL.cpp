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
    int a, b;
    char p;
    while (1)
    {
        string ans = "";
        cin >> p >> a >> p >> b;
        if (a == 0 && b == 0)
            break;
        while (b)
        {
            b--;
            ans = (char)('A' + b % 26) + ans;
            b /= 26;
        }
        cout << ans << a << endl;
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