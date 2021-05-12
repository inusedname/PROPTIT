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
    string z;
    string s;
    string x;
    getline(cin, z);
    getline(cin, s);
    getline(cin, x);
    for (int i = 0; i < x.size(); i++)
    {
        for (int j = 0; j < z.size(); j++)
            if (x[i] == z[j])
            {
                x[i] = s[j];
                break;
            }
    }
    cout << x;
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