#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>

#define ll long long
#define endl "\n"
#define vi vector<int>
#define vll vector<ll>
#define vii pair<int, int>
#define v2ll pair<ll, ll>
const int oo = 1e9;
const int MOD = 1e9 + 7;
using namespace std;

vector<int> a;
void solve()
{
    int n;
    cin >> n;
    a.clear();
    a.resize(n);
    int id_min = 0, id_max = 0;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 1)
            id_min = i + 1;
        else if (a[i] == n)
            id_max = i + 1;
        if (id_min > 0 && id_max > 0)
            break;
    }
    int tmp;
    int res = max(id_min, id_max);
    res = min(res, max(n - id_min + 1, n - id_max + 1));
    res = min(res, id_min + n - id_max + 1);
    res = min(res, n - id_min + id_max + 1);
    cout << res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
        cout << endl;
    }
}