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
    int n, k;
    cin >> n >> k;
    int a[n];
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    if (sum % 2)
        cout << 0;
    else
    {
        sum /= k;
        
    }
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