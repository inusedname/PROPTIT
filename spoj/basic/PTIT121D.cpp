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
    string ans = "moo";
    string s = "moo";
    int n;
    cin >> n;
    while (ans.size() < n)
    {
        s = s + "o";
        ans = ans + s + ans;
        cout << ans << endl;
    }
    cout << ans[n - 1];
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