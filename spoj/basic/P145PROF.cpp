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
    int p, q;
    int a[24][60] = {0};
    int mmax = 1;
    for (int i = 0; i < n; i++)
    {
        cin >> p >> q;
        a[p][q]++;
        mmax = max(mmax, a[p][q]);
    }
    cout << mmax;
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