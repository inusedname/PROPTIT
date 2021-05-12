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
    int a[n];
    int dem0 = 0;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i + 1] != 0 && a[i] == a[i + 1])
        {
            a[i] *= 2;
            a[i + 1] = 0;
        }
    }
    for (int i = 0; i < n; i++)
        if (a[i])
            cout << a[i] << " ";
        else
            dem0++;
    for (int i = 0; i < dem0; i++)
        cout << 0 << " ";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
        cout << endl;
    }
}