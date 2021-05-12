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
    int n, a, b;
    int dem = 0;
    cin >> n >> a >> b;
    for (int i = 0; i <= b; i++)
        if (n - i - 1 >= a)
            dem++;
        else
            break;
    cout << dem;
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