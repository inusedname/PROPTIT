#include <iostream>
#include <vector>
#define ll long long
#define endl "\n"
using namespace std;

int const MAX = 1e6 + 6;
vector<int> ke[MAX];
vector<bool> chuaxet;
int n, m;
int demTP;
void dfsLT(int u)
{
    chuaxet[u] = 0;
    demTP++;
    for (auto &&v : ke[u])
    {
        if (chuaxet[v])
            dfsLT(v);
    }
}
void solve()
{
    for (int i = 0; i < MAX; i++)
    {
        ke[i].clear();
    }
    chuaxet.clear();
    demTP = 0;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        ke[u].push_back(v);
        ke[v].push_back(u);
    }
    chuaxet.assign(n + 1, 1);
    int maxLT = 0;
    for (int u = 1; u <= n; u++)
    {
        if (chuaxet[u])
        {
            demTP = 0;
            dfsLT(u);
            maxLT = max(maxLT, demTP);
        }
    }
    cout << maxLT;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
        cout << endl;
    }
}