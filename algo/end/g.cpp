#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
const int oo = 1e9 + 7;
using namespace std;
int n4 = 0;
void replace(string s, int i)
{
    if (n4 * 2 < s.size())
        s[i] = '4', n4++;
    else
        s[i] = '7';
}
void solve()
{
    string s;
    cin >> s;
    if (s.size() % 2)
    {
    flag:
        for (int i = 0; i * 2 < s.size(); i++)
            cout << 4;
        for (int i = 0; i * 2 < s.size(); i++)
            cout << 7;
    }
    else
    {
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] > '7')
            {
                if (i == 0 || s[i - 1] == '7')
                {
                    s.resize(s.size() + 1);
                    goto flag;
                }
                else if (s[i - 1] >= '4')
                {
                    s[i - 1] = '7';
                    replace(s, i);
                }
                else
                {
                    replace(s, i - 1);
                    replace(s, i);
                }
            }
            if (s[i] > '4' || n4 * 2 < s.size())
                s[i] = '7';
            else
                s[i] = '4', n4++;
        }
        cout << s;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
        cout << endl;
    }
}