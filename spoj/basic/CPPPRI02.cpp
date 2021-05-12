#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef double db;
#define endl "\n";
#define MAX 500000000;

void solve()
{
    ll n;
    cin >> n;
    ll prime = 2;
    while (n % 2 == 0)
    {
        n /= 2;
    }
    for (ll i = 3; i * i <= n; i += 2)
    {
        if (n % i == 0)
        {
            prime = i;
            while (n % i == 0)
                n /= i;
        }
    }
    if (n > 1)
        prime = n;
    cout << prime;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
        cout << endl;
    }
}