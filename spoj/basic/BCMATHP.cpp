#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef double db;
#define endl "\n";
int csdautien(int i)
{
    while (i > 9)
    {
        i /= 10;
    }
    return i;
}
void solve()
{
    int a, b;
    cin >> a >> b;
    ll tich = 1;
    int dem = 0;
    for (int i = a + 1; i <= 62; i++)
    {
        tich *= 2;
        dem++;
        if (csdautien(tich) == b)
        {
            cout << dem;
            return;
        }
    }
    cout << 0;
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