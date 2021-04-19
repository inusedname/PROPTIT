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
void solve()
{
    ll n, k, tmp;
    cin >> n >> k;
    ll a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        a[i] = tmp - k;
    }
    sort(a, a + n, cmp);
    ll sum = 0;
    int dem = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        dem++;
        if (sum < 0)
        {
            dem--;
            break;
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