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
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int ti = 0;
    int teo = n - 1;
    int m = 0;
    n = 0;
    int Min;
    int flag = 1;
    while (ti != teo)
    {
        Min = min(a[ti], a[teo]);
        a[ti] -= Min;
        a[teo] -= Min;
        // if (a[ti] == 0 && a[teo] == 0 && ti + 1 == teo - 1)
        // {
        //     m += 2;
        //     n++;
        //     break;
        // }
        if (a[ti] == 0)
        {
            ti++;
            m++;
            flag = 0;
        }
        if (a[teo] == 0)
        {
            teo--;
            n++;
            flag = 1;
        }
    }
    if (a[ti])
        if (flag)
            m++;
        else
            n++;
    cout << m << " " << n << endl;
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