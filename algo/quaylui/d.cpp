#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef double db;
#define endl "\n"
int k;
string s;
void Try(string s, int k, string &res, int pos)
{
    if (k == 0)
        return;
    char c = s[pos];
    for (int i = pos + 1; i < s.size(); i++)
        c = max(c, s[i]);
    if (c != s[pos])
        k--;
    for (int i = pos; i < s.size(); i++)
    {
        if (s[i] == c)
        {
            swap(s[i], s[pos]);
            Try(s, k, res, pos + 1);
            if (s.compare(res) > 0)
                res = s;
            swap(s[i], s[pos]);
        }
    }
}
void solve()
{
    cin >> k;
    cin >> s;
    string res = s;
    Try(s, k, res, 0);
    cout << res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
        cout << endl;
    }
}