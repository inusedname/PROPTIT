#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef double db;
#define endl "\n";

void solve()
{
    int m, n;
    cin >> m >> n;
    cin.ignore();
    vector<string> s(m + 1);
    for (int i = 1; i <= m; i++)
        cin >> s[i];
    int a[m + 1] = {0};
    int b[m + 1];
    for (int i = 1; i <= m; i++)
        b[i] = i;
    int t1, t2;
    for (int i = 0; i < n; i++)
    {
        cin >> t1 >> t2;
        a[t2] = b[t1];
        b[t1] = 0;
    }
    int j = 1;
    for (int i = 1; i <= m; i++)
    {
        if (!a[i])
        {
            for (; j <= m; j++)
                if (b[j])
                {
                    a[i] = b[j];
                    b[j] = 0;
                    break;
                }
        }
    }
    for (int i = 1; i <= m; i++)
        cout << s[a[i]] << " ";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
        cout << endl;
    }
}