#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define ll long long
#define endl "\n"
using namespace std;

int const MAX = 1e6 + 6;
vector<int> ke[MAX];
vector<bool> chuaxet;
int n, m, st;

// bool cmp(int x, int y)
// {
//     return x > y;
// }
void nhap()
{
    cin >> n >> m >> st;
    for (int i = 1; i <= n; i++)
        ke[i].clear();
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        ke[u].push_back(v);
        // ke[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
        sort(ke[i].begin(), ke[i].end());
    chuaxet.assign(n + 1, 1);
}

void bfs(int s)
{
    queue<int> q;
    q.push(s);
    cout << s << " ";
    chuaxet[s] = 0;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto &&v : ke[u])
        {
            if (chuaxet[v])
            {
                cout << v << " ";
                q.push(v);
                chuaxet[v] = 0;
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        nhap();
        bfs(st);
        cout << endl;
    }
}