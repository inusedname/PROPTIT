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
    int n, m;
    cin >> n >> m;
    int winner = 0;
    while (n > 0 && m > 0)
    {
        n--;
        m--;
        winner = !winner;
    }
    if (winner)
        cout << "Xavi";
    else
        cout << "Wilshere";
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