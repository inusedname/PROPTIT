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
    int n;
    cin >> n;
    int a[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    int f1[n];
    int f2[n] = {0};
    for (int i = 0; i < n; i++)
        f1[i] = 1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (a[i][j]==1)
            {

            }
            else 
            {
                f1[j] = 0;
                f1[]
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