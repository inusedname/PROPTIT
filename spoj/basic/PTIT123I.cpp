#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef double db;
#define endl "\n";
int sto[123457 * 2 + 1];
int danhdau[(123456 * 2) + 1];
void solve()
{
    int k;
    while (1)
    {
        cin >> k;
        if (k == 0)
            break;
        cout << danhdau[2 * k] - danhdau[k] << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n = 123456 * 2;
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
    int dem = 0;
    danhdau[0] = 0;
    danhdau[1] = 0;
    for (int i = 2; i < (123456 * 2) + 1; i++)
    {
        if (sto[i])
            dem++;
        danhdau[i] = dem;
    }
    {
        solve();
        cout << endl;
    }
}