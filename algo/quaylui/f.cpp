#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef double db;
#define endl "\n"
int n;
int a[15][15];
int mmin = INT_MAX;
vector<bool> freq(15, 0);
void dequi(int k, int s, int index)
{
    for (int i = 2; i <= n; i++)
        if (i != index && freq[i] == 0)
        {
            freq[i] = 1;
            s += a[index][i];
            if (s < mmin)
                if (k == n - 1)
                {
                    s += a[i][1];
                    if (s < mmin)
                        mmin = s;
                    s -= a[i][1];
                }
                else
                    dequi(k + 1, s, i);
            freq[i] = 0;
            s -= a[index][i];
        }
}
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    dequi(1, 0, 1);
    if (mmin != INT_MAX)
        cout << mmin;
    else
        cout << 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // int t;
    // cin >> t;
    // while (t--)
    {
        solve();
        cout << endl;
    }
}