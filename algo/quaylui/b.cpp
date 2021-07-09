#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef double db;
#define endl "\n"
int n, m, tmp;
void solve()
{
    cin >> n >> m;
    ll a[n + 1][m + 1];
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= m; j++)
            a[i][j] = 0;
    for (int i = 0; i < n * m; i++)
        cin >> tmp;
    a[1][1] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (i != 1 || j != 1)
                a[i][j] = a[i - 1][j] + a[i][j - 1];
    cout << a[n][m];
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