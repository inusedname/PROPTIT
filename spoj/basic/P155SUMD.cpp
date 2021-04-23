#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef double db;
#define endl "\n";
int ans[100002] = {0};
void solve()
{
    int n, m;
    cin >> n >> m;
    int a[n];
    int b[m];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    int srt[m];
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
        srt[i] = b[i];
    }
    sort(srt, srt + m);
    int j = 0;
    int dem = 0;
    for (int i = 0; i < m; i++)
    {
        for (;; j++)
        {
            if (a[j] > srt[i] || j == n)
                break;
            dem++;
        }
        ans[srt[i]] = dem;
    }
    for (int i = 0; i < m; i++)
    {
        cout << ans[b[i]] << " ";
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