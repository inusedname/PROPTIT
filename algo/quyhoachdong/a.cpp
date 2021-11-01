#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
const int oo = 1e9 + 7;
using namespace std;

ll a[1005][1005];
void solve()
{
    int n, k;
    cin >> n >> k;  
    cout << a[k][n];
}
int main()
{
    for (int i = 0; i <= 1000; i++)
        for (int j = i; j <= 1000; j++)
            if (i == 0 || i == j)
                a[i][j] = 1;
            else
                a[i][j] = (a[i][j - 1] + a[i - 1][j - 1]) % oo;
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
        cout << endl;
    }
}