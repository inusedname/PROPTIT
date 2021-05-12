#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef double db;
#define endl "\n";

ll POW(ll msb)
{
    ll ans = 1;
    for (int i = 1; i <= msb; i++)
        ans *= 3;
    return ans;
}
void solve()
{
    vector<int> ans;
    vector<int> first;
    vector<int> second;
    ll a, c;
    cin >> a >> c;
    while (c > 0)
    {
        ans.push_back(c % 3);
        c /= 3;
    }
    while (a > 0)
    {
        first.push_back(a % 3);
        a /= 3;
    }
    reverse(ans.begin(), ans.end());
    reverse(first.begin(), first.end());
    while (first.size() < ans.size())
        first.insert(first.begin(), 0);
    while (ans.size() < first.size())
        ans.insert(ans.begin(), 0);
    int tmp;
    for (int i = 0; i < ans.size(); i++)
    {
        tmp = ans[i] - first[i];
        if (tmp == -1)
            tmp = 2;
        if (tmp == -2)
            tmp = 1;
        second.push_back(tmp);
    }
    ll sum = 0;
    tmp = second.size() - 1;
    for (int i = 0; i < second.size(); i++)
        sum += second[i] * POW(tmp--);
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