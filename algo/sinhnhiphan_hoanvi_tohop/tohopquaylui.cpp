#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef double db;
#define endl "\n"
int a[100], n, k;
void dequi(int i)
{
    for (int j = a[i - 1] + 1; j <= n - k + i; j++)
    {
        a[i] = j;
        if (i == k)
        {
            for (int z = 1; z <= k; z++)
                cout << a[z];
            cout << " ";
        }
        else
            dequi(i + 1);
    }
}
void solve()
{
    a[0] = 0;
    cin >> n >> k;
    dequi(1);
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