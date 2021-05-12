#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef double db;
#define endl "\n";
struct data
{
    ll stat;
    ll tests;
};
bool cmp(data x, data y)
{
    return x.tests < y.tests;
}

ll tbc(data a[], ll n)
{
    ll figure = 0;
    for (int i = 0; i < n; i++)
        figure += a[i].stat;
    return figure;
}
void solve()
{
    ll n, r;
    ll avg;
    cin >> n >> r >> avg;
    data a[n];
    for (ll i = 0; i < n; i++)
        cin >> a[i].stat >> a[i].tests;
    ll sum = 0;
    sort(a, a + n, cmp);
    ll i = 0;
    ll target = (avg * n) - tbc(a, n);
    while (target > 0)
    {
        if (a[i].stat < r)
        {
            sum += a[i].tests;
            a[i].stat++;
            target--;
        }
        else
            i++;
    }
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