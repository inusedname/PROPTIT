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
    int n, m;
    cin >> n >> m;
    int a[m];
    int res = 1000;
    for (int i = 0; i < m; i++)
        cin >> a[i];
    sort(a, a + m);
    for (int i = 0; i < m - n + 1; i++)
    {
        int min = 1000;
        int max = 0;
        for (int j = i; j < i + n; j++)
        {
            if (a[j] < min)
                min = a[j];
            if (a[j] > max)
                max = a[j];
        }
        if (max - min < res)
            res = max - min;
    }
    cout << res;
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