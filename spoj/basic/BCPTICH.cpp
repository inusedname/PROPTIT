#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef double db;
#define endl "\n";
int tmp;
ll n;
void solve()
{
    cin >> tmp;
    cout << tmp << " ";
    cin >> n;
    int dem = 0;
    for (ll i = 2; i <= sqrt(2 * n); i++)
    {
        if ((2 * n) % i == 0)
        {
            if (((i + 1) - (2 * n) / i) % 2 == 0)
                dem++;
        }
    }
    cout << dem;
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