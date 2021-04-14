#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef unsigned long long ll;
typedef double db;
#define endl "\n";

void solve()
{
    ll a;
    cin >> a;
    for (ll i = 2; i <= sqrt(a); i++)
    {
        while (a % i == 0)
        {
            cout << i << " ";
            a /= i;
        }
    }
    if (a > 1)
        cout << a;
    cout << endl;
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