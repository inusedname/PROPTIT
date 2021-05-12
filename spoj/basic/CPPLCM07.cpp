#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef unsigned long long ll;
typedef double db;
#define endl "\n"
ll POW(int n)
{
    ll p = 1;
    for (int i = 1; i < n; i++)
        p *= 10;
    return p;
}
ll LCM(int x, int y)
{
    int fx = x, fy = y;
    while (x > 0)
    {
        if (x < y)
        {
            int i = x;
            x = y;
            y = i;
        }
        x %= y;
    }
    return (fx / y) * fy;
}
void solve()
{
    ll x, y, z;
    cin >> x >> y >> z;
    ll n;
    cin >> n;
    int chuso = 0;
    ll lcm = LCM(LCM(x, y), z);
    ll tmp = lcm;
    while (tmp > 0)
    {
        chuso++;
        tmp /= 10;
    }
    if (chuso == n)
        cout << lcm;
    else if (chuso > n)
        cout << -1;
    else
    {
        ll u = POW(n);
        tmp = u / lcm;
        int flag = 1;
        while (lcm * tmp < u)
        {
            tmp++;
            if (lcm * tmp >= u * 10)
            {
                flag = 0;
                break;
            }
        }
        if (flag)
            cout << lcm * tmp;
        else
            cout << -1;
    }
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