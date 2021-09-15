#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
#define endl "\n"
using namespace std;

int const MAX = 1e6 + 6;
vector<int> ke[MAX];
vector<bool> chuaxet;
int n, m, st;

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
        ke[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
        sort(ke[i].begin(), ke[i].end());
    chuaxet.assign(n + 1, 1);
}

void dfs(int u)
{
    cout << u << " ", chuaxet[u] = 0;
    for (int i = 0; i < ke[u].size(); i++)
    {
        int v = ke[u][i];
        if (chuaxet[v])
            dfs(v);
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
        dfs(st);
        cout << endl;
    }
}