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
    int i = s.size() - 1;
    while (i >= 0 && s[i] == '1')
        i--;
    for (int j = 0; j < i; j++)
        cout << s[j];
    if (i >= 0)
        cout << "1";
    for (int j = i + 1; j < s.size(); j++)
        cout << 0;
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