#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef double db;
#define endl "\n"
int n, s, res;
int a[31];
void Try(int dem, int sum, int vt)
{
    if (dem >= res || sum > s)
        return;
    if (sum == s && res > dem)
        res = dem;
    for (int i = vt; i < n; i++)
        Try(dem + 1, sum + a[i], i + 1);
}
void solve()
{
    res = INT_MAX;
    cin >> n >> s;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n, greater<int>());
    Try(0, 0, 0);
    if (res == INT_MAX)
        cout << -1;
    else
        cout << res;
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