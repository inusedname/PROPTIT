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
    int n;
    cin >> n;
    int dem = 0;
    for (int i = 1; i < sqrt(n); i++)
    {
        if (n % i == 0)
        {
            if (i % 2 == 0)
                dem++;
            if (n / i % 2 == 0)
                dem++;
        }
    }
    if ((float)sqrt(n) == sqrt(n) && (int)sqrt(n) % 2 == 0)
        dem++;
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