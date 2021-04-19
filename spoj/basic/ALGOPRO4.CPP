#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef double db;
#define endl "\n";
string convert(string s)
{
    if (s == "000")
        return "0";
    if (s == "001")
        return "1";
    if (s == "010")
        return "2";
    if (s == "011")
        return "3";
    if (s == "100")
        return "4";
    if (s == "101")
        return "5";
    if (s == "110")
        return "6";
    if (s == "111")
        return "7";
}
void solve()
{
    string s;
    cin >> s;
    if (s.size() % 3 != 0)
    {
        int b = s.size();
        for (int i = 0; i < 3 - (b % 3); i++)
            s = "0" + s;
    }
    string ans = "";
    for (int i = s.size() - 3; i >= 0; i -= 3)
    {
        string s1 = s.substr(i, 3);
        ans = convert(s1) + ans;
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