#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
#define endl "\n"
const int oo = 1e9;
const int MOD = 1e9 + 7;
bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.second <= b.second;
}
void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i].first >> a[i].second;
    sort(a.begin(), a.end(), cmp);
    int dem = 0;
    int x = a[0].first;
    for (int i = 0; i < n; i++)
    {
        if (x <= a[i].first)
        {
            dem++;
            x = a[i].second;
        }
    }
    cout << dem;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // int t;
    // cin >> t;
    // while (t--)
    {
        solve();
        cout << endl;
    }
}