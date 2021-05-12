#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef double db;
#define endl "\n";
int tcs(ll n)
{
    int sum = 0;
    while (n > 0)
    {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}
int nto(int n)
{
    if (n == 1)
        return 0;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
            return 0;
    return 1;
}
void solve()
{
    ll n;
    cin >> n;
    ll u = n;
    int sum = 0;
    ll i = 2;
    if (!nto(n))
        while (n > 1)
        {
            if (n % i == 0)
            {
                sum += tcs(i);
                n /= i;
            }
            else
                i++;
        }
    else
        sum = tcs(n);
    if (sum == tcs(u))
        cout << "YES";
    else
        cout << "NO";
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