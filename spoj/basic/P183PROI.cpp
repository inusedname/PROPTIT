#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef double db;
#define endl "\n";
ll a[28] = {0};
ll ucln(ll a, ll b)
{
    while (a > 0)
    {
        if (a < b)
        {
            ll i = a;
            a = b;
            b = i;
        }
        a %= b;
    }
    return b;
}
void solve()
{
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++)
        a[s[i] - 'a' + 1]++;
    int n;
    cin >> n;
    ll tmp;
    int flag;
    for (int i = 0; i < n; i++)
    {
        flag = 0;
        cin >> tmp;
        if (a[tmp])
        {
            cout << "Yes\n";
            continue;
        }
        for (ll i = 1; i < tmp; i++)
        {
            if (tmp == a[i] * i || (a[i] * i > tmp && ucln(tmp, a[i] * i) == i))
            {
                cout << "Yes\n";
                flag = 1;
            }
        }
        if (!flag)
            cout << "No\n";
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