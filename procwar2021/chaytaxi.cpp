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
    int n, tmp;
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        pq.push(tmp);
    }
    int total = 0;
    while (pq.size() >= 2)
    {
        int x = pq.top();
        pq.pop();
        int y = pq.top();
        pq.pop();
        total += x + y;
        pq.push(x + y);
    }
    cout << (20000 * (n - 1)) - total;
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