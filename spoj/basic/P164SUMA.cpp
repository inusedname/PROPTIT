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
    string a, b = "", tmp;
    int dem1 = 1, dem2 = 0, n;
    cin >> n;
    cin.ignore();
    cin >> a;
    for (int i = 1; i < n; i++)
    {
        cin >> tmp;
        if (b == "")
            if (tmp != a)
                b = tmp;
        if (tmp == a)
            dem1++;
        else
            dem2++;
    }
    if (dem1 > dem2)
        cout << a;
    else
        cout << b;
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