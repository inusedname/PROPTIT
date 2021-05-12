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
    int n;
    cin >> n;
    int a[3005] = {0};
    int tmp;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        a[tmp]++;
    }
    for (int i = 1; i < 3005; i++)
    {
        if (a[i] == 0)
        {
            cout << i;
            return;
        }
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