#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef unsigned long long ll;
typedef double db;
#define endl "\n";
#define mod 1000000007
const ll mmax = 5360000 - 3;
ll a[mmax];
void fibo(ll nmax)
{
    a[0] = 0;
    a[1] = 1;
    ll i = 2;
    while (i <= mmax)
    {
        a[i] = (a[i - 1] % mod + a[i - 2] % mod) % mod;
        a[i - 2] = a[i - 1];
        a[i - 1] = a[i];
        i++;
    }
    if (nmax > mmax)
    {
        ll ak, a0 = a[mmax - 2], a1 = a[mmax - 1];
        for (i; i <= nmax; i++)
        {
            ak = a0 + a1;
            a0 = a1;
            a1 = ak;
        }
    }
}
void solve(int c)
{
    if (c > mmax)
    {
        ll i = mmax;
        ll ak, a0 = a[mmax - 2], a1 = a[mmax - 1];
        for (i; i <= c; i++)
        {
            ak = a0 + a1;
            a0 = a1;
            a1 = ak;
        }
        cout << ak << endl
    }
    else
        cout << a[c] << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    ll b[t];
    ll nmax = -999;
    for (int i = 0; i < t; i++)
    {
        cin >> b[t];
        if (b[t] > nmax)
            nmax = b[t];
    }
    fibo(nmax);
    for (int i = 0; i < t; i++)
    {
        solve(b[i]);
    }
}