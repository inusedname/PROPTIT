#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef double db;
#define endl "\n";
int sto[10001] = {0};
void solve()
{
    int k;
    cin >> k;
    if (k == 1)
    {
        cout << "1 1";
        return;
    }
    int dem;
    for (int i = 2; k > 1; i++)
    {
        if (sto[i])
        {
            dem = 0;
            if (k % i == 0)
            {
                while (k % i == 0)
                {
                    dem++;
                    k /= i;
                }
                cout << i << " " << dem << " ";
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n = 10000;
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
    int t;
    cin >> t;
    while (t--)
    {
        solve();
        cout << endl;
    }
}