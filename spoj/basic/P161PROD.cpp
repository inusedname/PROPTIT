#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef double db;
#define endl "\n"
string first = "qwertyuiopq";
string second = "asdfghjkl;a";
string third = "zxcvbnm,./z";
void solve()
{
    char c;
    cin >> c;
    string s;
    cin >> s;
    int flag = 1;
    if (c == 'L')
        flag = 1;
    else
        flag = -1;
    for (int i = 0; i < s.size(); i++)
    {
    replay:
        if (i == s.size())
            break;
        for (int j = 0; j < first.size(); j++)
            if (s[i] == first[j])
            {
                if (flag == -1 && s[i] == 'q')
                    cout << 'p';
                else
                    cout << first[j + flag];
                i++;
                goto replay;
            }
        for (int j = 0; j < second.size(); j++)
            if (s[i] == second[j])
            {
                if (flag == -1 && s[i] == 'a')
                    cout << ';';
                else
                    cout << second[j + flag];
                i++;
                goto replay;
            }
        for (int j = 0; j < third.size(); j++)
            if (s[i] == third[j])
            {
                if (flag == -1 && s[i] == 'z')
                    cout << '/';
                else
                    cout << third[j + flag];
                i++;
                goto replay;
            }
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