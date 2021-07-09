#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
#define endl "\n"
#define oo INT_MAX
const int MOD = 1e9 + 7;
ll POW(int n)
{
    int multi = 1;
    for (int i = 0; i < n; i++)
        multi *= 2;
    return multi;
}
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int m;
    cin >> m;
    int tmp, sum = 0;
    for (int i = 0; i < m; i++)
    {
        cin >> tmp;
        int posi = lower_bound(a.begin(), a.end(), tmp) - a.begin();
        if (a[posi] == tmp)
            sum += posi + 1;
        else
            sum--;
    }
    sum %= 30;
    cout << sum;
    cout << POW(sum);
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