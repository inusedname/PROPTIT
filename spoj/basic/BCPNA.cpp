#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef double db;
#define endl "\n";
int nto(int n)
{
    if (n == 1)
        return 0;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
            return 0;
    return 1;
}

void solve()
{
    int dem = 0;
    int n;
    cin >> n;
    if (nto(n))
        dem++;
    for (int i = 2; i <= n / 2; i++)
    {
        int sum = 0;
        if (nto(i))
        {
            for (int j = i; j <= n; j++)
                if (nto(j))
                {
                    sum += j;
                    if (sum == n)
                        dem++;
                    if (sum > n)
                        break;
                }
        }
    }
    cout << dem;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
        cout << endl;
    }
}