#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>

#define ll long long
#define endl "\n"
#define vi vector<int>
#define vll vector<ll>
#define vii pair<int, int>
#define v2ll pair<ll, ll>
const int oo = 1e9;
const int MOD = 1e9 + 7;
using namespace std;
vector<int> ans;

void solve()
{
    int n, m, tmp;
    cin >> n >> m;
    int base = 1;
    int k = 2;
    int step = 1;
    int u = 1;
    while (k <= 9)
    {
        base = base * 10 + k;
        tmp = base;
        u *= 10, step += u;
        ans.push_back(tmp);
        while (tmp % 10 != 9)
        {
            tmp += step;
            ans.push_back(tmp);
        }
        k++;
    }
    int i, j;
    for (i = 0; i < ans.size(); i++)
        if (ans[i] >= n)
            break;
    for (j = ans.size() - 1; j >= 0; j--)
        if (ans[j] <= m)
            break;
    sort(ans.begin() + i, ans.begin() + j);
    cout << j - i + 1 << "\n";
    cout << "[";
    for (; i <= j - 1; i++)
        cout << "[" << ans[i] << "], ";
    cout << "[" << ans[j] << "]]";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    // int t;
    // cin >> t;
    // while (t--)
    {
        solve();
        cout << endl;
    }
}