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
    long long a[3];
    for (int i = 0; i < 3; i++)
        cin >> a[i];
    sort(a, a + 3);
    ll u = min(a[1], a[2] - a[0]);
    a[1] -= u;
    a[2] -= u;
    ll round = u;
    //process b to 0
    if (a[1] % 2)
        a[1]--;
    round += a[1];
    u = a[1] / 2;
    a[0] -= u, a[2] -= u;
    //end
    round += min(a[0], a[2]);
    cout << round;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
        cout << endl;
    }
}