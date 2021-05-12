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
    cin >> s;
    int sum = 0, close = 0;
    for (int i = 0; i < s.size() - 1; i++)
        if (s[i] == ')' && s[i + 1] == ')')
            close++;
    for (int i = 0; i < s.size() - 1; i++)
    {
        if (s[i] == '(' && s[i + 1] == '(')
            sum += close;
        else if (s[i] == ')' && s[i + 1] == ')')
            close--;
    }
    cout << sum;
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