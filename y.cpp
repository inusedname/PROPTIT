#include <bits/stdc++.h>
#define ll long long
#define arraycin(n)             \
    for (int i = 0; i < n; i++) \
        cin >> a[i];
#define endl "\n"
const int oo = 1e9 + 7;
using namespace std;
int n;
ll res = 0;
bool a[60];
void dequi(int step)
{

    for (int i = 1; i >= 0; i--)
    {
        a[i] = i;
        
    }
}
void solve()
{
    cin >> n;
    for (int i = 0; i <= 60; i++)
        a[i] = 0;
    dequi(1);
    cout << res;
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