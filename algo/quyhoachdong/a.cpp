#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
const int oo = 1e9 + 7;
using namespace std;
int a[1005][1005];
int tohop(int k, int n)
{
    if (k == 0 || k == n)
        return 1;
    for (int i = 0; i <= k; i++)
        for (int j = i; j <= n; j++)
            if (i == 0 || i == j)
                a[i][j] = 1;
            else
                a[i][j] = (a[i][j - 1] + a[i - 1][j - 1]) % oo;
    return a[k][n];
}
void solve()
{
    int n, k;
    cin >> n >> k;
    cout << tohop(k, n);
}
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
        cout << endl;
    }
}