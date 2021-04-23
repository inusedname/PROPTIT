#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef double db;
#define endl "\n";
int sto[123457];

void solve()
{
    int k;
    int dem;
    int i;
    while (1)
    {
        cin >> k;
        if (k == 0)
            break;
        dem = 0;
        for (i = k + 1; i <= 2 * k; i += 2)
        {
            if (sto[i])
                dem++;
        }
        cout << dem << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n = 123456;
    n++;
    sto[0] = 0;
    sto[1] = 0;
    for (int i = 2; i < n; i++)
        sto[i] = 1;
    for (int i = 2; i * i <= n; i++)
    {
        if (sto[i])
        {
            for (int j = i * i; j < n; j += i)
                sto[j] = 0;
        }
    }
    {
        solve();
        cout << endl;
    }
}