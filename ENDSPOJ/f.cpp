#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef double db;
#define endl "\n"
ll p, q, tmp;
int n;
void solve()
{
    while (cin >> p >> q)
    {
        cin >> n;
        int flag = 1;
        for (int i = 0; i < n - 1; i++)
        {
            cin >> tmp;
            p -= tmp * q;
            ll k = p;
            p = q;
            q = k;
            if (p < q)
            {
                flag = 0;
                q = 2;
            }
        }
        cin >> tmp;
        if (flag == 0)
            cout << "NO";
        else if (tmp == p && q == 1)
            cout << "YES";
        else
            cout << "NO";
        cout << endl;
    }
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