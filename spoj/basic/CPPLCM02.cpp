#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef unsigned long long ll;
typedef double db;
#define endl "\n";
int a[100001];
ll bcnn(ll a, ll b)
{
    ll af = a,
       bf = b;
    while (a > 0)
    {
        if (a < b)
        {
            ll i = a;
            a = b;
            b = i;
        }
        a %= b;
    }
    return (af / b) * bf;
}
void solve()
{
    ll n;
    cin >> n;
    ll s = 1;
    for (int i = 2; i <= n; i++)
    {
        if (s % i != 0)
        {
            ll k = i;
            while (k <= n)
                k *= i;
            s *= k / i;
        }
    }
    cout << s << endl;
    // int b[n] = {0};
    // for (int i = n; i > n / 2; i--)
    // {
    //     int t = i;
    //     for (int j = 2; j <= t; j++)
    //     {
    //         int dem = 0;
    //         if (a[j])
    //         {
    //             while (t % j == 0)
    //             {
    //                 t /= j;
    //                 if (b[j] > dem++)
    //                     continue;
    //                 b[j]++;
    //                 if (a[t])
    //                 {
    //                     b[t]++;
    //                     t = 1;
    //                     break;
    //                 }
    //             }
    //         }
    //     }
    // }
    // if (n < 3)
    // {
    //     cout << n << endl;
    //     return;
    // }
    // ll multi = 1;
    // for (int i = 1; i <= n; i++)
    // {
    //     cout << b[i] << " ";
    // }
    // for (int i = 2; i <= n; i++)
    // {
    //     if (b[i])
    //     {
    //         for (int j = 1; j <= b[i]; j++)
    //             multi *= i;
    //     }
    // }
    // cout << multi << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    int n = 100000;
    n++;
    a[0] = 0;
    a[1] = 0;
    for (int i = 2; i < n; i++)
        a[i] = 1;
    for (int i = 2; i * i <= n; i++)
    {
        if (a[i])
        {
            for (int j = i * i; j < n; j += i)
                a[j] = 0;
        }
    }
    while (t--)
        solve();
}