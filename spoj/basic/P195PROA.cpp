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
    int x = n / 7;
    if (n % 7 == 6)
        cout << (x * 2) + 1 << " ";
    else
        cout << x * 2 << " ";
    n %= 7;
    if (n > 1)
        cout << (x * 2) + 2;
    else
        cout << (x * 2) + n;
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