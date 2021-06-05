#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef double db;
#define endl "\n"
ll POW(int n)
{
    ll pp = 1;
    for (int i = 0; i < n; i++)
        pp *= 2;
    return pp;
}
void solve()
{
    string s1, s2;
    s1.clear(), s2.clear();
    cin >> s1;
    cin >> s2;
    ll num1 = 0, num2 = 0;
    int dem = 0;
    for (int i = s1.size() - 1; i >= 0; dem++, i--)
        if (s1[i] == '1')
            num1 += POW(dem);
    dem = 0;
    for (int i = s2.size() - 1; i >= 0; dem++, i--)
        if (s2[i] == '1')
            num2 += POW(dem);
    cout << num1 * num2;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
        cout << endl;
    }
}