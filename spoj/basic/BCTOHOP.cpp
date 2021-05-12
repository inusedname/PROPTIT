#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef double db;
#define endl "\n";
int danhdau[11] = {0};
int ans[11];
int dem = 0;
int n, k;
void xuat()
{
    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";
    cout << endl;
}
int dequi()
{
    for (int i = 1; i <= n; i++)
    {
        if (!danhdau[i])
        {
            danhdau[i] = 1;
            ans[dem++] = i;
            if (dem == k)
            {
                xuat();
                dem--;
            }
            else
            {
                dequi();
                i++;
            }
            danhdau[i] = 0;
            dem--;
        }
    }
}
void solve()
{
    cin >> n >> k;
    dequi();
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