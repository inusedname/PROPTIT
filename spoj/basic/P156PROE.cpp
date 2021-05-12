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
    int k;
    string s;
    int step;
    while (1)
    {
        cin >> k;
        if (k == 0)
            break;
        cin >> s;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '_')
                s[i] = 91;
            if (s[i] == '.')
                s[i] = 92;
            step = (s[i] - 'A' + k) % 28;
            s[i] = step + 'A';
            if (s[i] == '[')
                s[i] = '_';
            if (s[i] == '\\')
                s[i] = '.';
        }
        reverse(s.begin(), s.end());
        cout << s << endl;
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