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
    cin.ignore();
    string s1, s2;
    cin >> s1;
    cin >> s2;
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        if (s1[i] - s2[i])
            if (abs(s1[i] - s2[i]) > 5)
                res += min(s1[i], s2[i]) + 10 - max(s1[i], s2[i]);
            else
                res += abs(s1[i] - s2[i]);
    }
    cout << res;
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