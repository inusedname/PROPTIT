#include <iostream>
#include <vector>
#include <stack>
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
    chuaxet.assign(n, 1);
}

void dfs(int u)
{
    stack<int> st;
    st.push(u);
    cout << u << " ", chuaxet[u] = 0;
    while (!st.empty())
    {
        u = st.top(), st.pop();
        for (auto &&v : ke[u])
        {
            if (chuaxet[v])
            {
                cout << v << " ", chuaxet[v] = 0;
                // st.push(u);
                st.push(v);
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    nhap();
    dfs(1);
}