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
    while (1)
    {
        cin >> s;
        if (s == "0")
            break;
        ll S = 0;
        for (int i = 0; i < s.size(); i++)
        {
            int a = s[i] - '0';
            if (a > 4)
                a--;
            S = S * 9 + a;
        }
        cout << s << ": " << S << endl;
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