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
    int n, t;
    cin >> n >> t;
    int tmp;
    int dem = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        t -= tmp;
        if (t >= 0)
            dem++;
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