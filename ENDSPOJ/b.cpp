#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef double db;
#define endl "\n"
void solve()
{
    int f[10005] = {0};
    int n, m;
    cin >> n >> m;
    int tmp;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        f[tmp]++;
    }
    for (int i = 0; i < m; i++)
    {
        cin >> tmp;
        f[tmp]++;
    }
    for (int i = 0; i < 10005; i++)
        if (f[i])
            cout << i << " ";
    cout << endl;
    for (int i = 0; i < 10005; i++)
        if (f[i] > 1)
            cout << i << " ";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
        cout << endl;
    }
}