#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef double db;
// #define endl "\n";

void solve()
{
    string s1, s2;
    // cin.ignore();
    cin >> s1;
    // cin.ignore();
    cin >> s2;
    if (s1.size() < s2.size())
        swap(s1, s2);
    else if (s1.size() == s2.size() && s1 < s2)
        swap(s1, s2);
    int tmp = s2.size();
    for (int i = 0; i < s1.size() - tmp; i++)
    {
        s2 = "0" + s2;
    }
    char s[s1.size()];
    int du = 0;
    for (int i = s1.size() - 1; i >= 0; i--)
    {
        tmp = s1[i] - s2[i] - du;
        if (du)
            du--;
        if (tmp < 0)
        {
            tmp += 10;
            du++;
        }
        s[i] = tmp + '0';
    }
    for (int i = 0; i < s1.size(); i++)
        cout << s[i];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
        cout << endl;
    }
}