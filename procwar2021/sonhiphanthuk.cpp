#include <bits/stdc++.h>
#define ll long long
#define arraycin(n)             \
    for (int i = 0; i < n; i++) \
        cin >> a[i];
#define endl "\n"
const int oo = 1e9 + 7;
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    int a[n] = {0};
    k--;
    while (k)
    {
        int u = log2(k);
        a[u] = 1;
        k -= pow(2, u);
    }
    for (int i = n - 1; i >= 0; i--)
        cout << a[i];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
        cout << endl;
    }
}