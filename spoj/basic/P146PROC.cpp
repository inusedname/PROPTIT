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
    int a[4];
    for (int i = 0; i < 4; i++)
        cin >> a[i];
    sort(a, a + 4);
    int dem = 0;
    for (int i = 0; i < 3; i++)
        if (a[i] == a[i + 1])
            dem++;
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