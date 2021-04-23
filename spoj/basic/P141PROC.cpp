#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef double db;
#define endl "\n";
int ans = 0;
void solve()
{
    string s;
    cin >> s;
    for (int i = 0; i < 3; i++)
    {
        if (s[i] == '+')
        {
            ans++;
            return;
        }
        if (s[i] == '-')
        {
            ans--;
            return;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        solve();
    }
    cout << ans;
}