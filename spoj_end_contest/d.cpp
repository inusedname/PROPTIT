#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef double db;
#define endl "\n"
int AthenTarget[100005];
int BaTuTarget[100005];
int AthenDead[100005];
int BaTuDead[100005];

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> AthenTarget[i];
        AthenDead[i] = 0;
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> BaTuTarget[i];
        BaTuDead[i] = 0;
    }
    int dem = 0;
    for (int i = 1; i <= max(m, n); i++)
    {
        if (i <= n)
        {
            if (AthenDead[i] == 0)
                BaTuDead[AthenTarget[i]] = 1;
            dem++;
        }
        if (dem == k)
            break;
        if (i <= m)
        {
            if (BaTuDead[i] == 0)
                AthenDead[BaTuTarget[i]] = 1;
            dem++;
        }
        if (dem == k)
            break;
    }
    for (int i = 1; i <= n; i++)
    {
        if (AthenDead[i] == 0)
            cout << AthenTarget[i] << " ";
        else
            cout << "killed ";
    }
    cout << endl;
    for (int i = 1; i <= m; i++)
    {
        if (BaTuDead[i] == 0)
            cout << BaTuTarget[i] << " ";
        else
            cout << "killed ";
    }
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