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
    int a[n], b[n];
    stack<int> s;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = n - 1; i >= 0; i--)
    {
        while (s.size() && a[s.top()] <= a[i])
            s.pop();
        if (s.empty())
            b[i] = -1;
        else
            b[i] = s.top();
        s.push(i);
    }
    bool flag = 0;
    for (int i = 0; i < n; i++)
    {
        if (b[i] != -1)
        {
            cout << a[b[i]];
            flag = 1;
        }
    }
    if (!flag)
        cout << "-1";
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