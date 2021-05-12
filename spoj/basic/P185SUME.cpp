#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef unsigned long long ll;
typedef double db;
#define endl "\n"
vector<ll> f(0);
void solve()
{
    int n;
    ll tmp;
    cin >> n;
    int flag;
    for (int i = 0; i < n; i++)
    {
        flag = 1;
        cin >> tmp;
        for (int i = 0; i < f.size(); i++)
            if (f[i] == tmp)
            {
                flag = 0;
                break;
            }
        if (flag)
            f.push_back(tmp);
    }
    if (f.size() < 3)
        cout << "YES";
    else if (f.size() > 3)
        cout << "NO";
    else
    {
        sort(f.begin(), f.end());
        if (2 * f[1] == f[0] + f[2])
            cout << "YES";
        else
            cout << "NO";
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