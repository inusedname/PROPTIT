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
    int n;
    cin >> n;
    int dem = 1;
    ll tmp1, tmp2;
    int max = 1;
    cin >> tmp1;
    for (int i = 1; i < n; i++)
    {
        cin >> tmp2;
        if (tmp2 >= tmp1)
        {
            dem++;
        }
        else
        {
            if (dem > max)
                max = dem;
            dem = 1;
        }
        tmp1 = tmp2;
    }
    cout << max;
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