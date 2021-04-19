#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef double db;
#define endl "\n";
int n;
int nto(int n)
{
    if (n == 1)
        return 0;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            return 0;
    }
    return 1;
}
void solve()
{
    cin >> n;
    int dem = 0;
    for (int i = 6; i <= n; i++)
    {
        if (!nto(i))
        {
            int demtmp = 0;
            for (int j = 2; j * j <= i; j++)
            {
                if (i % j == 0)
                {
                    if (nto(j))
                        demtmp++;
                    if (j != i / j && nto(i / j))
                        demtmp++;
                    if (demtmp > 2)
                        break;
                }
            }
            if (demtmp == 2)
            {
                dem++;
            }
        }
    }
    cout << dem;
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