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
    int n, k;
    cin >> n >> k;
    int a[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    vector<int> hoanvi(n);
    vector<vector<int>> ans;
    for (int i = 0; i < n; i++)
        hoanvi[i] = i;
    int res = 0;
    while (1)
    {
        int i = n - 2;
        while (i >= 0 && hoanvi[i] > hoanvi[i + 1])
            i--;
        if (i < 0)
            break;
        for (int j = n - 1; j > i; j--)
            if (hoanvi[j] > hoanvi[i])
            {
                swap(hoanvi[i], hoanvi[j]);
                break;
            }
        sort(hoanvi.begin() + i + 1, hoanvi.end());
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += a[i][hoanvi[i]];
            if (sum > k)
                break;
        }
        if (sum == k)
        {
            res++;
            ans.push_back(hoanvi);
        }
    }
    cout << res << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < n; j++)
            cout << ans[i][j] + 1 << " ";
        cout << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // int t;
    // cin >> t;
    // while (t--)
    {
        solve();
        cout << endl;
    }
}