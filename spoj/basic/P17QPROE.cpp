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
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int i = 0, j = n - 1;
    int dem = 0;
    while (i < j)
    {
        if (a[i] == a[j])
        {
            i++;
            j--;
        }
        if (a[i] < a[j])
        {
            a[i + 1] = a[i] + a[i + 1];
            i++;
            dem++;
        }
        else if (a[i] > a[j])
        {
            a[j - 1] = a[j] + a[j - 1];
            j--;
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
    {
        solve();
        cout << endl;
    }
}