#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
#define endl "\n"
using namespace std;

int const MAX = 1e6 + 6;
vector<int> ke[MAX];
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
    for (int i = 1; i <= n; i++)
        sort(ke[i].begin(), ke[i].end());
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    nhap();
    for (int i = 1; i <= n; i++)
    {
        cout << ke[i].size();
        cout << endl;
    }
}