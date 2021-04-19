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
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return 0;
    return 1;
}
int uc(int a, int b)
{
    int af = a, bf = b;
    while (a > 0)
    {
        if (a < b)
        {
            int i = a;
            a = b;
            b = i;
        }
        a = a % b;
    }
    return b;
}
void solve()
{
    int n;
    cin >> n;
    int sum = 1;
    for (int i = 2; i < n; i++)
        if (uc(n, i) == 1)
            sum++;
    cout << nto(sum) << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}