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
vector<int> ans;
void solve()
{
    int n, tmp, i;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b.begin(), b.end());
    int max = 0, dem = 0;
    for (i = 0; i < n - 1; i++)
    {
        if (b[i] == b[i + 1])
            dem++;
        else
        {
            if (dem > max)
            {
                ans.clear();
                ans.resize(0);
                max = dem;
            }
            if (dem == max)
                ans.push_back(b[i]);
            dem = 0;
        }
    }
    if (dem > max)
    {
        ans.clear();
        ans.resize(0);
        max = dem;
    }
    if (dem == max)
        ans.push_back(b[i]);
    for (int i = 0; i < n; i++)
    {
        if (binary_search(ans.begin(), ans.end(), a[i]))
        {
            cout << a[i];
            return;
        }
    }
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