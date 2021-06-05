#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef double db;
#define endl "\n"
int n;
ll k;
void solve()
{
    cin >> n >> k;
    if (k % 2)
    {
        cout << 1;
        return;
    }
    int k_fixed = k;
    while (k % 2 == 0)
        k /= 2;
    if (k)
        cout << log2(k_fixed / k) + 1;
    else
        cout << log2(k) + 1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
        cout << endl;
    }
}