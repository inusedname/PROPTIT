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
    int a[42] = {0};
    int tmp;
    for (int i = 0; i < 10; i++)
    {
        cin >> tmp;
        tmp %= 42;
        a[tmp]++;
    }
    int sum = 0;
    for (int i = 0; i < 42; i++)
        if (a[i])
            sum++;
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