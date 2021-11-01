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
    int n;
    cin >> n;
    vector<ll> a(n + 5);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    ll L[n + 5] = {0}, R[n + 5] = {0};
    //process here
    for (int i = 1; i <= n; i++)
    {
        L[i] = 0;
        for (int j = 0; j < i; j++)
            L[i] = max(L[i], L[j] + a[i]);
    }
    for (int i = n - 1; i > 0; i--)
    {
        R[i] = 0;
        for (int j = n; j > i; j--)
            R[i] = max(R[i], R[j] + a[i]);
    }
    for (int i = 1; i <= n; i++)
        cout << L[i] << " " << R[i] << endl;
    ll MAX = 0;
    for (int i = 1; i <= n; i++)
        MAX = max(MAX, L[i] + R[i] + a[i]);
    cout << MAX;
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