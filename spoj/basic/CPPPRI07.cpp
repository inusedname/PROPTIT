#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef double db;
#define endl "\n";
int a[10001];
void solve()
{
    int n;
    cin >> n;
    if (n < 30)
    {
        cout << "0";
        return;
    }
    int dem = 0;
    for (int i = 2; i <= n; i++)
    {
        if (n % i == 0)
        {
            dem++;
            if (dem > 3)
            {
                cout << 0;
                return;
            }
            n /= i;
        }
        if (n % i == 0)
        {
            cout << 0;
            return;
        }
    }
    if (dem == 3)
        cout << 1;
    else
        cout << 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    int n = 10000;
    n++;
    a[0] = 0;
    a[1] = 0;
    for (int i = 2; i < n; i++)
        a[i] = 1;
    for (int i = 2; i * i <= n; i++)
    {
        if (a[i])
        {
            for (int j = i * i; j < n; j += i)
                a[j] = 0;
        }
    }
    while (t--)
    {
        solve();
        cout << endl;
    }
}