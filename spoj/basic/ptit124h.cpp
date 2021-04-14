#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef double db;
#define endl "\n";
int a[10000] = {0};
int b[10000] = {0};
void solve()
{
    int c[3], d[3];
    for (int i = 0; i < 3; i++)
    {
        cin >> c[i] >> d[i];
        a[c[i]]++;
        b[d[i]]++;
    }
    for (int i = 0; i < 3; i++)
    {
        if (a[c[i]] == 1)
        {
            cout << c[i] << " ";
            break;
        }
    }
    for (int i = 0; i < 3; i++)
    {
        if (b[d[i]] == 1)
        {
            cout << d[i];
            break;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    // cin >> t;
    // while (t--)
    solve();
}