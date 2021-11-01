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
    int n, m;
    cin >> n >> m;
    vector<ll> a(n);
    vector<ll> b(m);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for (int i = n - 2; i >= 0; i--)
        a[i] += a[i + 1];
    int q, tmp;
    cin >> q;
    while (q--)
    {
        cin >> tmp;
        if (binary_search(b.begin(), b.end(), a[n - tmp]))
            cout << "YES";
        else
            cout << "NO";
        cout << endl;
    }
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