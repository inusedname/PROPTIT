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
    int n;
    cin >> n;
    int ans = 1;
    if (n)
        switch (n % 4)
        {
        case 1:
            ans = 8;
            break;
        case 2:
            ans = 4;
            break;
        case 3:
            ans = 2;
            break;
        case 0:
            ans = 6;
            break;
        }
    cout << ans;
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