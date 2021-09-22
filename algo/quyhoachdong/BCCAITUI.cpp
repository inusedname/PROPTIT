#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
const int oo = 1e9 + 7;
using namespace std;

int n, m;
int b[200][200];
struct mem
{
    int mass;
    int price;
};
vector<mem> a;
void solve()
{
    cin >> n >> m;
    a.resize(n + 5);
    for (int i = 1; i <= n; i++)
        cin >> a[i].mass >> a[i].price;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            b[i][j] = b[i - 1][j];
            if (j - a[i].mass >= 0)
                b[i][j] = max(b[i][j], b[i - 1][j - a[i].mass] + a[i].price);
        }
    }
    cout << b[n][m];
    // bool res[n + 1] = {0};
    // int tmp = n;
    // while (tmp != 0)
    // {
    //     if (b[tmp][m] != b[tmp - 1][m])
    //     {
    //         res[tmp] = 1;
    //         m -= a[tmp].mass;
    //     }
    //     tmp -= 1;
    // }
    // for (int i = 1; i <= n; i++)
    //     if (res[i])
    //         cout << a[i].price << " ";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
        cout << endl;
    }
}