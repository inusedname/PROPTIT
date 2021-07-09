#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;
typedef long long ll;
#define endl "\n"
#define oo INT_MAX
const int MOD = 1e9 + 7;
struct part
{
    int val;
    int pos;
};
bool cmp(part x, part y)
{
    if (x.val == y.val)
        return x.pos < y.pos;
    return x.val < y.val;
}
void solve()
{
    int n, m, tmp;
    cin >> n >> m;
    vector<part> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].val;
        a[i].pos = i;
    }
    sort(a.begin(), a.end(), cmp);
    vector<int> b(n);
    for (int i = 0; i < n; i++)
        b[i] = a[i].val;
    for (int i = 0; i < m; i++)
    {
        cin >> tmp;
        int posi = lower_bound(b.begin(), b.end(), tmp) - b.begin();
        if (b[posi] == tmp)
            cout << a[posi].pos + 1 << " ";
        else
            cout << 0 << " ";
    }
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