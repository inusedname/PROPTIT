#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef double db;
#define endl "\n";
ll n, a, b;
void solve()
{
    cin >> n >> a >> b;
    if (a < b)
    {
        ll i = a;
        a = b;
        b = i;
    }
    int dem = n / a;
    n = n % a;
    if (n == 0)
    {
        cout << dem << endl;
        return;
    }
    while (dem > -1)
    {
        if (n % b == 0)
        {
            dem += n / b;
            break;
        }
        else
        {
            n += a;
            dem--;
        }
    }
    if (dem == 0)
        dem = -1;
    cout << dem << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}