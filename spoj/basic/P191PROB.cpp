#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef double db;
#define endl "\n";
int freq[1001] = {0};
void solve()
{
    int n, m;
    cin >> n >> m;
    int tmp, res = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        freq[tmp]++;
    }
    for (int i = 0; i * 2 < m; i++)
    {
        if (freq[i])
            res += freq[i] * freq[m - i];
    }
    if (m % 2 == 0)
        for (int i = freq[m / 2] - 1; i > 0; i--)
            res += i;
    cout << res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // int t;
    // cin >> t;
    // while (t--)
    {
        solve();
        cout << endl;
    }
}