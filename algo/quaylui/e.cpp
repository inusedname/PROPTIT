#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef double db;
#define endl "\n"
int n, x;
vector<int> a;
vector<vector<int>> res;
vector<int> tmp;
void Try(int k, int sum)
{
    if (sum > x)
        return;
    if (sum == x)
        res.push_back(tmp);
    for (int i = k; i < n; i++)
    {
        tmp.push_back(a[i]);
        Try(i, sum + a[i]);
        tmp.pop_back();
    }
}
void solve()
{
    cin >> n >> x;
    a.clear();
    a.resize(n);
    res.clear();
    res.resize(0);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    Try(0, 0);
    if (res.empty())
        cout << -1;
    else
    {
        cout << res.size() << " ";
        for (int i = 0; i < res.size(); i++)
        {
            cout << "{";
            for (int j = 0; j < res[i].size() - 1; j++)
                cout << res[i][j] << " ";
            cout << res[i].back() << "} ";
        }
    }
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