#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef unsigned long long ll;
typedef double db;
#define endl "\n";
ll a[300002];
void solve()
{
    int n;
    cin >> n;
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    if (sum % 2)
        cout << sum;
    else
    {
        sort(a, a + n);
        for (int i = 0; i < n; i++)
            if (a[i] % 2)
            {
                cout << sum - a[i];
                return;
            }
        cout << 1;
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