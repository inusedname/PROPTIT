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
    int n, k;
    cin >> n;
    vector<string> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    for (int k = 1; k < 21; k++)
    {
        int u = sqrt(k * 2);
        if (u * (u + 1) == k * 2)
            cout << a[u - 1][0];
        else if (u * (u + 1) > k * 2)
        {
            int t = (u * (u + 1) - k * 2) / 2;
            cout << a[u - t - 1][0];
        }
        else if (u * (u + 1) < k * 2)
        {
            u++;
            int t = (u * (u + 1) - k * 2) / 2;
            cout << a[u - t - 1][0];
        }
    }
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