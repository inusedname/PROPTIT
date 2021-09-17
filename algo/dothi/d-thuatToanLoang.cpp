#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

int n;
stack<char> res;
vector<vector<int>> a;
vector<vector<int>> dd;
vector<vector<int>> trace;

void truyvet(int x, int y)
{
    if (x == 1 && y == 1)
        return;
    if (trace[x][y] == 1)
    {
        res.push('D');
        truyvet(x - 1, y);
    }
    else
    {
        res.push('R');
        truyvet(x, y - 1);
    }
}
void loang()
{
    queue<pair<int, int>> q;
    q.push({1, 1});
    dd[1][1] = 1;
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if (x == n && y == n)
        {
            truyvet(n, n);
            while (!res.empty())
            {
                cout << res.top();
                res.pop();
            }
            return;
        }
        if (a[x + 1][y] == 1 && dd[x + 1][y] == 0)
        {
            q.push({x + 1, y});
            dd[x + 1][y] = 1;
            trace[x + 1][y] = 1;
        }
        if (a[x][y + 1] == 1 && dd[x][y + 1] == 0)
        {
            q.push({x, y + 1});
            dd[x][y + 1] = 1;
            trace[x][y + 1] = 0;
        }
    }
    cout << -1;
}

void solve()
{
    if (!a[1][1])
    {
        cout << -1;
        return;
    }
    loang();
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    a.resize(n + 2, vector<int>(n + 2, 0));
    dd.resize(n + 2, vector<int>(n + 2, 0));
    trace.resize(n + 2, vector<int>(n + 2, 0));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    solve();
}