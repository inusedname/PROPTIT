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

void solve()
{
    int n;
    int tmp;
    int res = 0;
    cin >> n;
    int du1 = 0, du2 = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        if (tmp > 0)
        {
            if (tmp % 3 == 0)
                res++;
            else if (tmp % 3 == 1)
                du1++;
            else
                du2++;
        }
    }
    res += min(du1, du2) + (abs(du1 - du2) / 3);
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