#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef double db;
#define endl "\n";

string chuyendoi(string n)
{
    if (n == "000")
        return "0";
    if (n == "001")
        return "1";
    if (n == "010")
        return "2";
    if (n == "011")
        return "3";
    if (n == "100")
        return "4";
    if (n == "101")
        return "5";
    if (n == "110")
        return "6";
    if (n == "111")
        return "7";
}
void solve()
{
    string s;
    cin >> s;
    if (s.size() % 3 == 1)
        s = "00" + s;
    else if (s.size() % 3 == 2)
        s = "0" + s;
    string s2 = "";
    for (int i = s.size() - 3; i >= 0; i -= 3)
    {
        string s1 = s.substr(i, 3);
        s2 = chuyendoi(s1) + s2;
    }
    cout << s2;
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