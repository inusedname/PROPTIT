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
    string s;
    cin >> s;
    string ans;
    int dem = 0;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        if (dem < 3)
        {
            ans = ans + s[i];
            dem++;
        }
        else
        {
            ans = ans + "," + s[i];
            dem = 1;
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans;
    // for (int i = ans.size() - 1; i >= 0; i--)
    //     cout << ans[i];
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