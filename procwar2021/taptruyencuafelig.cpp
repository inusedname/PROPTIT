#include <bits/stdc++.h>
#define ll long long
#define arraycin(n)             \
    for (int i = 0; i < n; i++) \
        cin >> a[i];
#define endl "\n"
const int oo = 1e9 + 7;
using namespace std;
ll adjusted[105][105];
ll oneDim[10005];
void solve()
{
    int n, m, tmp;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> tmp;
            adjusted[i][j] = tmp;
            oneDim[i * m + j] = tmp;
        }
    sort(oneDim, oneDim + n * m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (oneDim[(i * m) + j] != adjusted[i][j])
                cout << adjusted[i][j] << "-" << oneDim[(i * m) + j] << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}