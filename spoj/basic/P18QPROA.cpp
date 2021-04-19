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
    ll n;
    cin >> n;
    if (n % 2)
    {
        cout << 0 << endl;
        return;
    }
    int dem = 0;
    for (int i = 1; i * i < n; i++)
    {
        if (n % i == 0)
        {
            if (i % 2 == 0)
                dem++;
            if ((n / i) % 2 == 0)
                dem++;
        }
    }
    if (sqrt(n) == float(sqrt(n)))
        dem++;
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