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
    int n, x;
    cin >> n >> x;
    int dem = 0;
    int i;
    for (i = 1; i * i < x; i++)
    {
        if (x % i == 0)
            if (i <= n && x / i <= n)
                dem += 2;
    }
    if (sqrt(x) == (float)sqrt(x) && sqrt(x) <= n)
        dem++;
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