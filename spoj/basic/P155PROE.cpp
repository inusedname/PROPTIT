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
    int a[] = {2, 7, 2, 3, 3, 4, 2, 5, 1, 2};
    int n;
    cin >> n;
    if (n > 9)
        cout << a[n % 10] * a[n / 10];
    else
        cout << a[0] * a[n % 10];
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