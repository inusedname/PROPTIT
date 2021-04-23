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
    ll a;
    cin >> a;
    string b;
    ll k;
    cin.ignore();
    cin >> b;
    for (int i = 1; i < a; i++)
    {
        if (a % i == 0)
        {
            k = a / i;
            ll tong = 0;
            for (int j = 0; j < b.size(); j++)
            {
                tong = tong * 10 + (b[j] - '0');
                tong %= k;
            }
            if (tong == 0)
            {
                cout << k << endl;
                return;
            }
        }
    }
    cout << "1\n";
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