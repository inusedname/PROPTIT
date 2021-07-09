#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef double db;
#define endl "\n"
int n, res;
bool hang[30], cheochinh[30], cheophu[30];
void Try(int i)
{
    for (int j = 1; j <= n; j++)
    {
        if (hang[j] == 0 && cheochinh[i + j - 1] == 0 && cheophu[j - i + n] == 0)
        {
            hang[j] = 1, cheochinh[i + j - 1] = 1, cheophu[j - i + n] = 1;
            if (i < n)
                Try(i + 1);
            else
                res++;
            hang[j] = 0, cheochinh[i + j - 1] = 0, cheophu[j - i + n] = 0;
        }
    }
}
void solve()
{
    cin >> n;
    for (int i = 1; i < 30; i++)
        hang[i] = cheochinh[i] = cheophu[i] = 0;
    res = 0;
    Try(1);
    cout << res;
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