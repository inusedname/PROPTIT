#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef double db;
#define endl "\n"

void solve()
{
    int n;
    cin >> n;
    string a, b;
    cin >> a;
    cin >> b;
    int dem = 0;
    for (int i = 0; i < n; i++)
    {
        int k = abs(a[i] - b[i]);
        if (k)
            if (k < 6)
                dem += k;
            else
                dem += 10 - k;
    }
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