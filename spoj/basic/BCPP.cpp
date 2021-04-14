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
    int l, r;
    cin >> l >> r;
    if (l < 13)
        l = 12;
    int count = 0;
    for (int i = l; i <= r; i++)
    {
        int sum = 1;
        for (int j = 2; j <= sqrt(i); j++)
        {
            if (i % j == 0)
                sum += j + (i / j);
        }
        if ((float)sqrt(i) == sqrt(i))
            sum -= sqrt(i);
        if (sum > i)
            count++;
    }
    cout << count;
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