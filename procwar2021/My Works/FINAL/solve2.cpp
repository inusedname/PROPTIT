#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define endl "\n"
const int oo = 1e9 + 7;
using namespace std;

void say(int x, int y, bool flag)
{
    int u = abs(x - y);
    switch (u)
    {
    case 3:
        cout << "great-grandparent";
        break;
    case 2:
        cout << "grandparent";
        break;
    case 1:
        cout << "parent";
        break;
    default:
        if (flag)
            cout << "sibling";
        else
            cout << "cousin";
        break;
    }
    if (u && !flag)
        cout << "'s sibling";
}
void solve()
{
    int n, m;
    int u, v;
    cin >> n >> m;
    int a[n + 5] = {0};
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        a[v] = u;
    }
    int t;
    cin >> t;
    while (t--)
    {
        cin >> u >> v;
        int check1(0), check2(0);
        int tmp = u;
        while (a[tmp])
        {
            check1++;
            tmp = a[tmp];
        }
        tmp = v;
        while (a[tmp])
        {
            check2++;
            tmp = a[tmp];
        }
        //kiểm tra có rẽ nhánh không?
        bool flag = 0;
        if (a[u] == a[v])
            flag = 1;
        else
        {
            if (u < v)
                swap(u, v);
            tmp = u;
            while (a[tmp] && a[tmp] != v)
                tmp = a[tmp];
            if (a[tmp] == v)
                flag = 1;
        }
        say(check1, check2, flag);
        if (t > 0)
            cout << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
        cout << endl;
    }
}