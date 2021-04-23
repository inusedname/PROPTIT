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
    cin.ignore();
    string s;
    cin >> s;
    int dem = 1;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'S')
            dem++;
        else
        {
            dem++;
            i++;
        }
    }
    if (dem > n)
        cout << n;
    else
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