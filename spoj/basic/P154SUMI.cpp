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
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j++)
        {
            int so = sqrt(i * i + j * j);
            if (so * so - i * i == j * j && so <= n)
                dem++;
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