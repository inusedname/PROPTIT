#include <iostream>
#include <vector>
#include <queue>
#define ll long long
#define endl "\n"
using namespace std;

int const MAX = 1e6 + 6;
vector<int> ke[MAX];
vector<bool> chuaxet;
int n, m;

void nhap()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        ke[u].push_back(v);
        ke[v].push_back(u);
    }
    chuaxet.assign(n + 1, 1);
}

void bfs(int u)
{
    queue<int> q;
    q.push(u);
    chuaxet[u] = 0;
    while (!q.empty())
    {
        u = q.front();
        q.pop();
        cout << u << " ";
        for (auto &&i : ke[u])
        {
            if (chuaxet[i])
            {
                q.push(i);
                chuaxet[i] = 0;
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    nhap();
    bfs(1);
}