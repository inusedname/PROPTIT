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
    ll n, m;
    cin >> n >> m;
    ll tmp = n * pow(2, m);
    vector<vector<ll>> v;
    for (ll i = 0; i < n; i++)
    {
        vector<ll> v1(n);
        v1.resize(n, 0);
        for (ll j = 0; j < n; j++)
        {
            cin >> v1[j];
        }
        v.push_back(v1);
    }
    ll x, y;       //4>7 -> 7-4-1 = 2
    cin >> x >> y; // nếu 2ei * n > x thì ko trừ nx
    tmp = n * pow(2, m);
    while (x > n)
    {
        while (tmp - x + 1 > x)
            tmp /= 2;
        x = tmp - x + 1;
        tmp /= 2;
    }
    tmp = n * pow(2, m);
    while (y > n)
    {
        while (tmp - y + 1 > y)
            tmp /= 2;
        y = tmp - y + 1;
        tmp /= 2;
    }
    x--; //7 -> 6
    y--; //6 -> 5
    cout << v[x][y];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    // cin >> t;
    // while (t--)
    solve();
}