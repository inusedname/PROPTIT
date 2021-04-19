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
    int a, b;
    cin >> a >> b;
    int min = 0, max = 0;
    int multi = 1;
    while (a > 0)
    {
        int tmp = a % 10;
        if (tmp == 5)
        {
            max += (tmp + 1) * multi;
            min += tmp * multi;
        }
        else if (tmp == 6)
        {
            min += (tmp - 1) * multi;
            max += tmp * multi;
        }
        else
        {
            min += tmp * multi;
            max += tmp * multi;
        }
        multi = multi * 10;
        a /= 10;
    }
    multi = 1;
    while (b > 0)
    {
        int tmp = b % 10;
        if (tmp == 5)
        {
            max += (tmp + 1) * multi;
            min += tmp * multi;
        }
        else if (tmp == 6)
        {
            min += (tmp - 1) * multi;
            max += tmp * multi;
        }
        else
        {
            min += tmp * multi;
            max += tmp * multi;
        }
        multi *= 10;
        b /= 10;
    }
    cout << min << " " << max;
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