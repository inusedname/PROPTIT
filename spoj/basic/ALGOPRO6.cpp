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
    int n;
    cin >> n;
    int nhuan = 0;
    int flag = 0;
    if (n % 4 == 0)
        if (n % 100 != 0)
            flag = 1;
    if (n % 400 == 0)
        flag = 1;
    int sum = 0;
    int tmp = n;
    while (tmp > 0)
    {
        sum += tmp % 10;
        tmp /= 10;
    }
    sum = (365 + flag) * sum;
    sum += 1554 + 1876;
    if (flag)
        sum += 2;
    if (flag)
        sum += 154 + 11;
    else
        sum += 154;
    cout << sum;
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