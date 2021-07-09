#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
#define endl "\n"
#define oo INT_MAX
const int MOD = 1e9 + 7;
struct res
{
    int val;
    bool stat = 0;
    int stt;
};
bool cmp1(res x, res y)
{
    return x.val < y.val;
}
bool cmp2(res x, res y)
{
    return x.stt < y.stt;
}
void solve()
{
    int m, n;
    cin >> n >> m;
    int a[n];
    vector<res> r(m);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
    {
        cin >> r[i].val;
        r[i].stt = i;
    }
    sort(r.begin(), r.end(), cmp1);
    int p = 0;
    for (int i = 0; i < n; i++)
    {
        while (p < m && r[p].val <= a[i])
        {
            if (a[i] == r[p].val)
                r[p].stat = 1;
            p++;
        }
        if (p == m)
            break;
    }
    sort(r.begin(), r.end(), cmp2);
    for (int i = 0; i < m; i++)
        cout << r[i].stat;
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