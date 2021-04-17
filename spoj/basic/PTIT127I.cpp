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
    int n, tmp;
    while (1)
    {
        int flag = 1;
        int dem = 0;
        cin >> n;
        if (!n)
            break;
        if (n < 9)
            flag = 0;
        int a[50] = {0};
        for (int i = 0; i < 6 * n; i++)
        {
            cin >> tmp;
            a[tmp]++;
            if (a[tmp] == 1)
                dem++;
        }
        if (dem < 49)
            flag = 0;
        if (flag)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // int t;
    // cin >> t;
    // while (t--)
    solve();
}