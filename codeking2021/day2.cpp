#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>

#define ll long long
#define endl "\n"
#define vi vector<int>
#define vll vector<ll>
#define vii pair<int, int>
#define v2ll pair<ll, ll>
const int oo = 1e9;
const int MOD = 1e9 + 7;
using namespace std;

void solve()
{
    ll a, b;
    ll n;
    cin >> a >> b >> n;
    a = abs(a);
    b = abs(b);
    if (a > n || b > n || a + b > n)
    {
        cout << "NO";
        return;
    }
    if (((a + b) % 2 && n % 2) || ((a + b) % 2 == 0 && n % 2 == 0))
        cout << "YES";
    else
        cout << "NO";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
        cout << endl;
    }
}