#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef double db;
#define endl "\n";
string s;
void solve()
{
    cin >> s;
    for (int i = s.size() - 2; i >= 0; i--)
    {
        if (s[i + 1] >= '5')
            s[i] = s[i] + 1;
        s[i + 1] = '0';
    }
    if (s[0] == ':')
    {
        s[0] = '1';
        s.insert(s.begin() + 1, '0');
    }
    cout << s;
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