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
    int n;
    cin >> n;
    int a[n];
    int dem = 0;
    int sum = 0;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        dem++;
        if (sum > 300)
        {
            sum -= a[i];
            dem--;
            break;
        }
    }

    cout << dem << " ";
    sum = 0;
    int u = dem;
    for (int i = 0; i < dem; i++)
        sum += (u--) * a[i];
    cout << sum;
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