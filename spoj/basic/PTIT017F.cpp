#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef double db;
#define endl "\n"

void solve()
{
    string s;
    cin >> s;
    int pointer = 0;
    int du = 0;
    int tmp;
    if (s == "0")
    {
        cout << "YES";
        return;
    }
    while (pointer < s.size())
    {
        while (du < 36 && pointer < s.size())
            du = du * 10 + s[pointer++] - '0';
        if (du < 36)
        {
            cout << "NO";
            return;
        }
        du -= 36 * (du / 36);
    }
    if (du)
        cout << "NO";
    else
        cout << "YES";
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