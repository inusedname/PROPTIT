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
    int dem = 0;
    int a[] = {500, 200, 100, 50, 20, 10, 5, 2, 1};
    int step = 0;
    while (n > 0)
    {
        if (ceil(n / a[step]) >= 1)
        {
            int tmp = floor(n / a[step]);
            dem += tmp;
            n -= a[step] * tmp;
        }
        else
            step++;
    }
    cout << dem << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}