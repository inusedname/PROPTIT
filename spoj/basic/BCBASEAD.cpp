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
    vector<string> s(17);
    s[0] = "{}";
    for (int i = 1; i < 16; i++)
    {
        s[i] = " ";
        for (int j = 0; j < i; j++)
        {
            s[i] = s[i] + s[j] + ",";
        }
        s[i][0] = '{';
        s[i][s[i].size() - 1] = '}';
    }
    string s1, s2;
    cin.ignore();
    cin >> s1;
    cin.ignore();
    cin >> s2;
    int i, j;
    for (i = 0; i < 16; i++)
    {
        if (s1 == s[i])
        {
            break;
        }
    }
    for (j = 0; j < 16; j++)
    {
        if (s2 == s[j])
        {
            break;
        }
    }
    cout << s[i + j] << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    solve();
}