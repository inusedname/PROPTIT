#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef double db;
#define endl "\n";
bool cmp(int x, int y)
{
    return x > y;
}
ll a[100002];
void solve()
{
    ll n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a + 1, a + n, cmp);
    ll sum = 0;
    for (int i = 0; i <= k; i++)
        sum += a[i];
    for (int i = k + 1; i < n; i++)
        sum -= a[i];
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