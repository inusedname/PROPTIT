#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef double db;
#define endl "\n";

void solve()
{
    int n, m;
    cin >> n >> m;
    int p;
    cin >> p;
    int tmp;
    int dem = 0;
    int x = 1;
    for (int i = 0; i < p; i++)
    {
        cin >> tmp;
        if (tmp >= x && tmp <= x + m - 1)
            continue;
        while (tmp < x)
        {
            x--;
            dem++;
        }
        while (tmp > x + m - 1)
        {
            x++;
            dem++;
        }
    }
    cout << dem;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // int t;
    // cin >> t;
    // while (t--)
    solve();
}