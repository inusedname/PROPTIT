#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef double db;
#define endl "\n";
#define mod 1000000007
void solve()
{
    int t;
    cin >> t;
    int ar[t];
    int max = 0;
    for (int i = 0; i < t; i++)
    {
        cin >> ar[i];
        if (ar[i] > max)
            max = ar[i];
    }
    ll a[max + 1];
    a[0] = 0;
    a[1] = 1;
    for (int i = 2; i <= max; i++)
    {
        a[i] = (a[i - 1] % mod + a[i - 2] % mod) % mod;
    }
    for (int i = 0; i < t; i++)
    {
        cout << a[ar[i]] << endl;
    }
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