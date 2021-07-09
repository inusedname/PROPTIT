#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>

#define ll long long
#define endl "\n"
#define pi pair<int, int>
#define pll pair<ll, ll>
const int oo = 1e9;
const int MOD = 1e9 + 7;

using namespace std;
bool kiemtra(vector<string> s, int n)
{
    int f['z' + 1] = {0};
    vector<int> ft;
    int l = s[0].size();
    for (int i = 0; i < l; i++)
        f[s[0][i]]++;
    for (int i = 1; i < n; i++)
    {
        ft.assign('z' + 1, 0);
        for (int j = 0; j < s[i].size(); j++)
            ft[s[i][j]]++;
        for (char c = 'a'; c <= 'z'; c++)
            if (ft[c] != f[c])
                return 0;
    }
    return 1;
}
void solve()
{
    int n;
    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; i++)
        cin >> s[i];
    if (kiemtra(s, n) == 0)
    {
        cout << -1;
        return;
    }
    int l = s[0].size();
    string tmp;
    int mmin = oo;
    int a[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            tmp = s[j];
            int limit = l;
            while (limit > 0)
            {
                if (s[i] != tmp)
                {
                    tmp.insert(tmp.begin() + l, tmp[0]);
                    tmp.erase(tmp.begin());
                    a[i][j]++;
                }
                else
                    break;
                limit--;
            }
            if (limit == 0)
            {
                cout << -1;
                return;
            }
            a[j][i] = l - a[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = 0; j < n; j++)
            sum += a[i][j];
        if (sum < mmin)
            mmin = sum;
    }
    cout << mmin;
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